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

void ft_PyNumber_InPlaceLshift(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 96));
    PB_STR((SP + 32), cpu->regs[21]);
    if ((cpu->regs[2])==0) goto L_16aecc;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 192));
    if ((cpu->regs[2])!=0) goto L_16af04;
L_16aecc:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2400));
L_16aed4:
    cpu->regs[2] = 88ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16aee4ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_EQ) goto L_16af38;
L_16aef0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_16af04:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2400));
    cpu->regs[30] = PB_BASE + 0x16af10ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_16aef0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_16aed4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_16aed4;
    cpu->regs[30] = PB_BASE + 0x16af34ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16aed4;
L_16af38:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[2] = cpu->regs[2] + 3952ULL;
    cpu->regs[30] = PB_BASE + 0x16af4cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1ac810ULL);
    cpu->regs[2] = 0ULL;
    goto L_16aef0;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 8));
    if ((cpu->regs[19])==0) goto L_16b1b4;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_16b0f8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_16b0c4;
L_16afa0:
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 16));
    if ((cpu->regs[19])==0) goto L_16afb4;
L_16afa8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (((cpu->regs[1] >> 14) & 1)) goto L_16b0a8;
L_16afb4:
    PB_LDRW(cpu->regs[4], (cpu->regs[21] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_16b164;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    cpu->regs[19] = 0ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_NE) goto L_16b060;
    cpu->regs[22] = PB_BASE + 0xe2000ULL;
    cpu->regs[22] = cpu->regs[22] + 1792ULL;
    goto L_16afec;
L_16afe0:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_LE) goto L_16b028;
L_16afec:
    cpu->regs[0] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 40));
    if ((cpu->regs[20])==0) goto L_16afe0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 14) & 1)) goto L_16afe0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_16b0e0;
L_16b00c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_16afe0;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    PB_STR((cpu->regs[20] + -8), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_GT) goto L_16afec;
L_16b028:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_16b034;
L_16b030:
    cpu->regs[30] = PB_BASE + 0x16b034ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x108700ULL);
L_16b034:
    cpu->regs[0] = 0ULL;
L_16b038:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_16b048:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_LE) goto L_16b088;
    /* nop */
    /* nop */
    /* nop */
L_16b060:
    cpu->regs[3] = cpu->regs[21] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    cpu->regs[1] = cpu->regs[22];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 40));
    if ((cpu->regs[0])==0) goto L_16b048;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    cpu->regs[30] = PB_BASE + 0x16b078ULL; PB_CALL(6, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b038;
    PB_LDRW(cpu->regs[4], (cpu->regs[21] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_LT) goto L_16b060;
L_16b088:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_16b034;
L_16b090:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[16] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_16b0a8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_16b144;
L_16b0b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_16afb4;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    goto L_16afb4;
L_16b0c4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 328));
    if ((cpu->regs[1])!=0) goto L_16b124;
L_16b0cc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    if (!((cpu->regs[0] >> 1) & 1)) goto L_16afa0;
    cpu->regs[0] = cpu->regs[0] - 4ULL;
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    goto L_16afa0;
L_16b0e0:
    FLAG_CMP(cpu->regs[1], cpu->regs[22]);
    if (FLAG_NE) goto L_16b180;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b00c;
    goto L_16afe0;
L_16b0f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x16b104ULL; PB_CALL(7, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b038;
    PB_LDR(cpu->regs[19], (cpu->regs[21] + 16));
    if ((cpu->regs[19])==0) goto L_16afb4;
L_16b110:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x16b11cULL; PB_CALL(8, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_16afb4;
    goto L_16b038;
L_16b124:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_16b1a4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b0cc;
    goto L_16afa0;
L_16b144:
    cpu->regs[0] = PB_BASE + 0xe2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1792ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_16b194;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 168));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 512ULL));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b0b0;
    goto L_16afb4;
L_16b164:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_16b034;
    cpu->regs[1] = PB_BASE + 0x108000ULL;
    cpu->regs[1] = cpu->regs[1] + 1664ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_NE) goto L_16b090;
    goto L_16b030;
L_16b180:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16b188ULL; PB_CALL(9, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[4], (cpu->regs[21] + 24));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b00c;
    goto L_16afe0;
L_16b194:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16b19cULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b0b0;
    goto L_16afb4;
L_16b1a4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16b1acULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b0cc;
    goto L_16afa0;
