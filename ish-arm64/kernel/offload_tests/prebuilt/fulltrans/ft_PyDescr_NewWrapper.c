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

void ft_PyDescr_NewWrapper(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2480));
    cpu->regs[30] = PB_BASE + 0x18ce68ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xde700ULL);
    if ((cpu->regs[0])==0) goto L_18ce70;
    PB_STR((cpu->regs[0] + 40), cpu->regs[19]); PB_STR((cpu->regs[0] + 40) + 8, cpu->regs[20]);
L_18ce70:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[5] = 64ULL;
    cpu->regs[4] = cpu->regs[4] + (cpu->regs[4] << 1);
    cpu->regs[4] = cpu->regs[4] | 8ULL;
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[4] = cpu->regs[4] | 7ULL;
    cpu->regs[4] = (((uint64_t)(cpu->regs[4])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[4])));
    cpu->regs[2] = ((uint32_t)(cpu->regs[5] - cpu->regs[4]));
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xe03e0ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 16));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 32ULL));
    if (((cpu->regs[2] >> 4) & 1)) goto L_18cf3c;
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_18cf5c;
    cpu->regs[30] = PB_BASE + 0x18ced8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18d030ULL);
    cpu->regs[19] = cpu->regs[0];
L_18cedc:
    if ((cpu->regs[19])==0) goto L_18cfc0;
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 24));
    cpu->regs[22] = 1ULL;
L_18cee8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18cef0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdb420ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[2] = cpu->regs[19];
    if (((cpu->regs[1] >> 6) & 1)) goto L_18cf4c;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x18cf04ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe09a4ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[20] = (FLAG_EQ) ? 1 : 0;
L_18cf0c:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_18cfc8;
L_18cf10:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_18cf24;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_18cff4;
L_18cf24:
    cpu->regs[0] = ((uint32_t)((uint64_t)(-(int64_t)cpu->regs[20])));
L_18cf28:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_18cf3c:
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_18d000;
    cpu->regs[30] = PB_BASE + 0x18cf44ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x18d124ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_18cedc;
L_18cf4c:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x18cf54ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xddf30ULL);
    cpu->regs[20] = ((uint32_t)(cpu->regs[0] >> 31));
    goto L_18cf0c;
L_18cf5c:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[22] = ((uint32_t)(cpu->regs[2] & 16ULL));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18cf74ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xddd20ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18cfc0;
    cpu->regs[30] = PB_BASE + 0x18cf80ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18d670ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18cf98;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18cfe8;
L_18cf98:
    if ((cpu->regs[19])==0) goto L_18cfc0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0x18cfa4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_18cee8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18cfc0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18d020;
L_18cfc0:
    cpu->regs[0] = 4294967295ULL;
    goto L_18cf28;
L_18cfc8:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18cf10;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18cf10;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x18cfe4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18cf10;
L_18cfe8:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x18cff0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18cf98;
L_18cff4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18cffcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18cf24;
L_18d000:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 1680ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18d018ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_18cf28;
L_18d020:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18d028ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_18cf28;
}
