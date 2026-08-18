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

void ft_PyODict_SetItem(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x2216f0ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_221718;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_221888;
L_221718:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x221740ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x213250ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_221860;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_221838;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x221754ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x14d3acULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_221878;
    cpu->regs[30] = PB_BASE + 0x221760ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x14d650ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_221780;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221780;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x221780ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_221780:
    if ((cpu->regs[19])==0) goto L_221878;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[1] = 1ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x221798ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x134b80ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_2217b8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2217b8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2217b8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2217b8:
    if ((cpu->regs[20])==0) goto L_221878;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3672));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_221820;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1400ULL;
    cpu->regs[30] = PB_BASE + 0x2217e4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[19] = cpu->regs[0];
L_2217e8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_221804;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221804;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x221804ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_221804:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22180cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x2153e0ULL);
L_22180c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_221820:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1416ULL;
    cpu->regs[30] = PB_BASE + 0x221830ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_2217e8;
L_221838:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x221840ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x2153e0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1392ULL;
L_22184c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_221860:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_221880;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1384ULL;
    goto L_22184c;
L_221878:
    cpu->regs[19] = 0ULL;
    goto L_221804;
L_221880:
    cpu->regs[19] = 0ULL;
    goto L_22180c;
L_221888:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x2218acULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x202dc0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22199c;
    cpu->regs[22] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_22193c;
L_2218c0:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2218d0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x2219f0ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_2219a4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 64));
    cpu->regs[20] = cpu->regs[0] << 3;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[20]));
    if ((cpu->regs[0])!=0) goto L_221944;
    cpu->regs[0] = 32ULL;
    cpu->regs[30] = PB_BASE + 0x2218ecULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdbd90ULL);
    if ((cpu->regs[0])==0) goto L_221964;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 56));
    PB_STR((cpu->regs[0] + 0), cpu->regs[21]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[23]);
    PB_STR((cpu->regs[0] + 16), 0ULL); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221934;
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
L_221904:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 64));
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 88));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[19] + 88), cpu->regs[1]);
    PB_STR((cpu->regs[2] + cpu->regs[20]), cpu->regs[0]);
L_22191c:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_221934:
    PB_STR((cpu->regs[1] + 16), cpu->regs[0]);
    goto L_221904;
L_22193c:
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
    goto L_2218c0;
L_221944:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22191c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22191c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x221960ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22191c;
L_221964:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_221978;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2219cc;
L_221978:
    cpu->regs[30] = PB_BASE + 0x22197cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x22d780ULL);
L_22197c:
    cpu->regs[30] = PB_BASE + 0x221980ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x221994ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x197fe0ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22199cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1cd8e0ULL);
L_22199c:
    cpu->regs[22] = 4294967295ULL;
    goto L_22191c;
L_2219a4:
    cpu->regs[30] = PB_BASE + 0x2219a8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_2219d8;
L_2219ac:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22197c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22197c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2219c8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22197c;
L_2219cc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2219d4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221978;
L_2219d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x2219ecULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    goto L_2219ac;
L_2219f0:
    SP = SP - 96ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = 1ULL;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 32));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 80));
    cpu->regs[20] = cpu->regs[20] << (cpu->regs[0] & 63);
    FLAG_CMP(cpu->regs[3], cpu->regs[23]);
    if (FLAG_NE) goto L_221aac;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[24] = SP;
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_NE) goto L_221aac;
L_221a54:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x221a68ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdd360ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_221b44;
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_GE) ? cpu->regs[0] : (~0ULL);
L_221a78:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_221b4c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_221aac:
    cpu->regs[1] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_HI) goto L_221b5c;
    cpu->regs[1] = 8ULL;
    cpu->regs[0] = cpu->regs[1] << (cpu->regs[0] & 63);
    cpu->regs[30] = PB_BASE + 0x221ac4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_221b5c;
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    goto L_221ae0;
L_221ad8:
    PB_STR((cpu->regs[23] + (cpu->regs[3] << 3)), 0ULL);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
L_221ae0:
    FLAG_CMP(cpu->regs[3], cpu->regs[20]);
    if (FLAG_NE) goto L_221ad8;
    PB_LDR(cpu->regs[25], (cpu->regs[19] + 48));
    cpu->regs[24] = SP;
