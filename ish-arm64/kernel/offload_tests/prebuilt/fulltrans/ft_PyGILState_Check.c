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

void ft_PyGILState_Check(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 2496));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_188084;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 1544));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_188084;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x18805cULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[2] + cpu->regs[0]));
    if ((cpu->regs[19])==0) goto L_18808c;
    cpu->regs[0] = cpu->regs[1] + 1544ULL;
    cpu->regs[30] = PB_BASE + 0x188070ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x182a60ULL);
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
L_188078:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_188084:
    cpu->regs[0] = 1ULL;
    return;
L_18808c:
    cpu->regs[0] = 0ULL;
    goto L_188078;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x451000ULL;
    cpu->regs[19] = cpu->regs[20] + 576ULL;
    cpu->regs[0] = cpu->regs[19] + 864ULL;
    cpu->regs[30] = PB_BASE + 0x1880bcULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1168ULL;
    cpu->regs[30] = PB_BASE + 0x1880c8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1536ULL;
    cpu->regs[30] = PB_BASE + 0x1880d4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1776ULL;
    cpu->regs[30] = PB_BASE + 0x1880e0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1984ULL;
    cpu->regs[30] = PB_BASE + 0x1880ecULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 2256ULL;
    cpu->regs[30] = PB_BASE + 0x1880f8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 2512ULL;
    cpu->regs[30] = PB_BASE + 0x188104ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x188110ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 3200ULL;
    cpu->regs[30] = PB_BASE + 0x18811cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 3552ULL;
    cpu->regs[30] = PB_BASE + 0x188128ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 576ULL;
    cpu->regs[0] = cpu->regs[0] + 3808ULL;
    cpu->regs[30] = PB_BASE + 0x188138ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[20] = PB_BASE + 0x452000ULL;
    cpu->regs[19] = cpu->regs[20] + 832ULL;
    cpu->regs[0] = cpu->regs[19] - 176ULL;
    cpu->regs[30] = PB_BASE + 0x18814cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 176ULL;
    cpu->regs[30] = PB_BASE + 0x188158ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 576ULL;
    cpu->regs[30] = PB_BASE + 0x188164ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 816ULL;
    cpu->regs[30] = PB_BASE + 0x188170ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1040ULL;
    cpu->regs[30] = PB_BASE + 0x18817cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1408ULL;
    cpu->regs[30] = PB_BASE + 0x188188ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1680ULL;
    cpu->regs[30] = PB_BASE + 0x188194ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1912ULL;
    cpu->regs[30] = PB_BASE + 0x1881a0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 2128ULL;
    cpu->regs[30] = PB_BASE + 0x1881acULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 2528ULL;
    cpu->regs[30] = PB_BASE + 0x1881b8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 2880ULL;
    cpu->regs[30] = PB_BASE + 0x1881c4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 3200ULL;
    cpu->regs[30] = PB_BASE + 0x1881d0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 4000ULL;
    cpu->regs[30] = PB_BASE + 0x1881dcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x453000ULL;
    cpu->regs[20] = cpu->regs[19] + 1088ULL;
    cpu->regs[0] = cpu->regs[20] + 320ULL;
    cpu->regs[30] = PB_BASE + 0x1881f0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 576ULL;
    cpu->regs[30] = PB_BASE + 0x1881fcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 816ULL;
    cpu->regs[30] = PB_BASE + 0x188208ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1040ULL;
    cpu->regs[30] = PB_BASE + 0x188214ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1280ULL;
    cpu->regs[30] = PB_BASE + 0x188220ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1584ULL;
    cpu->regs[30] = PB_BASE + 0x18822cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1840ULL;
    cpu->regs[30] = PB_BASE + 0x188238ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x188244ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2304ULL;
    cpu->regs[30] = PB_BASE + 0x188250ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2608ULL;
    cpu->regs[30] = PB_BASE + 0x18825cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2864ULL;
    cpu->regs[30] = PB_BASE + 0x188268ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3088ULL;
    cpu->regs[30] = PB_BASE + 0x188274ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3488ULL;
    cpu->regs[30] = PB_BASE + 0x188280ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 4016ULL;
    cpu->regs[30] = PB_BASE + 0x18828cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x454000ULL;
    cpu->regs[20] = cpu->regs[19] + 1344ULL;
    cpu->regs[0] = cpu->regs[20] - 16ULL;
    cpu->regs[30] = PB_BASE + 0x1882a0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 208ULL;
    cpu->regs[30] = PB_BASE + 0x1882acULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 592ULL;
    cpu->regs[30] = PB_BASE + 0x1882b8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 880ULL;
    cpu->regs[30] = PB_BASE + 0x1882c4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1120ULL;
    cpu->regs[30] = PB_BASE + 0x1882d0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1408ULL;
    cpu->regs[30] = PB_BASE + 0x1882dcULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1648ULL;
    cpu->regs[30] = PB_BASE + 0x1882e8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x1882f4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2528ULL;
    cpu->regs[30] = PB_BASE + 0x188300ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x18830cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3360ULL;
    cpu->regs[30] = PB_BASE + 0x188318ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3936ULL;
    cpu->regs[30] = PB_BASE + 0x188324ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x455000ULL;
    cpu->regs[19] = cpu->regs[19] + 1600ULL;
    cpu->regs[0] = cpu->regs[19] - 16ULL;
    cpu->regs[30] = PB_BASE + 0x188338ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 208ULL;
    cpu->regs[30] = PB_BASE + 0x188344ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 512ULL;
    cpu->regs[30] = PB_BASE + 0x188350ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 736ULL;
    cpu->regs[30] = PB_BASE + 0x18835cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 976ULL;
    cpu->regs[30] = PB_BASE + 0x188368ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1344ULL;
    cpu->regs[30] = PB_BASE + 0x188374ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x188380ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 2544ULL;
    cpu->regs[30] = PB_BASE + 0x18838cULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 3632ULL;
    cpu->regs[30] = PB_BASE + 0x188398ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 4080ULL;
    cpu->regs[30] = PB_BASE + 0x1883a4ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x456000ULL;
    cpu->regs[19] = cpu->regs[19] + 1856ULL;
    cpu->regs[0] = cpu->regs[19] + 304ULL;
    cpu->regs[30] = PB_BASE + 0x1883b8ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 1408ULL;
    cpu->regs[30] = PB_BASE + 0x1883c4ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 2400ULL;
    cpu->regs[30] = PB_BASE + 0x1883d0ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 3376ULL;
    cpu->regs[30] = PB_BASE + 0x1883dcULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 3680ULL;
    cpu->regs[30] = PB_BASE + 0x1883e8ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[19] + 3968ULL;
    cpu->regs[30] = PB_BASE + 0x1883f4ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x457000ULL;
    cpu->regs[20] = cpu->regs[19] + 2112ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x188408ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 248ULL;
    cpu->regs[30] = PB_BASE + 0x188414ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 448ULL;
    cpu->regs[30] = PB_BASE + 0x188420ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 648ULL;
    cpu->regs[30] = PB_BASE + 0x18842cULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 848ULL;
    cpu->regs[30] = PB_BASE + 0x188438ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1216ULL;
    cpu->regs[30] = PB_BASE + 0x188444ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2976ULL;
    cpu->regs[30] = PB_BASE + 0x188450ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3568ULL;
    cpu->regs[30] = PB_BASE + 0x18845cULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 4080ULL;
    cpu->regs[30] = PB_BASE + 0x188468ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x458000ULL;
    cpu->regs[20] = cpu->regs[19] + 2368ULL;
    cpu->regs[0] = cpu->regs[20] + 64ULL;
    cpu->regs[30] = PB_BASE + 0x18847cULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 416ULL;
    cpu->regs[30] = PB_BASE + 0x188488ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 832ULL;
    cpu->regs[30] = PB_BASE + 0x188494ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1072ULL;
    cpu->regs[30] = PB_BASE + 0x1884a0ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1280ULL;
    cpu->regs[30] = PB_BASE + 0x1884acULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1520ULL;
    cpu->regs[30] = PB_BASE + 0x1884b8ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1920ULL;
    cpu->regs[30] = PB_BASE + 0x1884c4ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1884d0ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2400ULL;
    cpu->regs[30] = PB_BASE + 0x1884dcULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2624ULL;
    cpu->regs[30] = PB_BASE + 0x1884e8ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2944ULL;
    cpu->regs[30] = PB_BASE + 0x1884f4ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3648ULL;
    cpu->regs[30] = PB_BASE + 0x188500ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x459000ULL;
    cpu->regs[20] = cpu->regs[19] + 2624ULL;
    cpu->regs[0] = cpu->regs[20] - 256ULL;
    cpu->regs[30] = PB_BASE + 0x188514ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 800ULL;
    cpu->regs[30] = PB_BASE + 0x188520ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1408ULL;
    cpu->regs[30] = PB_BASE + 0x18852cULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1696ULL;
    cpu->regs[30] = PB_BASE + 0x188538ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2384ULL;
    cpu->regs[30] = PB_BASE + 0x188544ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x188550ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3552ULL;
    cpu->regs[30] = PB_BASE + 0x18855cULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3856ULL;
    cpu->regs[30] = PB_BASE + 0x188568ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x45a000ULL;
    cpu->regs[20] = cpu->regs[19] + 2880ULL;
    cpu->regs[0] = cpu->regs[20] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x18857cULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 624ULL;
    cpu->regs[30] = PB_BASE + 0x188588ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 912ULL;
    cpu->regs[30] = PB_BASE + 0x188594ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1632ULL;
    cpu->regs[30] = PB_BASE + 0x1885a0ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1888ULL;
    cpu->regs[30] = PB_BASE + 0x1885acULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2184ULL;
    cpu->regs[30] = PB_BASE + 0x1885b8ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2384ULL;
    cpu->regs[30] = PB_BASE + 0x1885c4ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2768ULL;
    cpu->regs[30] = PB_BASE + 0x1885d0ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3024ULL;
    cpu->regs[30] = PB_BASE + 0x1885dcULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3296ULL;
    cpu->regs[30] = PB_BASE + 0x1885e8ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3568ULL;
    cpu->regs[30] = PB_BASE + 0x1885f4ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x45b000ULL;
    cpu->regs[20] = cpu->regs[19] + 3136ULL;
    cpu->regs[0] = cpu->regs[20] + 80ULL;
    cpu->regs[30] = PB_BASE + 0x188608ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 400ULL;
    cpu->regs[30] = PB_BASE + 0x188614ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 656ULL;
    cpu->regs[30] = PB_BASE + 0x188620ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 944ULL;
    cpu->regs[30] = PB_BASE + 0x18862cULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1184ULL;
    cpu->regs[30] = PB_BASE + 0x188638ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x188644ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1696ULL;
    cpu->regs[30] = PB_BASE + 0x188650ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1968ULL;
    cpu->regs[30] = PB_BASE + 0x18865cULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2352ULL;
    cpu->regs[30] = PB_BASE + 0x188668ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2592ULL;
    cpu->regs[30] = PB_BASE + 0x188674ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2944ULL;
    cpu->regs[30] = PB_BASE + 0x188680ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3648ULL;
    cpu->regs[30] = PB_BASE + 0x18868cULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x45c000ULL;
    cpu->regs[20] = cpu->regs[19] + 3392ULL;
    cpu->regs[0] = cpu->regs[20] + 320ULL;
    cpu->regs[30] = PB_BASE + 0x1886a0ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1328ULL;
    cpu->regs[30] = PB_BASE + 0x1886acULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1760ULL;
    cpu->regs[30] = PB_BASE + 0x1886b8ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2144ULL;
    cpu->regs[30] = PB_BASE + 0x1886c4ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x1886d0ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2784ULL;
    cpu->regs[30] = PB_BASE + 0x1886dcULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3152ULL;
    cpu->regs[30] = PB_BASE + 0x1886e8ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3440ULL;
    cpu->regs[30] = PB_BASE + 0x1886f4ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3936ULL;
    cpu->regs[30] = PB_BASE + 0x188700ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x45d000ULL;
    cpu->regs[20] = cpu->regs[19] + 3648ULL;
    cpu->regs[0] = cpu->regs[20] - 16ULL;
    cpu->regs[30] = PB_BASE + 0x188714ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 240ULL;
    cpu->regs[30] = PB_BASE + 0x188720ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 640ULL;
    cpu->regs[30] = PB_BASE + 0x18872cULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1104ULL;
    cpu->regs[30] = PB_BASE + 0x188738ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0x188744ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1968ULL;
    cpu->regs[30] = PB_BASE + 0x188750ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2816ULL;
    cpu->regs[30] = PB_BASE + 0x18875cULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3408ULL;
    cpu->regs[30] = PB_BASE + 0x188768ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3792ULL;
    cpu->regs[30] = PB_BASE + 0x188774ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[19] = PB_BASE + 0x45e000ULL;
    cpu->regs[20] = cpu->regs[19] + 3904ULL;
    cpu->regs[0] = cpu->regs[20] - 48ULL;
    cpu->regs[30] = PB_BASE + 0x188788ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 400ULL;
    cpu->regs[30] = PB_BASE + 0x188794ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 688ULL;
    cpu->regs[30] = PB_BASE + 0x1887a0ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1048ULL;
    cpu->regs[30] = PB_BASE + 0x1887acULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1248ULL;
    cpu->regs[30] = PB_BASE + 0x1887b8ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1632ULL;
    cpu->regs[30] = PB_BASE + 0x1887c4ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 1872ULL;
    cpu->regs[30] = PB_BASE + 0x1887d0ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2104ULL;
    cpu->regs[30] = PB_BASE + 0x1887dcULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2320ULL;
    cpu->regs[30] = PB_BASE + 0x1887e8ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2560ULL;
    cpu->regs[30] = PB_BASE + 0x1887f4ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2792ULL;
    cpu->regs[30] = PB_BASE + 0x188800ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 2992ULL;
    cpu->regs[30] = PB_BASE + 0x18880cULL; PB_CALL(150, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3344ULL;
    cpu->regs[30] = PB_BASE + 0x188818ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[0] = cpu->regs[20] + 3600ULL;
    cpu->regs[30] = PB_BASE + 0x188824ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a738;
    cpu->regs[20] = PB_BASE + 0x460000ULL;
    cpu->regs[19] = cpu->regs[20] + 64ULL;
    cpu->regs[0] = cpu->regs[19] + 544ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[19] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x188840ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c444;
    cpu->regs[0] = cpu->regs[19] + 800ULL;
    cpu->regs[30] = PB_BASE + 0x18884cULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c438;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x188858ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c42c;
    cpu->regs[0] = cpu->regs[19] + 1328ULL;
    cpu->regs[30] = PB_BASE + 0x188864ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c420;
    cpu->regs[0] = cpu->regs[19] + 1616ULL;
    cpu->regs[30] = PB_BASE + 0x188870ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c414;
    cpu->regs[0] = cpu->regs[19] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x18887cULL; PB_CALL(158, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c408;
    cpu->regs[0] = cpu->regs[19] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x188888ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c3fc;
    cpu->regs[0] = cpu->regs[19] + 2576ULL;
    cpu->regs[30] = PB_BASE + 0x188894ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c3f0;
    cpu->regs[0] = cpu->regs[19] + 2800ULL;
    cpu->regs[30] = PB_BASE + 0x1888a0ULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c3e4;
    cpu->regs[0] = cpu->regs[19] + 3104ULL;
    cpu->regs[30] = PB_BASE + 0x1888acULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c3d8;
    cpu->regs[0] = cpu->regs[19] + 3376ULL;
    cpu->regs[30] = PB_BASE + 0x1888b8ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c3cc;
    cpu->regs[0] = cpu->regs[19] + 3632ULL;
    cpu->regs[30] = PB_BASE + 0x1888c4ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c3c0;
    cpu->regs[19] = PB_BASE + 0x461000ULL;
    cpu->regs[20] = cpu->regs[19] + 320ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1888d8ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c3b4;
    cpu->regs[0] = cpu->regs[20] + 240ULL;
    cpu->regs[30] = PB_BASE + 0x1888e4ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c3a8;
    cpu->regs[21] = cpu->regs[20] + 1024ULL;
    cpu->regs[0] = cpu->regs[20] + 592ULL;
    cpu->regs[30] = PB_BASE + 0x1888f4ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c39c;
    cpu->regs[0] = cpu->regs[20] + 800ULL;
    cpu->regs[30] = PB_BASE + 0x188900ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c390;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18890cULL; PB_CALL(169, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c384;
    cpu->regs[0] = cpu->regs[20] + 1248ULL;
    cpu->regs[30] = PB_BASE + 0x188918ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c378;
    cpu->regs[0] = cpu->regs[20] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0x188924ULL; PB_CALL(171, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c36c;
    cpu->regs[0] = cpu->regs[20] + 1840ULL;
    cpu->regs[30] = PB_BASE + 0x188930ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c360;
    cpu->regs[0] = cpu->regs[20] + 2208ULL;
    cpu->regs[30] = PB_BASE + 0x18893cULL; PB_CALL(173, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c354;
    cpu->regs[0] = cpu->regs[20] + 2576ULL;
    cpu->regs[30] = PB_BASE + 0x188948ULL; PB_CALL(174, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c348;
    cpu->regs[0] = cpu->regs[20] + 2816ULL;
    cpu->regs[30] = PB_BASE + 0x188954ULL; PB_CALL(175, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c33c;
    cpu->regs[0] = cpu->regs[20] + 3112ULL;
    cpu->regs[30] = PB_BASE + 0x188960ULL; PB_CALL(176, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c330;
    cpu->regs[0] = cpu->regs[20] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x18896cULL; PB_CALL(177, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c324;
    cpu->regs[0] = cpu->regs[20] + 3520ULL;
    cpu->regs[30] = PB_BASE + 0x188978ULL; PB_CALL(178, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c318;
    cpu->regs[0] = cpu->regs[20] + 3744ULL;
    cpu->regs[30] = PB_BASE + 0x188984ULL; PB_CALL(179, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c30c;
    cpu->regs[0] = cpu->regs[20] + 4016ULL;
    cpu->regs[30] = PB_BASE + 0x188990ULL; PB_CALL(180, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c300;
    cpu->regs[20] = PB_BASE + 0x462000ULL;
    cpu->regs[19] = cpu->regs[20] + 576ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1889a4ULL; PB_CALL(181, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c2f4;
    cpu->regs[0] = cpu->regs[19] + 288ULL;
    cpu->regs[30] = PB_BASE + 0x1889b0ULL; PB_CALL(182, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c2e8;
    cpu->regs[0] = cpu->regs[19] + 592ULL;
    cpu->regs[30] = PB_BASE + 0x1889bcULL; PB_CALL(183, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c2dc;
    cpu->regs[0] = cpu->regs[19] + 1136ULL;
    cpu->regs[30] = PB_BASE + 0x1889c8ULL; PB_CALL(184, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c2d0;
    cpu->regs[0] = cpu->regs[19] + 1392ULL;
    cpu->regs[30] = PB_BASE + 0x1889d4ULL; PB_CALL(185, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c2c4;
    cpu->regs[0] = cpu->regs[19] + 1632ULL;
    cpu->regs[30] = PB_BASE + 0x1889e0ULL; PB_CALL(186, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c2b8;
    cpu->regs[0] = cpu->regs[19] + 1872ULL;
    cpu->regs[30] = PB_BASE + 0x1889ecULL; PB_CALL(187, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c2ac;
    cpu->regs[0] = cpu->regs[19] + 2128ULL;
    cpu->regs[30] = PB_BASE + 0x1889f8ULL; PB_CALL(188, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c2a0;
    cpu->regs[0] = cpu->regs[19] + 2368ULL;
    cpu->regs[30] = PB_BASE + 0x188a04ULL; PB_CALL(189, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c294;
    cpu->regs[0] = cpu->regs[19] + 2608ULL;
    cpu->regs[30] = PB_BASE + 0x188a10ULL; PB_CALL(190, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c288;
    cpu->regs[0] = cpu->regs[19] + 2864ULL;
    cpu->regs[30] = PB_BASE + 0x188a1cULL; PB_CALL(191, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c27c;
    cpu->regs[0] = cpu->regs[19] + 3152ULL;
    cpu->regs[30] = PB_BASE + 0x188a28ULL; PB_CALL(192, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c270;
    cpu->regs[0] = cpu->regs[19] + 3384ULL;
    cpu->regs[30] = PB_BASE + 0x188a34ULL; PB_CALL(193, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c264;
    cpu->regs[0] = cpu->regs[19] + 3584ULL;
    cpu->regs[30] = PB_BASE + 0x188a40ULL; PB_CALL(194, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c258;
    cpu->regs[0] = cpu->regs[19] + 3792ULL;
    cpu->regs[30] = PB_BASE + 0x188a4cULL; PB_CALL(195, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c24c;
    cpu->regs[0] = cpu->regs[19] + 4016ULL;
    cpu->regs[30] = PB_BASE + 0x188a58ULL; PB_CALL(196, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c240;
    cpu->regs[19] = PB_BASE + 0x463000ULL;
    cpu->regs[20] = cpu->regs[19] + 832ULL;
    cpu->regs[0] = cpu->regs[20] - 136ULL;
    cpu->regs[30] = PB_BASE + 0x188a6cULL; PB_CALL(197, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c234;
    cpu->regs[0] = cpu->regs[20] + 64ULL;
    cpu->regs[30] = PB_BASE + 0x188a78ULL; PB_CALL(198, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c228;
    cpu->regs[0] = cpu->regs[20] + 368ULL;
    cpu->regs[30] = PB_BASE + 0x188a84ULL; PB_CALL(199, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c21c;
    cpu->regs[0] = cpu->regs[20] + 624ULL;
    cpu->regs[30] = PB_BASE + 0x188a90ULL; PB_CALL(200, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c210;
    cpu->regs[0] = cpu->regs[20] + 880ULL;
    cpu->regs[30] = PB_BASE + 0x188a9cULL; PB_CALL(201, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c204;
    cpu->regs[0] = cpu->regs[20] + 1392ULL;
    cpu->regs[30] = PB_BASE + 0x188aa8ULL; PB_CALL(202, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c1f8;
    cpu->regs[0] = cpu->regs[20] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x188ab4ULL; PB_CALL(203, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c1ec;
    cpu->regs[0] = cpu->regs[20] + 2240ULL;
    cpu->regs[30] = PB_BASE + 0x188ac0ULL; PB_CALL(204, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c1e0;
    cpu->regs[0] = cpu->regs[20] + 2752ULL;
    cpu->regs[30] = PB_BASE + 0x188accULL; PB_CALL(205, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c1d4;
    cpu->regs[0] = cpu->regs[20] + 3168ULL;
    cpu->regs[30] = PB_BASE + 0x188ad8ULL; PB_CALL(206, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c1c8;
    cpu->regs[0] = cpu->regs[20] + 3424ULL;
    cpu->regs[30] = PB_BASE + 0x188ae4ULL; PB_CALL(207, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c1bc;
    cpu->regs[0] = cpu->regs[20] + 3744ULL;
    cpu->regs[30] = PB_BASE + 0x188af0ULL; PB_CALL(208, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c1b0;
    cpu->regs[0] = cpu->regs[20] + 3984ULL;
    cpu->regs[30] = PB_BASE + 0x188afcULL; PB_CALL(209, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c1a4;
    cpu->regs[19] = PB_BASE + 0x464000ULL;
    cpu->regs[20] = cpu->regs[19] + 1088ULL;
    cpu->regs[0] = cpu->regs[20] + 96ULL;
    cpu->regs[30] = PB_BASE + 0x188b10ULL; PB_CALL(210, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c198;
    cpu->regs[0] = cpu->regs[20] + 320ULL;
    cpu->regs[30] = PB_BASE + 0x188b1cULL; PB_CALL(211, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c18c;
    cpu->regs[0] = cpu->regs[20] + 576ULL;
    cpu->regs[30] = PB_BASE + 0x188b28ULL; PB_CALL(212, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c180;
    cpu->regs[0] = cpu->regs[20] + 1728ULL;
    cpu->regs[30] = PB_BASE + 0x188b34ULL; PB_CALL(213, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c174;
    cpu->regs[0] = cpu->regs[20] + 2528ULL;
    cpu->regs[30] = PB_BASE + 0x188b40ULL; PB_CALL(214, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c168;
    cpu->regs[0] = cpu->regs[20] + 2800ULL;
    cpu->regs[30] = PB_BASE + 0x188b4cULL; PB_CALL(215, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c15c;
    cpu->regs[0] = cpu->regs[20] + 3024ULL;
    cpu->regs[30] = PB_BASE + 0x188b58ULL; PB_CALL(216, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c150;
    cpu->regs[0] = cpu->regs[20] + 3264ULL;
    cpu->regs[30] = PB_BASE + 0x188b64ULL; PB_CALL(217, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c144;
    cpu->regs[0] = cpu->regs[20] + 3536ULL;
    cpu->regs[30] = PB_BASE + 0x188b70ULL; PB_CALL(218, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c138;
    cpu->regs[0] = cpu->regs[20] + 4048ULL;
    cpu->regs[30] = PB_BASE + 0x188b7cULL; PB_CALL(219, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c12c;
    cpu->regs[19] = PB_BASE + 0x465000ULL;
    cpu->regs[20] = cpu->regs[19] + 1344ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x188b90ULL; PB_CALL(220, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c120;
    cpu->regs[0] = cpu->regs[20] + 208ULL;
    cpu->regs[30] = PB_BASE + 0x188b9cULL; PB_CALL(221, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c114;
    cpu->regs[0] = cpu->regs[20] + 624ULL;
    cpu->regs[30] = PB_BASE + 0x188ba8ULL; PB_CALL(222, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c108;
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[20] + 2048ULL;
    cpu->regs[0] = cpu->regs[19] + 1832ULL;
    cpu->regs[30] = PB_BASE + 0x188bbcULL; PB_CALL(223, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c0fc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x188bc8ULL; PB_CALL(224, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c0f0;
    cpu->regs[0] = cpu->regs[19] + 2960ULL;
    cpu->regs[30] = PB_BASE + 0x188bd4ULL; PB_CALL(225, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c0e4;
    cpu->regs[0] = cpu->regs[19] + 3440ULL;
    cpu->regs[30] = PB_BASE + 0x188be0ULL; PB_CALL(226, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c0d8;
    cpu->regs[0] = cpu->regs[19] + 3680ULL;
    cpu->regs[30] = PB_BASE + 0x188becULL; PB_CALL(227, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c0cc;
    cpu->regs[19] = PB_BASE + 0x466000ULL;
    cpu->regs[20] = cpu->regs[19] + 1600ULL;
    cpu->regs[0] = cpu->regs[20] - 144ULL;
    cpu->regs[30] = PB_BASE + 0x188c00ULL; PB_CALL(228, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c0c0;
    cpu->regs[0] = cpu->regs[20] + 96ULL;
    cpu->regs[30] = PB_BASE + 0x188c0cULL; PB_CALL(229, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c0b4;
    cpu->regs[0] = cpu->regs[20] + 576ULL;
    cpu->regs[30] = PB_BASE + 0x188c18ULL; PB_CALL(230, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c0a8;
    cpu->regs[0] = cpu->regs[20] + 848ULL;
    cpu->regs[30] = PB_BASE + 0x188c24ULL; PB_CALL(231, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c09c;
    cpu->regs[0] = cpu->regs[20] + 1760ULL;
    cpu->regs[30] = PB_BASE + 0x188c30ULL; PB_CALL(232, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c090;
    cpu->regs[0] = cpu->regs[20] + 1984ULL;
    cpu->regs[30] = PB_BASE + 0x188c3cULL; PB_CALL(233, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c084;
    cpu->regs[0] = cpu->regs[20] + 2400ULL;
    cpu->regs[30] = PB_BASE + 0x188c48ULL; PB_CALL(234, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c078;
    cpu->regs[0] = cpu->regs[20] + 2672ULL;
    cpu->regs[30] = PB_BASE + 0x188c54ULL; PB_CALL(235, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c06c;
    cpu->regs[0] = cpu->regs[20] + 2960ULL;
    cpu->regs[30] = PB_BASE + 0x188c60ULL; PB_CALL(236, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c060;
    cpu->regs[0] = cpu->regs[20] + 3232ULL;
    cpu->regs[30] = PB_BASE + 0x188c6cULL; PB_CALL(237, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c054;
    cpu->regs[0] = cpu->regs[20] + 3472ULL;
    cpu->regs[30] = PB_BASE + 0x188c78ULL; PB_CALL(238, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c048;
    cpu->regs[0] = cpu->regs[20] + 3776ULL;
    cpu->regs[30] = PB_BASE + 0x188c84ULL; PB_CALL(239, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c03c;
    cpu->regs[19] = PB_BASE + 0x467000ULL;
    cpu->regs[20] = cpu->regs[19] + 1856ULL;
    cpu->regs[0] = cpu->regs[20] + 2192ULL;
    cpu->regs[30] = PB_BASE + 0x188c98ULL; PB_CALL(240, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c030;
    cpu->regs[0] = cpu->regs[20] + 2640ULL;
    cpu->regs[30] = PB_BASE + 0x188ca4ULL; PB_CALL(241, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c024;
    cpu->regs[0] = cpu->regs[20] + 3568ULL;
    cpu->regs[30] = PB_BASE + 0x188cb0ULL; PB_CALL(242, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c018;
    cpu->regs[0] = cpu->regs[20] + 3808ULL;
    cpu->regs[30] = PB_BASE + 0x188cbcULL; PB_CALL(243, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c00c;
    cpu->regs[20] = PB_BASE + 0x468000ULL;
    cpu->regs[19] = cpu->regs[20] + 2112ULL;
    cpu->regs[0] = cpu->regs[19] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x188cd0ULL; PB_CALL(244, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c000;
    cpu->regs[0] = cpu->regs[19] + 528ULL;
    cpu->regs[30] = PB_BASE + 0x188cdcULL; PB_CALL(245, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bff4;
    cpu->regs[0] = cpu->regs[19] + 784ULL;
    cpu->regs[30] = PB_BASE + 0x188ce8ULL; PB_CALL(246, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bfe8;
    cpu->regs[0] = cpu->regs[19] + 1104ULL;
    cpu->regs[30] = PB_BASE + 0x188cf4ULL; PB_CALL(247, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bfdc;
    cpu->regs[0] = cpu->regs[19] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x188d00ULL; PB_CALL(248, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bfd0;
    cpu->regs[0] = cpu->regs[19] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x188d0cULL; PB_CALL(249, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bfc4;
    cpu->regs[0] = cpu->regs[19] + 2496ULL;
    cpu->regs[30] = PB_BASE + 0x188d18ULL; PB_CALL(250, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bfb8;
    cpu->regs[0] = cpu->regs[19] + 3104ULL;
    cpu->regs[30] = PB_BASE + 0x188d24ULL; PB_CALL(251, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bfac;
    cpu->regs[0] = cpu->regs[19] + 3328ULL;
    cpu->regs[30] = PB_BASE + 0x188d30ULL; PB_CALL(252, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bfa0;
    cpu->regs[0] = cpu->regs[19] + 3584ULL;
    cpu->regs[30] = PB_BASE + 0x188d3cULL; PB_CALL(253, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf94;
    cpu->regs[0] = cpu->regs[19] + 3824ULL;
    cpu->regs[30] = PB_BASE + 0x188d48ULL; PB_CALL(254, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf88;
    cpu->regs[0] = cpu->regs[19] + 4080ULL;
    cpu->regs[30] = PB_BASE + 0x188d54ULL; PB_CALL(255, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf7c;
    cpu->regs[19] = PB_BASE + 0x469000ULL;
    cpu->regs[20] = cpu->regs[19] + 2368ULL;
    cpu->regs[0] = cpu->regs[20] - 32ULL;
    cpu->regs[30] = PB_BASE + 0x188d68ULL; PB_CALL(256, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf70;
    cpu->regs[0] = cpu->regs[20] + 192ULL;
    cpu->regs[30] = PB_BASE + 0x188d74ULL; PB_CALL(257, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf64;
    cpu->regs[0] = cpu->regs[20] + 464ULL;
    cpu->regs[30] = PB_BASE + 0x188d80ULL; PB_CALL(258, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf58;
    cpu->regs[0] = cpu->regs[20] + 688ULL;
    cpu->regs[30] = PB_BASE + 0x188d8cULL; PB_CALL(259, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf4c;
    cpu->regs[0] = cpu->regs[20] + 912ULL;
    cpu->regs[30] = PB_BASE + 0x188d98ULL; PB_CALL(260, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf40;
    cpu->regs[0] = cpu->regs[20] + 1136ULL;
    cpu->regs[30] = PB_BASE + 0x188da4ULL; PB_CALL(261, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf34;
    cpu->regs[0] = cpu->regs[20] + 1632ULL;
    cpu->regs[30] = PB_BASE + 0x188db0ULL; PB_CALL(262, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf28;
    cpu->regs[0] = cpu->regs[20] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x188dbcULL; PB_CALL(263, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf1c;
    cpu->regs[0] = cpu->regs[20] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x188dc8ULL; PB_CALL(264, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf10;
    cpu->regs[0] = cpu->regs[20] + 2352ULL;
    cpu->regs[30] = PB_BASE + 0x188dd4ULL; PB_CALL(265, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bf04;
    cpu->regs[0] = cpu->regs[20] + 2928ULL;
    cpu->regs[30] = PB_BASE + 0x188de0ULL; PB_CALL(266, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bef8;
    cpu->regs[0] = cpu->regs[20] + 3152ULL;
    cpu->regs[30] = PB_BASE + 0x188decULL; PB_CALL(267, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18beec;
    cpu->regs[0] = cpu->regs[20] + 3584ULL;
    cpu->regs[30] = PB_BASE + 0x188df8ULL; PB_CALL(268, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bee0;
    cpu->regs[0] = cpu->regs[20] + 3952ULL;
    cpu->regs[30] = PB_BASE + 0x188e04ULL; PB_CALL(269, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bed4;
    cpu->regs[19] = PB_BASE + 0x46a000ULL;
    cpu->regs[20] = cpu->regs[19] + 2624ULL;
    cpu->regs[0] = cpu->regs[20] - 64ULL;
    cpu->regs[30] = PB_BASE + 0x188e18ULL; PB_CALL(270, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bec8;
    cpu->regs[0] = cpu->regs[20] + 176ULL;
    cpu->regs[30] = PB_BASE + 0x188e24ULL; PB_CALL(271, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bebc;
    cpu->regs[0] = cpu->regs[20] + 384ULL;
    cpu->regs[30] = PB_BASE + 0x188e30ULL; PB_CALL(272, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18beb0;
    cpu->regs[0] = cpu->regs[20] + 592ULL;
    cpu->regs[30] = PB_BASE + 0x188e3cULL; PB_CALL(273, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bea4;
    cpu->regs[0] = cpu->regs[20] + 816ULL;
    cpu->regs[30] = PB_BASE + 0x188e48ULL; PB_CALL(274, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be98;
    cpu->regs[0] = cpu->regs[20] + 1040ULL;
    cpu->regs[30] = PB_BASE + 0x188e54ULL; PB_CALL(275, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be8c;
    cpu->regs[0] = cpu->regs[20] + 1248ULL;
    cpu->regs[30] = PB_BASE + 0x188e60ULL; PB_CALL(276, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be80;
    cpu->regs[0] = cpu->regs[20] + 1448ULL;
    cpu->regs[30] = PB_BASE + 0x188e6cULL; PB_CALL(277, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be74;
    cpu->regs[0] = cpu->regs[20] + 1648ULL;
    cpu->regs[30] = PB_BASE + 0x188e78ULL; PB_CALL(278, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be68;
    cpu->regs[0] = cpu->regs[20] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x188e84ULL; PB_CALL(279, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be5c;
    cpu->regs[0] = cpu->regs[20] + 2112ULL;
    cpu->regs[30] = PB_BASE + 0x188e90ULL; PB_CALL(280, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be50;
    cpu->regs[0] = cpu->regs[20] + 2368ULL;
    cpu->regs[30] = PB_BASE + 0x188e9cULL; PB_CALL(281, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be44;
    cpu->regs[0] = cpu->regs[20] + 2576ULL;
    cpu->regs[30] = PB_BASE + 0x188ea8ULL; PB_CALL(282, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be38;
    cpu->regs[0] = cpu->regs[20] + 2896ULL;
    cpu->regs[30] = PB_BASE + 0x188eb4ULL; PB_CALL(283, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be2c;
    cpu->regs[0] = cpu->regs[20] + 3152ULL;
    cpu->regs[30] = PB_BASE + 0x188ec0ULL; PB_CALL(284, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be20;
    cpu->regs[0] = cpu->regs[20] + 3392ULL;
    cpu->regs[30] = PB_BASE + 0x188eccULL; PB_CALL(285, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be14;
    cpu->regs[0] = cpu->regs[20] + 3616ULL;
    cpu->regs[30] = PB_BASE + 0x188ed8ULL; PB_CALL(286, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18be08;
    cpu->regs[0] = cpu->regs[20] + 3872ULL;
    cpu->regs[30] = PB_BASE + 0x188ee4ULL; PB_CALL(287, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bdfc;
    cpu->regs[0] = cpu->regs[20] + 4088ULL;
    cpu->regs[30] = PB_BASE + 0x188ef0ULL; PB_CALL(288, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bdf0;
    cpu->regs[20] = PB_BASE + 0x46b000ULL;
    cpu->regs[19] = cpu->regs[20] + 2880ULL;
    cpu->regs[0] = cpu->regs[19] - 56ULL;
    cpu->regs[30] = PB_BASE + 0x188f04ULL; PB_CALL(289, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bde4;
    cpu->regs[0] = cpu->regs[19] + 144ULL;
    cpu->regs[30] = PB_BASE + 0x188f10ULL; PB_CALL(290, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bdd8;
    cpu->regs[0] = cpu->regs[19] + 344ULL;
    cpu->regs[30] = PB_BASE + 0x188f1cULL; PB_CALL(291, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bdcc;
    cpu->regs[0] = cpu->regs[19] + 544ULL;
    cpu->regs[30] = PB_BASE + 0x188f28ULL; PB_CALL(292, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bdc0;
    cpu->regs[0] = cpu->regs[19] + 800ULL;
    cpu->regs[30] = PB_BASE + 0x188f34ULL; PB_CALL(293, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bdb4;
    cpu->regs[0] = cpu->regs[19] + 1056ULL;
    cpu->regs[30] = PB_BASE + 0x188f40ULL; PB_CALL(294, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bda8;
    cpu->regs[0] = cpu->regs[19] + 1264ULL;
    cpu->regs[30] = PB_BASE + 0x188f4cULL; PB_CALL(295, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd9c;
    cpu->regs[0] = cpu->regs[19] + 1584ULL;
    cpu->regs[30] = PB_BASE + 0x188f58ULL; PB_CALL(296, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd90;
    cpu->regs[0] = cpu->regs[19] + 1840ULL;
    cpu->regs[30] = PB_BASE + 0x188f64ULL; PB_CALL(297, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd84;
    cpu->regs[0] = cpu->regs[19] + 2064ULL;
    cpu->regs[30] = PB_BASE + 0x188f70ULL; PB_CALL(298, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd78;
    cpu->regs[0] = cpu->regs[19] + 2288ULL;
    cpu->regs[30] = PB_BASE + 0x188f7cULL; PB_CALL(299, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd6c;
    cpu->regs[0] = cpu->regs[19] + 2544ULL;
    cpu->regs[30] = PB_BASE + 0x188f88ULL; PB_CALL(300, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd60;
    cpu->regs[0] = cpu->regs[19] + 2768ULL;
    cpu->regs[30] = PB_BASE + 0x188f94ULL; PB_CALL(301, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd54;
    cpu->regs[0] = cpu->regs[19] + 3088ULL;
    cpu->regs[30] = PB_BASE + 0x188fa0ULL; PB_CALL(302, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd48;
    cpu->regs[0] = cpu->regs[19] + 3352ULL;
    cpu->regs[30] = PB_BASE + 0x188facULL; PB_CALL(303, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd3c;
    cpu->regs[0] = cpu->regs[19] + 3552ULL;
    cpu->regs[30] = PB_BASE + 0x188fb8ULL; PB_CALL(304, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd30;
    cpu->regs[0] = cpu->regs[19] + 3872ULL;
    cpu->regs[30] = PB_BASE + 0x188fc4ULL; PB_CALL(305, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd24;
    cpu->regs[20] = PB_BASE + 0x46c000ULL;
    cpu->regs[19] = cpu->regs[20] + 3136ULL;
    cpu->regs[0] = cpu->regs[19] - 248ULL;
    cpu->regs[30] = PB_BASE + 0x188fd8ULL; PB_CALL(306, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd18;
    cpu->regs[0] = cpu->regs[19] - 48ULL;
    cpu->regs[30] = PB_BASE + 0x188fe4ULL; PB_CALL(307, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd0c;
    cpu->regs[0] = cpu->regs[19] + 208ULL;
    cpu->regs[30] = PB_BASE + 0x188ff0ULL; PB_CALL(308, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bd00;
    cpu->regs[0] = cpu->regs[19] + 480ULL;
    cpu->regs[30] = PB_BASE + 0x188ffcULL; PB_CALL(309, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bcf4;
    cpu->regs[0] = cpu->regs[19] + 752ULL;
    cpu->regs[30] = PB_BASE + 0x189008ULL; PB_CALL(310, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bce8;
    cpu->regs[0] = cpu->regs[19] + 1080ULL;
    cpu->regs[30] = PB_BASE + 0x189014ULL; PB_CALL(311, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bcdc;
    cpu->regs[0] = cpu->regs[19] + 1296ULL;
    cpu->regs[30] = PB_BASE + 0x189020ULL; PB_CALL(312, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bcd0;
    cpu->regs[0] = cpu->regs[19] + 2336ULL;
    cpu->regs[30] = PB_BASE + 0x18902cULL; PB_CALL(313, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bcc4;
    cpu->regs[0] = cpu->regs[19] + 3600ULL;
    cpu->regs[30] = PB_BASE + 0x189038ULL; PB_CALL(314, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bcb8;
    cpu->regs[0] = cpu->regs[19] + 3872ULL;
    cpu->regs[30] = PB_BASE + 0x189044ULL; PB_CALL(315, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bcac;
    cpu->regs[19] = PB_BASE + 0x46d000ULL;
    cpu->regs[20] = cpu->regs[19] + 3392ULL;
    cpu->regs[0] = cpu->regs[20] - 208ULL;
    cpu->regs[30] = PB_BASE + 0x189058ULL; PB_CALL(316, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bca0;
    cpu->regs[0] = cpu->regs[20] + 80ULL;
    cpu->regs[30] = PB_BASE + 0x189064ULL; PB_CALL(317, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc94;
    cpu->regs[0] = cpu->regs[20] + 328ULL;
    cpu->regs[30] = PB_BASE + 0x189070ULL; PB_CALL(318, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc88;
    cpu->regs[0] = cpu->regs[20] + 528ULL;
    cpu->regs[30] = PB_BASE + 0x18907cULL; PB_CALL(319, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc7c;
    cpu->regs[0] = cpu->regs[20] + 760ULL;
    cpu->regs[30] = PB_BASE + 0x189088ULL; PB_CALL(320, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc70;
    cpu->regs[0] = cpu->regs[20] + 960ULL;
    cpu->regs[30] = PB_BASE + 0x189094ULL; PB_CALL(321, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc64;
    cpu->regs[0] = cpu->regs[20] + 1216ULL;
    cpu->regs[30] = PB_BASE + 0x1890a0ULL; PB_CALL(322, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc58;
    cpu->regs[0] = cpu->regs[20] + 1488ULL;
    cpu->regs[30] = PB_BASE + 0x1890acULL; PB_CALL(323, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc4c;
    cpu->regs[0] = cpu->regs[20] + 1792ULL;
    cpu->regs[30] = PB_BASE + 0x1890b8ULL; PB_CALL(324, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc40;
    cpu->regs[0] = cpu->regs[20] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x1890c4ULL; PB_CALL(325, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc34;
    cpu->regs[0] = cpu->regs[20] + 2336ULL;
    cpu->regs[30] = PB_BASE + 0x1890d0ULL; PB_CALL(326, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc28;
    cpu->regs[0] = cpu->regs[20] + 2592ULL;
    cpu->regs[30] = PB_BASE + 0x1890dcULL; PB_CALL(327, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc1c;
    cpu->regs[0] = cpu->regs[20] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x1890e8ULL; PB_CALL(328, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc10;
    cpu->regs[0] = cpu->regs[20] + 3088ULL;
    cpu->regs[30] = PB_BASE + 0x1890f4ULL; PB_CALL(329, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bc04;
    cpu->regs[0] = cpu->regs[20] + 3296ULL;
    cpu->regs[30] = PB_BASE + 0x189100ULL; PB_CALL(330, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bbf8;
    cpu->regs[0] = cpu->regs[20] + 3552ULL;
    cpu->regs[30] = PB_BASE + 0x18910cULL; PB_CALL(331, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bbec;
    cpu->regs[0] = cpu->regs[20] + 3808ULL;
    cpu->regs[30] = PB_BASE + 0x189118ULL; PB_CALL(332, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bbe0;
    cpu->regs[20] = PB_BASE + 0x46e000ULL;
    cpu->regs[19] = cpu->regs[20] + 3648ULL;
    cpu->regs[0] = cpu->regs[19] - 240ULL;
    cpu->regs[30] = PB_BASE + 0x18912cULL; PB_CALL(333, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bbd4;
    cpu->regs[0] = cpu->regs[19] + 144ULL;
    cpu->regs[30] = PB_BASE + 0x189138ULL; PB_CALL(334, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bbc8;
    cpu->regs[0] = cpu->regs[19] + 376ULL;
    cpu->regs[30] = PB_BASE + 0x189144ULL; PB_CALL(335, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bbbc;
    cpu->regs[0] = cpu->regs[19] + 576ULL;
    cpu->regs[30] = PB_BASE + 0x189150ULL; PB_CALL(336, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bbb0;
    cpu->regs[0] = cpu->regs[19] + 832ULL;
    cpu->regs[30] = PB_BASE + 0x18915cULL; PB_CALL(337, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bba4;
    cpu->regs[0] = cpu->regs[19] + 1104ULL;
    cpu->regs[30] = PB_BASE + 0x189168ULL; PB_CALL(338, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb98;
    cpu->regs[0] = cpu->regs[19] + 1424ULL;
    cpu->regs[30] = PB_BASE + 0x189174ULL; PB_CALL(339, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb8c;
    cpu->regs[0] = cpu->regs[19] + 1744ULL;
    cpu->regs[30] = PB_BASE + 0x189180ULL; PB_CALL(340, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb80;
    cpu->regs[0] = cpu->regs[19] + 2064ULL;
    cpu->regs[30] = PB_BASE + 0x18918cULL; PB_CALL(341, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb74;
    cpu->regs[0] = cpu->regs[19] + 2448ULL;
    cpu->regs[30] = PB_BASE + 0x189198ULL; PB_CALL(342, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb68;
    cpu->regs[0] = cpu->regs[19] + 2800ULL;
    cpu->regs[30] = PB_BASE + 0x1891a4ULL; PB_CALL(343, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb5c;
    cpu->regs[0] = cpu->regs[19] + 3104ULL;
    cpu->regs[30] = PB_BASE + 0x1891b0ULL; PB_CALL(344, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb50;
    cpu->regs[0] = cpu->regs[19] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x1891bcULL; PB_CALL(345, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb44;
    cpu->regs[0] = cpu->regs[19] + 3632ULL;
    cpu->regs[30] = PB_BASE + 0x1891c8ULL; PB_CALL(346, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb38;
    cpu->regs[0] = cpu->regs[19] + 3984ULL;
    cpu->regs[30] = PB_BASE + 0x1891d4ULL; PB_CALL(347, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb2c;
    cpu->regs[19] = PB_BASE + 0x46f000ULL;
    cpu->regs[20] = cpu->regs[19] + 3904ULL;
    cpu->regs[0] = cpu->regs[20] - 64ULL;
    cpu->regs[30] = PB_BASE + 0x1891e8ULL; PB_CALL(348, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb20;
    cpu->regs[0] = cpu->regs[20] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x1891f4ULL; PB_CALL(349, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb14;
    cpu->regs[0] = cpu->regs[20] + 488ULL;
    cpu->regs[30] = PB_BASE + 0x189200ULL; PB_CALL(350, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bb08;
    cpu->regs[0] = cpu->regs[20] + 688ULL;
    cpu->regs[30] = PB_BASE + 0x18920cULL; PB_CALL(351, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bafc;
    cpu->regs[0] = cpu->regs[20] + 944ULL;
    cpu->regs[30] = PB_BASE + 0x189218ULL; PB_CALL(352, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18baf0;
    cpu->regs[0] = cpu->regs[20] + 1216ULL;
    cpu->regs[30] = PB_BASE + 0x189224ULL; PB_CALL(353, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bae4;
    cpu->regs[0] = cpu->regs[20] + 1536ULL;
    cpu->regs[30] = PB_BASE + 0x189230ULL; PB_CALL(354, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bad8;
    cpu->regs[0] = cpu->regs[20] + 1968ULL;
    cpu->regs[30] = PB_BASE + 0x18923cULL; PB_CALL(355, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bacc;
    cpu->regs[0] = cpu->regs[20] + 2368ULL;
    cpu->regs[30] = PB_BASE + 0x189248ULL; PB_CALL(356, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bac0;
    cpu->regs[0] = cpu->regs[20] + 2608ULL;
    cpu->regs[30] = PB_BASE + 0x189254ULL; PB_CALL(357, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18bab4;
    cpu->regs[0] = cpu->regs[20] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x189260ULL; PB_CALL(358, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18baa8;
    cpu->regs[0] = cpu->regs[20] + 3120ULL;
    cpu->regs[30] = PB_BASE + 0x18926cULL; PB_CALL(359, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba9c;
    cpu->regs[0] = cpu->regs[20] + 3392ULL;
    cpu->regs[30] = PB_BASE + 0x189278ULL; PB_CALL(360, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba90;
    cpu->regs[0] = cpu->regs[20] + 3632ULL;
    cpu->regs[30] = PB_BASE + 0x189284ULL; PB_CALL(361, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba84;
    cpu->regs[0] = cpu->regs[20] + 3872ULL;
    cpu->regs[30] = PB_BASE + 0x189290ULL; PB_CALL(362, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba78;
    cpu->regs[20] = PB_BASE + 0x471000ULL;
    cpu->regs[19] = cpu->regs[20] + 64ULL;
    cpu->regs[0] = cpu->regs[19] - 128ULL;
    cpu->regs[30] = PB_BASE + 0x1892a4ULL; PB_CALL(363, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba6c;
    cpu->regs[0] = cpu->regs[19] + 224ULL;
    cpu->regs[30] = PB_BASE + 0x1892b0ULL; PB_CALL(364, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba60;
    cpu->regs[0] = cpu->regs[19] + 464ULL;
    cpu->regs[30] = PB_BASE + 0x1892bcULL; PB_CALL(365, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba54;
    cpu->regs[0] = cpu->regs[19] + 752ULL;
    cpu->regs[30] = PB_BASE + 0x1892c8ULL; PB_CALL(366, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba48;
    cpu->regs[0] = cpu->regs[19] + 1600ULL;
    cpu->regs[30] = PB_BASE + 0x1892d4ULL; PB_CALL(367, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba3c;
    cpu->regs[0] = cpu->regs[19] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x1892e0ULL; PB_CALL(368, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba30;
    cpu->regs[0] = cpu->regs[19] + 2112ULL;
    cpu->regs[30] = PB_BASE + 0x1892ecULL; PB_CALL(369, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba24;
    cpu->regs[0] = cpu->regs[19] + 2368ULL;
    cpu->regs[30] = PB_BASE + 0x1892f8ULL; PB_CALL(370, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba18;
    cpu->regs[0] = cpu->regs[19] + 2624ULL;
    cpu->regs[30] = PB_BASE + 0x189304ULL; PB_CALL(371, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba0c;
    cpu->regs[0] = cpu->regs[19] + 3360ULL;
    cpu->regs[30] = PB_BASE + 0x189310ULL; PB_CALL(372, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ba00;
    cpu->regs[0] = cpu->regs[19] + 3560ULL;
    cpu->regs[30] = PB_BASE + 0x18931cULL; PB_CALL(373, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b9f4;
    cpu->regs[0] = cpu->regs[19] + 3768ULL;
    cpu->regs[30] = PB_BASE + 0x189328ULL; PB_CALL(374, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b9e8;
    cpu->regs[0] = cpu->regs[19] + 3984ULL;
    cpu->regs[30] = PB_BASE + 0x189334ULL; PB_CALL(375, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b9dc;
    cpu->regs[19] = PB_BASE + 0x472000ULL;
    cpu->regs[20] = cpu->regs[19] + 320ULL;
    cpu->regs[0] = cpu->regs[20] - 144ULL;
    cpu->regs[30] = PB_BASE + 0x189348ULL; PB_CALL(376, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b9d0;
    cpu->regs[0] = cpu->regs[20] + 200ULL;
    cpu->regs[30] = PB_BASE + 0x189354ULL; PB_CALL(377, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b9c4;
    cpu->regs[0] = cpu->regs[20] + 400ULL;
    cpu->regs[30] = PB_BASE + 0x189360ULL; PB_CALL(378, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b9b8;
    cpu->regs[0] = cpu->regs[20] + 656ULL;
    cpu->regs[30] = PB_BASE + 0x18936cULL; PB_CALL(379, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b9ac;
    cpu->regs[0] = cpu->regs[20] + 896ULL;
    cpu->regs[30] = PB_BASE + 0x189378ULL; PB_CALL(380, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b9a0;
    cpu->regs[0] = cpu->regs[20] + 1120ULL;
    cpu->regs[30] = PB_BASE + 0x189384ULL; PB_CALL(381, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b994;
    cpu->regs[0] = cpu->regs[20] + 1376ULL;
    cpu->regs[30] = PB_BASE + 0x189390ULL; PB_CALL(382, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b988;
    cpu->regs[0] = cpu->regs[20] + 1632ULL;
    cpu->regs[30] = PB_BASE + 0x18939cULL; PB_CALL(383, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b97c;
    cpu->regs[0] = cpu->regs[20] + 1840ULL;
    cpu->regs[30] = PB_BASE + 0x1893a8ULL; PB_CALL(384, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b970;
    cpu->regs[0] = cpu->regs[20] + 2112ULL;
    cpu->regs[30] = PB_BASE + 0x1893b4ULL; PB_CALL(385, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b964;
    cpu->regs[0] = cpu->regs[20] + 2416ULL;
    cpu->regs[30] = PB_BASE + 0x1893c0ULL; PB_CALL(386, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b958;
    cpu->regs[0] = cpu->regs[20] + 2672ULL;
    cpu->regs[30] = PB_BASE + 0x1893ccULL; PB_CALL(387, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b94c;
    cpu->regs[0] = cpu->regs[20] + 2944ULL;
    cpu->regs[30] = PB_BASE + 0x1893d8ULL; PB_CALL(388, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b940;
    cpu->regs[0] = cpu->regs[20] + 3168ULL;
    cpu->regs[30] = PB_BASE + 0x1893e4ULL; PB_CALL(389, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b934;
    cpu->regs[0] = cpu->regs[20] + 3424ULL;
    cpu->regs[30] = PB_BASE + 0x1893f0ULL; PB_CALL(390, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b928;
    cpu->regs[0] = cpu->regs[20] + 3680ULL;
    cpu->regs[30] = PB_BASE + 0x1893fcULL; PB_CALL(391, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b91c;
    cpu->regs[0] = cpu->regs[20] + 3896ULL;
    cpu->regs[30] = PB_BASE + 0x189408ULL; PB_CALL(392, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b910;
    cpu->regs[19] = PB_BASE + 0x473000ULL;
    cpu->regs[20] = cpu->regs[19] + 576ULL;
    cpu->regs[0] = cpu->regs[20] - 256ULL;
    cpu->regs[30] = PB_BASE + 0x18941cULL; PB_CALL(393, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b904;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x189428ULL; PB_CALL(394, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b8f8;
    cpu->regs[0] = cpu->regs[20] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x189434ULL; PB_CALL(395, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b8ec;
    cpu->regs[0] = cpu->regs[20] + 512ULL;
    cpu->regs[30] = PB_BASE + 0x189440ULL; PB_CALL(396, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b8e0;
    cpu->regs[0] = cpu->regs[20] + 736ULL;
    cpu->regs[30] = PB_BASE + 0x18944cULL; PB_CALL(397, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b8d4;
    cpu->regs[0] = cpu->regs[20] + 1008ULL;
    cpu->regs[30] = PB_BASE + 0x189458ULL; PB_CALL(398, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b8c8;
    cpu->regs[0] = cpu->regs[20] + 1344ULL;
    cpu->regs[30] = PB_BASE + 0x189464ULL; PB_CALL(399, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b8bc;
    cpu->regs[0] = cpu->regs[20] + 1600ULL;
    cpu->regs[30] = PB_BASE + 0x189470ULL; PB_CALL(400, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b8b0;
    cpu->regs[0] = cpu->regs[20] + 1872ULL;
    cpu->regs[30] = PB_BASE + 0x18947cULL; PB_CALL(401, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b8a4;
    cpu->regs[0] = cpu->regs[20] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x189488ULL; PB_CALL(402, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b898;
    cpu->regs[0] = cpu->regs[20] + 2336ULL;
    cpu->regs[30] = PB_BASE + 0x189494ULL; PB_CALL(403, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b88c;
    cpu->regs[0] = cpu->regs[20] + 2592ULL;
    cpu->regs[30] = PB_BASE + 0x1894a0ULL; PB_CALL(404, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b880;
    cpu->regs[0] = cpu->regs[20] + 2800ULL;
    cpu->regs[30] = PB_BASE + 0x1894acULL; PB_CALL(405, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b874;
    cpu->regs[0] = cpu->regs[20] + 3008ULL;
    cpu->regs[30] = PB_BASE + 0x1894b8ULL; PB_CALL(406, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b868;
    cpu->regs[0] = cpu->regs[20] + 3264ULL;
    cpu->regs[30] = PB_BASE + 0x1894c4ULL; PB_CALL(407, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b85c;
    cpu->regs[0] = cpu->regs[20] + 3512ULL;
    cpu->regs[30] = PB_BASE + 0x1894d0ULL; PB_CALL(408, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b850;
    cpu->regs[0] = cpu->regs[20] + 3728ULL;
    cpu->regs[30] = PB_BASE + 0x1894dcULL; PB_CALL(409, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b844;
    cpu->regs[0] = cpu->regs[20] + 3984ULL;
    cpu->regs[30] = PB_BASE + 0x1894e8ULL; PB_CALL(410, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b838;
    cpu->regs[19] = PB_BASE + 0x474000ULL;
    cpu->regs[20] = cpu->regs[19] + 832ULL;
    cpu->regs[0] = cpu->regs[20] - 128ULL;
    cpu->regs[30] = PB_BASE + 0x1894fcULL; PB_CALL(411, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b82c;
    cpu->regs[0] = cpu->regs[20] + 104ULL;
    cpu->regs[30] = PB_BASE + 0x189508ULL; PB_CALL(412, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b820;
    cpu->regs[0] = cpu->regs[20] + 320ULL;
    cpu->regs[30] = PB_BASE + 0x189514ULL; PB_CALL(413, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b814;
    cpu->regs[0] = cpu->regs[20] + 592ULL;
    cpu->regs[30] = PB_BASE + 0x189520ULL; PB_CALL(414, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b808;
    cpu->regs[0] = cpu->regs[20] + 896ULL;
    cpu->regs[30] = PB_BASE + 0x18952cULL; PB_CALL(415, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b7fc;
    cpu->regs[0] = cpu->regs[20] + 1152ULL;
    cpu->regs[30] = PB_BASE + 0x189538ULL; PB_CALL(416, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b7f0;
    cpu->regs[0] = cpu->regs[20] + 1424ULL;
    cpu->regs[30] = PB_BASE + 0x189544ULL; PB_CALL(417, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b7e4;
    cpu->regs[0] = cpu->regs[20] + 1632ULL;
    cpu->regs[30] = PB_BASE + 0x189550ULL; PB_CALL(418, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b7d8;
    cpu->regs[0] = cpu->regs[20] + 1888ULL;
    cpu->regs[30] = PB_BASE + 0x18955cULL; PB_CALL(419, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b7cc;
    cpu->regs[0] = cpu->regs[20] + 2128ULL;
    cpu->regs[30] = PB_BASE + 0x189568ULL; PB_CALL(420, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b7c0;
    cpu->regs[0] = cpu->regs[20] + 2336ULL;
    cpu->regs[30] = PB_BASE + 0x189574ULL; PB_CALL(421, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b7b4;
    cpu->regs[0] = cpu->regs[20] + 2592ULL;
    cpu->regs[30] = PB_BASE + 0x189580ULL; PB_CALL(422, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b7a8;
    cpu->regs[0] = cpu->regs[20] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x18958cULL; PB_CALL(423, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b79c;
    cpu->regs[0] = cpu->regs[20] + 3104ULL;
    cpu->regs[30] = PB_BASE + 0x189598ULL; PB_CALL(424, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b790;
    cpu->regs[0] = cpu->regs[20] + 3328ULL;
    cpu->regs[30] = PB_BASE + 0x1895a4ULL; PB_CALL(425, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b784;
    cpu->regs[0] = cpu->regs[20] + 3536ULL;
    cpu->regs[30] = PB_BASE + 0x1895b0ULL; PB_CALL(426, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b778;
    cpu->regs[0] = cpu->regs[20] + 3792ULL;
    cpu->regs[30] = PB_BASE + 0x1895bcULL; PB_CALL(427, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b76c;
    cpu->regs[0] = cpu->regs[20] + 4048ULL;
    cpu->regs[30] = PB_BASE + 0x1895c8ULL; PB_CALL(428, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b760;
    cpu->regs[19] = PB_BASE + 0x475000ULL;
    cpu->regs[20] = cpu->regs[19] + 1088ULL;
    cpu->regs[0] = cpu->regs[20] + 128ULL;
    cpu->regs[30] = PB_BASE + 0x1895dcULL; PB_CALL(429, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b754;
    cpu->regs[0] = cpu->regs[20] + 624ULL;
    cpu->regs[30] = PB_BASE + 0x1895e8ULL; PB_CALL(430, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b748;
    cpu->regs[0] = cpu->regs[20] + 976ULL;
    cpu->regs[30] = PB_BASE + 0x1895f4ULL; PB_CALL(431, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b73c;
    cpu->regs[0] = cpu->regs[20] + 1392ULL;
    cpu->regs[30] = PB_BASE + 0x189600ULL; PB_CALL(432, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b730;
    cpu->regs[0] = cpu->regs[20] + 1648ULL;
    cpu->regs[30] = PB_BASE + 0x18960cULL; PB_CALL(433, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b724;
    cpu->regs[0] = cpu->regs[20] + 1904ULL;
    cpu->regs[30] = PB_BASE + 0x189618ULL; PB_CALL(434, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b718;
    cpu->regs[0] = cpu->regs[20] + 2256ULL;
    cpu->regs[30] = PB_BASE + 0x189624ULL; PB_CALL(435, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b70c;
    cpu->regs[0] = cpu->regs[20] + 2688ULL;
    cpu->regs[30] = PB_BASE + 0x189630ULL; PB_CALL(436, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b700;
    cpu->regs[0] = cpu->regs[20] + 2896ULL;
    cpu->regs[30] = PB_BASE + 0x18963cULL; PB_CALL(437, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b6f4;
    cpu->regs[0] = cpu->regs[20] + 3152ULL;
    cpu->regs[30] = PB_BASE + 0x189648ULL; PB_CALL(438, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b6e8;
    cpu->regs[0] = cpu->regs[20] + 3408ULL;
    cpu->regs[30] = PB_BASE + 0x189654ULL; PB_CALL(439, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b6dc;
    cpu->regs[0] = cpu->regs[20] + 3728ULL;
    cpu->regs[30] = PB_BASE + 0x189660ULL; PB_CALL(440, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b6d0;
    cpu->regs[0] = cpu->regs[20] + 4064ULL;
    cpu->regs[30] = PB_BASE + 0x18966cULL; PB_CALL(441, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b6c4;
    cpu->regs[20] = PB_BASE + 0x476000ULL;
    cpu->regs[0] = cpu->regs[20] + 1344ULL;
    cpu->regs[0] = cpu->regs[0] + 48ULL;
    cpu->regs[30] = PB_BASE + 0x189680ULL; PB_CALL(442, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b6b8;
    cpu->regs[19] = cpu->regs[20] + 1344ULL;
    cpu->regs[0] = cpu->regs[19] + 368ULL;
    cpu->regs[30] = PB_BASE + 0x189690ULL; PB_CALL(443, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b6ac;
    cpu->regs[0] = cpu->regs[19] + 704ULL;
    cpu->regs[30] = PB_BASE + 0x18969cULL; PB_CALL(444, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b6a0;
    cpu->regs[0] = cpu->regs[19] + 928ULL;
    cpu->regs[30] = PB_BASE + 0x1896a8ULL; PB_CALL(445, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b694;
    cpu->regs[0] = cpu->regs[19] + 1168ULL;
    cpu->regs[30] = PB_BASE + 0x1896b4ULL; PB_CALL(446, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b688;
    cpu->regs[0] = cpu->regs[19] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1896c0ULL; PB_CALL(447, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b67c;
    cpu->regs[0] = cpu->regs[19] + 1696ULL;
    cpu->regs[30] = PB_BASE + 0x1896ccULL; PB_CALL(448, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b670;
    cpu->regs[0] = cpu->regs[19] + 1936ULL;
    cpu->regs[30] = PB_BASE + 0x1896d8ULL; PB_CALL(449, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b664;
    cpu->regs[0] = cpu->regs[19] + 2240ULL;
    cpu->regs[30] = PB_BASE + 0x1896e4ULL; PB_CALL(450, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b658;
    cpu->regs[0] = cpu->regs[19] + 2480ULL;
    cpu->regs[30] = PB_BASE + 0x1896f0ULL; PB_CALL(451, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b64c;
    cpu->regs[0] = cpu->regs[19] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x1896fcULL; PB_CALL(452, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b640;
    cpu->regs[0] = cpu->regs[19] + 3088ULL;
    cpu->regs[30] = PB_BASE + 0x189708ULL; PB_CALL(453, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b634;
    cpu->regs[0] = cpu->regs[19] + 3456ULL;
    cpu->regs[30] = PB_BASE + 0x189714ULL; PB_CALL(454, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b628;
    cpu->regs[0] = cpu->regs[19] + 3792ULL;
    cpu->regs[30] = PB_BASE + 0x189720ULL; PB_CALL(455, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b61c;
    cpu->regs[19] = PB_BASE + 0x477000ULL;
    cpu->regs[20] = cpu->regs[19] + 1600ULL;
    cpu->regs[0] = cpu->regs[20] - 80ULL;
    cpu->regs[30] = PB_BASE + 0x189734ULL; PB_CALL(456, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b610;
    cpu->regs[0] = cpu->regs[20] + 232ULL;
    cpu->regs[30] = PB_BASE + 0x189740ULL; PB_CALL(457, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b604;
    cpu->regs[0] = cpu->regs[20] + 440ULL;
    cpu->regs[30] = PB_BASE + 0x18974cULL; PB_CALL(458, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b5f8;
    cpu->regs[0] = cpu->regs[20] + 656ULL;
    cpu->regs[30] = PB_BASE + 0x189758ULL; PB_CALL(459, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b5ec;
    cpu->regs[0] = cpu->regs[20] + 928ULL;
    cpu->regs[30] = PB_BASE + 0x189764ULL; PB_CALL(460, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b5e0;
    cpu->regs[0] = cpu->regs[20] + 1248ULL;
    cpu->regs[30] = PB_BASE + 0x189770ULL; PB_CALL(461, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b5d4;
    cpu->regs[0] = cpu->regs[20] + 1520ULL;
    cpu->regs[30] = PB_BASE + 0x18977cULL; PB_CALL(462, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b5c8;
    cpu->regs[0] = cpu->regs[20] + 1776ULL;
    cpu->regs[30] = PB_BASE + 0x189788ULL; PB_CALL(463, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b5bc;
    cpu->regs[0] = cpu->regs[20] + 2032ULL;
    cpu->regs[30] = PB_BASE + 0x189794ULL; PB_CALL(464, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b5b0;
    cpu->regs[0] = cpu->regs[20] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x1897a0ULL; PB_CALL(465, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b5a4;
    cpu->regs[0] = cpu->regs[20] + 2736ULL;
    cpu->regs[30] = PB_BASE + 0x1897acULL; PB_CALL(466, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b598;
    cpu->regs[0] = cpu->regs[20] + 3024ULL;
    cpu->regs[30] = PB_BASE + 0x1897b8ULL; PB_CALL(467, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b58c;
    cpu->regs[0] = cpu->regs[20] + 3232ULL;
    cpu->regs[30] = PB_BASE + 0x1897c4ULL; PB_CALL(468, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b580;
    cpu->regs[0] = cpu->regs[20] + 3472ULL;
    cpu->regs[30] = PB_BASE + 0x1897d0ULL; PB_CALL(469, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b574;
    cpu->regs[0] = cpu->regs[20] + 3712ULL;
    cpu->regs[30] = PB_BASE + 0x1897dcULL; PB_CALL(470, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b568;
    cpu->regs[0] = cpu->regs[20] + 3936ULL;
    cpu->regs[30] = PB_BASE + 0x1897e8ULL; PB_CALL(471, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b55c;
    cpu->regs[19] = PB_BASE + 0x478000ULL;
    cpu->regs[0] = cpu->regs[19] + 1856ULL;
    cpu->regs[0] = cpu->regs[0] - 192ULL;
    cpu->regs[30] = PB_BASE + 0x1897fcULL; PB_CALL(472, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b550;
    cpu->regs[20] = cpu->regs[19] + 1856ULL;
    cpu->regs[0] = cpu->regs[20] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x18980cULL; PB_CALL(473, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b544;
    cpu->regs[0] = cpu->regs[20] + 384ULL;
    cpu->regs[30] = PB_BASE + 0x189818ULL; PB_CALL(474, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b538;
    cpu->regs[0] = cpu->regs[20] + 672ULL;
    cpu->regs[30] = PB_BASE + 0x189824ULL; PB_CALL(475, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b52c;
    cpu->regs[0] = cpu->regs[20] + 896ULL;
    cpu->regs[30] = PB_BASE + 0x189830ULL; PB_CALL(476, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b520;
    cpu->regs[0] = cpu->regs[20] + 1136ULL;
    cpu->regs[30] = PB_BASE + 0x18983cULL; PB_CALL(477, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b514;
    cpu->regs[0] = cpu->regs[20] + 1376ULL;
    cpu->regs[30] = PB_BASE + 0x189848ULL; PB_CALL(478, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b508;
    cpu->regs[0] = cpu->regs[20] + 1632ULL;
    cpu->regs[30] = PB_BASE + 0x189854ULL; PB_CALL(479, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b4fc;
    cpu->regs[0] = cpu->regs[20] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x189860ULL; PB_CALL(480, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b4f0;
    cpu->regs[0] = cpu->regs[20] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x18986cULL; PB_CALL(481, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b4e4;
    cpu->regs[0] = cpu->regs[20] + 2336ULL;
    cpu->regs[30] = PB_BASE + 0x189878ULL; PB_CALL(482, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b4d8;
    cpu->regs[0] = cpu->regs[20] + 2576ULL;
    cpu->regs[30] = PB_BASE + 0x189884ULL; PB_CALL(483, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b4cc;
    cpu->regs[0] = cpu->regs[20] + 2800ULL;
    cpu->regs[30] = PB_BASE + 0x189890ULL; PB_CALL(484, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b4c0;
    cpu->regs[0] = cpu->regs[20] + 3088ULL;
    cpu->regs[30] = PB_BASE + 0x18989cULL; PB_CALL(485, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b4b4;
    cpu->regs[0] = cpu->regs[20] + 3376ULL;
    cpu->regs[30] = PB_BASE + 0x1898a8ULL; PB_CALL(486, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b4a8;
    cpu->regs[0] = cpu->regs[20] + 3616ULL;
    cpu->regs[30] = PB_BASE + 0x1898b4ULL; PB_CALL(487, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b49c;
    cpu->regs[0] = cpu->regs[20] + 3904ULL;
    cpu->regs[30] = PB_BASE + 0x1898c0ULL; PB_CALL(488, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b490;
    cpu->regs[20] = PB_BASE + 0x479000ULL;
    cpu->regs[19] = cpu->regs[20] + 2112ULL;
    cpu->regs[0] = cpu->regs[19] - 176ULL;
    cpu->regs[30] = PB_BASE + 0x1898d4ULL; PB_CALL(489, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b484;
    cpu->regs[0] = cpu->regs[19] + 48ULL;
    cpu->regs[30] = PB_BASE + 0x1898e0ULL; PB_CALL(490, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b478;
    cpu->regs[0] = cpu->regs[19] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x1898ecULL; PB_CALL(491, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b46c;
    cpu->regs[0] = cpu->regs[19] + 464ULL;
    cpu->regs[30] = PB_BASE + 0x1898f8ULL; PB_CALL(492, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b460;
    cpu->regs[0] = cpu->regs[19] + 752ULL;
    cpu->regs[30] = PB_BASE + 0x189904ULL; PB_CALL(493, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b454;
    cpu->regs[0] = cpu->regs[19] + 1056ULL;
    cpu->regs[30] = PB_BASE + 0x189910ULL; PB_CALL(494, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b448;
    cpu->regs[0] = cpu->regs[19] + 1328ULL;
    cpu->regs[30] = PB_BASE + 0x18991cULL; PB_CALL(495, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b43c;
    cpu->regs[0] = cpu->regs[19] + 1760ULL;
    cpu->regs[30] = PB_BASE + 0x189928ULL; PB_CALL(496, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b430;
    cpu->regs[0] = cpu->regs[19] + 2016ULL;
    cpu->regs[30] = PB_BASE + 0x189934ULL; PB_CALL(497, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b424;
    cpu->regs[0] = cpu->regs[19] + 2312ULL;
    cpu->regs[30] = PB_BASE + 0x189940ULL; PB_CALL(498, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b418;
    cpu->regs[0] = cpu->regs[19] + 2528ULL;
    cpu->regs[30] = PB_BASE + 0x18994cULL; PB_CALL(499, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b40c;
    cpu->regs[0] = cpu->regs[19] + 2800ULL;
    cpu->regs[30] = PB_BASE + 0x189958ULL; PB_CALL(500, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b400;
    cpu->regs[0] = cpu->regs[19] + 3040ULL;
    cpu->regs[30] = PB_BASE + 0x189964ULL; PB_CALL(501, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b3f4;
    cpu->regs[0] = cpu->regs[19] + 3328ULL;
    cpu->regs[30] = PB_BASE + 0x189970ULL; PB_CALL(502, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b3e8;
    cpu->regs[0] = cpu->regs[19] + 3760ULL;
    cpu->regs[30] = PB_BASE + 0x18997cULL; PB_CALL(503, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b3dc;
    cpu->regs[0] = cpu->regs[19] + 4016ULL;
    cpu->regs[30] = PB_BASE + 0x189988ULL; PB_CALL(504, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b3d0;
    cpu->regs[19] = PB_BASE + 0x47a000ULL;
    cpu->regs[20] = cpu->regs[19] + 2368ULL;
    cpu->regs[0] = cpu->regs[20] - 96ULL;
    cpu->regs[30] = PB_BASE + 0x18999cULL; PB_CALL(505, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b3c4;
    cpu->regs[0] = cpu->regs[20] + 176ULL;
    cpu->regs[30] = PB_BASE + 0x1899a8ULL; PB_CALL(506, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b3b8;
    cpu->regs[0] = cpu->regs[20] + 480ULL;
    cpu->regs[30] = PB_BASE + 0x1899b4ULL; PB_CALL(507, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b3ac;
    cpu->regs[0] = cpu->regs[20] + 752ULL;
    cpu->regs[30] = PB_BASE + 0x1899c0ULL; PB_CALL(508, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b3a0;
    cpu->regs[0] = cpu->regs[20] + 992ULL;
    cpu->regs[30] = PB_BASE + 0x1899ccULL; PB_CALL(509, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b394;
    cpu->regs[0] = cpu->regs[20] + 1208ULL;
    cpu->regs[30] = PB_BASE + 0x1899d8ULL; PB_CALL(510, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b388;
    cpu->regs[0] = cpu->regs[20] + 1416ULL;
    cpu->regs[30] = PB_BASE + 0x1899e4ULL; PB_CALL(511, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b37c;
    cpu->regs[0] = cpu->regs[20] + 1624ULL;
    cpu->regs[30] = PB_BASE + 0x1899f0ULL; PB_CALL(512, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b370;
    cpu->regs[0] = cpu->regs[20] + 1840ULL;
    cpu->regs[30] = PB_BASE + 0x1899fcULL; PB_CALL(513, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b364;
    cpu->regs[0] = cpu->regs[20] + 2096ULL;
    cpu->regs[30] = PB_BASE + 0x189a08ULL; PB_CALL(514, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b358;
    cpu->regs[0] = cpu->regs[20] + 2368ULL;
    cpu->regs[30] = PB_BASE + 0x189a14ULL; PB_CALL(515, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b34c;
    cpu->regs[0] = cpu->regs[20] + 2688ULL;
    cpu->regs[30] = PB_BASE + 0x189a20ULL; PB_CALL(516, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b340;
    cpu->regs[0] = cpu->regs[20] + 2976ULL;
    cpu->regs[30] = PB_BASE + 0x189a2cULL; PB_CALL(517, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b334;
    cpu->regs[0] = cpu->regs[20] + 3200ULL;
    cpu->regs[30] = PB_BASE + 0x189a38ULL; PB_CALL(518, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b328;
    cpu->regs[0] = cpu->regs[20] + 3440ULL;
    cpu->regs[30] = PB_BASE + 0x189a44ULL; PB_CALL(519, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b31c;
    cpu->regs[0] = cpu->regs[20] + 3680ULL;
    cpu->regs[30] = PB_BASE + 0x189a50ULL; PB_CALL(520, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b310;
    cpu->regs[0] = cpu->regs[20] + 3984ULL;
    cpu->regs[30] = PB_BASE + 0x189a5cULL; PB_CALL(521, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b304;
    cpu->regs[19] = PB_BASE + 0x47b000ULL;
    cpu->regs[0] = cpu->regs[19] + 2624ULL;
    cpu->regs[0] = cpu->regs[0] + 2480ULL;
    cpu->regs[30] = PB_BASE + 0x189a70ULL; PB_CALL(522, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b2f8;
    cpu->regs[19] = cpu->regs[19] + 2624ULL;
    cpu->regs[0] = cpu->regs[19] + 2704ULL;
    cpu->regs[30] = PB_BASE + 0x189a80ULL; PB_CALL(523, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b2ec;
    cpu->regs[0] = cpu->regs[19] + 2960ULL;
    cpu->regs[30] = PB_BASE + 0x189a8cULL; PB_CALL(524, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b2e0;
    cpu->regs[0] = cpu->regs[19] + 3280ULL;
    cpu->regs[30] = PB_BASE + 0x189a98ULL; PB_CALL(525, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b2d4;
    cpu->regs[0] = cpu->regs[19] + 3504ULL;
    cpu->regs[30] = PB_BASE + 0x189aa4ULL; PB_CALL(526, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b2c8;
    cpu->regs[0] = cpu->regs[19] + 3888ULL;
    cpu->regs[30] = PB_BASE + 0x189ab0ULL; PB_CALL(527, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b2bc;
    cpu->regs[19] = PB_BASE + 0x47c000ULL;
    cpu->regs[20] = cpu->regs[19] + 2880ULL;
    cpu->regs[0] = cpu->regs[20] + 64ULL;
    cpu->regs[30] = PB_BASE + 0x189ac4ULL; PB_CALL(528, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b2b0;
    cpu->regs[0] = cpu->regs[20] + 464ULL;
    cpu->regs[30] = PB_BASE + 0x189ad0ULL; PB_CALL(529, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b2a4;
    cpu->regs[0] = cpu->regs[20] + 944ULL;
    cpu->regs[30] = PB_BASE + 0x189adcULL; PB_CALL(530, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b298;
    cpu->regs[0] = cpu->regs[20] + 1184ULL;
    cpu->regs[30] = PB_BASE + 0x189ae8ULL; PB_CALL(531, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b28c;
    cpu->regs[0] = cpu->regs[20] + 1392ULL;
    cpu->regs[30] = PB_BASE + 0x189af4ULL; PB_CALL(532, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b280;
    cpu->regs[0] = cpu->regs[20] + 1632ULL;
    cpu->regs[30] = PB_BASE + 0x189b00ULL; PB_CALL(533, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b274;
    cpu->regs[0] = cpu->regs[20] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x189b0cULL; PB_CALL(534, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b268;
    cpu->regs[0] = cpu->regs[20] + 2144ULL;
    cpu->regs[30] = PB_BASE + 0x189b18ULL; PB_CALL(535, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b25c;
    cpu->regs[0] = cpu->regs[20] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x189b24ULL; PB_CALL(536, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b250;
    cpu->regs[0] = cpu->regs[20] + 2784ULL;
    cpu->regs[30] = PB_BASE + 0x189b30ULL; PB_CALL(537, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b244;
    cpu->regs[0] = cpu->regs[20] + 3136ULL;
    cpu->regs[30] = PB_BASE + 0x189b3cULL; PB_CALL(538, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b238;
    cpu->regs[0] = cpu->regs[20] + 3488ULL;
    cpu->regs[30] = PB_BASE + 0x189b48ULL; PB_CALL(539, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b22c;
    cpu->regs[0] = cpu->regs[20] + 3744ULL;
    cpu->regs[30] = PB_BASE + 0x189b54ULL; PB_CALL(540, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b220;
    cpu->regs[0] = cpu->regs[20] + 4000ULL;
    cpu->regs[30] = PB_BASE + 0x189b60ULL; PB_CALL(541, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b214;
    cpu->regs[20] = PB_BASE + 0x47d000ULL;
    cpu->regs[0] = cpu->regs[20] + 3136ULL;
    cpu->regs[0] = cpu->regs[0] - 96ULL;
    cpu->regs[30] = PB_BASE + 0x189b74ULL; PB_CALL(542, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b208;
    cpu->regs[19] = cpu->regs[20] + 3136ULL;
    cpu->regs[0] = cpu->regs[19] + 160ULL;
    cpu->regs[30] = PB_BASE + 0x189b84ULL; PB_CALL(543, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b1fc;
    cpu->regs[0] = cpu->regs[19] + 608ULL;
    cpu->regs[30] = PB_BASE + 0x189b90ULL; PB_CALL(544, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b1f0;
    cpu->regs[0] = cpu->regs[19] + 912ULL;
    cpu->regs[30] = PB_BASE + 0x189b9cULL; PB_CALL(545, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b1e4;
    cpu->regs[0] = cpu->regs[19] + 1216ULL;
    cpu->regs[30] = PB_BASE + 0x189ba8ULL; PB_CALL(546, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b1d8;
    cpu->regs[0] = cpu->regs[19] + 1520ULL;
    cpu->regs[30] = PB_BASE + 0x189bb4ULL; PB_CALL(547, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b1cc;
    cpu->regs[0] = cpu->regs[19] + 1952ULL;
    cpu->regs[30] = PB_BASE + 0x189bc0ULL; PB_CALL(548, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b1c0;
    cpu->regs[0] = cpu->regs[19] + 2352ULL;
    cpu->regs[30] = PB_BASE + 0x189bccULL; PB_CALL(549, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b1b4;
    cpu->regs[0] = cpu->regs[19] + 2560ULL;
    cpu->regs[30] = PB_BASE + 0x189bd8ULL; PB_CALL(550, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b1a8;
    cpu->regs[0] = cpu->regs[19] + 2800ULL;
    cpu->regs[30] = PB_BASE + 0x189be4ULL; PB_CALL(551, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b19c;
    cpu->regs[0] = cpu->regs[19] + 3024ULL;
    cpu->regs[30] = PB_BASE + 0x189bf0ULL; PB_CALL(552, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b190;
    cpu->regs[0] = cpu->regs[19] + 3392ULL;
    cpu->regs[30] = PB_BASE + 0x189bfcULL; PB_CALL(553, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b184;
    cpu->regs[0] = cpu->regs[19] + 3632ULL;
    cpu->regs[30] = PB_BASE + 0x189c08ULL; PB_CALL(554, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b178;
    cpu->regs[20] = PB_BASE + 0x47e000ULL;
    cpu->regs[19] = cpu->regs[20] + 3392ULL;
    cpu->regs[0] = cpu->regs[19] - 176ULL;
    cpu->regs[30] = PB_BASE + 0x189c1cULL; PB_CALL(555, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b16c;
    cpu->regs[0] = cpu->regs[19] + 304ULL;
    cpu->regs[30] = PB_BASE + 0x189c28ULL; PB_CALL(556, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b160;
    cpu->regs[0] = cpu->regs[19] + 720ULL;
    cpu->regs[30] = PB_BASE + 0x189c34ULL; PB_CALL(557, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b154;
    cpu->regs[0] = cpu->regs[19] + 1488ULL;
    cpu->regs[30] = PB_BASE + 0x189c40ULL; PB_CALL(558, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b148;
    cpu->regs[0] = cpu->regs[19] + 1728ULL;
    cpu->regs[30] = PB_BASE + 0x189c4cULL; PB_CALL(559, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b13c;
    cpu->regs[0] = cpu->regs[19] + 2432ULL;
    cpu->regs[30] = PB_BASE + 0x189c58ULL; PB_CALL(560, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b130;
    cpu->regs[0] = cpu->regs[19] + 2880ULL;
    cpu->regs[30] = PB_BASE + 0x189c64ULL; PB_CALL(561, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b124;
    cpu->regs[0] = cpu->regs[19] + 3248ULL;
    cpu->regs[30] = PB_BASE + 0x189c70ULL; PB_CALL(562, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b118;
    cpu->regs[0] = cpu->regs[19] + 3472ULL;
    cpu->regs[30] = PB_BASE + 0x189c7cULL; PB_CALL(563, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b10c;
    cpu->regs[0] = cpu->regs[19] + 3696ULL;
    cpu->regs[30] = PB_BASE + 0x189c88ULL; PB_CALL(564, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b100;
    cpu->regs[0] = cpu->regs[19] + 4064ULL;
    cpu->regs[30] = PB_BASE + 0x189c94ULL; PB_CALL(565, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b0f4;
    cpu->regs[19] = PB_BASE + 0x47f000ULL;
    cpu->regs[19] = cpu->regs[19] + 3648ULL;
    cpu->regs[0] = cpu->regs[19] - 48ULL;
    cpu->regs[30] = PB_BASE + 0x189ca8ULL; PB_CALL(566, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b0e8;
    cpu->regs[0] = cpu->regs[19] + 240ULL;
    cpu->regs[30] = PB_BASE + 0x189cb4ULL; PB_CALL(567, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b0dc;
    cpu->regs[0] = cpu->regs[19] + 752ULL;
    cpu->regs[30] = PB_BASE + 0x189cc0ULL; PB_CALL(568, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b0d0;
    cpu->regs[0] = cpu->regs[19] + 1776ULL;
    cpu->regs[30] = PB_BASE + 0x189cccULL; PB_CALL(569, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b0c4;
    cpu->regs[0] = cpu->regs[19] + 3744ULL;
    cpu->regs[30] = PB_BASE + 0x189cd8ULL; PB_CALL(570, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b0b8;
    cpu->regs[19] = PB_BASE + 0x480000ULL;
    cpu->regs[20] = cpu->regs[19] + 3904ULL;
    cpu->regs[0] = cpu->regs[20] + 112ULL;
    cpu->regs[30] = PB_BASE + 0x189cecULL; PB_CALL(571, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b0ac;
    cpu->regs[0] = cpu->regs[20] + 816ULL;
    cpu->regs[30] = PB_BASE + 0x189cf8ULL; PB_CALL(572, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b0a0;
    cpu->regs[0] = cpu->regs[20] + 1248ULL;
    cpu->regs[30] = PB_BASE + 0x189d04ULL; PB_CALL(573, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b094;
    cpu->regs[0] = cpu->regs[20] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x189d10ULL; PB_CALL(574, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b088;
    cpu->regs[0] = cpu->regs[20] + 2352ULL;
    cpu->regs[30] = PB_BASE + 0x189d1cULL; PB_CALL(575, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b07c;
    cpu->regs[0] = cpu->regs[20] + 3504ULL;
    cpu->regs[30] = PB_BASE + 0x189d28ULL; PB_CALL(576, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b070;
    cpu->regs[0] = cpu->regs[20] + 3728ULL;
    cpu->regs[30] = PB_BASE + 0x189d34ULL; PB_CALL(577, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b064;
    cpu->regs[19] = PB_BASE + 0x482000ULL;
    cpu->regs[20] = cpu->regs[19] + 64ULL;
    cpu->regs[0] = cpu->regs[20] + 416ULL;
    cpu->regs[30] = PB_BASE + 0x189d48ULL; PB_CALL(578, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b058;
    cpu->regs[0] = cpu->regs[20] + 1728ULL;
    cpu->regs[30] = PB_BASE + 0x189d54ULL; PB_CALL(579, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b04c;
    cpu->regs[0] = cpu->regs[20] + 2000ULL;
    cpu->regs[30] = PB_BASE + 0x189d60ULL; PB_CALL(580, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b040;
    cpu->regs[0] = cpu->regs[20] + 2208ULL;
    cpu->regs[30] = PB_BASE + 0x189d6cULL; PB_CALL(581, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b034;
    cpu->regs[0] = cpu->regs[20] + 3088ULL;
    cpu->regs[30] = PB_BASE + 0x189d78ULL; PB_CALL(582, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b028;
    cpu->regs[0] = cpu->regs[20] + 3328ULL;
    cpu->regs[30] = PB_BASE + 0x189d84ULL; PB_CALL(583, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b01c;
    cpu->regs[0] = cpu->regs[20] + 3568ULL;
    cpu->regs[30] = PB_BASE + 0x189d90ULL; PB_CALL(584, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b010;
    cpu->regs[0] = cpu->regs[20] + 3872ULL;
    cpu->regs[30] = PB_BASE + 0x189d9cULL; PB_CALL(585, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18b004;
    cpu->regs[20] = PB_BASE + 0x483000ULL;
    cpu->regs[19] = cpu->regs[20] + 320ULL;
    cpu->regs[0] = cpu->regs[19] + 80ULL;
    cpu->regs[30] = PB_BASE + 0x189db0ULL; PB_CALL(586, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aff8;
    cpu->regs[0] = cpu->regs[19] + 480ULL;
    cpu->regs[30] = PB_BASE + 0x189dbcULL; PB_CALL(587, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18afec;
    cpu->regs[0] = cpu->regs[19] + 816ULL;
    cpu->regs[30] = PB_BASE + 0x189dc8ULL; PB_CALL(588, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18afe0;
    cpu->regs[0] = cpu->regs[19] + 1072ULL;
    cpu->regs[30] = PB_BASE + 0x189dd4ULL; PB_CALL(589, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18afd4;
    cpu->regs[0] = cpu->regs[19] + 1456ULL;
    cpu->regs[30] = PB_BASE + 0x189de0ULL; PB_CALL(590, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18afc8;
    cpu->regs[0] = cpu->regs[19] + 1776ULL;
    cpu->regs[30] = PB_BASE + 0x189decULL; PB_CALL(591, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18afbc;
    cpu->regs[0] = cpu->regs[19] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x189df8ULL; PB_CALL(592, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18afb0;
    cpu->regs[0] = cpu->regs[19] + 2400ULL;
    cpu->regs[30] = PB_BASE + 0x189e04ULL; PB_CALL(593, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18afa4;
    cpu->regs[0] = cpu->regs[19] + 2688ULL;
    cpu->regs[30] = PB_BASE + 0x189e10ULL; PB_CALL(594, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af98;
    cpu->regs[0] = cpu->regs[19] + 3392ULL;
    cpu->regs[30] = PB_BASE + 0x189e1cULL; PB_CALL(595, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af8c;
    cpu->regs[19] = PB_BASE + 0x484000ULL;
    cpu->regs[19] = cpu->regs[19] + 576ULL;
    cpu->regs[0] = cpu->regs[19] + 128ULL;
    cpu->regs[30] = PB_BASE + 0x189e30ULL; PB_CALL(596, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af80;
    cpu->regs[0] = cpu->regs[19] + 1136ULL;
    cpu->regs[30] = PB_BASE + 0x189e3cULL; PB_CALL(597, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af74;
    cpu->regs[0] = cpu->regs[19] + 1728ULL;
    cpu->regs[30] = PB_BASE + 0x189e48ULL; PB_CALL(598, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af68;
    cpu->regs[0] = cpu->regs[19] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x189e54ULL; PB_CALL(599, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af5c;
    cpu->regs[0] = cpu->regs[19] + 2464ULL;
    cpu->regs[30] = PB_BASE + 0x189e60ULL; PB_CALL(600, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af50;
    cpu->regs[0] = cpu->regs[19] + 3408ULL;
    cpu->regs[30] = PB_BASE + 0x189e6cULL; PB_CALL(601, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af44;
    cpu->regs[19] = PB_BASE + 0x485000ULL;
    cpu->regs[0] = cpu->regs[19] + 832ULL;
    cpu->regs[0] = cpu->regs[0] - 160ULL;
    cpu->regs[30] = PB_BASE + 0x189e80ULL; PB_CALL(602, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af38;
    cpu->regs[19] = cpu->regs[19] + 832ULL;
    cpu->regs[0] = cpu->regs[19] + 80ULL;
    cpu->regs[30] = PB_BASE + 0x189e90ULL; PB_CALL(603, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af2c;
    cpu->regs[0] = cpu->regs[19] + 960ULL;
    cpu->regs[30] = PB_BASE + 0x189e9cULL; PB_CALL(604, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af20;
    cpu->regs[0] = cpu->regs[19] + 1504ULL;
    cpu->regs[30] = PB_BASE + 0x189ea8ULL; PB_CALL(605, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af14;
    cpu->regs[0] = cpu->regs[19] + 1728ULL;
    cpu->regs[30] = PB_BASE + 0x189eb4ULL; PB_CALL(606, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18af08;
    cpu->regs[0] = cpu->regs[19] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x189ec0ULL; PB_CALL(607, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aefc;
    cpu->regs[0] = cpu->regs[19] + 2368ULL;
    cpu->regs[30] = PB_BASE + 0x189eccULL; PB_CALL(608, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aef0;
    cpu->regs[0] = cpu->regs[19] + 2976ULL;
    cpu->regs[30] = PB_BASE + 0x189ed8ULL; PB_CALL(609, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aee4;
    cpu->regs[0] = cpu->regs[19] + 3424ULL;
    cpu->regs[30] = PB_BASE + 0x189ee4ULL; PB_CALL(610, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aed8;
    cpu->regs[0] = cpu->regs[19] + 3888ULL;
    cpu->regs[30] = PB_BASE + 0x189ef0ULL; PB_CALL(611, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aecc;
    cpu->regs[19] = PB_BASE + 0x486000ULL;
    cpu->regs[0] = cpu->regs[19] + 1088ULL;
    cpu->regs[0] = cpu->regs[0] + 928ULL;
    cpu->regs[30] = PB_BASE + 0x189f04ULL; PB_CALL(612, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aec0;
    cpu->regs[19] = cpu->regs[19] + 1088ULL;
    cpu->regs[0] = cpu->regs[19] + 1520ULL;
    cpu->regs[30] = PB_BASE + 0x189f14ULL; PB_CALL(613, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aeb4;
    cpu->regs[20] = cpu->regs[19] + 2048ULL;
    cpu->regs[0] = cpu->regs[19] + 1776ULL;
    cpu->regs[30] = PB_BASE + 0x189f24ULL; PB_CALL(614, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aea8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x189f30ULL; PB_CALL(615, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae9c;
    cpu->regs[0] = cpu->regs[19] + 3472ULL;
    cpu->regs[30] = PB_BASE + 0x189f3cULL; PB_CALL(616, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae90;
    cpu->regs[0] = cpu->regs[19] + 3696ULL;
    cpu->regs[30] = PB_BASE + 0x189f48ULL; PB_CALL(617, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae84;
    cpu->regs[0] = cpu->regs[19] + 3936ULL;
    cpu->regs[30] = PB_BASE + 0x189f54ULL; PB_CALL(618, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae78;
    cpu->regs[19] = PB_BASE + 0x487000ULL;
    cpu->regs[20] = cpu->regs[19] + 1344ULL;
    cpu->regs[0] = cpu->regs[20] - 192ULL;
    cpu->regs[30] = PB_BASE + 0x189f68ULL; PB_CALL(619, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae6c;
    cpu->regs[0] = cpu->regs[20] + 48ULL;
    cpu->regs[30] = PB_BASE + 0x189f74ULL; PB_CALL(620, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae60;
    cpu->regs[0] = cpu->regs[20] + 272ULL;
    cpu->regs[30] = PB_BASE + 0x189f80ULL; PB_CALL(621, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae54;
    cpu->regs[0] = cpu->regs[20] + 496ULL;
    cpu->regs[30] = PB_BASE + 0x189f8cULL; PB_CALL(622, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae48;
    cpu->regs[0] = cpu->regs[20] + 1104ULL;
    cpu->regs[30] = PB_BASE + 0x189f98ULL; PB_CALL(623, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae3c;
    cpu->regs[0] = cpu->regs[20] + 1728ULL;
    cpu->regs[30] = PB_BASE + 0x189fa4ULL; PB_CALL(624, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae30;
    cpu->regs[0] = cpu->regs[20] + 2000ULL;
    cpu->regs[30] = PB_BASE + 0x189fb0ULL; PB_CALL(625, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae24;
    cpu->regs[0] = cpu->regs[20] + 2352ULL;
    cpu->regs[30] = PB_BASE + 0x189fbcULL; PB_CALL(626, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae18;
    cpu->regs[0] = cpu->regs[20] + 2672ULL;
    cpu->regs[30] = PB_BASE + 0x189fc8ULL; PB_CALL(627, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae0c;
    cpu->regs[0] = cpu->regs[20] + 3008ULL;
    cpu->regs[30] = PB_BASE + 0x189fd4ULL; PB_CALL(628, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ae00;
    cpu->regs[0] = cpu->regs[20] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x189fe0ULL; PB_CALL(629, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18adf4;
    cpu->regs[0] = cpu->regs[20] + 3552ULL;
    cpu->regs[30] = PB_BASE + 0x189fecULL; PB_CALL(630, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ade8;
    cpu->regs[0] = cpu->regs[20] + 3856ULL;
    cpu->regs[30] = PB_BASE + 0x189ff8ULL; PB_CALL(631, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18addc;
    cpu->regs[20] = PB_BASE + 0x488000ULL;
    cpu->regs[0] = cpu->regs[20] + 1600ULL;
    cpu->regs[0] = cpu->regs[0] - 176ULL;
    cpu->regs[30] = PB_BASE + 0x18a00cULL; PB_CALL(632, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18add0;
    cpu->regs[19] = cpu->regs[20] + 1600ULL;
    cpu->regs[0] = cpu->regs[19] + 48ULL;
    cpu->regs[30] = PB_BASE + 0x18a01cULL; PB_CALL(633, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18adc4;
    cpu->regs[0] = cpu->regs[19] + 272ULL;
    cpu->regs[30] = PB_BASE + 0x18a028ULL; PB_CALL(634, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18adb8;
    cpu->regs[0] = cpu->regs[19] + 512ULL;
    cpu->regs[30] = PB_BASE + 0x18a034ULL; PB_CALL(635, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18adac;
    cpu->regs[0] = cpu->regs[19] + 816ULL;
    cpu->regs[30] = PB_BASE + 0x18a040ULL; PB_CALL(636, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ada0;
    cpu->regs[0] = cpu->regs[19] + 1120ULL;
    cpu->regs[30] = PB_BASE + 0x18a04cULL; PB_CALL(637, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad94;
    cpu->regs[0] = cpu->regs[19] + 1408ULL;
    cpu->regs[30] = PB_BASE + 0x18a058ULL; PB_CALL(638, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad88;
    cpu->regs[0] = cpu->regs[19] + 1712ULL;
    cpu->regs[30] = PB_BASE + 0x18a064ULL; PB_CALL(639, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad7c;
    cpu->regs[0] = cpu->regs[19] + 1952ULL;
    cpu->regs[30] = PB_BASE + 0x18a070ULL; PB_CALL(640, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad70;
    cpu->regs[0] = cpu->regs[19] + 2288ULL;
    cpu->regs[30] = PB_BASE + 0x18a07cULL; PB_CALL(641, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad64;
    cpu->regs[0] = cpu->regs[19] + 2528ULL;
    cpu->regs[30] = PB_BASE + 0x18a088ULL; PB_CALL(642, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad58;
    cpu->regs[0] = cpu->regs[19] + 2976ULL;
    cpu->regs[30] = PB_BASE + 0x18a094ULL; PB_CALL(643, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad4c;
    cpu->regs[0] = cpu->regs[19] + 3216ULL;
    cpu->regs[30] = PB_BASE + 0x18a0a0ULL; PB_CALL(644, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad40;
    cpu->regs[0] = cpu->regs[19] + 3520ULL;
    cpu->regs[30] = PB_BASE + 0x18a0acULL; PB_CALL(645, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad34;
    cpu->regs[0] = cpu->regs[19] + 3760ULL;
    cpu->regs[30] = PB_BASE + 0x18a0b8ULL; PB_CALL(646, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad28;
    cpu->regs[0] = cpu->regs[19] + 4064ULL;
    cpu->regs[30] = PB_BASE + 0x18a0c4ULL; PB_CALL(647, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad1c;
    cpu->regs[19] = PB_BASE + 0x489000ULL;
    cpu->regs[20] = cpu->regs[19] + 1856ULL;
    cpu->regs[0] = cpu->regs[20] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x18a0d8ULL; PB_CALL(648, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad10;
    cpu->regs[0] = cpu->regs[20] + 336ULL;
    cpu->regs[30] = PB_BASE + 0x18a0e4ULL; PB_CALL(649, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ad04;
    cpu->regs[0] = cpu->regs[20] + 848ULL;
    cpu->regs[30] = PB_BASE + 0x18a0f0ULL; PB_CALL(650, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18acf8;
    cpu->regs[0] = cpu->regs[20] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x18a0fcULL; PB_CALL(651, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18acec;
    cpu->regs[0] = cpu->regs[20] + 1328ULL;
    cpu->regs[30] = PB_BASE + 0x18a108ULL; PB_CALL(652, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ace0;
    cpu->regs[0] = cpu->regs[20] + 1568ULL;
    cpu->regs[30] = PB_BASE + 0x18a114ULL; PB_CALL(653, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18acd4;
    cpu->regs[0] = cpu->regs[20] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x18a120ULL; PB_CALL(654, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18acc8;
    cpu->regs[0] = cpu->regs[20] + 2032ULL;
    cpu->regs[30] = PB_BASE + 0x18a12cULL; PB_CALL(655, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18acbc;
    cpu->regs[0] = cpu->regs[20] + 2272ULL;
    cpu->regs[30] = PB_BASE + 0x18a138ULL; PB_CALL(656, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18acb0;
    cpu->regs[0] = cpu->regs[20] + 2496ULL;
    cpu->regs[30] = PB_BASE + 0x18a144ULL; PB_CALL(657, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aca4;
    cpu->regs[0] = cpu->regs[20] + 2736ULL;
    cpu->regs[30] = PB_BASE + 0x18a150ULL; PB_CALL(658, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac98;
    cpu->regs[0] = cpu->regs[20] + 3328ULL;
    cpu->regs[30] = PB_BASE + 0x18a15cULL; PB_CALL(659, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac8c;
    cpu->regs[0] = cpu->regs[20] + 3552ULL;
    cpu->regs[30] = PB_BASE + 0x18a168ULL; PB_CALL(660, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac80;
    cpu->regs[0] = cpu->regs[20] + 3896ULL;
    cpu->regs[30] = PB_BASE + 0x18a174ULL; PB_CALL(661, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac74;
    cpu->regs[20] = PB_BASE + 0x48a000ULL;
    cpu->regs[0] = cpu->regs[20] + 2112ULL;
    cpu->regs[0] = cpu->regs[0] - 256ULL;
    cpu->regs[30] = PB_BASE + 0x18a188ULL; PB_CALL(662, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac68;
    cpu->regs[19] = cpu->regs[20] + 2112ULL;
    cpu->regs[0] = cpu->regs[19] - 16ULL;
    cpu->regs[30] = PB_BASE + 0x18a198ULL; PB_CALL(663, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac5c;
    cpu->regs[0] = cpu->regs[19] + 224ULL;
    cpu->regs[30] = PB_BASE + 0x18a1a4ULL; PB_CALL(664, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac50;
    cpu->regs[0] = cpu->regs[19] + 464ULL;
    cpu->regs[30] = PB_BASE + 0x18a1b0ULL; PB_CALL(665, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac44;
    cpu->regs[0] = cpu->regs[19] + 704ULL;
    cpu->regs[30] = PB_BASE + 0x18a1bcULL; PB_CALL(666, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac38;
    cpu->regs[0] = cpu->regs[19] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x18a1c8ULL; PB_CALL(667, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac2c;
    cpu->regs[0] = cpu->regs[19] + 1648ULL;
    cpu->regs[30] = PB_BASE + 0x18a1d4ULL; PB_CALL(668, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac20;
    cpu->regs[0] = cpu->regs[19] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x18a1e0ULL; PB_CALL(669, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac14;
    cpu->regs[0] = cpu->regs[19] + 2112ULL;
    cpu->regs[30] = PB_BASE + 0x18a1ecULL; PB_CALL(670, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ac08;
    cpu->regs[0] = cpu->regs[19] + 2400ULL;
    cpu->regs[30] = PB_BASE + 0x18a1f8ULL; PB_CALL(671, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18abfc;
    cpu->regs[0] = cpu->regs[19] + 2640ULL;
    cpu->regs[30] = PB_BASE + 0x18a204ULL; PB_CALL(672, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18abf0;
    cpu->regs[0] = cpu->regs[19] + 2904ULL;
    cpu->regs[30] = PB_BASE + 0x18a210ULL; PB_CALL(673, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18abe4;
    cpu->regs[0] = cpu->regs[19] + 3104ULL;
    cpu->regs[30] = PB_BASE + 0x18a21cULL; PB_CALL(674, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18abd8;
    cpu->regs[0] = cpu->regs[19] + 3344ULL;
    cpu->regs[30] = PB_BASE + 0x18a228ULL; PB_CALL(675, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18abcc;
    cpu->regs[0] = cpu->regs[19] + 3632ULL;
    cpu->regs[30] = PB_BASE + 0x18a234ULL; PB_CALL(676, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18abc0;
    cpu->regs[0] = cpu->regs[19] + 3872ULL;
    cpu->regs[30] = PB_BASE + 0x18a240ULL; PB_CALL(677, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18abb4;
    cpu->regs[19] = PB_BASE + 0x48b000ULL;
    cpu->regs[19] = cpu->regs[19] + 2368ULL;
    cpu->regs[0] = cpu->regs[19] - 192ULL;
    cpu->regs[30] = PB_BASE + 0x18a254ULL; PB_CALL(678, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aba8;
    cpu->regs[0] = cpu->regs[19] + 2592ULL;
    cpu->regs[30] = PB_BASE + 0x18a260ULL; PB_CALL(679, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab9c;
    cpu->regs[0] = cpu->regs[19] + 2896ULL;
    cpu->regs[30] = PB_BASE + 0x18a26cULL; PB_CALL(680, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab90;
    cpu->regs[0] = cpu->regs[19] + 3312ULL;
    cpu->regs[30] = PB_BASE + 0x18a278ULL; PB_CALL(681, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab84;
    cpu->regs[0] = cpu->regs[19] + 4080ULL;
    cpu->regs[30] = PB_BASE + 0x18a284ULL; PB_CALL(682, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab78;
    cpu->regs[19] = PB_BASE + 0x48c000ULL;
    cpu->regs[19] = cpu->regs[19] + 2624ULL;
    cpu->regs[0] = cpu->regs[19] + 144ULL;
    cpu->regs[30] = PB_BASE + 0x18a298ULL; PB_CALL(683, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab6c;
    cpu->regs[0] = cpu->regs[19] + 560ULL;
    cpu->regs[30] = PB_BASE + 0x18a2a4ULL; PB_CALL(684, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab60;
    cpu->regs[0] = cpu->regs[19] + 2224ULL;
    cpu->regs[30] = PB_BASE + 0x18a2b0ULL; PB_CALL(685, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab54;
    cpu->regs[0] = cpu->regs[19] + 2864ULL;
    cpu->regs[30] = PB_BASE + 0x18a2bcULL; PB_CALL(686, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab48;
    cpu->regs[0] = cpu->regs[19] + 3424ULL;
    cpu->regs[30] = PB_BASE + 0x18a2c8ULL; PB_CALL(687, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab3c;
    cpu->regs[0] = cpu->regs[19] + 3744ULL;
    cpu->regs[30] = PB_BASE + 0x18a2d4ULL; PB_CALL(688, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab30;
    cpu->regs[19] = PB_BASE + 0x48d000ULL;
    cpu->regs[20] = cpu->regs[19] + 2880ULL;
    cpu->regs[0] = cpu->regs[20] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x18a2e8ULL; PB_CALL(689, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab24;
    cpu->regs[0] = cpu->regs[20] + 480ULL;
    cpu->regs[30] = PB_BASE + 0x18a2f4ULL; PB_CALL(690, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab18;
    cpu->regs[0] = cpu->regs[20] + 720ULL;
    cpu->regs[30] = PB_BASE + 0x18a300ULL; PB_CALL(691, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab0c;
    cpu->regs[0] = cpu->regs[20] + 1008ULL;
    cpu->regs[30] = PB_BASE + 0x18a30cULL; PB_CALL(692, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18ab00;
    cpu->regs[0] = cpu->regs[20] + 1360ULL;
    cpu->regs[30] = PB_BASE + 0x18a318ULL; PB_CALL(693, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aaf4;
    cpu->regs[0] = cpu->regs[20] + 2096ULL;
    cpu->regs[30] = PB_BASE + 0x18a324ULL; PB_CALL(694, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aae8;
    cpu->regs[0] = cpu->regs[20] + 2448ULL;
    cpu->regs[30] = PB_BASE + 0x18a330ULL; PB_CALL(695, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aadc;
    cpu->regs[0] = cpu->regs[20] + 2816ULL;
    cpu->regs[30] = PB_BASE + 0x18a33cULL; PB_CALL(696, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aad0;
    cpu->regs[0] = cpu->regs[20] + 3600ULL;
    cpu->regs[30] = PB_BASE + 0x18a348ULL; PB_CALL(697, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aac4;
    cpu->regs[0] = cpu->regs[20] + 3856ULL;
    cpu->regs[30] = PB_BASE + 0x18a354ULL; PB_CALL(698, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aab8;
    cpu->regs[19] = PB_BASE + 0x48e000ULL;
    cpu->regs[20] = cpu->regs[19] + 3136ULL;
    cpu->regs[0] = cpu->regs[20] - 224ULL;
    cpu->regs[30] = PB_BASE + 0x18a368ULL; PB_CALL(699, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aaac;
    cpu->regs[0] = cpu->regs[20] + 480ULL;
    cpu->regs[30] = PB_BASE + 0x18a374ULL; PB_CALL(700, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aaa0;
    cpu->regs[0] = cpu->regs[20] + 704ULL;
    cpu->regs[30] = PB_BASE + 0x18a380ULL; PB_CALL(701, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa94;
    cpu->regs[0] = cpu->regs[20] + 992ULL;
    cpu->regs[30] = PB_BASE + 0x18a38cULL; PB_CALL(702, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa88;
    cpu->regs[0] = cpu->regs[20] + 2288ULL;
    cpu->regs[30] = PB_BASE + 0x18a398ULL; PB_CALL(703, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa7c;
    cpu->regs[0] = cpu->regs[20] + 2880ULL;
    cpu->regs[30] = PB_BASE + 0x18a3a4ULL; PB_CALL(704, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa70;
    cpu->regs[0] = cpu->regs[20] + 3472ULL;
    cpu->regs[30] = PB_BASE + 0x18a3b0ULL; PB_CALL(705, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa64;
    cpu->regs[0] = cpu->regs[20] + 4080ULL;
    cpu->regs[30] = PB_BASE + 0x18a3bcULL; PB_CALL(706, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa58;
    cpu->regs[19] = PB_BASE + 0x48f000ULL;
    cpu->regs[20] = cpu->regs[19] + 3392ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18a3d0ULL; PB_CALL(707, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa4c;
    cpu->regs[0] = cpu->regs[20] + 1168ULL;
    cpu->regs[30] = PB_BASE + 0x18a3dcULL; PB_CALL(708, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa40;
    cpu->regs[0] = cpu->regs[20] + 1712ULL;
    cpu->regs[30] = PB_BASE + 0x18a3e8ULL; PB_CALL(709, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa34;
    cpu->regs[0] = cpu->regs[20] + 1920ULL;
    cpu->regs[30] = PB_BASE + 0x18a3f4ULL; PB_CALL(710, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa28;
    cpu->regs[0] = cpu->regs[20] + 2128ULL;
    cpu->regs[30] = PB_BASE + 0x18a400ULL; PB_CALL(711, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa1c;
    cpu->regs[0] = cpu->regs[20] + 2368ULL;
    cpu->regs[30] = PB_BASE + 0x18a40cULL; PB_CALL(712, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa10;
    cpu->regs[0] = cpu->regs[20] + 2608ULL;
    cpu->regs[30] = PB_BASE + 0x18a418ULL; PB_CALL(713, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18aa04;
    cpu->regs[0] = cpu->regs[20] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0x18a424ULL; PB_CALL(714, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a9f8;
    cpu->regs[0] = cpu->regs[20] + 3088ULL;
    cpu->regs[30] = PB_BASE + 0x18a430ULL; PB_CALL(715, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a9ec;
    cpu->regs[0] = cpu->regs[20] + 3328ULL;
    cpu->regs[30] = PB_BASE + 0x18a43cULL; PB_CALL(716, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a9e0;
    cpu->regs[0] = cpu->regs[20] + 3568ULL;
    cpu->regs[30] = PB_BASE + 0x18a448ULL; PB_CALL(717, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a9d4;
    cpu->regs[0] = cpu->regs[20] + 3800ULL;
    cpu->regs[30] = PB_BASE + 0x18a454ULL; PB_CALL(718, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a9c8;
    cpu->regs[0] = cpu->regs[20] + 4000ULL;
    cpu->regs[30] = PB_BASE + 0x18a460ULL; PB_CALL(719, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a9bc;
    cpu->regs[19] = PB_BASE + 0x490000ULL;
    cpu->regs[20] = cpu->regs[19] + 3648ULL;
    cpu->regs[0] = cpu->regs[20] - 152ULL;
    cpu->regs[30] = PB_BASE + 0x18a474ULL; PB_CALL(720, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a9b0;
    cpu->regs[0] = cpu->regs[20] + 48ULL;
    cpu->regs[30] = PB_BASE + 0x18a480ULL; PB_CALL(721, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a9a4;
    cpu->regs[0] = cpu->regs[20] + 416ULL;
    cpu->regs[30] = PB_BASE + 0x18a48cULL; PB_CALL(722, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a998;
    cpu->regs[0] = cpu->regs[20] + 1184ULL;
    cpu->regs[30] = PB_BASE + 0x18a498ULL; PB_CALL(723, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a98c;
    cpu->regs[0] = cpu->regs[20] + 1440ULL;
    cpu->regs[30] = PB_BASE + 0x18a4a4ULL; PB_CALL(724, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a980;
    cpu->regs[0] = cpu->regs[20] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x18a4b0ULL; PB_CALL(725, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a974;
    cpu->regs[0] = cpu->regs[20] + 2224ULL;
    cpu->regs[30] = PB_BASE + 0x18a4bcULL; PB_CALL(726, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a968;
    cpu->regs[0] = cpu->regs[20] + 2880ULL;
    cpu->regs[30] = PB_BASE + 0x18a4c8ULL; PB_CALL(727, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a95c;
    cpu->regs[0] = cpu->regs[20] + 3120ULL;
    cpu->regs[30] = PB_BASE + 0x18a4d4ULL; PB_CALL(728, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a950;
    cpu->regs[0] = cpu->regs[20] + 3392ULL;
    cpu->regs[30] = PB_BASE + 0x18a4e0ULL; PB_CALL(729, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a944;
    cpu->regs[0] = cpu->regs[20] + 3664ULL;
    cpu->regs[30] = PB_BASE + 0x18a4ecULL; PB_CALL(730, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a938;
    cpu->regs[0] = cpu->regs[20] + 3904ULL;
    cpu->regs[30] = PB_BASE + 0x18a4f8ULL; PB_CALL(731, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a92c;
    cpu->regs[20] = PB_BASE + 0x491000ULL;
    cpu->regs[0] = cpu->regs[20] + 3904ULL;
    cpu->regs[0] = cpu->regs[0] - 192ULL;
    cpu->regs[30] = PB_BASE + 0x18a50cULL; PB_CALL(732, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a920;
    cpu->regs[19] = cpu->regs[20] + 3904ULL;
    cpu->regs[0] = cpu->regs[19] + 800ULL;
    cpu->regs[30] = PB_BASE + 0x18a51cULL; PB_CALL(733, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a914;
    cpu->regs[0] = cpu->regs[19] + 1056ULL;
    cpu->regs[30] = PB_BASE + 0x18a528ULL; PB_CALL(734, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a908;
    cpu->regs[0] = cpu->regs[19] + 1280ULL;
    cpu->regs[30] = PB_BASE + 0x18a534ULL; PB_CALL(735, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a8fc;
    cpu->regs[0] = cpu->regs[19] + 1536ULL;
    cpu->regs[30] = PB_BASE + 0x18a540ULL; PB_CALL(736, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a8f0;
    cpu->regs[0] = cpu->regs[19] + 1760ULL;
    cpu->regs[30] = PB_BASE + 0x18a54cULL; PB_CALL(737, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a8e4;
    cpu->regs[0] = cpu->regs[19] + 2016ULL;
    cpu->regs[30] = PB_BASE + 0x18a558ULL; PB_CALL(738, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a8d8;
    cpu->regs[0] = cpu->regs[19] + 2272ULL;
    cpu->regs[30] = PB_BASE + 0x18a564ULL; PB_CALL(739, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a8cc;
    cpu->regs[0] = cpu->regs[19] + 2528ULL;
    cpu->regs[30] = PB_BASE + 0x18a570ULL; PB_CALL(740, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a8c0;
    cpu->regs[0] = cpu->regs[19] + 3024ULL;
    cpu->regs[30] = PB_BASE + 0x18a57cULL; PB_CALL(741, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a8b4;
    cpu->regs[0] = cpu->regs[19] + 3296ULL;
    cpu->regs[30] = PB_BASE + 0x18a588ULL; PB_CALL(742, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a8a8;
    cpu->regs[0] = cpu->regs[19] + 3776ULL;
    cpu->regs[30] = PB_BASE + 0x18a594ULL; PB_CALL(743, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a89c;
    cpu->regs[0] = cpu->regs[19] + 4016ULL;
    cpu->regs[30] = PB_BASE + 0x18a5a0ULL; PB_CALL(744, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a890;
    cpu->regs[20] = PB_BASE + 0x493000ULL;
    cpu->regs[19] = cpu->regs[20] + 64ULL;
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x18a5b4ULL; PB_CALL(745, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a884;
    cpu->regs[0] = cpu->regs[19] + 288ULL;
    cpu->regs[30] = PB_BASE + 0x18a5c0ULL; PB_CALL(746, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a878;
    cpu->regs[0] = cpu->regs[19] + 688ULL;
    cpu->regs[30] = PB_BASE + 0x18a5ccULL; PB_CALL(747, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a86c;
    cpu->regs[0] = cpu->regs[19] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x18a5d8ULL; PB_CALL(748, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a860;
    cpu->regs[0] = cpu->regs[19] + 1328ULL;
    cpu->regs[30] = PB_BASE + 0x18a5e4ULL; PB_CALL(749, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a854;
    cpu->regs[0] = cpu->regs[19] + 1584ULL;
    cpu->regs[30] = PB_BASE + 0x18a5f0ULL; PB_CALL(750, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a848;
    cpu->regs[0] = cpu->regs[19] + 1968ULL;
    cpu->regs[30] = PB_BASE + 0x18a5fcULL; PB_CALL(751, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a83c;
    cpu->regs[0] = cpu->regs[19] + 2256ULL;
    cpu->regs[30] = PB_BASE + 0x18a608ULL; PB_CALL(752, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a830;
    cpu->regs[0] = cpu->regs[19] + 2480ULL;
    cpu->regs[30] = PB_BASE + 0x18a614ULL; PB_CALL(753, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a824;
    cpu->regs[0] = cpu->regs[19] + 2912ULL;
    cpu->regs[30] = PB_BASE + 0x18a620ULL; PB_CALL(754, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a818;
    cpu->regs[0] = cpu->regs[19] + 3408ULL;
    cpu->regs[30] = PB_BASE + 0x18a62cULL; PB_CALL(755, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a80c;
    cpu->regs[19] = PB_BASE + 0x494000ULL;
    cpu->regs[19] = cpu->regs[19] + 320ULL;
    cpu->regs[0] = cpu->regs[19] + 432ULL;
    cpu->regs[30] = PB_BASE + 0x18a640ULL; PB_CALL(756, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a800;
    cpu->regs[0] = cpu->regs[19] + 640ULL;
    cpu->regs[30] = PB_BASE + 0x18a64cULL; PB_CALL(757, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a7f4;
    cpu->regs[0] = cpu->regs[19] + 1216ULL;
    cpu->regs[30] = PB_BASE + 0x18a658ULL; PB_CALL(758, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a7e8;
    cpu->regs[0] = cpu->regs[19] + 1520ULL;
    cpu->regs[30] = PB_BASE + 0x18a664ULL; PB_CALL(759, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a7dc;
    cpu->regs[0] = cpu->regs[19] + 2032ULL;
    cpu->regs[30] = PB_BASE + 0x18a670ULL; PB_CALL(760, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a7d0;
    cpu->regs[0] = cpu->regs[19] + 2560ULL;
    cpu->regs[30] = PB_BASE + 0x18a67cULL; PB_CALL(761, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a7c4;
    cpu->regs[0] = cpu->regs[19] + 3616ULL;
    cpu->regs[30] = PB_BASE + 0x18a688ULL; PB_CALL(762, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a7b8;
    cpu->regs[20] = PB_BASE + 0x495000ULL;
    cpu->regs[19] = cpu->regs[20] + 576ULL;
    cpu->regs[0] = cpu->regs[19] - 160ULL;
    cpu->regs[30] = PB_BASE + 0x18a69cULL; PB_CALL(763, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a7ac;
    cpu->regs[0] = cpu->regs[19] + 48ULL;
    cpu->regs[30] = PB_BASE + 0x18a6a8ULL; PB_CALL(764, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a7a0;
    cpu->regs[0] = cpu->regs[19] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x18a6b4ULL; PB_CALL(765, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a794;
    cpu->regs[0] = cpu->regs[19] + 464ULL;
    cpu->regs[30] = PB_BASE + 0x18a6c0ULL; PB_CALL(766, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a788;
    cpu->regs[0] = cpu->regs[19] + 688ULL;
    cpu->regs[30] = PB_BASE + 0x18a6ccULL; PB_CALL(767, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a77c;
    cpu->regs[0] = cpu->regs[19] + 992ULL;
    cpu->regs[30] = PB_BASE + 0x18a6d8ULL; PB_CALL(768, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a770;
    cpu->regs[0] = cpu->regs[19] + 1216ULL;
    cpu->regs[30] = PB_BASE + 0x18a6e4ULL; PB_CALL(769, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a764;
    cpu->regs[0] = cpu->regs[19] + 1448ULL;
    cpu->regs[30] = PB_BASE + 0x18a6f0ULL; PB_CALL(770, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a758;
    cpu->regs[0] = cpu->regs[19] + 1648ULL;
    cpu->regs[30] = PB_BASE + 0x18a6fcULL; PB_CALL(771, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a74c;
    cpu->regs[0] = cpu->regs[19] + 1856ULL;
    cpu->regs[30] = PB_BASE + 0x18a708ULL; PB_CALL(772, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a740;
    cpu->regs[0] = cpu->regs[19] + 2080ULL;
    cpu->regs[30] = PB_BASE + 0x18a714ULL; PB_CALL(773, cpu, tlb, PB_BASE + 0x18c450ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18a734;
    cpu->regs[0] = cpu->regs[19] + 2320ULL;
    cpu->regs[30] = PB_BASE + 0x18a720ULL; PB_CALL(774, cpu, tlb, PB_BASE + 0x18c450ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
L_18a728:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_18a734:
    PB_LDR(cpu->regs[21], (SP + 32));
L_18a738:
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a740:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a74c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a758:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a764:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a770:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a77c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a788:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a794:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a7a0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a7ac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a7b8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a7c4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a7d0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a7dc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a7e8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a7f4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a800:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a80c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a818:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a824:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a830:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a83c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a848:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a854:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a860:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a86c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a878:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a884:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a890:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a89c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a8a8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a8b4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a8c0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a8cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a8d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a8e4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a8f0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a8fc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a908:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a914:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a920:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a92c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a938:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a944:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a950:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a95c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a968:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a974:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a980:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a98c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a998:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a9a4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a9b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a9bc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a9c8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a9d4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a9e0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a9ec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18a9f8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa04:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa10:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa1c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa28:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa34:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa40:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa4c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa58:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa64:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa70:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa7c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa88:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aa94:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aaa0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aaac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aab8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aac4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aad0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aadc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aae8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aaf4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab00:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab0c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab18:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab24:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab30:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab3c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab48:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab54:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab60:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab6c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab78:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab84:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab90:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ab9c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aba8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18abb4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18abc0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18abcc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18abd8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18abe4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18abf0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18abfc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac08:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac14:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac20:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac2c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac38:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac44:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac50:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac5c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac68:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac74:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac80:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac8c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ac98:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aca4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18acb0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18acbc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18acc8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18acd4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ace0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18acec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18acf8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad04:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad10:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad1c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad28:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad34:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad40:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad4c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad58:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad64:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad70:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad7c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad88:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ad94:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ada0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18adac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18adb8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18adc4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18add0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18addc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ade8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18adf4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae00:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae0c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae18:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae24:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae30:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae3c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae48:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae54:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae60:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae6c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae78:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae84:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae90:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ae9c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aea8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aeb4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aec0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aecc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aed8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aee4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aef0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aefc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af08:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af14:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af20:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af2c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af38:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af44:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af50:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af5c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af68:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af74:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af80:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af8c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18af98:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18afa4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18afb0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18afbc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18afc8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18afd4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18afe0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18afec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18aff8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b004:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b010:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b01c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b028:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b034:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b040:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b04c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b058:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b064:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b070:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b07c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b088:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b094:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b0a0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b0ac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b0b8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b0c4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b0d0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b0dc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b0e8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b0f4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b100:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b10c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b118:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b124:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b130:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b13c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b148:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b154:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b160:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b16c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b178:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b184:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b190:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b19c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b1a8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b1b4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b1c0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b1cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b1d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b1e4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b1f0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b1fc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b208:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b214:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b220:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b22c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b238:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b244:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b250:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b25c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b268:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b274:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b280:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b28c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b298:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b2a4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b2b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b2bc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b2c8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b2d4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b2e0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b2ec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b2f8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b304:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b310:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b31c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b328:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b334:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b340:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b34c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b358:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b364:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b370:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b37c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b388:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b394:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b3a0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b3ac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b3b8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b3c4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b3d0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b3dc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b3e8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b3f4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b400:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b40c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b418:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b424:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b430:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b43c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b448:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b454:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b460:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b46c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b478:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b484:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b490:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b49c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b4a8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b4b4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b4c0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b4cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b4d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b4e4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b4f0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b4fc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b508:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b514:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b520:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b52c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b538:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b544:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b550:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b55c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b568:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b574:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b580:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b58c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b598:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b5a4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b5b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b5bc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b5c8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b5d4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b5e0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b5ec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b5f8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b604:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b610:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b61c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b628:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b634:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b640:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b64c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b658:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b664:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b670:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b67c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b688:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b694:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b6a0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b6ac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b6b8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b6c4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b6d0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b6dc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b6e8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b6f4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b700:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b70c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b718:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b724:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b730:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b73c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b748:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b754:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b760:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b76c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b778:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b784:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b790:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b79c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b7a8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b7b4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b7c0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b7cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b7d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b7e4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b7f0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b7fc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b808:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b814:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b820:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b82c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b838:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b844:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b850:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b85c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b868:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b874:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b880:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b88c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b898:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b8a4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b8b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b8bc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b8c8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b8d4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b8e0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b8ec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b8f8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b904:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b910:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b91c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b928:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b934:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b940:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b94c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b958:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b964:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b970:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b97c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b988:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b994:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b9a0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b9ac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b9b8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b9c4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b9d0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b9dc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b9e8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18b9f4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba00:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba0c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba18:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba24:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba30:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba3c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba48:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba54:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba60:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba6c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba78:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba84:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba90:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18ba9c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18baa8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bab4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bac0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bacc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bad8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bae4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18baf0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bafc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb08:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb14:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb20:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb2c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb38:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb44:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb50:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb5c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb68:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb74:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb80:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb8c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bb98:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bba4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bbb0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bbbc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bbc8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bbd4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bbe0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bbec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bbf8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc04:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc10:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc1c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc28:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc34:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc40:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc4c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc58:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc64:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc70:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc7c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc88:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bc94:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bca0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bcac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bcb8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bcc4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bcd0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bcdc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bce8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bcf4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd00:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd0c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd18:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd24:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd30:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd3c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd48:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd54:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd60:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd6c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd78:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd84:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd90:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bd9c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bda8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bdb4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bdc0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bdcc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bdd8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bde4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bdf0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bdfc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be08:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be14:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be20:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be2c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be38:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be44:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be50:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be5c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be68:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be74:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be80:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be8c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18be98:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bea4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18beb0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bebc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bec8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bed4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bee0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18beec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bef8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf04:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf10:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf1c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf28:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf34:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf40:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf4c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf58:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf64:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf70:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf7c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf88:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bf94:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bfa0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bfac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bfb8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bfc4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bfd0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bfdc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bfe8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18bff4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c000:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c00c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c018:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c024:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c030:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c03c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c048:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c054:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c060:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c06c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c078:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c084:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c090:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c09c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c0a8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c0b4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c0c0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c0cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c0d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c0e4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c0f0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c0fc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c108:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c114:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c120:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c12c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c138:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c144:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c150:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c15c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c168:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c174:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c180:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c18c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c198:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c1a4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c1b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c1bc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c1c8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c1d4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c1e0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c1ec:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c1f8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c204:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c210:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c21c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c228:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c234:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c240:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c24c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c258:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c264:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c270:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c27c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c288:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c294:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c2a0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c2ac:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c2b8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c2c4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c2d0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c2dc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c2e8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c2f4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c300:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c30c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c318:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c324:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c330:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c33c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c348:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c354:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c360:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c36c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c378:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c384:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c390:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c39c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c3a8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c3b4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c3c0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c3cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c3d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c3e4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c3f0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c3fc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c408:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c414:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c420:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c42c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c438:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c444:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 4294967295ULL;
    goto L_18a728;
L_18c450:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[30] = PB_BASE + 0x18c468ULL; PB_CALL(775, cpu, tlb, PB_BASE + 0xdb580ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_18c4ac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18c47cULL; PB_CALL(776, cpu, tlb, PB_BASE + 0xdba30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_18c4ac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[30] = PB_BASE + 0x18c48cULL; PB_CALL(777, cpu, tlb, PB_BASE + 0xdb580ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_18c4ac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18c49cULL; PB_CALL(778, cpu, tlb, PB_BASE + 0xdbe20ULL);
    cpu->regs[0] = 0ULL;
L_18c4a0:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_18c4ac:
    cpu->regs[0] = 4294967295ULL;
    goto L_18c4a0;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 112ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 344));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[22])!=0) goto L_18c71c;
L_18c500:
    PB_LDR(cpu->regs[25], (cpu->regs[19] + 8));
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3216));
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_NE) goto L_18c600;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18c51cULL; PB_CALL(779, cpu, tlb, PB_BASE + 0x18c7e0ULL);
    cpu->regs[21] = cpu->regs[0];
L_18c520:
    if ((cpu->regs[21])==0) goto L_18c6b8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18c52cULL; PB_CALL(780, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[2] >> 31) & 1)) goto L_18c544;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_18c5f4;
L_18c544:
    if ((cpu->regs[20])==0) goto L_18c6b8;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    if ((cpu->regs[21])==0) goto L_18c6d8;
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_NE) goto L_18c658;
L_18c558:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 344));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x18c564ULL; PB_CALL(781, cpu, tlb, PB_BASE + 0xdce4cULL);
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_NE) goto L_18c73c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (((cpu->regs[0] >> 1) & 1)) goto L_18c5e8;
L_18c574:
    PB_STR((cpu->regs[19] + 344), cpu->regs[20]);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18c584ULL; PB_CALL(782, cpu, tlb, PB_BASE + 0xdcf60ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 336));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18c590ULL; PB_CALL(783, cpu, tlb, PB_BASE + 0xdcf60ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if (((cpu->regs[0] >> 1) & 1)) goto L_18c5a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18c5a0ULL; PB_CALL(784, cpu, tlb, PB_BASE + 0x18e42cULL);
L_18c5a0:
    if ((cpu->regs[23])!=0) goto L_18c730;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x18c5acULL; PB_CALL(785, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = 1ULL;
L_18c5b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_18c714;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 112ULL;
    return;
L_18c5e8:
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_18c574;
L_18c5f4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18c5fcULL; PB_CALL(786, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18c544;
L_18c600:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 50768ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x18c61cULL; PB_CALL(787, cpu, tlb, PB_BASE + 0x122b00ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18c6b0;
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18c634ULL; PB_CALL(788, cpu, tlb, PB_BASE + 0x1d3764ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_18c520;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_18c520;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18c654ULL; PB_CALL(789, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18c520;
L_18c658:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 96), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x18c668ULL; PB_CALL(790, cpu, tlb, PB_BASE + 0x18e3acULL);
    cpu->regs[27] = cpu->regs[20] + 24ULL;
    cpu->regs[26] = cpu->regs[0];
    goto L_18c6a0;
L_18c674:
    PB_LDR(cpu->regs[25], (cpu->regs[27] + (cpu->regs[24] << 3)));
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18c7a0;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18c68cULL; PB_CALL(791, cpu, tlb, PB_BASE + 0x18e3acULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x18c698ULL; PB_CALL(792, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18c758;
    cpu->regs[24] = cpu->regs[24] + 1ULL;
L_18c6a0:
    FLAG_CMP(cpu->regs[21], cpu->regs[24]);
    if (FLAG_GT) goto L_18c674;
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_18c558;
L_18c6b0:
    cpu->regs[30] = PB_BASE + 0x18c6b4ULL; PB_CALL(793, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_18c6c8;
L_18c6b8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x18c6c0ULL; PB_CALL(794, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_18c5b0;
L_18c6c8:
    cpu->regs[0] = 50768ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x18c6d4ULL; PB_CALL(795, cpu, tlb, PB_BASE + 0x7c598ULL);
    goto L_18c6b8;
L_18c6d8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c6ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18c708;
L_18c6ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18c704ULL; PB_CALL(796, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_18c6b8;
L_18c708:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18c710ULL; PB_CALL(797, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18c6ec;
L_18c714:
    PB_STR((SP + 96), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x18c71cULL; PB_CALL(798, cpu, tlb, PB_BASE + 0x7c170ULL);
L_18c71c:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_18c500;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_18c500;
L_18c730:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[22]);
    goto L_18c5b0;
L_18c73c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c750;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18c790;
L_18c750:
    cpu->regs[0] = 0ULL;
    goto L_18c5b0;
L_18c758:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 24));
    cpu->regs[1] = cpu->regs[1] + 1048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18c774ULL; PB_CALL(799, cpu, tlb, PB_BASE + 0x11f220ULL);
L_18c774:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c788;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18c7c0;
L_18c788:
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_18c6b8;
L_18c790:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18c798ULL; PB_CALL(800, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_18c5b0;
L_18c7a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1008ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18c7bcULL; PB_CALL(801, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_18c774;
L_18c7c0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18c7c8ULL; PB_CALL(802, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 96));
    goto L_18c6b8;
}
