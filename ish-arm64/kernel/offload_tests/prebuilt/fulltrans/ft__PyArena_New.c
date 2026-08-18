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

void ft__PyArena_New(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = 24ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x193db0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdbd90ULL);
    if ((cpu->regs[0])==0) goto L_193e08;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 8192ULL;
    cpu->regs[30] = PB_BASE + 0x193dc4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x193e20ULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]); PB_STR((cpu->regs[19] + 0) + 8, cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_193dfc;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x193dd4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_193e10;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_193dec:
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0x193df4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_193df4:
    cpu->regs[0] = cpu->regs[20];
    if ((cpu->regs[20])!=0) goto L_193dec;
L_193dfc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x193e04ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_193e08:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_193e10:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0));
    goto L_193df4;
    /* nop */
    /* nop */
L_193e20:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x193e38ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdbd90ULL);
    if ((cpu->regs[0])==0) goto L_193e58;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[0] + 39ULL;
    cpu->regs[1] = cpu->regs[1] & 18446744073709551608ULL;
    PB_STR(cpu->regs[2], cpu->regs[19]); cpu->regs[2] += 32;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2];
    PB_STR((cpu->regs[0] + 8), cpu->regs[1]); PB_STR((cpu->regs[0] + 8) + 8, 0ULL);
    PB_STR((cpu->regs[0] + 24), cpu->regs[2]);
L_193e58:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 128ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[3];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[4];
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = PB_BASE + 0x285000ULL;
    cpu->regs[1] = cpu->regs[1] + 344ULL;
    cpu->regs[0] = cpu->regs[0] + 352ULL;
    cpu->regs[30] = PB_BASE + 0x193ec4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xee244ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_194154;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(257ULL)));
    cpu->regs[25] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[21])==0) goto L_193fd8;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 11) & 1)) goto L_193fd8;
    cpu->regs[30] = PB_BASE + 0x193ee0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1946e4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_194144;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x193ef8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1947a8ULL);
    PB_STR((cpu->regs[19] + 2824), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_19413c;
    cpu->regs[0] = 2ULL;
    PB_STRW((cpu->regs[19] + 2744), cpu->regs[0]);
    PB_STR((cpu->regs[19] + 2808), 0ULL);
    cpu->regs[2] = cpu->regs[19];
    PB_STR((cpu->regs[19] + 2816), cpu->regs[20]);
    cpu->regs[1] = 5ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[0] + 1576ULL;
    cpu->regs[30] = PB_BASE + 0x193f28ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1de500ULL);
    PB_STR((cpu->regs[19] + 2752), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_19413c;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    PB_STR((cpu->regs[19] + 0), cpu->regs[20]); PB_STR((cpu->regs[19] + 0) + 8, cpu->regs[20]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STR((cpu->regs[19] + 48), cpu->regs[20]);
    if (FLAG_NE) goto L_1940c4;
    PB_STR((cpu->regs[19] + 2336), cpu->regs[22]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x193f54ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x195040ULL);
    cpu->regs[2] = cpu->regs[0];
L_193f58:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[3] = 12ULL;
    if (((cpu->regs[0] >> 10) & 1)) goto L_1940ec;
L_193f64:
    cpu->regs[5] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x193f78ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1950e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_193f94;
    cpu->regs[30] = PB_BASE + 0x193f84ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x195310ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x193f94ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x124000ULL);
L_193f94:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x193f9cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1a8480ULL);
L_193f9c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_19415c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
L_193fd8:
    cpu->regs[30] = PB_BASE + 0x193fdcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1946e4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_194144;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    PB_STR((SP + 0), 0ULL); PB_STR((SP + 0) + 8, 0ULL);
    cpu->regs[30] = PB_BASE + 0x193ff8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1947a8ULL);
    PB_STR((cpu->regs[19] + 2824), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_19413c;
    PB_STR((cpu->regs[19] + 2808), 0ULL);
    cpu->regs[1] = PB_BASE + 0x194000ULL;
    PB_STR((cpu->regs[19] + 2816), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] + 2944ULL;
    cpu->regs[0] = PB_BASE + 0x194000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 2720ULL;
    cpu->regs[30] = PB_BASE + 0x194020ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1949b0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_194190;
    PB_LDR(cpu->regs[26], (cpu->regs[19] + 2808));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 2816));
    if ((cpu->regs[26])!=0) goto L_194164;
    PB_STR((SP + 112), cpu->regs[27]);
L_194034:
    cpu->regs[6] = cpu->regs[20];
    cpu->regs[1] = SP;
    cpu->regs[0] = 0ULL;
L_194040:
    PB_LDRB(cpu->regs[7], (cpu->regs[6] + 0));
    if ((((uint32_t)(cpu->regs[7])))==0) goto L_194060;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(10ULL)));
    if (FLAG_NE) goto L_1940e4;
    PB_STR((cpu->regs[1] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)), cpu->regs[6]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1940e4;
L_194060:
    PB_LDR(cpu->regs[27], (SP + 0));
    PB_STR((cpu->regs[19] + 2808), 0ULL);
    if ((cpu->regs[27])==0) goto L_1940a0;
    cpu->regs[25] = PB_BASE + 0x86000ULL;
    cpu->regs[25] = cpu->regs[25] + 160ULL;
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[27] - cpu->regs[20];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x194088ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x194c80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_194188;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 2808));
    if ((cpu->regs[1])!=0) goto L_19411c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 2744));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1940f4;
L_1940a0:
    PB_STR((cpu->regs[19] + 2792), cpu->regs[26]);
    if ((cpu->regs[20])==0) goto L_194188;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    PB_STR((cpu->regs[19] + 0), cpu->regs[20]); PB_STR((cpu->regs[19] + 0) + 8, cpu->regs[20]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    PB_LDR(cpu->regs[27], (SP + 112));
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STR((cpu->regs[19] + 48), cpu->regs[20]);
    if (FLAG_EQ) goto L_1940c8;
L_1940c4:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_1940c8:
    PB_STR((cpu->regs[19] + 2336), cpu->regs[22]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1940d4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x195040ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[21])!=0) goto L_193f58;
    cpu->regs[3] = 12ULL;
    goto L_193f64;
L_1940e4:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    goto L_194040;
L_1940ec:
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + 4));
    goto L_193f64;
L_1940f4:
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[1])==0) goto L_1940a0;
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[27];
    cpu->regs[0] = cpu->regs[27] + 1ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x194110ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x194c80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_194188;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 2808));
    if ((cpu->regs[1])==0) goto L_1940a0;
L_19411c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x194124ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xacaa4ULL);
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[0] + 32ULL;
    if ((cpu->regs[0])!=0) goto L_1940a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x194138ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x883e8ULL);
    PB_LDR(cpu->regs[27], (SP + 112));
L_19413c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x194144ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1a8480ULL);
L_194144:
    cpu->regs[30] = PB_BASE + 0x194148ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_194154;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x194154ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xcaea4ULL);
L_194154:
    cpu->regs[20] = 0ULL;
    goto L_193f9c;
L_19415c:
    PB_STR((SP + 112), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x194164ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7c170ULL);
L_194164:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x194170ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xacaa4ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_194190;
    PB_STR((SP + 112), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x194180ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1063e8ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_194034;
L_194188:
    PB_LDR(cpu->regs[27], (SP + 112));
    goto L_19413c;
L_194190:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x194198ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x883e8ULL);
    goto L_19413c;
    /* nop */
}
