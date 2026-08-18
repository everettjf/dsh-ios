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

void ft_PyObject_Print(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xad848ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x12cde0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ad954;
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xad858ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7bb90ULL);
    if ((cpu->regs[19])!=0) goto L_ad888;
    cpu->regs[30] = PB_BASE + 0xad860ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = 5ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 1960ULL;
    cpu->regs[30] = PB_BASE + 0xad87cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7b510ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xad884ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    goto L_ad930;
L_ad888:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_ad8c0;
    cpu->regs[30] = PB_BASE + 0xad898ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 1968ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xad8b4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b6e0ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xad8bcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    goto L_ad930;
L_ad8c0:
    cpu->regs[0] = cpu->regs[19];
    if (!((cpu->regs[22] >> 0) & 1)) goto L_ad8d4;
    cpu->regs[30] = PB_BASE + 0xad8ccULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x12cb88ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_ad8dc;
L_ad8d4:
    cpu->regs[30] = PB_BASE + 0xad8d8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x14d650ULL);
    cpu->regs[19] = cpu->regs[0];
L_ad8dc:
    if ((cpu->regs[19])==0) goto L_ad954;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xad8ecULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    if ((cpu->regs[0])==0) goto L_ad904;
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xad900ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b510ULL);
    goto L_ad908;
L_ad904:
    cpu->regs[21] = 4294967295ULL;
L_ad908:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_ad92c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_ad92c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xad92cULL; PB_CALL(13, cpu, tlb, cpu->regs[1]);
L_ad92c:
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_ad954;
L_ad930:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xad938ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7b7c0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ad958;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xad94cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xad954ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7bb90ULL);
L_ad954:
    cpu->regs[0] = 4294967295ULL;
L_ad958:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ad978;
    cpu->regs[30] = PB_BASE + 0xad978ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ad978:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 208ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 160), cpu->regs[29]); PB_STR((SP + 160) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 160ULL;
    PB_STR((SP + 176), cpu->regs[19]); PB_STR((SP + 176) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 192), cpu->regs[21]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 152), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_ad9d8;
L_ad9c0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0xad9c8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ada00;
    goto L_ad9f8;
L_ad9d8:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1992ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xad9f0ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ad9c0;
    goto L_ada90;
L_ad9f8:
    cpu->regs[30] = PB_BASE + 0xad9fcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ada90;
L_ada00:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0xada08ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ada1c;
    cpu->regs[30] = PB_BASE + 0xada18ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ada90;
L_ada1c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[19] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(63ULL)));
    if (FLAG_LS) goto L_ada44;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xada40ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_ada90;
L_ada44:
    cpu->regs[2] = SP;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xada54ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7c030ULL);
    PB_LDRW(cpu->regs[3], (SP + 136));
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] & 4026531839ULL));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | 268435456ULL));
    cpu->regs[3] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[2];
    cpu->regs[2] = 0ULL;
    PB_STRW((SP + 136), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xada7cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7c030ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ada98;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xada90ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_ada90:
    cpu->regs[0] = 0ULL;
    goto L_adaa0;
L_ada98:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_adaa0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 152));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_adac0;
    cpu->regs[30] = PB_BASE + 0xadac0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7c170ULL);
L_adac0:
    PB_LDR(cpu->regs[21], (SP + 192));
    PB_LDR(cpu->regs[29], (SP + 160)); PB_LDR(cpu->regs[30], (SP + 160) + 8);
    PB_LDR(cpu->regs[19], (SP + 176)); PB_LDR(cpu->regs[20], (SP + 176) + 8);
    SP = SP + 208ULL;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[2] - 2ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_HI) goto L_adb14;
L_adafc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0xadb04ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_adb40;
    goto L_adb38;
L_adb14:
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 2008ULL;
    cpu->regs[3] = 4ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xadb2cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_adafc;
L_adb30:
    cpu->regs[0] = 0ULL;
    goto L_adbf8;
L_adb38:
    cpu->regs[30] = PB_BASE + 0xadb3cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_adb30;
L_adb40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0xadb48ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[22] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_adb5c;
    cpu->regs[30] = PB_BASE + 0xadb58ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_adb30;
L_adb5c:
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_LE) goto L_adbc0;
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[20], 3ULL);
    if (FLAG_EQ) goto L_adb90;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0xadb78ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[4] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_adb94;
    cpu->regs[30] = PB_BASE + 0xadb88ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_adb94;
    goto L_adb30;
L_adb90:
    cpu->regs[4] = 0ULL;
L_adb94:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[23], cpu->regs[0]);
    if (FLAG_EQ) goto L_adbc4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 2032ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xadbbcULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_adb30;
