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

void ft_PySlice_GetIndicesEx(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[3];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[4];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[4];
    cpu->regs[22] = cpu->regs[5];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa96b0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x146840ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a96d8;
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 0));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xa96ccULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x146b24ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
L_a96d8:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_HI) goto L_a9734;
L_a9728:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_GT) goto L_a9758;
    goto L_a98ac;
L_a9734:
    cpu->regs[0] = PB_BASE + 0x2ac000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 520ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa974cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a9728;
L_a9750:
    cpu->regs[19] = 0ULL;
    goto L_a98d4;
L_a9758:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0xa9760ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a9774;
L_a9768:
    cpu->regs[30] = PB_BASE + 0xa976cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a98ac;
    goto L_a9750;
L_a9774:
    cpu->regs[30] = PB_BASE + 0xa9778ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a9798;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a9798;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa9798ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a9798:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a9768;
    if (((cpu->regs[20] >> 63) & 1)) goto L_a98ac;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa97b0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1fc8e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a9750;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[5] = 54864ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[5];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa97d8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x13bfa0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a97f0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_a9808;
L_a97f0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a98d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a98d4;
    goto L_a98a0;
L_a9808:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xa9818ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_a9838;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_a9838;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa9838ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a9838:
    FLAG_CMP(cpu->regs[21], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9868;
    cpu->regs[30] = PB_BASE + 0xa9844ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a9868;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a9750;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a9750;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa9864ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a9750;
L_a9868:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_a9878;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    goto L_a9880;
L_a9878:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
L_a9880:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa9888ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a98d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a98d4;
L_a98a0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa98a8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a98d4;
L_a98ac:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 54816ULL;
    cpu->regs[1] = SP;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0xa98d0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[19] = cpu->regs[0];
L_a98d4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a98f4;
    cpu->regs[30] = PB_BASE + 0xa98f4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a98f4:
    PB_LDR(cpu->regs[21], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_LS) goto L_a9960;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3960ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa9944ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a9958;
L_a9948:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0xa9950ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_a996c;
L_a9958:
    cpu->regs[0] = 0ULL;
    goto L_a99b8;
L_a9960:
    if ((cpu->regs[2])!=0) goto L_a9948;
    cpu->regs[20] = 1ULL;
    goto L_a99a0;
L_a996c:
    cpu->regs[30] = PB_BASE + 0xa9970ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a9990;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a9990;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa9990ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a9990:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a99a0;
    cpu->regs[30] = PB_BASE + 0xa999cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9958;
L_a99a0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa99acULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x242940ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a9958;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a99b8:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_a9a08;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 3976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9a04ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9a24;
L_a9a08:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 24));
    cpu->regs[30] = PB_BASE + 0xa9a10ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9a2c;
    cpu->regs[30] = PB_BASE + 0xa9a20ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a9a5c;
L_a9a24:
    cpu->regs[0] = 0ULL;
    goto L_a9a64;
L_a9a2c:
    cpu->regs[0] = 2147483648ULL;
    cpu->regs[0] = cpu->regs[3] + cpu->regs[0];
    cpu->regs[1] = 4294967295ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LS) goto L_a9a5c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 4008ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9a58ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9a24;
L_a9a5c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[3]);
L_a9a64:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa9a84ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x129680ULL);
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xa9a8cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 160ULL;
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[22] = SP + 24ULL;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[25], (cpu->regs[24] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 24), 0ULL); PB_STR((SP + 24) + 8, 0ULL);
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[25];
    PB_STR((cpu->regs[22] + 16), 0ULL); PB_STR((cpu->regs[22] + 16) + 8, 0ULL);
    cpu->regs[30] = PB_BASE + 0xa9af8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdbdc0ULL);
    if ((cpu->regs[0])==0) goto L_a9d3c;
    cpu->regs[19] = PB_BASE + 0x2b8000ULL;
    cpu->regs[19] = cpu->regs[19] + 2096ULL;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] - 144ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[21] = 1ULL;
L_a9b14:
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_LE) goto L_a9bc8;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 24));
    PB_LDR(cpu->regs[27], (cpu->regs[0] + (cpu->regs[23] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_a9cb8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 16));
    FLAG_CMP(cpu->regs[0], 6ULL);
    if (FLAG_NE) goto L_a9cb8;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 24));
    cpu->regs[30] = PB_BASE + 0xa9b44ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xa9b4cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9d34;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(511ULL)));
    if (FLAG_HI) goto L_a9b68;
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[3] >> 5)));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + (cpu->regs[0] << 2)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> (cpu->regs[3] & 63)));
    if (((cpu->regs[0] >> 0) & 1)) goto L_a9b7c;
