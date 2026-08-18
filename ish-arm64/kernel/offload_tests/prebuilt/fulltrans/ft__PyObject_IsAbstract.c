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

void ft__PyObject_IsAbstract(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 48ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    if ((cpu->regs[0])==0) goto L_1d487c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 29728ULL;
    cpu->regs[2] = SP;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1d4808ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x112290ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_1d4844;
L_1d4814:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1d4884;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_1d4844:
    PB_LDR(cpu->regs[20], (SP + 0));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4850ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d4814;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d4814;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1d4878ULL; PB_CALL(3, cpu, tlb, cpu->regs[1]);
    goto L_1d4814;
L_1d487c:
    cpu->regs[19] = 0ULL;
    goto L_1d4814;
L_1d4884:
    cpu->regs[30] = PB_BASE + 0x1d4888ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 336));
    if ((cpu->regs[0])==0) goto L_1d48a4;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1d48a0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1d48a0:
    return;
L_1d48a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3216));
    cpu->regs[29] = SP;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1d48fc;
    cpu->regs[30] = PB_BASE + 0x1d48ccULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 25592ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1d48e0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])==0) goto L_1d48fc;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1d48f4;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_1d48f4:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1d48fc:
    cpu->regs[30] = PB_BASE + 0x1d4900ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1d4924;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[2] = 25592ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1d4924ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
L_1d4924:
    cpu->regs[0] = 0ULL;
    goto L_1d48f4;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1d4948ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[20])==0) goto L_1d49b4;
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4958ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d4a14;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 25592ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1d497cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xddf30ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d49a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d498cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x18e42cULL);
    if ((((uint32_t)(cpu->regs[21])))==0) goto L_1d49d8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[0] = cpu->regs[0] | 1048576ULL;
    PB_STR((cpu->regs[19] + 168), cpu->regs[0]);
L_1d499c:
    cpu->regs[20] = 0ULL;
L_1d49a0:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1d49b4:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[2] = 25592ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1d49c8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x197f6cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d49e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d49d8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x18e42cULL);
L_1d49d8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[0] = cpu->regs[0] & 18446744073708503039ULL;
    PB_STR((cpu->regs[19] + 168), cpu->regs[0]);
    goto L_1d499c;
L_1d49e8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d49f8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d49a0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = 25592ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d4a14ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
L_1d4a14:
    cpu->regs[20] = 4294967295ULL;
    goto L_1d49a0;
    /* nop */
    { PB_CALL(17, cpu, tlb, PB_BASE + 0x2807c8ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 0ULL;
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 304));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1d4a40ULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1d4a88;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 888));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 32));
    if ((cpu->regs[2])==0) goto L_1d4a70;
    PB_STR((cpu->regs[0] + 16), 0ULL); PB_STR((cpu->regs[0] + 16) + 8, 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    PB_STR((cpu->regs[1] + 32), 0ULL); PB_STR((cpu->regs[1] + 32) + 8, cpu->regs[0]);
L_1d4a60:
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1d4a70:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1d4a88;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1d4a88;
    cpu->regs[30] = PB_BASE + 0x1d4a88ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d4a88:
    cpu->regs[1] = 0ULL;
    goto L_1d4a60;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x28f000ULL;
    cpu->regs[2] = cpu->regs[2] + 1000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d4ab0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d4b00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d4ae4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d4abcULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x18e42cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d4ac4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[3] = 30600ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    { PB_CALL(23, cpu, tlb, PB_BASE + 0xddf30ULL); return; };
L_1d4ae4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    /* nop */
L_1d4b00:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 8) & 1)) goto L_1d4b44;
    if ((cpu->regs[4])==0) goto L_1d4b68;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] + 88ULL;
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[0] + 96ULL;
    cpu->regs[30] = PB_BASE + 0x1d4b34ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
L_1d4b3c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1d4b44:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2736));
    cpu->regs[1] = PB_BASE + 0x291000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 4072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[30] = PB_BASE + 0x1d4b60ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d4b3c;
