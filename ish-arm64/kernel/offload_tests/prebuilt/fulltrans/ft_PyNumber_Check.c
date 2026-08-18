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

void ft_PyNumber_Check(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((cpu->regs[0])==0) goto L_1cb0f0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 96));
    if ((cpu->regs[1])==0) goto L_1cb0f0;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 264));
    cpu->regs[3] = 1ULL;
    if ((cpu->regs[2])==0) goto L_1cb0d4;
L_1cb0cc:
    cpu->regs[0] = cpu->regs[3];
    return;
L_1cb0d4:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 128));
    if ((cpu->regs[2])!=0) goto L_1cb0cc;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 144));
    if ((cpu->regs[1])!=0) goto L_1cb0cc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2320));
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xe270cULL); return; };
L_1cb0f0:
    cpu->regs[3] = 0ULL;
    goto L_1cb0cc;
    /* nop */
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 0ULL;
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 304));
    cpu->regs[30] = PB_BASE + 0x1cb114ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1cb138;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 20));
    cpu->regs[2] = 4294967295ULL;
    PB_STRW((cpu->regs[0] + 16), cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 4294967168ULL));
    PB_STRW((cpu->regs[0] + 24), 0ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 112ULL));
    PB_STRB((cpu->regs[0] + 20), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 32), 0ULL);
L_1cb138:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 288ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 192), cpu->regs[29]); PB_STR((SP + 192) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 192ULL;
    PB_STR((SP + 208), cpu->regs[19]); PB_STR((SP + 208) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 224), cpu->regs[21]); PB_STR((SP + 224) + 8, cpu->regs[22]);
    PB_STR((SP + 240), cpu->regs[23]); PB_STR((SP + 240) + 8, cpu->regs[24]);
    PB_STR((SP + 256), cpu->regs[25]); PB_STR((SP + 256) + 8, cpu->regs[26]);
    PB_STR((SP + 272), cpu->regs[27]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 184), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    if ((cpu->regs[2])!=0) goto L_1cb764;
    cpu->regs[21] = cpu->regs[3] - 1ULL;
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    cpu->regs[24] = cpu->regs[3];
    FLAG_CMP(cpu->regs[21], 3ULL);
    if (FLAG_HI) goto L_1cb774;
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1cb774;
L_1cb19c:
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 0));
    if ((cpu->regs[21])==0) goto L_1cb74c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    if ((cpu->regs[0])==0) goto L_1cb80c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1cb7e4;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x1cb1c0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1cb628;
    cpu->regs[30] = PB_BASE + 0x1cb1ccULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1cb7b0;
    cpu->regs[21] = cpu->regs[24] - 2ULL; FLAG_CMP(cpu->regs[21], 0);
    if (FLAG_EQ) goto L_1cb4fc;
L_1cb1e0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    if ((cpu->regs[0])==0) goto L_1cb7dc;
    cpu->regs[30] = PB_BASE + 0x1cb1ecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[25] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_1cb628;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_1cb7d0;
L_1cb1fc:
    PB_LDR(cpu->regs[27], (cpu->regs[22] + 24));
L_1cb200:
    PB_STR((SP + 16), 0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1cb5d8;
L_1cb20c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1cb214ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[22] = cpu->regs[0];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1cb480;
    cpu->regs[30] = PB_BASE + 0x1cb220ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1cb6b8;
    cpu->regs[30] = PB_BASE + 0x1cb228ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1cb234ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1cb820ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1cb628;
    PB_LDR(cpu->regs[26], (SP + 16));
    cpu->regs[26] = cpu->regs[26] + 32ULL;
L_1cb240:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[24] = 0ULL;
L_1cb250:
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1cb3f8;
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_1cb630;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = 25769803776ULL;
    cpu->regs[0] = cpu->regs[0] & cpu->regs[1];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1cb50c;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 20));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_1cb448;
L_1cb278:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | 524288ULL));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 3384ULL;
    cpu->regs[0] = cpu->regs[0] + 3064ULL;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1cb29cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1cb470;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 20));
    if (!((cpu->regs[22] >> 31) & 1)) goto L_1cb488;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | 64ULL));
    PB_STRB((cpu->regs[19] + 20), cpu->regs[0]);
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_1cb69c;
    cpu->regs[30] = PB_BASE + 0x1cb2bcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STRW((cpu->regs[20] + 0), 0ULL);
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_NE) goto L_1cb564;
L_1cb2d4:
    cpu->regs[30] = PB_BASE + 0x1cb2d8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = 438ULL;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1cb2ecULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7b240ULL);
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1cb2f8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 16));
    if (((cpu->regs[3] >> 31) & 1)) goto L_1cb450;
    cpu->regs[2] = PB_BASE + 0x450000ULL;
    cpu->regs[2] = cpu->regs[2] + 8ULL;
    cpu->regs[2] = cpu->regs[2] + 464ULL;
