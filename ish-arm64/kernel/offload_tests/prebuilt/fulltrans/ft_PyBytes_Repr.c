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

void ft_PyBytes_Repr(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_LE) goto L_15d42c;
    cpu->regs[3] = cpu->regs[0] + 32ULL;
    cpu->regs[6] = 9223372036854775806ULL;
    cpu->regs[7] = cpu->regs[3] + cpu->regs[21];
    cpu->regs[5] = cpu->regs[6] - 3ULL;
    cpu->regs[10] = 0ULL;
    cpu->regs[9] = 0ULL;
    cpu->regs[0] = 3ULL;
    cpu->regs[8] = 4ULL;
    if (!((cpu->regs[21] >> 0) & 1)) goto L_15d33c;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_15d4a8;
    if (FLAG_LS) goto L_15d3c4;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_15d4a8;
    if (FLAG_HI) goto L_15d1b0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_15d4b0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(39ULL)));
    if (FLAG_EQ) goto L_15d4bc;
L_15d1b0:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 32ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(95ULL)));
    cpu->regs[2] = (FLAG_LO) ? cpu->regs[6] : cpu->regs[5];
    cpu->regs[4] = (FLAG_HS) ? cpu->regs[8] : (0ULL + 1);
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_LT) goto L_15d4d0;
L_15d1cc:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = cpu->regs[4] + 3ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_NE) goto L_15d33c;
L_15d1dc:
    FLAG_CMP(cpu->regs[9], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[10], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_15d488;
    cpu->regs[20] = 39ULL;
    if ((cpu->regs[9])!=0) goto L_15d490;
L_15d1f4:
    cpu->regs[1] = 127ULL;
    cpu->regs[30] = PB_BASE + 0x15d1fcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    if ((cpu->regs[0])==0) goto L_15d4e8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_15d4c8;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[2] = cpu->regs[0] + 40ULL;
    cpu->regs[1] = cpu->regs[0] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
L_15d218:
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = 98ULL;
    PB_STRB(cpu->regs[2], cpu->regs[3]); cpu->regs[2] += 2;
    PB_STRB((cpu->regs[1] + 1), cpu->regs[20]);
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_LE) goto L_15d3b0;
    cpu->regs[3] = cpu->regs[19] + 32ULL;
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2576));
    cpu->regs[8] = cpu->regs[3] + cpu->regs[21];
    cpu->regs[9] = 30812ULL;
L_15d248:
    PB_LDRB(cpu->regs[1], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(92ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[20]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_15d438;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(9ULL)));
    if (FLAG_EQ) goto L_15d3fc;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(10ULL)));
    if (FLAG_EQ) goto L_15d41c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_15d40c;
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] - 32ULL));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(94ULL)));
    if (FLAG_LS) goto L_15d39c;
    PB_STRH((cpu->regs[2] + 0), cpu->regs[9]);
    cpu->regs[4] = ((cpu->regs[1] >> 4) & 0xfULL);
    cpu->regs[1] = cpu->regs[1] & 15ULL;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 0));
    cpu->regs[2] = cpu->regs[2] + 4ULL;
    PB_LDRB(cpu->regs[4], (cpu->regs[7] + cpu->regs[4]));
    PB_STRB((cpu->regs[2] + -2), cpu->regs[4]);
    PB_LDR(cpu->regs[4], (cpu->regs[6] + 0));
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + cpu->regs[1]));
    PB_STRB((cpu->regs[5] + 3), cpu->regs[1]);
    FLAG_CMP(cpu->regs[3], cpu->regs[8]);
    if (FLAG_EQ) goto L_15d3b0;
L_15d2b4:
    cpu->regs[5] = cpu->regs[2];
    goto L_15d248;
L_15d2bc:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 9ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_15d3dc;
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[4] = 4ULL;
L_15d2d4:
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LT) goto L_15d4d0;
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 1));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_15d3ec;
    if (FLAG_LS) goto L_15d380;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_15d3ec;
    if (FLAG_HI) goto L_15d310;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_15d448;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(39ULL)));
    if (FLAG_EQ) goto L_15d468;
L_15d310:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 32ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(95ULL)));
    cpu->regs[2] = (FLAG_LO) ? cpu->regs[6] : cpu->regs[5];
    cpu->regs[4] = (FLAG_HS) ? cpu->regs[8] : (0ULL + 1);
L_15d324:
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LT) goto L_15d4d0;
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    FLAG_CMP(cpu->regs[3], cpu->regs[7]);
    if (FLAG_EQ) goto L_15d1dc;
L_15d33c:
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_15d3dc;
    if (FLAG_LS) goto L_15d2bc;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(92ULL)));
    if (FLAG_EQ) goto L_15d3dc;
    if (FLAG_HI) goto L_15d368;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(34ULL)));
    if (FLAG_EQ) goto L_15d458;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(39ULL)));
    if (FLAG_EQ) goto L_15d478;
