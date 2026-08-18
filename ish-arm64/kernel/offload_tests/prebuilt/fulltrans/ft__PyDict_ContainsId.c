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

void ft__PyDict_ContainsId(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xc62ecULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xa3348ULL);
    if ((cpu->regs[0])==0) goto L_c6304;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xdd250ULL); return; };
L_c6304:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 192ULL;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    PB_STR((SP + 144), cpu->regs[23]); PB_STR((SP + 144) + 8, cpu->regs[24]);
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    PB_STR((SP + 176), cpu->regs[27]); PB_STR((SP + 176) + 8, cpu->regs[28]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4024));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 88), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc635cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c65f4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6368ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c65f4;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    PB_LDR(cpu->regs[28], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0xc6378ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c664c;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc6388ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c63b0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c664c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c664c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc63acULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c664c;
L_c63b0:
    cpu->regs[27] = SP + 48ULL;
    cpu->regs[26] = SP + 32ULL;
    cpu->regs[25] = SP + 24ULL;
    cpu->regs[0] = SP + 40ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    PB_STR((SP + 24), 0ULL); PB_STR((SP + 24) + 8, 0ULL);
    PB_STR((SP + 40), 0ULL);
L_c63cc:
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[4] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xc63e4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c6524;
    PB_LDR(cpu->regs[22], (SP + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c63fc;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_c63fc:
    PB_LDR(cpu->regs[23], (SP + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c6410;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_c6410:
    PB_LDR(cpu->regs[24], (SP + 48));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xc6424ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe35f0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c6438;
    cpu->regs[30] = PB_BASE + 0xc6430ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_c6480;
    goto L_c65c4;
L_c6438:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c6448;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_c6448:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xc6458ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_c65c8;
    if (FLAG_EQ) goto L_c6480;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc6474ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x197fe0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c64e0;
    goto L_c65c8;
L_c6480:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xc6490ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c65c8;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc64a4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x12b468ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c64c8;
    if (((cpu->regs[2] >> 31) & 1)) goto L_c65c8;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c65c8;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xc64c4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c65c8;
L_c64c8:
    if (((cpu->regs[2] >> 31) & 1)) goto L_c64e0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c64e0;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xc64e0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c64e0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c64fc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c64fc;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc64fcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c64fc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc6504ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c63cc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c63cc;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xc6520ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c63cc;
L_c6524:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 47904ULL;
    cpu->regs[1] = SP + 56ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 24), 0ULL); PB_STR((SP + 24) + 8, 0ULL);
    PB_STR((SP + 56), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xc654cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c65c4;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6560ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1ffce0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_c6588;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c65c4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c65c4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc6584ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c65c4;
L_c6588:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c65a4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c65a4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc65a4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c65a4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c666c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c666c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc65c0ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c666c;
L_c65c4:
    cpu->regs[21] = 0ULL;
L_c65c8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc65d0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc65d8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0xc65e0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc65e8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0xc65f0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_c664c;
L_c65f4:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0xc65fcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xc4fd8ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c664c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 58400ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[1] = SP + 64ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xc662cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])!=0) goto L_c6654;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c664c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c664c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc664cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c664c:
    cpu->regs[19] = 0ULL;
    goto L_c666c;
L_c6654:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c666c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c666c;
    cpu->regs[30] = PB_BASE + 0xc666cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c666c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 88));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_c668c;
    cpu->regs[30] = PB_BASE + 0xc668cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c668c:
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    PB_LDR(cpu->regs[23], (SP + 144)); PB_LDR(cpu->regs[24], (SP + 144) + 8);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    PB_LDR(cpu->regs[27], (SP + 176)); PB_LDR(cpu->regs[28], (SP + 176) + 8);
    SP = SP + 192ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xc66c4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x24fc48ULL);
    if ((cpu->regs[0])==0) goto L_c6718;
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 144));
    if ((cpu->regs[0])!=0) goto L_c66f0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c6720;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_c6720;
L_c66f0:
    cpu->regs[30] = PB_BASE + 0xc66f4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c6728;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c6718;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c6718;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6718ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c6718:
    cpu->regs[20] = 0ULL;
    goto L_c6770;