L_1d4b68:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 32ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[30] = PB_BASE + 0x1d4b84ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_1d4b3c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 9) & 1)) goto L_1d4bf8;
L_1d4ba4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d4bacULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdb420ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 27680ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1d4bc0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe27c8ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d4c28;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 272));
    if ((cpu->regs[4])!=0) goto L_1d4c10;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1d4bf0;
L_1d4be0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1d4bf0:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    goto L_1d4be0;
L_1d4bf8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 176));
    if ((cpu->regs[1])==0) goto L_1d4ba4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(29, cpu, tlb, PB_BASE + 0x1daee4ULL); return; };
L_1d4c10:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[16] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1d4c28:
    cpu->regs[30] = PB_BASE + 0x1d4c2cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1d4be0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d4c48;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1d4c48:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    goto L_1d4be0;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_1d4db8;
L_1d4c80:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[19], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d4d98;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d4c9cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x136260ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1d4d20;
    if (FLAG_NE) goto L_1d4d64;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4cb4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x136260ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1d4d6c;
    if (FLAG_NE) goto L_1d4d64;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d4cccULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d53a0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d4d64;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x1d4ce0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d556cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d4d54;
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d4cf8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d4d8c;
L_1d4cf8:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1d4d20;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 168));
    cpu->regs[1] = cpu->regs[1] & 96ULL; FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1d4d40;
L_1d4d20:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1d4d4c;
L_1d4d2c:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1d4d40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d4d48ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1db090ULL);
    goto L_1d4d20;
L_1d4d4c:
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1d4d2c;
L_1d4d54:
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d4d64;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d4ddc;
L_1d4d64:
    cpu->regs[19] = 0ULL;
    goto L_1d4d2c;
L_1d4d6c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 168ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d4d88ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1d4d2c;
L_1d4d8c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d4d94ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d4cf8;
L_1d4d98:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 136ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d4db4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1d4d2c;
L_1d4db8:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 120ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1d4dd0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d4c80;
    cpu->regs[19] = 0ULL;
    goto L_1d4d2c;
L_1d4ddc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d4de8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d4d2c;
    SP = SP - 160ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 56), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_1d536c;
L_1d4e28:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[20], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d5274;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d4e44ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1d53a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d4fb0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4e58ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x14d444ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1d5314;
    if (FLAG_NE) goto L_1d50cc;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 32) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_LO) goto L_1d50dc;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4e80ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x14d444ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1d5314;
    if (FLAG_NE) goto L_1d51cc;
L_1d4e8c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 33552ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 48)) | ((0x8000ULL & 0xffff) << 48);
    cpu->regs[1] = SP + 32ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1d4eb4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1d5314;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3664));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_1d50b4;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_1d51a4;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2400));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (FLAG_NE) goto L_1d52ec;
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1d534c;
L_1d4ef0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 344));
    cpu->regs[0] = 0ULL;
    cpu->regs[3] = cpu->regs[1] + 24ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
L_1d4f00:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_GE) goto L_1d4f1c;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + (cpu->regs[0] << 3)));
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_EQ) goto L_1d50bc;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_1d4f00;
L_1d4f1c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d4f28ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x14d444ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1d5314;
    if (FLAG_NE) goto L_1d50cc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])!=0) goto L_1d4fec;
L_1d4f3c:
    cpu->regs[24] = 0ULL;
L_1d4f40:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 304ULL;
    cpu->regs[30] = PB_BASE + 0x1d4f54ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1a36c0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5248;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_1d52d0;
L_1d4f6c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_LT) goto L_1d505c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x1d4f84ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1d556cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5248;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3184));
L_1d4f90:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d52a0;
L_1d4f98:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d52bc;
L_1d4fa4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d4facULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdce4cULL);
    if ((cpu->regs[24])!=0) goto L_1d52a8;
L_1d4fb0:
    cpu->regs[24] = 0ULL;
