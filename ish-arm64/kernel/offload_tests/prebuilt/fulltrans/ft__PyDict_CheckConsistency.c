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

void ft__PyDict_CheckConsistency(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (((cpu->regs[2] >> 29) & 1)) goto L_92b18;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2344ULL;
    cpu->regs[4] = 520ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92b18ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92b18:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 32)); PB_LDR(cpu->regs[6], (cpu->regs[0] + 32) + 8);
    cpu->regs[9] = 1ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 16));
    cpu->regs[2] = 3ULL;
    cpu->regs[3] = cpu->regs[0];
    PB_LDRB(cpu->regs[5], (cpu->regs[4] + 8));
    cpu->regs[9] = cpu->regs[9] << (cpu->regs[5] & 63);
    cpu->regs[5] = cpu->regs[9] << 1;
    cpu->regs[5] = (cpu->regs[2] ? (uint64_t)((int64_t)cpu->regs[5] / (int64_t)cpu->regs[2]) : 0);
    if (((cpu->regs[7] >> 63) & 1)) goto L_92b48;
    FLAG_CMP(cpu->regs[7], cpu->regs[5]);
    if (FLAG_LE) goto L_92b74;
L_92b48:
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2416ULL;
    cpu->regs[4] = 527ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92b74ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92b74:
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 16));
    if (((cpu->regs[2] >> 63) & 1)) goto L_92b84;
    FLAG_CMP(cpu->regs[2], cpu->regs[5]);
    if (FLAG_LE) goto L_92bb0;
L_92b84:
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2464ULL;
    cpu->regs[4] = 528ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92bb0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92bb0:
    PB_LDR(cpu->regs[8], (cpu->regs[4] + 24));
    if (((cpu->regs[8] >> 63) & 1)) goto L_92bc0;
    FLAG_CMP(cpu->regs[8], cpu->regs[5]);
    if (FLAG_LE) goto L_92bec;
L_92bc0:
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2520ULL;
    cpu->regs[4] = 529ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92becULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92bec:
    cpu->regs[2] = cpu->regs[2] + cpu->regs[8];
    FLAG_CMP(cpu->regs[2], cpu->regs[5]);
    if (FLAG_LE) goto L_92c20;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2576ULL;
    cpu->regs[4] = 530ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92c20ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92c20:
    PB_LDRB(cpu->regs[10], (cpu->regs[4] + 10));
    FLAG_CMP(((uint32_t)(cpu->regs[10])), ((uint32_t)(2ULL)));
    if ((cpu->regs[6])!=0) goto L_92ca4;
    if (FLAG_NE) goto L_92c58;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[4] = 534ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92c58ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92c58:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_92d00;
    cpu->regs[0] = PB_BASE + 0x450000ULL;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    cpu->regs[0] = cpu->regs[0] + 216ULL;
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_EQ) goto L_92d00;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2664ULL;
    cpu->regs[4] = 535ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92ca4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92ca4:
    if (FLAG_EQ) goto L_92cd0;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2720ULL;
    cpu->regs[4] = 538ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92cd0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92cd0:
    FLAG_CMP(cpu->regs[7], 30ULL);
    if (FLAG_LE) goto L_92d00;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2760ULL;
    cpu->regs[4] = 539ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92d00ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92d00:
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_93018;
    cpu->regs[8] = 0ULL;
L_92d08:
    FLAG_CMP(cpu->regs[9], cpu->regs[8]);
    if (FLAG_LE) goto L_92d5c;
    cpu->regs[1] = cpu->regs[8];
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x92d1cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18cc20ULL);
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_GE) { FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)2LL)); } else { FLAG_CMP(0, 1); }
    if (FLAG_GE) goto L_92d54;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2784ULL;
    cpu->regs[4] = 545ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92d54ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92d54:
    cpu->regs[8] = cpu->regs[8] + 1ULL;
    goto L_92d08;
L_92d5c:
    PB_LDRB(cpu->regs[1], (cpu->regs[4] + 9));
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = cpu->regs[0] << (cpu->regs[1] & 63);
    cpu->regs[4] = cpu->regs[4] + cpu->regs[0];
    cpu->regs[0] = 0ULL;
    if ((((uint32_t)(cpu->regs[10])))!=0) goto L_92e48;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 2520));
L_92d7c:
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_EQ) goto L_92f48;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 40));
    if ((cpu->regs[1])==0) goto L_92e3c;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 32));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_92dc4;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2816ULL;
    cpu->regs[4] = 556ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92dc4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92dc4:
    PB_LDR(cpu->regs[9], (cpu->regs[4] + 48));
    if ((cpu->regs[9])!=0) goto L_92df8;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2840ULL;
    cpu->regs[4] = 557ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92df8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92df8:
    PB_LDR(cpu->regs[9], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[9], cpu->regs[8]);
    if (FLAG_NE) goto L_92e3c;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_92e3c;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2872ULL;
    cpu->regs[4] = 561ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92e3cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92e3c:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[4] = cpu->regs[4] + 24ULL;
    goto L_92d7c;
L_92e48:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
L_92e50:
    FLAG_CMP(cpu->regs[0], cpu->regs[5]);
    if (FLAG_EQ) goto L_92f48;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 32));
    if ((cpu->regs[1])==0) goto L_92f04;
    PB_LDR(cpu->regs[8], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[8], cpu->regs[2]);
    if (FLAG_EQ) goto L_92e98;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2896ULL;
    cpu->regs[4] = 573ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92e98ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92e98:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_92ed0;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2952ULL;
    cpu->regs[4] = 575ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92ed0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92ed0:
    if ((cpu->regs[6])!=0) goto L_92f08;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 40));
    if ((cpu->regs[1])!=0) goto L_92f3c;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2840ULL;
    cpu->regs[4] = 577ULL;
    cpu->regs[30] = PB_BASE + 0x92f04ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92f04:
    if ((cpu->regs[6])==0) goto L_92f3c;
L_92f08:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 40));
    if ((cpu->regs[1])==0) goto L_92f3c;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2968ULL;
    cpu->regs[4] = 582ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92f3cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92f3c:
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    goto L_92e50;
L_92f48:
    if ((cpu->regs[6])==0) goto L_93018;
    FLAG_CMP(cpu->regs[7], 30ULL);
    if (FLAG_GT) goto L_92f64;
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[2] = 0ULL;
    cpu->regs[4] = 1ULL;
    goto L_92f90;
L_92f64:
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 2760ULL;
    cpu->regs[4] = 588ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92f90ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92f90:
    cpu->regs[0] = cpu->regs[6] - cpu->regs[1];
    FLAG_CMP(cpu->regs[7], cpu->regs[0]);
    if (FLAG_LE) goto L_93018;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + -3));
    cpu->regs[5] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[2] >> (cpu->regs[0] & 63))));
    if (!((cpu->regs[5] >> 0) & 1)) goto L_92fd4;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 3000ULL;
    cpu->regs[4] = 593ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x92fd4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x924f8ULL);
L_92fd4:
    cpu->regs[5] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[4] << (cpu->regs[0] & 63)));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] | cpu->regs[0]));
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + (cpu->regs[5] << 3)));
    if ((cpu->regs[0])!=0) goto L_92f90;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = PB_BASE + 0x283000ULL;
    cpu->regs[5] = cpu->regs[5] + 1072ULL;
    cpu->regs[3] = cpu->regs[3] + 1472ULL;
    cpu->regs[2] = cpu->regs[2] + 3040ULL;
    cpu->regs[4] = 595ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x93018ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x924f8ULL);
L_93018:
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