L_221af0:
    if ((cpu->regs[25])!=0) goto L_221b10;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    cpu->regs[30] = PB_BASE + 0x221afcULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((cpu->regs[19] + 64), cpu->regs[23]); PB_STR((cpu->regs[19] + 64) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 32));
    PB_STR((cpu->regs[19] + 80), cpu->regs[23]);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_221a54;
L_221b10:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 0)); PB_LDR(cpu->regs[2], (cpu->regs[25] + 0) + 8);
    cpu->regs[3] = cpu->regs[24];
    PB_LDR(cpu->regs[26], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x221b24ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdd360ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_221b54;
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_GE) ? cpu->regs[0] : (~0ULL);
L_221b34:
    if (((cpu->regs[0] >> 63) & 1)) goto L_221b68;
    PB_STR((cpu->regs[23] + (cpu->regs[0] << 3)), cpu->regs[25]);
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 16));
    goto L_221af0;
L_221b44:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 24));
    goto L_221a78;
L_221b4c:
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x221b54ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c170ULL);
L_221b54:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 24));
    goto L_221b34;
L_221b5c:
    cpu->regs[30] = PB_BASE + 0x221b60ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_221a78;
L_221b68:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x221b70ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_221a78;
    /* nop */
    SP = SP - 32ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 8), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[0] = 60376ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x221bc8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_221bf0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_221bf0:
    cpu->regs[30] = PB_BASE + 0x221bf4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3320));
    { PB_CALL(35, cpu, tlb, PB_BASE + 0x1a3d00ULL); return; };
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_221c1c;
    cpu->regs[1] = 4ULL;
    goto L_221c28;
L_221c1c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    return;
L_221c28:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3008));
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = ((uint32_t)(cpu->regs[1] & 1ULL));
    cpu->regs[30] = PB_BASE + 0x221c50ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xd8d60ULL);
    if ((cpu->regs[0])==0) goto L_221cfc;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = ((uint32_t)(cpu->regs[21] & 6ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(6ULL)));
    if (FLAG_EQ) goto L_221ccc;
    PB_STR((cpu->regs[19] + 56), 0ULL);
L_221c68:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_221d0c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
L_221c74:
    if ((cpu->regs[0])==0) goto L_221c88;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_221d04;
L_221c88:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 88));
    PB_STR((cpu->regs[19] + 40), cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_221cac;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_221cac:
    PB_STR((cpu->regs[19] + 24), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x221cb8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xd9444ULL);
L_221cb8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_221ccc:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[0] = 2ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x221ce0ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe1204ULL);
    PB_STR((cpu->regs[19] + 56), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_221c68;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_221cfc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_221d14;
L_221cfc:
    cpu->regs[19] = 0ULL;
    goto L_221cb8;
L_221d04:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_221c88;
L_221d0c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    goto L_221c74;
L_221d14:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x221d20ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221cb8;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_221e28;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    if ((cpu->regs[1])==0) goto L_221e08;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 88));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_221df0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_221f7c;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x221d70ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x222000ULL);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_221f1c;
    if (((cpu->regs[20] >> 0) & 1)) goto L_221f00;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
L_221d80:
    if ((cpu->regs[0])==0) goto L_221d94;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_221ed8;
L_221d94:
    PB_STR((cpu->regs[19] + 48), cpu->regs[0]);
    if ((cpu->regs[21])==0) goto L_221e28;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if (!((cpu->regs[0] >> 2) & 1)) goto L_221ddc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x221db0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x190fa8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_221f54;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_221dc8;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_221dc8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if (((cpu->regs[0] >> 1) & 1)) goto L_221e30;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_221fa4;
L_221dd8:
    cpu->regs[21] = cpu->regs[20];
L_221ddc:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_221df0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 1448ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x221e08ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_221e08:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_221e28;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_221e28;
L_221e1c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_221ee0;
L_221e28:
    cpu->regs[21] = 0ULL;
    goto L_221ddc;
L_221e30:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_221e7c;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_221e50;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_221e50:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_221f08;
L_221e5c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_221eec;
L_221e68:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + -16));
    if ((cpu->regs[0])==0) goto L_221fd8;
L_221e70:
    PB_STR((cpu->regs[22] + 24), cpu->regs[21]); PB_STR((cpu->regs[22] + 24) + 8, cpu->regs[20]);
    cpu->regs[21] = cpu->regs[22];
    goto L_221ddc;