L_15d368:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 32ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(95ULL)));
    cpu->regs[2] = (FLAG_LO) ? cpu->regs[6] : cpu->regs[5];
    cpu->regs[4] = (FLAG_HS) ? cpu->regs[8] : (0ULL + 1);
    goto L_15d2d4;
L_15d380:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 9ULL));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_15d3ec;
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[4] = 4ULL;
    goto L_15d324;
L_15d39c:
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STRB((cpu->regs[5] + 0), cpu->regs[1]);
L_15d3a4:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[8], cpu->regs[3]);
    if (FLAG_NE) goto L_15d2b4;
L_15d3b0:
    PB_STRB((cpu->regs[2] + 0), cpu->regs[20]);
L_15d3b4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_15d3c4:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 9ULL));
    cpu->regs[4] = 2ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    cpu->regs[4] = (FLAG_HS) ? cpu->regs[8] : cpu->regs[4];
    goto L_15d1cc;
L_15d3dc:
    cpu->regs[2] = 18446744073709551613ULL;
    cpu->regs[4] = 2ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_15d2d4;
L_15d3ec:
    cpu->regs[2] = 18446744073709551613ULL;
    cpu->regs[4] = 2ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_15d324;
L_15d3fc:
    cpu->regs[1] = 29788ULL;
    cpu->regs[2] = cpu->regs[2] + 2ULL;
    PB_STRH((cpu->regs[5] + 0), cpu->regs[1]);
    goto L_15d3a4;
L_15d40c:
    cpu->regs[1] = 29276ULL;
    cpu->regs[2] = cpu->regs[2] + 2ULL;
    PB_STRH((cpu->regs[5] + 0), cpu->regs[1]);
    goto L_15d3a4;
L_15d41c:
    cpu->regs[1] = 28252ULL;
    cpu->regs[2] = cpu->regs[2] + 2ULL;
    PB_STRH((cpu->regs[5] + 0), cpu->regs[1]);
    goto L_15d3a4;
L_15d42c:
    cpu->regs[20] = 39ULL;
    cpu->regs[0] = 3ULL;
    goto L_15d1f4;
L_15d438:
    cpu->regs[4] = 92ULL;
    PB_STRB(cpu->regs[2], cpu->regs[4]); cpu->regs[2] += 2;
    PB_STRB((cpu->regs[5] + 1), cpu->regs[1]);
    goto L_15d3a4;
L_15d448:
    cpu->regs[10] = cpu->regs[10] + 1ULL;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[4] = 1ULL;
    goto L_15d324;
L_15d458:
    cpu->regs[10] = cpu->regs[10] + 1ULL;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[4] = 1ULL;
    goto L_15d2d4;
L_15d468:
    cpu->regs[9] = cpu->regs[9] + 1ULL;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[4] = 1ULL;
    goto L_15d324;
L_15d478:
    cpu->regs[9] = cpu->regs[9] + 1ULL;
    cpu->regs[2] = 9223372036854775806ULL;
    cpu->regs[4] = 1ULL;
    goto L_15d2d4;
L_15d488:
    cpu->regs[20] = 34ULL;
    goto L_15d1f4;
L_15d490:
    cpu->regs[1] = 9223372036854775807ULL;
    cpu->regs[1] = cpu->regs[1] - cpu->regs[9];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LT) goto L_15d4d0;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[9];
    goto L_15d1f4;
L_15d4a8:
    cpu->regs[4] = 2ULL;
    goto L_15d1cc;
L_15d4b0:
    cpu->regs[10] = 1ULL;
    cpu->regs[4] = cpu->regs[10];
    goto L_15d1cc;
L_15d4bc:
    cpu->regs[9] = 1ULL;
    cpu->regs[4] = cpu->regs[9];
    goto L_15d1cc;
L_15d4c8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
    goto L_15d218;
L_15d4d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 3400ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x15d4e8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_15d4e8:
    cpu->regs[0] = 0ULL;
    goto L_15d3b4;
    goto L_15d500;
    /* nop */
    /* nop */
    /* nop */
L_15d500:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] >> 3;
    if ((cpu->regs[1])==0) goto L_15d620;
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[1] << 2);
    cpu->regs[3] = cpu->regs[1] - 1ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 20));
    if ((cpu->regs[2])==0) goto L_15d640;
    cpu->regs[2] = (((uint64_t)(cpu->regs[2])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[2])));
    cpu->regs[0] = 4919131752989213764ULL;
    cpu->regs[20] = 64ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x444ULL & 0xffff) << 48);
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] - cpu->regs[2]));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HI) goto L_15d654;
L_15d544:
    cpu->regs[19] = cpu->regs[3] << 4;
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[19] = cpu->regs[19] - cpu->regs[3];
    cpu->regs[19] = cpu->regs[20] + (cpu->regs[19] << 1);
    cpu->regs[0] = cpu->regs[19] + 5ULL;
    FLAG_CMP(cpu->regs[0], 261ULL);
    if (FLAG_HI) goto L_15d588;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 5ULL));
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[19] = ((cpu->regs[19] & 0xffffffffULL) << 5);
    cpu->regs[19] = cpu->regs[19] + 3048ULL;
    cpu->regs[20] = cpu->regs[19] + cpu->regs[20];
