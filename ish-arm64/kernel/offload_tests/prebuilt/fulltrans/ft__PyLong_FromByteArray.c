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

void ft__PyLong_FromByteArray(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((cpu->regs[1])==0) goto L_145ce0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[22] = 1ULL;
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_145cc0;
L_145594:
    cpu->regs[4] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[22])));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_145ba8;
L_14559c:
    cpu->regs[21] = 0ULL;
    cpu->regs[5] = 0ULL;
L_1455a4:
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[4]));
    cpu->regs[2] = 0ULL;
L_1455ac:
    PB_LDRB(cpu->regs[4], (cpu->regs[0] + 0));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_NE) goto L_1455d0;
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_1455ac;
    cpu->regs[20] = cpu->regs[21] & 1ULL;
    goto L_1455f0;
L_1455d0:
    cpu->regs[2] = cpu->regs[1] - cpu->regs[2];
    cpu->regs[0] = 1152921504606846972ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    cpu->regs[20] = (FLAG_HI) ? 1 : 0;
    cpu->regs[20] = cpu->regs[20] & cpu->regs[21];
    cpu->regs[20] = cpu->regs[20] + cpu->regs[2];
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HI) goto L_145cf0;
L_1455f0:
    cpu->regs[0] = cpu->regs[20] << 3;
    cpu->regs[1] = 30ULL;
    cpu->regs[0] = cpu->regs[0] + 29ULL;
    cpu->regs[0] = (cpu->regs[1] ? cpu->regs[0] / cpu->regs[1] : 0);
    cpu->regs[30] = PB_BASE + 0x145604ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_145d08;
    if ((cpu->regs[20])==0) goto L_145cd4;
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(1ULL)));
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1459a4;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[6] = 0ULL;
    if (FLAG_NE) goto L_145840;
    cpu->regs[3] = cpu->regs[20] & 3ULL; FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_145748;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_145664;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_NE) goto L_145814;
L_145640:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145bbc;
    cpu->regs[2] = cpu->regs[4];
L_14565c:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_145664:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145824;
    cpu->regs[2] = cpu->regs[4];
L_145680:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[20]);
    if (FLAG_NE) goto L_145748;
L_145690:
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_1456a4;
L_145694:
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    PB_STRW((cpu->regs[2] + 24), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_145a68;
L_1456a4:
    cpu->regs[2] = 1ULL;
L_1456a8:
    FLAG_CMP(cpu->regs[6], 0ULL);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : 0ULL;
L_1456b0:
    cpu->regs[1] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] | (cpu->regs[6] << 3);
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1456c8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x145d20ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_145da0;
L_1456d8:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 1));
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145798;
L_1456fc:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 1));
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_1457c8;
L_145718:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 2));
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_1457f8;
L_145734:
    cpu->regs[2] = cpu->regs[4];
L_145738:
    cpu->regs[5] = cpu->regs[5] + 3ULL;
    cpu->regs[19] = cpu->regs[19] + 3ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[20]);
    if (FLAG_EQ) goto L_145690;
L_145748:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_LS) goto L_1456d8;
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[1] = cpu->regs[1] >> 30;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_LS) goto L_1456fc;
L_145798:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[1] = cpu->regs[1] >> 30;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 1));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_LS) goto L_145718;
L_1457c8:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[1] = cpu->regs[1] >> 30;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 2));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_LS) goto L_145734;
L_1457f8:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_145738;
L_145814:
    PB_LDRB(cpu->regs[1], cpu->regs[19]); cpu->regs[19] += 1;
    cpu->regs[2] = 8ULL;
    cpu->regs[5] = 1ULL;
    goto L_145640;
L_145824:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_145680;
L_145840:
    cpu->regs[3] = cpu->regs[20] & 3ULL; FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_14591c;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_EQ) goto L_14587c;
    FLAG_CMP(cpu->regs[3], 2ULL);
    if (FLAG_NE) goto L_145bd8;
L_145858:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145ca4;
    cpu->regs[2] = cpu->regs[4];
L_145874:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
L_14587c:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145c6c;
    cpu->regs[2] = cpu->regs[4];
L_145898:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[20]);
    if (FLAG_NE) goto L_14591c;
    goto L_145690;
L_1458ac:
    cpu->regs[2] = cpu->regs[4];
L_1458b0:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + -1));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145988;
    cpu->regs[2] = cpu->regs[4];
L_1458d4:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + -1));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_14596c;
    cpu->regs[2] = cpu->regs[4];
L_1458f0:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + -2));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145950;
    cpu->regs[2] = cpu->regs[4];
