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

void ft_PyUnstable_Exc_PrepReraiseStar(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    if ((cpu->regs[0])==0) goto L_c5fa4;
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 30) & 1)) goto L_c5fc0;
L_c5fa4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 3072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc5fbcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c60ac;
L_c5fc0:
    cpu->regs[19] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_c5fd4;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 25) & 1)) goto L_c5ff0;
L_c5fd4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 3112ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc5fecULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c60ac;
L_c5ff0:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
L_c6000:
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_GE) goto L_c604c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[2] << 3)));
    if ((cpu->regs[0])!=0) goto L_c6030;
L_c6014:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 3160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc602cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c60ac;
L_c6030:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 168));
    if (((cpu->regs[4] >> 30) & 1)) goto L_c6044;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_c6014;
L_c6044:
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    goto L_c6000;
L_c604c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    if ((cpu->regs[0])!=0) goto L_c6070;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 3200ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc606cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c60ac;
L_c6070:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_c6080;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_c6080:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c6098;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c6098;
    cpu->regs[30] = PB_BASE + 0xc6098ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c6098:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0xc5c68ULL); return; };
L_c60ac:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    { PB_CALL(7, cpu, tlb, PB_BASE + 0xc5c68ULL); return; };
    SP = SP - 96ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + 3232ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_STR((SP + 80), cpu->regs[25]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0xc610cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x173cc8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c6118;
L_c6110:
    cpu->regs[19] = 0ULL;
    goto L_c6294;
L_c6118:
    PB_LDRW(cpu->regs[24], (SP + 4));
    cpu->regs[21] = 25ULL;
    cpu->regs[19] = 64ULL;
L_c6124:
    cpu->regs[23] = ((uint64_t)(((int64_t)(cpu->regs[19] << (35-3)) ) >> 35));
    cpu->regs[0] = 1ULL;
    cpu->regs[23] = cpu->regs[23] & 2305843009213693944ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xc6138ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b8e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c614c;
    cpu->regs[30] = PB_BASE + 0xc6144ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_c6294;
L_c614c:
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xc615cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7bb40ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c61bc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc616cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7bcf0ULL);
    cpu->regs[30] = PB_BASE + 0xc6170ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(22ULL)));
    if (FLAG_EQ) goto L_c6190;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc618cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_c6110;
L_c6190:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] - 1ULL)); FLAG_CMP(cpu->regs[21], 0);
    if (FLAG_NE) goto L_c61b4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = cpu->regs[1] + 3256ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc61b0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c6110;
L_c61b4:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] << 1));
    goto L_c6124;
L_c61bc:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc61c4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c6280;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xc61d8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7b370ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[25] = 8ULL;
L_c61e0:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_c6274;
    cpu->regs[0] = ((uint32_t)(cpu->regs[22] >> 3));
    FLAG_CMP(cpu->regs[23], cpu->regs[0]);
    if (FLAG_LS) goto L_c626c;
    cpu->regs[0] = ((uint32_t)((cpu->regs[25] ? (uint64_t)((int64_t)cpu->regs[22] / (int64_t)cpu->regs[25]) : 0)));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] & 18446744073709551608ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[22] & 63);
    if (!((cpu->regs[0] >> 0) & 1)) goto L_c626c;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    cpu->regs[30] = PB_BASE + 0xc6210ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c6280;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6224ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x12b468ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c6248;
    if (((cpu->regs[3] >> 31) & 1)) goto L_c6280;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_c6280;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc6244ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c6280;
L_c6248:
    if (((cpu->regs[3] >> 31) & 1)) goto L_c6258;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[3]);
    if ((cpu->regs[3])==0) goto L_c6260;
L_c6258:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] - 1ULL));
    goto L_c626c;
L_c6260:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc6268ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c6258;
L_c626c:
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    goto L_c61e0;
L_c6274:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc627cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7bcf0ULL);
    goto L_c6294;
L_c6280:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6288ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7bcf0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6290ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_c6110;
L_c6294:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_c62b4;
    cpu->regs[30] = PB_BASE + 0xc62b4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c62b4:
    PB_LDR(cpu->regs[25], (SP + 80));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
}
