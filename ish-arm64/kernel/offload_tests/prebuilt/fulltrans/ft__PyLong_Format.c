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

void ft__PyLong_Format(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_168618;
    cpu->regs[3] = SP;
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1685e4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x168640ULL);
L_1685e4:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_168630;
    PB_LDR(cpu->regs[0], (SP + 0));
L_1685f0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_16862c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_168618:
    cpu->regs[1] = SP;
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x168628ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x12df40ULL);
    goto L_1685e4;
L_16862c:
    cpu->regs[30] = PB_BASE + 0x168630ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_168630:
    cpu->regs[0] = 0ULL;
    goto L_1685f0;
    /* nop */
    /* nop */
L_168640:
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_168e8c;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_168e88;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = 4ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[3];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[2];
    cpu->regs[25] = cpu->regs[4];
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 16));
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[27] = cpu->regs[20] & 3ULL;
    FLAG_CMP(cpu->regs[27], 2ULL);
    cpu->regs[20] = cpu->regs[20] >> 3;
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_1688d8;
    if ((cpu->regs[20])==0) goto L_1688e8;
L_1686a4:
    cpu->regs[0] = 4919131752989213764ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x444ULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_HI) goto L_168ecc;
    cpu->regs[0] = cpu->regs[21] + (cpu->regs[20] << 2);
    cpu->regs[3] = cpu->regs[20] - 1ULL;
    cpu->regs[1] = cpu->regs[3] << 4;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 20));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] << 1;
    if ((cpu->regs[0])==0) goto L_1688f8;
    cpu->regs[4] = (((uint64_t)(cpu->regs[0])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[0])));
    cpu->regs[2] = ((uint32_t)(cpu->regs[19] - 1ULL));
    cpu->regs[0] = 64ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - cpu->regs[4]));
    cpu->regs[1] = cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[0] = cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_168908;
L_1686f0:
    cpu->regs[22] = cpu->regs[22] + ((uint64_t)((int64_t)cpu->regs[0] >> 2));
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_168918;
L_1686f8:
    cpu->regs[22] = cpu->regs[22] + 2ULL;
L_1686fc:
    if ((cpu->regs[25])!=0) goto L_168b7c;
L_168700:
    if ((cpu->regs[5])!=0) goto L_168ca4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 120ULL;
    cpu->regs[30] = PB_BASE + 0x168710ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    if ((cpu->regs[0])==0) goto L_168cc4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[2] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_168d74;
    if (!((cpu->regs[1] >> 5) & 1)) goto L_168d4c;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_168d58;
    cpu->regs[8] = cpu->regs[22] + 40ULL;
    cpu->regs[8] = cpu->regs[0] + cpu->regs[8];
L_168734:
    if ((cpu->regs[20])==0) goto L_1689a0;
    cpu->regs[7] = ((uint32_t)(cpu->regs[24] - 1ULL));
    cpu->regs[21] = cpu->regs[21] + 24ULL;
    cpu->regs[7] = ((uint32_t)(cpu->regs[7] & 255ULL));
    cpu->regs[3] = cpu->regs[20] - 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = 0ULL;
L_168754:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (cpu->regs[2] << 2)));
    cpu->regs[9] = ((uint32_t)(cpu->regs[6] + 30ULL));
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[6] & 63);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[5];
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_GT) goto L_1689f8;
    cpu->regs[4] = ((uint32_t)(cpu->regs[7] & cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_1689c0;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 48ULL));
    PB_STRB((cpu->regs[8] + -1), cpu->regs[4]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[9] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[1] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])==0) goto L_1689d4;
L_16878c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_1689dc;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 48ULL));
    PB_STRB((cpu->regs[8] + -2), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])==0) goto L_1689f0;
L_1687ac:
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_16896c;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 48ULL));
    PB_STRB((cpu->regs[8] + -3), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])==0) goto L_168980;
L_1687cc:
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_168b44;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 48ULL));
    PB_STRB((cpu->regs[8] + -4), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])==0) goto L_168b58;
L_1687ec:
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_168b28;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 48ULL));
    PB_STRB((cpu->regs[8] + -5), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])==0) goto L_168b3c;
L_16880c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_168b60;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 48ULL));
    PB_STRB((cpu->regs[8] + -6), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])==0) goto L_168b74;
L_16882c:
    cpu->regs[4] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[9] = 48ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(9ULL)));
    cpu->regs[1] = 87ULL;
    cpu->regs[1] = (FLAG_HI) ? cpu->regs[1] : cpu->regs[9];
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[4]));
    PB_STRB((cpu->regs[8] + -7), cpu->regs[1]);
    cpu->regs[9] = cpu->regs[8] - 7ULL;
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])==0) goto L_168880;
    /* nop */
    /* nop */
