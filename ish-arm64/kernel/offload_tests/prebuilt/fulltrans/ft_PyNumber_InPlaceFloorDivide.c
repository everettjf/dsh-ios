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

void ft_PyNumber_InPlaceFloorDivide(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = PB_BASE + 0x29a000ULL;
    cpu->regs[3] = 232ULL;
    cpu->regs[4] = cpu->regs[4] + 2664ULL;
    cpu->regs[2] = 248ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x12bc80ULL); return; };
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[2];
    if ((cpu->regs[0])!=0) goto L_245658;
L_245640:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_245668;
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_245658:
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x245660ULL; PB_CALL(2, cpu, tlb, cpu->regs[20]);
    PB_LDR(cpu->regs[1], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_245640;
L_245668:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[0] + 32ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
L_2456a0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[19] = cpu->regs[19] - 1ULL; FLAG_CMP(cpu->regs[19], 0);
    if (FLAG_LT) goto L_2456c0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[19] << 3)));
    if ((cpu->regs[0])==0) goto L_2456a0;
    cpu->regs[30] = PB_BASE + 0x2456b8ULL; PB_CALL(3, cpu, tlb, cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2456a0;
    goto L_2456c4;
L_2456c0:
    cpu->regs[0] = 0ULL;
L_2456c4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_2456f8;
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_2456f8:
    cpu->regs[0] = 0ULL;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x245724ULL; PB_CALL(4, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x245738ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x187fc0ULL);
    if ((cpu->regs[0])==0) goto L_2458a4;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_245874;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 10));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_2458c0;
L_245758:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 10));
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 24));
    PB_STRW((cpu->regs[1] + 12), 0ULL);
    PB_LDRB(cpu->regs[3], (cpu->regs[1] + 9));
    cpu->regs[22] = cpu->regs[22] - 1ULL;
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[3] & 63);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_245810;
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[22] << 4);
    cpu->regs[19] = cpu->regs[1] + cpu->regs[0];
L_245784:
    cpu->regs[0] = cpu->regs[19] - 16ULL;
    if (((cpu->regs[22] >> 63) & 1)) goto L_245794;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_2458ac;
L_245794:
    PB_LDR(cpu->regs[24], (cpu->regs[19] + 0));
    cpu->regs[1] = 2ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2457b0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xde604ULL);
    cpu->regs[9] = cpu->regs[0];
    PB_LDR(cpu->regs[11], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 24));
    PB_STR((cpu->regs[19] + 0), 0ULL); PB_STR((cpu->regs[19] + 0) + 8, 0ULL);
L_2457c0:
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[10], (cpu->regs[20] + 32));
    cpu->regs[0] = cpu->regs[10];
    cpu->regs[30] = PB_BASE + 0x2457d0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x198148ULL);
    cpu->regs[2] = 18446744073709551614ULL;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[10];
    cpu->regs[30] = PB_BASE + 0x2457e0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18cdacULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_STR((cpu->regs[21] + 24), cpu->regs[24]); PB_STR((cpu->regs[21] + 24) + 8, cpu->regs[11]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[22]);
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 16), cpu->regs[1]); PB_STR((cpu->regs[20] + 16) + 8, cpu->regs[9]);
L_2457f8:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_245810:
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    cpu->regs[2] = 24ULL;
    cpu->regs[19] = cpu->regs[1] + cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[0] = cpu->regs[19] + 16ULL;
L_245824:
    cpu->regs[25] = cpu->regs[22] * cpu->regs[2];
    if (((cpu->regs[22] >> 63) & 1)) goto L_245834;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + cpu->regs[25]));
    if ((cpu->regs[1])==0) goto L_2458b8;
L_245834:
    cpu->regs[26] = cpu->regs[19] + cpu->regs[25];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = 2ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[26] + 8));
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x245854ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xde604ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + cpu->regs[25]));
    cpu->regs[2] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[11], (cpu->regs[26] + 16));
    PB_STR((cpu->regs[19] + cpu->regs[25]), cpu->regs[2]);
    PB_STR((cpu->regs[26] + 8), 0ULL); PB_STR((cpu->regs[26] + 8) + 8, 0ULL);
    cpu->regs[9] = cpu->regs[0];
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_2457c0;
L_245874:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_24588c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_24588c;
    cpu->regs[30] = PB_BASE + 0x24588cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_24588c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    cpu->regs[1] = PB_BASE + 0x29a000ULL;
    cpu->regs[1] = cpu->regs[1] + 2672ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2458a4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_2458a4:
    cpu->regs[21] = 0ULL;
    goto L_2457f8;
L_2458ac:
    cpu->regs[22] = cpu->regs[22] - 1ULL;
    cpu->regs[19] = cpu->regs[0];
    goto L_245784;
L_2458b8:
    cpu->regs[22] = cpu->regs[22] - 1ULL;
    goto L_245824;
L_2458c0:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x2458d4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe03e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2458e0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    goto L_245758;
L_2458e0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2458a4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2458a4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x245900ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2457f8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 32));
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x245920ULL); return; };
    /* nop */
    /* nop */
    /* nop */
}
