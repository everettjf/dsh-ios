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

void ft__PyErr_SetObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_120858;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_120b98;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 30) & 1)) goto L_120b98;
L_120858:
    if ((cpu->regs[19])==0) goto L_120950;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 30) & 1)) goto L_1209e8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_120950;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[21] + 96), 0ULL);
    if ((cpu->regs[0])==0) goto L_120914;
L_120884:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_120898;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_120960;
L_120898:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1208a4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x120c24ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_120afc;
    if ((cpu->regs[19])!=0) goto L_120928;
L_1208b0:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 104));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_120978;
L_1208cc:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])!=0) goto L_120968;
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_120978;
L_1208e0:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 30) & 1)) goto L_120b90;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 40));
    if ((cpu->regs[3])!=0) goto L_1209d4;
L_1208f4:
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_120a2c;
L_120900:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x121b40ULL); return; };
L_120914:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x120920ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x120c24ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_120afc;
L_120928:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1208b0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1208b0;
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x120948ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    goto L_1208b0;
L_120950:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    PB_STR((cpu->regs[21] + 96), 0ULL);
    if ((cpu->regs[0])!=0) goto L_120884;
    goto L_120898;
L_120960:
    cpu->regs[30] = PB_BASE + 0x120964ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_120898;
L_120968:
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1208cc;
L_120978:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_120988;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_120988:
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    if (FLAG_EQ) goto L_120a68;
    cpu->regs[22] = cpu->regs[20];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[20];
    cpu->regs[24] = 0ULL;
L_1209a0:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1209acULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1b3890ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 72));
    if ((cpu->regs[0])!=0) goto L_120a34;
L_1209b8:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 48));
    PB_STR((cpu->regs[2] + 48), cpu->regs[20]);
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1209c8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_1208e0;
L_1209d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1208f4;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    goto L_1208f4;
L_1209e8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1209f0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x136260ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_120aec;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_120a04;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_120a04:
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_120950;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 104));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[20], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1208cc;
    goto L_120978;
L_120a2c:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_120900;
L_120a34:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_120a48;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_120ac4;
L_120a48:
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_EQ) goto L_120ad4;
    FLAG_CMP(cpu->regs[23], cpu->regs[19]);
    if (FLAG_EQ) goto L_1209b8;
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_120a90;
L_120a5c:
    cpu->regs[24] = ((uint32_t)(cpu->regs[24] ^ 1ULL));
    cpu->regs[22] = cpu->regs[19];
    goto L_1209a0;
L_120a68:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1208e0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1208e0;
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x120a88ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    goto L_1208e0;
L_120a90:
    cpu->regs[0] = cpu->regs[23];
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x120a9cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1b3890ULL);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[2], (SP + 72));
    if (((cpu->regs[1] >> 31) & 1)) goto L_120a5c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_120a5c;
    cpu->regs[30] = PB_BASE + 0x120abcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    goto L_120a5c;
L_120ac4:
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x120accULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    goto L_120a48;
L_120ad4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 48));
    PB_STR((cpu->regs[22] + 48), 0ULL);
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x120ae4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[2], (SP + 72));
    goto L_1209b8;
L_120aec:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_120afc:
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[23], (cpu->regs[21] + 96));
    PB_STR((cpu->regs[21] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x120b10ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x14d650ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_120bc4;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
L_120b1c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = cpu->regs[0] + 448ULL;
    cpu->regs[30] = PB_BASE + 0x120b30ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_120b48;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_120c0c;
L_120b48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x120b50ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18d760ULL);
    if ((cpu->regs[20])==0) goto L_120b74;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x120b60ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x24c624ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_120b74;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_120c18;
L_120b74:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    PB_STR((cpu->regs[21] + 96), cpu->regs[23]);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(18, cpu, tlb, PB_BASE + 0x18d760ULL); return; };
L_120b90:
    cpu->regs[3] = 0ULL;
    goto L_1208f4;
L_120b98:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2936));
    cpu->regs[3] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = PB_BASE + 0x289000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[2] + 336ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x225d40ULL); return; };
L_120bc4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    PB_STR((cpu->regs[21] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x120bd0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = cpu->regs[0] + 400ULL;
    cpu->regs[30] = PB_BASE + 0x120bdcULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 24));
    if ((cpu->regs[0])!=0) goto L_120b1c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    PB_STR((cpu->regs[21] + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x120bf4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = PB_BASE + 0x289000ULL;
    cpu->regs[0] = cpu->regs[0] + 416ULL;
    cpu->regs[30] = PB_BASE + 0x120c04ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    goto L_120b48;
L_120c0c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x120c14ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_120b48;
L_120c18:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x120c20ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_120b74;
L_120c24:
    SP = SP - 48ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[3]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_120cb4;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (((cpu->regs[2] >> 26) & 1)) goto L_120d6c;
    cpu->regs[30] = PB_BASE + 0x120c70ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_120d30;
L_120c78:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 30) & 1)) goto L_120d88;
L_120c84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_120d80;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_120cb4:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x120cc8ULL; PB_CALL(27, cpu, tlb, cpu->regs[3]);
    cpu->regs[1] = cpu->tls_ptr;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 168));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + cpu->regs[0]));
    if (!((cpu->regs[3] >> 11) & 1)) goto L_120d10;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 56));
    cpu->regs[2] = SP + 8ULL;
    cpu->regs[1] = SP;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[3];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_HI) { FLAG_CMP(cpu->regs[1], cpu->regs[0]); } else { FLAG_CMP(1, 0); }
    if (FLAG_LO) goto L_120d84;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_120d08;
    cpu->regs[0] = cpu->regs[0] + 8ULL;
    FLAG_CMP(SP, cpu->regs[0]);
    if (FLAG_LO) goto L_120d84;
L_120d08:
    PB_LDR(cpu->regs[4], (cpu->regs[20] + cpu->regs[3]));
    if ((cpu->regs[4])!=0) goto L_120d38;
L_120d10:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x120d28ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xea120ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_120c78;
L_120d30:
    cpu->regs[19] = 0ULL;
    goto L_120c84;
L_120d38:
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x120d4cULL; PB_CALL(29, cpu, tlb, cpu->regs[4]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x120d60ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe8888ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_120c78;
    goto L_120d30;
L_120d6c:
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x120d74ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x7c1e0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[19])!=0) goto L_120c78;
    goto L_120d30;
L_120d80:
    cpu->regs[30] = PB_BASE + 0x120d84ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x7c170ULL);
L_120d84:
    __builtin_trap();
L_120d88:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2736));
    cpu->regs[2] = cpu->regs[20];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[1] = cpu->regs[1] + 488ULL;
    cpu->regs[30] = PB_BASE + 0x120da8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_120d30;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_120d30;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x120dc8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_120c84;
}
