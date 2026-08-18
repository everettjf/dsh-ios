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

void ft__PyObject_ClearManagedDict(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 4) & 1)) goto L_1ef6f4;
    PB_LDR(cpu->regs[19], (cpu->regs[20] + -24));
    if (((cpu->regs[19] >> 0) & 1)) goto L_1ef680;
    if ((cpu->regs[19])==0) goto L_1ef6f4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[20] + -24), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ef6f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ef6f4;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_1ef680:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[19] + 1ULL;
    cpu->regs[21] = 0ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 880));
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
L_1ef698:
    FLAG_CMP(cpu->regs[3], cpu->regs[21]);
    if (FLAG_LE) goto L_1ef6d0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[21] << 3)));
    if ((cpu->regs[0])==0) goto L_1ef6c8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[22] + (cpu->regs[21] << 3)), 0ULL);
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ef6c8;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1ef6c8;
    cpu->regs[30] = PB_BASE + 0x1ef6c4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[23] + 24));
L_1ef6c8:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_1ef698;
L_1ef6d0:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STR((cpu->regs[20] + -24), 0ULL);
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19] - cpu->regs[0];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xdc0e4ULL); return; };
L_1ef6f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 8));
    PB_STR((cpu->regs[0] + 8), 0ULL);
L_1ef714:
    if ((cpu->regs[19])!=0) goto L_1ef724;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1ef724:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x1ef730ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ef73cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xd7784ULL);
    goto L_1ef714;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[2] & 9223372036854775807ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_1ef788;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_EQ) goto L_1ef7b8;
    cpu->regs[1] = cpu->regs[2];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_NE) goto L_1ef7d4;
L_1ef770:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    goto L_1ef8e0;
L_1ef788:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 16));
    cpu->regs[1] = cpu->regs[2] + cpu->regs[0];
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_1ef7cc;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_1ef814;
    cpu->regs[2] = PB_BASE + 0x286000ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] + 2280ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ef7b4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x27e344ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ef7f4;
L_1ef7b8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 0) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    goto L_1ef8e0;
L_1ef7cc:
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_1ef870;
L_1ef7d4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_1ef804;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 1776ULL;
    cpu->regs[30] = PB_BASE + 0x1ef7f4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1ef7f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1ef804:
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 1720ULL;
    cpu->regs[30] = PB_BASE + 0x1ef810ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1ef7f4;
L_1ef814:
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_NE) goto L_1ef7b8;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 24));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x286000ULL;
    cpu->regs[21] = cpu->regs[21] + 2280ULL;
    cpu->regs[1] = cpu->regs[21];
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1ef838ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11d180ULL);
    PB_LDR(cpu->regs[3], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ef894;
    cpu->regs[2] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] + 3504ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1ef854ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x27e344ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ef8d0;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    goto L_1ef8e0;
L_1ef870:
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_1ef770;
    cpu->regs[2] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] + 3504ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ef88cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x27e344ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ef770;
    goto L_1ef7f4;
L_1ef894:
    cpu->regs[2] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[2] + 3504ULL;
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1ef8acULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x27e344ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ef8d0;
    PB_LDR(cpu->regs[3], (SP + 56));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1ef8c4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x27e344ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ef7b8;
    goto L_1ef7f4;
L_1ef8d0:
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_1ef7f4;
    /* nop */
    /* nop */
L_1ef8e0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 304));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ef904ULL; PB_CALL(14, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1ef9c8;
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[20])!=0) goto L_1ef968;
    PB_STR((cpu->regs[0] + 16), 0ULL);
    PB_STR((cpu->regs[0] + 40), 0ULL);
L_1ef918:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ef920ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe7e88ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1ef9ac;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[0] = 2ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1ef93cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1204ULL);
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1ef9ac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 3240ULL;
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
L_1ef954:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1ef968:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ef970ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x14e5a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ef9ac;
    cpu->regs[30] = PB_BASE + 0x1ef97cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe5240ULL);
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1ef9d0;
L_1ef988:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ef918;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ef918;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ef9a8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ef918;
L_1ef9ac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ef9c8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ef9c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ef9c8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ef9c8:
    cpu->regs[19] = 0ULL;
    goto L_1ef954;
L_1ef9d0:
    cpu->regs[30] = PB_BASE + 0x1ef9d4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1ef988;
    cpu->regs[30] = PB_BASE + 0x1ef9dcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_STR((cpu->regs[19] + 40), cpu->regs[20]);
    cpu->regs[0] = 9223372036854775807ULL;
    PB_STR((cpu->regs[19] + 16), cpu->regs[0]);
    goto L_1ef918;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->regs[0] + 192ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1efa00ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1444e0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 184));
    cpu->regs[30] = PB_BASE + 0x1efa0cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 152));
    if ((cpu->regs[1])!=0) goto L_1efa50;
