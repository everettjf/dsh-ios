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

void ft_PyDict_Keys(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[19])==0) goto L_1b02a8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_1b02a8;
L_1b01dc:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
L_1b01e0:
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1b01ecULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[12] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1b0244;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_1b028c;
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[11] = 0ULL;
    PB_STR((SP + 8), 0ULL);
    goto L_1b0230;
L_1b0214:
    PB_LDR(cpu->regs[4], (SP + 16));
    PB_LDRW(cpu->regs[3], (cpu->regs[4] + 0));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_NE) goto L_1b0274;
    PB_LDR(cpu->regs[3], (cpu->regs[12] + 24));
    PB_STR((cpu->regs[3] + cpu->regs[11]), cpu->regs[4]);
    cpu->regs[11] = cpu->regs[11] + 8ULL;
L_1b0230:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1b0240ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1b0214;
L_1b0244:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1b0288;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[12];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_1b0274:
    PB_LDR(cpu->regs[0], (cpu->regs[12] + 24));
    PB_STRW((cpu->regs[4] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[0] + cpu->regs[11]), cpu->regs[4]);
    cpu->regs[11] = cpu->regs[11] + 8ULL;
    goto L_1b0230;
L_1b0288:
    cpu->regs[30] = PB_BASE + 0x1b028cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1b028c:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1b01e0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1b01e0;
    cpu->regs[30] = PB_BASE + 0x1b02a4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1b01dc;
L_1b02a8:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 3119ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1b02b8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[12] = 0ULL;
    goto L_1b0244;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2400));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[3];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1b0374;
L_1b02f0:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(96ULL)));
    if (FLAG_EQ) goto L_1b0318;
L_1b02f8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0x1b0304ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x230820ULL);
L_1b0304:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1b0318:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2864));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_NE) goto L_1b02f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 920ULL;
    PB_STR((SP + 56), cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1b0344ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7ae60ULL);
    PB_LDR(cpu->regs[2], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1b02f8;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 928ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 24));
    cpu->regs[30] = PB_BASE + 0x1b0370ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1b0304;
L_1b0374:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1b02f0;
    cpu->regs[0] = cpu->regs[4];
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1b038cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 56));
    goto L_1b02f0;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1b03b4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd7750ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 64));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_1b03e0;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
L_1b03d4:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1b03e0:
    cpu->regs[0] = 0ULL;
    goto L_1b03d4;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[4];
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[2] + (cpu->regs[4] << 3);
    cpu->regs[26] = cpu->regs[3];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + (cpu->regs[4] << 3)));
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 4152));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1b042cULL; PB_CALL(11, cpu, tlb, cpu->regs[4]);
    cpu->regs[19] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LT) goto L_1b055c;
    if (FLAG_EQ) goto L_1b04cc;
    cpu->regs[26] = cpu->regs[24] + 1ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 1ULL;
L_1b0448:
    FLAG_CMP(cpu->regs[19], cpu->regs[26]);
    if (FLAG_LT) goto L_1b0524;
L_1b0450:
    FLAG_CMP(cpu->regs[19], cpu->regs[26]);
    cpu->regs[20] = cpu->regs[24] - cpu->regs[20];
    cpu->regs[19] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[26];
    cpu->regs[19] = cpu->regs[24] - cpu->regs[19];
