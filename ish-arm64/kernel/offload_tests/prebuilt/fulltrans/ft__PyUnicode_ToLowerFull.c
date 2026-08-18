/* AUTO-GENERATED prebuilt-gadget spec_fn for guest `_PyToken_OneChar` — DO NOT EDIT.
 * Source: /tmp/pyroot/fs/usr/lib/debug/usr/lib/libpython3.12.so.1.0.debug  addr 0xef9ab4e0
 * Produced by tools/prebuilt_gadget_gen/gen.sh (guest asm -> equivalent C).
 * Compiled only with -Doffload_test_prebuilt=true. */
#include <stdint.h>
#include "emu/arch/arm64/cpu.h"
#include "emu/tlb.h"
#include "kernel/native_offload.h"  /* prebuilt_call for bl/blr sites */

static uint64_t ror64(uint64_t v, unsigned r) { return (v >> r) | (v << (64 - r)); }
static uint64_t g_fa, g_fb;
static double fr[32];   /* float/double register file (s/d regs) */
/* FCMP: encode float ordering into g_fa/g_fb so the integer FLAG_* macros
 * that follow a fcmp read the right branch. sign(lhs-rhs) → (1,0)/(0,1)/(0,0);
 * NaN (unordered) → (0,1): gt/ge false, matching AArch64 fcmp semantics. */
#define FCMP(x,y) do { double _dx=(x), _dy=(y); \
    if (_dx < _dy) { g_fa=0; g_fb=1; } \
    else if (_dx > _dy) { g_fa=1; g_fb=0; } \
    else if (_dx == _dy) { g_fa=0; g_fb=0; } \
    else { g_fa=0; g_fb=1; } } while(0)   /* NaN */
#define FLAG_CMP(x,y) do { g_fa=(x); g_fb=(y); } while(0)
#define FLAG_EQ (g_fa == g_fb)
#define FLAG_NE (g_fa != g_fb)
#define FLAG_GT ((int64_t)g_fa >  (int64_t)g_fb)   /* signed */
#define FLAG_LT ((int64_t)g_fa <  (int64_t)g_fb)
#define FLAG_GE ((int64_t)g_fa >= (int64_t)g_fb)
#define FLAG_LE ((int64_t)g_fa <= (int64_t)g_fb)
#define FLAG_HI (g_fa >  g_fb)                     /* unsigned */
#define FLAG_LO (g_fa <  g_fb)
#define FLAG_HS (g_fa >= g_fb)
#define FLAG_LS (g_fa <= g_fb)
#define SP (cpu->sp)                               /* stack pointer */
/* PB_BASE: library load base = runtime addr (0xef9ab4e0) - file offset (0x00000000000874e0).
 * adrp/adr targets (file-absolute in the disassembly) resolve to
 * PB_BASE + target at runtime. No-ASLR makes this constant. */
extern uint64_t g_ft_base;
#define PB_BASE g_ft_base
/* Memory ops go through the guest TLB (fork/CoW safe). 64/32-bit + byte. */
#define PB_LDR(dst, addr)  do { uint64_t _v=0; tlb_read (tlb,(addr),&_v,8); (dst)=_v; } while(0)
#define PB_STR(addr, val)  do { uint64_t _v=(val); tlb_write(tlb,(addr),&_v,8); } while(0)
#define PB_LDRW(dst, addr) do { uint32_t _v=0; tlb_read (tlb,(addr),&_v,4); (dst)=_v; } while(0)
#define PB_STRW(addr, val) do { uint32_t _v=(uint32_t)(val); tlb_write(tlb,(addr),&_v,4); } while(0)
#define PB_LDRB(dst, addr) do { uint8_t  _b=0; tlb_read (tlb,(addr),&_b,1); (dst)=_b; } while(0)
#define PB_STRB(addr, val) do { uint8_t  _b=(uint8_t)(val); tlb_write(tlb,(addr),&_b,1); } while(0)
#define PB_LDRH(dst, addr) do { uint16_t _h=0; tlb_read (tlb,(addr),&_h,2); (dst)=_h; } while(0)
#define PB_STRH(addr, val) do { uint16_t _h=(uint16_t)(val); tlb_write(tlb,(addr),&_h,2); } while(0)
/* Inline-cache call: if the callee (guest addr `tgt`) has a translated
 * spec_fn, call it directly (stays in host code, no interpreter round-
 * trip); otherwise fall back to prebuilt_call (nested dispatch). Each
 * call site has its own static IC slot keyed by the last target. */
