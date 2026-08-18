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

void ft__PyStack_AsDict(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2] + 24ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 16));
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x115500ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1a6f00ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a6f0c;
    PB_STR((cpu->regs[0] + 0), cpu->regs[20]);
    PB_STRW((cpu->regs[0] + 8), cpu->regs[19]);
L_1a6f0c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0] + 9ULL;
    cpu->regs[19] = cpu->regs[19] & 18446744073709551608ULL;
    cpu->regs[0] = cpu->regs[19] + (cpu->regs[0] << 3);
    cpu->regs[30] = PB_BASE + 0x1a6f3cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdbd90ULL);
    if ((cpu->regs[0])==0) goto L_1a6f4c;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[19];
    cpu->regs[0] = cpu->regs[1];
    PB_STRB((cpu->regs[1] + -1), cpu->regs[19]);
L_1a6f4c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1a6f7cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1a6fe0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a6f90;
L_1a6f80:
    cpu->regs[0] = 0ULL;
L_1a6f84:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1a6f90:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[30] = PB_BASE + 0x1a6f9cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    if ((cpu->regs[0])==0) goto L_1a6f80;
    if ((cpu->regs[19])==0) goto L_1a6f84;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 0ULL;
L_1a6fb0:
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_GE) goto L_1a6f84;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    cpu->regs[5] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + (cpu->regs[1] << 3)));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_LDRW(cpu->regs[6], (cpu->regs[3] + 8));
    if ((((uint32_t)(cpu->regs[6])))!=0) goto L_1a6fb0;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STR((cpu->regs[5] + 16), cpu->regs[3]);
    goto L_1a6fb0;
L_1a6fe0:
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7018;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = 0ULL;
L_1a6ff4:
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_GE) goto L_1a701c;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[4] + (cpu->regs[1] << 3)));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    cpu->regs[0] = ((uint32_t)((FLAG_EQ) ? (cpu->regs[0] + 1) : cpu->regs[0]));
    goto L_1a6ff4;
L_1a7018:
    cpu->regs[0] = 0ULL;
L_1a701c:
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1a703cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    if ((cpu->regs[0])==0) goto L_1a70d8;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1a7054ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a70d4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1a7068ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a70d4;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1a7080ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a70d0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1a7094ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a70d0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = 56ULL;
    cpu->regs[30] = PB_BASE + 0x1a70a8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a70e0;
    PB_STR((cpu->regs[0] + 0), cpu->regs[23]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[24]);
    PB_STR((cpu->regs[0] + 16), 0ULL); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[22]);
    PB_STR((cpu->regs[0] + 32), cpu->regs[21]); PB_STR((cpu->regs[0] + 32) + 8, 0ULL);
    PB_STR((cpu->regs[0] + 48), cpu->regs[20]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1a70c4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a70d0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
L_1a70d4:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1a70d8:
    cpu->regs[0] = 0ULL;
    goto L_1a70c4;
L_1a70e0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1a70c4;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_1a716c;
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 0));
L_1a7108:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a7110ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1a6fe0ULL);
    cpu->regs[0] = cpu->regs[20] - ((uint64_t)(int64_t)(int32_t)(cpu->regs[0])); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1a715c;
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 32));
    cpu->regs[30] = PB_BASE + 0x1a7120ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    if ((cpu->regs[0])==0) goto L_1a715c;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
L_1a712c:
    cpu->regs[4] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3);
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_GE) goto L_1a7160;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + (cpu->regs[2] << 3)));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    PB_LDRW(cpu->regs[5], (cpu->regs[3] + 8));
    if ((((uint32_t)(cpu->regs[5])))==0) goto L_1a712c;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STR((cpu->regs[4] + 16), cpu->regs[3]);
    goto L_1a712c;
L_1a715c:
    cpu->regs[0] = 0ULL;
L_1a7160:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1a716c:
    cpu->regs[20] = 0ULL;
    goto L_1a7108;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x1a7198ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a71a0;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[19]);
L_1a71a0:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1a7368;
L_1a71d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a7358;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1a71f0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1a74c0ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7340;
    cpu->regs[0] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1a734c;