L_15d578:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_15d588:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[19] >> 30;
    if ((cpu->regs[22])!=0) goto L_15d5c4;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x15d59cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d718;
    cpu->regs[0] = 8ULL;
    PB_STR((cpu->regs[20] + 16), cpu->regs[0]);
    PB_STRW((cpu->regs[20] + 24), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_15d5c4:
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[19] >> 60;
    FLAG_CMP(cpu->regs[23], 0ULL);
    cpu->regs[21] = (FLAG_NE) ? 1 : 0;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] + 2ULL));
    cpu->regs[21] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[21]));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15d5e4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d630;
    cpu->regs[21] = cpu->regs[21] << 3;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] & 1073741823ULL));
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] & 1073741823ULL));
    PB_STR((cpu->regs[0] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[0] + 24), cpu->regs[19]); PB_STRW((cpu->regs[0] + 24) + 4, cpu->regs[22]);
    if ((cpu->regs[23])!=0) goto L_15d610;
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_15d578;
L_15d610:
    PB_STRW((cpu->regs[20] + 32), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_15d578;
L_15d620:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[20] = cpu->regs[20] + 3208ULL;
    goto L_15d578;
L_15d630:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_15d638:
    cpu->regs[20] = 0ULL;
    goto L_15d578;
L_15d640:
    cpu->regs[0] = 4919131752989213764ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x444ULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LS) goto L_15d544;
L_15d654:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x15d65cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d638;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[1] = 4168ULL;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[1] = cpu->regs[22] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x15d67cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 4168));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_15d694;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 4168), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15d724;
L_15d694:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[21])==0) goto L_15d704;
    if (((cpu->regs[0] >> 31) & 1)) goto L_15d6ac;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15d748;
L_15d6ac:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    cpu->regs[30] = PB_BASE + 0x15d6b4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d700;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15d6c8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1484c0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15d6e0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15d754;
L_15d6e0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if ((cpu->regs[20])==0) goto L_15d700;
    if (((cpu->regs[0] >> 31) & 1)) goto L_15d6f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15d760;
L_15d6f8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_15d578;
L_15d700:
    cpu->regs[19] = cpu->regs[21];
L_15d704:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15d718;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15d734;
L_15d718:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[20] = 0ULL;
    goto L_15d578;
L_15d724:
    cpu->regs[0] = 4168ULL;
    cpu->regs[0] = cpu->regs[22] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x15d730ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15d694;
L_15d734:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15d740ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_15d578;
L_15d748:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15d750ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15d6ac;
L_15d754:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15d75cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15d6e0;
L_15d760:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15d768ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_15d578;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[3] = PB_BASE + 0x294000ULL;
    cpu->regs[3] = cpu->regs[3] + 2976ULL;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x15bcecULL); return; };
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[1] + 24));
    cpu->regs[1] = cpu->regs[3] - cpu->regs[2];
    cpu->regs[2] = cpu->regs[4] & 3ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2];
    cpu->regs[0] = cpu->regs[1] * cpu->regs[5];
    cpu->regs[3] = cpu->regs[3] * cpu->regs[4];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    cpu->regs[0] = (FLAG_GT) ? 1 : 0;
    return;
    /* nop */
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_15d844;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_GE) goto L_15d810;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[2]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 5ULL));
    cpu->regs[1] = ((cpu->regs[1] & 0x1ffULL) << 5);
    cpu->regs[1] = cpu->regs[1] + 3048ULL;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[3];
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_15d84c;
    return;
L_15d810:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[0] + 24), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_15d844;
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15d844;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x15d838ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_15d844:
    cpu->regs[0] = 0ULL;
    return;
L_15d84c:
    PB_STRW((cpu->regs[3] + cpu->regs[1]), cpu->regs[2]);
    return;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = SP + 4ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15d88cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x129708ULL);
    PB_LDRW(cpu->regs[1], (SP + 4));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_15d948;
    cpu->regs[1] = 2147483648ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = 4294967295ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HI) goto L_15d948;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15d960;
    cpu->regs[1] = 1114111ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_HI) goto L_15d968;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_15d908;
    if (((cpu->regs[0] >> 7) & 1)) goto L_15d930;
    cpu->regs[3] = 48ULL;
    cpu->regs[2] = 61184ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = cpu->regs[2] + (uint64_t)(uint32_t)cpu->regs[0] * (uint64_t)(uint32_t)cpu->regs[3];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_15d8e0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_15d944;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_15d908:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_15d944;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    { PB_CALL(17, cpu, tlb, PB_BASE + 0x15190cULL); return; };
L_15d930:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 924ULL));
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[0] << 6);
    goto L_15d8e0;
L_15d944:
    cpu->regs[30] = PB_BASE + 0x15d948ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_15d948:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 336ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x15d960ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_15d960:
    cpu->regs[30] = PB_BASE + 0x15d964ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_15d980;
L_15d968:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 3784ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x15d980ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_15d980:
    cpu->regs[0] = 0ULL;
    goto L_15d8e0;
}
