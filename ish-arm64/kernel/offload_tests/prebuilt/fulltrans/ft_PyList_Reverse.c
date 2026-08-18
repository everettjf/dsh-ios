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

void ft_PyList_Reverse(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((cpu->regs[0])==0) goto L_2203b0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 25) & 1)) goto L_2203b0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_LE) goto L_2203a8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[0] = cpu->regs[2] + (cpu->regs[1] << 3);
    cpu->regs[0] = cpu->regs[0] - 8ULL;
L_22038c:
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_HS) goto L_2203a8;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR(cpu->regs[2], cpu->regs[3]); cpu->regs[2] += 8;
    PB_STR(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += -8;
    goto L_22038c;
L_2203a8:
    cpu->regs[0] = 0ULL;
    return;
L_2203b0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 2548ULL;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[29] = SP;
    cpu->regs[0] = cpu->regs[0] + 224ULL;
    cpu->regs[30] = PB_BASE + 0x2203c8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    /* nop */
    /* nop */
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_220400;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 584));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_2203fc;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_2203fc:
    return;
L_220400:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_220420;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 944));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_2203fc;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_2203fc;
L_220420:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 240));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_2203fc;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_2203fc;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_220470;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x22046cULL; PB_CALL(2, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2204a4;
L_220470:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_220484;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x220480ULL; PB_CALL(3, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2204a4;
L_220484:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_2204a4;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_2204a4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 144ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    if ((cpu->regs[22])==0) goto L_220658;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_STR((SP + 128), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x220500ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x213250ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22068c;
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x22050cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11cb84ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 16));
    cpu->regs[3] = 4ULL;
    cpu->regs[4] = 1ULL;
    cpu->regs[21] = SP;
    FLAG_CMP(cpu->regs[2], 1ULL);
    cpu->regs[1] = 40ULL;
    cpu->regs[2] = cpu->regs[2] + (cpu->regs[2] << 1);
    PB_STRB((SP + 52), cpu->regs[4]);
    cpu->regs[2] = (FLAG_GT) ? cpu->regs[2] : cpu->regs[3];
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x220538ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x129f60ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_220640;
    cpu->regs[24] = PB_BASE + 0x285000ULL;
    cpu->regs[25] = cpu->regs[23] + 24ULL;
    cpu->regs[24] = cpu->regs[24] + 2888ULL;
    cpu->regs[20] = 0ULL;
L_220550:
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_GE) goto L_2205bc;
    if ((cpu->regs[20])==0) goto L_220574;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x22056cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_220640;
L_220574:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + (cpu->regs[20] << 3)));
    cpu->regs[30] = PB_BASE + 0x22057cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x14d650ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_220640;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x220590ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x120700ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2206c4;
    if (((cpu->regs[2] >> 31) & 1)) goto L_2205b4;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_2205b4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2205b4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2205b4:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_220550;
L_2205bc:
    PB_STRB((SP + 52), 0ULL);
    FLAG_CMP(cpu->regs[22], 1ULL);
    if (FLAG_LE) goto L_220624;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 41ULL;
    cpu->regs[30] = PB_BASE + 0x2205d4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x129f60ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_220640;
L_2205dc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x2205e4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x2153e0ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2205ecULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11ce48ULL);
L_2205ec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2206b0;
    PB_LDR(cpu->regs[25], (SP + 128));
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 144ULL;
    return;
L_220624:
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 1064ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x220638ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_2205dc;
L_220640:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x220648ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7bef0ULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x220650ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x2153e0ULL);
L_220650:
    cpu->regs[0] = 0ULL;
    goto L_2205ec;
L_220658:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_2206b4;
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[0] + 3040ULL;
L_22067c:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 144ULL;
    { PB_CALL(17, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
L_22068c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_220650;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_2206e0;
L_2206b0:
    cpu->regs[30] = PB_BASE + 0x2206b4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2206b4:
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0x2206c4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2206c4:
    if (((cpu->regs[2] >> 31) & 1)) goto L_220640;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_220640;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2206dcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_220640;
L_2206e0:
    PB_LDR(cpu->regs[25], (SP + 128));
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    cpu->regs[0] = cpu->regs[0] + 1056ULL;
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    goto L_22067c;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_220764;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x220734ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x179564ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2207b8;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22074cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe97e4ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_2207a4;
    PB_LDR(cpu->regs[21], (SP + 32));
L_220754:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_220764:
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x22076cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe13e0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22079c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x220788ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22079c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2207d8;
L_22079c:
    cpu->regs[19] = 0ULL;
    goto L_220754;
L_2207a4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2207b8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2207c4;
L_2207b8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[19] = 0ULL;
    goto L_220754;
L_2207c4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2207d0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_220754;
L_2207d8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2207e4ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_220754;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_220834;
    cpu->regs[19] = PB_BASE + 0x3db000ULL;
    cpu->regs[19] = cpu->regs[19] + 2816ULL;
    cpu->regs[19] = cpu->regs[19] + 2560ULL;
L_220818:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[20];
    if ((cpu->regs[1])==0) goto L_220834;
    cpu->regs[30] = PB_BASE + 0x220828ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22084c;
    cpu->regs[19] = cpu->regs[19] + 8ULL;
    goto L_220818;
L_220834:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(28, cpu, tlb, PB_BASE + 0x115f60ULL); return; };
L_22084c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(29, cpu, tlb, PB_BASE + 0xed3ccULL); return; };
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x220870ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x220880ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    { PB_CALL(31, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
    /* nop */
}
