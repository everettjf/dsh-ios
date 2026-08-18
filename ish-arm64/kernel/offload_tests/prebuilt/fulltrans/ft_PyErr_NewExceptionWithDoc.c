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

void ft_PyErr_NewExceptionWithDoc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    if ((cpu->regs[3])!=0) goto L_20b210;
    cpu->regs[30] = PB_BASE + 0x20b18cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20b1f8;
    cpu->regs[23] = cpu->regs[0];
L_20b198:
    if ((cpu->regs[20])==0) goto L_20b1dc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20b1a4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20b228;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    cpu->regs[30] = PB_BASE + 0x20b1c0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 0));
    if (((cpu->regs[3] >> 31) & 1)) goto L_20b1d8;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[3]);
    if ((cpu->regs[3])==0) goto L_20b21c;
L_20b1d8:
    if (((cpu->regs[24] >> 31) & 1)) goto L_20b228;
L_20b1dc:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20b1ecULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x191650ULL);
    cpu->regs[19] = cpu->regs[0];
L_20b1f0:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x20b1f8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x18d760ULL);
L_20b1f8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_20b210:
    cpu->regs[19] = cpu->regs[3];
    cpu->regs[23] = 0ULL;
    goto L_20b198;
L_20b21c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20b224ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20b1d8;
L_20b228:
    cpu->regs[19] = 0ULL;
    goto L_20b1f0;
    SP = SP - 128ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    if ((cpu->regs[2])!=0) goto L_20b524;
    cpu->regs[4] = cpu->regs[1] - 1ULL;
    FLAG_CMP(cpu->regs[4], 1ULL);
    if (FLAG_HI) goto L_20b4e0;
    cpu->regs[3] = cpu->regs[3] + 24ULL;
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[3];
    if ((cpu->regs[3])==0) goto L_20b530;
L_20b290:
    PB_LDR(cpu->regs[20], (cpu->regs[2] + 0));
    cpu->regs[23] = 0ULL;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_20b518;
L_20b2a0:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[2] = 51016ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x20b2b8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x190200ULL);
    cpu->regs[25] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_20b44c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = 50960ULL;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x20b2d0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x190200ULL);
    cpu->regs[24] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_20b44c;
    cpu->regs[0] = 51080ULL;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20b2e8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x190200ULL);
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_20b44c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[1] + 424ULL;
    cpu->regs[30] = PB_BASE + 0x20b300ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x136da0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20b44c;
    if ((cpu->regs[23])!=0) goto L_20b4ac;
L_20b30c:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_EQ) goto L_20b454;
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_LT) goto L_20b5c4;
    FLAG_CMP(cpu->regs[19], cpu->regs[24]);
    if (FLAG_GT) goto L_20b594;
L_20b328:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20b330ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe51acULL);
    cpu->regs[1] = 0ULL;
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20b588;
    cpu->regs[6] = cpu->regs[20] + 24ULL;
    cpu->regs[4] = cpu->regs[0] + 24ULL;
    goto L_20b350;
L_20b348:
    PB_STR((cpu->regs[4] + (cpu->regs[1] << 3)), cpu->regs[5]);
    cpu->regs[1] = cpu->regs[1] + 1ULL;
L_20b350:
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_LE) goto L_20b37c;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (((cpu->regs[2] >> 25) & 1)) goto L_20b57c;
    PB_LDR(cpu->regs[5], (cpu->regs[6] + (cpu->regs[1] << 3)));
L_20b368:
    PB_LDRW(cpu->regs[2], (cpu->regs[5] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_20b348;
    PB_STRW((cpu->regs[5] + 0), cpu->regs[2]);
    goto L_20b348;
L_20b37c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_20b390;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20b570;
L_20b390:
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    cpu->regs[20] = cpu->regs[26] + 24ULL;
L_20b39c:
    FLAG_CMP(cpu->regs[24], cpu->regs[19]);
    if (FLAG_LE) goto L_20b3c4;
    if ((cpu->regs[23])!=0) goto L_20b408;
L_20b3a8:
    cpu->regs[2] = cpu->regs[25];
L_20b3ac:
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_20b4a4;
L_20b3b8:
    PB_STR((cpu->regs[20] + (cpu->regs[19] << 3)), cpu->regs[2]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_20b39c;
L_20b3c4:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x20b3ccULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xd9444ULL);
L_20b3cc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_20b520;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[26];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_20b408:
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 240));
    cpu->regs[2] = 40ULL;
    cpu->regs[1] = 18446744073709551576ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[19] * cpu->regs[2] + cpu->regs[3];
    cpu->regs[1] = cpu->regs[22] * cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + cpu->regs[1]));
    cpu->regs[30] = PB_BASE + 0x20b428ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xedfe0ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_20b3ac;
    cpu->regs[30] = PB_BASE + 0x20b434ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_20b3a8;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20b44c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20b5f4;
L_20b44c:
    cpu->regs[26] = 0ULL;
    goto L_20b3cc;
L_20b454:
    FLAG_CMP(cpu->regs[19], cpu->regs[25]);
    if (FLAG_EQ) goto L_20b328;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[4] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    cpu->regs[3] = cpu->regs[25];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[1] + 632ULL;
    cpu->regs[30] = PB_BASE + 0x20b480ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20b44c;
L_20b488:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_20b44c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20b4a0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20b3cc;
L_20b4a4:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    goto L_20b3b8;
L_20b4ac:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 29) & 1)) goto L_20b30c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    cpu->regs[1] = cpu->regs[1] + 456ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x20b4d4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_20b488;
    goto L_20b44c;
L_20b4e0:
    cpu->regs[0] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[0] = cpu->regs[3] + 24ULL;
    cpu->regs[4] = cpu->regs[4] + 264ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20b50cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20b44c;
    PB_LDR(cpu->regs[20], (cpu->regs[2] + 0));
L_20b518:
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 8));
    goto L_20b2a0;
L_20b520:
    cpu->regs[30] = PB_BASE + 0x20b524ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_20b524:
    PB_LDR(cpu->regs[19], (cpu->regs[2] + 16));
    cpu->regs[3] = cpu->regs[3] + 24ULL;
    cpu->regs[19] = cpu->regs[1] + cpu->regs[19];
L_20b530:
    cpu->regs[2] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[4] = cpu->regs[4] + 264ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20b560ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_20b290;
    cpu->regs[26] = 0ULL;
    goto L_20b3cc;
L_20b570:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20b578ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20b390;
L_20b57c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + (cpu->regs[1] << 3)));
    goto L_20b368;
L_20b588:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_20b488;
    goto L_20b44c;
L_20b594:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[4] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    cpu->regs[3] = cpu->regs[24];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[1] + 568ULL;
    cpu->regs[30] = PB_BASE + 0x20b5b8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_20b488;
    goto L_20b44c;
L_20b5c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[4] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    cpu->regs[3] = cpu->regs[25];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[1] + 504ULL;
    cpu->regs[30] = PB_BASE + 0x20b5e8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_20b488;
    goto L_20b44c;
L_20b5f4:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20b600ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20b3cc;
}
