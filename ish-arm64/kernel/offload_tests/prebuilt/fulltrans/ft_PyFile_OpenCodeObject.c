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

void ft_PyFile_OpenCodeObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1ca5c8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 2976));
    if ((cpu->regs[2])!=0) goto L_1ca5f0;
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[1] = cpu->regs[1] + 3064ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = cpu->regs[0] + 2696ULL;
    cpu->regs[30] = PB_BASE + 0x1ca580ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1c5aa0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ca5e8;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[3] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[3] = cpu->regs[3] + 2704ULL;
    cpu->regs[1] = cpu->regs[1] + 320ULL;
    cpu->regs[30] = PB_BASE + 0x1ca5a0ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1c1960ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ca5b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ca600;
L_1ca5b8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1ca5c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 2656ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1ca5e8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1ca5e8:
    cpu->regs[20] = 0ULL;
    goto L_1ca5b8;
L_1ca5f0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[16] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2984));
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1ca600:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ca608ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ca5b8;
    SP = SP - 272ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 176), cpu->regs[29]); PB_STR((SP + 176) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 176ULL;
    PB_STR((SP + 192), cpu->regs[19]); PB_STR((SP + 192) + 8, cpu->regs[20]);
    PB_STR((SP + 208), cpu->regs[21]); PB_STR((SP + 208) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 224), cpu->regs[23]); PB_STR((SP + 224) + 8, cpu->regs[24]);
    PB_STR((SP + 240), cpu->regs[25]); PB_STR((SP + 240) + 8, cpu->regs[26]);
    PB_STR((SP + 256), cpu->regs[27]); PB_STR((SP + 256) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 168), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 72), cpu->regs[0]);
    if ((cpu->regs[3])!=0) goto L_1caa38;
    cpu->regs[23] = cpu->regs[2] - 1ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_1caf18;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[19] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 8ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_1caa44;
L_1ca668:
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 0));
    if ((cpu->regs[23])==0) goto L_1caca8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    if ((cpu->regs[0])==0) goto L_1ca9b8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1caf20;
    cpu->regs[1] = SP + 88ULL;
    cpu->regs[30] = PB_BASE + 0x1ca68cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1caa7c;
    cpu->regs[30] = PB_BASE + 0x1ca698ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 88));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1cacfc;
    cpu->regs[23] = cpu->regs[19] - 2ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_NE) goto L_1ca9c0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[19] = 1ULL;
    cpu->regs[24] = 4294967295ULL;
    PB_STR((SP + 40), 0ULL); PB_STR((SP + 40) + 8, 0ULL);
    PB_STR((SP + 56), 0ULL); PB_STR((SP + 56) + 8, cpu->regs[0]);
L_1ca6c4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ca6ccULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1cb0b0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cab8c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ca6d8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1ca00cULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1caa7c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    FLAG_CMP((cpu->regs[0]) & (402653184ULL), 0);
    if (FLAG_EQ) goto L_1cb068;
L_1ca6f0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ca6f8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[23] = 0ULL;
    cpu->regs[26] = 0ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[28] = 0ULL;
    PB_STRW((SP + 28), 0ULL); PB_STRW((SP + 28) + 4, 0ULL);
    PB_STRW((SP + 36), 0ULL);
L_1ca718:
    cpu->regs[4] = cpu->regs[28];
    FLAG_CMP(cpu->regs[22], cpu->regs[28]);
    if (FLAG_LS) goto L_1ca758;
    PB_LDRB(cpu->regs[1], (cpu->regs[20] + cpu->regs[4]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(114ULL)));
    if (FLAG_EQ) goto L_1ca9b0;
    if (FLAG_HI) goto L_1cab30;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(98ULL)));
    if (FLAG_NE) goto L_1cac24;
    cpu->regs[23] = 1ULL;
L_1ca740:
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1ca74cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x7b3e0ULL);
    if ((cpu->regs[0])!=0) goto L_1cb018;
    cpu->regs[28] = ((uint32_t)(cpu->regs[28] + 1ULL));
    goto L_1ca718;
L_1ca758:
    cpu->regs[1] = SP + 96ULL;
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1cab20;
L_1ca760:
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_1ca76c;
    cpu->regs[0] = 114ULL;
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
L_1ca76c:
    if ((((uint32_t)(cpu->regs[26])))!=0) goto L_1cab40;
L_1ca770:
    PB_LDRW(cpu->regs[0], (SP + 28));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cac64;
L_1ca778:
    PB_LDRW(cpu->regs[0], (SP + 32));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cac44;
