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

void ft_PySequence_Length(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x1fd1e8ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xb9740ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b9760;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 1296ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb975cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b9770;
L_b9760:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xb9768ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1fd1e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if (!((cpu->regs[0] >> 63) & 1)) goto L_b9778;
L_b9770:
    cpu->regs[0] = 0ULL;
    goto L_b988c;
L_b9778:
    FLAG_CMP(cpu->regs[0], 65536ULL);
    if (FLAG_LE) goto L_b979c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 1336ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb9798ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b9770;
L_b979c:
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 2);
    cpu->regs[30] = PB_BASE + 0xb97a4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[21] = 0ULL;
L_b97ac:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_EQ) goto L_b9850;
    cpu->regs[30] = PB_BASE + 0xb97c0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x14d028ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b9870;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = cpu->regs[20] + (((cpu->regs[21]) & 0xffffffffULL) << 2);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (((cpu->regs[2] >> 24) & 1)) goto L_b9808;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 1352ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb97f0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b9870;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b9870;
    goto L_b9824;
L_b9808:
    cpu->regs[30] = PB_BASE + 0xb980cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xaa80cULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b9830;
    if (((cpu->regs[2] >> 31) & 1)) goto L_b9870;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_b9870;
L_b9824:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb982cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b9870;
L_b9830:
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    if (((cpu->regs[2] >> 31) & 1)) goto L_b9848;
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_b9848;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb9848ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9848:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_b97ac;
L_b9850:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb985cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c1b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_b987c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb9870ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_b9870:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb9878ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_b9770;
L_b987c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb9884ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_b988c:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_b98a0:
    SP = SP - 80ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[23]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_STR((cpu->regs[22] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0xb98e4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1fd1e8ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LT) goto L_b9ad0;
    if (FLAG_EQ) goto L_b9aac;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[2] = cpu->regs[2] + 3336ULL;
    cpu->regs[1] = cpu->regs[1] + 1376ULL;
    cpu->regs[30] = PB_BASE + 0xb990cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x22356cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b9ad0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3792));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xb9924ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b9944;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 1384ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xb9940ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_b9ab4;
L_b9944:
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 40));
    if ((cpu->regs[21])!=0) goto L_b9958;
L_b994c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 48));
    if ((cpu->regs[1])!=0) goto L_b99a4;
    goto L_b99b4;
L_b9958:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b9968;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_b9968:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb9978ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x12246cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[23] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9998;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9998;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb9998ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9998:
    FLAG_CMP(cpu->regs[23], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b994c;
    goto L_b9ab4;
L_b99a4:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b99b4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_b99b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    PB_STR((cpu->regs[19] + 48), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xb99c0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 56));
    if ((cpu->regs[1])==0) goto L_b99d8;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b99d8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_b99d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[2] = 1ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    PB_STR((cpu->regs[19] + 56), cpu->regs[1]);
    PB_STRB((cpu->regs[19] + 64), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0xb99f4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[1] = 31128ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = SP;
    cpu->regs[1] = cpu->regs[23] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xb9a08ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b9ab4;
    PB_LDR(cpu->regs[20], (SP + 0));
    if ((cpu->regs[20])==0) goto L_b9aa8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb9a20ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b9a8c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb9a2cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x14d3acULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9a4c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9a4c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb9a4cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9a4c:
    if ((cpu->regs[21])==0) goto L_b9ab4;
    cpu->regs[0] = 31128ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb9a64ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe28a0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9a84;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9a84;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb9a84ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9a84:
    if (!((cpu->regs[20] >> 31) & 1)) goto L_b9aa8;
    goto L_b9ab4;
L_b9a8c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b9aa8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b9aa8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb9aa8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9aa8:
    PB_STR((cpu->regs[22] + 0), cpu->regs[19]);
L_b9aac:
    cpu->regs[0] = 0ULL;
    goto L_b9ad4;
L_b9ab4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b9ad0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b9ad0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb9ad0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9ad0:
    cpu->regs[0] = 4294967295ULL;
L_b9ad4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_b9af4;
    cpu->regs[30] = PB_BASE + 0xb9af4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b9af4:
    PB_LDR(cpu->regs[23], (SP + 64));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_b9b0c:
    SP = SP - 176ULL;
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[2];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[4];
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[27] = ((uint32_t)(cpu->regs[3] & 255ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_STR((cpu->regs[4] + 0), 0ULL); PB_STR((cpu->regs[4] + 0) + 8, 0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_b9b7c;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_b9ba4;
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_b9c14;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xb9b74ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x121d90ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_b9bf8;
L_b9b7c:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xb9b88ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b9e90;
    cpu->regs[30] = PB_BASE + 0xb9b94ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b9be0;
    goto L_b9bf4;
L_b9ba4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3792));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xb9bb4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b9c14;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb9bc0ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe1564ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b9e90;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xb9bd4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x12ba40ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9bf4;
L_b9be0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9bf4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb9bf4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9bf4:
    if (((cpu->regs[21] >> 31) & 1)) goto L_b9e90;
L_b9bf8:
    if ((((uint32_t)(cpu->regs[21])))==0) goto L_b9c14;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b9c0c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_b9c0c:
    PB_STR((cpu->regs[20] + 0), cpu->regs[19]);
    goto L_b9c44;
L_b9c14:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3792));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xb9c28ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b9c4c;
    if (!((cpu->regs[27] >> 0) & 1)) goto L_b9c44;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b9c40;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_b9c40:
    PB_STR((cpu->regs[20] + 8), cpu->regs[19]);
