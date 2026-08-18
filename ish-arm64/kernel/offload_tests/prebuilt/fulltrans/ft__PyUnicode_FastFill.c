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

void ft__PyUnicode_FastFill(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 32));
    cpu->regs[0] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_225f34;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[1] = cpu->regs[5] + 40ULL;
    cpu->regs[5] = cpu->regs[5] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[5] : cpu->regs[1];
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x20700cULL); return; };
L_225f34:
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 56));
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x20700cULL); return; };
    /* nop */
    SP = SP - 208ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 144), cpu->regs[29]); PB_STR((SP + 144) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 144ULL;
    cpu->regs[3] = PB_BASE + 0x521000ULL;
    cpu->regs[3] = cpu->regs[3] + 272ULL;
    cpu->regs[7] = SP;
    PB_STR((SP + 160), cpu->regs[19]); PB_STR((SP + 160) + 8, cpu->regs[20]);
    cpu->regs[19] = SP + 8ULL;
    cpu->regs[3] = cpu->regs[3] + 2192ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 136), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[6] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[5] = SP + 4ULL;
    cpu->regs[2] = cpu->regs[2] + 144ULL;
    cpu->regs[4] = SP + 24ULL;
    PB_STRW((SP + 0), 0ULL); PB_STRW((SP + 0) + 4, 0ULL);
    PB_STR((SP + 8), 0ULL);
    cpu->regs[30] = PB_BASE + 0x225fa0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x13eb20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_226178;
    PB_LDR(cpu->regs[1], (SP + 24));
    cpu->regs[0] = SP + 16ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x225fb4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x226230ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_226178;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x225fc4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1bea60ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_2261e8;
    cpu->regs[0] = 21495ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0xa5e3ULL & 0xffff) << 16);
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 32)) | ((0xc49bULL & 0xffff) << 32);
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x20ULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_GT) goto L_2261c8;
    PB_STR((SP + 192), cpu->regs[23]); PB_STR((SP + 192) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x225ff0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c8584ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2261bc;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 176), cpu->regs[21]); PB_STR((SP + 176) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x226004ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c7a00ULL);
    cpu->regs[22] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2261b8;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2640));
    if ((cpu->regs[0])==0) goto L_226180;
L_226020:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2632));
    if ((cpu->regs[0])==0) goto L_226208;
L_226028:
    cpu->regs[6] = 16960ULL;
    cpu->regs[4] = 60ULL;
    cpu->regs[6] = (cpu->regs[6] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    cpu->regs[21] = SP + 32ULL;
    cpu->regs[5] = (cpu->regs[6] ? (uint64_t)((int64_t)cpu->regs[20] / (int64_t)cpu->regs[6]) : 0);
    cpu->regs[0] = (cpu->regs[4] ? cpu->regs[5] / cpu->regs[4] : 0);
    cpu->regs[6] = cpu->regs[20] - cpu->regs[5] * cpu->regs[6];
    cpu->regs[3] = (cpu->regs[4] ? cpu->regs[0] / cpu->regs[4] : 0);
    cpu->regs[5] = cpu->regs[5] - cpu->regs[0] * cpu->regs[4];
    cpu->regs[4] = cpu->regs[0] - cpu->regs[3] * cpu->regs[4];
    cpu->regs[0] = cpu->regs[21];
    if ((cpu->regs[6])!=0) goto L_2261a4;
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = 100ULL;
    cpu->regs[2] = cpu->regs[2] + 248ULL;
    cpu->regs[30] = PB_BASE + 0x226068ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1815f0ULL);
L_226068:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x226070ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x2264c0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22618c;
    cpu->regs[30] = PB_BASE + 0x22607cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x226084ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x226640ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2568));
    PB_STR((cpu->regs[19] + 2568), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x226094ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 16));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2640));
    PB_LDRW(cpu->regs[2], (SP + 0)); PB_LDRW(cpu->regs[4], (SP + 0) + 4);
    PB_STRW((cpu->regs[19] + 2576), cpu->regs[22]);
    PB_STR((cpu->regs[19] + 2584), cpu->regs[20]);
    PB_STRW((cpu->regs[19] + 2592), cpu->regs[4]);
    PB_STR((cpu->regs[19] + 2600), cpu->regs[3]);
    PB_STRW((cpu->regs[19] + 2608), cpu->regs[2]);
    PB_STR((cpu->regs[19] + 2616), cpu->regs[21]);
    PB_STR((cpu->regs[19] + 2624), cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x2260c4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x17f520ULL);
    cpu->regs[0] = PB_BASE + 0x226000ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 2720ULL;
    cpu->regs[30] = PB_BASE + 0x2260d4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x2267e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_226124;
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_2260ec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 136));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_226118;
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    PB_LDR(cpu->regs[19], (SP + 160)); PB_LDR(cpu->regs[20], (SP + 160) + 8);
    SP = SP + 208ULL;
    return;
L_226118:
    PB_STR((SP + 176), cpu->regs[21]); PB_STR((SP + 176) + 8, cpu->regs[22]);
    PB_STR((SP + 192), cpu->regs[23]); PB_STR((SP + 192) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x226124ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_226124:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2640));
    cpu->regs[30] = PB_BASE + 0x22612cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x17faa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2568));
    if ((cpu->regs[0])==0) goto L_22614c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 2568), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_22614c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_226228;
L_22614c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x226154ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 280ULL;
    PB_STR((cpu->regs[19] + 2616), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x226170ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
L_226178:
    cpu->regs[0] = 0ULL;
    goto L_2260ec;
L_226180:
    cpu->regs[30] = PB_BASE + 0x226184ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x17aba0ULL);
    PB_STR((cpu->regs[19] + 2640), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_226020;
L_22618c:
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x226194ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[30] = PB_BASE + 0x226198ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    goto L_2260ec;
L_2261a4:
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = 100ULL;
    cpu->regs[2] = cpu->regs[2] + 208ULL;
    cpu->regs[30] = PB_BASE + 0x2261b4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1815f0ULL);
    goto L_226068;
L_2261b8:
    PB_LDR(cpu->regs[21], (SP + 176)); PB_LDR(cpu->regs[22], (SP + 176) + 8);
L_2261bc:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 192)); PB_LDR(cpu->regs[24], (SP + 192) + 8);
    goto L_2260ec;
L_2261c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 2000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2261e0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_2260ec;
L_2261e8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 176ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x226200ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_2260ec;
L_226208:
    cpu->regs[30] = PB_BASE + 0x22620cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x17aba0ULL);
    PB_STR((cpu->regs[19] + 2632), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22618c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 2640));
    if ((cpu->regs[1])==0) goto L_22618c;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x226224ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x17f520ULL);
    goto L_226028;
L_226228:
    cpu->regs[30] = PB_BASE + 0x22622cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22614c;
}
