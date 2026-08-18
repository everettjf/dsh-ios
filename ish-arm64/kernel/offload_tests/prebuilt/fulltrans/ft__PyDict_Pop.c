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

void ft__PyDict_Pop(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1a9794;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_1a9770;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 24));
    FLAG_CMP(cpu->regs[2], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1a9770;
L_1a9760:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_1a988c;
L_1a9770:
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[1]); PB_STR((SP + 32) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1a977cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    PB_LDR(cpu->regs[1], (SP + 32)); PB_LDR(cpu->regs[3], (SP + 32) + 8);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1a9760;
    cpu->regs[3] = 0ULL;
    goto L_1a97a4;
L_1a9794:
    if ((cpu->regs[2])==0) goto L_1a97bc;
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1a97b4;
L_1a97a4:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1a97b4:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_1a97a4;
L_1a97bc:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1a97c4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1bdee0ULL);
    cpu->regs[3] = 0ULL;
    goto L_1a97a4;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a97f0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x125060ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9884;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a9804ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x125060ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9884;
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 16));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[1] = 0ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[22])==0) goto L_1a9824;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
L_1a9824:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_1a9854;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a9838ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1a99ccULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
L_1a9844:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a9854:
    cpu->regs[0] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[23])) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1a9870;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a986cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x125060ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9880;
L_1a9870:
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    goto L_1a9824;
L_1a9880:
    PB_LDR(cpu->regs[23], (SP + 48));
L_1a9884:
    cpu->regs[0] = 0ULL;
    goto L_1a9844;
L_1a988c:
    SP = SP - 96ULL;
    cpu->regs[5] = cpu->tls_ptr;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1a98b4ULL; PB_CALL(7, cpu, tlb, cpu->regs[4]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[3];
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_LDR(cpu->regs[5], (cpu->regs[5] + cpu->regs[0]));
    PB_STR((SP + 80), cpu->regs[25]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[25], (cpu->regs[5] + 16));
    if ((cpu->regs[0])==0) goto L_1a9910;
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[3] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a98fcULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdd360ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(3ULL)));
    if (FLAG_EQ) goto L_1a99c4;
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1a9928;
L_1a9910:
    if ((cpu->regs[21])==0) goto L_1a99bc;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1a99ac;
    cpu->regs[24] = cpu->regs[21];
    goto L_1a9970;
L_1a9928:
    PB_LDR(cpu->regs[24], (SP + 0));
    if ((cpu->regs[24])==0) goto L_1a9910;
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = 2ULL;
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a9948ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xde604ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[24] + 0));
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1a995c;
    PB_STRW((cpu->regs[24] + 0), cpu->regs[1]);
L_1a995c:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1a9970ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x114640ULL);
L_1a9970:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1a99b8;
    PB_LDR(cpu->regs[25], (SP + 80));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_1a99ac:
    cpu->regs[24] = cpu->regs[21];
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_1a9970;
L_1a99b8:
    cpu->regs[30] = PB_BASE + 0x1a99bcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1a99bc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1a99c4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1bdee0ULL);
L_1a99c4:
    cpu->regs[24] = 0ULL;
    goto L_1a9970;
L_1a99cc:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(25ULL)));
    if (FLAG_EQ) goto L_1a9a00;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(8ULL)));
    if (FLAG_EQ) goto L_1a9a64;
L_1a99f0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a9a00:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_1a9abc;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
L_1a9a0c:
    cpu->regs[5] = cpu->regs[0] + 16ULL;
    cpu->regs[2] = 0ULL;
L_1a9a14:
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_GE) goto L_1a9a34;
    PB_LDR(cpu->regs[3], (cpu->regs[5] + (cpu->regs[2] << 3)));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(23ULL)));
    if (FLAG_NE) goto L_1a9a14;
    goto L_1a99f0;
L_1a9a34:
    cpu->regs[2] = 26ULL;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[2]);
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a9a44ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1aa520ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 56));
L_1a9a4c:
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x1aa680ULL); return; };
L_1a9a64:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a9a70ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1aa520ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 56));
    if ((cpu->regs[0])==0) goto L_1a9a4c;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1a9a84ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1b2528ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 56));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1a9ab0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1a9ab0;
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a9aacULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
L_1a9ab0:
    cpu->regs[20] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_1a9a4c;
