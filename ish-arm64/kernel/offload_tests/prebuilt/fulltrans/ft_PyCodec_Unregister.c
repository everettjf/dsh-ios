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

void ft_PyCodec_Unregister(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x24be60ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xecf64ULL);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 1248));
    if ((cpu->regs[20])==0) goto L_24bec0;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    cpu->regs[19] = 0ULL;
L_24be70:
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_GE) goto L_24bec0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 24));
    cpu->regs[22] = cpu->regs[19] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[19] << 3)));
    FLAG_CMP(cpu->regs[1], cpu->regs[21]);
    if (FLAG_NE) goto L_24beb8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 1256));
    if ((cpu->regs[0])==0) goto L_24be98;
    cpu->regs[30] = PB_BASE + 0x24be98ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1c17e0ULL);
L_24be98:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x1ac20cULL); return; };
L_24beb8:
    cpu->regs[19] = cpu->regs[22];
    goto L_24be70;
L_24bec0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_24c100;
L_24bef8:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x24bf08ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c1f8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[1] = 45512ULL;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[1] = cpu->regs[24] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x24bf28ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[2] = 45512ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2680));
    cpu->regs[1] = cpu->regs[24] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x24bf40ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[3] = 33056ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x24bf54ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2680));
    cpu->regs[4] = 33056ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x24bf6cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xe31ccULL);
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[21]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_24c130;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[0]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_24c130;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_24c130;
    cpu->regs[24] = cpu->regs[24] + 3240ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2520));
    goto L_24c000;
L_24bfa4:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24c01c;
L_24bfb0:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24bfc0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe35f0ULL);
    if ((cpu->regs[0])==0) goto L_24c040;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x24bfccULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11a700ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c030;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24bfe8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x202dc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_24c124;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_24c068;
L_24bff8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_24c080;
L_24c000:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x24c008ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c098;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[25]);
    if (FLAG_EQ) goto L_24bfa4;
L_24c01c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24c024ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_24bfb0;
L_24c030:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[21] = 0ULL;
    cpu->regs[20] = 0ULL;
    goto L_24c0a8;
L_24c040:
    cpu->regs[30] = PB_BASE + 0x24c044ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_24c030;
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24c05cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x202dc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_24bff8;
    goto L_24c030;
L_24c068:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24bff8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24c07cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24bff8;
L_24c080:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_24c000;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24c094ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24c000;
L_24c098:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_24c09c:
    cpu->regs[21] = 0ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[19] = 0ULL;
L_24c0a8:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24c0c4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24c0c4;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x24c0c4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_24c0c4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24c0ccULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24c0d4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x24c0dcULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[30] = PB_BASE + 0x24c0e0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_24c1f8;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_24c0f4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_24c100:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 3688ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x24c118ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_24bef8;
    cpu->regs[0] = 0ULL;
    goto L_24c0f4;
L_24c124:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[20] = 0ULL;
    goto L_24c0a8;
L_24c130:
    cpu->regs[0] = 45512ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24c140ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c09c;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[24] + 3208ULL;
    cpu->regs[24] = cpu->regs[24] + 3240ULL;
L_24c154:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x24c15cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c1d4;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24c178ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1987c8ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c1d4;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x24c188ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11a700ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_24c210;
L_24c194:
    if ((cpu->regs[21])==0) goto L_24c208;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x24c1a8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe97e4ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_24c208;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_24c1e0;
L_24c1b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_24c154;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24c154;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x24c1d0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24c154;
L_24c1d4:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[21] = 0ULL;
    goto L_24c0a8;
L_24c1e0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_24c1b4;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x24c1f4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24c1b4;
L_24c1f8:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_24c0f4;
L_24c208:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_24c0a8;
L_24c210:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_24c194;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x24c224ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_24c194;
    SP = SP - 128ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 72), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[3];
    if ((cpu->regs[3])!=0) goto L_24c344;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_24c39c;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[21] = cpu->regs[2];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 3ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_24c34c;
L_24c278:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_EQ) goto L_24c38c;
L_24c284:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 8));
    if ((cpu->regs[19])==0) goto L_24c300;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_24c438;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[30] = PB_BASE + 0x24c2a4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c404;
    cpu->regs[30] = PB_BASE + 0x24c2b0ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_24c45c;
    FLAG_CMP(cpu->regs[21], 2ULL);
    if (FLAG_NE) goto L_24c300;
    cpu->regs[2] = 0ULL;
L_24c2c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_24c3e0;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 128ULL;
    { PB_CALL(34, cpu, tlb, PB_BASE + 0x24c480ULL); return; };
L_24c300:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_24c3e4;
    cpu->regs[1] = SP + 40ULL;
    cpu->regs[30] = PB_BASE + 0x24c318ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe9aa4ULL);
    PB_STR((SP + 24), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_24c404;
    cpu->regs[30] = PB_BASE + 0x24c324ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    PB_LDR(cpu->regs[2], (SP + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_24c45c;
    if ((cpu->regs[19])!=0) goto L_24c2c8;
    cpu->regs[19] = PB_BASE + 0x283000ULL;
    cpu->regs[19] = cpu->regs[19] + 1576ULL;
    goto L_24c2c8;
L_24c344:
    PB_LDR(cpu->regs[21], (cpu->regs[3] + 16));
    cpu->regs[21] = cpu->regs[2] + cpu->regs[21];
L_24c34c:
    cpu->regs[2] = SP + 48ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[4] + 224ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24c380ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c404;
    goto L_24c278;
L_24c38c:
    cpu->regs[19] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 1576ULL;
    goto L_24c2c8;
L_24c39c:
    cpu->regs[0] = SP + 48ULL;
    PB_STR((SP + 0), cpu->regs[0]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[4] + 224ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 3ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x24c3ccULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x14bee8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_24c404;
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[19];
    goto L_24c284;
L_24c3e0:
    cpu->regs[30] = PB_BASE + 0x24c3e4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x7c170ULL);
L_24c3e4:
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1920ULL;
    cpu->regs[0] = cpu->regs[0] + 2920ULL;
    cpu->regs[30] = PB_BASE + 0x24c404ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x23b310ULL);
L_24c404:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_24c3e0;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_24c438:
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 1896ULL;
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 2920ULL;
    cpu->regs[30] = PB_BASE + 0x24c458ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x23b310ULL);
    goto L_24c404;
L_24c45c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x24c474ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_24c404;
    /* nop */
    /* nop */
}
