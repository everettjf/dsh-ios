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

void ft__Py_CheckFunctionResult(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[2])==0) goto L_e88b4;
    if ((cpu->regs[0])!=0) goto L_e88c8;
L_e88a4:
    cpu->regs[0] = cpu->regs[2];
L_e88a8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_e88b4:
    if ((cpu->regs[0])==0) goto L_e8914;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_e8914;
    cpu->regs[0] = 0ULL;
    goto L_e88a8;
L_e88c8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_e88a4;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e88e4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e8960;
L_e88e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])==0) goto L_e8974;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] + 712ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe890cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xa6218ULL);
    cpu->regs[0] = 0ULL;
    goto L_e88a8;
L_e8914:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[1])==0) goto L_e8944;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[2] + 616ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe893cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x225d40ULL);
    cpu->regs[0] = 0ULL;
    goto L_e88a8;
L_e8944:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 664ULL;
    cpu->regs[30] = PB_BASE + 0xe8958ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x225d40ULL);
    cpu->regs[0] = 0ULL;
    goto L_e88a8;
L_e8960:
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[1]); PB_STR((SP + 32) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xe896cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 32)); PB_LDR(cpu->regs[3], (SP + 32) + 8);
    goto L_e88e4;
L_e8974:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 760ULL;
    cpu->regs[30] = PB_BASE + 0xe8988ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xa6218ULL);
    cpu->regs[0] = 0ULL;
    goto L_e88a8;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] + (18ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 1808ULL;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[19], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_e8b60;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -16));
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[1])==0) goto L_e8bf8;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    cpu->regs[3] = PB_BASE + 0xe8000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 48));
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[3] + 2448ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_e8c10;
L_e8a10:
    cpu->regs[23] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe8a24ULL; PB_CALL(6, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[21], (cpu->regs[23] + cpu->regs[0]));
    if ((cpu->regs[21])==0) goto L_e8c24;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 152));
    cpu->regs[1] = cpu->regs[21] + 152ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_GT) goto L_e8c38;
L_e8a3c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[20] - 1ULL; FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_LT) goto L_e8b94;
L_e8a4c:
    cpu->regs[22] = cpu->regs[19] + (cpu->regs[20] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    if ((cpu->regs[0])==0) goto L_e8a60;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_e8b6c;
L_e8a60:
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_e8ac0;
L_e8a68:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    if ((cpu->regs[0])==0) goto L_e8a84;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e8a84;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_e8bc8;
L_e8a84:
    cpu->regs[22] = cpu->regs[20] - 3ULL;
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_EQ) goto L_e8abc;
L_e8a90:
    cpu->regs[20] = cpu->regs[19] + 24ULL;
L_e8a94:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (cpu->regs[22] << 3)));
    if ((cpu->regs[0])==0) goto L_e8ab0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_e8ab0;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_e8be8;
L_e8ab0:
    cpu->regs[22] = cpu->regs[22] - 1ULL;
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_e8a94;
L_e8abc:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
L_e8ac0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe8ad0ULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[20])==0) goto L_e8bb0;
    cpu->regs[1] = cpu->regs[20] - 1ULL;
    FLAG_CMP(cpu->regs[1], 19ULL);
    if (FLAG_GT) goto L_e8bb0;
L_e8ae8:
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[1] << 2);
    cpu->regs[4] = cpu->regs[1] << 2;
    cpu->regs[2] = cpu->regs[2] + (64ULL << 12);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + 7848));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1999ULL)));
    if (FLAG_GT) goto L_e8bb0;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2640));
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_NE) goto L_e8bb0;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 3);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[1] = cpu->regs[1] + (64ULL << 12);
    cpu->regs[0] = cpu->regs[0] + (64ULL << 12);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 7688));
    PB_STR((cpu->regs[19] + 24), cpu->regs[3]);
    PB_STR((cpu->regs[1] + 7688), cpu->regs[19]);
    PB_STRW((cpu->regs[0] + 7848), cpu->regs[2]);
    if ((cpu->regs[21])==0) goto L_e8b58;
L_e8b3c:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[21] + 152), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_e8b58;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 160));
    if ((cpu->regs[2])!=0) goto L_e8c84;
L_e8b58:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48));
L_e8b60:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_e8b6c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e8a60;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe8b84ULL; PB_CALL(8, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_NE) goto L_e8a68;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    goto L_e8ac0;
L_e8b94:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe8ba4ULL; PB_CALL(9, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[20])!=0) goto L_e8ae8;
L_e8bb0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0xe8bc0ULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[21])!=0) goto L_e8b3c;
    goto L_e8b58;
