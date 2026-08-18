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

void ft_PyFile_SetOpenCodeHook(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d20b4;
L_d20a8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2976));
    if ((cpu->regs[0])==0) goto L_d20f8;
    goto L_d20d0;
L_d20b4:
    cpu->regs[0] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 1424ULL;
    cpu->regs[30] = PB_BASE + 0xd20c4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_d20a8;
    goto L_d20f0;
L_d20d0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d20f0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 1440ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd20f0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_d20f0:
    cpu->regs[0] = 4294967295ULL;
    goto L_d2104;
L_d20f8:
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[19] + 2976), cpu->regs[21]);
    PB_STR((cpu->regs[19] + 2984), cpu->regs[20]);
L_d2104:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 1488ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x82108ULL); return; };
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    cpu->regs[1] = cpu->regs[1] + 1496ULL;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x82108ULL); return; };
    SP = SP - 160ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3904));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[21] = SP + 48ULL;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[1];
    cpu->regs[26] = cpu->regs[2];
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 56), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_STRW((SP + 36), 0ULL);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_NE) goto L_d2208;
    cpu->regs[5] = 57840ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[24] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0xd21a0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d2230;
    PB_LDR(cpu->regs[20], (SP + 48));
    if ((cpu->regs[20])==0) goto L_d21f4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_d21f4;
    cpu->regs[4] = 42864ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0xd21d0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d21e4;
L_d21d8:
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xd21e0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_d21fc;
L_d21e4:
    cpu->regs[30] = PB_BASE + 0xd21e8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d21fc;
    goto L_d21d8;
L_d21f4:
    cpu->regs[22] = 0ULL;
    cpu->regs[19] = 0ULL;
L_d21fc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd2204ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_d2210;
L_d2208:
    cpu->regs[22] = 0ULL;
    cpu->regs[19] = 0ULL;
L_d2210:
    cpu->regs[3] = 54416ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[24] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xd2220ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_d2238;
L_d2228:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd2230ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdce4cULL);
L_d2230:
    cpu->regs[19] = 4294967295ULL;
    goto L_d2434;
L_d2238:
    PB_LDR(cpu->regs[21], (SP + 48));
    if ((cpu->regs[21])==0) goto L_d2274;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd2248ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x12cb88ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_d226c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d226c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd226cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d226c:
    if ((cpu->regs[20])!=0) goto L_d2280;
L_d2270:
    cpu->regs[30] = PB_BASE + 0xd2274ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_d2274:
    cpu->regs[23] = PB_BASE + 0x299000ULL;
    cpu->regs[23] = cpu->regs[23] + 240ULL;
    goto L_d229c;
L_d2280:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_d2274;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd2294ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d2270;
L_d229c:
    cpu->regs[2] = 54464ULL;
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xd22acULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_d2228;
    PB_LDR(cpu->regs[20], (SP + 40));
    if ((cpu->regs[20])==0) goto L_d22f0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd22c4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x12cb88ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_d22e8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d22e8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd22e8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d22e8:
    if ((cpu->regs[21])!=0) goto L_d2300;
    cpu->regs[30] = PB_BASE + 0xd22f0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_d22f0:
    cpu->regs[20] = PB_BASE + 0x299000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[20] = cpu->regs[20] + 240ULL;
    goto L_d2328;
L_d2300:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_d2320;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd2314ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1947a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d2328;
    cpu->regs[30] = PB_BASE + 0xd2320ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_d2320:
    cpu->regs[20] = PB_BASE + 0x299000ULL;
    cpu->regs[20] = cpu->regs[20] + 240ULL;
L_d2328:
    cpu->regs[30] = PB_BASE + 0xd232cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x193da0ULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[8], (SP + 48));
    if ((cpu->regs[0])!=0) goto L_d2354;
    cpu->regs[0] = cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0xd2340ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd2348ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd2350ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_d2230;
L_d2354:
    PB_STR((SP + 0), cpu->regs[28]);
    cpu->regs[5] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[7] = SP + 36ULL;
    cpu->regs[6] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[3] = 256ULL;
    cpu->regs[0] = cpu->regs[27];
    PB_STR((SP + 24), cpu->regs[8]);
    cpu->regs[30] = PB_BASE + 0xd2380ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1de6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[8], (SP + 24));
    cpu->regs[0] = cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0xd2390ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd2398ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd23a0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdce4cULL);
    if ((cpu->regs[20])!=0) goto L_d23c0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xd23acULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1c12acULL);
    PB_LDRW(cpu->regs[19], (SP + 36));
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(11ULL)));
    if (FLAG_NE) goto L_d2230;
    cpu->regs[30] = PB_BASE + 0xd23bcULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_d2434;
L_d23c0:
    cpu->regs[0] = 30384ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xd23ccULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1a1d48ULL);
    if ((cpu->regs[0])!=0) goto L_d23dc;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xd23d8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1c12acULL);
    goto L_d2230;
L_d23dc:
    cpu->regs[30] = PB_BASE + 0xd23e0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x18fc40ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[5] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd23fcULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1e33e0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[28];
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0xd240cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1c12acULL);
    if ((cpu->regs[19])==0) goto L_d2230;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_d242c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d242c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd242cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d242c:
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xd2434ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1e6da0ULL);
L_d2434:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_d2454;
    cpu->regs[30] = PB_BASE + 0xd2454ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x7c170ULL);
L_d2454:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
}