L_a9b68:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 4294967293ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(256ULL)));
    if (FLAG_EQ) goto L_a9b7c;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(257ULL)));
    if (FLAG_NE) goto L_a9bc0;
L_a9b7c:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 32));
    cpu->regs[30] = PB_BASE + 0xa9b84ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xa9b8cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9d34;
    if (((cpu->regs[3] >> 31) & 1)) goto L_a9ba0;
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    FLAG_CMP(cpu->regs[25], cpu->regs[3]);
    if (FLAG_GT) goto L_a9bbc;
L_a9ba0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 4064ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9bb8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9d34;
L_a9bbc:
    PB_STRB((cpu->regs[20] + cpu->regs[0]), cpu->regs[21]);
L_a9bc0:
    cpu->regs[23] = cpu->regs[23] + 1ULL;
    goto L_a9b14;
L_a9bc8:
    cpu->regs[23] = 0ULL;
    goto L_a9c90;
L_a9bd0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], 6ULL);
    if (FLAG_NE) goto L_a9cb8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0xa9be4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xa9becULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9d34;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(89ULL)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] - 256ULL));
    if (FLAG_GT) { FLAG_CMP(cpu->regs[0], 10ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LS) goto L_a9cec;
L_a9c00:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0xa9c08ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xa9c10ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9d34;
L_a9c14:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    cpu->regs[26] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa9c20ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[26] = ((cpu->regs[26] & ~0xffffffffULL) | ((cpu->regs[0] >> 0) & 0xffffffffULL));
    cpu->regs[30] = PB_BASE + 0xa9c28ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9d34;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0xa9c34ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[26] = ((cpu->regs[26] & ~(0xffffffffULL << 32)) | ((cpu->regs[0] & 0xffffffffULL) << 32));
    cpu->regs[30] = PB_BASE + 0xa9c3cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9d34;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    cpu->regs[28] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa9c4cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[28] = ((cpu->regs[28] & ~0xffffffffULL) | ((cpu->regs[0] >> 0) & 0xffffffffULL));
    cpu->regs[30] = PB_BASE + 0xa9c54ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9d34;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[30] = PB_BASE + 0xa9c60ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x129680ULL);
    cpu->regs[28] = ((cpu->regs[28] & ~(0xffffffffULL << 32)) | ((cpu->regs[0] & 0xffffffffULL) << 32));
    cpu->regs[30] = PB_BASE + 0xa9c68ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_a9d34;
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[4] = cpu->regs[28];
    cpu->regs[2] = cpu->regs[27];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa9c84ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x12f7d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a9d34;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
L_a9c90:
    cpu->regs[19] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[25], cpu->regs[23]);
    if (FLAG_LE) goto L_a9d08;
    PB_LDRB(cpu->regs[0], (cpu->regs[20] + cpu->regs[19]));
    if (((cpu->regs[0] >> 0) & 1)) goto L_a9cd4;
L_a9ca4:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 24));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_a9bd0;
L_a9cb8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 4040ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9cd0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9d34;
L_a9cd4:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa9ce0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1b2920ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9ca4;
    goto L_a9d34;
L_a9cec:
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] - 260ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(5ULL)));
    if (FLAG_LS) goto L_a9c00;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(266ULL)));
    if (FLAG_EQ) goto L_a9c00;
    cpu->regs[27] = 0ULL;
    goto L_a9c14;
L_a9d08:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa9d10ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa9d1cULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x137da0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a9d3c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa9d2cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1bed40ULL);
    cpu->regs[0] = 0ULL;
    goto L_a9d48;
L_a9d34:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa9d3cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_a9d3c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa9d44ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1bed40ULL);
    cpu->regs[0] = 4294967295ULL;
L_a9d48:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_a9d68;
    cpu->regs[30] = PB_BASE + 0xa9d68ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a9d68:
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa9da0ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x129680ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9db4;
    cpu->regs[30] = PB_BASE + 0xa9dacULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a9dcc;
    goto L_a9df0;
L_a9db4:
    if (((cpu->regs[0] >> 63) & 1)) goto L_a9dc8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
    goto L_a9dcc;
L_a9dc8:
    cpu->regs[0] = 0ULL;
L_a9dcc:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 16) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    cpu->regs[2] = cpu->regs[0] * cpu->regs[2] + cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((cpu->regs[19] + 16), cpu->regs[2]);
    goto L_a9df4;
