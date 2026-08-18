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

void ft__PyRuntimeState_Init(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 320ULL;
    PB_STR((SP + 224), cpu->regs[29]); PB_STR((SP + 224) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 224ULL;
    PB_STR((SP + 288), cpu->regs[25]); PB_STR((SP + 288) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 240), cpu->regs[19]); PB_STR((SP + 240) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[8];
    PB_STR((SP + 256), cpu->regs[21]); PB_STR((SP + 256) + 8, cpu->regs[22]);
    cpu->regs[21] = SP + 24ULL;
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 272), cpu->regs[23]); PB_STR((SP + 272) + 8, cpu->regs[24]);
    PB_STR((SP + 304), cpu->regs[27]); PB_STR((SP + 304) + 8, cpu->regs[28]);
    cpu->regs[27] = SP + 144ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 216), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[26] + 2976));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[24], (cpu->regs[26] + 2984));
    PB_LDR(cpu->regs[23], (cpu->regs[26] + 3000));
    PB_LDR(cpu->regs[22], (cpu->regs[26] + 3032));
    cpu->regs[30] = PB_BASE + 0x17a44cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x17a7a8ULL);
L_17a44c:
    cpu->regs[30] = PB_BASE + 0x17a450ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x17aba0ULL);
    if ((cpu->regs[0])==0) goto L_17a5fc;
    PB_STR((cpu->regs[27] + (cpu->regs[19] << 3)), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[19], 9ULL);
    if (FLAG_NE) goto L_17a44c;
L_17a464:
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x17a470ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x17ac80ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_17a5b0;
L_17a478:
    cpu->regs[0] = cpu->regs[26] + 1544ULL;
    cpu->regs[30] = PB_BASE + 0x17a480ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x17ace0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_17a578;
    cpu->regs[0] = cpu->regs[26] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0x17a48cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x17ace0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_17a578;
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_17a560;
    PB_STR((cpu->regs[26] + 2976), cpu->regs[25]);
    cpu->regs[0] = cpu->regs[26] + 2936ULL;
    PB_STR((cpu->regs[26] + 2984), cpu->regs[24]);
    PB_STR((cpu->regs[26] + 3000), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x17a4acULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x17ad28ULL);
    cpu->regs[3] = SP + 64ULL;
    cpu->regs[10] = cpu->regs[26] + 32ULL;
    cpu->regs[9] = cpu->regs[26] + 72ULL;
    cpu->regs[8] = cpu->regs[26] + 2512ULL;
    cpu->regs[7] = cpu->regs[26] + 3024ULL;
    cpu->regs[6] = cpu->regs[26] + 1920ULL;
    cpu->regs[5] = cpu->regs[26] + 1960ULL;
    cpu->regs[4] = cpu->regs[26] + 1632ULL;
    cpu->regs[2] = cpu->regs[26] + 2992ULL;
    cpu->regs[0] = cpu->regs[26] + 88ULL;
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 64), cpu->regs[10]); PB_STR((SP + 64) + 8, cpu->regs[9]);
    PB_STR((SP + 80), cpu->regs[8]); PB_STR((SP + 80) + 8, cpu->regs[7]);
    PB_STR((SP + 96), cpu->regs[6]); PB_STR((SP + 96) + 8, cpu->regs[5]);
    PB_STR((SP + 112), cpu->regs[4]); PB_STR((SP + 112) + 8, cpu->regs[2]);
    PB_STR((SP + 128), cpu->regs[0]);
L_17a4ec:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[1]));
    PB_LDR(cpu->regs[2], (cpu->regs[27] + cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], 72ULL);
    if (FLAG_NE) goto L_17a4ec;
    cpu->regs[30] = PB_BASE + 0x17a508ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xd7750ULL);
    PB_STR((cpu->regs[20] + 0), 0ULL); PB_STR((cpu->regs[20] + 0) + 8, 0ULL);
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[20] + 16), 0ULL); PB_STR((cpu->regs[20] + 16) + 8, 0ULL);
    PB_STR((cpu->regs[26] + 64), cpu->regs[0]);
    PB_STR((cpu->regs[26] + 3032), cpu->regs[22]);
