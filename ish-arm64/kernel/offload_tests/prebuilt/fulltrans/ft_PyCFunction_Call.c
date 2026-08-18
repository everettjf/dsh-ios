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

void ft_PyCFunction_Call(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x179548ULL; PB_CALL(1, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[5] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[5];
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x12660cULL); return; };
    SP = SP - 48ULL;
    cpu->regs[1] = cpu->tls_ptr;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x17958cULL; PB_CALL(3, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 168));
    if (!((cpu->regs[0] >> 11) & 1)) goto L_1795e8;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 56));
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[3];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_17967c;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_1795e0;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    FLAG_CMP(SP, cpu->regs[0]);
    if (FLAG_LO) goto L_17967c;
L_1795e0:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + cpu->regs[3]));
    if ((cpu->regs[4])!=0) goto L_179628;
L_1795e8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_179678;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[3] = 0ULL;
    SP = SP + 48ULL;
    cpu->regs[2] = 0ULL;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0xea120ULL); return; };
L_179628:
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x17963cULL; PB_CALL(5, cpu, tlb, cpu->regs[4]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_179678;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0xe8888ULL); return; };
L_179678:
    cpu->regs[30] = PB_BASE + 0x17967cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7c170ULL);
L_17967c:
    __builtin_trap();
L_179680:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_179788;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_179798;
L_1796b4:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1796c8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x10e300ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_17975c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1797a4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1796e4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179758;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_179734;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(53ULL)));
    if (FLAG_EQ) goto L_179758;
L_17970c:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_179720:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_179734:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x17973cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_179774;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 16),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(53ULL)));
    if (FLAG_NE) goto L_17970c;
L_179758:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
L_17975c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = cpu->regs[21];
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_179720;
L_179774:
    cpu->regs[0] = 1ULL;
    cpu->regs[21] = cpu->regs[20];
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_17975c;
L_179788:
    cpu->regs[30] = PB_BASE + 0x17978cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1796b4;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_179798:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[20] = 0ULL;
    goto L_179720;
L_1797a4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_179720;
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1799b4;
L_1797ec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1799c8;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x179800ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1799bc;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1799c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179818ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x118d8cULL);
    if ((cpu->regs[0])==0) goto L_179908;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179830ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x118d8cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_17988c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 16ULL;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x179848ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_17995c;
    cpu->regs[22] = 2ULL;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[22];
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[0] + 8), cpu->regs[21]);
L_179860:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[23] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x17986cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x118d8cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179924;
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_EQ) goto L_179934;
L_17987c:
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[22] << 3)), cpu->regs[21]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_179860;
L_17988c:
    cpu->regs[23] = 1ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
L_179894:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_179988;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1798a8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179990;
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_1798dc;
    cpu->regs[1] = 0ULL;
L_1798bc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[1] = cpu->regs[1] << 3;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[1]));
    PB_STR((cpu->regs[0] + cpu->regs[1]), cpu->regs[2]);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    FLAG_CMP(cpu->regs[23], cpu->regs[21]);
    if (FLAG_GT) goto L_1798bc;
L_1798dc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1798e4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1798f0:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_179908:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_17990c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x179914ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[22] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1798f0;
L_179924:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    if ((cpu->regs[22])==0) goto L_179950;
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_179894;
L_179934:
    cpu->regs[24] = cpu->regs[24] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24] << 3;
    cpu->regs[30] = PB_BASE + 0x179944ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_17995c;
    cpu->regs[20] = cpu->regs[0];
    goto L_17987c;
L_179950:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_17990c;
L_17995c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x179964ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x179974ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1798f0;
L_179988:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_17990c;
L_179990:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x179998ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1799a4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1798f0;
L_1799b4:
    cpu->regs[30] = PB_BASE + 0x1799b8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1797ec;
L_1799bc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1799c8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1799c8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[22] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1798f0;
    /* nop */
    /* nop */
L_1799e0:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_179ae8;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_179af8;
L_179a14:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x179a28ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x118420ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_179abc;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_179b04;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179a44ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x179680ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179ab8;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_179a94;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(22ULL)));
    if (FLAG_EQ) goto L_179ab8;
L_179a6c:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_179a80:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_179a94:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179a9cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_179ad4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 16),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(22ULL)));
    if (FLAG_NE) goto L_179a6c;
L_179ab8:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
L_179abc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = cpu->regs[21];
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_179a80;
L_179ad4:
    cpu->regs[0] = 1ULL;
    cpu->regs[21] = cpu->regs[20];
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_179abc;
L_179ae8:
    cpu->regs[30] = PB_BASE + 0x179aecULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_179a14;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_179af8:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[20] = 0ULL;
    goto L_179a80;
L_179b04:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_179a80;
    /* nop */
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_179e58;
L_179b48:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_179e48;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x179b64ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1799e0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179d64;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_179de8;
L_179b84:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_179d58;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x179b98ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179d4c;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[25])))!=0) goto L_179e08;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_179d70;
L_179bb8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(12ULL)));
    if (FLAG_EQ) goto L_179bd4;
L_179bcc:
    cpu->regs[24] = 0ULL;
    goto L_179c88;
