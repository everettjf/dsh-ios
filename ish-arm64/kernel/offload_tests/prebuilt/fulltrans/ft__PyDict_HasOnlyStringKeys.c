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

void ft__PyDict_HasOnlyStringKeys(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 48ULL;
    cpu->regs[11] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[11] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 10));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1aa4ec;
L_1aa4bc:
    cpu->regs[0] = 1ULL;
L_1aa4c0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1aa4e8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_1aa4e8:
    cpu->regs[30] = PB_BASE + 0x1aa4ecULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1aa4ec:
    cpu->regs[3] = SP;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP + 16ULL;
L_1aa4f8:
    cpu->regs[0] = cpu->regs[11];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aa504ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1aa4bc;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_1aa4f8;
    cpu->regs[0] = 0ULL;
    goto L_1aa4c0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aa578;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[3];
L_1aa544:
    cpu->regs[4] = cpu->regs[19] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_LE) goto L_1aa57c;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 16));
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_1aa544;
L_1aa568:
    cpu->regs[0] = 0ULL;
L_1aa56c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1aa578:
    cpu->regs[0] = 0ULL;
L_1aa57c:
    cpu->regs[30] = PB_BASE + 0x1aa580ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdb480ULL);
    if ((cpu->regs[0])==0) goto L_1aa568;
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = 0ULL;
    if ((cpu->regs[19])==0) goto L_1aa5cc;
L_1aa590:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
L_1aa594:
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LE) goto L_1aa56c;
    cpu->regs[1] = cpu->regs[19] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[4] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1aa5b8;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[1]);
L_1aa5b8:
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[3] << 3);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    PB_STR((cpu->regs[1] + 24), cpu->regs[4]);
    goto L_1aa590;
L_1aa5cc:
    cpu->regs[1] = 0ULL;
    goto L_1aa594;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1aa658;
L_1aa608:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aa668;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 13ULL;
    cpu->regs[30] = PB_BASE + 0x1aa620ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1aa640;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1aa640;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1aa63cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1aa660;
L_1aa640:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1aa648:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1aa658:
    cpu->regs[30] = PB_BASE + 0x1aa65cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1aa608;
L_1aa660:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_1aa640;
L_1aa668:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1aa648;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[1])==0) goto L_1aa6c0;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1aa6a0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xf7220ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aa6dc;
    cpu->regs[0] = 20ULL;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    PB_STR((cpu->regs[20] + 8), cpu->regs[19]); PB_STR((cpu->regs[20] + 8) + 8, 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_1aa6b4:
    cpu->regs[0] = 1ULL;
L_1aa6b8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1aa6c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3440));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1aa6d0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aa6f4;
    cpu->regs[30] = PB_BASE + 0x1aa6d8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1aa6b4;
L_1aa6dc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aa6f0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1aa6fc;
L_1aa6f0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_1aa6f4:
    cpu->regs[0] = 0ULL;
    goto L_1aa6b8;
L_1aa6fc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa704ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_1aa6b8;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[3];
    cpu->regs[20] = cpu->regs[4];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[1] = 80ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1aa744ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1aa75c;
    cpu->regs[1] = 5ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[23]);
    PB_STRW((cpu->regs[0] + 64), cpu->regs[21]); PB_STRW((cpu->regs[0] + 64) + 4, cpu->regs[22]);
    PB_STRW((cpu->regs[0] + 72), cpu->regs[19]); PB_STRW((cpu->regs[0] + 72) + 4, cpu->regs[20]);
L_1aa75c:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1aa7ec;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 1904));
    goto L_1aa7b0;
L_1aa7a4:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1aa7acULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aa7dc;
L_1aa7b0:
    cpu->regs[2] = (((uint64_t)(((int64_t)(cpu->regs[19] << 32)) >> 32) & 0xffffffffULL) << 4);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[22] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 4);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + cpu->regs[2]));
    if ((cpu->regs[1])!=0) goto L_1aa7a4;
    cpu->regs[0] = 0ULL;
L_1aa7c8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_1aa7dc:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[0] = ((uint32_t)((FLAG_NE) ? cpu->regs[0] : (~0ULL)));
    goto L_1aa7c8;