L_a9df0:
    cpu->regs[0] = 0ULL;
L_a9df4:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_LS) goto L_a9e40;
    cpu->regs[0] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 2280ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa9e34ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a9e40;
L_a9e38:
    cpu->regs[0] = 0ULL;
    goto L_a9e84;
L_a9e40:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_a9e68;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0xa9e50ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9e6c;
    cpu->regs[30] = PB_BASE + 0xa9e60ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a9e6c;
    goto L_a9e38;
L_a9e68:
    cpu->regs[3] = 1ULL;
L_a9e6c:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xa9e74ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x98804ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a9e38;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a9e84:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xa9ea0ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x13ae00ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9eb8;
    cpu->regs[30] = PB_BASE + 0xa9eacULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a9ec4;
L_a9eb0:
    cpu->regs[0] = 0ULL;
    goto L_a9f18;
L_a9eb8:
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(63ULL)));
    if (FLAG_LS) goto L_a9ee0;
L_a9ec4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9edcULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9eb0;
L_a9ee0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 472ULL;
    cpu->regs[0] = cpu->regs[2] + (((cpu->regs[0]) & 0xffffffffULL) << 4);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_a9f10;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a9f18;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_a9f18;
L_a9f10:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a9f18:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xa9f34ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x13ae00ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9f4c;
    cpu->regs[30] = PB_BASE + 0xa9f40ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_a9f5c;
L_a9f44:
    cpu->regs[0] = 0ULL;
    goto L_a9fcc;
L_a9f4c:
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(63ULL)));
    if (FLAG_LS) goto L_a9f78;
L_a9f5c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa9f74ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a9f44;
L_a9f78:
    cpu->regs[30] = PB_BASE + 0xa9f7cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x7bae0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_STRW((cpu->regs[20] + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0xa9f8cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x7bf00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_a9fc4;
    if ((cpu->regs[0])==0) goto L_a9fc4;
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 4088ULL;
    cpu->regs[30] = PB_BASE + 0xa9fa8ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x7b2c0ULL);
    if ((cpu->regs[0])!=0) goto L_a9fc4;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x292000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[0] + 1000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(72, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
L_a9fc4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a9fcc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xa9fe8ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a9ffc;
    cpu->regs[30] = PB_BASE + 0xa9ff8ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa010;
L_a9ffc:
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaa004ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x7b570ULL);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = cpu->regs[0];
    { PB_CALL(76, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_aa010:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xaa02cULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x13ae00ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa04c;
    cpu->regs[30] = PB_BASE + 0xaa038ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_aa068;
L_aa04c:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP((cpu->regs[1]) & (128ULL), 0);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
L_aa068:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xaa084ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa0a0;
    cpu->regs[30] = PB_BASE + 0xaa094ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_aa0a0;
L_aa098:
    cpu->regs[0] = 0ULL;
    goto L_aa0f0;
L_aa0a0:
    cpu->regs[30] = PB_BASE + 0xaa0a4ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaa0b0ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x7bdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xaa0bcULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa0d8;
    cpu->regs[30] = PB_BASE + 0xaa0c8ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa098;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_aa0f0;
L_aa0d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
L_aa0f0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_aa12c;
L_aa114:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0xaa11cULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa158;
    goto L_aa150;
L_aa12c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xaa144ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aa114;
L_aa148:
    cpu->regs[0] = 0ULL;
    goto L_aa198;
L_aa150:
    cpu->regs[30] = PB_BASE + 0xaa154ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa148;
L_aa158:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[30] = PB_BASE + 0xaa160ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa174;
    cpu->regs[30] = PB_BASE + 0xaa170ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa148;
L_aa174:
    cpu->regs[30] = PB_BASE + 0xaa178ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[1] = ((uint32_t)(cpu->regs[20] - 1ULL));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaa188ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x9142cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xaa190ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_aa198:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xaa1b4ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa1c8;
    cpu->regs[30] = PB_BASE + 0xaa1c4ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa1f4;
L_aa1c8:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xaa1dcULL; PB_CALL(95, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[0] + 128), cpu->regs[3]);
    goto L_aa1f8;
L_aa1f4:
    cpu->regs[2] = 0ULL;
L_aa1f8:
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xaa214ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa228;
    cpu->regs[30] = PB_BASE + 0xaa224ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa254;
L_aa228:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xaa23cULL; PB_CALL(98, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[0] + 976), cpu->regs[3]);
    goto L_aa258;
L_aa254:
    cpu->regs[2] = 0ULL;
L_aa258:
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xaa288ULL; PB_CALL(99, cpu, tlb, cpu->regs[3]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[22], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 72));
    if ((cpu->regs[0])==0) goto L_aa2ec;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[30] = PB_BASE + 0xaa2a0ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xaa2a8ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x279ea0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_aa2cc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 1480ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaa2c8ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aa2f4;