L_16b1b4:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    if ((cpu->regs[19])==0) goto L_16afb4;
    cpu->regs[0] = PB_BASE + 0x108000ULL;
    cpu->regs[0] = cpu->regs[0] + 1664ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_16b110;
    goto L_16afa8;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(17ULL)));
    if (FLAG_LS) goto L_16b1e0;
    cpu->regs[0] = 0ULL;
    return;
L_16b1e0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = PB_BASE + 0x2b5000ULL;
    cpu->regs[2] = cpu->regs[2] + 308ULL;
    cpu->regs[29] = SP;
    PB_LDRH(cpu->regs[2], (cpu->regs[2] + (((uint64_t)(uint32_t)(cpu->regs[0])) << 1)));
    cpu->regs[0] = PB_BASE + 0x16b200ULL;
    cpu->regs[2] = cpu->regs[0] + (((uint64_t)(int64_t)(int16_t)(cpu->regs[2])) << 2);
    prebuilt_call(cpu, tlb, cpu->regs[2]); return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_16b3c4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2568));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + ((uint64_t)(uint32_t)(cpu->regs[1]))));
L_16b214:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[0] = 1114111ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HI) goto L_16b430;
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] >> 7));
    cpu->regs[0] = PB_BASE + 0x35c000ULL;
    cpu->regs[0] = cpu->regs[0] + 1904ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 127ULL));
    cpu->regs[2] = PB_BASE + 0x34a000ULL;
    cpu->regs[2] = cpu->regs[2] + 3184ULL;
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + (cpu->regs[3] << 1)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + (cpu->regs[0] << 7)));
    PB_LDRH(cpu->regs[0], (cpu->regs[2] + (cpu->regs[0] << 1)));
L_16b24c:
    cpu->regs[1] = PB_BASE + 0x348000ULL;
    cpu->regs[1] = cpu->regs[1] + 3312ULL;
    cpu->regs[0] = cpu->regs[1] + (((cpu->regs[0]) & 0xffffULL) << 4);
    PB_LDRH(cpu->regs[0], (cpu->regs[0] + 14));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = ((cpu->regs[0] >> 1) & 0x1ULL);
    return;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(127ULL)));
    if (FLAG_HI) goto L_16b3d0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2568));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + ((uint64_t)(uint32_t)(cpu->regs[1]))));
L_16b27c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    goto L_16b214;
    cpu->regs[0] = cpu->regs[1];
    PB_STRW((SP + 28), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x16b294ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d3460ULL);
    PB_LDRW(cpu->regs[1], (SP + 28));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] & 1ULL));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] | cpu->regs[1]));
    goto L_16b214;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(32ULL)));
    if (FLAG_LS) goto L_16b3b0;
L_16b2b4:
    cpu->regs[0] = 0ULL;
    goto L_16b214;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(122ULL)));
    if (FLAG_HI) goto L_16b2b4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2272));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    goto L_16b214;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(57ULL)));
    if (FLAG_HI) goto L_16b3a8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2272));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[0] = ((cpu->regs[0] >> 2) & 0x1ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ 1ULL));
    goto L_16b214;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_16b2b4;
    cpu->regs[0] = cpu->regs[1];
    PB_STRW((SP + 28), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x16b318ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7bb70ULL);
    PB_LDRW(cpu->regs[1], (SP + 28));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    goto L_16b214;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16b334ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x14d120ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ 1ULL));
    goto L_16b214;
    cpu->regs[0] = cpu->regs[1];
    PB_STRW((SP + 28), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x16b348ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d3460ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ 1ULL));
    PB_LDRW(cpu->regs[1], (SP + 28));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & cpu->regs[1]));
    goto L_16b214;
    cpu->regs[0] = 1ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(32ULL)));
    if (FLAG_HI) goto L_16b214;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2272));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[0] = ((cpu->regs[0] >> 3) & 0x1ULL);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] ^ 1ULL));
    goto L_16b214;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(57ULL)));
    if (FLAG_HI) goto L_16b2b4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2272));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[0] = ((cpu->regs[0] >> 2) & 0x1ULL);
    goto L_16b214;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(122ULL)));
    if (FLAG_LS) goto L_16b3dc;
L_16b3a8:
    cpu->regs[0] = 1ULL;
    goto L_16b214;
L_16b3b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2272));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[0] = ((cpu->regs[0] >> 3) & 0x1ULL);
    goto L_16b214;
L_16b3c4:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x2546c0ULL); return; };
L_16b3d0:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16b3d8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x2546c0ULL);
    goto L_16b27c;
