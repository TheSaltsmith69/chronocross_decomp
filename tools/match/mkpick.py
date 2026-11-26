import re,sys
src=sys.argv[1]; dst=sys.argv[2]; pick=dict(a.split('=') for a in sys.argv[3:])
b=re.split(r'^// @@(\S+)\n', open(src).read().replace('\r\n','\n'), flags=re.M)[1:]
d={}; order=[]; cnt={}
for n,c in zip(b[0::2],b[1::2]):
    i=cnt.get(n,0); cnt[n]=i+1
    if n not in order: order.append(n)
    if i==int(pick.get(n,0)): d[n]=c
open(dst,'w',newline='\n').write(''.join('// @@%s\n%s'%(n,d[n]) for n in order if n in d))
