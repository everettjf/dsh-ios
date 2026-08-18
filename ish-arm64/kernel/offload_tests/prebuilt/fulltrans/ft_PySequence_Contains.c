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

void ft_PySequence_Contains(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 104));
    if ((cpu->regs[4])==0) goto L_11e734;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 56));
    if ((cpu->regs[4])==0) goto L_11e734;
    cpu->regs[16] = cpu->regs[4];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_11e734:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[29] = SP;
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x11e74cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x276a88ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    /* nop */
    /* nop */
L_11e760:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3216));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_11e7a4;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x14b6c4ULL); return; };
L_11e7a4:
    cpu->regs[2] = PB_BASE + 0x495000ULL;
    cpu->regs[2] = cpu->regs[2] + 576ULL;
    cpu->regs[2] = cpu->regs[2] + 2536ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_11e8a0;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_11e8b0;
L_11e7c8:
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 36));
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_11e94c;
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_11e880;
L_11e7ec:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_11e824;
L_11e7fc:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[21] = 1ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + cpu->regs[21]));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[0]);
L_11e80c:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_11e824:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x11e830ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11e760ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11e890;
    cpu->regs[19] = cpu->regs[19] + 24ULL;
    cpu->regs[23] = 1ULL;
    FLAG_CMP(cpu->regs[22], 1ULL);
    if (FLAG_EQ) goto L_11e878;
L_11e848:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + (cpu->regs[23] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_11e7fc;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x11e868ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11e760ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11e890;
    FLAG_CMP(cpu->regs[23], cpu->regs[22]);
    if (FLAG_NE) goto L_11e848;
L_11e878:
    PB_LDRW(cpu->regs[2], (cpu->regs[20] + 36));
    /* nop */
L_11e880:
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[21] = 0ULL;
    PB_STRW((cpu->regs[20] + 36), cpu->regs[2]);
    goto L_11e80c;
L_11e890:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[0]);
    goto L_11e80c;
L_11e8a0:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_11e7c8;
L_11e8b0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 29400ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x11e8c8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xed124ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11e994;
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3920ULL;
    cpu->regs[30] = PB_BASE + 0x11e8e0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xea32cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11e970;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11e8f0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_11e91c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11e91c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11e91cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_11e91c:
    if ((cpu->regs[19])==0) goto L_11e98c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11e928ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_11e80c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11e80c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x11e948ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11e80c;
L_11e94c:
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3920ULL;
    cpu->regs[30] = PB_BASE + 0x11e95cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x26c444ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11e98c;
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_GT) goto L_11e7ec;
    goto L_11e878;
L_11e970:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_11e98c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_11e98c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x11e98cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_11e98c:
    cpu->regs[21] = 4294967295ULL;
    goto L_11e80c;
L_11e994:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 96));
    if ((cpu->regs[0])==0) goto L_11e9a4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_11e98c;
L_11e9a4:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x14b6c4ULL); return; };
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[3] + 32ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[4] = 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x11eae4ULL); return; };
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3664));
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[0] + 24ULL;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2296));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = 0ULL;
L_11ea18:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = 2ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_LE) goto L_11eaa4;
    PB_LDR(cpu->regs[0], (cpu->regs[26] + (cpu->regs[20] << 3)));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_EQ) goto L_11ea84;
    cpu->regs[30] = PB_BASE + 0x11ea3cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_11eaac;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[25]);
    if (FLAG_NE) goto L_11eab4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    cpu->regs[23] = (FLAG_EQ) ? 1 : 0;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_11eac4;
L_11ea60:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_11ea18;
L_11ea68:
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_11ea84:
    cpu->regs[23] = 1ULL;
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_11eaa4:
    cpu->regs[23] = 0ULL;
    goto L_11ea68;
L_11eaac:
    cpu->regs[23] = 4294967295ULL;
    goto L_11ea68;
L_11eab4:
    cpu->regs[30] = PB_BASE + 0x11eab8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_11ea60;
L_11eac4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11ea60;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x11eae0ULL; PB_CALL(17, cpu, tlb, cpu->regs[1]);
    goto L_11ea60;
}