L_14590c:
    cpu->regs[5] = cpu->regs[5] + 3ULL;
    cpu->regs[19] = cpu->regs[19] - 3ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[20]);
    if (FLAG_EQ) goto L_145690;
L_14591c:
    PB_LDRB(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] + 8ULL));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[2] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(29ULL)));
    if (FLAG_LS) goto L_1458ac;
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_1458b0;
L_145950:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_14590c;
L_14596c:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_1458f0;
L_145988:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_1458d4;
L_1459a4:
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_145c04;
    cpu->regs[4] = cpu->regs[20] & 3ULL; FLAG_CMP(cpu->regs[4], 0);
    cpu->regs[2] = 1ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 0ULL;
    if (FLAG_EQ) goto L_145b10;
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_EQ) goto L_145a28;
    FLAG_CMP(cpu->regs[4], 2ULL);
    if (FLAG_EQ) goto L_1459f4;
    PB_LDRB(cpu->regs[4], cpu->regs[19]); cpu->regs[19] += 1;
    cpu->regs[7] = 1ULL;
    cpu->regs[3] = 8ULL;
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[4] = cpu->regs[4] & 255ULL;
    cpu->regs[2] = cpu->regs[4] + cpu->regs[7];
    cpu->regs[1] = cpu->regs[2] & 255ULL;
    cpu->regs[2] = cpu->regs[2] >> 8;
L_1459f4:
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + 0));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] + 8ULL));
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[2] = cpu->regs[2] + ((cpu->regs[4]) & 0xffULL);
    cpu->regs[4] = cpu->regs[2] & 255ULL;
    cpu->regs[2] = cpu->regs[2] >> 8;
    cpu->regs[4] = cpu->regs[4] << (cpu->regs[3] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145be8;
    cpu->regs[3] = cpu->regs[5];
L_145a20:
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_145a28:
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + 0));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] + 8ULL));
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[2] = cpu->regs[2] + ((cpu->regs[4]) & 0xffULL);
    cpu->regs[4] = cpu->regs[2] & 255ULL;
    cpu->regs[2] = cpu->regs[2] >> 8;
    cpu->regs[4] = cpu->regs[4] << (cpu->regs[3] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145c88;
    cpu->regs[3] = cpu->regs[5];
L_145a54:
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[20]);
    if (FLAG_NE) goto L_145b10;
L_145a64:
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_145694;
L_145a68:
    cpu->regs[2] = 4294967295ULL;
    goto L_1456a8;
L_145a70:
    cpu->regs[3] = cpu->regs[5];
L_145a74:
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + 1));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] + 8ULL));
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[2] = cpu->regs[2] + ((cpu->regs[4]) & 0xffULL);
    cpu->regs[4] = cpu->regs[2] & 255ULL;
    cpu->regs[2] = cpu->regs[2] >> 8;
    cpu->regs[4] = cpu->regs[4] << (cpu->regs[3] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145b8c;
    cpu->regs[3] = cpu->regs[5];
L_145aa8:
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + 1));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] + 8ULL));
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[2] = cpu->regs[2] + ((cpu->regs[4]) & 0xffULL);
    cpu->regs[4] = cpu->regs[2] & 255ULL;
    cpu->regs[2] = cpu->regs[2] >> 8;
    cpu->regs[4] = cpu->regs[4] << (cpu->regs[3] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145b70;
    cpu->regs[3] = cpu->regs[5];
L_145ad4:
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + 2));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] + 8ULL));
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[2] = cpu->regs[2] + ((cpu->regs[4]) & 0xffULL);
    cpu->regs[4] = cpu->regs[2] & 255ULL;
    cpu->regs[2] = cpu->regs[2] >> 8;
    cpu->regs[4] = cpu->regs[4] << (cpu->regs[3] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(29ULL)));
    if (FLAG_HI) goto L_145b54;
    cpu->regs[3] = cpu->regs[5];
L_145b00:
    cpu->regs[7] = cpu->regs[7] + 3ULL;
    cpu->regs[19] = cpu->regs[19] + 3ULL;
    FLAG_CMP(cpu->regs[7], cpu->regs[20]);
    if (FLAG_EQ) goto L_145a64;
L_145b10:
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + 0));
    cpu->regs[5] = ((uint32_t)(cpu->regs[3] + 8ULL));
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[2] = cpu->regs[2] + ((cpu->regs[4]) & 0xffULL);
    cpu->regs[4] = cpu->regs[2] & 255ULL;
    cpu->regs[2] = cpu->regs[2] >> 8;
    cpu->regs[4] = cpu->regs[4] << (cpu->regs[3] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(29ULL)));
    if (FLAG_LS) goto L_145a70;
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[4] + 24), cpu->regs[5]);
    goto L_145a74;
