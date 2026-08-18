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

void ft__Py_DisplaySourceLine(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[6] = cpu->regs[4];
    cpu->regs[7] = cpu->regs[5];
    cpu->regs[4] = 0ULL;
    cpu->regs[5] = 0ULL;
    goto L_7c634;
L_7c634:
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[13] = 4240ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    SP = SP - cpu->regs[13];
    PB_STR((SP + 1024), 0ULL);
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3080));
    PB_LDR(cpu->regs[9], (cpu->regs[8] + 0));
    PB_STR((SP + 4232), cpu->regs[9]);
    cpu->regs[9] = 0ULL;
    PB_STRW((SP + 20), cpu->regs[3]);
    PB_STR((SP + 24), cpu->regs[6]); PB_STR((SP + 24) + 8, cpu->regs[7]);
    PB_STRW((SP + 64), cpu->regs[2]); PB_STRW((SP + 64) + 4, cpu->regs[4]);
    PB_STR((SP + 72), cpu->regs[5]);
    if ((cpu->regs[1])==0) goto L_7cd2c;
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7c698ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x122a60ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(60ULL)));
    if (FLAG_NE) goto L_7c6c0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_7c6c0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7c6b8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x122a60ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(62ULL)));
    if (FLAG_EQ) goto L_7cd2c;
L_7c6c0:
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2944ULL;
    cpu->regs[30] = PB_BASE + 0x7c6ccULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1c7c60ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7c6dc;
L_7c6d4:
    cpu->regs[0] = 4294967295ULL;
    goto L_7cd54;
L_7c6dc:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[8] = 52648ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[3] = cpu->regs[21];
    cpu->regs[4] = cpu->regs[1] + 2704ULL;
    cpu->regs[2] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[8];
    cpu->regs[2] = cpu->regs[2] + 320ULL;
    cpu->regs[30] = PB_BASE + 0x7c704ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d604cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7c97c;
    cpu->regs[30] = PB_BASE + 0x7c710ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7c718ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1c85e0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7c728;
    cpu->regs[30] = PB_BASE + 0x7c724ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_7c95c;
L_7c728:
    cpu->regs[28] = cpu->regs[0] + 32ULL;
    cpu->regs[1] = 47ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x7c738ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7b140ULL);
    if ((cpu->regs[0])==0) goto L_7c740;
    cpu->regs[28] = cpu->regs[0] + 1ULL;
L_7c740:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x7c748ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[7] = 53360ULL;
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x7c764ULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = SP + 120ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[24] + cpu->regs[7];
    cpu->regs[30] = PB_BASE + 0x7c778ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1e3100ULL);
    PB_LDR(cpu->regs[25], (SP + 120));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7c78c;
    cpu->regs[30] = PB_BASE + 0x7c788ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_7c928;
L_7c78c:
    if ((cpu->regs[25])==0) goto L_7c928;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 25) & 1)) goto L_7c928;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7c7a4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1b0088ULL);
    cpu->regs[6] = 52648ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[6];
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7c7b8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xed3ccULL);
    PB_STR((SP + 0), cpu->regs[0]); PB_STR((SP + 0) + 8, cpu->regs[20]);
    cpu->regs[1] = cpu->regs[26] + 1ULL;
    cpu->regs[0] = SP + 127ULL;
    cpu->regs[26] = SP + 128ULL;
    cpu->regs[27] = 0ULL;
    PB_STR((SP + 40), cpu->regs[19]);
    PB_STR((SP + 96), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x291000ULL;
    cpu->regs[0] = cpu->regs[0] + 1720ULL;
    PB_STR((SP + 80), cpu->regs[1]); PB_STR((SP + 80) + 8, cpu->regs[0]);
L_7c7e0:
    PB_LDR(cpu->regs[0], (SP + 56));
    FLAG_CMP(cpu->regs[0], cpu->regs[27]);
    if (FLAG_LE) goto L_7c91c;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7c7f8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1c4a00ULL);
    if ((cpu->regs[0])!=0) goto L_7c80c;
    PB_LDR(cpu->regs[20], (SP + 8));
    PB_LDR(cpu->regs[19], (SP + 40));
    cpu->regs[30] = PB_BASE + 0x7c808ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_7c92c;
L_7c80c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_7c914;
    cpu->regs[30] = PB_BASE + 0x7c81cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1c85e0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7c82c;