L_168860:
    cpu->regs[1] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] + 48ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_HI) goto L_168988;
    cpu->regs[9] += -1; PB_STRB(cpu->regs[9], cpu->regs[4]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])!=0) goto L_168860;
L_168880:
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    if (FLAG_GT) goto L_168be8;
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_1689b0;
L_168890:
    cpu->regs[1] = 120ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_168938;
L_16889c:
    cpu->regs[2] = 48ULL;
    PB_STRB((cpu->regs[9] + -2), cpu->regs[2]);
    PB_STRB((cpu->regs[9] + -1), cpu->regs[1]);
    FLAG_CMP(cpu->regs[27], 2ULL);
    if (FLAG_EQ) goto L_16894c;
L_1688b0:
    if ((cpu->regs[25])!=0) goto L_16895c;
L_1688b4:
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
L_1688b8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80));
L_1688d0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_1688d8:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    cpu->regs[19] = 3ULL;
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : (0ULL + 1);
    if ((cpu->regs[20])!=0) goto L_1686a4;
L_1688e8:
    cpu->regs[22] = 1ULL;
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_1686fc;
    cpu->regs[22] = cpu->regs[22] + 2ULL;
    goto L_1686fc;
L_1688f8:
    cpu->regs[0] = ((uint32_t)(cpu->regs[19] - 1ULL));
    cpu->regs[0] = cpu->regs[1] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_1686f0;
L_168908:
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    cpu->regs[0] = (cpu->regs[1] ? cpu->regs[0] / cpu->regs[1] : 0);
    cpu->regs[22] = cpu->regs[0] + cpu->regs[22];
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_1686f8;
L_168918:
    if ((cpu->regs[25])==0) goto L_168700;
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(119ULL)));
    if (FLAG_HI) goto L_168ce0;
L_168928:
    if ((cpu->regs[22])!=0) goto L_168b88;
    if ((cpu->regs[5])==0) goto L_168bac;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 0));
    goto L_168c14;
L_168938:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(8ULL)));
    cpu->regs[1] = 111ULL;
    cpu->regs[2] = 98ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    goto L_16889c;
L_16894c:
    cpu->regs[9] = cpu->regs[9] - 2ULL;
L_168950:
    cpu->regs[1] = 45ULL;
    PB_STRB((cpu->regs[9] + -1), cpu->regs[1]);
    if ((cpu->regs[25])==0) goto L_1688b4;
L_16895c:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 32));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[22];
    PB_STR((cpu->regs[25] + 32), cpu->regs[0]);
    goto L_1688b8;
L_16896c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 87ULL));
    PB_STRB((cpu->regs[8] + -3), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])!=0) goto L_1687cc;
L_168980:
    cpu->regs[9] = cpu->regs[8] - 3ULL;
    goto L_168880;
L_168988:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 87ULL));
    cpu->regs[9] += -1; PB_STRB(cpu->regs[9], cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])!=0) goto L_168860;
    goto L_168880;
L_1689a0:
    cpu->regs[1] = 48ULL;
    PB_STRB((cpu->regs[8] + -1), cpu->regs[1]);
    cpu->regs[9] = cpu->regs[8] - 1ULL;
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_168890;
L_1689b0:
    FLAG_CMP(cpu->regs[27], 2ULL);
    if (FLAG_EQ) goto L_168950;
    if ((cpu->regs[25])==0) goto L_1688b4;
    goto L_16895c;
L_1689c0:
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 87ULL));
    PB_STRB((cpu->regs[8] + -1), cpu->regs[4]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[9] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[1] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])!=0) goto L_16878c;
L_1689d4:
    cpu->regs[9] = cpu->regs[8] - 1ULL;
    goto L_168880;
L_1689dc:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 87ULL));
    PB_STRB((cpu->regs[8] + -2), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])!=0) goto L_1687ac;
L_1689f0:
    cpu->regs[9] = cpu->regs[8] - 2ULL;
    goto L_168880;
L_1689f8:
    cpu->regs[11] = ((uint32_t)(cpu->regs[7] & cpu->regs[1]));
    cpu->regs[10] = 87ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[11])), ((uint32_t)(9ULL)));
    cpu->regs[4] = 48ULL;
    cpu->regs[5] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[4];
    cpu->regs[6] = ((uint32_t)(cpu->regs[9] - cpu->regs[19]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] + cpu->regs[11]));
    PB_STRB((cpu->regs[8] + -1), cpu->regs[5]);
    cpu->regs[5] = cpu->regs[1] >> (cpu->regs[19] & 63);
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_LT) goto L_1689d4;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(9ULL)));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    cpu->regs[1] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[4];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[9]));
    PB_STRB((cpu->regs[8] + -2), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_GT) goto L_1689f0;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(9ULL)));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    cpu->regs[1] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[4];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[9]));
    PB_STRB((cpu->regs[8] + -3), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_GT) goto L_168980;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(9ULL)));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    cpu->regs[1] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[4];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[9]));
    PB_STRB((cpu->regs[8] + -4), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_LT) goto L_168b58;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(9ULL)));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    cpu->regs[1] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[4];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[9]));
    PB_STRB((cpu->regs[8] + -5), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_GT) goto L_168b3c;
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(9ULL)));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    cpu->regs[1] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[4];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[9]));
    PB_STRB((cpu->regs[8] + -6), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_GT) goto L_168b74;
    cpu->regs[11] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[11])), ((uint32_t)(9ULL)));
    cpu->regs[9] = cpu->regs[8] - 7ULL;
    cpu->regs[1] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[4];
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[11]));
    PB_STRB((cpu->regs[8] + -7), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_GT) goto L_168880;