L_145b54:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[4] + 24), cpu->regs[5]);
    goto L_145b00;
L_145b70:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[4] + 24), cpu->regs[5]);
    goto L_145ad4;
L_145b8c:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[4] + 24), cpu->regs[5]);
    goto L_145aa8;
L_145ba8:
    do { int8_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,1); cpu->regs[2] = (uint64_t)(int64_t)_s; } while(0);
    if (!((cpu->regs[2] >> 31) & 1)) goto L_14559c;
    cpu->regs[21] = 1ULL;
    cpu->regs[5] = 255ULL;
    goto L_1455a4;
L_145bbc:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_14565c;
L_145bd8:
    PB_LDRB(cpu->regs[1], cpu->regs[19]); cpu->regs[19] += -1;
    cpu->regs[2] = 8ULL;
    cpu->regs[5] = 1ULL;
    goto L_145858;
L_145be8:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[4] + 24), cpu->regs[5]);
    goto L_145a20;
L_145c04:
    cpu->regs[5] = 0ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[2] = 1ULL;
    goto L_145c28;
L_145c14:
    cpu->regs[3] = cpu->regs[7];
L_145c18:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[19] = cpu->regs[19] - 1ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[20]);
    if (FLAG_EQ) goto L_145a64;
L_145c28:
    PB_LDRB(cpu->regs[4], (cpu->regs[19] + 0));
    cpu->regs[7] = ((uint32_t)(cpu->regs[3] + 8ULL));
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[2] = cpu->regs[2] + ((cpu->regs[4]) & 0xffULL);
    cpu->regs[4] = cpu->regs[2] & 255ULL;
    cpu->regs[2] = cpu->regs[2] >> 8;
    cpu->regs[4] = cpu->regs[4] << (cpu->regs[3] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(29ULL)));
    if (FLAG_LS) goto L_145c14;
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[7] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[4] + 24), cpu->regs[7]);
    goto L_145c18;
L_145c6c:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_145898;
L_145c88:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[4] + 24), cpu->regs[5]);
    goto L_145a54;
L_145ca4:
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[6] << 2);
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 22ULL));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    PB_STRW((cpu->regs[3] + 24), cpu->regs[4]);
    goto L_145874;
L_145cc0:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[22] = 4294967295ULL;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    goto L_145594;
L_145cd4:
    cpu->regs[6] = 0ULL;
    cpu->regs[2] = 0ULL;
    goto L_1456b0;
L_145ce0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 3208ULL;
    return;
L_145cf0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3288ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x145d08ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_145d08:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
L_145d20:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[2] >> 3;
    if ((cpu->regs[1])==0) goto L_145d38;
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[1] << 2);
    PB_LDRW(cpu->regs[3], (cpu->regs[4] + 20));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_145d3c;
L_145d38:
    return;
L_145d3c:
    cpu->regs[3] = cpu->regs[1] - 1ULL; FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_145d88;
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + 16));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_145d5c;
L_145d4c:
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[3] = cpu->regs[2] | (cpu->regs[3] << 3);
    PB_STR((cpu->regs[0] + 16), cpu->regs[3]);
    return;
L_145d5c:
    cpu->regs[3] = cpu->regs[1] - 2ULL;
    cpu->regs[6] = cpu->regs[0] + 24ULL;
L_145d64:
    cpu->regs[4] = cpu->regs[3] - 1ULL;
    if ((cpu->regs[3])==0) goto L_145d88;
    PB_LDRW(cpu->regs[5], (cpu->regs[6] + (cpu->regs[4] << 2)));
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_145d80;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_NE) goto L_145d4c;
    return;
L_145d80:
    cpu->regs[3] = cpu->regs[4];
    goto L_145d64;
L_145d88:
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    return;
    /* nop */
    /* nop */
    /* nop */
L_145da0:
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_145db4;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[2], 15ULL);
    if (FLAG_LS) goto L_145dbc;
L_145db4:
    cpu->regs[0] = cpu->regs[1];
    return;
L_145dbc:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[29] = SP;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 24));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = 1ULL;
    cpu->regs[19] = cpu->regs[19] - cpu->regs[2];
    cpu->regs[19] = cpu->regs[19] * cpu->regs[3];
    cpu->regs[2] = cpu->regs[19] + 5ULL;
    FLAG_CMP(cpu->regs[2], 261ULL);
    if (FLAG_LS) goto L_145df8;
L_145de8:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_145df8:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_145e10;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_145e10;
    cpu->regs[30] = PB_BASE + 0x145e10ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdfce0ULL);
L_145e10:
    cpu->regs[0] = ((uint32_t)(cpu->regs[19] + 5ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    goto L_145de8;
}