L_221e7c:
    cpu->regs[30] = PB_BASE + 0x221e80ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x187fc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_221e70;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_221e9c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_221fe4;
L_221e9c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_221eb0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_221ff0;
L_221eb0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_221e08;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_221e08;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221e08;
    cpu->regs[30] = PB_BASE + 0x221ed4ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221e08;
L_221ed8:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
    goto L_221d94;
L_221ee0:
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x221ee8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221ddc;
L_221eec:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221e68;
    cpu->regs[30] = PB_BASE + 0x221efcULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221e68;
L_221f00:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    goto L_221d80;
L_221f08:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221e5c;
    cpu->regs[30] = PB_BASE + 0x221f18ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221e5c;
L_221f1c:
    cpu->regs[30] = PB_BASE + 0x221f20ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_221f38;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x221f38ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
L_221f38:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    if ((cpu->regs[0])==0) goto L_221e28;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 48), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_221e1c;
    cpu->regs[21] = 0ULL;
    goto L_221ddc;
L_221f54:
    cpu->regs[30] = PB_BASE + 0x221f58ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_221fc0;
L_221f5c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_221eb0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_221eb0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x221f78ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221eb0;
L_221f7c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 1488ULL;
    cpu->regs[21] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x221f98ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    goto L_221ddc;
L_221fa4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_221dd8;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[21] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x221fbcULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221ddc;
L_221fc0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3544));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x221fd4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
    goto L_221f5c;
L_221fd8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x221fe0ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xd9444ULL);
    goto L_221e70;
L_221fe4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x221fecULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221e9c;
L_221ff0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x221ff8ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221eb0;
    /* nop */
L_222000:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    if ((cpu->regs[0])==0) goto L_222054;
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x222024ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222054;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22203cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x2219f0ULL);
    if (((cpu->regs[0] >> 63) & 1)) goto L_222054;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 64));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + (cpu->regs[0] << 3)));
L_222048:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_222054:
    cpu->regs[0] = 0ULL;
    goto L_222048;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x222074ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x22207cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x222084ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 6ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(6ULL)));
    if (FLAG_EQ) goto L_2220a4;
L_222094:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(63, cpu, tlb, PB_BASE + 0xe1dc0ULL); return; };
L_2220a4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_222094;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_222094;
    cpu->regs[30] = PB_BASE + 0x2220c0ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_222094;
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 3736ULL;
    { PB_CALL(65, cpu, tlb, PB_BASE + 0xdea4cULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x2220e0ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x222000ULL;
    cpu->regs[0] = cpu->regs[0] + 208ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_222164;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x222110ULL; PB_CALL(67, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[20], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222120ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcdb0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_22219c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[30] = PB_BASE + 0x22212cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])!=0) goto L_2221ac;
L_222134:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22213cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x2221c0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2680));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x222150ULL; PB_CALL(71, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[20])==0) goto L_22219c;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(72, cpu, tlb, PB_BASE + 0xdce80ULL); return; };
L_222164:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    cpu->regs[30] = PB_BASE + 0x22216cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])!=0) goto L_2221a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22217cULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x2221c0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2680));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_22219c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2221a8:
    cpu->regs[20] = 0ULL;
L_2221ac:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2221b4ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_222134;
    /* nop */
    /* nop */
L_2221c0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 64));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x2221dcULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((cpu->regs[20] + 64), 0ULL); PB_STR((cpu->regs[20] + 64) + 8, 0ULL);
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 48));
    PB_STR((cpu->regs[20] + 48), 0ULL); PB_STR((cpu->regs[20] + 48) + 8, 0ULL);
    PB_STR((cpu->regs[20] + 80), 0ULL);
    if ((cpu->regs[19])==0) goto L_222210;
L_2221f0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_22222c;
L_222200:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22220cULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    if ((cpu->regs[19])!=0) goto L_2221f0;
L_222210:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 88));
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[20] + 88), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_22222c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_222200;
    cpu->regs[30] = PB_BASE + 0x22223cULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_222200;
    SP = SP - 208ULL;
    cpu->regs[4] = 31288ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    PB_STR((SP + 144), cpu->regs[21]); PB_STR((SP + 144) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = SP + 48ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[19] = 0ULL;
    PB_STR((SP + 160), cpu->regs[23]); PB_STR((SP + 160) + 8, cpu->regs[24]);
    PB_STR((SP + 176), cpu->regs[25]); PB_STR((SP + 176) + 8, cpu->regs[26]);
    cpu->regs[25] = PB_BASE + 0x298000ULL;
    cpu->regs[25] = cpu->regs[25] + 1536ULL;
    PB_STR((SP + 192), cpu->regs[27]); PB_STR((SP + 192) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 104), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2248));
    PB_LDR(cpu->regs[24], (cpu->regs[2] + 16));
    cpu->regs[27] = cpu->regs[23] + cpu->regs[4];
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 3808));
    cpu->regs[30] = PB_BASE + 0x2222b0ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x11cb84ULL);
