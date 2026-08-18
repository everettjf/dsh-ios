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

void ft_PyNumber_Multiply(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1486a4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2400));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_EQ) goto L_1486c8;
L_1486b8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1486c8:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[22], (cpu->regs[2] + 104));
    PB_LDR(cpu->regs[21], (cpu->regs[4] + 104));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_14874c;
L_1486e4:
    if ((cpu->regs[21])==0) goto L_148708;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_148708;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x152850ULL); return; };
L_148708:
    if ((cpu->regs[22])==0) goto L_14872c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    if ((cpu->regs[0])==0) goto L_14872c;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x152850ULL); return; };
L_14872c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[2] = cpu->regs[2] + 2208ULL;
    cpu->regs[30] = PB_BASE + 0x148740ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x230820ULL);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1486b8;
L_14874c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1486e4;
    cpu->regs[30] = PB_BASE + 0x14875cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1486e4;
    SP = SP - 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_1488a8;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_148898;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    cpu->regs[4] = cpu->regs[2] | cpu->regs[3];
    FLAG_CMP(cpu->regs[4], 15ULL);
    if (FLAG_HI) goto L_148870;
    cpu->regs[0] = cpu->regs[2] & 3ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 24));
    cpu->regs[3] = cpu->regs[3] & 3ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[3];
    cpu->regs[2] = (uint64_t)(uint32_t)cpu->regs[4] * (uint64_t)(uint32_t)cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[2];
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_HI) goto L_148830;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 5ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_148808:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1488ec;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
L_148830:
    cpu->regs[1] = 1073741823ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = 2147483646ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    if (FLAG_HI) goto L_1488b4;
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1488f0;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0xe3e84ULL); return; };
L_148870:
    cpu->regs[30] = PB_BASE + 0x148874ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x148900ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[2];
    FLAG_CMP((cpu->regs[1]) & (3ULL), 0);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1488d8;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_148808;
L_148898:
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_148808;
L_1488a8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_148808;
L_1488b4:
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1488f0;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0x169eacULL); return; };
L_1488d8:
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0x1488e0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x22d820ULL);
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    goto L_148808;
L_1488ec:
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
L_1488f0:
    cpu->regs[30] = PB_BASE + 0x1488f4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
L_148900:
    SP = SP - 192ULL;
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 144), cpu->regs[23]); PB_STR((SP + 144) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_STR((SP + 176), cpu->regs[27]); PB_STR((SP + 176) + 8, cpu->regs[28]);
    cpu->regs[28] = cpu->regs[0];
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[24] + 16));
    PB_LDR(cpu->regs[20], (cpu->regs[28] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    cpu->regs[21] = cpu->regs[21] >> 3;
    cpu->regs[20] = cpu->regs[20] >> 3;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 88), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 56), 0ULL); PB_STR((SP + 56) + 8, 0ULL);
    PB_STR((SP + 72), 0ULL); PB_STR((SP + 72) + 8, 0ULL);
    FLAG_CMP(cpu->regs[21], cpu->regs[20]);
    if (FLAG_LT) goto L_148cd8;
L_148958:
    FLAG_CMP(cpu->regs[28], cpu->regs[24]);
    cpu->regs[0] = 70ULL;
    cpu->regs[1] = 140ULL;
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_GT) goto L_148df8;
    if ((cpu->regs[20])==0) goto L_1491e0;
    PB_LDR(cpu->regs[22], (cpu->regs[24] + 16));
    PB_LDR(cpu->regs[21], (cpu->regs[28] + 16));
    cpu->regs[22] = cpu->regs[22] >> 3;
    cpu->regs[21] = cpu->regs[21] >> 3;
    cpu->regs[0] = cpu->regs[22] + cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x14898cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_149264;
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[20] + 16));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[26] >> 3;
    cpu->regs[2] = cpu->regs[25] << 2;
    cpu->regs[30] = PB_BASE + 0x1489b4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7aee0ULL);
    FLAG_CMP(cpu->regs[28], cpu->regs[24]);
    if (FLAG_EQ) goto L_148d20;
    if ((cpu->regs[21])==0) goto L_148c28;
    cpu->regs[25] = cpu->regs[24] + 24ULL;
    cpu->regs[19] = cpu->regs[28] + 24ULL;
    cpu->regs[22] = cpu->regs[25] + (cpu->regs[22] << 2);
    cpu->regs[23] = 0ULL;
    cpu->regs[0] = cpu->regs[22] - cpu->regs[24];
    cpu->regs[0] = cpu->regs[0] - 25ULL;
    cpu->regs[27] = cpu->regs[0] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[24], (SP + 8));
    cpu->regs[27] = cpu->regs[27] + 4ULL;
    cpu->regs[28] = cpu->regs[27];
