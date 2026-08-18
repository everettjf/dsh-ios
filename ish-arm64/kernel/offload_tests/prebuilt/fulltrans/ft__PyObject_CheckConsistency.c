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

void ft__PyObject_CheckConsistency(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xc7790ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x88eccULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c77c0;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = PB_BASE + 0x2a7000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1592ULL;
    cpu->regs[3] = cpu->regs[3] + 3944ULL;
    cpu->regs[2] = cpu->regs[2] + 24ULL;
    cpu->regs[4] = 41ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc77c0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c77c0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_c77f8;
    cpu->regs[5] = PB_BASE + 0x2b9000ULL;
    cpu->regs[5] = cpu->regs[5] + 2352ULL;
    cpu->regs[3] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = PB_BASE + 0x2a7000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[5] + 1592ULL;
    cpu->regs[3] = cpu->regs[3] + 3944ULL;
    cpu->regs[2] = cpu->regs[2] + 48ULL;
    cpu->regs[4] = 42ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc77f8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x924f8ULL);
L_c77f8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0xc7800ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xc758cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_c781c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc7818ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x92658ULL);
    goto L_c782c;
L_c781c:
    if (!((cpu->regs[0] >> 29) & 1)) goto L_c782c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc782cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x92adcULL);
L_c782c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3080));
    cpu->regs[30] = PB_BASE + 0xc7870ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1cef60ULL);
    if ((cpu->regs[0])==0) goto L_c78f0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 1112));
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc7884ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c78f0;
    PB_LDR(cpu->regs[2], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    if ((cpu->regs[2])==0) goto L_c78c4;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[3]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_NE) goto L_c7904;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x2a7000ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 88ULL;
    SP = SP + 48ULL;
    { PB_CALL(9, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
L_c78c4:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_c7904;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[0] + 3480ULL;
    SP = SP + 48ULL;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0xe3f40ULL); return; };
L_c78f0:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_c7908;
L_c7904:
    cpu->regs[30] = PB_BASE + 0xc7908ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c7908:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 112ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xc795cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1cef60ULL);
    if ((cpu->regs[0])==0) goto L_c7afc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 1152));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[30] = PB_BASE + 0xc796cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c79d4;
    cpu->regs[30] = PB_BASE + 0xc7978ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1fd1e8ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c79d4;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 16));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_GE) goto L_c79dc;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xc79a4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1ab164ULL);
    FLAG_CMP(cpu->regs[19], 1ULL);
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[4] = PB_BASE + 0x292000ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[4] = cpu->regs[4] + 1000ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[4] = (FLAG_NE) ? cpu->regs[4] : cpu->regs[1];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 96ULL;
    cpu->regs[30] = PB_BASE + 0xc79d4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11f220ULL);
L_c79d4:
    cpu->regs[19] = 4294967295ULL;
    goto L_c7af0;
L_c79dc:
    cpu->regs[1] = 0ULL;
    cpu->regs[19] = 0ULL;
L_c79e4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 16));
    PB_STR((SP + 16), cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LE) goto L_c7a4c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc79fcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x14d028ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c79d4;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[23] + (cpu->regs[2] << 3);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0xc7a1cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe28a0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c7a3c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c7a3c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xc7a3cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c7a3c:
    if (((cpu->regs[19] >> 31) & 1)) goto L_c7af0;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    goto L_c79e4;
L_c7a4c:
    if ((cpu->regs[24])==0) goto L_c7af0;
    cpu->regs[26] = SP;
    cpu->regs[25] = SP + 8ULL;
    cpu->regs[22] = SP + 16ULL;
    PB_STR((SP + 16), 0ULL);
L_c7a60:
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0xc7a74ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c7af0;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc7a84ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x11e710ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c79d4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_c7adc;
    PB_LDR(cpu->regs[1], (SP + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc7aa0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x276ec0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c79d4;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_c7adc;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 160ULL;
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[30] = PB_BASE + 0xc7ad8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c79d4;
L_c7adc:
    PB_LDR(cpu->regs[2], (SP + 0)); PB_LDR(cpu->regs[1], (SP + 0) + 8);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc7ae8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe28a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_c7a60;
L_c7af0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xc7af8ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_c7b00;
L_c7afc:
    cpu->regs[19] = 4294967295ULL;
L_c7b00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_c7b20;
    cpu->regs[30] = PB_BASE + 0xc7b20ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c7b20:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
}
