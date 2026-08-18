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

void ft__PyUnicode_FindMaxChar(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[1])!=0) goto L_1dbe74;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_1dbe8c;
L_1dbe74:
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_EQ) goto L_1dbef8;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 32));
    cpu->regs[0] = 127ULL;
    if (!((cpu->regs[4] >> 6) & 1)) goto L_1dbeb8;
L_1dbe88:
    return;
L_1dbe8c:
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 32));
    cpu->regs[0] = 127ULL;
    if (((cpu->regs[1] >> 6) & 1)) goto L_1dbe88;
    cpu->regs[1] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1dbf00;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(2ULL)));
    cpu->regs[0] = 65535ULL;
    cpu->regs[1] = 1114111ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    return;
L_1dbeb8:
    cpu->regs[5] = ((uint32_t)(((cpu->regs[4] >> 2) & 0x7ULL)));
    if (!((cpu->regs[4] >> 5) & 1)) goto L_1dbef0;
    cpu->regs[3] = cpu->regs[3] + 56ULL;
L_1dbec4:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[2] = cpu->regs[2] * cpu->regs[0] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[1] * cpu->regs[0] + cpu->regs[3];
    cpu->regs[1] = cpu->regs[2];
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1dbee0;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x213344ULL); return; };
L_1dbee0:
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_1dbeec;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x196180ULL); return; };
L_1dbeec:
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x212f28ULL); return; };
L_1dbef0:
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 56));
    goto L_1dbec4;
L_1dbef8:
    cpu->regs[0] = 127ULL;
    return;
L_1dbf00:
    cpu->regs[0] = 255ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1dbf14ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7ac70ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x1c8fd0ULL); return; };
    /* nop */
    SP = SP - 128ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 96));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    PB_STR((cpu->regs[22] + 96), 0ULL);
    if ((cpu->regs[23])==0) goto L_1dc064;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 1488));
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1dc064;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2840));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[24] = PB_BASE + 0x293000ULL;
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[25] = SP + 16ULL;
    cpu->regs[26] = 0ULL;
    PB_STR((SP + 112), cpu->regs[27]); PB_STR((SP + 112) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    cpu->regs[30] = PB_BASE + 0x1dbf94ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    PB_STRW((SP + 12), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1dbfa0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x121b20ULL);
    cpu->regs[28] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[24] + 184ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    PB_STR((SP + 16), cpu->regs[28]);
    if ((cpu->regs[28])==0) goto L_1dc02c;
L_1dbfb4:
    PB_LDR(cpu->regs[24], (cpu->regs[28] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[28] + 16) + 8);
    cpu->regs[30] = PB_BASE + 0x1dbfbcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1dc120ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 0));
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 112));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1dbfd0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11d180ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1dc0bc;
L_1dbfd8:
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] ^ 1ULL));
    FLAG_CMP((((uint32_t)(cpu->regs[21]))) & (((uint32_t)(cpu->regs[19]))), 0);
    if (FLAG_NE) goto L_1dbfec;
    cpu->regs[25] = cpu->regs[26];
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_1dc0e8;
L_1dbfec:
    PB_LDRW(cpu->regs[0], (SP + 12));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1dc0d4;
L_1dbff4:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if ((cpu->regs[24])==0) goto L_1dc00c;
    PB_LDRW(cpu->regs[1], (cpu->regs[24] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1dc00c;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[1]);
L_1dc00c:
    PB_STR((cpu->regs[25] + 0), cpu->regs[24]);
    cpu->regs[26] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1dc018ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdce4cULL);
L_1dc018:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1dc0a4;
L_1dc020:
    cpu->regs[28] = cpu->regs[24];
    cpu->regs[21] = cpu->regs[19];
    if ((cpu->regs[28])!=0) goto L_1dbfb4;
L_1dc02c:
    PB_LDR(cpu->regs[0], (SP + 16));
    if ((cpu->regs[0])!=0) goto L_1dc04c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_STR((SP + 16), cpu->regs[1]);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1dc104;
L_1dc04c:
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1dc058ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x122464ULL);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
L_1dc064:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x1dc06cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 96));
    PB_STR((cpu->regs[22] + 96), cpu->regs[23]);
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1dc0f4;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    SP = SP + 128ULL;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL); return; };
L_1dc0a4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1dc020;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dc0b8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1dc020;
L_1dc0bc:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    cpu->regs[30] = PB_BASE + 0x1dc0ccULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11d180ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_1dbfd8;
L_1dc0d4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 120));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 256ULL;
    cpu->regs[30] = PB_BASE + 0x1dc0e4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dbff4;
L_1dc0e8:
    cpu->regs[26] = cpu->regs[25];
    cpu->regs[25] = cpu->regs[28] + 16ULL;
    goto L_1dc018;
L_1dc0f4:
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_STR((SP + 112), cpu->regs[27]); PB_STR((SP + 112) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1dc104ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1dc104:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_1dc04c;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1dc118ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x7c1c0ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x1c8fd0ULL); return; };
}
