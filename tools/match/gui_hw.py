"""gui_hw.py -- hardware monitor for control_gui.py: CPU/GPU temperature, load, power, kWh.

A PowerShell loop on the Windows side (WSL can't see Windows' sensors) prints one JSON line
every ~2 s with:
  * CPU load       \\Processor Information(_Total)\\% Processor Utility (what Task Manager shows)
  * GPU            nvidia-smi: temperature, load, power draw, power limit, memory
  * CPU temp/power LibreHardwareMonitor's web server (http://localhost:8085/data.json, enable it in
                   LHM: Options > Remote Web Server). Without it, CPU power is ESTIMATED from load
                   (idle W + load x (max W - idle W), settings hw.cpu_idle_w / hw.cpu_max_w) and the
                   CPU temperature is unknown.
The WSL VM's own CPU use is read from /proc/stat, so "other load" = Windows load minus what WSL
(the permuter, m2c) uses; the CPU guard in control_gui.py works on that.
Energy is the integral of power over time, kept in permuter/gui/energy.json (all-time totals and
per day), saved once a minute.
"""
import base64, json, os, re, subprocess, threading, time
from collections import deque

PS = "/mnt/c/Windows/System32/WindowsPowerShell/v1.0/powershell.exe"
SCRIPT = r"""
$ErrorActionPreference = 'SilentlyContinue'
$ctr = '\Processor Information(_Total)\% Processor Utility'
if (-not (Get-Counter $ctr -MaxSamples 1)) { $ctr = '\Processor(_Total)\% Processor Time' }
$smi = (Get-Command nvidia-smi).Source
function Flat($n, $path) {
  $p = if ($path) { $path + '/' + $n.Text } else { $n.Text }
  if ($n.Value -and ($n.Value -match ' W$' -or $n.Value -match 'C$')) { $p + '=' + $n.Value }
  foreach ($c in $n.Children) { Flat $c $p }
}
while ($true) {
  $cpu = (Get-Counter $ctr -SampleInterval 2 -MaxSamples 1).CounterSamples[0].CookedValue
  $gpu = $null
  if ($smi) { $gpu = @(& $smi --query-gpu=name,temperature.gpu,utilization.gpu,power.draw,power.limit,memory.used,memory.total --format=csv,noheader,nounits)[0] }
  $lhm = @()
  try { $d = Invoke-RestMethod 'http://localhost:8085/data.json' -TimeoutSec 1; $lhm = @(Flat $d '') } catch {}
  $o = @{ cpu = $cpu; ncpu = [int]$env:NUMBER_OF_PROCESSORS; gpu = $gpu; lhm = $lhm }
  [Console]::Out.WriteLine(($o | ConvertTo-Json -Compress))
  [Console]::Out.Flush()
}
"""
NUM = re.compile(r"(-?\d+(?:[.,]\d+)?)")


def num(s):
    m = NUM.search(str(s or ""))
    return float(m.group(1).replace(",", ".")) if m else None