L_16b3dc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2272));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 2)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 7ULL));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    goto L_16b214;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16b404ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x24e3a0ULL);
    goto L_16b27c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(255ULL)));
    if (FLAG_HI) goto L_16b3a8;
    cpu->regs[0] = cpu->regs[1];
    PB_STRW((SP + 28), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x16b41cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7bb70ULL);
    PB_LDRW(cpu->regs[1], (SP + 28));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(95ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], 0ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    goto L_16b214;
L_16b430:
    cpu->regs[0] = 0ULL;
    goto L_16b24c;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(20, cpu, tlb, PB_BASE + 0x24e3a0ULL); return; };
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(10ULL)));
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    goto L_16b214;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(10ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    goto L_16b214;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[1])!=0) goto L_16b488;
    cpu->regs[1] = 0ULL;
L_16b478:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    goto L_16b4b0;
L_16b488:
    PB_STR((SP + 40), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x16b490ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x16b6c4ULL);
    PB_LDR(cpu->regs[2], (SP + 40));
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_16b478;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_16b4b0:
    SP = SP - 160ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    PB_STR((SP + 144), cpu->regs[21]); PB_STR((SP + 144) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_STR((SP + 104), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    FLAG_CMP(cpu->regs[20], cpu->regs[3]);
    if (FLAG_EQ) goto L_16b568;
    cpu->regs[19] = cpu->regs[21] + (cpu->regs[1] << 4);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 80));
    if (((cpu->regs[3] >> 63) & 1)) goto L_16b568;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_16b5a8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_16b658;
    if (!((cpu->regs[0] >> 6) & 1)) goto L_16b628;
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(40ULL)));
    if (FLAG_EQ) goto L_16b630;
L_16b520:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 88));
    PB_LDR(cpu->regs[5], (SP + 104));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    cpu->regs[5] = cpu->regs[5] - cpu->regs[4]; FLAG_CMP(cpu->regs[5], 0);
    cpu->regs[4] = 0ULL;
    if (FLAG_NE) goto L_16b638;
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    cpu->regs[2] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[2];
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    SP = SP + 160ULL;
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[3] : cpu->regs[1];
    { PB_CALL(22, cpu, tlb, PB_BASE + 0x134b80ULL); return; };
L_16b568:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_16b694;
L_16b574:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 104));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[1]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_16b638;
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
L_16b5a8:
    cpu->regs[22] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x16b5bcULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11e5ccULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16b66c;
    PB_LDR(cpu->regs[4], (SP + 24));
    PB_LDR(cpu->regs[1], (SP + 40));
    if ((cpu->regs[4])==0) goto L_16b69c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80)); PB_LDR(cpu->regs[5], (cpu->regs[19] + 80) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 24));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2392));
    PB_LDR(cpu->regs[6], (cpu->regs[2] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[0] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[0];
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    cpu->regs[1] = (FLAG_LE) ? cpu->regs[1] : cpu->regs[5];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[6], cpu->regs[3]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_16b63c;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_NE) goto L_16b63c;
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_16b664;
L_16b614:
    cpu->regs[0] = cpu->regs[22];
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x16b620ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x11ec60ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    goto L_16b574;
L_16b628:
    cpu->regs[0] = cpu->regs[20] + 56ULL;
    if ((cpu->regs[0])!=0) goto L_16b520;
L_16b630:
    cpu->regs[2] = 0ULL;
    goto L_16b574;
L_16b638:
    cpu->regs[30] = PB_BASE + 0x16b63cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7c170ULL);
L_16b63c:
    cpu->regs[1] = cpu->regs[1] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[4] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x16b648ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (SP + 24));
    if ((cpu->regs[1])!=0) goto L_16b614;
    goto L_16b574;
L_16b658:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    if ((cpu->regs[0])!=0) goto L_16b520;
    goto L_16b630;
L_16b664:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_16b614;
L_16b66c:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 4048ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x16b68cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[2] = 0ULL;
    goto L_16b574;
L_16b694:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_16b574;
L_16b69c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x16b6b4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x16b6bcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[2] = 0ULL;
    goto L_16b574;
L_16b6c4:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])==0) goto L_16b710;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    if ((cpu->regs[0])==0) goto L_16b710;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x16b6f4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x123dd0ULL);
L_16b6f4:
    if (((cpu->regs[0] >> 63) & 1)) goto L_16b738;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GE) goto L_16b738;