L_1ca780:
    PB_LDRW(cpu->regs[0], (SP + 36));
    PB_STRB((cpu->regs[1] + 0), 0ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & cpu->regs[23])); FLAG_CMP(cpu->regs[0], 0);
    PB_STRW((SP + 36), cpu->regs[0]);
    if (FLAG_NE) goto L_1cad68;
    PB_LDRW(cpu->regs[0], (SP + 28));
    cpu->regs[2] = ((uint32_t)(cpu->regs[21] + cpu->regs[25]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[26] + cpu->regs[0]));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + cpu->regs[2]));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_GT) goto L_1cae68;
    PB_LDR(cpu->regs[0], (SP + 40));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[23], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1cae4c;
    PB_LDR(cpu->regs[0], (SP + 56));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[23], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1cafa0;
    PB_LDR(cpu->regs[0], (SP + 48));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[23], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_1caf84;
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[24], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_1cae00;
L_1ca7e8:
    PB_LDR(cpu->regs[5], (SP + 64)); PB_LDR(cpu->regs[0], (SP + 64) + 8);
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 3664));
    cpu->regs[3] = SP + 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3184));
    cpu->regs[2] = cpu->regs[27];
    PB_LDR(cpu->regs[28], (cpu->regs[0] + 32));
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[4] : cpu->regs[7];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3144ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 96));
    cpu->regs[30] = PB_BASE + 0x1ca820ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1c1960ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1cad80;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ca83c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1cb08c;
L_1ca83c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ca844ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1cb054;
    if (!((cpu->regs[24] >> 31) & 1)) goto L_1cad48;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[7] = 47592ULL;
    cpu->regs[24] = SP + 88ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 64), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[7];
    PB_STR((SP + 88), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1ca87cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1caea8;
    cpu->regs[30] = PB_BASE + 0x1ca888ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_STRW((SP + 36), cpu->regs[0]);
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1cb098;
L_1ca894:
    PB_LDRW(cpu->regs[0], (SP + 36));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_1caea8;
    if (FLAG_NE) goto L_1cad5c;
L_1ca8a4:
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[6] = 34760ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[6];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ca8b8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xed3ccULL);
    if ((cpu->regs[0])==0) goto L_1caf10;
    PB_STR((SP + 72), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x1ca8c4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x129680ULL);
    PB_LDR(cpu->regs[1], (SP + 72));
    cpu->regs[27] = cpu->regs[0];
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    if (((cpu->regs[3] >> 31) & 1)) goto L_1ca8ec;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_1ca8ec;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1ca8ecULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ca8ec:
    FLAG_CMP(cpu->regs[27], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1cae84;
    if (((cpu->regs[27] >> 31) & 1)) goto L_1cae8c;
L_1ca8f8:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_1cad9c;
    PB_LDRW(cpu->regs[0], (SP + 32));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1cac3c;
    PB_LDRW(cpu->regs[0], (SP + 28));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | cpu->regs[26]));
    cpu->regs[21] = ((uint32_t)(cpu->regs[21] | cpu->regs[0]));
    if ((((uint32_t)(cpu->regs[21])))!=0) goto L_1cab4c;
    if ((((uint32_t)(cpu->regs[25])))==0) goto L_1caf54;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 64));
L_1ca91c:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 4016ULL;
    cpu->regs[30] = PB_BASE + 0x1ca930ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1c1960ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1cb054;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ca94c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1caf48;
L_1ca94c:
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_1caa84;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ca96c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ca96c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1ca96cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ca96c:
    cpu->regs[19] = cpu->regs[20];
L_1ca970:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1cad44;
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    PB_LDR(cpu->regs[23], (SP + 224)); PB_LDR(cpu->regs[24], (SP + 224) + 8);
    PB_LDR(cpu->regs[25], (SP + 240)); PB_LDR(cpu->regs[26], (SP + 240) + 8);
    PB_LDR(cpu->regs[27], (SP + 256)); PB_LDR(cpu->regs[28], (SP + 256) + 8);
    SP = SP + 272ULL;
    return;
L_1ca9b0:
    cpu->regs[25] = 1ULL;
    goto L_1ca740;
L_1ca9b8:
    cpu->regs[20] = PB_BASE + 0x295000ULL;
    cpu->regs[20] = cpu->regs[20] + 2904ULL;
L_1ca9c0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    if ((cpu->regs[0])!=0) goto L_1cab54;
    cpu->regs[24] = 4294967295ULL;
L_1ca9cc:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    PB_STR((SP + 40), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1caba0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1cac1c;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1cafbc;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = SP + 88ULL;
    cpu->regs[30] = PB_BASE + 0x1caa00ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 40), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1caa7c;
    cpu->regs[30] = PB_BASE + 0x1caa0cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 88));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1cacfc;
L_1caa18:
    cpu->regs[23] = cpu->regs[23] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_NE) goto L_1caba0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[19] = 1ULL;
    PB_STR((SP + 48), 0ULL); PB_STR((SP + 48) + 8, 0ULL);
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_1ca6c4;
L_1caa38:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 16));
    cpu->regs[19] = cpu->regs[2] + cpu->regs[19];
    cpu->regs[23] = cpu->regs[19] - 1ULL;