#define PB_CALL(id, cpu, tlb, tgt) do {                       \
    static addr_t _ic_tgt##id = 0; static prebuilt_fn _ic_fn##id = 0; \
    addr_t _t = (tgt);                                        \
    if (_t == _ic_tgt##id && _ic_fn##id) { _ic_fn##id(cpu, tlb); } \
    else { prebuilt_fn _f = native_offload_prebuilt_lookup(_t);\
           if (_f) { _ic_tgt##id = _t; _ic_fn##id = _f; _f(cpu, tlb); } \
           else { prebuilt_call(cpu, tlb, _t); } }            \
  } while(0)

void ft__PyUnicode_ToLowerFull(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[1];
    cpu->regs[6] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x24da38ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x10a220ULL);
    PB_LDRH(cpu->regs[1], (cpu->regs[0] + 14));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 4));
    if (((cpu->regs[1] >> 14) & 1)) goto L_24da58;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[6]));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[1]);
L_24da50:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_24da58:
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] & 65535ULL));
    cpu->regs[2] = PB_BASE + 0x347000ULL;
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 24)));
    cpu->regs[2] = cpu->regs[2] + 2464ULL;
    cpu->regs[1] = 0ULL;
L_24da6c:
    cpu->regs[3] = ((uint32_t)(cpu->regs[4] + cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_24da50;
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[3])) << 2)));
    PB_STRW((cpu->regs[5] + (cpu->regs[1] << 2)), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_24da6c;
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 88), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 160));
    PB_STR((cpu->regs[2] + 0), 0ULL);
    PB_STR((cpu->regs[19] + 0), 0ULL);
    if ((cpu->regs[1])==0) goto L_24dacc;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])!=0) goto L_24db28;
L_24dacc:
    cpu->regs[20] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24dad8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x24db40ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24db34;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 24));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24daf4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11ec60ULL);
L_24daf4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 88));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_24db24;
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_24db24:
    cpu->regs[30] = PB_BASE + 0x24db28ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_24db28:
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 3856ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
L_24db34:
    cpu->regs[19] = 18446744073709551615ULL;
    goto L_24daf4;
    /* nop */