L_e8bc8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[22] = cpu->regs[20] - 3ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe8bd8ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_NE) goto L_e8a90;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    goto L_e8ac0;
L_e8be8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe8bf4ULL; PB_CALL(12, cpu, tlb, cpu->regs[1]);
    goto L_e8ab0;
L_e8bf8:
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0xe8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2448ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_e8a10;
L_e8c10:
    cpu->regs[1] = cpu->regs[20] - 1ULL; FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_LT) goto L_e8c5c;
    cpu->regs[23] = cpu->tls_ptr;
    cpu->regs[21] = 0ULL;
    goto L_e8a4c;
L_e8c24:
    cpu->regs[30] = PB_BASE + 0xe8c28ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7c39cULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_LE) goto L_e8ce8;
L_e8c38:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_STR((cpu->regs[1] + 8), cpu->regs[19]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_e8b60;
L_e8c5c:
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe8c70ULL; PB_CALL(14, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[20])==0) goto L_e8cc8;
    cpu->regs[21] = 0ULL;
    goto L_e8ae8;
L_e8c84:
    PB_STRW((cpu->regs[21] + 152), cpu->regs[1]);
    goto L_e8ca8;
L_e8c8c:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 48));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    PB_STR((cpu->regs[21] + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xe8ca4ULL; PB_CALL(15, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 160));
L_e8ca8:
    cpu->regs[0] = cpu->regs[2];
    if ((cpu->regs[2])!=0) goto L_e8c8c;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 152));
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[21] + 152), cpu->regs[0]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_e8b60;
L_e8cc8:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_e8ce8:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 16));
    goto L_e8a3c;
    SP = SP - 160ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 56), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[1])==0) goto L_e927c;
    cpu->regs[20] = cpu->regs[3];
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[19] = cpu->regs[2];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    FLAG_CMP((cpu->regs[3]) & (536870912ULL), 0);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_e927c;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 168));
    if (!((cpu->regs[4] >> 29) & 1)) goto L_e9014;
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x1de000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 216));
    cpu->regs[4] = cpu->regs[4] + 3340ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_NE) goto L_e9014;
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_EQ) goto L_e8d70;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 16));
    if ((cpu->regs[3])!=0) goto L_e8da4;
L_e8d70:
    cpu->regs[0] = 0ULL;
L_e8d74:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_e915c;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    SP = SP + 160ULL;
    return;
L_e8da4:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    if ((cpu->regs[2])!=0) goto L_e8e4c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    if ((cpu->regs[1])!=0) goto L_e8e48;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_NE) goto L_e8e48;
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_e8fec;
L_e8dd0:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = 3ULL;
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0xe8decULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xde604ULL);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe8df8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe3740ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e9294;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 32));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe8e0cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe9320ULL);
    PB_STR((cpu->regs[21] + 32), cpu->regs[20]);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    if ((cpu->regs[0])!=0) goto L_e91a8;
L_e8e18:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -16));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[21] + 16), cpu->regs[1]); PB_STR((cpu->regs[21] + 16) + 8, cpu->regs[23]);
    if ((cpu->regs[0])!=0) goto L_e8e30;
L_e8e28:
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    goto L_e8d70;
L_e8e30:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + -16));
    if ((cpu->regs[0])!=0) goto L_e8e28;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe8e40ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xd9444ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    goto L_e8d70;
L_e8e48:
    cpu->regs[20] = 1ULL;
L_e8e4c:
    PB_LDR(cpu->regs[5], (cpu->regs[21] + 32));
    cpu->regs[1] = 2ULL;
    cpu->regs[4] = 3ULL;
    PB_LDRB(cpu->regs[5], (cpu->regs[5] + 8));
    cpu->regs[1] = cpu->regs[1] << (cpu->regs[5] & 63);
    cpu->regs[1] = (cpu->regs[4] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[4]) : 0);
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_GT) goto L_e910c;
L_e8e6c:
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[24] = SP + 32ULL;
    cpu->regs[1] = SP + 48ULL;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[26] = SP + 40ULL;
    cpu->regs[25] = SP + 24ULL;
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((SP + 0), cpu->regs[1]);
    PB_STR((SP + 48), 0ULL);
    PB_LDR(cpu->regs[27], (cpu->regs[0] + 24));