L_168b00:
    cpu->regs[8] = ((uint32_t)(cpu->regs[7] & cpu->regs[5]));
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    FLAG_CMP(((uint32_t)(cpu->regs[8])), ((uint32_t)(9ULL)));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    cpu->regs[1] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[4];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[8]));
    cpu->regs[9] += -1; PB_STRB(cpu->regs[9], cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_LE) goto L_168b00;
    goto L_168880;
L_168b28:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 87ULL));
    PB_STRB((cpu->regs[8] + -5), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])!=0) goto L_16880c;
L_168b3c:
    cpu->regs[9] = cpu->regs[8] - 5ULL;
    goto L_168880;
L_168b44:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 87ULL));
    PB_STRB((cpu->regs[8] + -4), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])!=0) goto L_1687ec;
L_168b58:
    cpu->regs[9] = cpu->regs[8] - 4ULL;
    goto L_168880;
L_168b60:
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 87ULL));
    PB_STRB((cpu->regs[8] + -6), cpu->regs[1]);
    cpu->regs[6] = ((uint32_t)(cpu->regs[6] - cpu->regs[19]));
    cpu->regs[5] = cpu->regs[5] >> (cpu->regs[19] & 63);
    if ((cpu->regs[5])!=0) goto L_16882c;
L_168b74:
    cpu->regs[9] = cpu->regs[8] - 6ULL;
    goto L_168880;
L_168b7c:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 20));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(119ULL)));
    if (FLAG_HI) goto L_168bf0;
L_168b88:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = 120ULL;
    PB_STR((SP + 96), cpu->regs[5]); PB_STR((SP + 96) + 8, cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x168b9cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11cba0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_168cc4;
    PB_LDR(cpu->regs[5], (SP + 96)); PB_LDR(cpu->regs[6], (SP + 96) + 8);
    if ((cpu->regs[5])!=0) goto L_168c04;
L_168bac:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 32));
L_168bb0:
    PB_LDRW(cpu->regs[0], (cpu->regs[25] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_168de4;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    if (!((cpu->regs[2] >> 5) & 1)) goto L_168ddc;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[8] = cpu->regs[0] + 56ULL;
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[8] = (FLAG_EQ) ? cpu->regs[8] : cpu->regs[2];
L_168bd8:
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[0] = 0ULL;
    cpu->regs[8] = cpu->regs[8] + cpu->regs[1];
    goto L_168734;
L_168be8:
    cpu->regs[8] = cpu->regs[9];
    goto L_168754;
L_168bf0:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 24)); PB_LDR(cpu->regs[1], (cpu->regs[25] + 24) + 8);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_GT) goto L_168b88;
    if ((cpu->regs[5])==0) goto L_168bb0;
L_168c04:
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 0));
    cpu->regs[3] = cpu->regs[20] - 1ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[22];
    if ((cpu->regs[20])==0) goto L_168d64;
L_168c14:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[21] + 24ULL;
    cpu->regs[7] = ((uint32_t)(cpu->regs[24] - 1ULL));
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[10] = 87ULL;
    cpu->regs[9] = 48ULL;
L_168c34:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + (cpu->regs[5] << 2)));
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[4] & 63);
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 30ULL));
    cpu->regs[2] = cpu->regs[2] | cpu->regs[0];
L_168c44:
    cpu->regs[0] = ((uint32_t)(cpu->regs[7] & cpu->regs[2]));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] - cpu->regs[19]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 255ULL));
    cpu->regs[2] = cpu->regs[2] >> (cpu->regs[19] & 63);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    cpu->regs[8] = (FLAG_HI) ? cpu->regs[10] : cpu->regs[9];
    cpu->regs[0] = ((uint32_t)(cpu->regs[8] + cpu->regs[0]));
    cpu->regs[1] += -1; PB_STRB(cpu->regs[1], cpu->regs[0]);
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_GT) goto L_168d2c;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
L_168c74:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_168c44;
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_GT) goto L_168c34;
L_168c84:
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_168d00;
L_168c88:
    FLAG_CMP(cpu->regs[27], 2ULL);
    if (FLAG_EQ) goto L_168d40;