L_17a520:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 216));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_17a55c;
    PB_LDR(cpu->regs[29], (SP + 224)); PB_LDR(cpu->regs[30], (SP + 224) + 8);
    PB_LDR(cpu->regs[19], (SP + 240)); PB_LDR(cpu->regs[20], (SP + 240) + 8);
    PB_LDR(cpu->regs[21], (SP + 256)); PB_LDR(cpu->regs[22], (SP + 256) + 8);
    PB_LDR(cpu->regs[23], (SP + 272)); PB_LDR(cpu->regs[24], (SP + 272) + 8);
    PB_LDR(cpu->regs[25], (SP + 288)); PB_LDR(cpu->regs[26], (SP + 288) + 8);
    PB_LDR(cpu->regs[27], (SP + 304)); PB_LDR(cpu->regs[28], (SP + 304) + 8);
    SP = SP + 320ULL;
    return;
L_17a55c:
    cpu->regs[30] = PB_BASE + 0x17a560ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_17a560:
    cpu->regs[0] = PB_BASE + 0x2b6000ULL;
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
    cpu->regs[1] = PB_BASE + 0x281000ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = cpu->regs[1] + 2224ULL;
    cpu->regs[30] = PB_BASE + 0x17a578ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x91ebcULL);
L_17a578:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x17a580ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1f6c24ULL);
    cpu->regs[0] = cpu->regs[20] + 4ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[1] = PB_BASE + 0x2b6000ULL;
    cpu->regs[2] = PB_BASE + 0x281000ULL;
    cpu->regs[1] = cpu->regs[1] + 1584ULL;
    cpu->regs[2] = cpu->regs[2] + 2192ULL;
    PB_STR((cpu->regs[0] + 0), 0ULL); PB_STR((cpu->regs[0] + 0) + 8, 0ULL);
    PB_STR((cpu->regs[20] + 20), 0ULL);
    PB_STRW((cpu->regs[20] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[20] + 8), cpu->regs[1]); PB_STR((cpu->regs[20] + 8) + 8, cpu->regs[2]);
    PB_STRW((cpu->regs[20] + 28), 0ULL);
    goto L_17a520;
L_17a5b0:
    cpu->regs[1] = PB_BASE + 0x3de000ULL;
    cpu->regs[0] = cpu->regs[1] + 2320ULL;
    FLAG_CMP(cpu->regs[26], cpu->regs[0]);
    if (FLAG_HS) goto L_17a5d0;
    cpu->regs[2] = cpu->regs[26] + (112ULL << 12);
    cpu->regs[2] = cpu->regs[2] + 464ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_HI) goto L_17a628;
L_17a5d0:
    cpu->regs[0] = PB_BASE + 0x44e000ULL;
    cpu->regs[0] = cpu->regs[0] + 2784ULL;
    cpu->regs[1] = cpu->regs[1] + 2320ULL;
    FLAG_CMP(cpu->regs[26], cpu->regs[0]);
    if (FLAG_LO) { FLAG_CMP(cpu->regs[26], cpu->regs[1]); } else { FLAG_CMP(0, 1); }
    if (FLAG_HI) goto L_17a628;
    cpu->regs[2] = 464ULL;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 16)) | ((0x7ULL & 0xffff) << 16);
    cpu->regs[30] = PB_BASE + 0x17a5f8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c090ULL);
    goto L_17a478;
L_17a5fc:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[28] = 0ULL;
L_17a604:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_EQ) goto L_17a464;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[28] = ((uint32_t)(cpu->regs[28] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x17a61cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1c208cULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_STR(cpu->regs[1], 0ULL); cpu->regs[1] += 8;
    goto L_17a604;
L_17a628:
    __builtin_trap();
}
