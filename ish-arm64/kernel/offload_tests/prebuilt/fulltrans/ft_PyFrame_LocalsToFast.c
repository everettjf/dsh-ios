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

void ft_PyFrame_LocalsToFast(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((cpu->regs[0])==0) goto L_27a16c;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 46));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27a170;
L_27a160:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_27a16c:
    return;
L_27a170:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 24));
    PB_STRW((SP + 44), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x27a180ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x8836cULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_27a160;
    PB_LDRW(cpu->regs[1], (SP + 44));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x27a194ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d2f10ULL);
    PB_STRB((cpu->regs[19] + 46), 0ULL);
    goto L_27a160;
    /* nop */
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x279dccULL); return; };
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 168));
    if ((cpu->regs[4])==0) goto L_27a1b8;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 32));
    if ((cpu->regs[5])!=0) goto L_27a1cc;
L_27a1b8:
    cpu->regs[2] = cpu->regs[4] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + 15));
    FLAG_CMP(((uint32_t)(((uint32_t)(cpu->regs[2] & ~(cpu->regs[3]))))), 0);
    if (FLAG_NE) goto L_27a1e8;
L_27a1c8:
    goto L_27a1ec;
L_27a1cc:
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_LDRB(cpu->regs[6], (cpu->regs[5] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[6] & ~(cpu->regs[3])));
    PB_STRB((cpu->regs[5] + cpu->regs[2]), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 32));
    PB_LDRB(cpu->regs[2], (cpu->regs[3] + cpu->regs[2]));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_27a1c8;
L_27a1e8:
    return;
L_27a1ec:
    cpu->regs[2] = cpu->regs[0] + 192ULL;
    cpu->regs[3] = (((uint64_t)(((int64_t)(cpu->regs[1] << 32)) >> 32) & 0xffffffffULL) << 1);
    cpu->regs[5] = cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 1);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[4] = cpu->regs[5];
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + cpu->regs[3]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(254ULL)));
    if (FLAG_EQ) goto L_27a23c;
L_27a20c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(253ULL)));
    if (FLAG_EQ) goto L_27a25c;
L_27a214:
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[1] = cpu->regs[0] + 1808ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + ((uint64_t)(uint32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_27a238;
    cpu->regs[0] = cpu->regs[0] + 2320ULL;
    PB_STRB((cpu->regs[4] + 0), cpu->regs[1]);
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + ((uint64_t)(uint32_t)(cpu->regs[1]))));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27a250;
L_27a238:
    return;
L_27a23c:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 40));
    cpu->regs[4] = cpu->regs[2] + cpu->regs[3];
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + cpu->regs[3]));
    goto L_27a20c;
L_27a250:
    cpu->regs[0] = 17ULL;
    PB_STRH((cpu->regs[5] + 2), cpu->regs[0]);
    return;
L_27a25c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    cpu->regs[4] = cpu->regs[0] + cpu->regs[1];
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + cpu->regs[1]));
    goto L_27a214;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 48));
    if ((cpu->regs[4])!=0) goto L_27a28c;
    PB_LDRB(cpu->regs[3], (cpu->regs[3] + 20));
    FLAG_CMP(((uint32_t)(((uint32_t)(cpu->regs[3] & ~(cpu->regs[2]))))), 0);
    if (FLAG_NE) goto L_27a2a4;
L_27a288:
    goto L_27a2a8;
L_27a28c:
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_LDRB(cpu->regs[5], (cpu->regs[4] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[5] & ~(cpu->regs[2])));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] & 255ULL));
    PB_STRB((cpu->regs[4] + cpu->regs[3]), cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_27a288;
L_27a2a4:
    return;
L_27a2a8:
    cpu->regs[3] = cpu->regs[0] + 192ULL;
    cpu->regs[2] = (((uint64_t)(((int64_t)(cpu->regs[1] << 32)) >> 32) & 0xffffffffULL) << 1);
    cpu->regs[6] = cpu->regs[3] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 1);
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    PB_LDRB(cpu->regs[4], (cpu->regs[3] + cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(254ULL)));
    if (FLAG_NE) goto L_27a2f0;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 40));
    PB_LDRB(cpu->regs[4], (cpu->regs[0] + cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(253ULL)));
    if (FLAG_EQ) goto L_27a300;
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[0] = cpu->regs[0] + 2320ULL;
    PB_STRB((cpu->regs[3] + cpu->regs[2]), cpu->regs[4]);
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + ((uint64_t)(uint32_t)(cpu->regs[4]))));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27a2f4;
L_27a2f0:
    return;
L_27a2f4:
    cpu->regs[0] = 17ULL;
    PB_STRH((cpu->regs[6] + 2), cpu->regs[0]);
    return;
L_27a300:
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 56));
    cpu->regs[4] = 4294967293ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[5] + cpu->regs[1]));
    PB_STRB((cpu->regs[0] + cpu->regs[2]), cpu->regs[1]);
    PB_STRB((cpu->regs[3] + cpu->regs[2]), cpu->regs[4]);
    return;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_27a350;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x27a34cULL; PB_CALL(4, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_27a384;
L_27a350:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_27a378;
L_27a358:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_27a384;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_27a378:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x27a380ULL; PB_CALL(5, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_27a358;
L_27a384:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
}