L_b9c44:
    cpu->regs[0] = 0ULL;
    goto L_b9e94;
L_b9c4c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    cpu->regs[30] = PB_BASE + 0xb9c54ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x10e664ULL);
    cpu->regs[26] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_b9e90;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb9c64ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b9e90;
    cpu->regs[0] = ((uint32_t)(cpu->regs[27] & 1ULL));
    PB_STRW((SP + 20), cpu->regs[0]);
    if (!((cpu->regs[27] >> 0) & 1)) goto L_b9c8c;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb9c80ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_b9c90;
    goto L_b9e1c;
L_b9c8c:
    cpu->regs[22] = 0ULL;
L_b9c90:
    cpu->regs[0] = PB_BASE + 0x2a5000ULL;
    cpu->regs[28] = cpu->tls_ptr;
    cpu->regs[0] = cpu->regs[0] + 1440ULL;
    cpu->regs[25] = 0ULL;
    PB_STR((SP + 32), cpu->regs[0]);
    cpu->regs[0] = SP + 56ULL;
    PB_STR((SP + 40), cpu->regs[0]);
L_b9cac:
    FLAG_CMP(cpu->regs[25], cpu->regs[26]);
    if (FLAG_EQ) goto L_b9db8;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 80));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb9cc8ULL; PB_CALL(44, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[28] + cpu->regs[0];
    PB_STR((SP + 24), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[28] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[25] << 3);
    PB_LDR(cpu->regs[1], (SP + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0xb9ce8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b9e1c;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[3] = cpu->regs[27];
    PB_LDR(cpu->regs[4], (SP + 40));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xb9d04ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xb9b0cULL);
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 36));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_b9d24;
    PB_STRW((cpu->regs[3] + 36), cpu->regs[2]);
    goto L_b9e1c;
L_b9d24:
    PB_LDR(cpu->regs[1], (SP + 56));
    PB_STRW((cpu->regs[3] + 36), cpu->regs[2]);
    if ((cpu->regs[1])==0) goto L_b9d7c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb9d38ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe548cULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_b9d68;
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9d5c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9d5c;
    cpu->regs[30] = PB_BASE + 0xb9d5cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9d5c:
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[30] = PB_BASE + 0xb9d64ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_b9e1c;
L_b9d68:
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9d7c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9d7c;
    cpu->regs[30] = PB_BASE + 0xb9d7cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9d7c:
    PB_LDR(cpu->regs[1], (SP + 64));
    if ((cpu->regs[1])==0) goto L_b9db0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb9d8cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe548cULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 64));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_b9e08;
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9db0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9db0;
    cpu->regs[30] = PB_BASE + 0xb9db0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9db0:
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    goto L_b9cac;
L_b9db8:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb9dc8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xb98a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b9e1c;
    PB_LDRW(cpu->regs[0], (SP + 20));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_b9df0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20] + 8ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb9de8ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xb98a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b9df8;