L_1aa7ec:
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x2ab000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = cpu->regs[0] + 3680ULL;
    cpu->regs[30] = PB_BASE + 0x1aa80cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x23b310ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[0] = 80ULL;
    cpu->regs[30] = PB_BASE + 0x1aa844ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdbd90ULL);
    if ((cpu->regs[0])==0) goto L_1aaad4;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[19] + 0), 0ULL);
    PB_STR((cpu->regs[19] + 24), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1aa85cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1aaac4;
    cpu->regs[30] = PB_BASE + 0x1aa868ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1aaac4;
    PB_STR((cpu->regs[19] + 8), 0ULL);
    PB_STR((cpu->regs[19] + 56), 0ULL);
    if ((cpu->regs[20])==0) goto L_1aaac4;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1aaa3c;
L_1aa888:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1aa89cULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    PB_STR((cpu->regs[19] + 64), cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_STR((cpu->regs[19] + 0), cpu->regs[20]);
    if ((cpu->regs[0])==0) goto L_1aaac4;
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 36));
    cpu->regs[0] = 10000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[22] = ((uint32_t)(cpu->regs[0] - cpu->regs[22]));
    PB_STRW((cpu->regs[19] + 72), cpu->regs[22]); PB_STRW((cpu->regs[19] + 72) + 4, cpu->regs[0]);
    cpu->regs[2] = 59400ULL;
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1aa8ecULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1aac4cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1aaac4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_1aa9f0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa910ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1283a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1aaaa8;
L_1aa914:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa91cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1aaac4;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 72));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_NE) goto L_1aab14;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aa934ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aaac4;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aa944ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aab40;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aa954ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aaae0;
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x1aa97cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x12a010ULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1aa99c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aa99c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1aa99cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1aa99c:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1aa9b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aa9b8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aa9b8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1aa9b8:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1aa9d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aa9d4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1aa9d4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1aa9d4:
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_1aaac0;
    PB_LDR(cpu->regs[23], (SP + 48));
L_1aa9dc:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1aa9f0:
    if (FLAG_HI) goto L_1aaa88;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1aaa44;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 8));
    if ((cpu->regs[21])==0) goto L_1aa914;
    cpu->regs[20] = 0ULL;
    cpu->regs[2] = 0ULL;
    goto L_1aaa14;
L_1aaa10:
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
L_1aaa14:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[3] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3);
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LE) goto L_1aa914;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1aaa34ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aaa10;
    goto L_1aaaa8;
L_1aaa3c:
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_1aa888;
L_1aaa44:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1aa914;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 8));
    if ((cpu->regs[20])==0) goto L_1aa914;
    cpu->regs[21] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1aaa5c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[3] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3);
    cpu->regs[0] = cpu->regs[19];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LE) goto L_1aa914;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x1aaa7cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x126900ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1aaaa8;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    goto L_1aaa5c;
L_1aaa88:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_1aa914;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3736ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1aaaa8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1aaaa8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aaab0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1ac1a8ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aaabcULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1c1210ULL);
    goto L_1aa9dc;
L_1aaac0:
    PB_LDR(cpu->regs[23], (SP + 48));
L_1aaac4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aaad0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1c1210ULL);
    goto L_1aa9dc;
L_1aaad4:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aaadcULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_1aa9dc;
L_1aaae0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aaaf4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1aab60;
L_1aaaf4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aaac4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1aaac4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aab10ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aaac4;
L_1aab14:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3784ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1aab30ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aab3cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1c1210ULL);
    goto L_1aa9dc;
L_1aab40:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aaac4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1aaac4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1aab5cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aaac4;
L_1aab60:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1aab68ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aaaf4;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1aab90ULL; PB_CALL(41, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 1472ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1aaba8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x11d200ULL);
    if ((cpu->regs[0])==0) goto L_1aac34;
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1aac04;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1aabccULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1a24a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1aabec;
L_1aabd8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1aabec:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1aabd8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aac00ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aabd8;
L_1aac04:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 3856ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1aac20ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aac34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1aac3c;
L_1aac34:
    cpu->regs[20] = 0ULL;
    goto L_1aabd8;