L_adbc0:
    cpu->regs[4] = 0ULL;
L_adbc4:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = 424ULL;
    cpu->regs[30] = PB_BASE + 0xadbd8ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7bc60ULL);
    if (!((cpu->regs[0] >> 63) & 1)) goto L_adbf0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xadbecULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_adb30;
L_adbf0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_adbf8:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP = SP - 304ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 272), cpu->regs[29]); PB_STR((SP + 272) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 272ULL;
    PB_STR((SP + 288), cpu->regs[19]); PB_STR((SP + 288) + 8, cpu->regs[20]);
    cpu->regs[20] = SP + 8ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 264), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xadc40ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xad27cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_adca8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[19] = SP + 136ULL;
    cpu->regs[2] = 128ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xadc58ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[30] = PB_BASE + 0xadc5cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xadc6cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x7abe0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xadc78ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_adc9c;
    cpu->regs[30] = PB_BASE + 0xadc80ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_STRW((cpu->regs[0] + 0), cpu->regs[19]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xadc94ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_adcac;
L_adc9c:
    do { int32_t _s=0; tlb_read(tlb,(SP + 4),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xadca4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe2620ULL);
    goto L_adcac;
L_adca8:
    cpu->regs[0] = 0ULL;
L_adcac:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 264));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_adccc;
    cpu->regs[30] = PB_BASE + 0xadcccULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7c170ULL);
L_adccc:
    PB_LDR(cpu->regs[29], (SP + 272)); PB_LDR(cpu->regs[30], (SP + 272) + 8);
    PB_LDR(cpu->regs[19], (SP + 288)); PB_LDR(cpu->regs[20], (SP + 288) + 8);
    SP = SP + 304ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0xadcf8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x7b460ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GE) goto L_add18;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xadd10ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_add10:
    cpu->regs[20] = 0ULL;
    goto L_adde0;
L_add18:
    if (FLAG_NE) goto L_add30;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(49, cpu, tlb, PB_BASE + 0xd8bc0ULL); return; };
L_add30:
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = ((cpu->regs[20] & 0xffffffffULL) << 2);
    cpu->regs[30] = PB_BASE + 0xadd3cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_add54;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(51, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_add54:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xadd60ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x7b460ULL);
    cpu->regs[22] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_add88;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xadd7cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xadd84ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_add10;
L_add88:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0xadd90ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_addcc;
    cpu->regs[21] = 0ULL;
L_add9c:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_LE) goto L_addc0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + (cpu->regs[21] << 2)));
    cpu->regs[30] = PB_BASE + 0xaddacULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x7aff0ULL);
    if ((cpu->regs[0])==0) goto L_addcc;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    PB_STR((cpu->regs[1] + (((uint64_t)(uint32_t)(cpu->regs[21])) << 3)), cpu->regs[0]);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_add9c;
L_addc0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaddc8ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_adde0;
L_addcc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaddd4ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xadddcULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_add10;
L_adde0:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = SP + 20ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = SP + 12ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xade28ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x7ba20ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ade44;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xade3cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_ade7c;
L_ade44:
    PB_LDRW(cpu->regs[0], (SP + 12));
    cpu->regs[30] = PB_BASE + 0xade4cULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x7aff0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0xade58ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x7aff0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 20));
    cpu->regs[30] = PB_BASE + 0xade64ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x7aff0ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 2056ULL;
    cpu->regs[30] = PB_BASE + 0xade7cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1e5ca0ULL);
L_ade7c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ade9c;
    cpu->regs[30] = PB_BASE + 0xade9cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ade9c:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = SP + 20ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = SP + 12ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xadee0ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x7b3f0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_adefc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xadef4ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_adf34;
L_adefc:
    PB_LDRW(cpu->regs[0], (SP + 12));
    cpu->regs[30] = PB_BASE + 0xadf04ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1c8fd0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0xadf10ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1c8fd0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 20));
    cpu->regs[30] = PB_BASE + 0xadf1cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x1c8fd0ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 2056ULL;
    cpu->regs[30] = PB_BASE + 0xadf34ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x1e5ca0ULL);
L_adf34:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_adf54;
    cpu->regs[30] = PB_BASE + 0xadf54ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x7c170ULL);
L_adf54:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xadf78ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_adf8c;
    cpu->regs[30] = PB_BASE + 0xadf88ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_adfd4;
