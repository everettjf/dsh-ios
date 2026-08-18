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

void ft_PyThread_tss_is_created(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    return;
    /* nop */
    /* nop */
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x18c7f8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])==0) goto L_18cb68;
L_18c7fc:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 336));
    cpu->regs[0] = 0ULL;
    cpu->regs[3] = cpu->regs[21] + 24ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 16));
L_18c80c:
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_LT) goto L_18c87c;
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_NE) goto L_18c8cc;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 344));
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x18c830ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18c8a8;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_18c848;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_18c848:
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[20] = cpu->regs[20] + 24ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[4] += 24; PB_STR(cpu->regs[4], cpu->regs[19]);
L_18c858:
    FLAG_CMP(cpu->regs[1], cpu->regs[21]);
    if (FLAG_GE) goto L_18c8ac;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + (cpu->regs[1] << 3)));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_NE) goto L_18c8c0;
    PB_STR((cpu->regs[4] + (cpu->regs[1] << 3)), cpu->regs[3]);
    goto L_18c858;
L_18c87c:
    PB_LDR(cpu->regs[2], (cpu->regs[3] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 344));
    if ((cpu->regs[1])!=0) goto L_18c80c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1136ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18c8a8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11f220ULL);
L_18c8a8:
    cpu->regs[22] = 0ULL;
L_18c8ac:
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_18c8c0:
    PB_STRW((cpu->regs[3] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[4] + (cpu->regs[1] << 3)), cpu->regs[3]);
    goto L_18c858;
L_18c8cc:
    cpu->regs[3] = cpu->regs[21] + 24ULL;
    cpu->regs[1] = 0ULL;
L_18c8d4:
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_LE) goto L_18c958;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + (cpu->regs[1] << 3)));
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    cpu->regs[2] = cpu->regs[1];
L_18c8e8:
    FLAG_CMP(cpu->regs[20], cpu->regs[2]);
    if (FLAG_EQ) goto L_18c8d4;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + (cpu->regs[2] << 3)));
    cpu->regs[2] = cpu->regs[2] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_NE) goto L_18c8e8;
    cpu->regs[30] = PB_BASE + 0x18c904ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xa6020ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18c8a8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_18cb7c;
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 1184ULL;
    cpu->regs[30] = PB_BASE + 0x18c934ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11f220ULL);
L_18c934:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18c8a8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18c8a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18c954ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18c8ac;
L_18c958:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[20] + 1ULL;
    cpu->regs[0] = 1152921504606846975ULL;
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_HI) goto L_18cb58;
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[24] << 3;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x18c97cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18cb54;
    cpu->regs[2] = cpu->regs[21] + 24ULL;
    cpu->regs[0] = 0ULL;
L_18c98c:
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_GE) goto L_18c9a8;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + (cpu->regs[0] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 344));
    PB_STR((cpu->regs[23] + (cpu->regs[0] << 3)), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_18c98c;
L_18c9a8:
    cpu->regs[1] = cpu->regs[23] + cpu->regs[25];
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[1] + -8), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x18c9b8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18cb3c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_18c9d0;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_18c9d0:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    cpu->regs[0] = cpu->regs[25];
    PB_STR((cpu->regs[1] + 0), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x18c9e0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[19])==0) goto L_18cb34;
L_18c9ec:
    FLAG_CMP(cpu->regs[24], cpu->regs[0]);
    if (FLAG_LE) goto L_18ca4c;
    PB_STR((cpu->regs[19] + (cpu->regs[0] << 3)), 0ULL);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_18c9ec;
L_18ca00:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x18ca0cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe548cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_18cb00;
    cpu->regs[3] = 0ULL;
L_18ca14:
    PB_LDR(cpu->regs[4], (cpu->regs[23] + (cpu->regs[3] << 3)));
    PB_LDR(cpu->regs[5], (cpu->regs[19] + (cpu->regs[3] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 16));
    cpu->regs[1] = cpu->regs[5] + 1ULL;
    cpu->regs[4] = cpu->regs[4] + (cpu->regs[5] << 3);
    FLAG_CMP(cpu->regs[5], cpu->regs[0]);
    if (FLAG_GE) goto L_18ca40;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 24));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_18ca40;
    PB_STR((cpu->regs[19] + (cpu->regs[3] << 3)), cpu->regs[1]);
L_18ca40:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[24], cpu->regs[3]);
    if (FLAG_GT) goto L_18ca14;
L_18ca4c:
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 0ULL;
L_18ca54:
    FLAG_CMP(cpu->regs[24], cpu->regs[6]);
    if (FLAG_LE) goto L_18cacc;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + (cpu->regs[6] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + (cpu->regs[6] << 3)));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_GE) goto L_18cac0;
    cpu->regs[0] = cpu->regs[1] + (cpu->regs[0] << 3);
    cpu->regs[4] = 0ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
L_18ca7c:
    PB_LDR(cpu->regs[5], (cpu->regs[23] + (cpu->regs[4] << 3)));
    PB_LDR(cpu->regs[3], (cpu->regs[19] + (cpu->regs[4] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 16));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
L_18ca8c:
    cpu->regs[2] = cpu->regs[5] + 24ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_GT) goto L_18caa8;
    cpu->regs[4] = cpu->regs[4] + 1ULL;
    FLAG_CMP(cpu->regs[24], cpu->regs[4]);
    if (FLAG_GT) goto L_18ca7c;
    goto L_18ca00;
L_18caa8:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + (cpu->regs[3] << 3)));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_18ca8c;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    goto L_18ca54;
L_18cac0:
    cpu->regs[7] = cpu->regs[7] + 1ULL;
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    goto L_18ca54;
L_18cacc:
    FLAG_CMP(cpu->regs[24], cpu->regs[7]);
    if (FLAG_NE) goto L_18caf0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18cadcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_18cadc:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x18cae4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_18c8ac;
