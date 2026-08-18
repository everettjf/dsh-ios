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

void ft_PyDict_Merge(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    cpu->regs[4] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = (FLAG_NE) ? 1 : 0;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x26bf70ULL; PB_CALL(1, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xe8cf0ULL); return; };
    cpu->regs[7] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[1] + 1832ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[7] + 8)); PB_LDR(cpu->regs[3], (cpu->regs[7] + 8) + 8);
    PB_LDR(cpu->regs[4], (cpu->regs[7] + 24)); PB_LDR(cpu->regs[5], (cpu->regs[7] + 24) + 8);
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 40));
    cpu->regs[2] = cpu->regs[3];
    FLAG_CMP(cpu->regs[7], 0ULL);
    cpu->regs[6] = (FLAG_NE) ? cpu->regs[7] : cpu->regs[6];
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
    SP = SP - 80ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_26c190;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[5] = SP + 8ULL;
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[4] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + 3752ULL;
    cpu->regs[3] = SP + 24ULL;
    cpu->regs[2] = SP + 32ULL;
    cpu->regs[30] = PB_BASE + 0x26c004ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26c190;
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x26c010ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11d7acULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_26c190;
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (!((cpu->regs[1] >> 26) & 1)) goto L_26c190;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_EQ) goto L_26c044;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 29) & 1)) goto L_26c190;
L_26c044:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2640));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_26c1b0;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_26c064;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
L_26c064:
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_EQ) goto L_26c1cc;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2680));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_26c1fc;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_26c090;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_26c090:
    PB_LDR(cpu->regs[0], (SP + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_EQ) goto L_26c174;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_26c0ac;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_26c0ac:
    PB_LDR(cpu->regs[2], (SP + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_26c0c4;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_26c0c4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[2]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_26c0dc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_26c208;
L_26c0dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26c17c;
L_26c0f0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_26c114;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26c114;
    cpu->regs[30] = PB_BASE + 0x26c114ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_26c114:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x26c124ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x26c12cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x2804c4ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = PB_BASE + 0x1fe000ULL;
    cpu->regs[0] = cpu->regs[0] + 2432ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : 0ULL;
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_26c148:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_26c1c8;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_26c174:
    PB_STR((SP + 8), 0ULL);
    goto L_26c0ac;
L_26c17c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26c0f0;
    cpu->regs[30] = PB_BASE + 0x26c18cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26c0f0;
L_26c190:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 1848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26c1a8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_26c1a8:
    cpu->regs[0] = 0ULL;
    goto L_26c148;
L_26c1b0:
    cpu->regs[30] = PB_BASE + 0x26c1b4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    PB_STR((SP + 24), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (SP + 16));
    if ((cpu->regs[0])!=0) goto L_26c064;
    cpu->regs[0] = 0ULL;
    goto L_26c148;
L_26c1c8:
    cpu->regs[30] = PB_BASE + 0x26c1ccULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c170ULL);
L_26c1cc:
    cpu->regs[30] = PB_BASE + 0x26c1d0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd94a0ULL);
L_26c1d0:
    PB_STR((SP + 16), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_26c090;
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_26c1a8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26c1a8;
    cpu->regs[30] = PB_BASE + 0x26c1f4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_26c148;
L_26c1fc:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x26c204ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18fc80ULL);
    goto L_26c1d0;
L_26c208:
    cpu->regs[30] = PB_BASE + 0x26c20cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26c0dc;
    SP = SP - 96ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26c240ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x213250ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26c3e0;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    cpu->regs[30] = PB_BASE + 0x26c250ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26c42c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
L_26c264:
    PB_STR((SP + 16), cpu->regs[2]);
    FLAG_CMP(cpu->regs[22], cpu->regs[2]);
    if (FLAG_GT) goto L_26c314;
    cpu->regs[22] = SP + 16ULL;
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[24] = SP;
    cpu->regs[23] = SP + 8ULL;
    PB_STR((SP + 16), 0ULL);
L_26c284:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x26c298ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_26c350;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[20] + 8) + 8);
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 1896ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    cpu->regs[30] = PB_BASE + 0x26c2b4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_26c3d8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26c3d8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26c2d4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_26c2d8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x26c2e0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x2153e0ULL);
L_26c2e0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_26c420;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_26c314:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 24));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 1872ULL;
    cpu->regs[2] = cpu->regs[3] + (cpu->regs[2] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0x26c330ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26c3c0;
L_26c33c:
    if ((cpu->regs[21])==0) goto L_26c42c;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[19] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    goto L_26c264;
L_26c350:
    PB_LDR(cpu->regs[3], (SP + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_26c364;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
L_26c364:
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 1880ULL;
    cpu->regs[30] = PB_BASE + 0x26c378ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_26c3a8;
L_26c384:
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_26c39c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_26c434;
L_26c39c:
    if ((cpu->regs[21])==0) goto L_26c428;
    cpu->regs[19] = cpu->regs[21];
    goto L_26c284;
L_26c3a8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26c384;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26c3bcULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26c384;
L_26c3c0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_26c33c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26c3d4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26c33c;
L_26c3d8:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    goto L_26c2d8;
L_26c3e0:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26c43c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_26c420;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[0] + 1656ULL;
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    { PB_CALL(27, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
L_26c420:
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x26c428ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7c170ULL);
L_26c428:
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
L_26c42c:
    cpu->regs[21] = 0ULL;
    goto L_26c2d8;
L_26c434:
    cpu->regs[30] = PB_BASE + 0x26c438ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26c39c;
L_26c43c:
    cpu->regs[21] = 0ULL;
    goto L_26c2e0;
}