L_e8e98:
    cpu->regs[4] = cpu->regs[26];
    PB_LDR(cpu->regs[1], (SP + 0));
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe8eb0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xecfd0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e8fdc;
    PB_LDR(cpu->regs[23], (SP + 32));
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e8ec8;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
L_e8ec8:
    PB_LDR(cpu->regs[28], (SP + 24));
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e8edc;
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
L_e8edc:
    PB_LDR(cpu->regs[3], (SP + 40));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_e8fac;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_e8fd4;
L_e8ef4:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e8f04;
    PB_STRW((cpu->regs[28] + 0), cpu->regs[0]);
L_e8f04:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe8f18ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdfd00ULL);
    cpu->regs[1] = cpu->regs[0];
L_e8f1c:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_e8f8c;
L_e8f24:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_e8f6c;
L_e8f2c:
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_e8f58;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_EQ) goto L_e8e98;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xe8f58ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_e8f58:
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
L_e8f64:
    cpu->regs[0] = 4294967295ULL;
    goto L_e8d74;
L_e8f6c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e8f2c;
    cpu->regs[0] = cpu->regs[23];
    PB_STRW((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xe8f84ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[1], (SP + 8));
    goto L_e8f2c;
L_e8f8c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e8f24;
    cpu->regs[0] = cpu->regs[28];
    PB_STRW((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xe8fa4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[1], (SP + 8));
    goto L_e8f24;
L_e8fac:
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xe8fc0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x20afe8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_e92a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[3], (SP + 8));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_e8ef4;
L_e8fd4:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_e8ef4;
L_e8fdc:
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_e8d74;
L_e8fec:
    cpu->regs[20] = 1ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[1] = cpu->regs[20] << (cpu->regs[1] & 63);
    cpu->regs[4] = 3ULL;
    cpu->regs[1] = (cpu->regs[5] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[5]) : 0);
    cpu->regs[1] = cpu->regs[1] << 1;
    cpu->regs[1] = (cpu->regs[4] ? (uint64_t)((int64_t)cpu->regs[1] / (int64_t)cpu->regs[4]) : 0);
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_GT) goto L_e8dd0;
    goto L_e8e4c;
L_e9014:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe901cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d2d70ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e8f64;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0xe902cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e9044;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_e9264;
L_e9044:
    if ((cpu->regs[24])==0) goto L_e9294;
    cpu->regs[0] = cpu->regs[24];
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0xe9054ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[22] = cpu->regs[0];
L_e9058:
    if ((cpu->regs[22])==0) goto L_e90d8;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_e916c;
L_e9064:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe9070ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e91bc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe9088ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[25] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_e90c0;
L_e9094:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e90a8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_e9270;
L_e90a8:
    FLAG_CMP(cpu->regs[25], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_e9220;
L_e90b0:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe90b8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[22] = cpu->regs[0];
    goto L_e9058;
L_e90c0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_e9094;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe90d4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e9094;
L_e90d8:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e90f4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e90f4;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe90f4ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e90f4:
    cpu->regs[30] = PB_BASE + 0xe90f8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    cpu->regs[0] = (FLAG_NE) ? 0xffffffffULL : 0;
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_e8d74;
L_e910c:
    cpu->regs[3] = cpu->regs[3] + cpu->regs[2];
    cpu->regs[5] = 2ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 10));
    cpu->regs[2] = 64ULL;
    cpu->regs[3] = cpu->regs[3] + (cpu->regs[3] << 1);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[3] + 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[3] = (FLAG_NE) ? 1 : 0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[4] = (cpu->regs[5] ? (uint64_t)((int64_t)cpu->regs[4] / (int64_t)cpu->regs[5]) : 0);
    cpu->regs[4] = cpu->regs[4] | 8ULL;
    cpu->regs[4] = cpu->regs[4] - 1ULL;
    cpu->regs[4] = cpu->regs[4] | 7ULL;
    cpu->regs[4] = (((uint64_t)(cpu->regs[4])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[4])));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[4]));
    cpu->regs[30] = PB_BASE + 0xe9150ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe03e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e8e6c;
    cpu->regs[0] = 4294967295ULL;
    goto L_e8d74;
L_e915c:
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0xe916cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7c170ULL);
L_e916c:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe9178ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdd250ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e9064;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_e9204;
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_e91fc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e90b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e90b0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe91a4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e90b0;
L_e91a8:
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + -1));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xe91b4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((cpu->regs[21] + 40), 0ULL);
    goto L_e8e18;