L_b9df0:
    cpu->regs[19] = 0ULL;
    goto L_b9e20;
L_b9df8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if ((cpu->regs[0])==0) goto L_b9e1c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 0), 0ULL);
L_b9e08:
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9e1c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9e1c;
    cpu->regs[30] = PB_BASE + 0xb9e1cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9e1c:
    cpu->regs[19] = 4294967295ULL;
L_b9e20:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b9e3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b9e3c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb9e3cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9e3c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb9e44ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x18d760ULL);
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_b9c44;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if ((cpu->regs[0])==0) goto L_b9e6c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9e6c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9e6c;
    cpu->regs[30] = PB_BASE + 0xb9e6cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9e6c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    if ((cpu->regs[0])==0) goto L_b9e90;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 8), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_b9e90;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b9e90;
    cpu->regs[30] = PB_BASE + 0xb9e90ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b9e90:
    cpu->regs[0] = 4294967295ULL;
L_b9e94:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_b9eb4;
    cpu->regs[30] = PB_BASE + 0xb9eb4ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b9eb4:
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    SP = SP + 176ULL;
    return;
    SP = SP - 80ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 1480ULL;
    PB_STR((SP + 16), 0ULL);
    cpu->regs[30] = PB_BASE + 0xb9f1cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_b9f28;
L_b9f20:
    cpu->regs[19] = 0ULL;
    goto L_b9f84;
L_b9f28:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[1] = SP + 12ULL;
    cpu->regs[30] = PB_BASE + 0xb9f34ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x9435cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b9f20;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[1], (SP + 12));
    cpu->regs[4] = SP + 24ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb9f54ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xb9b0cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_b9f20;
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[19];
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_b9f80;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_b9f80:
    cpu->regs[30] = PB_BASE + 0xb9f84ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x18d760ULL);
L_b9f84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_b9fa4;
    cpu->regs[30] = PB_BASE + 0xb9fa4ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x7c170ULL);
L_b9fa4:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 64));
    SP = SP + 80ULL;
    return;
    SP = SP - 96ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[21]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 2480ULL;
    PB_STR((SP + 16), 0ULL);
    cpu->regs[30] = PB_BASE + 0xba004ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ba010;
L_ba008:
    cpu->regs[19] = 0ULL;
    goto L_ba07c;
L_ba010:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[1] = SP + 12ULL;
    cpu->regs[30] = PB_BASE + 0xba01cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x9435cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ba008;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[1], (SP + 12));
    cpu->regs[4] = SP + 24ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xba03cULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xb9b0cULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ba008;
    PB_LDR(cpu->regs[21], (SP + 24)); PB_LDR(cpu->regs[20], (SP + 24) + 8);
    cpu->regs[0] = 2ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[21], 0ULL);
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[21] : cpu->regs[2];
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[20] : cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xba068ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xba074ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xba07cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x18d760ULL);
L_ba07c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_ba09c;
    cpu->regs[30] = PB_BASE + 0xba09cULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ba09c:
    PB_LDR(cpu->regs[21], (SP + 80));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3624));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_ba0fc;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 296));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_ba0fc;
L_ba0ec:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_ba114;
    goto L_ba12c;
L_ba0fc:
    if ((cpu->regs[1])==0) goto L_ba0ec;
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 3920ULL;
    cpu->regs[30] = PB_BASE + 0xba10cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ba0ec;
    goto L_ba140;