L_1489e8:
    PB_LDRW(cpu->regs[26], (cpu->regs[19] + (cpu->regs[23] << 2)));
    cpu->regs[30] = PB_BASE + 0x1489f0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x12cde0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14929c;
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[25], cpu->regs[22]);
    if (FLAG_HS) goto L_148c78;
    cpu->regs[0] = cpu->regs[27] - 4ULL;
    cpu->regs[0] = cpu->regs[0] >> 2;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[0] & 7ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_148b10;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_148ae8;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_148ac8;
    FLAG_CMP(cpu->regs[0], 3ULL);
    if (FLAG_EQ) goto L_148aa8;
    FLAG_CMP(cpu->regs[0], 4ULL);
    if (FLAG_EQ) goto L_148a88;
    FLAG_CMP(cpu->regs[0], 5ULL);
    if (FLAG_EQ) goto L_148a68;
    FLAG_CMP(cpu->regs[0], 6ULL);
    if (FLAG_NE) goto L_148c94;
L_148a48:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] >> 30;
    cpu->regs[2] = cpu->regs[2] + 4ULL;
L_148a68:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] >> 30;
    cpu->regs[2] = cpu->regs[2] + 4ULL;
L_148a88:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] >> 30;
    cpu->regs[2] = cpu->regs[2] + 4ULL;
L_148aa8:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] >> 30;
    cpu->regs[2] = cpu->regs[2] + 4ULL;
L_148ac8:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[3] >> 30;
    cpu->regs[2] = cpu->regs[2] + 4ULL;
L_148ae8:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] + 4ULL;
    cpu->regs[3] = cpu->regs[3] >> 30;
    FLAG_CMP(cpu->regs[2], cpu->regs[27]);
    if (FLAG_EQ) goto L_148bfc;
L_148b10:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    cpu->regs[4] = cpu->regs[2] + 4ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] + 8ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[4]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[4]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[3] >> 30);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[4]), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[3] >> 30);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[4] + 8ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[3] >> 30);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[4] + 12ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[3] >> 30);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[4] + 16ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[3] >> 30);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[4] + 20ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[3] >> 30);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[4] + 24ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + cpu->regs[2]));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + cpu->regs[2]));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[3] = cpu->regs[1] + (cpu->regs[3] >> 30);
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[2]), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[4] + 28ULL;
    cpu->regs[3] = cpu->regs[3] >> 30;
    FLAG_CMP(cpu->regs[2], cpu->regs[27]);
    if (FLAG_NE) goto L_148b10;
L_148bfc:
    if ((cpu->regs[3])==0) goto L_148c78;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[24]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + cpu->regs[3]));
    PB_STRW((cpu->regs[28] + cpu->regs[24]), cpu->regs[0]);
    cpu->regs[24] = cpu->regs[24] + 4ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_NE) goto L_1489e8;
    PB_LDR(cpu->regs[26], (cpu->regs[20] + 16));
    cpu->regs[25] = cpu->regs[26] >> 3;
L_148c28:
    if ((cpu->regs[25])==0) goto L_148c38;
    cpu->regs[1] = cpu->regs[20] + (cpu->regs[25] << 2);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 20));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_148cb4;
L_148c38:
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
L_148c3c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 88));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1491d8;
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    PB_LDR(cpu->regs[23], (SP + 144)); PB_LDR(cpu->regs[24], (SP + 144) + 8);
    PB_LDR(cpu->regs[27], (SP + 176)); PB_LDR(cpu->regs[28], (SP + 176) + 8);
    SP = SP + 192ULL;
    return;
