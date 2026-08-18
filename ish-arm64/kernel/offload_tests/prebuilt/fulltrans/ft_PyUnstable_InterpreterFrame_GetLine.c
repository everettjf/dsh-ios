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

void ft_PyUnstable_InterpreterFrame_GetLine(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 56));
    cpu->regs[1] = cpu->regs[0] + 192ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] - cpu->regs[1]));
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x1fcf30ULL); return; };
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x2273ecULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d53a0ULL);
    if ((cpu->regs[0])==0) goto L_227454;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])!=0) goto L_22745c;
L_227400:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])!=0) goto L_227430;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
L_22740c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_22741c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_227490;
L_22741c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_227428:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_227430:
    cpu->regs[30] = PB_BASE + 0x227434ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_22740c;
    if (((cpu->regs[1] >> 31) & 1)) goto L_227450;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22747c;
L_227450:
    PB_LDR(cpu->regs[19], (SP + 16));
L_227454:
    cpu->regs[0] = 0ULL;
    goto L_227428;
L_22745c:
    cpu->regs[30] = PB_BASE + 0x227460ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5760ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_227400;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_227450;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_227450;
L_22747c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x227484ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    goto L_227428;
L_227490:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x227498ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22741c;
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3];
    if ((cpu->regs[3])!=0) goto L_22760c;
    if (((cpu->regs[2] >> 63) & 1)) goto L_227558;
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[19] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_227614;
L_2274e4:
    if ((cpu->regs[19])!=0) goto L_227588;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x2274fcULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = 2ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
L_227504:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    cpu->regs[19] = cpu->regs[19] + 112ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 200));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_227604;
    cpu->regs[2] = 1ULL;
    PB_STRW((cpu->regs[19] + 200), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x227520ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x196c00ULL);
    PB_STRW((cpu->regs[19] + 200), 0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2275f4;
L_22752c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2275c0;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_227558:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 2336ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x227584ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_2275a4;
L_227588:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x227590ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_227660;
    cpu->regs[30] = PB_BASE + 0x2275a0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_2275c4;
L_2275a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_22764c;
L_2275c0:
    cpu->regs[30] = PB_BASE + 0x2275c4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2275c4:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x2275d8ULL; PB_CALL(14, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
L_2275dc:
    cpu->regs[2] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[2] = cpu->regs[2] + 728ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x2275f4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5980ULL);
L_2275f4:
    cpu->regs[30] = PB_BASE + 0x2275f8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_2275a4;
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_22752c;
L_227604:
    cpu->regs[0] = 0ULL;
    goto L_22752c;
L_22760c:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    cpu->regs[19] = cpu->regs[2] + cpu->regs[19];
L_227614:
    cpu->regs[3] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[4] + 2336ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x227644ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_2274e4;
    goto L_2275a4;
L_22764c:
    PB_LDR(cpu->regs[19], (SP + 48));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_227660:
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x227674ULL; PB_CALL(18, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_LS) goto L_227504;
    goto L_2275dc;
    if ((cpu->regs[2])==0) goto L_22779c;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0] + 3896ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_EQ) goto L_227794;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 60424ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[23] + cpu->regs[1];
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x2276c8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1977e4ULL);
    if ((cpu->regs[0])==0) goto L_227724;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_227724;
    cpu->regs[30] = PB_BASE + 0x2276e4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x129680ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_227724;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2276fcULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])!=0) goto L_2277c8;
    cpu->regs[30] = PB_BASE + 0x227704ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_22778c;
L_227708:
    cpu->regs[0] = 0ULL;
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_2277a4;
L_227710:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_227718:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_227724:
    cpu->regs[30] = PB_BASE + 0x227728ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_22778c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x227734ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1c17e0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x22773cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22778c;
    cpu->regs[0] = 60424ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x227758ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22777c;
    if (((cpu->regs[1] >> 31) & 1)) goto L_227708;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_227708;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x227778ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_227708;
L_22777c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_22778c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2277d4;
L_22778c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_227794:
    cpu->regs[0] = 4294967295ULL;
    goto L_227718;
L_22779c:
    cpu->regs[0] = 4294967295ULL;
    return;
L_2277a4:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3664));
    { PB_CALL(28, cpu, tlb, PB_BASE + 0xddf30ULL); return; };
L_2277c8:
    cpu->regs[30] = PB_BASE + 0x2277ccULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1227a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_227708;
    goto L_227710;
L_2277d4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2277dcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_227718;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x2277f8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x7ae60ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