L_168c90:
    if ((cpu->regs[25])!=0) goto L_16895c;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 0));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[22];
    PB_STR((cpu->regs[6] + 0), cpu->regs[0]);
    goto L_1688b8;
L_168ca4:
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 0));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[2] = cpu->regs[22];
    PB_STR((SP + 96), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0x168cb8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11db70ULL);
    PB_LDR(cpu->regs[6], (SP + 96));
    PB_STR((cpu->regs[6] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_168c04;
L_168cc4:
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1688d0;
L_168ce0:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 24)); PB_LDR(cpu->regs[1], (cpu->regs[25] + 24) + 8);
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_LT) goto L_168928;
    if ((cpu->regs[5])==0) goto L_168bb0;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 0));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[22];
    goto L_168c14;
L_168d00:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(16ULL)));
    if (FLAG_EQ) goto L_168d38;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(8ULL)));
    cpu->regs[0] = 111ULL;
    cpu->regs[2] = 98ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
L_168d18:
    cpu->regs[2] = 48ULL;
    cpu->regs[1] = cpu->regs[1] - 2ULL;
    PB_STRB((cpu->regs[1] + 0), cpu->regs[2]);
    PB_STRB((cpu->regs[1] + 1), cpu->regs[0]);
    goto L_168c88;
L_168d2c:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[4])));
    cpu->regs[0] = (FLAG_LE) ? 1 : 0;
    goto L_168c74;
L_168d38:
    cpu->regs[0] = 120ULL;
    goto L_168d18;
L_168d40:
    cpu->regs[0] = 45ULL;
    PB_STRB((cpu->regs[1] + -1), cpu->regs[0]);
    goto L_168c90;
L_168d4c:
    PB_LDR(cpu->regs[8], (cpu->regs[0] + 56));
    cpu->regs[8] = cpu->regs[8] + cpu->regs[22];
    goto L_168734;
L_168d58:
    cpu->regs[8] = cpu->regs[0] + 56ULL;
    cpu->regs[8] = cpu->regs[8] + cpu->regs[22];
    goto L_168734;
L_168d64:
    cpu->regs[2] = 48ULL;
    cpu->regs[1] = cpu->regs[0] - 1ULL;
    PB_STRB((cpu->regs[0] + -1), cpu->regs[2]);
    goto L_168c84;
L_168d74:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_168e0c;
    if (((cpu->regs[1] >> 5) & 1)) goto L_168e70;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[22] << 2);
L_168d88:
    cpu->regs[2] = cpu->regs[1] - 4ULL;
    if ((cpu->regs[20])!=0) goto L_168f00;
    cpu->regs[3] = 48ULL;
    PB_STRW((cpu->regs[1] + -4), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[2];
L_168d9c:
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_168dc4;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(16ULL)));
    if (FLAG_EQ) goto L_169028;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(8ULL)));
    cpu->regs[3] = 111ULL;
    cpu->regs[1] = 98ULL;
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[1];
L_168db8:
    cpu->regs[1] = cpu->regs[2] - 8ULL;
    cpu->regs[4] = 48ULL;
    PB_STRW((cpu->regs[2] + -8), cpu->regs[4]); PB_STRW((cpu->regs[2] + -8) + 4, cpu->regs[3]);
L_168dc4:
    FLAG_CMP(cpu->regs[27], 2ULL);
    if (FLAG_NE) goto L_1688b0;
    cpu->regs[2] = 45ULL;
    PB_STRW((cpu->regs[1] + -4), cpu->regs[2]);
    if ((cpu->regs[25])==0) goto L_1688b4;
    goto L_16895c;
L_168ddc:
    PB_LDR(cpu->regs[8], (cpu->regs[0] + 56));
    goto L_168bd8;
L_168de4:
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 32));
    if (FLAG_EQ) goto L_168ea4;
    if (((cpu->regs[3] >> 5) & 1)) goto L_168eb8;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 56));
L_168e00:
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[2] + (cpu->regs[1] << 2);
    goto L_168d88;
L_168e0c:
    if (((cpu->regs[1] >> 5) & 1)) goto L_168ee8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[22] << 1);
L_168e18:
    cpu->regs[2] = cpu->regs[1] - 2ULL;
    if ((cpu->regs[20])!=0) goto L_168f88;
    cpu->regs[3] = 48ULL;
    PB_STRH((cpu->regs[1] + -2), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[2];
L_168e2c:
    if ((((uint32_t)(cpu->regs[26])))==0) goto L_168e58;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(16ULL)));
    if (FLAG_EQ) goto L_169008;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(8ULL)));
    cpu->regs[3] = 111ULL;
    cpu->regs[1] = 98ULL;
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[1];
L_168e48:
    cpu->regs[1] = cpu->regs[2] - 4ULL;
    cpu->regs[4] = 48ULL;
    PB_STRH((cpu->regs[2] + -4), cpu->regs[4]);
    PB_STRH((cpu->regs[2] + -2), cpu->regs[3]);