L_148c78:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[24] = cpu->regs[24] + 4ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_NE) goto L_1489e8;
    PB_LDR(cpu->regs[26], (cpu->regs[20] + 16));
    cpu->regs[25] = cpu->regs[26] >> 3;
    goto L_148c28;
L_148c94:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[2] = 4ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 0));
    cpu->regs[1] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[26] * (uint64_t)(uint32_t)cpu->regs[1];
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
    cpu->regs[3] = cpu->regs[1] >> 30;
    goto L_148a48;
L_148cb4:
    cpu->regs[0] = cpu->regs[25] - 1ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14903c;
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 16));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_148cf4;
L_148cc4:
    cpu->regs[26] = cpu->regs[26] & 3ULL;
    cpu->regs[0] = cpu->regs[26] | (cpu->regs[0] << 3);
    PB_STR((cpu->regs[20] + 16), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    goto L_148c3c;
L_148cd8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[20] = cpu->regs[21];
    cpu->regs[28] = cpu->regs[24];
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[0];
    goto L_148958;
L_148cf4:
    cpu->regs[0] = cpu->regs[25] - 2ULL;
L_148cf8:
    if ((cpu->regs[0])==0) goto L_14903c;
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[1] = cpu->regs[0] - 1ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + (cpu->regs[1] << 2)));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_148d18;
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_NE) goto L_148cc4;
    goto L_148c38;
L_148d18:
    cpu->regs[0] = cpu->regs[1];
    goto L_148cf8;
L_148d20:
    cpu->regs[27] = cpu->regs[28] + 24ULL;
    cpu->regs[22] = cpu->regs[27] + (cpu->regs[21] << 2);
    if ((cpu->regs[21])==0) goto L_148c28;
    cpu->regs[4] = cpu->regs[22] - cpu->regs[28];
    cpu->regs[26] = cpu->regs[20] + 28ULL;
    cpu->regs[28] = cpu->regs[4] - 29ULL;
    cpu->regs[23] = 0ULL;
L_148d3c:
    cpu->regs[25] = cpu->regs[27];
    cpu->regs[24] = cpu->regs[26] - 4ULL;
    PB_LDRW(cpu->regs[19], cpu->regs[27]); cpu->regs[27] += 4;
    cpu->regs[30] = PB_BASE + 0x148d4cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x12cde0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_14929c;
    PB_LDRW(cpu->regs[1], (cpu->regs[26] + -4));
    cpu->regs[5] = cpu->regs[19] << 1;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[1] + (uint64_t)(uint32_t)cpu->regs[19] * (uint64_t)(uint32_t)cpu->regs[19];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[26] + -4), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] >> 30;
    FLAG_CMP(cpu->regs[22], cpu->regs[27]);
    if (FLAG_LS) goto L_148db4;
    cpu->regs[4] = cpu->regs[28] & 18446744073709551612ULL;
    cpu->regs[0] = 4ULL;
    cpu->regs[4] = cpu->regs[4] + 8ULL;
L_148d80:
    PB_LDRW(cpu->regs[2], (cpu->regs[25] + cpu->regs[0]));
    PB_LDRW(cpu->regs[3], (cpu->regs[24] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] * cpu->regs[5] + cpu->regs[3];
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[24] + cpu->regs[0]), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] + 4ULL;
    cpu->regs[1] = cpu->regs[1] >> 30;
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_NE) goto L_148d80;
    cpu->regs[0] = cpu->regs[28] & 18446744073709551612ULL;
    cpu->regs[2] = cpu->regs[26] + 4ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
L_148db4:
    if ((cpu->regs[1])!=0) goto L_148dd8;
L_148db8:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[26] = cpu->regs[26] + 8ULL;
    cpu->regs[28] = cpu->regs[28] - 4ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_NE) goto L_148d3c;
    PB_LDR(cpu->regs[26], (cpu->regs[20] + 16));
    cpu->regs[25] = cpu->regs[26] >> 3;
    goto L_148c28;
