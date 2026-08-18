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

void ft_PyUnicode_AsUTF8(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xe9aa4ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1947ccULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[21] = cpu->regs[0] + 2ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1947d8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1948cc;
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1948c0;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
L_1947f0:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(10ULL)));
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(cpu->regs[0]))), 0);
    if (FLAG_EQ) goto L_194810;
    goto L_1948b0;
L_194804:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[2];
L_194810:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(13ULL)));
    if (FLAG_EQ) goto L_19488c;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[4] = cpu->regs[19] + 1ULL;
    PB_STRB(cpu->regs[0], cpu->regs[1]); cpu->regs[0] += 1;
    PB_LDRB(cpu->regs[2], (cpu->regs[19] + 1));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_194804;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(10ULL)));
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[22]))) & (((uint32_t)(cpu->regs[1]))), 0);
    if (FLAG_NE) goto L_19487c;
L_19483c:
    cpu->regs[1] = cpu->regs[0] - cpu->regs[20];
    PB_STRB((cpu->regs[0] + 0), 0ULL);
    cpu->regs[1] = cpu->regs[1] + 1ULL; FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], cpu->regs[1]); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_194864;
L_194850:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x194858ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1948d8;
L_194860:
    cpu->regs[20] = cpu->regs[19];
L_194864:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_19487c:
    cpu->regs[1] = 10ULL;
    cpu->regs[0] = cpu->regs[3] + 2ULL;
    PB_STRB((cpu->regs[3] + 1), cpu->regs[1]);
    goto L_19483c;
L_19488c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 10ULL;
    PB_STRB(cpu->regs[3], cpu->regs[0]); cpu->regs[3] += 1;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[0] = 1ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + 1));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1947f0;
L_1948a8:
    cpu->regs[0] = cpu->regs[3];
    goto L_19483c;
L_1948b0:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 1));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1948a8;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_194810;
L_1948c0:
    cpu->regs[1] = 1ULL;
    PB_STRB((cpu->regs[0] + 0), 0ULL);
    goto L_194850;
L_1948cc:
    cpu->regs[0] = 15ULL;
    PB_STRW((cpu->regs[23] + 64), cpu->regs[0]);
    goto L_194864;
L_1948d8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1948e0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_194860;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    if ((cpu->regs[1])==0) goto L_194920;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_194920;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[16] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_194920:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x19492cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x194ac0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_194958;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3776));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_194970;
L_194948:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_194958:
    cpu->regs[30] = PB_BASE + 0x19495cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = 5ULL;
    cpu->regs[30] = PB_BASE + 0x194968ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xbddc8ULL);
L_194968:
    cpu->regs[20] = 0ULL;
    goto L_194948;
L_194970:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[1] = cpu->regs[1] + 392ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x19498cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_194968;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_194968;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1949acULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_194948;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1949d4ULL; PB_CALL(11, cpu, tlb, cpu->regs[22]);
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 2744), cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1949f8;
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(239ULL)));
    if (FLAG_EQ) goto L_194a0c;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1949f8ULL; PB_CALL(12, cpu, tlb, cpu->regs[21]);
L_1949f8:
    cpu->regs[0] = 1ULL;
L_1949fc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_194a0c:
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x194a18ULL; PB_CALL(13, cpu, tlb, cpu->regs[22]);
    cpu->regs[23] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(187ULL)));
    if (FLAG_EQ) goto L_194a40;
    cpu->regs[1] = cpu->regs[19];
L_194a28:
    cpu->regs[30] = PB_BASE + 0x194a2cULL; PB_CALL(14, cpu, tlb, cpu->regs[21]);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x194a38ULL; PB_CALL(15, cpu, tlb, cpu->regs[21]);
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_1949f8;
L_194a40:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x194a48ULL; PB_CALL(16, cpu, tlb, cpu->regs[22]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(191ULL)));
    if (FLAG_EQ) goto L_194a64;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x194a58ULL; PB_CALL(17, cpu, tlb, cpu->regs[21]);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    goto L_194a28;
L_194a64:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2752));
    if ((cpu->regs[0])==0) goto L_194a70;
    cpu->regs[30] = PB_BASE + 0x194a70ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_194a70:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 5ULL;
    cpu->regs[0] = cpu->regs[0] + 1576ULL;
    cpu->regs[30] = PB_BASE + 0x194a84ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1de500ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STR((cpu->regs[19] + 2752), cpu->regs[0]);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    goto L_1949fc;
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2816));
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[0] + 2816), cpu->regs[2]);
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 0));
    return;
    /* nop */
    /* nop */
    /* nop */
}
