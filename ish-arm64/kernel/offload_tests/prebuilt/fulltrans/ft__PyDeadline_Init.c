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

void ft__PyDeadline_Init(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 48ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x226c10ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x227088ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = SP;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x226c24ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x21c6ecULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_226c54;
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
L_226c54:
    cpu->regs[30] = PB_BASE + 0x226c58ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    SP = SP - 144ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[26] = cpu->regs[3];
    PB_STR((SP + 96), cpu->regs[27]); PB_STR((SP + 96) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x226c94ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1e17e0ULL);
    if ((cpu->regs[0])==0) goto L_226f98;
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x226ca4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1e17e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_226fd8;
    if ((cpu->regs[27])!=0) goto L_226f50;
L_226cb0:
    PB_LDR(cpu->regs[28], (cpu->regs[21] + 16));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x226cbcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x227188ULL);
    cpu->regs[22] = cpu->regs[0];
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_226f04;
    if ((cpu->regs[0])==0) goto L_226cdc;
    cpu->regs[30] = PB_BASE + 0x226cd0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x227228ULL);
    if ((cpu->regs[0])==0) goto L_226cdc;
    cpu->regs[30] = PB_BASE + 0x226cd8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x2272c4ULL);
    if (((cpu->regs[0] >> 0) & 1)) goto L_226f04;
L_226cdc:
    cpu->regs[20] = cpu->regs[22];
L_226ce0:
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_NE) goto L_226e3c;
L_226ce8:
    if ((cpu->regs[20])==0) goto L_226f28;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 112));
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_226d0c;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_226d0c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226d14ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x2273a0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[27] = cpu->regs[0];
    if (((cpu->regs[2] >> 31) & 1)) goto L_226d2c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_226fe4;
L_226d2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 34072ULL;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 120), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x226d4cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1977e4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_226fa0;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_226d64;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_226d64:
    cpu->regs[28] = cpu->regs[20];
L_226d68:
    PB_LDR(cpu->regs[0], (SP + 120));
    cpu->regs[1] = 30760ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x226d7cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1977e4ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_226da0;
    if ((cpu->regs[0])==0) goto L_227038;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_227038;
L_226da0:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_226db0;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_226db0:
    PB_STR((SP + 0), cpu->regs[26]);
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[6] = cpu->regs[28];
    cpu->regs[5] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[7] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x226dd8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1e19c0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_226df0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_227060;
L_226df0:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_226e04;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22706c;
L_226e04:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_226e18;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_227078;
L_226e18:
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
L_226e1c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    PB_LDR(cpu->regs[27], (SP + 96)); PB_LDR(cpu->regs[28], (SP + 96) + 8);
    SP = SP + 144ULL;
    return;
L_226e3c:
    if ((cpu->regs[20])==0) goto L_226f28;
L_226e40:
    cpu->regs[22] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226e4cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x227330ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_226e64;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_226f1c;
L_226e64:
    if ((cpu->regs[20])==0) goto L_226ff0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226e70ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x227228ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_226ff0;
    cpu->regs[30] = PB_BASE + 0x226e7cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x2272c4ULL);
    if (((cpu->regs[0] >> 0) & 1)) goto L_226e40;
    if ((cpu->regs[27])==0) goto L_226ce0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_226ce0;
    PB_LDR(cpu->regs[7], (cpu->regs[27] + 16));
    cpu->regs[6] = cpu->regs[27] + 24ULL;
    cpu->regs[5] = 0ULL;
L_226e9c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[3] = 18446744073709551615ULL;
    cpu->regs[2] = 0ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    if (FLAG_LE) goto L_226ce0;
    PB_LDR(cpu->regs[1], (cpu->regs[6] + (cpu->regs[5] << 3)));
    PB_STR((SP + 120), cpu->regs[5]); PB_STR((SP + 120) + 8, cpu->regs[6]);
    PB_STR((SP + 136), cpu->regs[7]);
    cpu->regs[30] = PB_BASE + 0x226ec4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1de1e0ULL);
    PB_LDR(cpu->regs[5], (SP + 120));
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_226e40;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_226ce0;
    PB_LDR(cpu->regs[6], (SP + 128)); PB_LDR(cpu->regs[7], (SP + 128) + 8);
    goto L_226e9c;
L_226ee4:
    if ((cpu->regs[22])==0) goto L_226f28;
    cpu->regs[30] = PB_BASE + 0x226eecULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x227330ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_226f04;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_226f44;
L_226f04:
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[20] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[22];
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_GT) goto L_226ee4;
    goto L_226ce8;
L_226f1c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x226f24ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_226e64;
L_226f28:
    PB_LDR(cpu->regs[19], (cpu->regs[28] + 352));
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[27] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3624ULL;
    cpu->regs[30] = PB_BASE + 0x226f3cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[22] = cpu->regs[0];
    goto L_226d2c;
L_226f44:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226f4cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_226f04;
L_226f50:
    PB_LDR(cpu->regs[3], (cpu->regs[27] + 16));
    cpu->regs[1] = cpu->regs[27] + 24ULL;
    cpu->regs[0] = 0ULL;
L_226f5c:
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LE) goto L_226cb0;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 168));
    if (((cpu->regs[4] >> 28) & 1)) goto L_226f5c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 680ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x226f94ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
L_226f98:
    cpu->regs[19] = 0ULL;
    goto L_226e1c;
L_226fa0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    if ((cpu->regs[0])==0) goto L_226ff8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_226ff8;
L_226fb0:
    cpu->regs[28] = 0ULL;
L_226fb4:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x226fbcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226fc4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_226fd8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_227024;
L_226fd8:
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[19] = 0ULL;
    goto L_226e1c;
L_226fe4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226fecULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_226d2c;
L_226ff0:
    cpu->regs[22] = cpu->regs[20];
    goto L_226cdc;
L_226ff8:
    cpu->regs[30] = PB_BASE + 0x226ffcULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_226fb0;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = 34072ULL;
    PB_LDR(cpu->regs[0], (SP + 120));
    cpu->regs[1] = cpu->regs[0] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22701cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_226d68;
    goto L_226fb4;
L_227024:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x227030ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    goto L_226e1c;
L_227038:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    if ((cpu->regs[0])==0) goto L_227048;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_226fb4;
L_227048:
    cpu->regs[0] = PB_BASE + 0x293000ULL;
    cpu->regs[0] = cpu->regs[0] + 2664ULL;
    cpu->regs[30] = PB_BASE + 0x227054ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_226db0;
    goto L_226fb4;
L_227060:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x227068ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_226df0;
L_22706c:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x227074ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_226e04;
L_227078:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x227080ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    goto L_226e1c;
}