L_148dd8:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] >> 30;
    if ((cpu->regs[1])==0) goto L_148db8;
    PB_STRW((cpu->regs[0] + 4), cpu->regs[1]);
    goto L_148db8;
L_148df8:
    FLAG_CMP(cpu->regs[21], cpu->regs[20]);
    if (FLAG_GE) goto L_1490bc;
    cpu->regs[22] = (uint64_t)((int64_t)cpu->regs[21] >> 1);
    cpu->regs[3] = SP + 72ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[2] = SP + 80ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x148e18ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x25ad00ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14926c;
    FLAG_CMP(cpu->regs[28], cpu->regs[24]);
    if (FLAG_EQ) goto L_149078;
    cpu->regs[3] = SP + 56ULL;
    cpu->regs[2] = SP + 64ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x148e3cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x25ad00ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14926c;
L_148e44:
    cpu->regs[0] = cpu->regs[20] + cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x148e4cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14926c;
    PB_LDR(cpu->regs[1], (SP + 64));
    PB_STR((SP + 16), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (SP + 80));
    PB_STR((SP + 32), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x148e68ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x148900ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14923c;
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    cpu->regs[23] = cpu->regs[20] + 24ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[25] = cpu->regs[23] + (cpu->regs[22] << 3);
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[26] = cpu->regs[22] << 3;
    cpu->regs[2] = cpu->regs[2] >> 3;
    cpu->regs[2] = cpu->regs[2] << 2;
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_LO) goto L_149064;
    if (FLAG_LS) goto L_148eb0;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_LO) goto L_149074;
L_148eb0:
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[21] = 18446744073709551614ULL;
    cpu->regs[30] = PB_BASE + 0x148ec0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[21] = cpu->regs[22] * cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[21] + (cpu->regs[1] >> 3);
    cpu->regs[1] = cpu->regs[1] - (cpu->regs[0] >> 3); FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[0] = cpu->regs[0] >> 3;
    if (FLAG_NE) goto L_14904c;
L_148edc:
    PB_LDR(cpu->regs[1], (SP + 56));
    PB_STR((SP + 24), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (SP + 72));
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x148ef0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x148900ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1492c8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[27] = cpu->regs[0] + 24ULL;
    cpu->regs[2] = cpu->regs[2] >> 3;
    cpu->regs[2] = cpu->regs[2] << 2;
    FLAG_CMP(cpu->regs[23], cpu->regs[27]);
    if (FLAG_LO) goto L_1490ac;
    if (FLAG_LS) goto L_148f20;
    cpu->regs[0] = cpu->regs[27] + cpu->regs[2];
    FLAG_CMP(cpu->regs[23], cpu->regs[0]);
    if (FLAG_LO) goto L_149074;
L_148f20:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x148f2cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 16));
    cpu->regs[21] = cpu->regs[21] + (cpu->regs[3] >> 3); FLAG_CMP(cpu->regs[21], 0);
    cpu->regs[0] = cpu->regs[3] >> 3;
    if (FLAG_NE) goto L_149208;
L_148f3c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[21] = 18446744073709551612ULL;
    cpu->regs[3] = cpu->regs[3] >> 3;
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[21] = cpu->regs[22] * cpu->regs[21] + cpu->regs[25];
    cpu->regs[1] = cpu->regs[1] >> 3;
    cpu->regs[22] = cpu->regs[1] - cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x148f64ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x25ae40ULL);
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x148f6cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x12ed20ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[3] >> 3;
    cpu->regs[30] = PB_BASE + 0x148f84ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x25ae40ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x148f8cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x12ed20ULL);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[25], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x148f9cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x149310ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_149238;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x148facULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x12ed20ULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x148fb4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x12ed20ULL);
    PB_STR((SP + 72), 0ULL); PB_STR((SP + 72) + 8, 0ULL);
    FLAG_CMP(cpu->regs[28], cpu->regs[24]);
    if (FLAG_EQ) goto L_1491f0;
    PB_LDR(cpu->regs[0], (SP + 16)); PB_LDR(cpu->regs[1], (SP + 16) + 8);
    cpu->regs[30] = PB_BASE + 0x148fc8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x149310ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_149224;