L_7c824:
    cpu->regs[30] = PB_BASE + 0x7c828ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_7c914;
L_7c82c:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (SP + 80));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[19];
    FLAG_CMP(cpu->regs[1], 4095ULL);
    if (FLAG_LE) goto L_7c85c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7c914;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7c914;
    cpu->regs[30] = PB_BASE + 0x7c858ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7c914;
L_7c85c:
    cpu->regs[1] = cpu->regs[0] + 32ULL;
    PB_STR((SP + 104), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x7c86cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[1], (SP + 104));
    cpu->regs[4] = 4097ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_LS) goto L_7c884;
    __builtin_trap();
L_7c884:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x7c88cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7b130ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7c8a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7c8a8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7c8a8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7c8a8:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x7c8b0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_7c914;
    if ((cpu->regs[19])==0) goto L_7c8dc;
    PB_LDR(cpu->regs[0], (SP + 96));
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + cpu->regs[19]));
    cpu->regs[0] = cpu->regs[26] + cpu->regs[19];
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(47ULL)));
    if (FLAG_EQ) goto L_7c8dc;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    cpu->regs[1] = 47ULL;
    PB_STRB((cpu->regs[0] + 0), cpu->regs[1]);
L_7c8dc:
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[26] + cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7c8e8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7b130ULL);
    cpu->regs[0] = PB_BASE + 0x28e000ULL;
    cpu->regs[4] = cpu->regs[0] + 2704ULL;
    PB_LDR(cpu->regs[1], (SP + 0));
    cpu->regs[3] = cpu->regs[26];
    PB_LDR(cpu->regs[0], (SP + 48));
    PB_LDR(cpu->regs[2], (SP + 88));
    cpu->regs[30] = PB_BASE + 0x7c904ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xb0700ULL);
    if ((cpu->regs[0])==0) goto L_7c824;
    PB_LDR(cpu->regs[20], (SP + 8));
    cpu->regs[19] = cpu->regs[0];
    goto L_7c92c;
L_7c914:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    goto L_7c7e0;
L_7c91c:
    PB_LDR(cpu->regs[20], (SP + 8));
    PB_LDR(cpu->regs[19], (SP + 40));
    goto L_7c92c;
L_7c928:
    PB_STR((SP + 0), 0ULL);
L_7c92c:
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x7c934ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x7c93cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7c958;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7c958;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7c958ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7c958:
    if ((cpu->regs[19])!=0) goto L_7c97c;
L_7c95c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7c6d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7c6d4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7c978ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7c6d4;
L_7c97c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7c984ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1e42c0ULL);
    cpu->regs[22] = cpu->regs[0];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_7c9c0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7c9a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7c9a8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7c9a8ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7c9a8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7cd2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7cd2c;
    goto L_7cd24;
L_7c9c0:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7c9c8ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1e4544ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_7c9e0;
    cpu->regs[25] = PB_BASE + 0x283000ULL;
    cpu->regs[30] = PB_BASE + 0x7c9d8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[25] = cpu->regs[25] + 1576ULL;
    goto L_7c9e4;
L_7c9e0:
    cpu->regs[25] = cpu->regs[0];
L_7c9e4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7c9f4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7ae10ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_7ca40;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7ca18;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7ca18;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7ca18ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7ca18:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7ca34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7ca34;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7ca34ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7ca34:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7ca3cULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_7cd2c;
L_7ca40:
    cpu->regs[5] = 25208ULL;
    cpu->regs[0] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[5];
    cpu->regs[2] = cpu->regs[0] + 320ULL;
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7ca60ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1d604cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_7ca80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7ca80;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7ca80ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7ca80:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7ca88ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    if ((cpu->regs[22])!=0) goto L_7caf8;
    cpu->regs[30] = PB_BASE + 0x7ca90ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_STR((SP + 120), cpu->regs[19]);
    cpu->regs[1] = 39328ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[1];
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[1] = SP + 120ULL;
    cpu->regs[30] = PB_BASE + 0x7caacULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x147564ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_7cacc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7cacc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7caccULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7cacc:
    if ((cpu->regs[20])==0) goto L_7caf0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7cd2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7cd2c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x7caecULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7cd2c;
L_7caf0:
    cpu->regs[30] = PB_BASE + 0x7caf4ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_7cd2c;