L_aa2cc:
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(103, cpu, tlb, PB_BASE + 0x891ccULL); return; };
L_aa2ec:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_aa2f4:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xaa32cULL; PB_CALL(104, cpu, tlb, cpu->regs[3]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 72));
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[0])!=0) goto L_aa34c;
L_aa340:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    goto L_aa3fc;
L_aa34c:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xaa358ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[19] = cpu->regs[19] >> 1;
    cpu->regs[30] = PB_BASE + 0xaa368ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[1] = cpu->regs[2] >> 1;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LT) goto L_aa3f0;
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 0));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xaa384ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x2799b0ULL);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xaa394ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x2799b0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_NE) goto L_aa3f0;
    cpu->regs[30] = PB_BASE + 0xaa3a0ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x279ea0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_aa3c4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 1480ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaa3c0ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aa3fc;
L_aa3c4:
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 44));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_aa340;
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(111, cpu, tlb, PB_BASE + 0x891ccULL); return; };
L_aa3f0:
    cpu->regs[19] = PB_BASE + 0x451000ULL;
    cpu->regs[19] = cpu->regs[19] + 576ULL;
    cpu->regs[19] = cpu->regs[19] + 832ULL;
L_aa3fc:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0xaa428ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa43c;
    cpu->regs[30] = PB_BASE + 0xaa438ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa4cc;
L_aa43c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaa444ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x9718cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aa4a4;
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xaa45cULL; PB_CALL(115, cpu, tlb, cpu->regs[1]);
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] << (cpu->regs[19] & 63)));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[0] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 816ULL;
L_aa47c:
    PB_LDRB(cpu->regs[4], (cpu->regs[0] + cpu->regs[1]));
    FLAG_CMP((((uint32_t)(cpu->regs[4]))) & (((uint32_t)(cpu->regs[2]))), 0);
    if (FLAG_EQ) goto L_aa494;
    cpu->regs[4] = 1ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] << (cpu->regs[1] & 63)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] | cpu->regs[4]));
L_aa494:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[1], 15ULL);
    if (FLAG_NE) goto L_aa47c;
    goto L_aa4ac;
L_aa4a4:
    cpu->regs[3] = 4294967295ULL;
    goto L_aa4b4;
L_aa4ac:
    FLAG_CMP(cpu->regs[3], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa4bc;
L_aa4b4:
    cpu->regs[30] = PB_BASE + 0xaa4b8ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa4cc;
L_aa4bc:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[3]));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(117, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_aa4cc:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0xaa4f0ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa50c;
    cpu->regs[30] = PB_BASE + 0xaa500ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_aa50c;
L_aa504:
    cpu->regs[0] = 0ULL;
    goto L_aa54c;
L_aa50c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaa514ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x9718cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aa504;
    cpu->regs[30] = PB_BASE + 0xaa51cULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[19] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    cpu->regs[19] = cpu->regs[19] + (93ULL << 12);
    cpu->regs[19] = cpu->regs[19] + 1936ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_aa544;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_aa54c;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_aa54c;
L_aa544:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_aa54c:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0xaa56cULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa588;
    cpu->regs[30] = PB_BASE + 0xaa57cULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_aa588;
L_aa580:
    cpu->regs[0] = 0ULL;
    goto L_aa5cc;
L_aa588:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xaa590ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x9718cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aa580;
    cpu->regs[30] = PB_BASE + 0xaa598ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[19] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    cpu->regs[19] = cpu->regs[19] + (88ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 22424));
    if ((cpu->regs[0])==0) goto L_aa5c4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 22424), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_aa5c4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_aa5c4;
    cpu->regs[30] = PB_BASE + 0xaa5c4ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_aa5c4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_aa5cc:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xaa5e8ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_aa5fc;
    cpu->regs[30] = PB_BASE + 0xaa5f8ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_aa65c;
L_aa5fc:
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xaa610ULL; PB_CALL(129, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 48));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_aa648;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 24ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xaa644ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_aa65c;
L_aa648:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 972));
    PB_STRW((cpu->regs[1] + 972), cpu->regs[3]);
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    { PB_CALL(131, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
L_aa65c:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