L_148fd0:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x148fd8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x12ed20ULL);
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x148fe0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x12ed20ULL);
    PB_STR((SP + 56), 0ULL); PB_STR((SP + 56) + 8, 0ULL);
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x148ff0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x148900ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x148ffcULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x12ed20ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x149004ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x12ed20ULL);
    if ((cpu->regs[19])==0) goto L_149238;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[19] + 24ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[3] >> 3;
    cpu->regs[30] = PB_BASE + 0x149020ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x25b028ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x149028ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x12ed20ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x149030ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x145d20ULL);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    cpu->regs[20] = cpu->regs[0];
    goto L_148c3c;
L_14903c:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[20] + 16), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    goto L_148c3c;
L_14904c:
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[0] << 2);
    cpu->regs[2] = cpu->regs[1] << 2;
    cpu->regs[0] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x149060ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7aee0ULL);
    goto L_148edc;
L_149064:
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[25] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_148eb0;
L_149074:
    __builtin_trap();
L_149078:
    PB_LDR(cpu->regs[2], (SP + 80));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_14908c;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_14908c:
    PB_LDR(cpu->regs[1], (SP + 72));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 64), cpu->regs[2]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1490a4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1490a4:
    PB_STR((SP + 56), cpu->regs[1]);
    goto L_148e44;
L_1490ac:
    cpu->regs[0] = cpu->regs[23] + cpu->regs[2];
    FLAG_CMP(cpu->regs[27], cpu->regs[0]);
    if (FLAG_HS) goto L_148f20;
    __builtin_trap();
L_1490bc:
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 16));
    PB_LDR(cpu->regs[21], (cpu->regs[28] + 16));
    cpu->regs[26] = cpu->regs[0] >> 3;
    cpu->regs[0] = cpu->regs[26] + (cpu->regs[21] >> 3);
    cpu->regs[21] = cpu->regs[21] >> 3;
    cpu->regs[30] = PB_BASE + 0x1490d8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1492b0;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[2] = cpu->regs[2] >> 3;
    cpu->regs[2] = cpu->regs[2] << 2;
    cpu->regs[30] = PB_BASE + 0x1490fcULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x149104ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_149274;
    cpu->regs[24] = cpu->regs[24] + 24ULL;
    cpu->regs[25] = cpu->regs[0] + 24ULL;
    cpu->regs[23] = 0ULL;
    goto L_149184;
L_14911c:
    cpu->regs[0] = cpu->regs[25] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_149074;
L_149128:
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 16), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x149134ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[0] = cpu->regs[27] << 3;
    PB_STR((cpu->regs[20] + 16), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x149148ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x148900ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_149274;
    cpu->regs[2] = cpu->regs[0] + 24ULL;
    cpu->regs[26] = cpu->regs[26] - cpu->regs[27];
    PB_LDR(cpu->regs[0], (SP + 8)); PB_LDR(cpu->regs[3], (SP + 8) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    cpu->regs[1] = cpu->regs[1] >> 3;
    PB_LDR(cpu->regs[3], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[23];
    cpu->regs[23] = cpu->regs[23] + cpu->regs[27];
    cpu->regs[3] = cpu->regs[3] >> 3;
    cpu->regs[30] = PB_BASE + 0x14917cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x25b028ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x149184ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x12ed20ULL);
L_149184:
    FLAG_CMP(cpu->regs[26], 0ULL);
    if (FLAG_LE) goto L_1491bc;
    FLAG_CMP(cpu->regs[21], cpu->regs[26]);
    cpu->regs[1] = cpu->regs[24] + (cpu->regs[23] << 2);
    cpu->regs[27] = (FLAG_LE) ? cpu->regs[21] : cpu->regs[26];
    cpu->regs[3] = cpu->regs[23] << 2;
    cpu->regs[2] = cpu->regs[27] << 2;
    FLAG_CMP(cpu->regs[25], cpu->regs[1]);
    if (FLAG_LO) goto L_14911c;
    if (FLAG_LS) goto L_149128;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[25], cpu->regs[0]);
    if (FLAG_HS) goto L_149128;
    __builtin_trap();
L_1491bc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1491c4ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x12ed20ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1491ccULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x145d20ULL);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    cpu->regs[20] = cpu->regs[0];
    goto L_148c3c;