L_179bd4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179be4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1799e0ULL);
    if ((cpu->regs[0])==0) goto L_179bcc;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16) + 4);
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[22];
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_179da0;
L_179bfc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(12ULL)));
    if (FLAG_EQ) goto L_179c18;
L_179c10:
    cpu->regs[24] = 1ULL;
    goto L_179c88;
L_179c18:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179c28ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1799e0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179c10;
    cpu->regs[1] = 16ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x179c40ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179e1c;
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[26] = 2ULL;
    cpu->regs[28] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[22];
    PB_STR((cpu->regs[1] + 8), cpu->regs[24]);
L_179c60:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 20));
    cpu->regs[24] = cpu->regs[26];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_179db4;
L_179c70:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(12ULL)));
    if (FLAG_EQ) goto L_179cf0;
L_179c84:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_179c88:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x179c98ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179df4;
    FLAG_CMP(cpu->regs[24], 0ULL);
    if (FLAG_GT) goto L_179d24;
L_179ca8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x179cb0ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x179cccULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x118accULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_179cd4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_179ce0:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_179cf0:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179d00ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1799e0ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_179c84;
    FLAG_CMP(cpu->regs[28], cpu->regs[26]);
    if (FLAG_EQ) goto L_179d84;
L_179d10:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[26] << 3)), cpu->regs[27]);
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    cpu->regs[22] = cpu->regs[0];
    goto L_179c60;
L_179d24:
    cpu->regs[0] = 0ULL;
L_179d28:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[25]));
    FLAG_CMP(cpu->regs[24], cpu->regs[25]);
    if (FLAG_LE) goto L_179ca8;
    goto L_179d28;
L_179d4c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x179d58ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x22d780ULL);
L_179d58:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
L_179d64:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[23]);
    goto L_179cd4;
L_179d70:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179d78ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_179dc8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_179bb8;
L_179d84:
    cpu->regs[28] = cpu->regs[28] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[28] << 3;
    cpu->regs[30] = PB_BASE + 0x179d94ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_179e1c;
    cpu->regs[20] = cpu->regs[0];
    goto L_179d10;
L_179da0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179da8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_179de0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_179bfc;
L_179db4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179dbcULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_179dd8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    goto L_179c70;
L_179dc8:
    cpu->regs[24] = 0ULL;
L_179dcc:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    goto L_179c88;
L_179dd8:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_179dcc;
L_179de0:
    cpu->regs[24] = 1ULL;
    goto L_179dcc;
L_179de8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x179df0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_179b84;
L_179df4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x179dfcULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x179e08ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x22d780ULL);
L_179e08:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_179d64;
L_179e1c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x179e24ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x179e30ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_179d64;
L_179e48:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_179ce0;
L_179e58:
    cpu->regs[30] = PB_BASE + 0x179e5cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_179b48;
L_179e60:
    cpu->regs[0] = PB_BASE + 0x53c000ULL;
    cpu->regs[0] = cpu->regs[0] + 3256ULL;
    cpu->regs[1] = PB_BASE + 0x53c000ULL;
    cpu->regs[1] = cpu->regs[1] + 3256ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_179e8c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2664));
    if ((cpu->regs[1])==0) goto L_179e8c;
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_179e8c:
    return;
L_179e90:
    cpu->regs[0] = PB_BASE + 0x53c000ULL;
    cpu->regs[0] = cpu->regs[0] + 3256ULL;
    cpu->regs[1] = PB_BASE + 0x53c000ULL;
    cpu->regs[1] = cpu->regs[1] + 3256ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[2] = cpu->regs[1] >> 63;
    cpu->regs[1] = cpu->regs[2] + ((uint64_t)((int64_t)cpu->regs[1] >> 3));
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 1);
    if ((cpu->regs[1])==0) goto L_179ec8;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3264));
    if ((cpu->regs[2])==0) goto L_179ec8;
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_179ec8:
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = PB_BASE + 0x5ac000ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 3728));
    if (((cpu->regs[0] >> 0) & 1)) goto L_179f20;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3104));
    if ((cpu->regs[0])==0) goto L_179efc;
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x179efcULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x7b660ULL);
L_179efc:
    cpu->regs[30] = PB_BASE + 0x179f00ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x179e60ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2440));
    if ((cpu->regs[0])==0) goto L_179f18;
    cpu->regs[0] = PB_BASE + 0x37c000ULL;
    cpu->regs[0] = cpu->regs[0] + 3496ULL;
    cpu->regs[30] = PB_BASE + 0x179f18ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x7adc0ULL);
L_179f18:
    cpu->regs[0] = 1ULL;
    PB_STRB((cpu->regs[19] + 3728), cpu->regs[0]);
L_179f20:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3112));
    if ((cpu->regs[0])==0) goto L_179f5c;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x5ac000ULL;
    cpu->regs[0] = PB_BASE + 0x37c000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3736ULL;
    cpu->regs[0] = cpu->regs[0] + 3496ULL;
    cpu->regs[30] = PB_BASE + 0x179f54ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x7b680ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    goto L_179e90;
L_179f5c:
    goto L_179e90;
}