L_1a9abc:
    cpu->regs[4] = 0ULL;
    goto L_1a9a0c;
    SP = SP - 96ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1a9b68;
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a9b04ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1944d0ULL);
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(4294967291ULL))), 0);
    if (FLAG_NE) goto L_1a9b58;
    PB_LDRB(cpu->regs[2], (SP + 40));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    FLAG_CMP((cpu->regs[2]) & (1ULL), 0);
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_1a9b28:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1a9b54;
    PB_LDR(cpu->regs[19], (SP + 80));
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_1a9b54:
    cpu->regs[30] = PB_BASE + 0x1a9b58ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1a9b58:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a9b60ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xbddc8ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a9b28;
L_1a9b68:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x2ab000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = cpu->regs[0] + 3616ULL;
    cpu->regs[30] = PB_BASE + 0x1a9b88ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x23b310ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a9b28;
L_1a9b90:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1a9dec;
L_1a9bbc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a9e18;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1a9df8;
L_1a9be0:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x1a9becULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1a9f40ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a9d78;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1a9dc4;
L_1a9c0c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a9ddc;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1a9c20ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a9dd0;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_1a9ddc;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = 0ULL;
    cpu->regs[26] = 1ULL;
L_1a9c3c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1a9c48ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1a9ce4;
L_1a9c4c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1a9c5cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a9d90;
L_1a9c64:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_GT) goto L_1a9d14;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a9c78ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1a9c94ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x118accULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_1a9db8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1a9cb4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a9d84;
L_1a9cc8:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
L_1a9cd0:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1a9ce4:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x1a9cf0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1a9f40ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a9d48;
    FLAG_CMP(cpu->regs[26], cpu->regs[25]);
    if (FLAG_EQ) goto L_1a9d2c;
L_1a9d00:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[25] << 3)), cpu->regs[27]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_1a9c3c;
L_1a9d14:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_1a9c64;
L_1a9d2c:
    cpu->regs[26] = cpu->regs[26] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[26] << 3;
    cpu->regs[30] = PB_BASE + 0x1a9d3cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_1a9d50;
    cpu->regs[20] = cpu->regs[0];
    goto L_1a9d00;
L_1a9d48:
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_1a9c4c;
L_1a9d50:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a9d58ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1a9d64ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_1a9d78:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1a9d84:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    goto L_1a9cc8;
L_1a9d90:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a9d98ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1a9da4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1a9d78;
L_1a9db8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1a9d84;
L_1a9dc4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a9dccULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1a9c0c;
L_1a9dd0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1a9ddcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1a9ddc:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_1a9d78;
L_1a9dec:
    cpu->regs[30] = PB_BASE + 0x1a9df0ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    goto L_1a9bbc;
L_1a9df8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a9e00ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9be0;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_1a9d84;
L_1a9e18:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[20] = 0ULL;
    goto L_1a9cd0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1a9eac;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_1a9e5c;
    cpu->regs[30] = PB_BASE + 0x1a9e58ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x125060ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9ebc;
L_1a9e5c:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 24));
    cpu->regs[3] = 0ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[20])==0) goto L_1a9e74;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
L_1a9e74:
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_LE) goto L_1a9ea8;
    cpu->regs[0] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1a9e98;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1a9e94ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1243f0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9ebc;
L_1a9e98:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[19]));
    goto L_1a9e74;
L_1a9ea8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1a9eac:
    cpu->regs[0] = 1ULL;
L_1a9eb0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1a9ebc:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    goto L_1a9eb0;
    { PB_CALL(41, cpu, tlb, PB_BASE + 0x2808d0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    if ((cpu->regs[0])!=0) goto L_1a9f0c;
    cpu->regs[19] = cpu->regs[2];
    if ((cpu->regs[2])==0) goto L_1a9f2c;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1a9ef4ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1aa424ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9f24;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(43, cpu, tlb, PB_BASE + 0x1904c0ULL); return; };
L_1a9f0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3640ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a9f24ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1a9f24:
    cpu->regs[0] = 4294967295ULL;
    goto L_1a9f30;
L_1a9f2c:
    cpu->regs[0] = 0ULL;
L_1a9f30:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
L_1a9f40:
    SP = SP - 80ULL;
    cpu->regs[3] = 6000ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 144));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_EQ) goto L_1aa380;