L_168e58:
    FLAG_CMP(cpu->regs[27], 2ULL);
    if (FLAG_NE) goto L_1688b0;
    cpu->regs[2] = 45ULL;
    PB_STRH((cpu->regs[1] + -2), cpu->regs[2]);
    if ((cpu->regs[25])==0) goto L_1688b4;
    goto L_16895c;
L_168e70:
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[1] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[22] << 2);
    goto L_168d88;
L_168e88:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_168e8c:
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = 2051ULL;
    cpu->regs[0] = cpu->regs[0] + 408ULL;
    cpu->regs[30] = PB_BASE + 0x168e9cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1688d0;
L_168ea4:
    if (((cpu->regs[3] >> 5) & 1)) goto L_168f74;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 56));
L_168eac:
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[1] = cpu->regs[2] + (cpu->regs[1] << 1);
    goto L_168e18;
L_168eb8:
    FLAG_CMP((((uint32_t)(cpu->regs[3]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[3] = cpu->regs[2] + 40ULL;
    cpu->regs[2] = cpu->regs[2] + 56ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[3];
    goto L_168e00;
L_168ecc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 1168ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x168ee4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_168cc4;
L_168ee8:
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[1] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[22] << 1);
    goto L_168e18;
L_168f00:
    cpu->regs[21] = cpu->regs[21] + 24ULL;
    cpu->regs[3] = cpu->regs[20] - 1ULL;
    cpu->regs[7] = ((uint32_t)(cpu->regs[24] - 1ULL));
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[11] = 87ULL;
    cpu->regs[10] = 48ULL;
L_168f20:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (cpu->regs[6] << 2)));
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[5] & 63);
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] + 30ULL));
    cpu->regs[4] = cpu->regs[4] | cpu->regs[1];
L_168f30:
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] & cpu->regs[4]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - cpu->regs[19]));
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] & 255ULL));
    cpu->regs[1] = cpu->regs[2];
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(9ULL)));
    cpu->regs[4] = cpu->regs[4] >> (cpu->regs[19] & 63);
    cpu->regs[8] = (FLAG_HI) ? cpu->regs[11] : cpu->regs[10];
    cpu->regs[8] = ((uint32_t)(cpu->regs[8] + cpu->regs[9]));
    cpu->regs[8] = ((uint64_t)(int64_t)(int8_t)(cpu->regs[8]));
    PB_STRW((cpu->regs[2] + 0), cpu->regs[8]);
    FLAG_CMP(cpu->regs[6], cpu->regs[3]);
    if (FLAG_GE) goto L_168ff8;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[5])));
    cpu->regs[8] = (FLAG_LE) ? 1 : 0;
    if ((((uint32_t)(cpu->regs[8])))==0) goto L_169030;
L_168f6c:
    cpu->regs[2] = cpu->regs[2] - 4ULL;
    goto L_168f30;
L_168f74:
    FLAG_CMP((((uint32_t)(cpu->regs[3]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[3] = cpu->regs[2] + 40ULL;
    cpu->regs[2] = cpu->regs[2] + 56ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[2] : cpu->regs[3];
    goto L_168eac;
L_168f88:
    cpu->regs[21] = cpu->regs[21] + 24ULL;
    cpu->regs[3] = cpu->regs[20] - 1ULL;
    cpu->regs[7] = ((uint32_t)(cpu->regs[24] - 1ULL));
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[11] = 87ULL;
    cpu->regs[10] = 48ULL;
L_168fa8:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + (cpu->regs[6] << 2)));
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[5] & 63);
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] + 30ULL));
    cpu->regs[4] = cpu->regs[4] | cpu->regs[1];
L_168fb8:
    cpu->regs[9] = ((uint32_t)(cpu->regs[7] & cpu->regs[4]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] - cpu->regs[19]));
    cpu->regs[9] = ((uint32_t)(cpu->regs[9] & 255ULL));
    cpu->regs[1] = cpu->regs[2];
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(9ULL)));
    cpu->regs[4] = cpu->regs[4] >> (cpu->regs[19] & 63);
    cpu->regs[8] = (FLAG_HI) ? cpu->regs[11] : cpu->regs[10];
    cpu->regs[8] = ((uint32_t)(cpu->regs[8] + cpu->regs[9]));
    cpu->regs[8] = ((uint64_t)(int64_t)(int8_t)(cpu->regs[8]));
    PB_STRH((cpu->regs[2] + 0), cpu->regs[8]);
    FLAG_CMP(cpu->regs[6], cpu->regs[3]);
    if (FLAG_GE) goto L_169010;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_GT) goto L_169014;