L_1d4fb4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1d5390;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    SP = SP + 160ULL;
    return;
L_1d4fec:
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1d4ff4ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1b6b10ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d51f4;
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[30] = PB_BASE + 0x1d5004ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5340;
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[24] = SP + 16ULL;
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[28] = SP + 24ULL;
    cpu->regs[27] = SP + 8ULL;
    PB_STR((SP + 16), 0ULL);
L_1d5024:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[3] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1d5038ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1c8b60ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d50f4;
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d5054;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1d5054:
    PB_STR(cpu->regs[22], cpu->regs[1]); cpu->regs[22] += 8;
    goto L_1d5024;
L_1d505c:
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[23], (cpu->regs[0] + (cpu->regs[22] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d5078;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_1d5078:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d5084ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x136260ULL);
    cpu->regs[25] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d509c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d5294;
L_1d509c:
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1d521c;
    if (FLAG_NE) goto L_1d52c8;
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_1d4f6c;
L_1d50b4:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1d5254;
L_1d50bc:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x1d50c8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1d556cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5314;
L_1d50cc:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3664));
    cpu->regs[21] = 0ULL;
    goto L_1d4f90;
L_1d50dc:
    if ((cpu->regs[0])==0) goto L_1d50ec;
    cpu->regs[30] = PB_BASE + 0x1d50e4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1d5760ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5314;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
L_1d50ec:
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]);
    goto L_1d4e8c;
L_1d50f4:
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2760));
    cpu->regs[24] = 0ULL;
L_1d5100:
    FLAG_CMP(cpu->regs[25], cpu->regs[24]);
    if (FLAG_LE) goto L_1d515c;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + (cpu->regs[24] << 3)));
    cpu->regs[30] = PB_BASE + 0x1d5110ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1a1decULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5268;
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_EQ) goto L_1d5154;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d5130;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_1d5130:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d513cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x136260ULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1d51dc;
L_1d5148:
    FLAG_CMP(((uint32_t)(cpu->regs[28])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1d5268;
    if (FLAG_NE) goto L_1d51fc;
L_1d5154:
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    goto L_1d5100;
L_1d515c:
    cpu->regs[24] = 0ULL;
L_1d5160:
    cpu->regs[22] = 0ULL;
L_1d5164:
    FLAG_CMP(cpu->regs[25], cpu->regs[22]);
    if (FLAG_LE) goto L_1d518c;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + (cpu->regs[22] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d5184;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d5360;
L_1d5184:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_1d5164;
L_1d518c:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1d5194ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_1d523c;
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_1d4f40;
L_1d51a4:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1d51bc;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1d51bc;
    cpu->regs[30] = PB_BASE + 0x1d51bcULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d51bc:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x1d51c8ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1d556cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5314;
L_1d51cc:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3184));
    cpu->regs[21] = 0ULL;
    goto L_1d4f90;
L_1d51dc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1d5148;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d51f0ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5148;
L_1d51f4:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_1d4f3c;
L_1d51fc:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x1d5208ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1d556cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5268;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3664));
    cpu->regs[23] = 1ULL;
    goto L_1d5160;
L_1d521c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x1d5228ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1d556cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d52c8;
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3664));
    goto L_1d4f90;
L_1d523c:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
L_1d5248:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1d4f98;
    goto L_1d4fa4;
L_1d5254:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1d50bc;
    cpu->regs[30] = PB_BASE + 0x1d5264ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d50bc;
L_1d5268:
    cpu->regs[24] = 0ULL;
    cpu->regs[23] = 4294967295ULL;
    goto L_1d5160;
L_1d5274:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3840ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d5290ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1d4fb4;
L_1d5294:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1d529cULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d509c;
L_1d52a0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d52a8ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdce4cULL);
L_1d52a8:
    PB_LDRW(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d4fb4;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[0]);
    goto L_1d4fb4;