L_16b704:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_16b710:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    if ((cpu->regs[0])==0) goto L_16b738;
    cpu->regs[30] = PB_BASE + 0x16b720ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe27c8ULL);
    if ((cpu->regs[0])==0) goto L_16b738;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_16b738;
    cpu->regs[30] = PB_BASE + 0x16b734ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xe5240ULL);
    goto L_16b6f4;
L_16b738:
    cpu->regs[30] = PB_BASE + 0x16b73cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_16b758;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[1] + 832ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x16b758ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_16b758:
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_16b704;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_16b83c;
    if ((cpu->regs[2])!=0) goto L_16b860;
L_16b788:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 88));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_16b888;
L_16b794:
    cpu->regs[1] = cpu->regs[0] + 5ULL;
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[1], 261ULL);
    if (FLAG_HI) goto L_16b7cc;
L_16b7a4:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 5ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[0] = ((cpu->regs[0] & 0xffffffffULL) << 5);
    cpu->regs[0] = cpu->regs[0] + 3048ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_16b7bc:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_16b7cc:
    if (((cpu->regs[0] >> 63) & 1)) goto L_16b830;
    cpu->regs[21] = 0ULL;
L_16b7d4:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 0ULL;
L_16b7dc:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    cpu->regs[1] = cpu->regs[1] >> 30;
    if ((cpu->regs[1])!=0) goto L_16b7dc;
    cpu->regs[20] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16b7f4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_16b898;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    cpu->regs[2] = 4294967295ULL;
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : (0ULL + 1);
    cpu->regs[1] = 1ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - cpu->regs[2]));
    cpu->regs[2] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[20] = cpu->regs[1] | (cpu->regs[20] << 3);
    PB_STR((cpu->regs[0] + 16), cpu->regs[20]);
L_16b81c:
    cpu->regs[1] = ((uint32_t)(cpu->regs[19] & 1073741823ULL));
    PB_STRW(cpu->regs[2], cpu->regs[1]); cpu->regs[2] += 4;
    cpu->regs[19] = cpu->regs[19] >> 30;
    if ((cpu->regs[19])==0) goto L_16b7bc;
    goto L_16b81c;
L_16b830:
    cpu->regs[19] = (uint64_t)(-(int64_t)cpu->regs[0]);
    cpu->regs[21] = 1ULL;
    goto L_16b7d4;
L_16b83c:
    cpu->regs[0] = PB_BASE + 0x2b1000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 2656ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x16b854ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_16b898;
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_16b788;
L_16b860:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if ((cpu->regs[1])==0) goto L_16b788;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16b870ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x16b6c4ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_16b888;
    cpu->regs[0] = cpu->regs[20] + (cpu->regs[0] << 4);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 88));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_16b794;
L_16b888:
    cpu->regs[30] = PB_BASE + 0x16b88cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_16b898;
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_16b7a4;
L_16b898:
    cpu->regs[0] = 0ULL;
    goto L_16b7bc;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + -16));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    if ((cpu->regs[2])==0) goto L_16b93c;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + -8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[3] = cpu->regs[3] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    PB_STR((cpu->regs[2] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[19] + -16), 0ULL); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_16b944;
L_16b8ec:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_16b944;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_16b944;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x16b910ULL; PB_CALL(39, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16b91cULL; PB_CALL(40, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_16b930;
L_16b924:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_16b95c;
L_16b930:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_16b93c:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])!=0) goto L_16b8ec;
L_16b944:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16b950ULL; PB_CALL(41, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_16b924;
    goto L_16b930;
L_16b95c:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    SP = SP - 48ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_16bafc;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20));
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_16baa4;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 192));
    PB_STRB((cpu->regs[0] + 95), 0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 120));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_16ba2c;
    cpu->regs[1] = 18446744073709551615ULL;
    cpu->regs[30] = PB_BASE + 0x16b9c8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x157be4ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_16ba20;
L_16b9d0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_16ba08;
L_16b9d8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_16ba28;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_16ba08:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_16bae4;
L_16ba10:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 152));
    if ((cpu->regs[0])!=0) goto L_16bac4;
L_16ba18:
    PB_LDRB(cpu->regs[0], (cpu->regs[19] + 93));
    PB_STRB((cpu->regs[19] + 95), cpu->regs[0]);
L_16ba20:
    cpu->regs[20] = 0ULL;
    goto L_16b9d8;
L_16ba28:
    cpu->regs[30] = PB_BASE + 0x16ba2cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x7c170ULL);