L_1cb30c:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cb318ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1cb920ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1cb6fc;
L_1cb31c:
    cpu->regs[0] = 8192ULL;
    PB_STRW((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1cb328ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = SP + 56ULL;
    cpu->regs[30] = PB_BASE + 0x1cb338ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7b150ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1cb344ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if (((cpu->regs[20] >> 31) & 1)) goto L_1cb6d8;
    PB_LDRW(cpu->regs[0], (SP + 72));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 61440ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(16384ULL)));
    if (FLAG_EQ) goto L_1cb724;
    PB_LDRW(cpu->regs[0], (SP + 112));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_LE) goto L_1cb368;
    PB_STRW((cpu->regs[19] + 24), cpu->regs[0]);
L_1cb368:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 51144ULL;
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1cb384ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1cb6f8;
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 20));
    if (((cpu->regs[0] >> 3) & 1)) goto L_1cb49c;
L_1cb390:
    cpu->regs[19] = 0ULL;
L_1cb394:
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])==0) goto L_1cb3b8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1cb3b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1cb3b8;
    cpu->regs[30] = PB_BASE + 0x1cb3b8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1cb3b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 184));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1cb5d4;
    PB_LDR(cpu->regs[27], (SP + 272));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 192)); PB_LDR(cpu->regs[30], (SP + 192) + 8);
    PB_LDR(cpu->regs[19], (SP + 208)); PB_LDR(cpu->regs[20], (SP + 208) + 8);
    PB_LDR(cpu->regs[21], (SP + 224)); PB_LDR(cpu->regs[22], (SP + 224) + 8);
    PB_LDR(cpu->regs[23], (SP + 240)); PB_LDR(cpu->regs[24], (SP + 240) + 8);
    PB_LDR(cpu->regs[25], (SP + 256)); PB_LDR(cpu->regs[26], (SP + 256) + 8);
    SP = SP + 288ULL;
    return;
L_1cb3f8:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(114ULL)));
    if (FLAG_NE) goto L_1cb41c;
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1cb630;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 20));
    cpu->regs[24] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 2ULL));
    PB_STRB((cpu->regs[19] + 20), cpu->regs[1]);
    goto L_1cb250;
L_1cb41c:
    if (FLAG_LS) goto L_1cb4d0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(119ULL)));
    if (FLAG_NE) goto L_1cb514;
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1cb630;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 20));
    cpu->regs[2] = 576ULL;
    cpu->regs[24] = 1ULL;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 4ULL));
    PB_STRB((cpu->regs[19] + 20), cpu->regs[1]);
    goto L_1cb250;
L_1cb448:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | 1ULL));
    goto L_1cb278;
L_1cb450:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_1cb5ec;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    cpu->regs[1] = cpu->regs[23];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb470ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1c8ce0ULL);
L_1cb470:
    cpu->regs[0] = 4294967295ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
L_1cb478:
    cpu->regs[19] = 4294967295ULL;
    goto L_1cb394;
L_1cb480:
    cpu->regs[26] = 0ULL;
    goto L_1cb240;
L_1cb488:
    cpu->regs[0] = ((uint32_t)(((cpu->regs[0] & ~(0x1ULL << 6)) | ((cpu->regs[25] & 0x1ULL) << 6))));
    cpu->regs[24] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    PB_STRB((cpu->regs[19] + 20), cpu->regs[0]);
    goto L_1cb31c;
L_1cb49c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cb4b0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1cc284ULL);
    if ((cpu->regs[0])==0) goto L_1cb6f8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1cb390;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1cb390;
    cpu->regs[30] = PB_BASE + 0x1cb4ccULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cb390;
L_1cb4d0:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(98ULL)));
    if (FLAG_EQ) goto L_1cb250;
    if (FLAG_HI) goto L_1cb5f8;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(43ULL)));
    if (FLAG_NE) goto L_1cb53c;
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_1cb630;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 20));
    cpu->regs[3] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 6ULL));
    PB_STRB((cpu->regs[19] + 20), cpu->regs[1]);
    goto L_1cb250;
L_1cb4fc:
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2760));
    cpu->regs[25] = 1ULL;
    goto L_1cb200;
L_1cb50c:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | 2ULL));
    goto L_1cb278;