L_1491d8:
    PB_STR((SP + 160), cpu->regs[25]); PB_STR((SP + 160) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1491e0ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1491e0:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[20] = cpu->regs[20] + 3208ULL;
    goto L_148c3c;
L_1491f0:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_149200;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_149200:
    cpu->regs[24] = cpu->regs[23];
    goto L_148fd0;
L_149208:
    cpu->regs[2] = 18446744073709551612ULL;
    cpu->regs[0] = cpu->regs[23] + (cpu->regs[0] << 2);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = cpu->regs[21] * cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x14921cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x7aee0ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[26] + 16));
    goto L_148f3c;
L_149224:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_149238;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1492ec;
L_149238:
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
L_14923c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x149244ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 80));
    cpu->regs[30] = PB_BASE + 0x14924cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 72));
    cpu->regs[30] = PB_BASE + 0x149254ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[30] = PB_BASE + 0x14925cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x149264ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x18d760ULL);
L_149264:
    cpu->regs[20] = 0ULL;
    goto L_148c3c;
L_14926c:
    cpu->regs[20] = 0ULL;
    goto L_14923c;
L_149274:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_149288;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1492bc;
L_149288:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x149294ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    goto L_148c3c;
L_14929c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1492b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1492fc;
L_1492b0:
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    cpu->regs[20] = 0ULL;
    goto L_148c3c;
L_1492bc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1492c4ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_149288;
L_1492c8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_149238;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_149238;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1492e4ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    goto L_14923c;
L_1492ec:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1492f4ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    goto L_14923c;
L_1492fc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x149308ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 160)); PB_LDR(cpu->regs[26], (SP + 160) + 8);
    goto L_148c3c;
L_149310:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 16));
    cpu->regs[20] = cpu->regs[20] >> 3;
    cpu->regs[19] = cpu->regs[19] >> 3;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_GT) goto L_149630;
    cpu->regs[0] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x149348ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_14967c;
    if ((cpu->regs[19])==0) goto L_149624;
L_149350:
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 24));
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + 24));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + cpu->regs[1]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 24), cpu->regs[1]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_149488;
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 28));
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + 28));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] + cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 28), cpu->regs[1]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_149488;
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 32));
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + 32));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] + cpu->regs[2]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 32), cpu->regs[1]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    FLAG_CMP(cpu->regs[19], 3ULL);
    if (FLAG_EQ) goto L_149488;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 36));
    PB_LDRW(cpu->regs[3], (cpu->regs[22] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 36), cpu->regs[2]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[19], 4ULL);
    if (FLAG_EQ) goto L_149488;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 40));
    PB_LDRW(cpu->regs[3], (cpu->regs[22] + 40));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 40), cpu->regs[2]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[19], 5ULL);
    if (FLAG_EQ) goto L_149488;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 44));
    PB_LDRW(cpu->regs[3], (cpu->regs[22] + 44));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 44), cpu->regs[2]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[19], 6ULL);
    if (FLAG_EQ) goto L_149488;
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 48));
    PB_LDRW(cpu->regs[3], (cpu->regs[22] + 48));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + 48), cpu->regs[2]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[19], 7ULL);
    if (FLAG_EQ) goto L_149488;
    cpu->regs[1] = cpu->regs[19] + 6ULL;
    cpu->regs[4] = 52ULL;
    cpu->regs[1] = cpu->regs[1] << 2;
    /* nop */
    /* nop */
    /* nop */
L_149460:
    PB_LDRW(cpu->regs[3], (cpu->regs[21] + cpu->regs[4]));
    PB_LDRW(cpu->regs[5], (cpu->regs[22] + cpu->regs[4]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + cpu->regs[5]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[0] + cpu->regs[4]), cpu->regs[3]);
    cpu->regs[4] = cpu->regs[4] + 4ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    FLAG_CMP(cpu->regs[4], cpu->regs[1]);
    if (FLAG_NE) goto L_149460;
