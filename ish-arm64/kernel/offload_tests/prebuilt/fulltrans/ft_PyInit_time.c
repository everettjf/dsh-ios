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

void ft_PyInit_time(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x51e000ULL;
    cpu->regs[0] = cpu->regs[0] + 3856ULL;
    cpu->regs[0] = cpu->regs[0] + 1976ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    SP = SP - 112ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 32));
    cpu->regs[30] = PB_BASE + 0x1c6040ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1c6190ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c6184;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3592ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c605cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c6184;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3608ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1c6074ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c6184;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3624ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1c608cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c6184;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3648ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1c60a4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c6184;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3680ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1c60bcULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c6184;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3704ULL;
    cpu->regs[2] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1c60d4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c6184;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3720ULL;
    cpu->regs[2] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x1c60ecULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c6184;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3736ULL;
    cpu->regs[2] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x1c6104ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c6184;
    cpu->regs[0] = PB_BASE + 0x51e000ULL;
    cpu->regs[0] = cpu->regs[0] + 3856ULL;
    cpu->regs[0] = cpu->regs[0] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x1c6118ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1ab22cULL);
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c6184;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c612cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1ab080ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c6184;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = SP + 8ULL;
    PB_STR((SP + 8), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1c6144ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7bfd0ULL);
    if ((cpu->regs[0])==0) goto L_1c6154;
    cpu->regs[0] = PB_BASE + 0x5ad000ULL;
    PB_LDR(cpu->regs[1], (SP + 64));
    PB_STR((cpu->regs[0] + 3496), cpu->regs[1]);
L_1c6154:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1c618c;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_1c6184:
    cpu->regs[19] = 4294967295ULL;
    goto L_1c6154;
L_1c618c:
    cpu->regs[30] = PB_BASE + 0x1c6190ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c6190:
    SP = SP - 160ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    cpu->regs[21] = SP;
    PB_STR((SP + 144), cpu->regs[23]); PB_STR((SP + 144) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 88), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c61ccULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7aea0ULL);
    cpu->regs[2] = 34784ULL;
    cpu->regs[1] = SP;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 16)) | ((0x1e1ULL & 0xffff) << 16);
    cpu->regs[19] = (cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[2]) : 0);
    cpu->regs[19] = cpu->regs[19] * cpu->regs[2];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c61e8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1c63c8ULL);
    PB_LDR(cpu->regs[1], (SP + 48));
    if ((cpu->regs[1])==0) goto L_1c63b0;
L_1c61f0:
    cpu->regs[23] = SP + 72ULL;
    cpu->regs[2] = 9ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1c6200ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    cpu->regs[0] = cpu->regs[19] + (3852ULL << 12);
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 40));
    cpu->regs[0] = cpu->regs[0] + 1008ULL;
    PB_STRB((SP + 81), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1c6218ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1c63c8ULL);
    PB_LDR(cpu->regs[1], (SP + 48));
    cpu->regs[22] = (uint64_t)(-(int64_t)cpu->regs[21]);
    if ((cpu->regs[1])==0) goto L_1c63bc;
L_1c6224:
    cpu->regs[24] = SP + 56ULL;
    cpu->regs[2] = 9ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1c6234ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    cpu->regs[0] = 41728ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x2ULL & 0xffff) << 16);
    cpu->regs[1] = 17920ULL;
    cpu->regs[21] = cpu->regs[0] - cpu->regs[21];
    PB_STRB((SP + 65), 0ULL);
    cpu->regs[19] = (uint64_t)(-(int64_t)cpu->regs[2]);
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0x5ULL & 0xffff) << 16);
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_HI) goto L_1c6390;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HI) goto L_1c6390;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_LT) goto L_1c6328;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 3792ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c6284ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c63a8;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3808ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c629cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c63a8;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[19])));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[2] = (FLAG_NE) ? 1 : 0;
    cpu->regs[1] = cpu->regs[1] + 3816ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c62b8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c63a8;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x1c62d0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[2] = cpu->regs[0];
L_1c62d4:
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3840ULL;
    cpu->regs[30] = PB_BASE + 0x1c62e4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1ab4d0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c63a8;
    cpu->regs[30] = PB_BASE + 0x1c62ecULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
L_1c62f4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 88));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1c638c;
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    PB_LDR(cpu->regs[23], (SP + 144)); PB_LDR(cpu->regs[24], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
L_1c6328:
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3792ULL;
    cpu->regs[30] = PB_BASE + 0x1c633cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c63a8;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3808ULL;
    cpu->regs[30] = PB_BASE + 0x1c6354ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c63a8;
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3816ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1c636cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c63a8;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3832ULL;
    cpu->regs[30] = PB_BASE + 0x1c6384ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[2] = cpu->regs[0];
    goto L_1c62d4;
L_1c638c:
    cpu->regs[30] = PB_BASE + 0x1c6390ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c6390:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3768ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c63a8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1c63a8:
    cpu->regs[0] = 4294967295ULL;
    goto L_1c62f4;
L_1c63b0:
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3760ULL;
    goto L_1c61f0;
L_1c63bc:
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3760ULL;
    goto L_1c6224;
}