L_2222b0:
    FLAG_CMP(cpu->regs[19], cpu->regs[24]);
    if (FLAG_GE) goto L_2223e4;
    if ((cpu->regs[19])==0) goto L_2222d4;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x2222ccULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2224d0;
L_2222d4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[19] << 3);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
    PB_STR((SP + 24), 0ULL); PB_STR((SP + 24) + 8, 0ULL);
    FLAG_CMP(cpu->regs[20], cpu->regs[26]);
    if (FLAG_EQ) goto L_222428;
    cpu->regs[28] = SP + 40ULL;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222300ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2224c0;
    PB_LDR(cpu->regs[0], (SP + 40));
    if ((cpu->regs[0])!=0) goto L_222444;
L_222310:
    cpu->regs[2] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 31664ULL;
    cpu->regs[1] = cpu->regs[23] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x222324ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x112290ULL);
    PB_LDR(cpu->regs[28], (SP + 24));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2224c0;
    if ((cpu->regs[28])==0) goto L_222484;
    cpu->regs[0] = 30600ULL;
    cpu->regs[2] = SP + 32ULL;
    cpu->regs[1] = cpu->regs[23] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222348ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x112290ULL);
    PB_LDR(cpu->regs[3], (SP + 32));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2224c0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[3], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_222484;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_2224a4;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 136ULL;
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x222388ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x11d180ULL);
    PB_LDR(cpu->regs[3], (SP + 8));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2224a4;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x222398ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x12cb88ULL);
    cpu->regs[20] = cpu->regs[0];
L_22239c:
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x2223a4ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x2223acULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x18d760ULL);
    if ((cpu->regs[20])==0) goto L_2224d0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2223bcULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x120700ULL);
    cpu->regs[28] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_2223d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_222494;
L_2223d4:
    FLAG_CMP(cpu->regs[28], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2224d0;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_2222b0;
L_2223e4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2223ecULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x11ce48ULL);
L_2223ec:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2224a0;
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    PB_LDR(cpu->regs[23], (SP + 160)); PB_LDR(cpu->regs[24], (SP + 160) + 8);
    PB_LDR(cpu->regs[25], (SP + 176)); PB_LDR(cpu->regs[26], (SP + 176) + 8);
    PB_LDR(cpu->regs[27], (SP + 192)); PB_LDR(cpu->regs[28], (SP + 192) + 8);
    SP = SP + 208ULL;
    return;
L_222428:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[2] = 4ULL;
    cpu->regs[1] = cpu->regs[1] + 2064ULL;
    cpu->regs[30] = PB_BASE + 0x22243cULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x1200e8ULL);
    cpu->regs[28] = cpu->regs[0];
    goto L_2223d4;
L_222444:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2224e0;
L_22244c:
    cpu->regs[3] = 26080ULL;
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[23] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222460ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2224c0;
    PB_LDR(cpu->regs[0], (SP + 40));
    if ((cpu->regs[0])==0) goto L_222310;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_222484;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2224f4;
L_222484:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22248cULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x14d650ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_22239c;
L_222494:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22249cULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2223d4;
L_2224a0:
    cpu->regs[30] = PB_BASE + 0x2224a4ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2224a4:
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1544ULL;
    cpu->regs[30] = PB_BASE + 0x2224b8ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_22239c;
L_2224c0:
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[30] = PB_BASE + 0x2224c8ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 32));
    cpu->regs[30] = PB_BASE + 0x2224d0ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x18d760ULL);
L_2224d0:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2224d8ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x7bef0ULL);
    cpu->regs[0] = 0ULL;
    goto L_2223ec;
L_2224e0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22244c;
    cpu->regs[30] = PB_BASE + 0x2224f0ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_22244c;