L_1efa14:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 144));
    PB_STR((cpu->regs[19] + 184), 0ULL);
    if ((cpu->regs[0])!=0) goto L_1efa40;
L_1efa20:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if ((cpu->regs[0])!=0) goto L_1efa38;
L_1efa28:
    PB_STR((cpu->regs[19] + 168), 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1efa38:
    cpu->regs[30] = PB_BASE + 0x1efa3cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1a29b0ULL);
    goto L_1efa28;
L_1efa40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1efa48ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x13f6ecULL);
    PB_STR((cpu->regs[19] + 144), 0ULL);
    goto L_1efa20;
L_1efa50:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if ((cpu->regs[0])==0) goto L_1efa70;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[1] + 0), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_1efa70;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_1efae0;
L_1efa70:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    if ((cpu->regs[0])==0) goto L_1efa90;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[1] + 16), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_1efa90;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_1efaec;
L_1efa90:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    if ((cpu->regs[0])==0) goto L_1efab0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[1] + 24), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_1efab0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_1efaf8;
L_1efab0:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    if ((cpu->regs[0])==0) goto L_1efad0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[1] + 8), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_1efad0;
    cpu->regs[1] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1efb04;
L_1efad0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    cpu->regs[30] = PB_BASE + 0x1efad8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((cpu->regs[19] + 152), 0ULL);
    goto L_1efa14;
L_1efae0:
    cpu->regs[30] = PB_BASE + 0x1efae4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 152));
    goto L_1efa70;
L_1efaec:
    cpu->regs[30] = PB_BASE + 0x1efaf0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 152));
    goto L_1efa90;
L_1efaf8:
    cpu->regs[30] = PB_BASE + 0x1efafcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 152));
    goto L_1efab0;
L_1efb04:
    cpu->regs[30] = PB_BASE + 0x1efb08ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1efad0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 888));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_1efbbc;
L_1efb34:
    if ((cpu->regs[2])!=0) goto L_1efc10;
L_1efb38:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_1efbf0;
L_1efb44:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x1efb50ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1efbd0;
    cpu->regs[30] = PB_BASE + 0x1efb5cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1efb74;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1efbe4;
L_1efb74:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1efbd0;
L_1efb7c:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 304));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 32));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1efb90ULL; PB_CALL(34, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1efbd8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[0] + 16), cpu->regs[22]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1efba8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_1efba8:
    PB_STR((cpu->regs[0] + 24), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1efbb0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1efbbc:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1efb38;
    goto L_1efb34;
L_1efbd0:
    cpu->regs[30] = PB_BASE + 0x1efbd4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1efc2c;
L_1efbd8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    goto L_1efbb0;
L_1efbe4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1efbecULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1efb74;
L_1efbf0:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1832ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1efc04ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1efb44;
    cpu->regs[0] = 0ULL;
    goto L_1efbb0;
L_1efc10:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + 1832ULL;
    cpu->regs[30] = PB_BASE + 0x1efc20ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1efb38;
    cpu->regs[0] = 0ULL;
    goto L_1efbb0;
L_1efc2c:
    cpu->regs[22] = 18446744073709551615ULL;
    goto L_1efb7c;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1efc54ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x1efc5cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1efc64ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[30] = PB_BASE + 0x1efc6cULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    SP += -128; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_HI) goto L_1f0360;
L_1efca8:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[28] = 0ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_GT) goto L_1f0358;
L_1efcc4:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[19] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[19] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1efcd4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f0344;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[20] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[20] + 1880ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1efcf0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f032c;
    cpu->regs[23] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1efd0cULL; PB_CALL(45, cpu, tlb, cpu->regs[1]);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24];
    PB_LDR(cpu->regs[21], (cpu->regs[23] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1efd20ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1a25d0ULL);
    PB_STR((SP + 120), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1eff60;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    if ((cpu->regs[0])!=0) goto L_1f0384;
L_1efd30:
    if ((cpu->regs[28])!=0) goto L_1f0250;
    cpu->regs[1] = cpu->regs[19] + 1472ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1efd40ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1eff60;
L_1efd48:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1f02bc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1efd5cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1947a0ULL);
    PB_STR((SP + 104), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f01a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1efd6cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1e2680ULL);
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[0] >> 63) & 1)) goto L_1f01a8;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 46ULL;
    cpu->regs[30] = PB_BASE + 0x1efd8cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1348ccULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_LT) goto L_1f01a8;
    if (FLAG_NE) goto L_1f0208;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1eff9c;
L_1efda4:
    cpu->regs[26] = cpu->regs[19];
L_1efda8:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2888ULL;
    cpu->regs[30] = PB_BASE + 0x1efdbcULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x146d68ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f0178;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1848ULL;
    PB_STR((SP + 96), cpu->regs[0]);