L_168ff0:
    cpu->regs[2] = cpu->regs[2] - 2ULL;
    goto L_168fb8;
L_168ff8:
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[8] = (FLAG_NE) ? 1 : 0;
    if ((((uint32_t)(cpu->regs[8])))!=0) goto L_168f6c;
    goto L_169030;
L_169008:
    cpu->regs[3] = 120ULL;
    goto L_168e48;
L_169010:
    if ((cpu->regs[4])!=0) goto L_168ff0;
L_169014:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[6]);
    if (FLAG_LE) goto L_168e2c;
    cpu->regs[2] = cpu->regs[2] - 2ULL;
    goto L_168fa8;
L_169028:
    cpu->regs[3] = 120ULL;
    goto L_168db8;
L_169030:
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[6]);
    if (FLAG_LE) goto L_168d9c;
    cpu->regs[2] = cpu->regs[2] - 4ULL;
    goto L_168f20;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16908c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[7] = 63392ULL;
    cpu->regs[3] = cpu->regs[0] + (4ULL << 12);
    cpu->regs[2] = cpu->regs[0] + cpu->regs[7];
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 8080));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_169190;
    cpu->regs[2] = PB_BASE + 0x2b8000ULL;
    cpu->regs[2] = cpu->regs[2] + 2096ULL;
    cpu->regs[2] = cpu->regs[2] + 1672ULL;
    cpu->regs[6] = 24464ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[6];
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]); PB_STR((cpu->regs[1] + 8) + 8, cpu->regs[2]);
L_169084:
    cpu->regs[0] = 0ULL;
    return;
L_16908c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(96ULL)));
    if (FLAG_HI) goto L_169150;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(94ULL)));
    if (FLAG_HI) goto L_169104;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(44ULL)));
    if (FLAG_NE) goto L_1690f4;
    cpu->regs[0] = 46ULL;
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1690c0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1db3c0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1690d0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x15d988ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1691b4;
L_1690e8:
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[0] + 1288ULL;
    PB_STR((cpu->regs[1] + 16), cpu->regs[0]);
L_1690f4:
    cpu->regs[0] = 0ULL;
L_1690f8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_169104:
    cpu->regs[0] = 46ULL;
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x169110ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1db3c0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    cpu->regs[0] = 95ULL;
    cpu->regs[30] = PB_BASE + 0x169120ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x15d988ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1691b4;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(96ULL)));
    if (FLAG_NE) goto L_1690e8;
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[0] = cpu->regs[0] + 1296ULL;
    PB_STR((cpu->regs[1] + 16), cpu->regs[0]);
    goto L_1690f4;
L_169150:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(97ULL)));
    if (FLAG_NE) goto L_1690f4;
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x169160ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c1f0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[1] + 8ULL;
    cpu->regs[30] = PB_BASE + 0x169170ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x25bb28ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1691b4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x16917cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x2264c0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_STR((cpu->regs[1] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1691b0;
    PB_STR((cpu->regs[1] + 16), cpu->regs[0]);
    goto L_1690f4;
L_169190:
    cpu->regs[4] = PB_BASE + 0x2b8000ULL;
    cpu->regs[4] = cpu->regs[4] + 2096ULL;
    PB_STRW((cpu->regs[3] + 8080), cpu->regs[2]);
    cpu->regs[5] = 24464ULL;
    cpu->regs[2] = cpu->regs[4] + 1672ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[5];
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]); PB_STR((cpu->regs[1] + 8) + 8, cpu->regs[2]);
    goto L_169084;
L_1691b0:
    cpu->regs[30] = PB_BASE + 0x1691b4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1691b4:
    cpu->regs[0] = 4294967295ULL;
    goto L_1690f8;
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 32));
    if ((cpu->regs[22])==0) goto L_169308;
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_169310;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1694b8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_169298;
L_169204:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = PB_BASE + 0xe8000ULL;
    cpu->regs[24] = cpu->regs[20] + 24ULL;
    cpu->regs[23] = cpu->regs[23] + 256ULL;
    cpu->regs[19] = 0ULL;
L_169218:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[19] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[1], cpu->regs[23]);
    if (FLAG_NE) goto L_1692b4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_1692e8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_GE) goto L_1692d0;
    cpu->regs[1] = cpu->regs[1] + (cpu->regs[2] << 3);
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_STR((cpu->regs[0] + 16), cpu->regs[2]);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_16926c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_16926c:
    PB_LDR(cpu->regs[2], (cpu->regs[24] + (cpu->regs[19] << 3)));
    PB_STR((cpu->regs[24] + (cpu->regs[19] << 3)), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_169288;
L_16927c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_169388;
L_169288:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_NE) goto L_169218;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_169298:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + -16));
    if ((cpu->regs[0])==0) goto L_16937c;