L_2224f4:
    cpu->regs[30] = PB_BASE + 0x2224f8ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_222484;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x222518ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_222530;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    goto L_222540;
L_222530:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
L_222540:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 304));
    cpu->regs[30] = PB_BASE + 0x22255cULL; PB_CALL(102, cpu, tlb, cpu->regs[2]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_222578;
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]); PB_STR((cpu->regs[0] + 16) + 8, 0ULL);
L_222568:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_222578:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_222568;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_222568;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222594ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_222568;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x2225b8ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x2225c0ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x2225c8ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2225d4ULL; PB_CALL(107, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2225e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_2225f4;
L_2225e8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2225f4:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(108, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    cpu->regs[30] = PB_BASE + 0x222630ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_NE) goto L_222668;
L_222640:
    if ((cpu->regs[20])!=0) goto L_22267c;
L_222644:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22264cULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_222690;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_222540;
L_222668:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_222640;
    goto L_222644;
L_22267c:
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 1552ULL;
    cpu->regs[30] = PB_BASE + 0x22268cULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_222644;
L_222690:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x520000ULL;
    cpu->regs[3] = cpu->regs[3] + 16ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[3] + 1088ULL;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x2226d0ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x14b8f0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_22274c;
L_2226e0:
    if ((cpu->regs[21])!=0) goto L_222708;
L_2226e4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_222730;
L_2226f0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 24) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_222760;
L_222708:
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[0] + 1560ULL;
    cpu->regs[30] = PB_BASE + 0x222718ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x22b240ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2226e4;
L_22271c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_222730:
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1560ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x222744ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22271c;
    goto L_2226f0;
L_22274c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 296));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_2226e0;
    goto L_2226e4;
L_222760:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x222780ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_2227dc;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 304));
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x222798ULL; PB_CALL(116, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_2227c0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_2227ac;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_2227ac:
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[20]);
L_2227b0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2227c0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2227dc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2227dc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2227dcULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2227dc:
    cpu->regs[0] = 0ULL;
    goto L_2227b0;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 24));
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2296));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 224));
L_22281c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x222824ULL; PB_CALL(118, cpu, tlb, cpu->regs[24]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_22287c;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[26]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[25]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_2228ac;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x222848ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2228d0;
    cpu->regs[30] = PB_BASE + 0x222854ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2228b8;
L_222860:
    if ((cpu->regs[21])==0) goto L_222880;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_222878;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22289c;
L_222878:
    if (!((cpu->regs[21] >> 63) & 1)) goto L_22281c;
L_22287c:
    cpu->regs[19] = 0ULL;
L_222880:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_22289c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2228a4ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if (!((cpu->regs[21] >> 63) & 1)) goto L_22281c;
    goto L_22287c;
L_2228ac:
    cpu->regs[30] = PB_BASE + 0x2228b0ULL; PB_CALL(122, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[21] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    goto L_222860;
L_2228b8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_222860;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2228ccULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_222860;
L_2228d0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22287c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_22287c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2228f0ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_222880;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_22291c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    cpu->regs[0] = cpu->regs[1] - cpu->regs[0]; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_LT) goto L_22291c;
    { PB_CALL(125, cpu, tlb, PB_BASE + 0xe1fc0ULL); return; };
L_22291c:
    cpu->regs[0] = 0ULL;
    { PB_CALL(126, cpu, tlb, PB_BASE + 0xe2620ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x22293cULL; PB_CALL(127, cpu, tlb, PB_BASE + 0xdcd00ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x222944ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x22294cULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x222958ULL; PB_CALL(130, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22296c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_222978;
L_22296c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_222978:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(131, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[2] = cpu->regs[2] + 1576ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x2229a8ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x1d4b00ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_222a1c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_2229fc;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 872));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_2229cc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_2229cc:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 872), cpu->regs[19]);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2229e8;
L_2229d8:
    cpu->regs[0] = 0ULL;
L_2229dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2229e8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2229d8;
    cpu->regs[30] = PB_BASE + 0x2229f8ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2229d8;
L_2229fc:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 1592ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x222a1cULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x11f220ULL);
L_222a1c:
    cpu->regs[0] = 4294967295ULL;
    goto L_2229dc;
    SP = SP - 160ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = SP;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    cpu->regs[20] = SP;
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 16));
    cpu->regs[30] = PB_BASE + 0x222a68ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x11cb84ULL);
    PB_LDRB(cpu->regs[1], (cpu->regs[21] + 48));
    if (((cpu->regs[1] >> 0) & 1)) goto L_222c3c;