L_24db40:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24db60ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11e5ccULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24db8c;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 67ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24db74ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x14cdc4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_24dba0;
L_24db78:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_24db8c:
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[0] = cpu->regs[0] + 3888ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_24db78;
L_24dba0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24dba8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[0] = cpu->regs[0] + 3392ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_24db78;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    if ((cpu->regs[0])==0) goto L_24dbf0;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x24dbecULL; PB_CALL(8, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24dc34;
L_24dbf0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 80));
    if ((cpu->regs[0])==0) goto L_24dc04;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24dc00ULL; PB_CALL(9, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24dc34;
L_24dc04:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 104));
    if ((cpu->regs[0])==0) goto L_24dc18;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24dc14ULL; PB_CALL(10, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24dc34;
L_24dc18:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x1de120ULL); return; };
L_24dc34:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 96ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3720));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24dc80ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24de24;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3656));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x24dc98ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_24e174;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24dca8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x2479e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24df8c;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24dcb8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x247ae0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24df8c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24dcc4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x247b50ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24df8c;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0] + 32ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24dce0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7b200ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24e090;
    cpu->regs[30] = PB_BASE + 0x24dcecULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1947a0ULL);
    if ((cpu->regs[0])==0) goto L_24e040;
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0x24dcf8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x24e200ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_24dd10;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_24e0bc;
L_24dd10:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24e084;
    PB_LDR(cpu->regs[22], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[2] = cpu->regs[23] + cpu->regs[22];
    do { int32_t _s=0; tlb_read(tlb,(SP + 4),&_s,4); cpu->regs[24] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[22];
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_LT) goto L_24df94;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_24dfc4;
    if (FLAG_LE) goto L_24de0c;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_24df70;
L_24dd48:
    PB_LDRB(cpu->regs[21], (cpu->regs[23] + cpu->regs[22]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] & 240ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(224ULL)));
    if (FLAG_NE) goto L_24df94;
    PB_LDRB(cpu->regs[1], (cpu->regs[2] + 1));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] & 192ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(128ULL)));
    if (FLAG_NE) goto L_24df94;
    PB_LDRB(cpu->regs[0], (cpu->regs[2] + 2));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] & 192ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(128ULL)));
    if (FLAG_NE) goto L_24df94;
    cpu->regs[21] = ((uint32_t)(((cpu->regs[21] & 0xfULL) << 12)));
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] & 0x3fULL) << 6)));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + cpu->regs[1]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 63ULL));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + cpu->regs[0]));
L_24dd8c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24dda0;
L_24dd94:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24e0e0;
L_24dda0:
    cpu->regs[0] = 4294912000ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2047ULL)));
    if (FLAG_HI) goto L_24df78;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24ddb8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x15d988ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24e068;
    cpu->regs[2] = cpu->regs[22] + cpu->regs[24];
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2704ULL;
    cpu->regs[30] = PB_BASE + 0x24ddd0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe3f40ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_24dddc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_24e008;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 96ULL;
    return;
L_24de0c:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_24dff8;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_24dd48;
    PB_LDRH(cpu->regs[21], (cpu->regs[23] + cpu->regs[22]));
    goto L_24dd8c;
L_24de24:
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24de30ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x248268ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24df8c;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24de40ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x248364ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24df8c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24de4cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x2483e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24df8c;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x24de60ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x24e1e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24e154;
    cpu->regs[30] = PB_BASE + 0x24de6cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1947a0ULL);
    if ((cpu->regs[0])==0) goto L_24e198;
    cpu->regs[1] = SP + 4ULL;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x24de7cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x24e200ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[23] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_24de94;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_24e118;
L_24de94:
    FLAG_CMP(cpu->regs[23], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24e084;
    do { int32_t _s=0; tlb_read(tlb,(SP + 4),&_s,4); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = 9223372036854775807ULL;
    PB_LDR(cpu->regs[22], (SP + 8)); PB_LDR(cpu->regs[24], (SP + 8) + 8);
    cpu->regs[0] = (cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[2]) : 0);
    cpu->regs[1] = cpu->regs[24] - cpu->regs[22];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_GT) goto L_24e130;
L_24deb8:
    cpu->regs[1] = cpu->regs[2] * cpu->regs[1];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24dec4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24e090;
    cpu->regs[30] = PB_BASE + 0x24ded0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1063e8ULL);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[6] = 4294912000ULL;
L_24ded8:
    FLAG_CMP(cpu->regs[22], cpu->regs[24]);
    if (FLAG_LT) goto L_24df2c;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2840ULL;
    cpu->regs[30] = PB_BASE + 0x24def4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_24df0c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_24e124;
L_24df0c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24df20;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24e140;
L_24df20:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_24dddc;
L_24df2c:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24df38ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x2483f0ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[6]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2047ULL)));
    if (FLAG_HI) goto L_24e0ec;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_24dfdc;
    if (FLAG_GT) goto L_24dfa4;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_24dfd0;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_24e014;
    PB_STRH(cpu->regs[5], cpu->regs[0]); cpu->regs[5] += 2;