L_1caa44:
    cpu->regs[0] = SP + 104ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x51e000ULL;
    cpu->regs[4] = cpu->regs[4] + 3856ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[4] = cpu->regs[4] + 3944ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 8ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1caa74ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ca668;
L_1caa7c:
    cpu->regs[19] = 0ULL;
    goto L_1ca970;
L_1caa84:
    PB_LDR(cpu->regs[3], (SP + 40)); PB_LDR(cpu->regs[5], (SP + 40) + 8);
    PB_LDRW(cpu->regs[1], (SP + 36));
    PB_LDR(cpu->regs[4], (SP + 56));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 120));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3664));
    cpu->regs[1] = cpu->regs[1] + 3232ULL;
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 3184));
    cpu->regs[6] = (FLAG_EQ) ? cpu->regs[6] : cpu->regs[2];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1caabcULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1c1960ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1caf00;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1caad8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1cb048;
L_1caad8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[5] = 50568ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 64), cpu->regs[1]);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1caafcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe28a0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1caf10;
L_1cab00:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ca970;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ca970;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1cab1cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ca970;
L_1cab20:
    cpu->regs[0] = 120ULL;
    cpu->regs[1] = SP + 97ULL;
    PB_STRB((SP + 96), cpu->regs[0]);
    goto L_1ca760;
L_1cab30:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(119ULL)));
    if (FLAG_NE) goto L_1cac70;
    cpu->regs[26] = 1ULL;
    goto L_1ca740;
L_1cab40:
    cpu->regs[0] = 119ULL;
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    goto L_1ca770;
L_1cab4c:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 72));
    goto L_1ca91c;
L_1cab54:
    cpu->regs[30] = PB_BASE + 0x1cab58ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[24] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_1cab6c;
    cpu->regs[30] = PB_BASE + 0x1cab68ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1caa7c;
L_1cab6c:
    cpu->regs[23] = cpu->regs[23] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_NE) goto L_1ca9cc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[19] = 1ULL;
    PB_STR((SP + 40), 0ULL); PB_STR((SP + 40) + 8, 0ULL);
    PB_STR((SP + 56), 0ULL); PB_STR((SP + 56) + 8, cpu->regs[0]);
    goto L_1ca6c4;
L_1cab8c:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_1cb00c;
    cpu->regs[27] = cpu->regs[21];
    goto L_1ca6f0;
L_1caba0:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 32));
    PB_STR((SP + 56), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1cabc8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1caccc;
    PB_STR((SP + 56), 0ULL);
L_1cabc0:
    cpu->regs[23] = cpu->regs[23] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_EQ) goto L_1cac80;
L_1cabc8:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 40));
    PB_STR((SP + 48), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1cabf0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1cadcc;
    PB_STR((SP + 48), 0ULL);
L_1cabe8:
    cpu->regs[23] = cpu->regs[23] - 1ULL; FLAG_CMP(cpu->regs[23], 0);
    if (FLAG_EQ) goto L_1cad30;
L_1cabf0:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 48));
    if ((cpu->regs[0])==0) goto L_1cac98;
    cpu->regs[30] = PB_BASE + 0x1cabfcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[0] >> 31) & 1)) goto L_1caa7c;
    FLAG_CMP(cpu->regs[23], 1ULL);
    if (FLAG_NE) goto L_1cac9c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_1ca6c4;
L_1cac1c:
    PB_STR((SP + 40), 0ULL);
    goto L_1caa18;
L_1cac24:
    if (FLAG_HI) goto L_1cb018;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(43ULL)));
    if (FLAG_NE) goto L_1cac50;
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 32), cpu->regs[0]);
    goto L_1ca740;
L_1cac3c:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 56));
    goto L_1ca91c;
L_1cac44:
    cpu->regs[0] = 43ULL;
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    goto L_1ca780;
L_1cac50:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(97ULL)));
    if (FLAG_NE) goto L_1cb018;
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 28), cpu->regs[0]);
    goto L_1ca740;
L_1cac64:
    cpu->regs[0] = 97ULL;
    PB_STRB(cpu->regs[1], cpu->regs[0]); cpu->regs[1] += 1;
    goto L_1ca778;
L_1cac70:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(120ULL)));
    if (FLAG_NE) goto L_1cad1c;
    cpu->regs[21] = 1ULL;
    goto L_1ca740;
L_1cac80:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[19] = 1ULL;
    PB_STR((SP + 48), 0ULL);
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_1ca6c4;
L_1cac98:
    cpu->regs[19] = 1ULL;