class Hardware:
    def __init__(self, gui_dir, settings, on_sample=None):
        self.path = os.path.join(gui_dir, "energy.json")
        self.settings = settings            # callable -> settings dict
        self.on_sample = on_sample
        self.samples = deque(maxlen=1200)   # ~45 min at ~2.2 s
        self.now = {}
        self.error = None
        self.lock = threading.Lock()
        self.energy = self._load()
        self.last_t = None
        self.last_save = time.time()
        self._stat = None
        threading.Thread(target=self._run, daemon=True).start()

    # ---------------------------------------------------------------- energy
    def _load(self):
        try:
            e = json.load(open(self.path))
            e.setdefault("total", {"cpu": 0.0, "gpu": 0.0})
            e.setdefault("days", {})
            e.setdefault("cpu_estimated", 0.0)
            return e
        except (OSError, ValueError):
            return {"since": time.strftime("%Y-%m-%d %H:%M"), "total": {"cpu": 0.0, "gpu": 0.0},
                    "days": {}, "cpu_estimated": 0.0, "session": {"cpu": 0.0, "gpu": 0.0}}

    def save(self):
        with self.lock:
            data = json.dumps(self.energy, indent=1)
        tmp = self.path + ".tmp"
        with open(tmp, "w") as f:
            f.write(data)
        os.replace(tmp, self.path)

    def reset(self):
        with self.lock:
            self.energy = {"since": time.strftime("%Y-%m-%d %H:%M"), "total": {"cpu": 0.0, "gpu": 0.0},
                           "days": {}, "cpu_estimated": 0.0}
        self.session = {"cpu": 0.0, "gpu": 0.0}
        self.save()

    session = {"cpu": 0.0, "gpu": 0.0}

    # ---------------------------------------------------------------- sampling
    def _wsl_busy(self):
        """WSL VM busy % since the last call (all its CPUs)."""
        try:
            f = [int(x) for x in open("/proc/stat").readline().split()[1:]]
        except OSError:
            return None
        idle, total = f[3] + f[4], sum(f[:8])
        prev, self._stat = self._stat, (idle, total)
        if not prev or total == prev[1]:
            return None
        return 100.0 * (1 - (idle - prev[0]) / (total - prev[1]))

    def _run(self):
        enc = base64.b64encode(SCRIPT.encode("utf-16-le")).decode()
        while True:
            try:
                p = subprocess.Popen([PS, "-NoProfile", "-NonInteractive", "-EncodedCommand", enc],
                                     stdin=subprocess.DEVNULL, stdout=subprocess.PIPE,
                                     stderr=subprocess.DEVNULL, text=True, encoding="utf-8", errors="replace")
                self.error = None
                for line in p.stdout:
                    line = line.strip()
                    if line.startswith("{"):
                        try:
                            self._sample(json.loads(line))
                        except Exception as e:      # keep sampling whatever happens
                            self.error = f"bad sample: {e}"
                p.wait()
                self.error = "the sampler stopped; restarting"
            except OSError as e:
                self.error = f"can't start PowerShell: {e}"
            time.sleep(10)

    def _sample(self, d):
        s = self.settings()["hw"]
        t = time.time()
        cpu_load = min(100.0, max(0.0, float(d.get("cpu") or 0)))
        ncpu = int(d.get("ncpu") or os.cpu_count() or 1)
        wsl = self._wsl_busy()
        wsl_share = (wsl or 0.0) * (os.cpu_count() or ncpu) / ncpu
        other = max(0.0, cpu_load - wsl_share)

        lhm = {}
        for item in d.get("lhm") or []:
            k, _, v = str(item).rpartition("=")
            lhm[k] = v
        cpu_temp = cpu_power = None
        for k, v in lhm.items():
            kl = k.lower()
            if "/temperatures/" in kl and cpu_temp is None and re.search(r"cpu package$|core average$|core max$", kl):
                cpu_temp = num(v)
            if "/powers/" in kl and re.search(r"(cpu )?package$", kl) and cpu_power is None:
                cpu_power = num(v)
        estimated = cpu_power is None
        if estimated:
            cpu_power = s["cpu_idle_w"] + cpu_load / 100.0 * (s["cpu_max_w"] - s["cpu_idle_w"])

        gpu = {}
        if d.get("gpu"):
            parts = [x.strip() for x in str(d["gpu"]).split(",")]
            if len(parts) >= 7:
                gpu = {"name": parts[0], "temp": num(parts[1]), "load": num(parts[2]), "power": num(parts[3]),
                       "limit": num(parts[4]), "mem_used": num(parts[5]), "mem_total": num(parts[6])}
        gpu_power = gpu.get("power") or 0.0

        with self.lock:
            if self.last_t is not None:
                dt = min(15.0, t - self.last_t)
                ec, eg = cpu_power * dt / 3.6e6, gpu_power * dt / 3.6e6
                e = self.energy
                e["total"]["cpu"] += ec
                e["total"]["gpu"] += eg
                if estimated:
                    e["cpu_estimated"] = e.get("cpu_estimated", 0.0) + ec
                day = e["days"].setdefault(time.strftime("%Y-%m-%d"), {"cpu": 0.0, "gpu": 0.0})
                day["cpu"] += ec
                day["gpu"] += eg
                self.session["cpu"] += ec
                self.session["gpu"] += eg
            self.last_t = t
            self.now = {"t": t, "cpu_load": round(cpu_load, 1), "cpu_temp": cpu_temp, "cpu_power": round(cpu_power, 1),
                        "cpu_estimated": estimated, "wsl_load": None if wsl is None else round(wsl_share, 1),
                        "other_load": round(other, 1), "gpu": gpu, "lhm": bool(lhm), "ncpu": ncpu}
            self.samples.append([round(t, 1), self.now["cpu_load"], cpu_temp, self.now["cpu_power"],
                                 gpu.get("load"), gpu.get("temp"), gpu.get("power"), self.now["other_load"]])
        if t - self.last_save > 60:
            self.last_save = t
            try:
                self.save()
            except OSError:
                pass
        if self.on_sample:
            self.on_sample(self.now)

    def state(self, since=0):
        with self.lock:
            e = json.loads(json.dumps(self.energy))
            return {"now": self.now, "error": self.error, "energy": e, "session": dict(self.session),
                    "today": e["days"].get(time.strftime("%Y-%m-%d"), {"cpu": 0.0, "gpu": 0.0}),
                    "samples": [x for x in self.samples if x[0] > since]}