L_1b0460:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_1b0464:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_GT) goto L_1b0488;
L_1b046c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1b0488:
    cpu->regs[24] = cpu->regs[20] - cpu->regs[19];
    cpu->regs[2] = cpu->regs[23];
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 4152));
    cpu->regs[24] = cpu->regs[19] + ((uint64_t)((int64_t)cpu->regs[24] >> 1));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + (cpu->regs[24] << 3)));
    cpu->regs[30] = PB_BASE + 0x1b04a4ULL; PB_CALL(12, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_1b055c;
    if (FLAG_EQ) goto L_1b04bc;
    cpu->regs[20] = cpu->regs[24];
    goto L_1b0464;
L_1b04bc:
    cpu->regs[19] = cpu->regs[24] + 1ULL;
    cpu->regs[24] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[24];
    goto L_1b0464;
L_1b04cc:
    cpu->regs[26] = cpu->regs[26] - cpu->regs[24];
    cpu->regs[20] = 1ULL;
L_1b04d4:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_GE) goto L_1b0510;
    PB_LDR(cpu->regs[1], (cpu->regs[25] + (cpu->regs[20] << 3)));
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 4152));
    cpu->regs[30] = PB_BASE + 0x1b04f0ULL; PB_CALL(13, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = cpu->regs[20] << 1;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_1b055c;
    if (FLAG_NE) goto L_1b0510;
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[1] + 1ULL;
    goto L_1b04d4;
L_1b0510:
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    cpu->regs[19] = cpu->regs[19] + cpu->regs[24];
    cpu->regs[20] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[26];
    cpu->regs[20] = cpu->regs[24] + cpu->regs[20];
    goto L_1b0460;
L_1b0524:
    cpu->regs[1] = cpu->regs[25] - (cpu->regs[19] << 3);
    cpu->regs[2] = cpu->regs[23];
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 4152));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1b053cULL; PB_CALL(14, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = cpu->regs[19] << 1;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_1b055c;
    if (FLAG_EQ) goto L_1b0450;
    cpu->regs[20] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[1] + 1ULL;
    goto L_1b0448;
L_1b055c:
    cpu->regs[20] = 18446744073709551615ULL;
    goto L_1b046c;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[4];
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[2] + (cpu->regs[4] << 3);
    cpu->regs[26] = cpu->regs[3];
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 4152));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + (cpu->regs[24] << 3)));
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1b05a4ULL; PB_CALL(15, cpu, tlb, cpu->regs[4]);
    cpu->regs[19] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LT) goto L_1b065c;
    if (FLAG_EQ) goto L_1b067c;
    cpu->regs[26] = cpu->regs[26] - cpu->regs[24];
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 1ULL;
L_1b05c0:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    FLAG_CMP(cpu->regs[19], cpu->regs[26]);
    if (FLAG_GE) goto L_1b05fc;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 4152));
    cpu->regs[30] = PB_BASE + 0x1b05dcULL; PB_CALL(16, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = cpu->regs[19] << 1;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_1b065c;
    if (FLAG_EQ) goto L_1b05fc;
    cpu->regs[20] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[1] + 1ULL;
    goto L_1b05c0;
L_1b05fc:
    FLAG_CMP(cpu->regs[19], cpu->regs[26]);
    cpu->regs[20] = cpu->regs[20] + cpu->regs[24];
    cpu->regs[19] = (FLAG_LE) ? cpu->regs[19] : cpu->regs[26];
    cpu->regs[19] = cpu->regs[19] + cpu->regs[24];
L_1b060c:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
L_1b0610:
    cpu->regs[24] = cpu->regs[19] - cpu->regs[20];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_LE) goto L_1b0660;
    cpu->regs[24] = cpu->regs[20] + ((uint64_t)((int64_t)cpu->regs[24] >> 1));
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 4152));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[24] << 3)));
    cpu->regs[30] = PB_BASE + 0x1b0634ULL; PB_CALL(17, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_1b065c;
    if (FLAG_NE) goto L_1b064c;
    cpu->regs[19] = cpu->regs[24];
    goto L_1b0610;
L_1b064c:
    cpu->regs[20] = cpu->regs[24] + 1ULL;
    cpu->regs[24] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[24];
    goto L_1b0610;
L_1b065c:
    cpu->regs[19] = 18446744073709551615ULL;
L_1b0660:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1b067c:
    cpu->regs[26] = cpu->regs[24] + 1ULL;
    cpu->regs[20] = 1ULL;
L_1b0684:
    cpu->regs[0] = cpu->regs[25] - (cpu->regs[20] << 3);
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_GE) goto L_1b06c4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 4152));
    cpu->regs[30] = PB_BASE + 0x1b06a4ULL; PB_CALL(18, cpu, tlb, cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = cpu->regs[20] << 1;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_1b065c;
    if (FLAG_NE) goto L_1b06c4;
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[1] + 1ULL;
    goto L_1b0684;
L_1b06c4:
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    cpu->regs[19] = cpu->regs[24] - cpu->regs[19];
    cpu->regs[20] = (FLAG_LE) ? cpu->regs[20] : cpu->regs[26];
    cpu->regs[20] = cpu->regs[24] - cpu->regs[20];
    goto L_1b060c;
    /* nop */
    /* nop */
}
