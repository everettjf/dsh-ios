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

void ft__PyInterpreterState_IDDecref(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_cd39c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 96));
    cpu->regs[30] = PB_BASE + 0xcd3c0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xcd3d4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x17faa0ULL);
    if ((cpu->regs[20])!=0) goto L_cd414;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_cd414;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 72));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xcd3f0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x26dea0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xcd3fcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x82a78ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x26dea0ULL); return; };
L_cd414:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0xcd43cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x97004ULL);
    if ((cpu->regs[0])==0) goto L_cd448;
    cpu->regs[30] = PB_BASE + 0xcd444ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xcd39cULL);
    goto L_cd44c;
L_cd448:
    cpu->regs[30] = PB_BASE + 0xcd44cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_cd44c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_cd468:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xcd48cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x97004ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_cd4a0;
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_cd4c4;
    cpu->regs[30] = PB_BASE + 0xcd49cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_cd4ac;
L_cd4a0:
    cpu->regs[30] = PB_BASE + 0xcd4a4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x959f0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_cd4c4;
L_cd4ac:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xcd4b4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe3a2cULL);
    if ((cpu->regs[0])!=0) goto L_cd4cc;
    if ((cpu->regs[19])==0) goto L_cd4c4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcd4c4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xcd39cULL);
L_cd4c4:
    cpu->regs[0] = 0ULL;
    goto L_cd4d0;
L_cd4cc:
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]);
L_cd4d0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x523000ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[3] = cpu->regs[3] + 784ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[3] = cpu->regs[3] + 1584ULL;
    cpu->regs[6] = SP + 12ULL;
    cpu->regs[5] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = PB_BASE + 0xab000ULL;
    cpu->regs[2] = PB_BASE + 0x2a7000ULL;
    cpu->regs[4] = cpu->regs[4] + 1272ULL;
    cpu->regs[2] = cpu->regs[2] + 2840ULL;
    PB_STRW((SP + 12), 0ULL);
    cpu->regs[30] = PB_BASE + 0xcd53cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x13eb20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_cd554;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[2], (SP + 12));
    cpu->regs[30] = PB_BASE + 0xcd550ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xcd468ULL);
    goto L_cd558;
L_cd554:
    cpu->regs[0] = 0ULL;
L_cd558:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_cd578;
    cpu->regs[30] = PB_BASE + 0xcd578ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_cd578:
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
}