L_1692a0:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1692b4:
    cpu->regs[30] = PB_BASE + 0x1692b8ULL; PB_CALL(17, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_1692e8;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + (cpu->regs[19] << 3)));
    PB_STR((cpu->regs[24] + (cpu->regs[19] << 3)), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_16927c;
    goto L_169288;
L_1692d0:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[0] + 24), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_1692e8;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_169370;
L_1692e8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1692fc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_169364;
L_1692fc:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 40));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_169394;
L_169304:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_169308:
    cpu->regs[20] = 0ULL;
    goto L_1692a0;
L_169310:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x169318ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_169308;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0] + 24ULL;
    cpu->regs[19] = 0ULL;
L_16932c:
    FLAG_CMP(cpu->regs[19], cpu->regs[22]);
    if (FLAG_GE) goto L_16935c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[19] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x16934cULL; PB_CALL(19, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_1692e8;
    PB_STR((cpu->regs[23] + (cpu->regs[19] << 3)), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_16932c;
L_16935c:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1692a0;
L_169364:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16936cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1692fc;
L_169370:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x169378ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1692e8;
L_16937c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x169384ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_1692a0;
L_169388:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x169390ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_169288;
L_169394:
    cpu->regs[30] = PB_BASE + 0x169398ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_16949c;
L_16939c:
    cpu->regs[20] = 1ULL;
    if ((cpu->regs[19])!=0) goto L_169458;
L_1693a4:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_GE) goto L_169304;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[20] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x1693c4ULL; PB_CALL(25, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])!=0) goto L_1693f8;
    cpu->regs[30] = PB_BASE + 0x1693ccULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1693d8;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_1693a4;
L_1693d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1693e8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_169304;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1693f4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1693a4;
L_1693f8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_16940c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_169450;
L_16940c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    FLAG_CMP(cpu->regs[20], 1ULL);
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 1688ULL;
    cpu->regs[3] = cpu->regs[3] + 1304ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[1];
    cpu->regs[4] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[20] + 1ULL;
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1360ULL;
    cpu->regs[30] = PB_BASE + 0x169448ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1692a0;
L_169450:
    cpu->regs[30] = PB_BASE + 0x169454ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16940c;
L_169458:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 1688ULL;
    cpu->regs[3] = cpu->regs[3] + 1304ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[1];
    cpu->regs[2] = cpu->regs[19] + cpu->regs[20];
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1312ULL;
    cpu->regs[30] = PB_BASE + 0x169494ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1692a0;
L_16949c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1694acULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_169304;
    cpu->regs[30] = PB_BASE + 0x1694b4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_16939c;
L_1694b8:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GT) goto L_169204;
    goto L_169298;
    SP = SP - 96ULL;
    cpu->regs[4] = cpu->regs[4] - cpu->regs[3];
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3080));
    cpu->regs[4] = cpu->regs[4] - cpu->regs[5];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[7];
    PB_LDR(cpu->regs[22], (SP + 96)); PB_LDR(cpu->regs[21], (SP + 96) + 8);
    PB_LDR(cpu->regs[9], (cpu->regs[8] + 0));
    PB_STR((SP + 24), cpu->regs[9]);
    cpu->regs[9] = 0ULL;
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1696d4;
    PB_STRB((cpu->regs[0] + 32), 0ULL);
    cpu->regs[20] = 0ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 16));
    PB_STR((cpu->regs[19] + 0), 0ULL); PB_STR((cpu->regs[19] + 0) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[19] + 16), 0ULL); PB_STR((cpu->regs[19] + 16) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 40), 0ULL);
    PB_STR((cpu->regs[19] + 56), 0ULL); PB_STR((cpu->regs[19] + 56) + 8, cpu->regs[5]);
    PB_STR((cpu->regs[19] + 72), cpu->regs[4]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32ULL)));
    if (FLAG_EQ) goto L_169704;
L_169530:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(43ULL)));
    if (FLAG_EQ) goto L_1696a8;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(45ULL)));
    if (FLAG_EQ) goto L_169754;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[20] = cpu->regs[20] + cpu->regs[5];
L_169548:
    cpu->regs[0] = 48ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[1];
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 32)) | ((0x3dULL & 0xffff) << 32);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_169644;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    cpu->regs[5] = cpu->regs[0] - cpu->regs[20];
    PB_STR((cpu->regs[19] + 80), cpu->regs[5]);
    if ((cpu->regs[4])==0) goto L_169654;