L_24df68:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_24ded8;
L_24df70:
    PB_LDRW(cpu->regs[21], (cpu->regs[23] + cpu->regs[22]));
    goto L_24dd8c;
L_24df78:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24df84ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_24df8c:
    cpu->regs[19] = 0ULL;
    goto L_24dddc;
L_24df94:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24df78;
    cpu->regs[21] = 0ULL;
    goto L_24dd94;
L_24dfa4:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_24e014;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    PB_STRH(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 4;
    PB_STRH((cpu->regs[5] + 2), 0ULL);
    cpu->regs[5] = cpu->regs[1];
    goto L_24ded8;
L_24dfc4:
    PB_LDRW(cpu->regs[21], (cpu->regs[23] + cpu->regs[22]));
    cpu->regs[21] = (uint64_t)__builtin_bswap32((uint32_t)cpu->regs[21]);
    goto L_24dd8c;
L_24dfd0:
    cpu->regs[0] = (cpu->regs[0] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[0] & 0x00ff00ff00ff00ffULL) << 8;
    PB_STRH(cpu->regs[5], cpu->regs[0]); cpu->regs[5] += 2;
    goto L_24df68;
L_24dfdc:
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = (cpu->regs[0] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[0] & 0x00ff00ff00ff00ffULL) << 8;
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    PB_STRH(cpu->regs[1], 0ULL); cpu->regs[1] += 4;
    PB_STRH((cpu->regs[5] + 2), cpu->regs[0]);
    cpu->regs[5] = cpu->regs[1];
    goto L_24ded8;
L_24dff8:
    PB_LDRH(cpu->regs[21], (cpu->regs[23] + cpu->regs[22]));
    cpu->regs[21] = (cpu->regs[21] & 0xff00ff00ff00ff00ULL) >> 8 | (cpu->regs[21] & 0x00ff00ff00ff00ffULL) << 8;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] & 65535ULL));
    goto L_24dd8c;
L_24e008:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x24e014ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x7c170ULL);
L_24e014:
    cpu->regs[0] = ((cpu->regs[0] >> 6) & 0x3fULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 63ULL));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 4294967168ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 4294967168ULL));
    cpu->regs[2] = 4294967277ULL;
    cpu->regs[5] = cpu->regs[5] + 3ULL;
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    PB_STRB((cpu->regs[5] + -3), cpu->regs[2]);
    PB_STRB((cpu->regs[5] + -2), cpu->regs[0]);
    PB_STRB((cpu->regs[5] + -1), cpu->regs[1]);
    goto L_24ded8;
L_24e040:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24e054;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24e078;
L_24e054:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24e068;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24e0c8;
L_24e068:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_24dddc;
L_24e078:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24e080ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24e054;
L_24e084:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24e090ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
L_24e090:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24e068;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24e068;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24e0b0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_24dddc;
L_24e0bc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24e0c4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24dd10;
L_24e0c8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24e0d4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_24dddc;
L_24e0e0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24e0e8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24dda0;
L_24e0ec:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24e0f8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24e090;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24e090;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24e114ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24e090;
L_24e118:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24e120ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24de94;
L_24e124:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24e12cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24df0c;
L_24e130:
    cpu->regs[24] = cpu->regs[22] + cpu->regs[0];
    cpu->regs[1] = cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[24]);
    goto L_24deb8;
L_24e140:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24e148ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_24dddc;
L_24e154:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24e168;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24e184;
L_24e168:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[19] = 0ULL;
    goto L_24dddc;
L_24e174:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24e180ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xb26a4ULL);
    goto L_24dddc;
L_24e184:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24e190ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_24dddc;
L_24e198:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24e1ac;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24e1d4;
L_24e1ac:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24e168;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24e168;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24e1ccULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_24dddc;
L_24e1d4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24e1dcULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24e1ac;
}
