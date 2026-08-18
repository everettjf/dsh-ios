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

void ft_PySequence_InPlaceRepeat(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    if ((cpu->regs[0])!=0) goto L_9afd8;
    cpu->regs[30] = PB_BASE + 0x9afd4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x96bd4ULL);
    goto L_9b040;
L_9afd8:
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 104));
    if ((cpu->regs[3])==0) goto L_9b024;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 72));
    if ((cpu->regs[4])==0) goto L_9b008;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[16] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_9b008:
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    if ((cpu->regs[3])==0) goto L_9b024;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_9b024:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9b02cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9b0a8;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x9b038ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9b048;
L_9b040:
    cpu->regs[19] = 0ULL;
    goto L_9b0cc;
L_9b048:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[3] = 16ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 168ULL;
    cpu->regs[30] = PB_BASE + 0x9b05cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1ac780ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9b07c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9b07c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9b07cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9b07c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_9b0cc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9b0a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9b0a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9b0a8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9b0a8:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 3432ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9b0c8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_9b040;
L_9b0cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = 576460752303423487ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[24] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[4];
    PB_STR((SP + 80), cpu->regs[27]);
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_GT) goto L_9b128;
    cpu->regs[0] = cpu->regs[3] << 4;
    cpu->regs[30] = PB_BASE + 0x9b124ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdbd90ULL);
    goto L_9b12c;
L_9b128:
    cpu->regs[0] = 0ULL;
L_9b12c:
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_9b174;
    cpu->regs[0] = 11068046444225730969ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x199ULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[23], cpu->regs[0]);
    if (FLAG_GT) goto L_9b154;
    cpu->regs[0] = 80ULL;
    cpu->regs[0] = cpu->regs[23] * cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x9b150ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdbd90ULL);
    goto L_9b158;
L_9b154:
    cpu->regs[0] = 0ULL;
L_9b158:
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    cpu->regs[21] = 0ULL;
    if ((cpu->regs[0])==0) goto L_9b16c;
    cpu->regs[26] = 80ULL;
    goto L_9b1e4;
L_9b16c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x9b174ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_9b174:
    cpu->regs[30] = PB_BASE + 0x9b178ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x22d780ULL);
L_9b178:
    cpu->regs[0] = 4294967295ULL;
    goto L_9b264;
L_9b180:
    cpu->regs[30] = PB_BASE + 0x9b184ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x14d028ULL);
    cpu->regs[27] = cpu->regs[21] * cpu->regs[26];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[25];
    if ((cpu->regs[0])==0) goto L_9b230;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x9b1a0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11e5ccULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_9b1f8;
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_9b214;
L_9b1b4:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[21] << 4;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + cpu->regs[27]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[2] = cpu->regs[2] + cpu->regs[27];
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 16));
    PB_STR((cpu->regs[0] + 8), cpu->regs[1]);
L_9b1e4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_NE) goto L_9b180;
    goto L_9b228;
L_9b1f8:
    if (((cpu->regs[1] >> 31) & 1)) goto L_9b230;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9b230;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9b210ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9b230;
L_9b214:
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9b1b4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9b224ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9b1b4;
L_9b228:
    cpu->regs[0] = 0ULL;
    goto L_9b264;
L_9b230:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 80ULL;
    cpu->regs[30] = PB_BASE + 0x9b240ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_9b240:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    if (FLAG_EQ) goto L_9b25c;
    cpu->regs[0] = cpu->regs[19] * cpu->regs[20] + cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x9b258ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_9b240;
L_9b25c:
    cpu->regs[30] = PB_BASE + 0x9b260ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_9b178;
L_9b264:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
}