L_16956c:
    PB_LDR(cpu->regs[7], (cpu->regs[23] + 8)); PB_LDR(cpu->regs[6], (cpu->regs[23] + 8) + 8);
    cpu->regs[0] = SP + 20ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x16958cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1697e8ULL);
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_169610;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + 0));
    PB_LDRW(cpu->regs[3], (SP + 20));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[3])));
    cpu->regs[2] = (FLAG_HS) ? cpu->regs[2] : cpu->regs[3];
    PB_STRW((cpu->regs[21] + 0), cpu->regs[2]);
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_GT) goto L_169668;
L_1695c0:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[4], (cpu->regs[19] + 16) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[5] = cpu->regs[1] | cpu->regs[3];
    cpu->regs[5] = cpu->regs[5] | cpu->regs[4];
    if ((cpu->regs[5])!=0) goto L_16967c;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 56));
    if ((cpu->regs[6])!=0) goto L_16971c;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1695e8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 64));
    cpu->regs[2] = cpu->regs[2] + cpu->regs[7];
    cpu->regs[2] = cpu->regs[2] + cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[5];
    cpu->regs[2] = cpu->regs[2] + cpu->regs[4];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[6];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] + cpu->regs[2];
L_169610:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1696d0;
    PB_LDR(cpu->regs[23], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_169644:
    PB_STR((cpu->regs[19] + 80), 0ULL);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[4])!=0) goto L_16956c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
L_169654:
    cpu->regs[1] = cpu->regs[0] - cpu->regs[20];
    PB_STR((cpu->regs[19] + 48), 0ULL);
    cpu->regs[0] = 0ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_1695c0;
L_169668:
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 4));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(62ULL)));
    if (FLAG_NE) goto L_16975c;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[4], (cpu->regs[19] + 16) + 8);
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
L_16967c:
    PB_LDRW(cpu->regs[5], (cpu->regs[22] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(cpu->regs[2])));
    cpu->regs[2] = (FLAG_HS) ? cpu->regs[5] : cpu->regs[2];
    PB_STRW((cpu->regs[21] + 0), cpu->regs[2]);
    cpu->regs[5] = cpu->regs[1];
    if ((cpu->regs[6])!=0) goto L_169728;
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[2] = 0ULL;
    goto L_1695e8;
L_1696a8:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(45ULL)));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[2] = 45ULL;
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[2];
L_1696b8:
    PB_STRB((cpu->regs[19] + 32), cpu->regs[2]);
    cpu->regs[0] = 1ULL;
    cpu->regs[20] = cpu->regs[20] + cpu->regs[5];
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
    goto L_169548;
L_1696d0:
    cpu->regs[30] = PB_BASE + 0x1696d4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1696d4:
    PB_LDR(cpu->regs[0], (cpu->regs[7] + 0));
    PB_STR((cpu->regs[19] + 0), 0ULL); PB_STR((cpu->regs[19] + 0) + 8, cpu->regs[1]);
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    PB_STRB((cpu->regs[19] + 32), 0ULL);
    PB_STR((cpu->regs[19] + 16), 0ULL); PB_STR((cpu->regs[19] + 16) + 8, 0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 16));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    PB_STR((cpu->regs[19] + 56), cpu->regs[20]); PB_STR((cpu->regs[19] + 56) + 8, cpu->regs[5]);
    PB_STR((cpu->regs[19] + 72), cpu->regs[4]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32ULL)));
    if (FLAG_NE) goto L_169530;
L_169704:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(45ULL)));
    cpu->regs[0] = 45ULL;
    cpu->regs[2] = 32ULL;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[0];
    goto L_1696b8;
L_16971c:
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
L_169728:
    PB_LDR(cpu->regs[7], (cpu->regs[23] + 0));
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 32));
    if (!((cpu->regs[7] >> 6) & 1)) goto L_169798;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(127ULL)));
    cpu->regs[2] = 127ULL;
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[1] : cpu->regs[2];
L_169744:
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[6] = cpu->regs[5];
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
    goto L_1695e8;
L_169754:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_1696b8;
L_16975c:
    if (FLAG_HI) goto L_169784;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(60ULL)));
    if (FLAG_NE) goto L_169770;
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    goto L_1695c0;
L_169770:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 24));
    cpu->regs[3] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[3]);
    goto L_16967c;
L_169784:
    cpu->regs[2] = (uint64_t)((int64_t)cpu->regs[1] >> 1);
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2];
    PB_STR((cpu->regs[19] + 24), cpu->regs[1]);
    goto L_1695c0;
L_169798:
    cpu->regs[7] = ((uint32_t)(((cpu->regs[7] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1697d8;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(2ULL)));
    cpu->regs[8] = 65535ULL;
    cpu->regs[9] = 1114111ULL;
    cpu->regs[8] = (FLAG_EQ) ? cpu->regs[8] : cpu->regs[9];
L_1697b4:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[8])));
    if (FLAG_HI) goto L_169744;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1697e0;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(2ULL)));
    cpu->regs[1] = 65535ULL;
    cpu->regs[2] = 1114111ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    goto L_169744;
L_1697d8:
    cpu->regs[8] = 255ULL;
    goto L_1697b4;
L_1697e0:
    cpu->regs[1] = 255ULL;
    goto L_169744;
}
