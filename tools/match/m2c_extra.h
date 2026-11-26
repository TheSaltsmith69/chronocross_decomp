/* Prototypes for decomp.py's m2c context: functions the C sources call without a
 * declaration (or haven't met yet). A line is skipped when the context already
 * declares its first symbol. Add to this as signatures become known. */
u8 *func_8009C9F4(u8 *parent, void *fn);
void func_8009CA60(u8 *task);
u8 *func_8009CB34(u8 *prev, void *fn);
void func_80029DD8(char *fmt, char *where, s32 value);
