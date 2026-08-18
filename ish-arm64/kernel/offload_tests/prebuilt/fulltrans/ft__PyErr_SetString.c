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

void ft__PyErr_SetString(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_1d5980:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d59a0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdea4cULL);
    if ((cpu->regs[0])==0) goto L_1d59cc;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d59b8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x120824ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d59cc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d59dc;
L_1d59cc:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1d59dc:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->tls_ptr;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2840));
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[4];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    PB_STR((SP + 72), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1d5a38ULL; PB_CALL(4, cpu, tlb, cpu->regs[6]);
    PB_LDR(cpu->regs[23], (cpu->regs[5] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1d5a44ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x136260ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1d5b24;
    if (FLAG_EQ) goto L_1d5b38;
    PB_LDR(cpu->regs[0], (SP + 72));
    if ((cpu->regs[0])==0) goto L_1d5b64;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[22], 0ULL);
    cpu->regs[22] = (FLAG_NE) ? cpu->regs[22] : cpu->regs[1];
    FLAG_CMP(cpu->regs[21], 0ULL);
    cpu->regs[21] = (FLAG_NE) ? cpu->regs[21] : cpu->regs[1];
    FLAG_CMP(cpu->regs[20], 0ULL);
    cpu->regs[20] = (FLAG_NE) ? cpu->regs[20] : cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d5a7cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5b24;
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1d5a94ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5b08;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2744ULL;
    cpu->regs[30] = PB_BASE + 0x1d5aacULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5b08;
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 680ULL;
    cpu->regs[30] = PB_BASE + 0x1d5ac4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5b08;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[1] = SP + 72ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1d5adcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x192f90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5b08;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d5af4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x120824ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5b08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d5b58;
L_1d5b08:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5b24;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5b24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d5b24ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d5b24:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_1d5b38:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = cpu->regs[2] + 608ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1d5b54ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_1d5b24;
L_1d5b58:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d5b60ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5b08;
L_1d5b64:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = cpu->regs[2] + 648ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1d5b80ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_1d5b24;
    SP = SP - 144ULL;
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 16), cpu->regs[5]);
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[3];
    PB_STR((SP + 112), cpu->regs[25]); PB_STR((SP + 112) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[6];
    PB_STR((SP + 128), cpu->regs[27]); PB_STR((SP + 128) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[28] = cpu->regs[4];
    PB_LDR(cpu->regs[1], (cpu->regs[7] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1d5bd8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d6020ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d5eac;
    FLAG_CMP(((uint32_t)(cpu->regs[27])), ((uint32_t)(0ULL)));
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 2760));
    FLAG_CMP((((uint32_t)(cpu->regs[23]))) & (((uint32_t)(cpu->regs[0]))), 0);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    PB_STR((SP + 0), cpu->regs[7]); PB_STR((SP + 0) + 8, cpu->regs[0]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    if (FLAG_NE) goto L_1d5f04;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    cpu->regs[12] = 52648ULL;
    cpu->regs[0] = PB_BASE + 0x28e000ULL;
    cpu->regs[4] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[0] + 2704ULL;
    cpu->regs[4] = cpu->regs[4] + 696ULL;
    cpu->regs[4] = (FLAG_NE) ? cpu->regs[4] : cpu->regs[0];
    cpu->regs[6] = cpu->regs[7];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[12];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[5] = 4294967295ULL;
    cpu->regs[2] = cpu->regs[2] + 712ULL;
    cpu->regs[30] = PB_BASE + 0x1d5c48ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d604cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5ef0;
    cpu->regs[11] = 54616ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[11];
    cpu->regs[30] = PB_BASE + 0x1d5c5cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5e5c;
L_1d5c64:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1d5c6cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5f90;
    cpu->regs[10] = 51144ULL;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[10];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d5c88ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5f90;
    cpu->regs[9] = 47592ULL;
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[9];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1d5ca8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5f90;
    cpu->regs[30] = PB_BASE + 0x1d5cb4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[28] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1d5f70;
L_1d5cc0:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1d5f90;
    if ((((uint32_t)(cpu->regs[27])))==0) goto L_1d5f5c;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 3184));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1d5e48;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2192));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d5ce8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7bf20ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_1d5e48;
    cpu->regs[28] = cpu->regs[27];
