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

void ft__PyLong_Lshift(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_2738a4;
    cpu->regs[3] = 30ULL;
    cpu->regs[1] = (cpu->regs[3] ? cpu->regs[2] / cpu->regs[3] : 0);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - cpu->regs[1] * cpu->regs[3]));
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x12db60ULL); return; };
L_2738a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 3208ULL;
    return;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_273a14;
L_2738e4:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_2739bc;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if ((cpu->regs[0])==0) goto L_2739bc;
    cpu->regs[30] = PB_BASE + 0x2738f8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x123ed0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_273a30;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_2739b4;
    cpu->regs[30] = PB_BASE + 0x273914ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x134ae0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2739e8;
L_273920:
    if ((cpu->regs[22])==0) goto L_273a30;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[0] = cpu->regs[19] + 3528ULL;
    cpu->regs[30] = PB_BASE + 0x273940ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x15c044ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_273a50;
L_27394c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 3528));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_273a38;
L_273954:
    if ((cpu->regs[21])==0) goto L_273a30;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x273964ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x259f24ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2739d0;
L_273970:
    if ((cpu->regs[19])==0) goto L_273a30;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x273980ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1b07c0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_2739a0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2739a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2739a0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2739a0:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_2739b4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_273a00;
L_2739bc:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0x16de80ULL); return; };
L_2739d0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_273970;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2739e4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_273970;
L_2739e8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_273920;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x2739fcULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_273920;
L_273a00:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2739bc;
    cpu->regs[30] = PB_BASE + 0x273a10ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_2739bc;
L_273a14:
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 848ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x273a2cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2738e4;
L_273a30:
    cpu->regs[20] = 0ULL;
    goto L_2739a0;
L_273a38:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 3528), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_273954;
    cpu->regs[0] = cpu->regs[19] + 3528ULL;
    cpu->regs[30] = PB_BASE + 0x273a4cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_273954;
L_273a50:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_27394c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x273a64ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_27394c;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_273b88;
L_273a90:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_GT) goto L_273c54;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_273aa0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[30] = PB_BASE + 0x273aa8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x230c8cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_273ba4;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 24) & 1)) goto L_273c30;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_NE) goto L_273c08;
L_273acc:
    cpu->regs[25] = 18446744073709551615ULL;
L_273ad0:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x273ad8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_273bdc;
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 16)); PB_LDR(cpu->regs[0], (cpu->regs[21] + 16) + 8);
    FLAG_CMP(cpu->regs[25], 0ULL);
    cpu->regs[26] = (FLAG_GT) ? 1 : 0;
    cpu->regs[23] = 0ULL;
    cpu->regs[22] = cpu->regs[22] + 32ULL;
    cpu->regs[22] = cpu->regs[22] + cpu->regs[0];
    goto L_273b50;
L_273afc:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    cpu->regs[2] = cpu->regs[2] + cpu->regs[19];
    PB_STR((cpu->regs[21] + 24), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x273b0cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[24];
    if ((cpu->regs[20])==0) goto L_273bc8;
    cpu->regs[30] = PB_BASE + 0x273b20ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_273bb8;
    cpu->regs[0] = cpu->regs[1] - 1ULL;
    if (((cpu->regs[1] >> 31) & 1)) goto L_273b3c;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_273bac;
L_273b3c:
    cpu->regs[23] = cpu->regs[23] + cpu->regs[19];
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(0ULL)));
    cpu->regs[22] = cpu->regs[22] + cpu->regs[19];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[23], cpu->regs[25]); } else { FLAG_CMP(0, 1); }
    if (FLAG_GE) goto L_273b6c;
L_273b50:
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x273b5cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x230ca0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    if ((cpu->regs[19])!=0) goto L_273afc;
L_273b6c:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_273b70:
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_273b88:
    cpu->regs[0] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3272ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x273ba0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_273a90;
L_273ba4:
    cpu->regs[24] = 0ULL;
    goto L_273b70;
L_273bac:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x273bb4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_273b3c;
L_273bb8:
    if (((cpu->regs[1] >> 31) & 1)) goto L_273bc8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_273be8;
L_273bc8:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_273bdc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_273bf4;
L_273bdc:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_273be0:
    cpu->regs[24] = 0ULL;
    goto L_273b70;
L_273be8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x273bf0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_273bc8;
L_273bf4:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[24] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x273c00ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_273b70;
L_273c08:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[24] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x273c28ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_273b70;
L_273c30:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x273c38ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe5240ULL);
    cpu->regs[25] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_273ad0;
    cpu->regs[30] = PB_BASE + 0x273c48ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_273acc;
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_273be0;
L_273c54:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 0));
    goto L_273aa0;
    /* nop */
}