L_adf8c:
    cpu->regs[30] = PB_BASE + 0xadf90ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    PB_STRW((cpu->regs[19] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0xadfa0ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x7b4c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_adfc4;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_adfc4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xadfc0ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_adfd4;
L_adfc4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(79, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_adfd4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xadff4ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ae008;
    cpu->regs[30] = PB_BASE + 0xae004ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ae034;
L_ae008:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xae010ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x7b8c0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae028;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae024ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae034;
L_ae028:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = cpu->regs[0];
    { PB_CALL(84, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_ae034:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xae050ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xae058ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x7c0b0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xae064ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if (!((cpu->regs[19] >> 31) & 1)) goto L_ae080;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae078ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_ae088;
L_ae080:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae088:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 32ULL;
    cpu->regs[5] = 4294967295ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[0] = SP;
    PB_STRW((SP + 0), cpu->regs[5]); PB_STRW((SP + 0) + 4, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0xae0d4ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x7add0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ae0ec;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae0e8ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae130;
L_ae0ec:
    PB_LDRW(cpu->regs[0], (SP + 0));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xae0fcULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x1cb920ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ae130;
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xae114ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x1cb920ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ae130;
    PB_LDRW(cpu->regs[1], (SP + 0)); PB_LDRW(cpu->regs[2], (SP + 0) + 4);
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 2896ULL;
    cpu->regs[30] = PB_BASE + 0xae12cULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x1e5ca0ULL);
    goto L_ae154;
L_ae130:
    PB_LDRW(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ae140;
    cpu->regs[30] = PB_BASE + 0xae140ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x7b860ULL);
L_ae140:
    PB_LDRW(cpu->regs[0], (SP + 4));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ae150;
    cpu->regs[30] = PB_BASE + 0xae150ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x7b860ULL);
L_ae150:
    cpu->regs[0] = 0ULL;
L_ae154:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae174;
    cpu->regs[30] = PB_BASE + 0xae174ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae174:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
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
    cpu->regs[30] = PB_BASE + 0xae1acULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x232a84ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae1b8;
L_ae1b0:
    cpu->regs[0] = 0ULL;
    goto L_ae1e4;
L_ae1b8:
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0xae1c0ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x7b430ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ae1dc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae1d8ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae1b0;
L_ae1dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae1e4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae204;
    cpu->regs[30] = PB_BASE + 0xae204ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae204:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
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
    cpu->regs[30] = PB_BASE + 0xae23cULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xaa668ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae248;
L_ae240:
    cpu->regs[0] = 0ULL;
    goto L_ae270;
L_ae248:
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0xae250ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x7ab60ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae268;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae264ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae240;
L_ae268:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae270:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae290;
    cpu->regs[30] = PB_BASE + 0xae290ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae290:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
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
    cpu->regs[30] = PB_BASE + 0xae2c8ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xaa668ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae2d4;
L_ae2cc:
    cpu->regs[0] = 0ULL;
    goto L_ae2fc;
L_ae2d4:
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0xae2dcULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x7b9e0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae2f4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae2f0ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae2cc;
L_ae2f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae2fc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae31c;
    cpu->regs[30] = PB_BASE + 0xae31cULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae31c:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_ae36c;
L_ae358:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0xae364ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xaa668ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae390;
    goto L_ae388;
L_ae36c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2064ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xae384ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae358;
L_ae388:
    cpu->regs[0] = 0ULL;
    goto L_ae3c8;
L_ae390:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xae39cULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xaa668ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ae388;
    PB_LDRW(cpu->regs[1], (SP + 0)); PB_LDRW(cpu->regs[0], (SP + 0) + 4);
    cpu->regs[30] = PB_BASE + 0xae3a8ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x7b580ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae3c0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae3bcULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae388;
L_ae3c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae3c8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae3e8;
    cpu->regs[30] = PB_BASE + 0xae3e8ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae3e8:
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
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
    cpu->regs[30] = PB_BASE + 0xae424ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae430;
L_ae428:
    cpu->regs[0] = 0ULL;
    goto L_ae458;
L_ae430:
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0xae438ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x7aef0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae450;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae44cULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae428;
L_ae450:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae458:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae478;
    cpu->regs[30] = PB_BASE + 0xae478ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae478:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
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
    cpu->regs[30] = PB_BASE + 0xae4b0ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae4bc;
L_ae4b4:
    cpu->regs[0] = 0ULL;
    goto L_ae4e4;
L_ae4bc:
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0xae4c4ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x7b7d0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae4dc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae4d8ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae4b4;
L_ae4dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae4e4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae504;
    cpu->regs[30] = PB_BASE + 0xae504ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae504:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_ae554;
L_ae540:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0xae54cULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae578;
    goto L_ae570;
L_ae554:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2080ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xae56cULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae540;
L_ae570:
    cpu->regs[0] = 0ULL;
    goto L_ae5b0;
L_ae578:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xae584ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ae570;
    PB_LDRW(cpu->regs[1], (SP + 0)); PB_LDRW(cpu->regs[0], (SP + 0) + 4);
    cpu->regs[30] = PB_BASE + 0xae590ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0x7bd90ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae5a8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae5a4ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae570;
L_ae5a8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae5b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae5d0;
    cpu->regs[30] = PB_BASE + 0xae5d0ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae5d0:
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xae5ecULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x7bf80ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae608;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae600ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_ae610;
L_ae608:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae610:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xae624ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x7ad00ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae640;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae638ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_ae648;
L_ae640:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae648:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[4] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = SP + 4ULL;
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[2] + 2096ULL;
    cpu->regs[30] = PB_BASE + 0xae68cULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x22ee90ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae698;
L_ae690:
    cpu->regs[0] = 0ULL;
    goto L_ae6c0;
L_ae698:
    PB_LDRW(cpu->regs[1], (SP + 0)); PB_LDRW(cpu->regs[0], (SP + 0) + 4);
    cpu->regs[30] = PB_BASE + 0xae6a0ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x7bbe0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae6b8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae6b4ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae690;
L_ae6b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae6c0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae6e0;
    cpu->regs[30] = PB_BASE + 0xae6e0ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae6e0:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xae6fcULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ae710;
    cpu->regs[30] = PB_BASE + 0xae70cULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ae73c;
L_ae710:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xae718ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0x7bf60ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae730;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae72cULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae73c;
L_ae730:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    { PB_CALL(141, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_ae73c:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[4] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = SP + 4ULL;
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[2] + 2112ULL;
    cpu->regs[30] = PB_BASE + 0xae784ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x22ee90ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae790;
L_ae788:
    cpu->regs[0] = 0ULL;
    goto L_ae7b8;
L_ae790:
    PB_LDRW(cpu->regs[1], (SP + 0)); PB_LDRW(cpu->regs[0], (SP + 0) + 4);
    cpu->regs[30] = PB_BASE + 0xae798ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x7be50ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_ae7b0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae7acULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ae788;
L_ae7b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_ae7b8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae7d8;
    cpu->regs[30] = PB_BASE + 0xae7d8ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae7d8:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
    SP = SP - 64ULL;
    FLAG_CMP(cpu->regs[2], 3ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 3080));
    if (FLAG_NE) goto L_ae838;
L_ae820:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0xae828ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ae860;
    goto L_ae858;
L_ae838:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[0] = cpu->regs[0] + 2128ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xae850ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ae820;
    goto L_ae904;
L_ae858:
    cpu->regs[30] = PB_BASE + 0xae85cULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ae904;
L_ae860:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0xae86cULL; PB_CALL(149, cpu, tlb, PB_BASE + 0xa9a70ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ae904;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0xae878ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ae88c;
    cpu->regs[30] = PB_BASE + 0xae888ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ae904;
L_ae88c:
    PB_LDR(cpu->regs[21], (SP + 0));
    cpu->regs[30] = PB_BASE + 0xae894ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xae8a8ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x7ae10ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xae8b4ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if (((cpu->regs[19] >> 63) & 1)) goto L_ae8e4;
L_ae8b8:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_ae918;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    { PB_CALL(155, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_ae8e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae8f4ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0x1b2720ULL);
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ae8b8;
    cpu->regs[30] = PB_BASE + 0xae900ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_ae8b8;
L_ae904:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_ae91c;
L_ae918:
    cpu->regs[30] = PB_BASE + 0xae91cULL; PB_CALL(158, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae91c:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 32ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xae95cULL; PB_CALL(159, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ae970;
    cpu->regs[30] = PB_BASE + 0xae96cULL; PB_CALL(160, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ae9ac;
L_ae970:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = SP;
    cpu->regs[30] = PB_BASE + 0xae97cULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x7bd30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ae998;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xae990ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_ae9b0;
L_ae998:
    PB_LDRW(cpu->regs[1], (SP + 0)); PB_LDRW(cpu->regs[2], (SP + 0) + 4);
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 2896ULL;
    cpu->regs[30] = PB_BASE + 0xae9a8ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0x1e5ca0ULL);
    goto L_ae9b0;
L_ae9ac:
    cpu->regs[0] = 0ULL;
L_ae9b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ae9d0;
    cpu->regs[30] = PB_BASE + 0xae9d0ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ae9d0:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
    SP = SP - 64ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_aea2c;
L_aea18:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0xaea24ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0x232a84ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aea4c;
    goto L_aeae0;
L_aea2c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2136ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaea44ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aea18;
    goto L_aeae0;
L_aea4c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[2] = PB_BASE + 0x51d000ULL;
    cpu->regs[2] = cpu->regs[2] + 3600ULL;
    cpu->regs[1] = SP;
    cpu->regs[2] = cpu->regs[2] + 3888ULL;
    cpu->regs[3] = 20ULL;
    cpu->regs[30] = PB_BASE + 0xaea68ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0x7f1e8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_aeae0;
    cpu->regs[30] = PB_BASE + 0xaea70ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[20], (SP + 0)); PB_LDRW(cpu->regs[19], (SP + 0) + 4);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_STRW((cpu->regs[20] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0xaea88ULL; PB_CALL(169, cpu, tlb, PB_BASE + 0x7b890ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aeab4;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_aeaac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaeaacULL; PB_CALL(170, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_aeaac:
    cpu->regs[30] = PB_BASE + 0xaeab0ULL; PB_CALL(171, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aeae0;
L_aeab4:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_aeaf4;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(172, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_aeae0:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_aeaf8;
L_aeaf4:
    cpu->regs[30] = PB_BASE + 0xaeaf8ULL; PB_CALL(173, cpu, tlb, PB_BASE + 0x7c170ULL);
L_aeaf8:
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 64ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_NE) goto L_aeb54;
L_aeb40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = SP + 20ULL;
    cpu->regs[30] = PB_BASE + 0xaeb4cULL; PB_CALL(174, cpu, tlb, PB_BASE + 0xaa668ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aeb78;
    goto L_aeb70;
L_aeb54:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[0] = cpu->regs[0] + 2152ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaeb6cULL; PB_CALL(175, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aeb40;
L_aeb70:
    cpu->regs[0] = 0ULL;
    goto L_aebc4;
L_aeb78:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0xaeb84ULL; PB_CALL(176, cpu, tlb, PB_BASE + 0xaa668ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_aeb70;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = SP + 12ULL;
    cpu->regs[30] = PB_BASE + 0xaeb94ULL; PB_CALL(177, cpu, tlb, PB_BASE + 0xaa668ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_aeb70;
    PB_LDRW(cpu->regs[2], (SP + 12)); PB_LDRW(cpu->regs[1], (SP + 12) + 4);
    PB_LDRW(cpu->regs[0], (SP + 20));
    cpu->regs[30] = PB_BASE + 0xaeba4ULL; PB_CALL(178, cpu, tlb, PB_BASE + 0x7ba30ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_aebbc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaebb8ULL; PB_CALL(179, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_aeb70;
L_aebbc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_aebc4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_aebe4;
    cpu->regs[30] = PB_BASE + 0xaebe4ULL; PB_CALL(180, cpu, tlb, PB_BASE + 0x7c170ULL);
L_aebe4:
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 64ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_NE) goto L_aec38;
L_aec24:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = SP + 20ULL;
    cpu->regs[30] = PB_BASE + 0xaec30ULL; PB_CALL(181, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aec5c;
    goto L_aec54;
L_aec38:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[0] = cpu->regs[0] + 2168ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaec50ULL; PB_CALL(182, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aec24;
L_aec54:
    cpu->regs[0] = 0ULL;
    goto L_aeca8;
L_aec5c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0xaec68ULL; PB_CALL(183, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_aec54;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = SP + 12ULL;
    cpu->regs[30] = PB_BASE + 0xaec78ULL; PB_CALL(184, cpu, tlb, PB_BASE + 0xaa80cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_aec54;
    PB_LDRW(cpu->regs[2], (SP + 12)); PB_LDRW(cpu->regs[1], (SP + 12) + 4);
    PB_LDRW(cpu->regs[0], (SP + 20));
    cpu->regs[30] = PB_BASE + 0xaec88ULL; PB_CALL(185, cpu, tlb, PB_BASE + 0x7b540ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_aeca0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaec9cULL; PB_CALL(186, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_aec54;
L_aeca0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_aeca8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_aecc8;
    cpu->regs[30] = PB_BASE + 0xaecc8ULL; PB_CALL(187, cpu, tlb, PB_BASE + 0x7c170ULL);
L_aecc8:
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3024));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    { PB_CALL(188, cpu, tlb, PB_BASE + 0x1b2740ULL); return; };
}