L_1a9f80:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aa3a0;
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 1189ULL;
    PB_STR((SP + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1a9f9cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x196cacULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aa298;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[21])));
    if (FLAG_EQ) goto L_1aa330;
L_1a9fb0:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[21])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1aa408;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a9fd0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x107820ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1aa0b8;
L_1a9fd8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aa408;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a9fecULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x107820ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1aa140;
L_1a9ff4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1aa388;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_1aa3f4;
L_1aa018:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16)); PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1aa3bc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
L_1aa030:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa038ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aa1c8;
L_1aa040:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1aa04cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x10d8f0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aa278;
L_1aa054:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
L_1aa060:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1189ULL;
    cpu->regs[30] = PB_BASE + 0x1aa074ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1082e0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
L_1aa088:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1aa324;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 80ULL;
    return;
L_1aa0b8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 23ULL;
    cpu->regs[30] = PB_BASE + 0x1aa0c4ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a9fd8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa0d0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a9fd8;
    cpu->regs[1] = PB_BASE + 0x10c000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 528ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aa0ecULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9fd8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1aa0fcULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x10cd80ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aa408;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[23];
    PB_LDRW(cpu->regs[5], (cpu->regs[2] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[2] + 28) + 4);
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1aa124ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x10dae0ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1aa060;
L_1aa130:
    cpu->regs[30] = PB_BASE + 0x1aa134ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1aa35c;
    cpu->regs[20] = 0ULL;
    goto L_1aa060;
L_1aa140:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x1aa14cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a9ff4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa158ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x1a0d64ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a9ff4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x1aa16cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a9ff4;
    cpu->regs[1] = PB_BASE + 0x10c000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 528ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1aa184ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a9ff4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1aa194ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1aa408;
    PB_LDR(cpu->regs[7], (cpu->regs[19] + 32));
    cpu->regs[4] = cpu->regs[23];
    PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[6], (cpu->regs[0] + 28) + 4);
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1aa1b8ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1a1c50ULL);
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1aa060;
    goto L_1aa130;
L_1aa1c8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aa280;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1aa1e0ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1aa204;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa1ecULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1a9f40ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1aa204;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1aa200ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1aa3b4;
L_1aa204:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1aa280;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0x1aa21cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1aa2ac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa228ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x1a9b90ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[24] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1aa2b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1aa240ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1aa2ac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1aa250ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1aa280;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1aa270ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1a4ee0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1aa054;
L_1aa278:
    cpu->regs[30] = PB_BASE + 0x1aa27cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1aa3e0;
L_1aa280:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_1aa288:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1aa060;
L_1aa298:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[20], (SP + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1aa088;
L_1aa2ac:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
L_1aa2b0:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1aa280;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 9ULL;
    cpu->regs[30] = PB_BASE + 0x1aa2c4ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1aa280;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa2d0ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x1a9b90ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    cpu->regs[20] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1aa280;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x1aa2e8ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1aa280;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1aa2f8ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x10cd80ULL);
    if ((cpu->regs[0])==0) goto L_1aa280;
    PB_LDR(cpu->regs[6], (cpu->regs[19] + 32));
    cpu->regs[3] = cpu->regs[23];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 28)); PB_LDRW(cpu->regs[5], (cpu->regs[0] + 28) + 4);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x1aa318ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x19fc84ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1aa054;
    goto L_1aa278;
L_1aa324:
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0x1aa330ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1aa330:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa338ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1a9fb0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    goto L_1aa088;
L_1aa35c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1aa088;
L_1aa380:
    cpu->regs[30] = PB_BASE + 0x1aa384ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1a9f80;
L_1aa388:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1aa088;
L_1aa3a0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_1aa088;
L_1aa3b4:
    cpu->regs[1] = cpu->regs[24];
    goto L_1aa040;
L_1aa3bc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa3c4ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xf27b0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1aa3e0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    PB_LDRW(cpu->regs[22], (cpu->regs[0] + 20)); PB_LDRW(cpu->regs[23], (cpu->regs[0] + 20) + 4);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1aa030;
    goto L_1aa280;
L_1aa3e0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_1aa288;
L_1aa3f4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1aa3fcULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1aa018;
    goto L_1aa280;
L_1aa408:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    goto L_1aa088;
}