L_222a70:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222a7cULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x222c64ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_222b68;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    cpu->regs[25] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[25] + 1648ULL;
    cpu->regs[30] = PB_BASE + 0x222a98ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222b64;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 3312));
    cpu->regs[19] = 0ULL;
L_222aac:
    FLAG_CMP(cpu->regs[19], cpu->regs[23]);
    if (FLAG_GE) goto L_222ae8;
    if ((cpu->regs[19])!=0) goto L_222b48;
L_222ab8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[19] << 3);
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_222ba8;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222adcULL; PB_CALL(138, cpu, tlb, PB_BASE + 0x222c64ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_222b64;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_222aac;
L_222ae8:
    if ((cpu->regs[23])==0) goto L_222b84;
L_222aec:
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2608ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x222b00ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222b64;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222b10ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x11ce48ULL);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
L_222b14:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_222b78;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    SP = SP + 160ULL;
    return;
L_222b48:
    cpu->regs[1] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2888ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x222b5cULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_222ab8;
L_222b64:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
L_222b68:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x222b70ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x7bef0ULL);
    cpu->regs[0] = 0ULL;
    goto L_222b14;
L_222b78:
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x222b84ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0x7c170ULL);
L_222b84:
    cpu->regs[1] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 3040ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x222b98ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_222aec;
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    goto L_222b68;
L_222ba8:
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[1] = cpu->regs[25] + 1648ULL;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[28], (cpu->regs[22] + 16));
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x222bc0ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222c30;
    cpu->regs[27] = PB_BASE + 0x285000ULL;
    cpu->regs[27] = cpu->regs[27] + 2888ULL;
    cpu->regs[26] = 0ULL;
L_222bd4:
    FLAG_CMP(cpu->regs[28], cpu->regs[26]);
    if (FLAG_LE) goto L_222c14;
    if ((cpu->regs[26])==0) goto L_222bf8;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x222bf0ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222c30;
L_222bf8:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + (cpu->regs[26] << 3)));
    cpu->regs[30] = PB_BASE + 0x222c08ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0x222c64ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_222c30;
    cpu->regs[26] = cpu->regs[26] + 1ULL;
    goto L_222bd4;
L_222c14:
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 2608ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x222c28ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_222c58;
L_222c30:
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    goto L_222b68;
L_222c3c:
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 2208ULL;
    cpu->regs[30] = PB_BASE + 0x222c4cULL; PB_CALL(149, cpu, tlb, PB_BASE + 0x1200e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_222a70;
    goto L_222b68;
L_222c58:
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_222aac;
L_222c64:
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2504));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 8), 0ULL); PB_STR((SP + 8) + 8, 0ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_222dd0;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[4] = 31288ULL;
    cpu->regs[22] = SP;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x222cc8ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222e7c;
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])!=0) goto L_222de4;
L_222cd8:
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 31664ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x222cecULL; PB_CALL(151, cpu, tlb, PB_BASE + 0x112290ULL);
    PB_LDR(cpu->regs[22], (SP + 16));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222e7c;
    if ((cpu->regs[22])==0) goto L_222e24;
    cpu->regs[0] = 30600ULL;
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x222d10ULL; PB_CALL(152, cpu, tlb, PB_BASE + 0x112290ULL);
    PB_LDR(cpu->regs[21], (SP + 8));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222e7c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[21], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_222e24;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_222e5c;
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 136ULL;
    cpu->regs[30] = PB_BASE + 0x222d4cULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x11d180ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_222e5c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x222d58ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0x12cb88ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[19] = cpu->regs[0];