L_e91bc:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e91d8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e91d8;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe91d8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e91d8:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e91ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e924c;
L_e91ec:
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_e8d74;
L_e91fc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe9204ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1bdee0ULL);
L_e9204:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e9220;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e9220;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe9220ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_e9220:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e91ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e91ec;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xe923cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_e8d74;
L_e924c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe9254ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_e8d74;
L_e9264:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xe926cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e9044;
L_e9270:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xe9278ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e90a8;
L_e927c:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = 2823ULL;
    cpu->regs[0] = cpu->regs[0] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0xe928cULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_e8d74;
L_e9294:
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    cpu->regs[0] = 4294967295ULL;
    goto L_e8d74;
L_e92a0:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_e92b0;
    cpu->regs[1] = 4294967295ULL;
    goto L_e8f1c;
L_e92b0:
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_e92bc;
    cpu->regs[1] = 0ULL;
    goto L_e8f1c;
L_e92bc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xe92c4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1bdee0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e92d8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_e9308;
L_e92d8:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e8f58;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e8f58;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xe92f4ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_e8d74;
L_e9308:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0xe9310ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e92d8;
    /* nop */
    /* nop */
    /* nop */
L_e9320:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[4] = 4294967295ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[4]);
    if (FLAG_EQ) goto L_e9340;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_e9340;
    goto L_e9620;
L_e9340:
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe9364ULL; PB_CALL(51, cpu, tlb, cpu->regs[1]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->tls_ptr;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + cpu->regs[0]));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 24));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e95d8;
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_e95dc;
L_e938c:
    cpu->regs[2] = cpu->regs[20] + (64ULL << 12);
    cpu->regs[3] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8576));
    cpu->regs[0] = cpu->regs[0] + 256ULL;
    PB_STR((cpu->regs[2] + 8576), cpu->regs[0]);
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_GT) goto L_e9610;
L_e93a8:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -16));
    if (((cpu->regs[3] >> 31) & 1)) goto L_e94e0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32)); PB_LDR(cpu->regs[22], (cpu->regs[19] + 32) + 8);
    PB_STR((cpu->regs[19] + 0), 0ULL);
    cpu->regs[23] = cpu->regs[1];
    if ((cpu->regs[2])==0) goto L_e94ec;
L_e93c4:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + -8));
    cpu->regs[4] = PB_BASE + 0xe9000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    cpu->regs[3] = cpu->regs[3] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[3];
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 48));
    PB_STR((cpu->regs[2] + 8), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[4] + 836ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + -8));
    cpu->regs[2] = cpu->regs[2] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[2]);
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_e9504;
L_e9404:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe9414ULL; PB_CALL(52, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[21], (cpu->regs[21] + cpu->regs[0]));
    if ((cpu->regs[21])==0) goto L_e955c;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 152));
    cpu->regs[2] = cpu->regs[21] + 152ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_GT) goto L_e9578;
L_e942c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[22])!=0) goto L_e9514;
L_e9438:
    if ((cpu->regs[1])==0) goto L_e9460;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[2] = 4294967295ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_e9460;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e9460;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe9460ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe9620ULL);
L_e9460:
    cpu->regs[20] = cpu->regs[20] + (66ULL << 12);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 1680));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(79ULL)));
    if (FLAG_GT) goto L_e94cc;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2680));
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_NE) goto L_e94cc;
    cpu->regs[20] = cpu->regs[20] + 384ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    cpu->regs[0] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3);
    PB_STRW((cpu->regs[20] + 1296), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]);
    if ((cpu->regs[21])==0) goto L_e94b8;
L_e949c:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[21] + 152), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_e94b8;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 160));
    if ((cpu->regs[2])!=0) goto L_e9598;
L_e94b8:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
L_e94bc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_e94cc:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xe94d8ULL; PB_CALL(54, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[21])!=0) goto L_e949c;
    goto L_e94b8;
L_e94e0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32)); PB_LDR(cpu->regs[22], (cpu->regs[19] + 32) + 8);
    cpu->regs[23] = cpu->regs[1];
    if ((cpu->regs[2])!=0) goto L_e93c4;
L_e94ec:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0xe9000ULL;
    cpu->regs[0] = cpu->regs[0] + 836ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 48));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_e9404;
