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

void ft_PyUnicode_GetDefaultEncoding(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[0] + 1576ULL;
    return;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 32));
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x7aeb0ULL); return; };
    SP = SP - 112ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])==0) goto L_81014;
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    goto L_81018;
L_81014:
    cpu->regs[19] = 0ULL;
L_81018:
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[19] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LT) goto L_8103c;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LE) goto L_81070;
L_8103c:
    cpu->regs[2] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[4] = cpu->regs[4] + 4000ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x81064ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_81070;
L_81068:
    cpu->regs[19] = 0ULL;
    goto L_811ac;
L_81070:
    if ((cpu->regs[19])==0) goto L_810a4;
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0));
    if ((cpu->regs[22])==0) goto L_81084;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_810ac;
L_81084:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x8108cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_810ac;
    cpu->regs[30] = PB_BASE + 0x8109cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_810ac;
    goto L_81068;
L_810a4:
    cpu->regs[19] = 1ULL;
    cpu->regs[22] = 0ULL;
L_810ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 40));
    if (((cpu->regs[0] >> 0) & 1)) goto L_810c0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 16));
    if (!((cpu->regs[1] >> 0) & 1)) goto L_810dc;
L_810c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[1] = cpu->regs[1] + 96ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x810d8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_81068;
L_810dc:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 72));
    cpu->regs[23] = cpu->regs[20] + 56ULL;
    cpu->regs[2] = 10ULL;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(cpu->regs[2]))), 0);
    if (FLAG_EQ) goto L_81128;
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_811c0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    cpu->regs[3] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 112ULL;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x233050ULL); return; };
L_81128:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x81130ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_81068;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 16));
    cpu->regs[24] = cpu->regs[0] + 32ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[3] = 67ULL;
    cpu->regs[30] = PB_BASE + 0x81150ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1e70e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_81178;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_81068;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_81068;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x81174ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_81068;
L_81178:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x8118cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x233050ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_811ac;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_811ac;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x811acULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_811ac:
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_811c4;
L_811c0:
    cpu->regs[30] = PB_BASE + 0x811c4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c170ULL);
L_811c4:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    if (((cpu->regs[1] >> 63) & 1)) goto L_81204;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_81210;
    goto L_81278;
L_81204:
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    cpu->regs[1] = 0ULL;
    goto L_81238;
L_81210:
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    if ((cpu->regs[1])==0) goto L_81238;
    cpu->regs[0] = 9223372036854775807ULL;
    cpu->regs[0] = (cpu->regs[1] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[1]) : 0);
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GE) goto L_81238;
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_81238:
    cpu->regs[20] = cpu->regs[21] * cpu->regs[1];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x81248ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1e6c20ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_8128c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_81260;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 40));
    goto L_81268;
L_81260:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3336));
L_81268:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x81278ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x16bdc8ULL);
L_81278:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_81290;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_81290;
L_8128c:
    cpu->regs[19] = 0ULL;
L_81290:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[2] = 2ULL;
    cpu->regs[3] = (cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[2]) : 0);
    if ((cpu->regs[1])==0) goto L_812bc;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 40));
    goto L_812c4;
L_812bc:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3336));
L_812c4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[0] = 0ULL;
L_812d0:
    cpu->regs[4] = (uint64_t)(-(int64_t)cpu->regs[0]);
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_LE) goto L_812f4;
    PB_LDRB(cpu->regs[6], (cpu->regs[1] + cpu->regs[4]));
    PB_LDRB(cpu->regs[5], (cpu->regs[2] + cpu->regs[0]));
    PB_STRB((cpu->regs[2] + cpu->regs[0]), cpu->regs[6]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STRB((cpu->regs[1] + cpu->regs[4]), cpu->regs[5]);
    goto L_812d0;
L_812f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x8131cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[6] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_81334;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x81334ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1f6100ULL);
L_81334:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[6];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x81360ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[10] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_81378;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x81378ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x80f58ULL);
L_81378:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[10];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
