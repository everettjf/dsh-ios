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

void ft_PyType_FromMetaclass(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x18d7a4ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if ((cpu->regs[0])==0) goto L_1dfb98;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1dfb94ULL; PB_CALL(2, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfb98:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    if ((cpu->regs[0])==0) goto L_1dfbac;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfba8ULL; PB_CALL(3, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfbac:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_1dfbc0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfbbcULL; PB_CALL(4, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfbc0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_1dfbd4;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfbd0ULL; PB_CALL(5, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfbd4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_1dfbe8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfbe4ULL; PB_CALL(6, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfbe8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    if ((cpu->regs[0])==0) goto L_1dfbfc;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfbf8ULL; PB_CALL(7, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfbfc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 48));
    if ((cpu->regs[0])==0) goto L_1dfc10;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfc0cULL; PB_CALL(8, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfc10:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 56));
    if ((cpu->regs[0])==0) goto L_1dfc24;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfc20ULL; PB_CALL(9, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfc24:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 64));
    if ((cpu->regs[0])==0) goto L_1dfc38;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfc34ULL; PB_CALL(10, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfc38:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 72));
    if ((cpu->regs[0])==0) goto L_1dfc4c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfc48ULL; PB_CALL(11, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfc4c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 80));
    if ((cpu->regs[0])==0) goto L_1dfc60;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfc5cULL; PB_CALL(12, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfc60:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 88));
    if ((cpu->regs[0])==0) goto L_1dfc74;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfc70ULL; PB_CALL(13, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfc74:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    if ((cpu->regs[0])==0) goto L_1dfc88;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfc84ULL; PB_CALL(14, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfc88:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 104));
    if ((cpu->regs[0])==0) goto L_1dfc9c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfc98ULL; PB_CALL(15, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfc9c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 112));
    if ((cpu->regs[0])==0) goto L_1dfcb0;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfcacULL; PB_CALL(16, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfcb0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 120));
    if ((cpu->regs[0])==0) goto L_1dfcc4;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfcc0ULL; PB_CALL(17, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfcc4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 128));
    if ((cpu->regs[0])==0) goto L_1dfcd8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfcd4ULL; PB_CALL(18, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfcd8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 136));
    if ((cpu->regs[0])==0) goto L_1dfcec;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfce8ULL; PB_CALL(19, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfcec:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 144));
    if ((cpu->regs[0])==0) goto L_1dfd00;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfcfcULL; PB_CALL(20, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfd00:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 152));
    if ((cpu->regs[0])==0) goto L_1dfd14;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfd10ULL; PB_CALL(21, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfd14:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 160));
    if ((cpu->regs[0])==0) goto L_1dfd28;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfd24ULL; PB_CALL(22, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfd48;
L_1dfd28:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    if ((cpu->regs[0])==0) goto L_1dfd48;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1dfd48:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    /* nop */
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    cpu->regs[29] = SP;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[3]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1dfdb8;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_1dfdc8;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STRW((cpu->regs[2] + 136), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 112));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_1dfda4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[3]);
L_1dfda4:
    PB_STR((cpu->regs[2] + 112), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1dfdacULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
L_1dfdb0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1dfdb8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 112));
    cpu->regs[1] = 0ULL;
    PB_STRW((cpu->regs[2] + 136), 0ULL);
    goto L_1dfda4;
L_1dfdc8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 1256ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1dfde0ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1dfdb0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 120));
    if ((cpu->regs[0])!=0) goto L_1dfdf4;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0xdb548ULL); return; };
L_1dfdf4:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1dfe04;
    return;
L_1dfe04:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if ((cpu->regs[0])==0) goto L_1dfe3c;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1dfe38ULL; PB_CALL(26, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfe98;
L_1dfe3c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    if ((cpu->regs[0])==0) goto L_1dfe50;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfe4cULL; PB_CALL(27, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfe98;
L_1dfe50:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_1dfe64;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfe60ULL; PB_CALL(28, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfe98;
L_1dfe64:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_1dfe78;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1dfe74ULL; PB_CALL(29, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dfe98;
L_1dfe78:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_1dfe98;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1dfe98:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[1])==0) goto L_1dfee8;
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_1dfee8;
    PB_LDRW(cpu->regs[3], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 120));
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_NE) goto L_1dff08;
L_1dfed4:
    PB_STR((cpu->regs[2] + 120), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1dfedcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
L_1dfee0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1dfee8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 1304ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1dff00ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1dfee0;
L_1dff08:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[3]);
    goto L_1dfed4;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x1dff28ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1d47c8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1dff7c;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dff70;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x1dff3cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d47c8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1dff7c;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dff70;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1dff50ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d47c8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1dff7c;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1dff70;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_1dff64:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1dff70:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_1dff64;
L_1dff7c:
    cpu->regs[0] = 0ULL;
    goto L_1dff64;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_1dffc0;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[1] + 16), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_1dffc0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1dffc0;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1dffb4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1dffc0:
    cpu->regs[0] = 0ULL;
    return;
}