L_222d60:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x222d68ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x222d70ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0x18d760ULL);
    if ((cpu->regs[19])==0) goto L_222e90;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x222d80ULL; PB_CALL(157, cpu, tlb, PB_BASE + 0x120700ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_222da0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_222da0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x222da0ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_222da0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_222e38;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_222dd0:
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1656ULL;
    cpu->regs[30] = PB_BASE + 0x222ddcULL; PB_CALL(159, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[19] = cpu->regs[0];
    goto L_222d60;
L_222de4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_222e48;
L_222dec:
    cpu->regs[3] = 26080ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x222e00ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_222e7c;
    PB_LDR(cpu->regs[0], (SP + 0));
    if ((cpu->regs[0])==0) goto L_222cd8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_222e24;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_222e40;
L_222e24:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x222e2cULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x14d650ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    cpu->regs[19] = cpu->regs[0];
    goto L_222d60;
L_222e38:
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x222e40ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x7c170ULL);
L_222e40:
    cpu->regs[30] = PB_BASE + 0x222e44ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_222e24;
L_222e48:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_222dec;
    cpu->regs[30] = PB_BASE + 0x222e58ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_222dec;
L_222e5c:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1544ULL;
    cpu->regs[30] = PB_BASE + 0x222e70ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_222d60;
L_222e7c:
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x222e84ULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x222e8cULL; PB_CALL(167, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
L_222e90:
    cpu->regs[20] = 4294967295ULL;
    goto L_222da0;
    /* nop */
    /* nop */
    SP += -112; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_22323c;
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[1] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x222ee4ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0x11e0a4ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_222f00;
L_222eec:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_223068;
L_222f00:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x222f08ULL; PB_CALL(169, cpu, tlb, PB_BASE + 0x12a000ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_222eec;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x222f18ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2231b0;
    if ((cpu->regs[22])==0) goto L_222ff8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[1] = cpu->regs[1] + 984ULL;
    cpu->regs[30] = PB_BASE + 0x222f34ULL; PB_CALL(171, cpu, tlb, PB_BASE + 0x11d200ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_223078;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_223294;
L_222f50:
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[27] = 0ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[26] + 16));
    FLAG_CMP(cpu->regs[22], cpu->regs[4]);
    if (FLAG_GT) goto L_2232ec;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2520));
    cpu->regs[28] = cpu->regs[26] + 24ULL;
    PB_STR((SP + 104), cpu->regs[0]);
L_222f74:
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[24];
    FLAG_CMP(cpu->regs[27], cpu->regs[22]);
    if (FLAG_GE) goto L_222fe0;
    PB_LDR(cpu->regs[3], (cpu->regs[28] + (cpu->regs[27] << 3)));
    PB_LDR(cpu->regs[5], (SP + 104));
    PB_LDR(cpu->regs[6], (cpu->regs[3] + 8));
    FLAG_CMP(cpu->regs[6], cpu->regs[5]);
    if (FLAG_NE) goto L_2232bc;
    cpu->regs[30] = PB_BASE + 0x222fa4ULL; PB_CALL(172, cpu, tlb, PB_BASE + 0x255c00ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_STR((SP + 96), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[2];
    if ((cpu->regs[2])==0) goto L_2232e4;
    cpu->regs[30] = PB_BASE + 0x222fbcULL; PB_CALL(173, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[2], (SP + 96));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22326c;
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_222fd8;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_223174;
L_222fd8:
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    goto L_222f74;
L_222fe0:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_222fe4:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_222ff8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_223228;
L_222ff8:
    cpu->regs[22] = 0ULL;
L_222ffc:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 16));
    FLAG_CMP(cpu->regs[22], cpu->regs[0]);
    if (FLAG_LT) goto L_223130;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x223010ULL; PB_CALL(174, cpu, tlb, PB_BASE + 0xdc740ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_223038;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_223038;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x223038ULL; PB_CALL(175, cpu, tlb, cpu->regs[1]);
L_223038:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22325c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22325c;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x22305cULL; PB_CALL(176, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_223068:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 112;
    return;
L_223078:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3368));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x22308cULL; PB_CALL(177, cpu, tlb, PB_BASE + 0x121d80ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_2230d4;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x223098ULL; PB_CALL(178, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    cpu->regs[30] = PB_BASE + 0x22309cULL; PB_CALL(179, cpu, tlb, PB_BASE + 0xdb548ULL);
    cpu->regs[26] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 168));
    if (!((cpu->regs[1] >> 22) & 1)) goto L_222f50;
    FLAG_CMP(cpu->regs[22], 1ULL);
    if (FLAG_GT) goto L_2231f4;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2230bcULL; PB_CALL(180, cpu, tlb, PB_BASE + 0xe548cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_222fe4;
L_2230c0:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2230d4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_22319c;
L_2230d4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2230f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2230f8;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x2230f8ULL; PB_CALL(181, cpu, tlb, cpu->regs[1]);
L_2230f8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_222eec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_222eec;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[21];
L_223114:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x223120ULL; PB_CALL(182, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_223068;
L_223130:
    cpu->regs[3] = cpu->regs[25] + 24ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + (cpu->regs[22] << 3)));
    cpu->regs[30] = PB_BASE + 0x22314cULL; PB_CALL(183, cpu, tlb, PB_BASE + 0x255c00ULL);
    cpu->regs[26] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[21];
    if ((cpu->regs[26])==0) goto L_2230d4;
    cpu->regs[30] = PB_BASE + 0x223160ULL; PB_CALL(184, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_22318c;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2231d0;
L_22316c:
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_222ffc;
L_223174:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x223188ULL; PB_CALL(185, cpu, tlb, cpu->regs[1]);
    goto L_222f74;
L_22318c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_2230d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2230d4;
L_22319c:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 8));
    cpu->regs[0] = cpu->regs[26];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x2231acULL; PB_CALL(186, cpu, tlb, cpu->regs[1]);
    goto L_2230d4;