L_1cac9c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 56));
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_1ca6c4;
L_1caca8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[20] = PB_BASE + 0x295000ULL;
    cpu->regs[19] = 1ULL;
    cpu->regs[20] = cpu->regs[20] + 2904ULL;
    cpu->regs[24] = 4294967295ULL;
    PB_STR((SP + 40), 0ULL); PB_STR((SP + 40) + 8, 0ULL);
    PB_STR((SP + 56), 0ULL); PB_STR((SP + 56) + 8, cpu->regs[0]);
    goto L_1ca6c4;
L_1caccc:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1cafe4;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = SP + 88ULL;
    cpu->regs[30] = PB_BASE + 0x1cace4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 56), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1caa7c;
    cpu->regs[30] = PB_BASE + 0x1cacf0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 88));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1cabc0;
L_1cacfc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cad18ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1ca970;
L_1cad1c:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(116ULL)));
    if (FLAG_NE) goto L_1cb018;
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 36), cpu->regs[0]);
    goto L_1ca740;
L_1cad30:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[19] = 1ULL;
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_1ca6c4;
L_1cad44:
    cpu->regs[30] = PB_BASE + 0x1cad48ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1cad48:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_1ca8f8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 64), cpu->regs[0]);
L_1cad5c:
    cpu->regs[0] = 1ULL;
    PB_STRW((SP + 36), cpu->regs[0]);
    goto L_1ca8a4;
L_1cad68:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 2800ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cad80ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1cad80:
    cpu->regs[22] = 0ULL;
L_1cad84:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1cad8cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cad98ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1ca970;
L_1cad9c:
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_1cab00;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3176ULL;
    cpu->regs[24] = SP + 88ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cadbcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_1caea8;
L_1cadcc:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1cae24;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = SP + 88ULL;
    cpu->regs[30] = PB_BASE + 0x1cade4ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1caa7c;
    cpu->regs[30] = PB_BASE + 0x1cadf0ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 88));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1cabe8;
    goto L_1cacfc;
L_1cae00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3744));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 3040ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cae1cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x226a20ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1ca7e8;
    goto L_1cad80;
L_1cae24:
    PB_LDR(cpu->regs[3], (SP + 48));
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 2728ULL;
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3064ULL;
    cpu->regs[30] = PB_BASE + 0x1cae48ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_1ca970;
L_1cae4c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 2896ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cae64ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cad80;
L_1cae68:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 2840ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cae80ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cad80;
L_1cae84:
    cpu->regs[30] = PB_BASE + 0x1cae88ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1caf10;
L_1cae8c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[24] = SP + 88ULL;
    cpu->regs[1] = cpu->regs[1] + 3152ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1caea8ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1caea8:
    cpu->regs[30] = PB_BASE + 0x1caeacULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[4] = 39328ULL;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    PB_STR((SP + 88), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1caed0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1caedcULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1caee4ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1caef8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1cb038;
L_1caef8:
    cpu->regs[27] = 0ULL;
    goto L_1cad84;
L_1caf00:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[19] = cpu->regs[20];
    PB_STR((SP + 64), cpu->regs[0]);
L_1caf10:
    cpu->regs[24] = SP + 88ULL;
    goto L_1caea8;
L_1caf18:
    cpu->regs[19] = cpu->regs[2];
    goto L_1caa44;
L_1caf20:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 2712ULL;
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3064ULL;
    cpu->regs[30] = PB_BASE + 0x1caf44ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_1ca970;
L_1caf48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1caf50ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ca94c;
L_1caf54:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3208ULL;
    cpu->regs[24] = SP + 88ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1caf74ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_1caea8;
L_1caf84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 2992ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1caf9cULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cad80;
L_1cafa0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 2944ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cafb8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_1cad80;
L_1cafbc:
    PB_LDR(cpu->regs[3], (SP + 40));
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 1896ULL;
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3064ULL;
    cpu->regs[30] = PB_BASE + 0x1cafe0ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_1ca970;
L_1cafe4:
    PB_LDR(cpu->regs[3], (SP + 56));
    cpu->regs[2] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 2624ULL;
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    cpu->regs[0] = PB_BASE + 0x28a000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3064ULL;
    cpu->regs[30] = PB_BASE + 0x1cb008ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_1ca970;
L_1cb00c:
    cpu->regs[27] = cpu->regs[21];
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_1ca6f0;
L_1cb018:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 2776ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb034ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1cad80;
L_1cb038:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[27] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1cb044ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1cad84;
L_1cb048:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1cb050ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1caad8;
L_1cb054:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[24] = SP + 88ULL;
    PB_STR((SP + 64), cpu->regs[0]);
    goto L_1caea8;
L_1cb068:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2752ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1cb088ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_1cad84;
L_1cb08c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1cb094ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ca83c;
L_1cb098:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1ca894;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1cb0acULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ca894;
}
