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

void ft_PyGILState_Release(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] + 1544ULL;
    cpu->regs[30] = PB_BASE + 0x20b624ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x182a60ULL);
    if ((cpu->regs[0])==0) goto L_20b6c8;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x20b640ULL; PB_CALL(2, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_20b6b0;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 120));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[2] + 120), cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_20b67c;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_20b670;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x1c8ae8ULL); return; };
L_20b670:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_20b67c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[2] + 120), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x20b690ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1ef260ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[2];
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 120));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[2] + 120), cpu->regs[1]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x242c80ULL); return; };
L_20b6b0:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[0] = cpu->regs[0] + 1704ULL;
    cpu->regs[1] = cpu->regs[1] + 760ULL;
    cpu->regs[30] = PB_BASE + 0x20b6c8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x92290ULL);
L_20b6c8:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[0] = cpu->regs[0] + 1704ULL;
    cpu->regs[1] = cpu->regs[1] + 688ULL;
    cpu->regs[30] = PB_BASE + 0x20b6e0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x91ebcULL);
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[23], 0ULL);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 1ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_20b7bc;
L_20b714:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_GT) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_20b758;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2248));
    cpu->regs[1] = cpu->regs[22] + (16ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 10000));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_20b7e8;
L_20b738:
    cpu->regs[22] = cpu->regs[22] + (18ULL << 12);
    cpu->regs[22] = cpu->regs[22] + 1808ULL;
L_20b740:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_20b758:
    cpu->regs[0] = 9223372036854775807ULL;
    cpu->regs[0] = (cpu->regs[20] ? (uint64_t)((int64_t)cpu->regs[0] / (int64_t)cpu->regs[20]) : 0);
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_LT) goto L_20b7f0;
    cpu->regs[19] = cpu->regs[20] * cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20b774ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdc8acULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20b740;
    cpu->regs[3] = cpu->regs[0] + 24ULL;
    FLAG_CMP(cpu->regs[23], 1ULL);
    if (FLAG_NE) goto L_20b804;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20b79c;
    cpu->regs[0] = cpu->regs[19] + cpu->regs[0];
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
L_20b79c:
    cpu->regs[1] = cpu->regs[3] + (cpu->regs[19] << 3);
    goto L_20b7a8;
L_20b7a4:
    PB_STR(cpu->regs[3], cpu->regs[2]); cpu->regs[3] += 8;
L_20b7a8:
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_LO) goto L_20b7a4;
L_20b7b0:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x20b7b8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_20b740;
L_20b7bc:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2640));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_20b714;
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_20b7e0;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_20b7e0:
    cpu->regs[22] = cpu->regs[21];
    goto L_20b740;
L_20b7e8:
    PB_STRW((cpu->regs[1] + 10000), cpu->regs[0]);
    goto L_20b738;
L_20b7f0:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_20b804:
    cpu->regs[0] = cpu->regs[21] + 24ULL;
    cpu->regs[2] = cpu->regs[23] << 3;
    cpu->regs[23] = cpu->regs[0] + (cpu->regs[23] << 3);
    cpu->regs[0] = 24ULL;
L_20b814:
    cpu->regs[1] = cpu->regs[21] + cpu->regs[0];
    FLAG_CMP(cpu->regs[23], cpu->regs[1]);
    if (FLAG_LS) goto L_20b840;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + cpu->regs[0]));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    cpu->regs[5] = cpu->regs[20] + cpu->regs[4];
    if (((cpu->regs[4] >> 31) & 1)) goto L_20b834;
    PB_STR((cpu->regs[1] + 0), cpu->regs[5]);
L_20b834:
    PB_STR((cpu->regs[22] + cpu->regs[0]), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    goto L_20b814;
L_20b840:
    cpu->regs[1] = cpu->regs[19] << 3;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x20b84cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x22b2c0ULL);
    goto L_20b7b0;
    SP = SP - 64ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3344));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20b894ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7bf20ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_HI) goto L_20b968;
L_20b8a0:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_20b8bc;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0x20b8b0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20b95c;
L_20b8bc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = SP;
    cpu->regs[1] = 21523ULL;
    cpu->regs[30] = PB_BASE + 0x20b8ccULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7abb0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_20b91c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x20b8e0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_20b8e0:
    cpu->regs[19] = 0ULL;