L_1efdd0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = 55448ULL;
    cpu->regs[2] = PB_BASE + 0x294000ULL;
    cpu->regs[4] = 95ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] + 1936ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[3] = 45ULL;
    cpu->regs[30] = PB_BASE + 0x1efdf8ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1d604cULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    if ((cpu->regs[0])==0) goto L_1f0190;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1effbc;
L_1efe08:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1efe1c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f00e8;
L_1efe1c:
    cpu->regs[0] = cpu->regs[21] + 32ULL;
    cpu->regs[1] = cpu->regs[20] + 1880ULL;
    PB_STR((SP + 112), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1efe30ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f00f8;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2760));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1176ULL;
    cpu->regs[5] = cpu->regs[6];
    cpu->regs[4] = cpu->regs[6];
    cpu->regs[0] = cpu->regs[0] + 1184ULL;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1efe64ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f00f8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1efe74ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1c85e0ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f00b8;
    cpu->regs[2] = cpu->regs[0] + 32ULL;
    cpu->regs[1] = cpu->regs[21] + 32ULL;
    PB_LDR(cpu->regs[0], (SP + 96));
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1efe90ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x1f19a4ULL);
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1efeb0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1efeb0;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1efeb0ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1efeb0:
    if ((cpu->regs[26])==0) goto L_1f0108;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1efec4ULL; PB_CALL(58, cpu, tlb, cpu->regs[1]);
    cpu->regs[23] = cpu->regs[23] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 104));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    PB_STR((cpu->regs[23] + 8), cpu->regs[0]);
    PB_STR((SP + 112), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1efedcULL; PB_CALL(59, cpu, tlb, cpu->regs[26]);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 112));
    PB_STR((cpu->regs[23] + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1efeecULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[27])==0) goto L_1f00f4;
    if ((cpu->regs[0])!=0) goto L_1f01e8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    if ((cpu->regs[0])==0) goto L_1f0224;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3928));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1eff0cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1effec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1effd4;
L_1eff18:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1eff34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1eff34;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1eff34ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1eff34:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1eff48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f0244;
L_1eff48:
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[2] = 1013ULL;
    cpu->regs[30] = PB_BASE + 0x1eff58ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1a2a20ULL);
    PB_STR((SP + 120), cpu->regs[0]);
L_1eff5c:
    if ((cpu->regs[28])!=0) goto L_1f0280;
L_1eff60:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1effa4;
L_1eff68:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1eff7c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f01cc;
L_1eff7c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_1eff8c:
    PB_LDR(cpu->regs[0], (SP + 120));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 128;
    return;
L_1eff9c:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1efda4;
L_1effa4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1eff68;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1effb8ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eff68;
L_1effbc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1efe08;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1effd0ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1efe08;
L_1effd4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1eff18;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1effe8ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eff18;
L_1effec:
    cpu->regs[0] = cpu->regs[21] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x1efff4ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x1f2ea0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f00b8;
    PB_LDR(cpu->regs[1], (SP + 96));
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1856ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1f009c;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1f0014ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x190cccULL);
    if ((cpu->regs[0])==0) goto L_1f02fc;
    PB_STR((cpu->regs[0] + 16), cpu->regs[26]);
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 824ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1f0030ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1a3300ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f02f4;
L_1f0034:
    cpu->regs[30] = PB_BASE + 0x1f0038ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1f4390ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1f004cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x1f46a4ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f00bc;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f0064;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f02e8;
L_1f0064:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f0080;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1f0080;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f0080ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1f0080:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f0094;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f02d8;
L_1f0094:
    PB_STR((SP + 120), cpu->regs[27]);
    goto L_1eff5c;
L_1f009c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[2] = cpu->regs[21] + 32ULL;
    cpu->regs[1] = cpu->regs[1] + 2184ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f00b8ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1f00b8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
L_1f00bc:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f00cc;
L_1f00c0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f0320;
L_1f00cc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1f00d4ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f00dcULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1f00e4ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_1eff5c;
L_1f00e8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1f00f0ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1efe1c;
L_1f00f4:
    if ((cpu->regs[0])==0) goto L_1f0158;
L_1f00f8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[27] = 0ULL;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1f00c0;
    goto L_1f00cc;
L_1f0108:
    cpu->regs[30] = PB_BASE + 0x1f010cULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1f00f8;
    PB_LDR(cpu->regs[1], (SP + 96));
    cpu->regs[2] = cpu->regs[21] + 32ULL;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1944ULL;
    cpu->regs[30] = PB_BASE + 0x1f0124ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1f00b8;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f0138ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xbdd90ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f00f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1f00f8;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1f0154ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f00f8;