L_2231b0:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_222eec;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_222eec;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[23];
    goto L_223114;
L_2231d0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22316c;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 8));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x2231f0ULL; PB_CALL(187, cpu, tlb, cpu->regs[1]);
    goto L_222ffc;
L_2231f4:
    cpu->regs[5] = PB_BASE + 0x299000ULL;
    cpu->regs[5] = cpu->regs[5] + 240ULL;
    cpu->regs[4] = 1ULL;
L_223200:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[6] = cpu->regs[22];
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] + 1752ULL;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x223224ULL; PB_CALL(188, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_2230c0;
L_223228:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 8));
    cpu->regs[0] = cpu->regs[26];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x223238ULL; PB_CALL(189, cpu, tlb, cpu->regs[1]);
    goto L_222ff8;
L_22323c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[19] = 0ULL;
    cpu->regs[2] = cpu->regs[2] + 1664ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x223258ULL; PB_CALL(190, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_223068;
L_22325c:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_223068;
L_22326c:
    if (((cpu->regs[1] >> 31) & 1)) goto L_2232e4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2232e4;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x22328cULL; PB_CALL(191, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_2230c0;
L_223294:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 24));
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    cpu->regs[2] = cpu->regs[2] + 1704ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x2232b8ULL; PB_CALL(192, cpu, tlb, PB_BASE + 0x225d40ULL);
    goto L_2230c0;
L_2232bc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[3], (cpu->regs[6] + 24));
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[2] = cpu->regs[2] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0x2232dcULL; PB_CALL(193, cpu, tlb, PB_BASE + 0x225d40ULL);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_2230c0;
L_2232e4:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_2230c0;
L_2232ec:
    FLAG_CMP(cpu->regs[4], 1ULL);
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[5] = PB_BASE + 0x292000ULL;
    cpu->regs[0] = cpu->regs[0] + 240ULL;
    cpu->regs[5] = cpu->regs[5] + 1000ULL;
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    cpu->regs[5] = (FLAG_NE) ? cpu->regs[5] : cpu->regs[0];
    goto L_223200;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 28) & 1)) goto L_223368;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[3] = 9223372036854775807ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x22333cULL; PB_CALL(194, cpu, tlb, PB_BASE + 0x1405a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_223350;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(195, cpu, tlb, PB_BASE + 0x1c5c40ULL); return; };
L_223350:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(196, cpu, tlb, PB_BASE + 0x134b80ULL); return; };
L_223368:
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = PB_BASE + 0x2ab000ULL;
    cpu->regs[2] = cpu->regs[2] + 3632ULL;
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[0] = PB_BASE + 0x298000ULL;
    cpu->regs[0] = cpu->regs[0] + 1984ULL;
    cpu->regs[30] = PB_BASE + 0x223388ULL; PB_CALL(197, cpu, tlb, PB_BASE + 0x23b310ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    SP = SP - 32ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[0] = SP;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x2233ccULL; PB_CALL(198, cpu, tlb, PB_BASE + 0x7bd10ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_223404;
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[30] = PB_BASE + 0x2233d8ULL; PB_CALL(199, cpu, tlb, PB_BASE + 0x21c820ULL);
L_2233d8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_223400;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_223400:
    cpu->regs[30] = PB_BASE + 0x223404ULL; PB_CALL(200, cpu, tlb, PB_BASE + 0x7c170ULL);
L_223404:
    cpu->regs[0] = 0ULL;
    goto L_2233d8;
}