L_20b8e4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_20b918;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_20b918:
    cpu->regs[30] = PB_BASE + 0x20b91cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_20b91c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    PB_LDRH(cpu->regs[21], (SP + 2));
    PB_LDRH(cpu->regs[20], (SP + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    cpu->regs[30] = PB_BASE + 0x20b930ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe51acULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20b8e0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20b940ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe2620ULL);
    if ((cpu->regs[0])==0) goto L_20b988;
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20b950ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe2620ULL);
    if ((cpu->regs[0])==0) goto L_20b988;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    goto L_20b8e4;
L_20b95c:
    cpu->regs[30] = PB_BASE + 0x20b960ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_20b8bc;
    goto L_20b8e0;
L_20b968:
    cpu->regs[0] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 808ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20b980ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20b8a0;
    goto L_20b8e0;
L_20b988:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20b8e0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_20b8e0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20b9a4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20b8e0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x20b9c4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x20b9ccULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20b9d8ULL; PB_CALL(25, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20b9ec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20b9f8;
L_20b9ec:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20b9f8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 2064ULL;
    { PB_CALL(27, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
    /* nop */
    /* nop */
    /* nop */
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 16));
    if ((cpu->regs[21])==0) goto L_20ba54;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_NE) goto L_20ba74;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    { PB_CALL(28, cpu, tlb, PB_BASE + 0x16b460ULL); return; };
L_20ba54:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[1] = cpu->regs[1] + 3208ULL;
    { PB_CALL(29, cpu, tlb, PB_BASE + 0x16b460ULL); return; };
L_20ba74:
    cpu->regs[22] = 0ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 88), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x20ba90ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20bb0c;
    PB_LDR(cpu->regs[1], (SP + 88));
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2760));
    cpu->regs[19] = cpu->regs[1] + 24ULL;
    cpu->regs[25] = cpu->regs[0] + 24ULL;
L_20bab0:
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[20];
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_GE) goto L_20bad8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + (cpu->regs[22] << 3)));
    cpu->regs[30] = PB_BASE + 0x20bac8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x16b460ULL);
    if ((cpu->regs[0])==0) goto L_20baf4;
    PB_STR((cpu->regs[25] + (cpu->regs[22] << 3)), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_20bab0;
L_20bad8:
    PB_LDR(cpu->regs[25], (SP + 64));
L_20badc:
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_20baf4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20bb08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20bb14;
L_20bb08:
    PB_LDR(cpu->regs[25], (SP + 64));
L_20bb0c:
    cpu->regs[23] = 0ULL;
    goto L_20badc;
L_20bb14:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[23] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20bb20ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_20badc;
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[3];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 24), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])!=0) goto L_20bcbc;
    if (((cpu->regs[2] >> 63) & 1)) goto L_20bc84;
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[20] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_20bcc4;
L_20bb74:
    if ((cpu->regs[20])!=0) goto L_20bcb4;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_20bb80:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x20bb8cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20bc7c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_LE) goto L_20bc20;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x20bbb0ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x16b4b0ULL);
    if ((cpu->regs[0])==0) goto L_20bc60;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    PB_STR((cpu->regs[20] + 24), cpu->regs[0]);
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_LE) goto L_20bc20;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x20bbd4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x16b4b0ULL);
    if ((cpu->regs[0])==0) goto L_20bc60;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_LE) goto L_20bc20;
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[20] + 16ULL;
    cpu->regs[21] = 3ULL;
L_20bbf4:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20bc04ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x16b4b0ULL);
    if ((cpu->regs[0])==0) goto L_20bc5c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    PB_STR((cpu->regs[23] + (cpu->regs[21] << 3)), cpu->regs[0]);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_LT) goto L_20bbf4;
    PB_LDR(cpu->regs[23], (SP + 80));
L_20bc20:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_20bc54;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_20bc54:
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x20bc5cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7c170ULL);
L_20bc5c:
    PB_LDR(cpu->regs[23], (SP + 80));
L_20bc60:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20bc7c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_20bc7c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20bc7cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_20bc7c:
    cpu->regs[20] = 0ULL;
    goto L_20bc20;
L_20bc84:
    cpu->regs[1] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[4] = cpu->regs[4] + 336ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20bcb0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_20bc7c;
L_20bcb4:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0));
    goto L_20bb80;
L_20bcbc:
    PB_LDR(cpu->regs[20], (cpu->regs[3] + 16));
    cpu->regs[20] = cpu->regs[2] + cpu->regs[20];
L_20bcc4:
    cpu->regs[3] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = cpu->regs[4] + 336ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 1ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20bcf4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])!=0) goto L_20bb74;
    cpu->regs[20] = 0ULL;
    goto L_20bc20;
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[6] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[4];
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20bd1c;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[5];
    { PB_CALL(41, cpu, tlb, PB_BASE + 0x134b80ULL); return; };