L_1f0158:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[21] + 32ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 2008ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f0174ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1f00f8;
L_1f0178:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3720));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f0188ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1f028c;
L_1f018c:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
L_1f0190:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1f01a0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1f01c0;
L_1f01a0:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1f01a8ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xdce4cULL);
L_1f01a8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[27] = 0ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[21] = 0ULL;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1f00c0;
    goto L_1f00cc;
L_1f01c0:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1f01c8ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f01a0;
L_1f01cc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1f01d4ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1eff8c;
L_1f01e8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[21] + 32ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 2072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f0204ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xa6154ULL);
    goto L_1f00f8;
L_1f0208:
    cpu->regs[1] = cpu->regs[0] + 1ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f0218ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x134b80ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1efda8;
    goto L_1f01a8;
L_1f0224:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[21] + 32ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 2128ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f0240ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1f00f8;
L_1f0244:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f024cULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1eff48;
L_1f0250:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 2904ULL;
    cpu->regs[30] = PB_BASE + 0x1f0260ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x1dd228ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1eff60;
    cpu->regs[1] = cpu->regs[19] + 1472ULL;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1f0274ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1efd48;
    PB_STR((SP + 120), 0ULL);
L_1f0280:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1f0288ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x7b1c0ULL);
    goto L_1eff60;
L_1f028c:
    cpu->regs[30] = PB_BASE + 0x1f0290ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f02a4ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x146d68ULL);
    if ((cpu->regs[0])==0) goto L_1f018c;
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1856ULL;
    PB_STR((SP + 96), cpu->regs[0]);
    goto L_1efdd0;
L_1f02bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 1888ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f02d4ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1f01a8;
L_1f02d8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1f02e0ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_STR((SP + 120), cpu->regs[27]);
    goto L_1eff5c;
L_1f02e8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f02f0ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f0064;
L_1f02f4:
    cpu->regs[30] = PB_BASE + 0x1f02f8ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1f0034;
L_1f02fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[2] = cpu->regs[21] + 32ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f0318ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    goto L_1f00bc;
L_1f0320:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f0328ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1f00cc;
L_1f032c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1f0340;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1f0390;
L_1f0340:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1f0344:
    PB_STR((SP + 120), 0ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1eff8c;
L_1f0358:
    PB_LDR(cpu->regs[28], (cpu->regs[20] + 8));
    goto L_1efcc4;
L_1f0360:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1864ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1f0378ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1efca8;
    PB_STR((SP + 120), 0ULL);
    goto L_1eff8c;
L_1f0384:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_1eff60;
    goto L_1efd30;
L_1f0390:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1f0398ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_STR((SP + 120), 0ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1eff8c;
    SP = SP - 64ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3];
    if ((cpu->regs[3])!=0) goto L_1f0510;
    if (((cpu->regs[2] >> 63) & 1)) goto L_1f0554;
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[19] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_1f0518;
L_1f03f4:
    if ((cpu->regs[19])==0) goto L_1f0508;
L_1f03f8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1f0400ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f04f8;
L_1f040c:
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 1800ULL;
    cpu->regs[0] = cpu->regs[0] + 2288ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1f0424ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1f0500;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1f0440ULL; PB_CALL(106, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
L_1f044c:
    if ((cpu->regs[1])==0) goto L_1f04ec;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 70));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1f0478;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 56));
    cpu->regs[3] = cpu->regs[0] + 192ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 176),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[3] + (cpu->regs[0] << 1);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LO) goto L_1f0484;
L_1f0478:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1f048c;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] - 1ULL));
L_1f0484:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    goto L_1f044c;
L_1f048c:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    if ((cpu->regs[0])==0) goto L_1f04ec;
    cpu->regs[30] = PB_BASE + 0x1f0498ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x1f058cULL);
    if ((cpu->regs[0])==0) goto L_1f04dc;
L_1f049c:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1f04ac;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1f04ac:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1f04d8;
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1f04d8:
    cpu->regs[30] = PB_BASE + 0x1f04dcULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1f04dc:
    cpu->regs[30] = PB_BASE + 0x1f04e0ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_1f049c;
L_1f04ec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_1f04ac;
L_1f04f8:
    cpu->regs[30] = PB_BASE + 0x1f04fcULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1f040c;
L_1f0500:
    cpu->regs[0] = 0ULL;
    goto L_1f04ac;
L_1f0508:
    cpu->regs[19] = 0ULL;
    goto L_1f040c;
L_1f0510:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    cpu->regs[19] = cpu->regs[2] + cpu->regs[19];
L_1f0518:
    cpu->regs[3] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[4] + 2952ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f0548ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_1f03f4;
    cpu->regs[0] = 0ULL;
    goto L_1f04ac;
L_1f0554:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 2952ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1f0580ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_1f03f8;
    cpu->regs[0] = 0ULL;
    goto L_1f04ac;
}
