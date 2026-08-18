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

void ft__PyTime_FromTimespec(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0)); PB_LDR(cpu->regs[2], (cpu->regs[1] + 0) + 8);
    cpu->regs[3] = 1ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x21c544ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x26dbe8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x123ed0ULL);
    if ((cpu->regs[0])==0) goto L_26dc9c;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x26dbf4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 0));
    if (((cpu->regs[3] >> 31) & 1)) goto L_26dc0c;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[3]);
    if ((cpu->regs[3])==0) goto L_26dcac;
L_26dc0c:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_26dc9c;
L_26dc14:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_GT) goto L_26dc34;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x1c5c40ULL); return; };
L_26dc34:
    cpu->regs[20] = cpu->regs[20] - cpu->regs[0];
    cpu->regs[3] = 48ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26dc4cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x26dd00ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26dca4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[3] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_26dcd8;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[1] = cpu->regs[4] + 56ULL;
    cpu->regs[0] = cpu->regs[4] + 40ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
L_26dc70:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x26dc7cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] - 43ULL));
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(4294967293ULL))), 0);
    if (FLAG_EQ) goto L_26dcb8;
L_26dc88:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_26dc9c:
    cpu->regs[30] = PB_BASE + 0x26dca0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_26dce0;
L_26dca4:
    cpu->regs[4] = 0ULL;
    goto L_26dc88;
L_26dcac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x26dcb4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_26dc0c;
L_26dcb8:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_26dce8;
    PB_STRB((cpu->regs[1] + 0), cpu->regs[0]);
L_26dcc4:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[3] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x26dcd4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11ce20ULL);
    goto L_26dc88;
L_26dcd8:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 56));
    goto L_26dc70;
L_26dce0:
    cpu->regs[20] = 18446744073709551615ULL;
    goto L_26dc14;
L_26dce8:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_26dcf8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_26dcc4;
L_26dcf8:
    PB_STRH((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_26dcc4;
L_26dd00:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1] & ~(((uint64_t)((int64_t)cpu->regs[1] >> 63)));
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[2] & ~(((uint64_t)((int64_t)cpu->regs[2] >> 63)));
    cpu->regs[1] = cpu->regs[25] | cpu->regs[21];
    if ((cpu->regs[1])==0) goto L_26de24;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[23] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = 9223372036854775807ULL;
    cpu->regs[2] = cpu->regs[1] - cpu->regs[0];
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_LT) goto L_26de40;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    FLAG_CMP(cpu->regs[25], cpu->regs[1]);
    if (FLAG_GT) goto L_26de40;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 32));
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[1] = 127ULL;
    if (!((cpu->regs[2] >> 6) & 1)) goto L_26de60;
L_26dd68:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[1])));
    cpu->regs[0] = cpu->regs[25] + cpu->regs[0];
    cpu->regs[1] = (FLAG_HS) ? cpu->regs[22] : cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x26dd78ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_26de58;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[27] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_26de38;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[1] = cpu->regs[19] + 40ULL;
    cpu->regs[26] = cpu->regs[19] + 56ULL;
    cpu->regs[26] = (FLAG_EQ) ? cpu->regs[26] : cpu->regs[1];
L_26dda0:
    FLAG_CMP(cpu->regs[24], 0ULL);
    if (FLAG_LE) goto L_26ddc0;
    cpu->regs[4] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26ddc0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x20700cULL);
L_26ddc0:
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_GT) goto L_26de04;
L_26ddc8:
    PB_LDR(cpu->regs[4], (cpu->regs[20] + 16));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x26dde4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11ae68ULL);
    PB_LDR(cpu->regs[27], (SP + 80));
L_26dde8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_26de04:
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 16));
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[3] = cpu->regs[21] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x26de20ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x20700cULL);
    goto L_26ddc8;
L_26de24:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x1c5c40ULL); return; };
L_26de38:
    PB_LDR(cpu->regs[26], (cpu->regs[19] + 56));
    goto L_26dda0;
L_26de40:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 3080ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x26de58ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_26de58:
    cpu->regs[19] = 0ULL;
    goto L_26dde8;
L_26de60:
    cpu->regs[2] = ((uint32_t)(((cpu->regs[2] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_26de80;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    cpu->regs[1] = 65535ULL;
    cpu->regs[2] = 1114111ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    goto L_26dd68;
L_26de80:
    cpu->regs[1] = 255ULL;
    goto L_26dd68;
}
