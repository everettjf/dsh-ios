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

void ft_PyUnicode_AsEncodedString(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 80ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_147288;
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[20] | cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_146ecc;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x146dc4ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 1292));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_14711c;
L_146dd4:
    if ((cpu->regs[20])==0) goto L_146ecc;
L_146dd8:
    PB_LDRB(cpu->regs[5], (cpu->regs[20] + 0));
    cpu->regs[19] = SP + 8ULL;
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_146e74;
    cpu->regs[11] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[11], (cpu->regs[11] + 2272));
    cpu->regs[7] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3472));
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[10] = SP + 18ULL;
    cpu->regs[8] = 0ULL;
    cpu->regs[0] = 95ULL;
L_146e08:
    PB_LDRW(cpu->regs[6], (cpu->regs[11] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(46ULL)));
    cpu->regs[9] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[6] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_146e64;
L_146e20:
    FLAG_CMP(cpu->regs[4], cpu->regs[19]);
    cpu->regs[5] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[5]))) & (((uint32_t)(cpu->regs[8]))), 0);
    if (FLAG_NE) goto L_146f08;
L_146e30:
    FLAG_CMP(cpu->regs[4], cpu->regs[10]);
    if (FLAG_EQ) goto L_146f64;
    cpu->regs[7] += 1; PB_LDRB(cpu->regs[5], cpu->regs[7]);
    PB_LDRB(cpu->regs[6], (cpu->regs[3] + cpu->regs[9]));
    PB_STRB(cpu->regs[4], cpu->regs[6]); cpu->regs[4] += 1;
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_146e80;
    PB_LDRW(cpu->regs[6], (cpu->regs[11] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 2)));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(46ULL)));
    cpu->regs[9] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]));
    cpu->regs[8] = 0ULL;
    cpu->regs[5] = ((uint32_t)(cpu->regs[6] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[5], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_146e20;
L_146e64:
    cpu->regs[7] += 1; PB_LDRB(cpu->regs[5], cpu->regs[7]);
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_146e80;
    cpu->regs[8] = 1ULL;
    goto L_146e08;
L_146e74:
    cpu->regs[4] = cpu->regs[19];
    /* nop */
    /* nop */
L_146e80:
    PB_STRB((cpu->regs[4] + 0), 0ULL);
    PB_LDRB(cpu->regs[0], (SP + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(117ULL)));
    if (FLAG_NE) goto L_146f18;
    PB_LDRB(cpu->regs[0], (SP + 9));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(116ULL)));
    if (FLAG_NE) goto L_146f18;
    PB_LDRB(cpu->regs[0], (SP + 10));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(102ULL)));
    if (FLAG_NE) goto L_146f18;
    PB_LDRB(cpu->regs[0], (SP + 11));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(95ULL)));
    if (FLAG_NE) goto L_146fbc;
    PB_LDRB(cpu->regs[1], (SP + 12));
    cpu->regs[0] = SP + 12ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(56ULL)));
    if (FLAG_NE) goto L_146fc8;
L_146ec4:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 1));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_146fc8;
L_146ecc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_147118;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[2] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[1] = 0ULL;
    SP = SP + 80ULL;
    goto L_147310;
L_146f08:
    FLAG_CMP(cpu->regs[4], cpu->regs[10]);
    if (FLAG_EQ) goto L_146f64;
    PB_STRB(cpu->regs[4], cpu->regs[0]); cpu->regs[4] += 1;
    goto L_146e30;
L_146f18:
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2888ULL;
    cpu->regs[30] = PB_BASE + 0x146f28ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14707c;
L_146f2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_147118;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x14d360ULL); return; };
L_146f64:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x146f74ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x228b60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_147180;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 168));
    if (!((cpu->regs[1] >> 27) & 1)) goto L_147234;
L_146f88:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_147118;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_146fbc:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(56ULL)));
    cpu->regs[0] = SP + 11ULL;
    if (FLAG_EQ) goto L_146ec4;
L_146fc8:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(49ULL)));
    if (FLAG_NE) goto L_147024;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(54ULL)));
    if (FLAG_NE) goto L_146f64;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 2));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_146f64;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_147118;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[2] = 0ULL;
    SP = SP + 80ULL;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x228fc0ULL); return; };
L_147024:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(51ULL)));
    if (FLAG_NE) goto L_146f64;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 1));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(50ULL)));
    if (FLAG_NE) goto L_146f64;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 2));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_146f64;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_147118;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[2] = 0ULL;
    SP = SP + 80ULL;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x22a260ULL); return; };
L_14707c:
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3928ULL;
    cpu->regs[30] = PB_BASE + 0x14708cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_146f2c;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3944ULL;
    cpu->regs[30] = PB_BASE + 0x1470a0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1470e0;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3952ULL;
    cpu->regs[30] = PB_BASE + 0x1470b4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1470e0;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3960ULL;
    cpu->regs[30] = PB_BASE + 0x1470c8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1470e0;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3976ULL;
    cpu->regs[30] = PB_BASE + 0x1470dcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_146f64;
L_1470e0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_147118;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    { PB_CALL(12, cpu, tlb, PB_BASE + 0x234ee0ULL); return; };
L_147118:
    cpu->regs[30] = PB_BASE + 0x14711cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_14711c:
    cpu->regs[1] = cpu->regs[0] + (64ULL << 12);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 5208));
    if ((cpu->regs[1])==0) goto L_146dd4;
    cpu->regs[0] = cpu->regs[0] + 104ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])!=0) goto L_146dd4;
    if ((cpu->regs[20])==0) goto L_147188;
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 1576ULL;
    cpu->regs[30] = PB_BASE + 0x147148ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14722c;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 40ULL;
    cpu->regs[30] = PB_BASE + 0x14715cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14722c;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2888ULL;
    cpu->regs[30] = PB_BASE + 0x147170ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_14722c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14717cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1c7344ULL);
    if ((cpu->regs[0])!=0) goto L_147218;
