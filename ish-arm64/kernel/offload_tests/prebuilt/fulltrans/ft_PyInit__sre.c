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

void ft_PyInit__sre(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = PB_BASE + 0x520000ULL;
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[0] = cpu->regs[0] + 3096ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18f580ULL); return; };
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 0ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x520000ULL;
    cpu->regs[20] = cpu->regs[20] + 16ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    cpu->regs[1] = cpu->regs[20] + 3200ULL;
    cpu->regs[30] = PB_BASE + 0x1f688cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f69c0;
    cpu->regs[1] = cpu->regs[20] + 3232ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f68a4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[21] + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f69c0;
    cpu->regs[1] = cpu->regs[20] + 3264ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f68bcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[21] + 16), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f69c0;
    cpu->regs[1] = cpu->regs[20] + 3296ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f68d4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1ab1a0ULL);
    PB_STR((cpu->regs[21] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f69c0;
    cpu->regs[2] = 35935ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3552ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 16)) | ((0x134ULL & 0xffff) << 16);
    cpu->regs[30] = PB_BASE + 0x1f68f4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f69c0;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3560ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1f690cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c1904ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f69c0;
    cpu->regs[0] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1f6918ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe1564ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f69c0;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3576ULL;
    cpu->regs[30] = PB_BASE + 0x1f6934ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1a3300ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f694c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f69d4;
L_1f694c:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1f69c0;
    cpu->regs[0] = 1073741823ULL;
    cpu->regs[30] = PB_BASE + 0x1f6958ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1564ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f69c0;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3592ULL;
    cpu->regs[30] = PB_BASE + 0x1f6974ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1a3300ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f698c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f69c8;
L_1f698c:
    if (((cpu->regs[21] >> 31) & 1)) goto L_1f69c0;
    cpu->regs[2] = PB_BASE + 0x2b8000ULL;
    cpu->regs[2] = cpu->regs[2] + 2096ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1152ULL;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = cpu->regs[1] + 3216ULL;
    cpu->regs[30] = PB_BASE + 0x1f69acULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1f6a80ULL);
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
L_1f69b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1f69c0:
    cpu->regs[0] = 4294967295ULL;
    goto L_1f69b0;
L_1f69c8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f69d0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f698c;
L_1f69d4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f69dcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f694c;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1f69f0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x187b80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1f6a60;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 5048));
    cpu->regs[4] = 0ULL;
    PB_LDRW(cpu->regs[6], (cpu->regs[5] + 4480));
    cpu->regs[7] = 48ULL;
    cpu->regs[8] = 16383ULL;
L_1f6a08:
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_LS) goto L_1f6a58;
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 4472));
    cpu->regs[1] = (uint64_t)(uint32_t)cpu->regs[4] * (uint64_t)(uint32_t)cpu->regs[7];
    cpu->regs[3] = cpu->regs[2] + cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + cpu->regs[1]));
    if ((cpu->regs[1])!=0) goto L_1f6a2c;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    goto L_1f6a08;
L_1f6a2c:
    cpu->regs[1] = cpu->regs[1] + cpu->regs[8];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[1] & 18446744073709535232ULL;
    goto L_1f6a48;
L_1f6a3c:
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[1] = cpu->regs[1] + (4ULL << 12);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
L_1f6a48:
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_LO) goto L_1f6a3c;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    goto L_1f6a08;
L_1f6a58:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1f6a60:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1208ULL;
    cpu->regs[1] = cpu->regs[1] + 3608ULL;
    cpu->regs[30] = PB_BASE + 0x1f6a78ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x91ebcULL);
    /* nop */
    /* nop */
}