L_1cb514:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(120ULL)));
    if (FLAG_NE) goto L_1cb5f8;
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1cb630;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 20));
    cpu->regs[2] = 5ULL;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | 192ULL));
    cpu->regs[24] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | cpu->regs[2]));
    PB_STRB((cpu->regs[19] + 20), cpu->regs[1]);
    goto L_1cb250;
L_1cb53c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(97ULL)));
    if (FLAG_NE) goto L_1cb5f8;
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1cb630;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 20));
    cpu->regs[2] = 1088ULL;
    cpu->regs[24] = 1ULL;
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 12ULL));
    PB_STRB((cpu->regs[19] + 20), cpu->regs[1]);
    goto L_1cb250;
L_1cb564:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 4016ULL;
    cpu->regs[30] = PB_BASE + 0x1cb57cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1c1960ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1cb470;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_1cb664;
    cpu->regs[30] = PB_BASE + 0x1cb594ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x13ae00ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1cb64c;
L_1cb5a0:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[2] = 0ULL;
    if (!((cpu->regs[3] >> 31) & 1)) goto L_1cb30c;
    cpu->regs[30] = PB_BASE + 0x1cb5b0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1cb470;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3464ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb5d0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1cb470;
L_1cb5d4:
    cpu->regs[30] = PB_BASE + 0x1cb5d8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1cb5d8:
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 20));
    if (((cpu->regs[0] >> 6) & 1)) goto L_1cb618;
    cpu->regs[0] = 4294967295ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[0]);
    goto L_1cb20c;
L_1cb5ec:
    cpu->regs[30] = PB_BASE + 0x1cb5f0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x12cde0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1cb2d4;
    goto L_1cb470;
L_1cb5f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3360ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb614ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1cb470;
L_1cb618:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cb620ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1cd960ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1cb20c;
L_1cb628:
    cpu->regs[19] = 4294967295ULL;
    goto L_1cb3b8;
L_1cb630:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3280ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb648ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cb470;
L_1cb64c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1cb5a0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1cb660ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cb5a0;
L_1cb664:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1cb678;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1cb694;
L_1cb678:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb690ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cb470;
L_1cb694:
    cpu->regs[30] = PB_BASE + 0x1cb698ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cb678;
L_1cb69c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3392ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb6b4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cb470;
L_1cb6b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[1] = cpu->regs[1] + 3248ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb6d4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cb3b8;
L_1cb6d8:
    cpu->regs[30] = PB_BASE + 0x1cb6dcULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(9ULL)));
    if (FLAG_NE) goto L_1cb368;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb6f8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_1cb6f8:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_1cb470;
L_1cb6fc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1cb478;
    cpu->regs[30] = PB_BASE + 0x1cb708ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1cb714ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1cd960ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1cb720ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
    goto L_1cb394;
L_1cb724:
    cpu->regs[30] = PB_BASE + 0x1cb728ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3024));
    cpu->regs[1] = 21ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[23];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb744ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1c8ce0ULL);
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1cb6fc;
    goto L_1cb470;
L_1cb74c:
    cpu->regs[20] = PB_BASE + 0x295000ULL;
    cpu->regs[25] = 1ULL;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2760));
    cpu->regs[20] = cpu->regs[20] + 2904ULL;
    goto L_1cb200;
L_1cb764:
    PB_LDR(cpu->regs[24], (cpu->regs[2] + 16));
    cpu->regs[0] = cpu->regs[1] + 24ULL;
    cpu->regs[24] = cpu->regs[3] + cpu->regs[24];
    cpu->regs[21] = cpu->regs[24] - 1ULL;
L_1cb774:
    cpu->regs[1] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x51e000ULL;
    cpu->regs[4] = cpu->regs[4] + 3856ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[4] = cpu->regs[4] + 4016ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 4ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cb7a0ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1cb19c;
    cpu->regs[19] = 4294967295ULL;
    goto L_1cb3b8;
L_1cb7b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb7ccULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cb3b8;
L_1cb7d0:
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2760));
    goto L_1cb200;
L_1cb7dc:
    cpu->regs[25] = 1ULL;
    goto L_1cb1fc;
L_1cb7e4:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2712ULL;
    cpu->regs[0] = PB_BASE + 0x28e000ULL;
    cpu->regs[19] = 4294967295ULL;
    cpu->regs[0] = cpu->regs[0] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0x1cb808ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_1cb3b8;
L_1cb80c:
    cpu->regs[20] = PB_BASE + 0x295000ULL;
    cpu->regs[20] = cpu->regs[20] + 2904ULL;
    goto L_1cb1e0;
    /* nop */
    /* nop */
}