L_147180:
    cpu->regs[19] = 0ULL;
    goto L_146f88;
L_147188:
    if ((cpu->regs[21])==0) goto L_146ecc;
L_14718c:
    cpu->regs[1] = PB_BASE + 0x281000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 3472ULL;
    cpu->regs[30] = PB_BASE + 0x14719cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_146dd4;
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 3288ULL;
    cpu->regs[30] = PB_BASE + 0x1471b0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_146dd4;
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 128ULL;
    cpu->regs[30] = PB_BASE + 0x1471c4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_146dd4;
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 2984ULL;
    cpu->regs[30] = PB_BASE + 0x1471d8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_146dd4;
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 1048ULL;
    cpu->regs[30] = PB_BASE + 0x1471ecULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7ae60ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_146dd4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1471f8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d3208ULL);
    if ((cpu->regs[0])==0) goto L_147180;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_146dd4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_146dd4;
    cpu->regs[30] = PB_BASE + 0x147214ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_146dd4;
L_147218:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_14722c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_147294;
L_14722c:
    if ((cpu->regs[21])!=0) goto L_14718c;
    goto L_146dd8;
L_147234:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3496));
    cpu->regs[30] = PB_BASE + 0x147240ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1472a0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 24));
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + 0ULL;
    cpu->regs[30] = PB_BASE + 0x147264ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x11f220ULL);
L_147264:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_147180;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_147180;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x147284ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_146f88;
L_147288:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x147290ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x22aba0ULL);
    goto L_146f88;
L_147294:
    cpu->regs[30] = PB_BASE + 0x147298ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if ((cpu->regs[21])!=0) goto L_14718c;
    goto L_146dd8;
L_1472a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3744));
    cpu->regs[2] = PB_BASE + 0x28d000ULL;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[2] + 3992ULL;
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1472c0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x24d184ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_147264;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    if ((cpu->regs[1])!=0) goto L_1472f8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
L_1472d4:
    cpu->regs[30] = PB_BASE + 0x1472d8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe9c70ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1472f0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_147300;
L_1472f0:
    cpu->regs[19] = cpu->regs[20];
    goto L_146f88;
L_1472f8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    goto L_1472d4;
L_147300:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x14730cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_146f88;
L_147310:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[6] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[29] = SP;
    SP = SP - 560ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 552), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1474b4;
    PB_LDRW(cpu->regs[0], (cpu->regs[6] + 32));
    if (!((cpu->regs[0] >> 6) & 1)) goto L_147388;
    PB_LDR(cpu->regs[5], (cpu->regs[6] + 32));
    if (!((cpu->regs[5] >> 5) & 1)) goto L_147498;
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 16));
    cpu->regs[0] = cpu->regs[6] + 40ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1473b4;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_LDR(cpu->regs[4], (SP + 552));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3]; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_147470;
L_14737c:
    SP = SP + 560ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(33, cpu, tlb, PB_BASE + 0xe9c70ULL); return; };
L_147388:
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 48));
    if ((cpu->regs[0])==0) goto L_147478;
L_147390:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 552));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_147470;
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 40));
    goto L_14737c;
L_1473b4:
    PB_STR((SP + 576), cpu->regs[19]);
L_1473b8:
    cpu->regs[7] = ((uint32_t)(((cpu->regs[5] >> 2) & 0x7ULL)));
    if (!((cpu->regs[5] >> 5) & 1)) goto L_1474ac;
    FLAG_CMP((((uint32_t)(cpu->regs[5]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[3] = cpu->regs[6] + 40ULL;
    cpu->regs[0] = cpu->regs[6] + 56ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[3];
L_1473d0:
    cpu->regs[19] = SP;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_147430;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x1473f4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1c67a8ULL);
    cpu->regs[1] = cpu->regs[0];
L_1473f8:
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[1])==0) goto L_147488;
    cpu->regs[30] = PB_BASE + 0x147404ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x11dec4ULL);
    PB_LDR(cpu->regs[19], (SP + 576));
L_147408:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 552));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_147470;
    SP = SP + 560ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_147430:
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_147450;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x147448ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1dd68cULL);
    cpu->regs[1] = cpu->regs[0];
    goto L_1473f8;
L_147450:
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x147468ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x216940ULL);
    cpu->regs[1] = cpu->regs[0];
    goto L_1473f8;
L_147470:
    PB_STR((SP + 576), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x147478ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7c170ULL);
L_147478:
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 16));
    PB_LDR(cpu->regs[5], (cpu->regs[6] + 32));
    PB_STR((SP + 576), cpu->regs[19]);
    goto L_1473b8;
L_147488:
    cpu->regs[30] = PB_BASE + 0x14748cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1fa1e0ULL);
    PB_LDR(cpu->regs[19], (SP + 576));
    cpu->regs[0] = 0ULL;
    goto L_147408;
L_147498:
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 48));
    if ((cpu->regs[0])!=0) goto L_147390;
    cpu->regs[7] = ((uint32_t)(((cpu->regs[5] >> 2) & 0x7ULL)));
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 16));
    PB_STR((SP + 576), cpu->regs[19]);
L_1474ac:
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 56));
    goto L_1473d0;
L_1474b4:
    cpu->regs[30] = PB_BASE + 0x1474b8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x22aba0ULL);
    cpu->regs[0] = 0ULL;
    goto L_147408;
}