L_20bd1c:
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 8));
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2392));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_20bd54;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    FLAG_CMP(cpu->regs[4], cpu->regs[0]);
    if (FLAG_NE) goto L_20bd54;
    PB_LDRW(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_20bd60;
L_20bd4c:
    cpu->regs[0] = cpu->regs[5];
    return;
L_20bd54:
    cpu->regs[1] = cpu->regs[2] - cpu->regs[3];
    cpu->regs[0] = cpu->regs[6] + cpu->regs[3];
    { PB_CALL(42, cpu, tlb, PB_BASE + 0xe9c70ULL); return; };
L_20bd60:
    PB_STRW((cpu->regs[5] + 0), cpu->regs[0]);
    goto L_20bd4c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x20bd80ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    if ((cpu->regs[0])==0) goto L_20bd94;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_20bdc8;
L_20bd94:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2680));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x20bda8ULL; PB_CALL(44, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20bdbc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20bddc;
L_20bdbc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20bdc8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_20bd94;
    cpu->regs[30] = PB_BASE + 0x20bdd8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20bd94;
L_20bddc:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x20be04ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_20be70;
L_20be10:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x20be18ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x20be20ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[30] = PB_BASE + 0x20be28ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x20be30ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20be38ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1ef630ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20be40ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x13f6ecULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0x20be50ULL; PB_CALL(54, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20be64;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20be84;
L_20be64:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20be70:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_20be10;
    cpu->regs[30] = PB_BASE + 0x20be80ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20be10;
L_20be84:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    /* nop */
    /* nop */
    /* nop */
L_20bea0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x20beacULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x11d2a0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_20becc;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[0] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20becc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20bed8;
L_20becc:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_20bed8:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x20bee0ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20becc;
    goto L_20bea0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x20bf00ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_20bf50;
L_20bf0c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x20bf14ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x20bf1cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[30] = PB_BASE + 0x20bf24ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x20bf2cULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0x20bf3cULL; PB_CALL(64, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_20bf64;
L_20bf44:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20bf50:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_20bf0c;
    cpu->regs[30] = PB_BASE + 0x20bf60ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20bf0c;
L_20bf64:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_20bf44;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[2] = 18446744073709551615ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_HI) goto L_20c244;
L_20bfc4:
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_GT) goto L_20c1fc;
L_20bfcc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    PB_STR((SP + 8), 0ULL);
    PB_LDR(cpu->regs[20], (SP + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_20c1a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 20));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20c1dc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 192));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 120));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_20c1c0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    if ((cpu->regs[0])==0) goto L_20c110;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 16));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20c140;
L_20c00c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])==0) goto L_20c268;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20c01cULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x157930ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20c158;
    if (!((cpu->regs[20] >> 63) & 1)) goto L_20c214;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[5] = 54664ULL;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[5];
    PB_STR((SP + 16), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x20c050ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20c228;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 192));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_20c160;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x20c07cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x158168ULL);
    cpu->regs[21] = cpu->regs[0];
L_20c080:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_20c09c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_20c09c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20c09cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_20c09c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20c0a4ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x1e6660ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20c228;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x20c0b8ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x20c8a4ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20c2bc;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x20c0ccULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x20c928ULL);
    PB_LDR(cpu->regs[20], (SP + 8));
    if ((cpu->regs[20])==0) goto L_20c228;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    if ((cpu->regs[0])!=0) goto L_20c284;
L_20c0dc:
    cpu->regs[0] = cpu->regs[20];
L_20c0e0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_20c184;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_20c110:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20c11cULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x1e6ba0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20c158;
    cpu->regs[30] = PB_BASE + 0x20c128ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_20c188;
L_20c134:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_20c158;
    if (FLAG_EQ) goto L_20c00c;
L_20c140:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3800ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x20c158ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_20c158:
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c160:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3664));
    cpu->regs[4] = 41344ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20c17cULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x13bfa0ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_20c080;
L_20c184:
    cpu->regs[30] = PB_BASE + 0x20c188ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x7c170ULL);
L_20c188:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_20c134;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20c19cULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20c134;
L_20c1a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x20c1b8ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c1c0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20c1d0ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x93a2cULL);
    if ((cpu->regs[0])!=0) goto L_20c00c;
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c1dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x20c1f4ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c1fc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x20c208ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x155680ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20bfcc;
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c214:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20c220ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x20c8a4ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_20c2e0;
L_20c228:
    cpu->regs[21] = 0ULL;