L_1d52bc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d52c4ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d4fa4;
L_1d52c8:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_1d5248;
L_1d52d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 320ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d52e8ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1d5248;
L_1d52ec:
    if (((cpu->regs[2] >> 31) & 1)) goto L_1d52fc;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_1d5328;
L_1d52fc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3232));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d5314ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1d5314:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d5330;
    cpu->regs[24] = 0ULL;
    cpu->regs[21] = 0ULL;
    goto L_1d4f98;
L_1d5328:
    cpu->regs[30] = PB_BASE + 0x1d532cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d52fc;
L_1d5330:
    cpu->regs[0] = 0ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d533cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_1d4fb4;
L_1d5340:
    cpu->regs[30] = PB_BASE + 0x1d5344ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_1d5314;
L_1d534c:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1d4ef0;
    cpu->regs[30] = PB_BASE + 0x1d535cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d4ef0;
L_1d5360:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1d5368ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5164;
L_1d536c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 208ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1d5384ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d4e28;
    cpu->regs[24] = 0ULL;
    goto L_1d4fb4;
L_1d5390:
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1d539cULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
L_1d53a0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[1] = 34304ULL;
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    PB_LDR(cpu->regs[20], (cpu->regs[3] + 32));
    cpu->regs[30] = PB_BASE + 0x1d53ccULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xed3ccULL);
    if ((cpu->regs[0])==0) goto L_1d5428;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1d53f4;
L_1d53e4:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1d53f4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 360ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d540cULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5428;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5428;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d5428ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d5428:
    cpu->regs[19] = 0ULL;
    goto L_1d53e4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    return;
    /* nop */
    goto L_1d5444;
L_1d5444:
    SP = SP - 96ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d5474ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    if ((cpu->regs[0])==0) goto L_1d5534;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d5484ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xe1a08ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1d54bc;
L_1d548c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1d5548;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 96ULL;
    return;
L_1d54bc:
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[22] = SP + 8ULL;
    cpu->regs[21] = SP + 16ULL;
    PB_STR((SP + 16), 0ULL);
L_1d54d8:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d54ecULL; PB_CALL(82, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d553c;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1d54d8;
    FLAG_CMP(cpu->regs[1], cpu->regs[23]);
    if (FLAG_EQ) goto L_1d54d8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d5514ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xe548cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d54d8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d552c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d5554;
L_1d552c:
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80));
L_1d5534:
    cpu->regs[19] = 0ULL;
    goto L_1d548c;
L_1d553c:
    PB_LDR(cpu->regs[23], (SP + 80));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_1d548c;
L_1d5548:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x1d5554ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d5554:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d5560ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[23], (SP + 80));
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_1d548c;
L_1d556c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0));
    if ((cpu->regs[22])==0) goto L_1d5634;
L_1d5588:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d5594ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xe1700ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d564c;
    cpu->regs[0] = PB_BASE + 0x520000ULL;
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[0] = cpu->regs[0] + 360ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d55b8ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xddd20ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5678;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d55ccULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xe1700ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d55e4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d566c;
L_1d55e4:
    if ((cpu->regs[20])==0) goto L_1d5678;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d55f4ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x12b468ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d560c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d5660;
L_1d560c:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d5620;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d5654;
L_1d5620:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1d5634:
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d5640ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5588;
L_1d564c:
    cpu->regs[21] = 4294967295ULL;
    goto L_1d5620;
L_1d5654:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d565cULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5620;
L_1d5660:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d5668ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d560c;
L_1d566c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d5674ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d55e4;
L_1d5678:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d564c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d564c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1d5698ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5620;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d56c8;
L_1d56b8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1d56c8:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1d573c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_1d573c;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1d5734;
L_1d56fc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d5704ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d571c;
L_1d5710:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_1d56b8;
L_1d571c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5710;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1d5730ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5710;
L_1d5734:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_1d56fc;
L_1d573c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 400ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d5754ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_1d56b8;
    /* nop */
}