L_149488:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_LE) goto L_149608;
L_149490:
    cpu->regs[4] = cpu->regs[21] + (cpu->regs[19] << 2);
    cpu->regs[3] = cpu->regs[0] + (cpu->regs[19] << 2);
    cpu->regs[5] = cpu->regs[19] + 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[4] + 24));
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[3] + 24), cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[5], cpu->regs[20]);
    if (FLAG_GE) goto L_149580;
    PB_LDRW(cpu->regs[5], (cpu->regs[4] + 28));
    cpu->regs[2] = cpu->regs[19] + 2ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[5]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[3] + 28), cpu->regs[5]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_GE) goto L_149580;
    PB_LDRW(cpu->regs[5], (cpu->regs[4] + 32));
    cpu->regs[2] = cpu->regs[19] + 3ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[5]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[3] + 32), cpu->regs[5]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_GE) goto L_149580;
    PB_LDRW(cpu->regs[5], (cpu->regs[4] + 36));
    cpu->regs[2] = cpu->regs[19] + 4ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[5]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[3] + 36), cpu->regs[5]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_GE) goto L_149580;
    PB_LDRW(cpu->regs[5], (cpu->regs[4] + 40));
    cpu->regs[2] = cpu->regs[19] + 5ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[5]));
    cpu->regs[5] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[3] + 40), cpu->regs[5]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_GE) goto L_149580;
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 44));
    cpu->regs[19] = cpu->regs[19] + 6ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[3] + 44), cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_GE) goto L_149580;
    cpu->regs[21] = cpu->regs[21] + 24ULL;
    cpu->regs[3] = cpu->regs[0] + 24ULL;
L_149560:
    PB_LDRW(cpu->regs[2], (cpu->regs[21] + (cpu->regs[19] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[3] + (cpu->regs[19] << 2)), cpu->regs[2]);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] >> 30));
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_NE) goto L_149560;
L_149580:
    cpu->regs[20] = cpu->regs[0] + (cpu->regs[20] << 2);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[20] + 24), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[3] >> 3;
    if ((cpu->regs[1])==0) goto L_1495a0;
L_149594:
    cpu->regs[4] = cpu->regs[0] + (cpu->regs[1] << 2);
    PB_LDRW(cpu->regs[2], (cpu->regs[4] + 20));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_1495b0;
L_1495a0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1495b0:
    cpu->regs[2] = cpu->regs[1] - 1ULL; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_14965c;
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + 16));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1495dc;
L_1495c0:
    cpu->regs[3] = cpu->regs[3] & 3ULL;
    cpu->regs[2] = cpu->regs[3] | (cpu->regs[2] << 3);
    PB_STR((cpu->regs[0] + 16), cpu->regs[2]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1495dc:
    cpu->regs[2] = cpu->regs[1] - 2ULL;
    cpu->regs[6] = cpu->regs[0] + 24ULL;
L_1495e4:
    cpu->regs[4] = cpu->regs[2] - 1ULL;
    if ((cpu->regs[2])==0) goto L_14965c;
    PB_LDRW(cpu->regs[5], (cpu->regs[6] + (cpu->regs[4] << 2)));
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_149600;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_1495c0;
    goto L_1495a0;
L_149600:
    cpu->regs[2] = cpu->regs[4];
    goto L_1495e4;
L_149608:
    cpu->regs[20] = cpu->regs[19];
L_14960c:
    cpu->regs[20] = cpu->regs[0] + (cpu->regs[20] << 2);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[20] + 24), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[3] >> 3;
    if ((cpu->regs[1])!=0) goto L_149594;
    goto L_1495a0;
L_149624:
    cpu->regs[2] = 0ULL;
    if ((cpu->regs[20])!=0) goto L_149490;
    goto L_14960c;
L_149630:
    cpu->regs[0] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x149638ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_14967c;
    if ((cpu->regs[20])==0) goto L_149668;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[20] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[22];
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[1];
    goto L_149350;
L_14965c:
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_1495a0;
L_149668:
    cpu->regs[20] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[22];
    cpu->regs[19] = 0ULL;
    cpu->regs[2] = 0ULL;
    goto L_149490;
L_14967c:
    cpu->regs[0] = 0ULL;
    goto L_1495a0;
}