L_7caf8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7cb14;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7cb14;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7cb14ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7cb14:
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
L_7cb20:
    PB_LDRW(cpu->regs[1], (SP + 64));
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_GE) goto L_7cb54;
    cpu->regs[30] = PB_BASE + 0x7cb30ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x7cb3cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1e4cd0ULL);
    if ((cpu->regs[0])!=0) goto L_7cb4c;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x7cb48ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_7cb58;
L_7cb4c:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    goto L_7cb20;
L_7cb54:
    cpu->regs[19] = cpu->regs[0];
L_7cb58:
    cpu->regs[0] = 39328ULL;
    cpu->regs[1] = SP + 120ULL;
    cpu->regs[0] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 120), cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x7cb74ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_7cb94;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7cb98;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7cb98;
    cpu->regs[30] = PB_BASE + 0x7cb90ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7cb98;
L_7cb94:
    cpu->regs[30] = PB_BASE + 0x7cb98ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_7cb98:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7cbb4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7cbb4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x7cbb4ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7cbb4:
    if ((cpu->regs[19])==0) goto L_7cbc4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_7cbd0;
L_7cbc4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7cbccULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_7c6d4;
L_7cbd0:
    PB_LDR(cpu->regs[0], (SP + 32));
    if ((cpu->regs[0])==0) goto L_7cbf0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_7cbe8;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_7cbe8:
    PB_LDR(cpu->regs[0], (SP + 32));
    PB_STR((cpu->regs[0] + 0), cpu->regs[19]);
L_7cbf0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[21] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_7cc10;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[22] = cpu->regs[19] + 56ULL;
    cpu->regs[0] = cpu->regs[19] + 40ULL;
    cpu->regs[22] = (FLAG_EQ) ? cpu->regs[22] : cpu->regs[0];
    goto L_7cc14;
L_7cc10:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 56));
L_7cc14:
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[19] + 16));
L_7cc1c:
    cpu->regs[24] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    FLAG_CMP(cpu->regs[25], cpu->regs[20]);
    if (FLAG_LE) goto L_7cc54;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x7cc38ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1e78e4ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 9ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_7cc4c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(12ULL)));
    if (FLAG_NE) goto L_7cc54;
L_7cc4c:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    goto L_7cc1c;
L_7cc54:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_7cc9c;
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7cc68ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x134b80ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_7cc98;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_7cc84;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_7cc8c;
L_7cc84:
    cpu->regs[19] = cpu->regs[21];
    goto L_7cc9c;
L_7cc8c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7cc94ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7cc84;
L_7cc98:
    cpu->regs[30] = PB_BASE + 0x7cc9cULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_7cc9c:
    PB_LDR(cpu->regs[0], (SP + 24));
    if ((cpu->regs[0])==0) goto L_7ccb4;
    PB_LDRW(cpu->regs[0], (SP + 20));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] - cpu->regs[0]));
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_STRW((cpu->regs[0] + 0), cpu->regs[20]);
L_7ccb4:
    PB_LDR(cpu->regs[1], (SP + 72));
    cpu->regs[2] = cpu->regs[23];
    PB_LDRW(cpu->regs[0], (SP + 68));
    cpu->regs[30] = PB_BASE + 0x7ccc4ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1e7c40ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7cd34;
    PB_LDRW(cpu->regs[0], (SP + 20));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x7ccd8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1e7d30ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7cd34;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x7ccf0ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7cd34;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x7cd08ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x1e3340ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_7cd34;
    if (((cpu->regs[1] >> 31) & 1)) goto L_7cd2c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_7cd2c;
L_7cd24:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7cd2cULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_7cd2c:
    cpu->regs[0] = 0ULL;
    goto L_7cd54;
L_7cd34:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_7c6d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_7c6d4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x7cd50ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_7c6d4;
L_7cd54:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 4232));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_7cd74;
    cpu->regs[30] = PB_BASE + 0x7cd74ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x7c170ULL);
L_7cd74:
    cpu->regs[13] = 4240ULL;
    SP = SP + cpu->regs[13];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 3ULL);
    if (FLAG_NE) goto L_7cdc8;
L_7cdb0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 8) + 8);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x7cdbcULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x7cdf4ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_7cde8;
L_7cdc8:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[0] = cpu->regs[0] + 3024ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x7cde0ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_7cdb0;
    cpu->regs[0] = 0ULL;
L_7cde8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