L_1a7210:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a7334;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0x1a7224ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7328;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_1a7334;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = 0ULL;
    cpu->regs[26] = 1ULL;
L_1a7240:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0x1a724cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1a72bc;
L_1a7250:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1a7260ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7370;
L_1a7268:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_GT) goto L_1a72ec;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a727cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1a7298ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x118accULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
L_1a72a0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1a72ac:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_1a72bc:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[30] = PB_BASE + 0x1a72c8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1a74c0ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7320;
    FLAG_CMP(cpu->regs[26], cpu->regs[25]);
    if (FLAG_EQ) goto L_1a7304;
L_1a72d8:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[25] << 3)), cpu->regs[27]);
    cpu->regs[25] = cpu->regs[25] + 1ULL;
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_1a7240;
L_1a72ec:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_1a7268;
L_1a7304:
    cpu->regs[26] = cpu->regs[26] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[26] << 3;
    cpu->regs[30] = PB_BASE + 0x1a7314ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_1a7398;
    cpu->regs[20] = cpu->regs[0];
    goto L_1a72d8;
L_1a7320:
    PB_LDR(cpu->regs[27], (SP + 80));
    goto L_1a7250;
L_1a7328:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1a7334ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1a7334:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
L_1a7340:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[24]);
    goto L_1a72a0;
L_1a734c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a7354ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1a7210;
L_1a7358:
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_1a72ac;
L_1a7368:
    cpu->regs[30] = PB_BASE + 0x1a736cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1a71d4;
L_1a7370:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a7378ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1a7384ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1a7340;
L_1a7398:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a73a0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1a73acULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    PB_LDR(cpu->regs[27], (SP + 80));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_1a7340;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7444;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    if ((cpu->regs[1])==0) goto L_1a7498;
    cpu->regs[19] = cpu->regs[2];
    if ((cpu->regs[2])==0) goto L_1a7474;
    cpu->regs[22] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[7];
    cpu->regs[1] = 48ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[23] = cpu->regs[6];
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1a7410ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a7464;
    PB_STR((cpu->regs[0] + 8), cpu->regs[20]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[21]);
    cpu->regs[1] = 6ULL;
    PB_STRW((cpu->regs[0] + 32), cpu->regs[24]); PB_STRW((cpu->regs[0] + 32) + 4, cpu->regs[25]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[22]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[23]);
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1a7438:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1a7444:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2048ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a745cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a7438;
L_1a7464:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1a7438;
L_1a7474:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2128ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a748cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1a7438;
L_1a7498:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2088ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a74b0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1a7438;
    /* nop */
L_1a74c0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1a75cc;
L_1a74e8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a75bc;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1a7500ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7518;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 640ULL;
    cpu->regs[30] = PB_BASE + 0x1a7514ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1a756c;
L_1a7518:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 148));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a760c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
L_1a7528:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a75f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a7534ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_1a75d4;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1a7544ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1a7a24ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a75ac;
L_1a754c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1a7558:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1a756c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a7574ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x10ca20ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7518;
    cpu->regs[1] = PB_BASE + 0x1a9000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3784ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1a7590ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a7518;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a75a4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1a7a24ULL);
    cpu->regs[3] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1a754c;
L_1a75ac:
    cpu->regs[30] = PB_BASE + 0x1a75b0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1a75e0;
    cpu->regs[3] = 0ULL;
    goto L_1a754c;
L_1a75bc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1a7558;
L_1a75cc:
    cpu->regs[30] = PB_BASE + 0x1a75d0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1a74e8;
L_1a75d4:
    cpu->regs[3] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    goto L_1a754c;
L_1a75e0:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1a7558;
L_1a75f8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1a7558;
L_1a760c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a7688;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1a7698;
L_1a762c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a7634ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_1a7670;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 640ULL;
    cpu->regs[30] = PB_BASE + 0x1a7644ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_1a7670;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a7650ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7670;
    cpu->regs[1] = PB_BASE + 0x280000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2256ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1a766cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1a76b4;
L_1a7670:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
L_1a7674:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1a767c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    goto L_1a7528;
L_1a7688:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[3] = 0ULL;
    goto L_1a7558;