L_ba114:
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3920ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xba128ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ba140;
L_ba12c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(75, cpu, tlb, PB_BASE + 0x1da204ULL); return; };
L_ba140:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 160ULL;
    cpu->regs[11] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[11], (cpu->regs[11] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    cpu->regs[12] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[12], (cpu->regs[12] + 2272));
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[21] = cpu->regs[6];
    cpu->regs[19] = cpu->regs[4];
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[20] = cpu->regs[5];
    cpu->regs[24] = 0ULL;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    PB_STR((SP + 8), cpu->regs[2]);
    PB_STRW((SP + 20), cpu->regs[3]);
    PB_STR((SP + 24), cpu->regs[7]);
    PB_LDR(cpu->regs[10], (cpu->regs[22] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[11] + 0));
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
L_ba1b8:
    PB_LDRB(cpu->regs[0], cpu->regs[10]); cpu->regs[10] += 1;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(40ULL)));
    if (FLAG_NE) goto L_ba1d4;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    cpu->regs[24] = ((uint32_t)((FLAG_EQ) ? (cpu->regs[24] + 1) : cpu->regs[24]));
    goto L_ba1b8;
L_ba1d4:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(41ULL)));
    if (FLAG_NE) goto L_ba1e8;
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_ba218;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_ba1b8;
L_ba1e8:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] - 58ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_ba218;
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_ba1b8;
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDRW(cpu->regs[2], (cpu->regs[12] + (cpu->regs[2] << 2)));
    FLAG_CMP((cpu->regs[2]) & (3ULL), 0);
    if (FLAG_EQ) goto L_ba1b8;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(101ULL)));
    cpu->regs[24] = ((uint32_t)((FLAG_NE) ? (cpu->regs[24] + 1) : cpu->regs[24]));
    goto L_ba1b8;
L_ba218:
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 48), cpu->regs[10]);
    cpu->regs[30] = PB_BASE + 0xba224ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ba238;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    cpu->regs[23] = cpu->regs[0] & 134217728ULL;
    if (!((cpu->regs[0] >> 27) & 1)) goto L_ba27c;
L_ba238:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STRW((cpu->regs[19] + 0), 0ULL);
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_EQ) goto L_ba258;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 24));
    goto L_ba260;
L_ba258:
    cpu->regs[4] = PB_BASE + 0x2a3000ULL;
    cpu->regs[4] = cpu->regs[4] + 2064ULL;
L_ba260:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[2] = cpu->regs[2] + 1496ULL;
    cpu->regs[30] = PB_BASE + 0xba278ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x1815f0ULL);
    goto L_ba2ac;
L_ba27c:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0xba284ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x1fd1e8ULL);
    cpu->regs[4] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_ba2b4;
    PB_STRW((cpu->regs[19] + 0), 0ULL);
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[2] + 1536ULL;
    cpu->regs[30] = PB_BASE + 0xba2acULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x1815f0ULL);
L_ba2ac:
    cpu->regs[1] = cpu->regs[20];
    goto L_ba354;
L_ba2b4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[28] = cpu->regs[19] + 4ULL;
    cpu->regs[1] = SP + 48ULL;
    PB_STR((SP + 32), cpu->regs[1]);
    PB_STR((SP + 48), cpu->regs[0]);
L_ba2c8:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[23])));
    if (FLAG_LE) goto L_ba348;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[26] = ((uint32_t)(cpu->regs[23] + 1ULL));
    cpu->regs[30] = PB_BASE + 0xba2e0ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x14d028ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_ba308;
    cpu->regs[30] = PB_BASE + 0xba2ecULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_STRW((cpu->regs[19] + 0), cpu->regs[26]); PB_STRW((cpu->regs[19] + 0) + 4, 0ULL);
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 1576ULL;
    cpu->regs[30] = PB_BASE + 0xba304ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    goto L_ba2ac;