L_18caf0:
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x18cb00ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xac000ULL);
L_18cb00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18cb08ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_18cb08:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18cb1c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18cb24;
L_18cb1c:
    cpu->regs[22] = 0ULL;
    goto L_18cadc;
L_18cb24:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18cb30ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18cadc;
L_18cb34:
    cpu->regs[30] = PB_BASE + 0x18cb38ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_18cb08;
L_18cb3c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x18cb48ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_18c8ac;
L_18cb54:
    PB_LDR(cpu->regs[25], (SP + 64));
L_18cb58:
    cpu->regs[30] = PB_BASE + 0x18cb5cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[22] = 0ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_18c8ac;
L_18cb68:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18cb70ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18e404ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18c7fc;
    cpu->regs[22] = 0ULL;
    goto L_18c8ac;
L_18cb7c:
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 1208ULL;
    cpu->regs[30] = PB_BASE + 0x18cb88ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_18c934;
    cpu->regs[2] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 1);
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[1] = (((uint64_t)(((int64_t)(cpu->regs[1] << 32)) >> 32) & 0xffffffffULL) << 1);
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + 192));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(254ULL)));
    if (FLAG_EQ) goto L_18cbd0;
L_18cba4:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(253ULL)));
    if (FLAG_EQ) goto L_18cbe0;
L_18cbac:
    cpu->regs[1] = PB_BASE + 0x2b7000ULL;
    cpu->regs[1] = cpu->regs[1] + 1840ULL;
    cpu->regs[0] = cpu->regs[1] + 1808ULL;
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + ((uint64_t)(uint32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18cbcc;
    cpu->regs[1] = cpu->regs[1] + 2064ULL;
    PB_LDRB(cpu->regs[0], (cpu->regs[1] + cpu->regs[3]));
L_18cbcc:
    return;
L_18cbd0:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 40));
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + cpu->regs[1]));
    goto L_18cba4;
L_18cbe0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + cpu->regs[3]));
    goto L_18cbac;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + -16)); PB_LDR(cpu->regs[2], (cpu->regs[0] + -16) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[3]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    PB_STR((cpu->regs[3] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[0] + -16), 0ULL); PB_STR((cpu->regs[0] + -16) + 8, cpu->regs[1]);
    return;
    /* nop */
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_18cc38;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    do { int8_t _s=0; tlb_read(tlb,(cpu->regs[0] + 32),&_s,1); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    return;
L_18cc38:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_18cc4c;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 1);
    do { int16_t _s=0; tlb_read(tlb,(cpu->regs[1] + 32),&_s,2); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    return;
L_18cc4c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_18cc60;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 2);
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[1] + 32),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    return;
L_18cc60:
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 32));
    return;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    if (((cpu->regs[2] >> 14) & 1)) goto L_18cc80;
    cpu->regs[0] = 0ULL;
    return;
L_18cc80:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 328));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[2])!=0) goto L_18ccb8;
L_18cc98:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_18cce4;
    cpu->regs[0] = 1ULL;
L_18ccac:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_18ccb8:
    cpu->regs[1] = PB_BASE + 0xe2000ULL;
    cpu->regs[1] = cpu->regs[1] + 1792ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_18ccf4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
L_18ccd0:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_18ccdc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    goto L_18cc98;
L_18ccdc:
    cpu->regs[0] = 0ULL;
    goto L_18ccac;
L_18cce4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -16));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    goto L_18ccac;
L_18ccf4:
    cpu->regs[30] = PB_BASE + 0x18ccf8ULL; PB_CALL(21, cpu, tlb, cpu->regs[2]);
    goto L_18ccd0;
    /* nop */
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 168));
    if (((cpu->regs[3] >> 14) & 1)) goto L_18cd14;
    cpu->regs[0] = 0ULL;
    return;
L_18cd14:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 328));
    if ((cpu->regs[2])!=0) goto L_18cd24;
    cpu->regs[0] = 1ULL;
    return;
L_18cd24:
    cpu->regs[3] = PB_BASE + 0xe2000ULL;
    cpu->regs[3] = cpu->regs[3] + 1792ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_18cd48;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    return;
L_18cd48:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x18cd54ULL; PB_CALL(22, cpu, tlb, cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = PB_BASE + 0x2b7000ULL;
    cpu->regs[3] = cpu->regs[3] + 1840ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[3] + 2600ULL;
    cpu->regs[30] = PB_BASE + 0x18cd90ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x187f84ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 1ULL;
    cpu->regs[2] = cpu->regs[21] * cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(24, cpu, tlb, PB_BASE + 0x17fe80ULL); return; };
    PB_LDRB(cpu->regs[3], (cpu->regs[0] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(7ULL)));
    if (FLAG_GT) goto L_18cdc4;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    PB_STRB((cpu->regs[0] + 32), cpu->regs[2]);
    return;
L_18cdc4:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_18cdd8;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 1);
    PB_STRH((cpu->regs[1] + 32), cpu->regs[2]);
    return;
L_18cdd8:
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(31ULL)));
    if (FLAG_GT) goto L_18cdec;
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 2);
    PB_STRW((cpu->regs[1] + 32), cpu->regs[2]);
    return;
L_18cdec:
    cpu->regs[1] = cpu->regs[0] + (cpu->regs[1] << 3);
    PB_STR((cpu->regs[1] + 32), cpu->regs[2]);
    return;
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x2b7000ULL;
    cpu->regs[2] = cpu->regs[2] + 1840ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[2] + 2624ULL;
    cpu->regs[30] = PB_BASE + 0x18ce24ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x187f84ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0xd7820ULL); return; };
    /* nop */
    /* nop */
}