L_1a7698:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a76a0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1a762c;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    goto L_1a767c;
L_1a76b4:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1a76c4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xcf904ULL);
    cpu->regs[30] = PB_BASE + 0x1a76c8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
    if ((cpu->regs[0])==0) goto L_1a7674;
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[1];
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    goto L_1a767c;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] + cpu->regs[3];
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_1a77e0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    if (!((cpu->regs[3] >> 31) & 1)) goto L_1a7848;
L_1a771c:
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_1a77e0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    if (!((cpu->regs[3] >> 31) & 1)) goto L_1a77f4;
L_1a7730:
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_1a77e0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    if (!((cpu->regs[3] >> 31) & 1)) goto L_1a7810;
L_1a7744:
    FLAG_CMP(cpu->regs[19], 3ULL);
    if (FLAG_EQ) goto L_1a77e0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1a782c;
L_1a7758:
    FLAG_CMP(cpu->regs[19], 4ULL);
    if (FLAG_EQ) goto L_1a77e0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1a7864;
L_1a776c:
    FLAG_CMP(cpu->regs[19], 5ULL);
    if (FLAG_EQ) goto L_1a77e0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1a7880;
L_1a7780:
    FLAG_CMP(cpu->regs[19], 6ULL);
    if (FLAG_EQ) goto L_1a77e0;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1a789c;
L_1a7794:
    FLAG_CMP(cpu->regs[19], 7ULL);
    if (FLAG_EQ) goto L_1a77e0;
    cpu->regs[20] = 7ULL;
    goto L_1a77b0;
L_1a77a4:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_EQ) goto L_1a77e0;
L_1a77b0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + (cpu->regs[20] << 3)));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    if (((cpu->regs[3] >> 31) & 1)) goto L_1a77a4;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_1a77a4;
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a77d4ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_NE) goto L_1a77b0;
L_1a77e0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(51, cpu, tlb, PB_BASE + 0x1230ecULL); return; };
L_1a77f4:
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_1a7730;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a7808ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_1a7730;
L_1a7810:
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_1a7744;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a7824ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_1a7744;
L_1a782c:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1a7758;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a7840ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_1a7758;
L_1a7848:
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_1a771c;
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1a785cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_1a771c;
L_1a7864:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1a776c;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a7878ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_1a776c;
L_1a7880:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1a7780;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a7894ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_1a7780;
L_1a789c:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1a7794;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1a78b0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    goto L_1a7794;
    /* nop */
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7944;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a7998;
    cpu->regs[19] = cpu->regs[2];
    if ((cpu->regs[2])==0) goto L_1a7974;
    cpu->regs[22] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[7];
    cpu->regs[1] = 80ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[23] = cpu->regs[6];
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1a790cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a7964;
    PB_STRW((cpu->regs[0] + 64), cpu->regs[24]); PB_STRW((cpu->regs[0] + 64) + 4, cpu->regs[25]);
    cpu->regs[1] = 8ULL;
    PB_STRW((cpu->regs[0] + 72), cpu->regs[22]); PB_STRW((cpu->regs[0] + 72) + 4, cpu->regs[23]);
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[21]);
    PB_STRW((cpu->regs[0] + 16), cpu->regs[20]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1a7938:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1a7944:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2168ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a795cULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a7938;
L_1a7964:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1a7938;
L_1a7974:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2256ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a798cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_1a7938;
L_1a7998:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a79b0ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_1a7938;
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[4];
    cpu->regs[20] = cpu->regs[5];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[1] = 80ULL;
    cpu->regs[30] = PB_BASE + 0x1a79f8ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a7a10;
    cpu->regs[1] = 17ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[23]); PB_STR((cpu->regs[0] + 8) + 8, cpu->regs[24]);
    PB_STRW((cpu->regs[0] + 64), cpu->regs[21]); PB_STRW((cpu->regs[0] + 64) + 4, cpu->regs[22]);
    PB_STRW((cpu->regs[0] + 72), cpu->regs[19]); PB_STRW((cpu->regs[0] + 72) + 4, cpu->regs[20]);
L_1a7a10:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a7a24:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7a5c;
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x1a7a48ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a7a50;
    PB_STR((cpu->regs[0] + 0), cpu->regs[19]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[20]);