L_e9504:
    cpu->regs[21] = 0ULL;
    if ((cpu->regs[22])==0) goto L_e9438;
    PB_STR((SP + 64), cpu->regs[25]);
    goto L_e951c;
L_e9514:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STR((SP + 64), cpu->regs[25]);
L_e951c:
    PB_LDR(cpu->regs[25], (cpu->regs[1] + 24));
    cpu->regs[24] = 0ULL;
L_e9524:
    FLAG_CMP(cpu->regs[24], cpu->regs[25]);
    if (FLAG_GE) goto L_e953c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + (cpu->regs[24] << 3)));
    cpu->regs[24] = cpu->regs[24] + 1ULL;
    cpu->regs[30] = PB_BASE + 0xe9538ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_e9524;
L_e953c:
    PB_LDRB(cpu->regs[0], (cpu->regs[22] + -1));
    cpu->regs[0] = cpu->regs[22] - cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xe9548ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe9554ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xe9320ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_e9460;
L_e955c:
    PB_STR((SP + 88), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xe9564ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x7c39cULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[1], (SP + 88));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_LE) goto L_e942c;
L_e9578:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[1];
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    PB_STR((cpu->regs[2] + 8), cpu->regs[19]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_e94bc;
L_e9598:
    PB_STRW((cpu->regs[21] + 152), cpu->regs[1]);
    goto L_e95bc;
L_e95a0:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 48));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    PB_STR((cpu->regs[21] + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0xe95b8ULL; PB_CALL(59, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 160));
L_e95bc:
    cpu->regs[0] = cpu->regs[2];
    if ((cpu->regs[2])!=0) goto L_e95a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[21] + 152), cpu->regs[0]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_e94bc;
L_e95d8:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e938c;
L_e95dc:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 5ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xe95f0ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x9b684ULL);
    cpu->regs[2] = cpu->regs[20] + (64ULL << 12);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8576));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] + 256ULL;
    PB_STR((cpu->regs[2] + 8576), cpu->regs[0]);
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_LE) goto L_e93a8;
L_e9610:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[3] >> 31) & 1)) goto L_e94bc;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    goto L_e94bc;
L_e9620:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = 1ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + 10));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + 9));
    PB_LDR(cpu->regs[23], (cpu->regs[21] + 24));
    cpu->regs[19] = cpu->regs[19] << (cpu->regs[1] & 63);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_e9744;
    cpu->regs[19] = cpu->regs[21] + cpu->regs[19];
    cpu->regs[20] = 0ULL;
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_e96ac;
L_e9664:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_e9680;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_e9680;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_e9734;
L_e9680:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_e969c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_e969c;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_e9724;
L_e969c:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[23]);
    if (FLAG_NE) goto L_e9664;
L_e96ac:
    PB_LDRB(cpu->regs[0], (cpu->regs[21] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_NE) goto L_e96f8;
    cpu->regs[22] = cpu->regs[22] + (66ULL << 12);
    cpu->regs[22] = cpu->regs[22] + 384ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 1300));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(79ULL)));
    if (FLAG_GT) goto L_e96f8;
    PB_LDRB(cpu->regs[1], (cpu->regs[21] + 10));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_e96f8;
    cpu->regs[1] = cpu->regs[22] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[22] + 1300), cpu->regs[0]);
    PB_STR((cpu->regs[1] + 656), cpu->regs[21]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_e96f8:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_e9724:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe9730ULL; PB_CALL(61, cpu, tlb, cpu->regs[1]);
    goto L_e969c;
L_e9734:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe9740ULL; PB_CALL(62, cpu, tlb, cpu->regs[1]);
    goto L_e9680;
L_e9744:
    FLAG_CMP(cpu->regs[23], 0ULL);
    if (FLAG_LE) goto L_e96ac;
    cpu->regs[19] = cpu->regs[21] + cpu->regs[19];
    cpu->regs[20] = 0ULL;
L_e9754:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])==0) goto L_e9770;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_e9770;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_e97a0;
L_e9770:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_e978c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_e978c;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_e97b0;
L_e978c:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 24ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[23]);
    if (FLAG_NE) goto L_e9754;
    goto L_e96ac;
L_e97a0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe97acULL; PB_CALL(63, cpu, tlb, cpu->regs[1]);
    goto L_e9770;
L_e97b0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0xe97bcULL; PB_CALL(64, cpu, tlb, cpu->regs[1]);
    goto L_e978c;
}
