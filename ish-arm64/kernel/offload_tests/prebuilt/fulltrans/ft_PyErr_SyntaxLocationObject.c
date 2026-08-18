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

void ft_PyErr_SyntaxLocationObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = 4294967295ULL;
    goto L_8502c;
L_8502c:
    SP = SP - 96ULL;
    cpu->regs[6] = cpu->tls_ptr;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x85058ULL; PB_CALL(1, cpu, tlb, cpu->regs[5]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[3];
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[2];
    cpu->regs[25] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (cpu->regs[6] + cpu->regs[0]));
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[30] = PB_BASE + 0x85098ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_850b0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x850acULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_850fc;
L_850b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[10] = 49376ULL;
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[10];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x850d0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_850e0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x850e0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18d760ULL);
L_850e0:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_850fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_850fc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x850fcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_850fc:
    PB_STR((SP + 0), 0ULL);
    if (((cpu->regs[26] >> 31) & 1)) goto L_85128;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[26]));
    cpu->regs[30] = PB_BASE + 0x8510cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_85134;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x85128ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18d760ULL);
L_85128:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[26] = 0ULL;
L_85134:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[9] = 52224ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x8514cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_8515c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x8515cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
L_8515c:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x85164ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 0), 0ULL);
    if (((cpu->regs[24] >> 31) & 1)) goto L_85190;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[24]));
    cpu->regs[30] = PB_BASE + 0x85174ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_8519c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x85190ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
L_85190:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[24] = 0ULL;
L_8519c:
    cpu->regs[8] = 42968ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x851acULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_851bc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x851bcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18d760ULL);
L_851bc:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x851c4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 0), 0ULL);
    if (((cpu->regs[25] >> 31) & 1)) goto L_85430;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[25]));
    cpu->regs[30] = PB_BASE + 0x851d4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe2620ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_851f0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x851ecULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_85430;
L_851f0:
    cpu->regs[24] = cpu->regs[0];
L_851f4:
    cpu->regs[7] = 43024ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x85204ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_85214;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x85214ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18d760ULL);
L_85214:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x8521cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 0), 0ULL);
    if ((cpu->regs[22])==0) goto L_852b4;
    cpu->regs[6] = 44368ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[6];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x85238ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_85248;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x85248ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18d760ULL);
L_85248:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x85258ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1e5ba0ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_852a8;
    cpu->regs[5] = 59096ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[5];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x85278ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_85288;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x85288ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x18d760ULL);
L_85288:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_852b4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_852b4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x852a4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_852b4;
L_852a8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x852b4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x18d760ULL);
L_852b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_853ec;
    cpu->regs[4] = 50816ULL;
    cpu->regs[23] = SP;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x852e4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_85364;
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])==0) goto L_8530c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_85370;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_85370;
    goto L_8535c;
L_8530c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x85314ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x12cb88ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_85364;
    cpu->regs[3] = 50816ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x85334ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_85344;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x85344ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x18d760ULL);
L_85344:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_85370;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_85370;
    cpu->regs[0] = cpu->regs[22];
L_8535c:
    cpu->regs[30] = PB_BASE + 0x85360ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_85370;
L_85364:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x85370ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x18d760ULL);
L_85370:
    cpu->regs[1] = 54008ULL;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x85384ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_8539c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x85398ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_853ec;
L_8539c:
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])==0) goto L_853c0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_853ec;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_853ec;
    cpu->regs[30] = PB_BASE + 0x853bcULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_853ec;
L_853c0:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[0] = 54008ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x853d8ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe28a0ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_853ec;
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x853ecULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x18d760ULL);
L_853ec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), cpu->regs[20]);
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_85414;
    cpu->regs[30] = PB_BASE + 0x85414ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7c170ULL);
L_85414:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    SP = SP + 96ULL;
    { PB_CALL(41, cpu, tlb, PB_BASE + 0x18d760ULL); return; };
L_85430:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[24] = 0ULL;
    goto L_851f4;
}