L_1a7a50:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1a7a5c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2296ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a7a74ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a7a50;
    /* nop */
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[2];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[4] = cpu->regs[1];
    if ((cpu->regs[2])==0) goto L_1a7b24;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_1a7b2c;
    cpu->regs[1] = SP;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 0), cpu->regs[4]); PB_STR((SP + 0) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1a7ad0ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x11028cULL);
L_1a7ad0:
    if ((cpu->regs[0])==0) goto L_1a7b7c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1a7b10;
L_1a7adc:
    cpu->regs[0] = 0ULL;
L_1a7ae0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1a7b0c;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_1a7b0c:
    cpu->regs[30] = PB_BASE + 0x1a7b10ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1a7b10:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1a7adc;
    cpu->regs[30] = PB_BASE + 0x1a7b20ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1a7adc;
L_1a7b24:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    if ((cpu->regs[0])!=0) goto L_1a7bb4;
L_1a7b2c:
    if ((cpu->regs[4])==0) goto L_1a7b84;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 8));
    cpu->regs[30] = PB_BASE + 0x1a7b38ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x1e8fa0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 48));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if ((cpu->regs[2])==0) goto L_1a7bbc;
    if ((cpu->regs[20])==0) goto L_1a7b8c;
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[3] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2344ULL;
    cpu->regs[3] = cpu->regs[3] + 2384ULL;
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[1];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a7b74ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1a7b74:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a7b7cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x18d760ULL);
L_1a7b7c:
    cpu->regs[0] = 4294967295ULL;
    goto L_1a7ae0;
L_1a7b84:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3368));
L_1a7b8c:
    FLAG_CMP(cpu->regs[19], 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[2] = PB_BASE + 0x289000ULL;
    cpu->regs[2] = cpu->regs[2] + 2528ULL;
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2504ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1a7bb0ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1a7b74;
L_1a7bb4:
    cpu->regs[30] = PB_BASE + 0x1a7bb8ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x120dccULL);
    goto L_1a7ad0;
L_1a7bbc:
    if ((cpu->regs[20])==0) goto L_1a7b8c;
    FLAG_CMP(cpu->regs[19], 0ULL);
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[2] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2424ULL;
    cpu->regs[2] = cpu->regs[2] + 2464ULL;
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[2] : cpu->regs[1];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1a7be0ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1a7b74;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1a7c54;
    cpu->regs[19] = cpu->regs[1];
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_1a7c80;
    cpu->regs[0] = cpu->regs[6];
    cpu->regs[1] = 48ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[22] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x1a7c24ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1a7c74;
    cpu->regs[1] = 23ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[20]);
    PB_STRW((cpu->regs[0] + 16), cpu->regs[19]);
    PB_STRW((cpu->regs[0] + 32), cpu->regs[23]); PB_STRW((cpu->regs[0] + 32) + 4, cpu->regs[24]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[21]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_1a7c48:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1a7c54:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2552ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a7c6cULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a7c48;
L_1a7c74:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1a7c48;
L_1a7c80:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2592ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1a7c98ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1a7c48;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[3]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1a7cdc;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    if ((cpu->regs[20])==0) goto L_1a7d00;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(78, cpu, tlb, PB_BASE + 0x120dccULL); return; };
L_1a7cdc:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1a7cec;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1a7cec:
    cpu->regs[20] = cpu->regs[19];
L_1a7cf0:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1a7d00:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[30] = PB_BASE + 0x1a7d08ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x1e8fa0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_1a7d40;
    if ((cpu->regs[19])==0) goto L_1a7d58;
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2632ULL;
    cpu->regs[30] = PB_BASE + 0x1a7d34ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1a7d34:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1a7d3cULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1a7cf0;
L_1a7d40:
    if ((cpu->regs[19])==0) goto L_1a7d58;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2672ULL;
    cpu->regs[30] = PB_BASE + 0x1a7d54ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1a7d34;
L_1a7d58:
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 2712ULL;
    cpu->regs[30] = PB_BASE + 0x1a7d64ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1a7d34;
    { PB_CALL(84, cpu, tlb, PB_BASE + 0x1a7d6cULL); return; };
}
