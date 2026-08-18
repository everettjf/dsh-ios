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

void ft_PyByteArray_FromObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3496));
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x120dccULL); return; };
    SP = SP - 96ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[23] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa74f0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe2620ULL);
    if ((cpu->regs[0])==0) goto L_a7608;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[3] = 26376ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = SP;
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 0), cpu->regs[21]); PB_STR((SP + 0) + 8, cpu->regs[19]);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xa7518ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a75dc;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2448));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_a7550;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 3680ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa754cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a75dc;
L_a7550:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa755cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11e5ccULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a75dc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2536));
    cpu->regs[30] = PB_BASE + 0xa756cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a75dc;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    PB_STR((cpu->regs[5] + 16), cpu->regs[20]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a7588;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_a7588:
    PB_STR((cpu->regs[5] + 24), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0xa7594ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xd9444ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[22] + 8), cpu->regs[5]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_a75b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a75b4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa75b4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a75b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_a75c4;
L_a75bc:
    cpu->regs[0] = 0ULL;
    goto L_a760c;
L_a75c4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a75bc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa75d8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a75bc;
L_a75dc:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa75e4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa75ecULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a7608;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a7608;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa7608ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a7608:
    cpu->regs[0] = 4294967295ULL;
L_a760c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_a762c;
    cpu->regs[30] = PB_BASE + 0xa762cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a762c:
    PB_LDR(cpu->regs[23], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa767cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    if ((cpu->regs[0])!=0) goto L_a7688;
L_a7680:
    cpu->regs[0] = 4294967295ULL;
    goto L_a7718;
L_a7688:
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 0), cpu->regs[21]); PB_STR((SP + 0) + 8, cpu->regs[20]);
    cpu->regs[1] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    if ((cpu->regs[19])!=0) goto L_a76b8;
    cpu->regs[3] = 27408ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xa76b0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_a76d0;
L_a76b8:
    cpu->regs[2] = 33056ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[2] = 3ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0xa76ccULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[19] = cpu->regs[0];
L_a76d0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a76ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a76ec;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa76ecULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a76ec:
    if ((cpu->regs[19])==0) goto L_a7680;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_a7700;
L_a76f8:
    cpu->regs[0] = 0ULL;
    goto L_a7718;
L_a7700:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a76f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa7714ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a76f8;
L_a7718:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_a7738;
    cpu->regs[30] = PB_BASE + 0xa7738ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a7738:
    PB_LDR(cpu->regs[21], (SP + 64));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 48));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[4] : cpu->regs[1];
    { PB_CALL(20, cpu, tlb, PB_BASE + 0x1987c8ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[1])==0) goto L_a77a8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a77a8;
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 24));
    if ((cpu->regs[22])==0) goto L_a77c0;
L_a77a8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a77b8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_a77b8:
    cpu->regs[22] = cpu->regs[19];
    goto L_a786c;
L_a77c0:
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 8) + 8);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2544));
    FLAG_CMP(cpu->regs[23], cpu->regs[2]);
    if (FLAG_EQ) goto L_a77f8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[1];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(21, cpu, tlb, PB_BASE + 0x1987c8ULL); return; };
L_a77f8:
    cpu->regs[30] = PB_BASE + 0xa77fcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xed18cULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a786c;
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 312));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa7818ULL; PB_CALL(23, cpu, tlb, cpu->regs[3]);
    if ((cpu->regs[0])!=0) goto L_a783c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a786c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a786c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa7838ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a786c;
L_a783c:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a7850;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_a7850:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[0] + 16), cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a7864;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_a7864:
    cpu->regs[22] = cpu->regs[0];
    PB_STR((cpu->regs[0] + 24), cpu->regs[20]); PB_STR((cpu->regs[0] + 24) + 8, cpu->regs[21]);
L_a786c:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0x198620ULL); return; };
}