L_16ba2c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 54976ULL;
    cpu->regs[1] = SP;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x16ba50ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x147564ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_16ba20;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_16b9d0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x16ba80ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_16ba20;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_16ba20;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x16baa0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16b9d8;
L_16baa4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x16bac0ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_16b9d8;
L_16bac4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 152), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_16ba18;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_16ba18;
    cpu->regs[30] = PB_BASE + 0x16bae0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16ba18;
L_16bae4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_16ba10;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x16baf8ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16ba10;
L_16bafc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x16bb18ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_16b9d8;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + -16));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    if ((cpu->regs[2])==0) goto L_16bb64;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + -8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[3] = cpu->regs[3] & 18446744073709551612ULL;
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_STR((cpu->regs[3] + 0), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[1] | cpu->regs[3];
    PB_STR((cpu->regs[2] + 8), cpu->regs[1]);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[0] + -16), 0ULL); PB_STR((cpu->regs[0] + -16) + 8, cpu->regs[1]);
L_16bb64:
    cpu->regs[30] = PB_BASE + 0x16bb68ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x16bba0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x16bb70ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_16bb84;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_16bb90;
L_16bb84:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_16bb90:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_16bba0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_16bbd0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[20] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_16bbd0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_16bcbc;
L_16bbd0:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_16bc04;
    cpu->regs[19] = 0ULL;
L_16bbe0:
    cpu->regs[2] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 40));
    if ((cpu->regs[1])==0) goto L_16bbf8;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[2] + 40), 0ULL);
    if (!((cpu->regs[3] >> 31) & 1)) goto L_16bca0;
L_16bbf8:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_GT) goto L_16bbe0;
L_16bc04:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 32));
    PB_STR((cpu->regs[20] + 32), 0ULL);
    if ((cpu->regs[1])==0) goto L_16bc70;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_16bc80;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 48));
    PB_STR((cpu->regs[1] + 0), 0ULL);
    PB_STR((cpu->regs[1] + 32), 0ULL);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16bc38ULL; PB_CALL(55, cpu, tlb, cpu->regs[2]);
    cpu->regs[1] = cpu->regs[19];
    if ((cpu->regs[19])==0) goto L_16bc70;
L_16bc40:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_NE) goto L_16bc80;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_STR((cpu->regs[1] + 0), 0ULL);
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 32));
    PB_STR((cpu->regs[1] + 32), 0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 48));
    cpu->regs[30] = PB_BASE + 0x16bc68ULL; PB_CALL(56, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[19];
    if ((cpu->regs[19])!=0) goto L_16bc40;
L_16bc70:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_16bc80:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_16bc70;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_16bc70;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16bc9cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16bc70;
L_16bca0:
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[3]);
    if ((cpu->regs[3])!=0) goto L_16bbf8;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x16bcb4ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 24));
    goto L_16bbf8;
L_16bcbc:
    cpu->regs[30] = PB_BASE + 0x16bcc0ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_16bbd0;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[6] = cpu->tls_ptr;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x16bcf8ULL; PB_CALL(60, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[20], (cpu->regs[6] + cpu->regs[0]));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    if (!((cpu->regs[0] >> 9) & 1)) goto L_16bd5c;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[3] = cpu->regs[5] & 9223372036854775807ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 56));
    cpu->regs[5] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[5]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_16bd78;
L_16bd24:
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 8));
    if ((cpu->regs[5])==0) goto L_16bda4;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 16));
    if (((cpu->regs[0] >> 5) & 1)) goto L_16bdac;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x16bd40ULL; PB_CALL(61, cpu, tlb, cpu->regs[5]);
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[1]);
L_16bd4c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_16bd5c:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 36));
    cpu->regs[3] = cpu->regs[5] & 9223372036854775807ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[5] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[5]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_16bd24;
L_16bd78:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    PB_STR((SP + 56), cpu->regs[3]); PB_STR((SP + 56) + 8, cpu->regs[2]);
    PB_STR((SP + 72), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x16bd90ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x26c444ULL);
    PB_LDR(cpu->regs[4], (SP + 72));
    PB_LDR(cpu->regs[3], (SP + 56)); PB_LDR(cpu->regs[2], (SP + 56) + 8);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_16bda4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    goto L_16bd24;
L_16bda4:
    cpu->regs[0] = 0ULL;
    goto L_16bd4c;
L_16bdac:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x16bdb8ULL; PB_CALL(63, cpu, tlb, cpu->regs[5]);
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[20] + 36), cpu->regs[1]);
    goto L_16bd4c;
}