L_20c22c:
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x20c234ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20c23cULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c244:
    cpu->regs[0] = PB_BASE + 0x2ac000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 520ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20c25cULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20bfc4;
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c268:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 192));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2896ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x20c27cULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c284:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    PB_STR((cpu->regs[19] + 120), 0ULL);
    cpu->regs[30] = PB_BASE + 0x20c290ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((cpu->regs[19] + 128), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    if ((cpu->regs[0])==0) goto L_20c2b4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 152), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20c2b4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_20c3bc;
L_20c2b4:
    PB_LDR(cpu->regs[20], (SP + 8));
    goto L_20c0dc;
L_20c2bc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20c158;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_20c158;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20c2d8ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_20c0e0;
L_20c2e0:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    cpu->regs[21] = 0ULL;
    cpu->regs[22] = cpu->regs[20] - cpu->regs[22];
L_20c2ec:
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_20c354;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20c300ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x1e50e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_20c3c8;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_20c354;
    if ((cpu->regs[21])==0) goto L_20c3d4;
L_20c310:
    PB_LDR(cpu->regs[20], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_20c3e8;
L_20c320:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20c334;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20c400;
L_20c334:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20c340ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x20c8a4ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20c22c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[22] = cpu->regs[22] - cpu->regs[0];
    goto L_20c2ec;
L_20c354:
    PB_LDR(cpu->regs[20], (SP + 8));
    if ((cpu->regs[21])==0) goto L_20c0dc;
    if ((cpu->regs[20])==0) goto L_20c374;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20c36cULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xe548cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_20c22c;
    PB_LDR(cpu->regs[20], (SP + 8));
L_20c374:
    cpu->regs[2] = 24464ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x20c38cULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x144c60ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x20c39cULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[20], (SP + 8));
    if ((cpu->regs[20])==0) goto L_20c22c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20c0dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_20c0dc;
    cpu->regs[0] = cpu->regs[21];
L_20c3bc:
    cpu->regs[30] = PB_BASE + 0x20c3c0ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[20], (SP + 8));
    goto L_20c0dc;
L_20c3c8:
    cpu->regs[30] = PB_BASE + 0x20c3ccULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x217af0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20c2ec;
    goto L_20c22c;
L_20c3d4:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20c3dcULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_20c310;
    goto L_20c228;
L_20c3e8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20c3f4ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xe548cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_20c22c;
    PB_LDR(cpu->regs[20], (SP + 8));
    goto L_20c320;
L_20c400:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20c408ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20c334;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x20c420ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x1cc470ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20c444;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_20c434;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_20c434:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20c444:
    cpu->regs[19] = 0ULL;
    goto L_20c434;
    SP = SP - 96ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = 9223372036854775807ULL;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    PB_STR((SP + 8), cpu->regs[20]); PB_STR((SP + 8) + 8, 0ULL);
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_HI) goto L_20c5dc;
    PB_LDR(cpu->regs[24], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_EQ) goto L_20c5b0;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x20c4b0ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x22bab0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_20c54c;
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_EQ) goto L_20c4cc;
L_20c4bc:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[1] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0x20c4c8ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x22bab0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_20c54c;
L_20c4cc:
    PB_LDR(cpu->regs[20], (SP + 8)); PB_LDR(cpu->regs[19], (SP + 8) + 8);
    if (((cpu->regs[19] >> 63) & 1)) goto L_20c590;
    if (((cpu->regs[20] >> 63) & 1)) goto L_20c5a0;
L_20c4d8:
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_GE) goto L_20c530;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_GE) goto L_20c530;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + (cpu->regs[19] << 3)));
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_20c5d0;
L_20c500:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x20c510ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[23] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_20c5b8;
L_20c51c:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_20c584;
    if (FLAG_NE) goto L_20c54c;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_20c4d8;
L_20c530:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[1] + 912ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x20c54cULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x11f220ULL);
L_20c54c:
    cpu->regs[0] = 0ULL;
L_20c550:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_20c5d8;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
L_20c584:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20c58cULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xe1fc0ULL);
    goto L_20c550;
L_20c590:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] & ~(((uint64_t)((int64_t)cpu->regs[19] >> 63)));
    if (!((cpu->regs[20] >> 63) & 1)) goto L_20c4d8;
L_20c5a0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[20] = cpu->regs[20] & ~(((uint64_t)((int64_t)cpu->regs[20] >> 63)));
    goto L_20c4d8;
L_20c5b0:
    cpu->regs[19] = 0ULL;
    goto L_20c4d8;
