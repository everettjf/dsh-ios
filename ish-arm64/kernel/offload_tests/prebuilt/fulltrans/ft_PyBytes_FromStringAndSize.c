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

void ft_PyBytes_FromStringAndSize(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    if (((cpu->regs[1] >> 63) & 1)) goto L_e9d74;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_EQ) goto L_e9cec;
    if ((cpu->regs[1])==0) goto L_e9d28;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xe9ca8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe9da0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_e9d94;
    if ((cpu->regs[20])==0) goto L_e9d14;
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_HS) goto L_e9d4c;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[19];
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_LO) goto L_e9d5c;
L_e9ccc:
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe9cd8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_e9cdc:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_e9cec:
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = 11472ULL;
    cpu->regs[3] = 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[0] = cpu->regs[1] + (uint64_t)(uint32_t)cpu->regs[0] * (uint64_t)(uint32_t)cpu->regs[3];
    cpu->regs[21] = cpu->regs[0] + cpu->regs[2];
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_e9d68;
L_e9d14:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_e9d28:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 11432));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_e9d60;
L_e9d3c:
    cpu->regs[0] = 11432ULL;
    cpu->regs[21] = cpu->regs[21] + cpu->regs[0];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_e9cdc;
L_e9d4c:
    if (FLAG_LS) goto L_e9ccc;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[19];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_e9ccc;
L_e9d5c:
    __builtin_trap();
L_e9d60:
    PB_STRW((cpu->regs[21] + 11432), cpu->regs[0]);
    goto L_e9d3c;
L_e9d68:
    PB_STRW((cpu->regs[2] + cpu->regs[0]), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_e9cdc;
L_e9d74:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xe9d90ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_e9cdc;
L_e9d94:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[21] = 0ULL;
    goto L_e9cdc;
L_e9da0:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_e9e78;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 18446744073709551582ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_HI) goto L_e9eb0;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[19] + 33ULL;
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_e9e50;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 176)); PB_LDR(cpu->regs[2], (cpu->regs[21] + 176) + 8);
    cpu->regs[30] = PB_BASE + 0xe9de4ULL; PB_CALL(4, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])==0) goto L_e9e68;
L_e9de8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2392));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    PB_STR((cpu->regs[0] + 8), cpu->regs[1]);
    if (((cpu->regs[2] >> 9) & 1)) goto L_e9e30;
L_e9dfc:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 2708));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_e9ea0;
L_e9e04:
    cpu->regs[2] = 1ULL;
    cpu->regs[1] = 18446744073709551615ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]); PB_STR((cpu->regs[0] + 16) + 8, cpu->regs[1]);
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_e9e44;
    cpu->regs[19] = cpu->regs[0] + cpu->regs[19];
    PB_STRB((cpu->regs[19] + 32), 0ULL);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32));
L_e9e28:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_e9e30:
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_e9dfc;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
    goto L_e9dfc;
L_e9e44:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_e9e28;
L_e9e50:
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xe9e58ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x12c1a0ULL);
    if ((cpu->regs[0])==0) goto L_e9e68;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    goto L_e9de8;
L_e9e68:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x22d780ULL); return; };
L_e9e78:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 11432));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_e9ed4;
L_e9e90:
    cpu->regs[0] = 11432ULL;
    cpu->regs[0] = cpu->regs[21] + cpu->regs[0];
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_e9e28;
L_e9ea0:
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xe9ea8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[0], (SP + 56));
    goto L_e9e04;
L_e9eb0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 1056ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xe9ec8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_e9e28;
L_e9ed4:
    PB_STRW((cpu->regs[21] + 11432), cpu->regs[0]);
    goto L_e9e90;
    /* nop */
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xe9f08ULL; PB_CALL(9, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 16));
    cpu->regs[3] = cpu->regs[2] + (65ULL << 12);
    PB_LDRB(cpu->regs[19], (cpu->regs[3] + 1104));
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_e9f2c;
L_e9f1c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_e9f2c:
    FLAG_CMP((cpu->regs[21]) & (1ULL), 0);
    cpu->regs[22] = cpu->regs[2] + (65ULL << 12);
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 1288ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = PB_BASE + 0x284000ULL;
    cpu->regs[24] = cpu->regs[24] + 1264ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[25] = PB_BASE + 0x284000ULL;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2760));
    cpu->regs[22] = cpu->regs[22] + 1040ULL;
    cpu->regs[24] = (FLAG_NE) ? cpu->regs[24] : cpu->regs[0];
    cpu->regs[25] = cpu->regs[25] + 1312ULL;
L_e9f68:
    if (!((cpu->regs[19] >> 0) & 1)) goto L_e9f98;
L_e9f6c:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xe9f7cULL; PB_CALL(10, cpu, tlb, cpu->regs[2]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_e9fa8;
L_e9f80:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] >> 1));
    cpu->regs[22] = cpu->regs[22] + 8ULL;
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_e9f68;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_e9f1c;
L_e9f98:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] >> 1));
    cpu->regs[22] = cpu->regs[22] + 8ULL;
    if (!((cpu->regs[19] >> 0) & 1)) goto L_e9f98;
    goto L_e9f6c;
L_e9fa8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xe9fb0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x9baacULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ea010;
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[25];
    PB_STR((SP + 88), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0xe9fc8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    PB_LDR(cpu->regs[2], (SP + 88));
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_e9fe4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_ea028;
L_e9fe4:
    if ((cpu->regs[23])==0) goto L_ea010;
L_e9fe8:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xe9ff0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1fa20cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_e9f80;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_e9f80;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0xea00cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_e9f80;
L_ea010:
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_ea020;
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
L_ea020:
    cpu->regs[23] = cpu->regs[26];
    goto L_e9fe8;
L_ea028:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xea030ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    if ((cpu->regs[23])!=0) goto L_e9fe8;
    goto L_ea010;
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    cpu->regs[2] = PB_BASE + 0xdf000ULL;
    cpu->regs[2] = cpu->regs[2] + 3296ULL;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 320));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_ea074;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 208));
    cpu->regs[16] = cpu->regs[2];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_ea074:
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3216));
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[6] = cpu->regs[2] & 9223372036854775807ULL;
    cpu->regs[29] = SP;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    cpu->regs[2] = cpu->regs[1];
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[6], 1ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_ea0c4;
    if ((cpu->regs[3])!=0) goto L_ea0fc;
L_ea0a8:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_ea0f4;
L_ea0bc:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_ea0c4:
    cpu->regs[7] = cpu->tls_ptr;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xea0dcULL; PB_CALL(16, cpu, tlb, cpu->regs[1]);
    cpu->regs[4] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[3] = cpu->regs[6];
    PB_LDR(cpu->regs[0], (cpu->regs[7] + cpu->regs[0]));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(17, cpu, tlb, PB_BASE + 0xea120ULL); return; };
L_ea0f4:
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_ea0bc;
L_ea0fc:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[0] + 3216ULL;
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0xea110ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x81c64ULL);
    PB_LDR(cpu->regs[2], (SP + 24));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ea0a8;
    cpu->regs[0] = 0ULL;
    goto L_ea0bc;
}