L_1aac3c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aac48ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aabd8;
L_1aac4c:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[6];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[4];
    cpu->regs[25] = cpu->regs[7];
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[27] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1aac8cULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe1564ULL);
    if ((cpu->regs[0])==0) goto L_1aae48;
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x495000ULL;
    cpu->regs[0] = cpu->regs[0] + 576ULL;
    cpu->regs[0] = cpu->regs[0] + 2952ULL;
    cpu->regs[30] = PB_BASE + 0x1aaca4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe3a2cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aae2c;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[22]);
    PB_STR((cpu->regs[19] + 112), cpu->regs[20]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1aaea4;
L_1aacc0:
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 72));
    PB_LDRB(cpu->regs[22], (cpu->regs[19] + 80));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967294ULL));
    PB_STRB((cpu->regs[19] + 72), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[22] & 4294967292ULL));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    PB_STR((cpu->regs[19] + 32), cpu->regs[23]); PB_STR((cpu->regs[19] + 32) + 8, 0ULL);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((cpu->regs[19] + 48), 0ULL); PB_STR((cpu->regs[19] + 48) + 8, 0ULL);
    PB_STRW((cpu->regs[19] + 64), cpu->regs[21]); PB_STRW((cpu->regs[19] + 64) + 4, 0ULL);
    PB_STRB((cpu->regs[19] + 80), cpu->regs[1]);
    PB_STRW((cpu->regs[19] + 88), cpu->regs[26]); PB_STRW((cpu->regs[19] + 88) + 4, cpu->regs[27]);
    PB_STRW((cpu->regs[19] + 96), cpu->regs[24]); PB_STRW((cpu->regs[19] + 96) + 4, cpu->regs[25]);
    PB_STR((cpu->regs[19] + 104), 0ULL);
    PB_STR((cpu->regs[19] + 120), 0ULL);
    if ((cpu->regs[0])==0) goto L_1aad18;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 68));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1aae20;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 64));
    cpu->regs[30] = PB_BASE + 0x1aad14ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x129660ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aae20;
L_1aad18:
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] & 3ULL));
    PB_STRW((cpu->regs[19] + 76), 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 4294967281ULL));
    PB_STRB((cpu->regs[19] + 72), cpu->regs[0]);
    PB_STRB((cpu->regs[19] + 80), cpu->regs[22]);
    PB_STRW((cpu->regs[19] + 84), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1aad38ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aad44ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aad50ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    if ((cpu->regs[1])==0) goto L_1aae4c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1aae4c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[2] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x1aad7cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xddf30ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aae4c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aad8cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xe548cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aae80;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 8));
    if ((cpu->regs[22])==0) goto L_1aadb0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 120));
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 84));
    PB_STRW((cpu->regs[19] + 84), cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], 1ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1aae68;
L_1aadb0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aadc4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1aae5c;
L_1aadc4:
    PB_STR((cpu->regs[20] + 8), cpu->regs[19]);
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_1aae18;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_1aae0c;
    if ((cpu->regs[22])==0) goto L_1aae18;
L_1aaddc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 48));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aade8ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xe548cULL);
    cpu->regs[0] = ((uint32_t)((~cpu->regs[0])));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> 31));
L_1aadf0:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1aae0c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_STR((cpu->regs[20] + 40), cpu->regs[0]);
    if ((cpu->regs[22])!=0) goto L_1aaddc;
L_1aae18:
    cpu->regs[0] = 1ULL;
    goto L_1aadf0;
L_1aae20:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 68), cpu->regs[0]);
    goto L_1aad18;
L_1aae2c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aae48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1aae48;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1aae48ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1aae48:
    cpu->regs[19] = 0ULL;
L_1aae4c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aae54ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdce4cULL);
L_1aae54:
    cpu->regs[0] = 0ULL;
    goto L_1aadf0;
L_1aae5c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aae64ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1aadc4;
L_1aae68:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1aae78;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1aae78:
    PB_STR((cpu->regs[19] + 120), cpu->regs[0]);
    goto L_1aadb0;
L_1aae80:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aae54;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1aae54;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aae9cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1aadf0;
L_1aaea4:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_1aacc0;
}