L_20c5b8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_20c51c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x20c5ccULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20c51c;
L_20c5d0:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_20c500;
L_20c5d8:
    cpu->regs[30] = PB_BASE + 0x20c5dcULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x7c170ULL);
L_20c5dc:
    cpu->regs[0] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1232ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x20c5f4ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_20c54c;
    PB_LDR(cpu->regs[24], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_LE) goto L_20c4cc;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x20c610ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x22bab0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_20c4bc;
    goto L_20c54c;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x20c638ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[30] = PB_BASE + 0x20c63cULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x20c680ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20c644ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_20c658;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_20c664;
L_20c658:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20c664:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(114, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    /* nop */
    /* nop */
    /* nop */
L_20c680:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[1])!=0) goto L_20c6cc;
L_20c698:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_20c6bc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_20c6bc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_20c6bc;
    cpu->regs[30] = PB_BASE + 0x20c6bcULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_20c6bc:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20c6cc:
    cpu->regs[30] = PB_BASE + 0x20c6d0ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_20c698;
    /* nop */
    /* nop */
    /* nop */
    SP = SP - 112ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[3];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[6], (cpu->regs[5] + 0));
    PB_STR((SP + 40), cpu->regs[6]);
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = cpu->regs[2];
    if ((cpu->regs[4])!=0) goto L_20c810;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_LE) goto L_20c79c;
    FLAG_CMP(cpu->regs[2], 0ULL);
    cpu->regs[21] = cpu->regs[3];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], 3ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_20c818;
L_20c738:
    PB_LDR(cpu->regs[23], (cpu->regs[5] + 0)); PB_LDR(cpu->regs[24], (cpu->regs[5] + 0) + 8);
    cpu->regs[22] = 0ULL;
    FLAG_CMP(cpu->regs[21], 2ULL);
    if (FLAG_NE) goto L_20c7d8;
L_20c748:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x20c750ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x15e540ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_20c86c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    SP = SP + 112ULL;
    { PB_CALL(118, cpu, tlb, PB_BASE + 0x20c94cULL); return; };
L_20c79c:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[4] = cpu->regs[4] + 272ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[4] = cpu->regs[4] + 408ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x20c7ccULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20c850;
    PB_LDR(cpu->regs[23], (cpu->regs[5] + 0)); PB_LDR(cpu->regs[24], (cpu->regs[5] + 0) + 8);
L_20c7d8:
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    cpu->regs[30] = PB_BASE + 0x20c7e0ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_20c800;
    cpu->regs[30] = PB_BASE + 0x20c7ecULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_20c88c;
L_20c7f8:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_20c748;
L_20c800:
    cpu->regs[30] = PB_BASE + 0x20c804ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_20c850;
    cpu->regs[22] = 18446744073709551615ULL;
    goto L_20c748;
L_20c810:
    PB_LDR(cpu->regs[21], (cpu->regs[4] + 16));
    cpu->regs[21] = cpu->regs[3] + cpu->regs[21];
L_20c818:
    cpu->regs[0] = SP + 16ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[6] = PB_BASE + 0x521000ULL;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[6] = cpu->regs[6] + 272ULL;
    cpu->regs[5] = 2ULL;
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[7] = 0ULL;
    cpu->regs[4] = cpu->regs[6] + 408ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x20c848ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_20c738;
L_20c850:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_20c870;
L_20c86c:
    cpu->regs[30] = PB_BASE + 0x20c870ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x7c170ULL);
L_20c870:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_20c88c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_20c7f8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x20c8a0ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_20c7f8;
L_20c8a4:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 120));
    if ((cpu->regs[0])!=0) goto L_20c8c8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(126, cpu, tlb, PB_BASE + 0x18e5c0ULL); return; };
L_20c8c8:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[1], 0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 128));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1];
    if (FLAG_GE) { FLAG_CMP(cpu->regs[2], cpu->regs[20]); } else { FLAG_CMP(0, 1); }
    cpu->regs[20] = (FLAG_GE) ? cpu->regs[20] : cpu->regs[2];
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) { FLAG_CMP(cpu->regs[20], cpu->regs[2]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GE) goto L_20c914;
    cpu->regs[2] = cpu->regs[1] + cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20c8f8ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x134b80ULL);
    if ((cpu->regs[0])==0) goto L_20c908;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 128));
L_20c900:
    cpu->regs[1] = cpu->regs[1] + cpu->regs[20];
    PB_STR((cpu->regs[19] + 128), cpu->regs[1]);
L_20c908:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_20c914:
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_20c900;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
    goto L_20c900;
}