L_1d5cf4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5d08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d6010;
L_1d5d08:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5d1c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d6004;
L_1d5d1c:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1d5d28ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5fd8;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x1d5d3cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1934e0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5eb8;
    cpu->regs[8] = 25208ULL;
    PB_STR((SP + 0), cpu->regs[27]);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[8];
    cpu->regs[7] = cpu->regs[28];
    cpu->regs[5] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[6] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[6] = cpu->regs[6] + 1024ULL;
    cpu->regs[2] = cpu->regs[2] + 704ULL;
    cpu->regs[30] = PB_BASE + 0x1d5d78ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d604cULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1d5d90;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1d5fcc;
L_1d5d90:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5dac;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5dac;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1d5dacULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d5dac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5dc0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1d5fc0;
L_1d5dc0:
    if ((cpu->regs[24])==0) goto L_1d5ef0;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 1632ULL;
    cpu->regs[0] = PB_BASE + 0x295000ULL;
    cpu->regs[0] = cpu->regs[0] + 2904ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d5de0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5fb4;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = 50568ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1d5dfcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5fb4;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1d5f98;
L_1d5e08:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
L_1d5e0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1d5e54;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 112)); PB_LDR(cpu->regs[26], (SP + 112) + 8);
    PB_LDR(cpu->regs[27], (SP + 128)); PB_LDR(cpu->regs[28], (SP + 128) + 8);
    SP = SP + 144ULL;
    return;
L_1d5e48:
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 3664));
    goto L_1d5cf4;
L_1d5e54:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1d5e5cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1d5e5c:
    cpu->regs[25] = 0ULL;
    cpu->regs[24] = 0ULL;
L_1d5e64:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d5e6cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1d5e74ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1d5e7cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d5e84ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1d5e94ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1d5f50;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1d5ea0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d6020ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1d5f50;
    cpu->regs[30] = PB_BASE + 0x1d5ea8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
L_1d5eac:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2760));
    goto L_1d5e0c;
L_1d5eb8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5ed4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5ed4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d5ed4ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d5ed4:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5ef0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5ef0;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1d5ef0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1d5ef0:
    cpu->regs[19] = 0ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[24] = 0ULL;
    goto L_1d5e64;
L_1d5f04:
    cpu->regs[0] = 52648ULL;
    cpu->regs[6] = cpu->regs[7];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[4] = PB_BASE + 0x292000ULL;
    cpu->regs[2] = PB_BASE + 0x292000ULL;
    cpu->regs[4] = cpu->regs[4] + 696ULL;
    cpu->regs[2] = cpu->regs[2] + 712ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d5f30ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x1d604cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1d5ef0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1d5f48;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1d5f48:
    cpu->regs[20] = cpu->regs[19];
    goto L_1d5c64;
L_1d5f50:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    cpu->regs[24] = 0ULL;
    goto L_1d5e0c;
L_1d5f5c:
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 3664));
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 3184));
    goto L_1d5cf4;
L_1d5f70:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1d5cc0;
    cpu->regs[0] = cpu->regs[28];
    PB_STRW((SP + 28), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1d5f88ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[1], (SP + 28));
    goto L_1d5cc0;
L_1d5f90:
    cpu->regs[24] = 0ULL;
    goto L_1d5e64;
L_1d5f98:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5e08;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1d5facULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    goto L_1d5e0c;
L_1d5fb4:
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
    goto L_1d5e64;
L_1d5fc0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d5fc8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5dc0;
L_1d5fcc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1d5fd4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5d90;
L_1d5fd8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1d5ef0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1d5ef0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[19] = 0ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1d6000ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5e64;
L_1d6004:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1d600cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5d1c;
L_1d6010:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1d6018ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1d5d08;
    /* nop */
}