L_ba308:
    PB_LDR(cpu->regs[7], (SP + 24)); PB_LDR(cpu->regs[1], (SP + 24) + 8);
    cpu->regs[6] = cpu->regs[21];
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[5] = cpu->regs[20];
    PB_LDRW(cpu->regs[3], (SP + 20));
    cpu->regs[4] = cpu->regs[28];
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[30] = PB_BASE + 0xba328ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xeaf48ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[27];
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xba338ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    if ((cpu->regs[1])==0) goto L_ba2c8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[26]);
    goto L_ba354;
L_ba348:
    PB_LDR(cpu->regs[0], (SP + 48));
    cpu->regs[1] = 0ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
L_ba354:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ba374;
    cpu->regs[30] = PB_BASE + 0xba374ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ba374:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
    SP = SP - 176ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 144), cpu->regs[29]); PB_STR((SP + 144) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 144ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[3] = PB_BASE + 0x523000ULL;
    cpu->regs[3] = cpu->regs[3] + 784ULL;
    PB_STR((SP + 160), cpu->regs[19]);
    cpu->regs[3] = cpu->regs[3] + 368ULL;
    cpu->regs[5] = SP + 4ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 136), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = SP;
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[2] = cpu->regs[2] + 1600ULL;
    PB_STRW((SP + 4), cpu->regs[6]);
    cpu->regs[30] = PB_BASE + 0xba3ecULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x13eb20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ba430;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xba404ULL; PB_CALL(87, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[19], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0xba410ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1b03a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ba438;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1624ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xba430ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x1d5980ULL);
L_ba430:
    cpu->regs[0] = 0ULL;
    goto L_ba4a8;
L_ba438:
    PB_LDRW(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ba488;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0xba44cULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xad598ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ba430;
    PB_LDRW(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0xba458ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xad5f4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ba430;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ba488;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[3], (SP + 0));
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[2] = cpu->regs[2] + 1688ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xba484ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_ba430;
L_ba488:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDRW(cpu->regs[3], (SP + 0)); PB_LDRW(cpu->regs[2], (SP + 0) + 4);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 1504));
    PB_STRW((cpu->regs[1] + 1504), cpu->regs[3]);
    PB_STRW((cpu->regs[1] + 1508), cpu->regs[2]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0xba4a8ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xe2620ULL);
L_ba4a8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 136));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ba4c8;
    cpu->regs[30] = PB_BASE + 0xba4c8ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ba4c8:
    PB_LDR(cpu->regs[19], (SP + 160));
    PB_LDR(cpu->regs[29], (SP + 144)); PB_LDR(cpu->regs[30], (SP + 144) + 8);
    SP = SP + 176ULL;
    return;
    SP = SP - 64ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[3] = PB_BASE + 0x523000ULL;
    cpu->regs[3] = cpu->regs[3] + 784ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[19] = SP + 16ULL;
    cpu->regs[3] = cpu->regs[3] + 400ULL;
    cpu->regs[4] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[5] = SP + 12ULL;
    cpu->regs[2] = PB_BASE + 0x2a5000ULL;
    cpu->regs[2] = cpu->regs[2] + 1728ULL;
    PB_STRW((SP + 12), cpu->regs[6]);
    PB_STR((SP + 16), 0ULL);
    cpu->regs[30] = PB_BASE + 0xba534ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x13eb20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ba590;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xba540ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x1c7a00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ba590;
    cpu->regs[30] = PB_BASE + 0xba550ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x1c8584ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ba588;
    PB_LDRW(cpu->regs[0], (SP + 12));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ba598;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xba570ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x91180ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ba5a0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xba588ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_ba588:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0xba590ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x18d760ULL);
L_ba590:
    cpu->regs[0] = 0ULL;
    goto L_ba5b8;
L_ba598:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xba5a0ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x91178ULL);
L_ba5a0:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0xba5a8ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[30] = PB_BASE + 0xba5acULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x12cde0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ba590;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ba5b8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ba5d8;
    cpu->regs[30] = PB_BASE + 0xba5d8ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ba5d8:
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
}