L_c6720:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2760));
L_c6728:
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 128));
    cpu->regs[0] = PB_BASE + 0x2a6000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 24));
    FLAG_CMP(cpu->regs[5], 0ULL);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[0] = cpu->regs[0] + 3304ULL;
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[5] : cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xc6750ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1e5ca0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_c6770;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c6770;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6770ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c6770:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xc6794ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x230ec4ULL);
    if ((cpu->regs[0])==0) goto L_c67e8;
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    if ((cpu->regs[0])!=0) goto L_c67c0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c67f0;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_c67f0;
L_c67c0:
    cpu->regs[30] = PB_BASE + 0xc67c4ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_c67f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c67e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c67e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc67e8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c67e8:
    cpu->regs[20] = 0ULL;
    goto L_c682c;
L_c67f0:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
L_c67f8:
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    cpu->regs[0] = PB_BASE + 0x2a6000ULL;
    cpu->regs[0] = cpu->regs[0] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0xc680cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c682c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c682c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc682cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c682c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 80));
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 16));
    if ((cpu->regs[0])!=0) goto L_c6868;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 88));
    if ((cpu->regs[0])!=0) goto L_c6868;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 96));
    if ((cpu->regs[0])==0) goto L_c6914;
L_c6868:
    if ((cpu->regs[19])==0) goto L_c687c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6874ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_c6884;
L_c687c:
    cpu->regs[30] = PB_BASE + 0xc6880ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
L_c6884:
    if ((cpu->regs[19])==0) goto L_c698c;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 80));
    if ((cpu->regs[2])==0) goto L_c68ac;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[5] = 51144ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0xc68a8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_c68f4;
L_c68ac:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 88));
    if ((cpu->regs[2])==0) goto L_c68d0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[4] = 53360ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0xc68ccULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_c68f4;
L_c68d0:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 96));
    if ((cpu->regs[2])==0) goto L_c6934;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 51192ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xc68f0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c6934;
L_c68f4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c698c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c698c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6910ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c698c;
L_c6914:
    if ((cpu->regs[19])==0) goto L_c692c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c6934;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_c6934;
L_c692c:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_c6934:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_c695c;
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xc6954ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_c696c;
L_c695c:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0xc6968ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xe0f0cULL);
    cpu->regs[20] = cpu->regs[0];
L_c696c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c6990;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c6990;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6988ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c6990;
L_c698c:
    cpu->regs[20] = 0ULL;
L_c6990:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_c69a0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 80));
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 16));
    if ((cpu->regs[0])!=0) goto L_c69c4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    if ((cpu->regs[0])==0) goto L_c6a40;
L_c69c4:
    if ((cpu->regs[19])==0) goto L_c69d8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc69d0ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_c69e0;
L_c69d8:
    cpu->regs[30] = PB_BASE + 0xc69dcULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
L_c69e0:
    if ((cpu->regs[19])==0) goto L_c6a38;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 80));
    if ((cpu->regs[2])==0) goto L_c6a00;
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0xc69fcULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_c6a1c;
L_c6a00:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    if ((cpu->regs[2])==0) goto L_c6a60;
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1056ULL;
    cpu->regs[30] = PB_BASE + 0xc6a18ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c6a60;
L_c6a1c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_c6a38;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_c6a38;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6a38ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c6a38:
    cpu->regs[19] = 0ULL;
    goto L_c6a60;
L_c6a40:
    if ((cpu->regs[19])==0) goto L_c6a58;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c6a60;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_c6a60;
L_c6a58:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_c6a60:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xc6a88ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xc69a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c6ad0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[3] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0xc6aa4ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xe0f0cULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c6abc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_c6ac4;
L_c6abc:
    cpu->regs[19] = cpu->regs[20];
    goto L_c6ad0;
L_c6ac4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc6accULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c6abc;
L_c6ad0:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    if ((cpu->regs[0])!=0) goto L_c6b08;
    cpu->regs[0] = PB_BASE + 0x2a6000ULL;
    cpu->regs[1] = 28ULL;
    cpu->regs[0] = cpu->regs[0] + 3320ULL;
    cpu->regs[30] = PB_BASE + 0xc6b00ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 0ULL;
    goto L_c6b24;
L_c6b08:
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0xc6b18ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1d2ad0ULL);
    if ((cpu->regs[0])==0) goto L_c6b24;
    cpu->regs[1] = 1ULL;
    PB_STRB((cpu->regs[19] + 46), cpu->regs[1]);
L_c6b24:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
