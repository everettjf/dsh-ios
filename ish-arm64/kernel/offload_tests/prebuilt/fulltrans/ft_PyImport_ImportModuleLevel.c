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

void ft_PyImport_ImportModuleLevel(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[3];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x1c5be8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c5c28;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = cpu->regs[23];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c5c04ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x13b400ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1c5c24;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1c5c24;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c5c24ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1c5c24:
    cpu->regs[19] = cpu->regs[20];
L_1c5c28:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2520));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_1c5c70;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1c5c68;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_1c5c68:
    cpu->regs[0] = cpu->regs[1];
    return;
L_1c5c70:
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x25a260ULL); return; };
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[0] = PB_BASE + 0x468000ULL;
    cpu->regs[2] = cpu->regs[0] + 2112ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 2496));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1c5ca0;
L_1c5c94:
    cpu->regs[0] = cpu->regs[0] + 2112ULL;
    cpu->regs[0] = cpu->regs[0] + 2496ULL;
    return;
L_1c5ca0:
    PB_STRW((cpu->regs[2] + 2496), cpu->regs[1]);
    goto L_1c5c94;
    SP = SP - 96ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1c5cecULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x112290ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c5d28;
    PB_LDR(cpu->regs[20], (SP + 0));
L_1c5cf4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1c5f14;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 96ULL;
    return;
L_1c5d28:
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = 30760ULL;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2248));
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[1] = cpu->regs[25] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1c5d48ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c5f3c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    if (!((cpu->regs[2] >> 28) & 1)) goto L_1c5f20;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = PB_BASE + 0x28c000ULL;
    cpu->regs[0] = cpu->regs[0] + 1112ULL;
    cpu->regs[30] = PB_BASE + 0x1c5d70ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c5fbc;
    cpu->regs[30] = PB_BASE + 0x1c5d7cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1d5800ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    PB_STR((SP + 0), cpu->regs[20]);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c5da8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c5da8;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1c5da8ULL; PB_CALL(9, cpu, tlb, cpu->regs[1]);
L_1c5da8:
    if ((cpu->regs[20])!=0) goto L_1c5f6c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    if ((cpu->regs[0])!=0) goto L_1c5f64;
L_1c5db4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[26] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1c5dc0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d58a8ULL);
    cpu->regs[24] = cpu->regs[0];
L_1c5dc4:
    if ((cpu->regs[24])!=0) goto L_1c5e84;
L_1c5dc8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c5dd0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1d2f00ULL);
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[0] + 3512ULL;
    cpu->regs[30] = PB_BASE + 0x1c5de4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2840));
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[30] = PB_BASE + 0x1c5e08ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d59f0ULL);
L_1c5e08:
    if ((cpu->regs[20])==0) goto L_1c5e20;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c5e20;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c5fa8;
L_1c5e20:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1c5e3c;
L_1c5e28:
    if ((cpu->regs[24])!=0) goto L_1c5e5c;
L_1c5e2c:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    cpu->regs[20] = 0ULL;
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_1c5cf4;
L_1c5e3c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c5e28;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1c5e58ULL; PB_CALL(14, cpu, tlb, cpu->regs[1]);
    goto L_1c5e28;
L_1c5e5c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c5e2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c5e2c;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1c5e80ULL; PB_CALL(15, cpu, tlb, cpu->regs[1]);
    goto L_1c5e2c;
L_1c5e84:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1c5dc8;
    cpu->regs[0] = 33336ULL;
    cpu->regs[1] = cpu->regs[25] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1c5ea0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[21] = PB_BASE + 0x28d000ULL;
    cpu->regs[30] = PB_BASE + 0x1c5eacULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x121ff0ULL);
    cpu->regs[21] = cpu->regs[21] + 3472ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[1] + 3368ULL;
    cpu->regs[21] = (FLAG_EQ) ? cpu->regs[21] : cpu->regs[1];
    if ((cpu->regs[20])==0) goto L_1c5ed8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c5ed8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c5fe4;
L_1c5ed8:
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1c5eecULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2840));
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c5f10ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d59f0ULL);
    goto L_1c5e08;
L_1c5f14:
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    PB_STR((SP + 80), cpu->regs[25]); PB_STR((SP + 80) + 8, cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x1c5f20ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c5f20:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1c5f3c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1c5f3c;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1c5f3cULL; PB_CALL(21, cpu, tlb, cpu->regs[1]);
L_1c5f3c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1c5f44ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d58a8ULL);
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[24] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1] + 3568ULL;
    cpu->regs[30] = PB_BASE + 0x1c5f54ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c5e28;
    cpu->regs[26] = 0ULL;
    goto L_1c5dc4;
L_1c5f64:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_1c5db4;
L_1c5f6c:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c5f80;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c5f8c;
L_1c5f80:
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_1c5cf4;
L_1c5f8c:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1c5f9cULL; PB_CALL(24, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    PB_LDR(cpu->regs[25], (SP + 80)); PB_LDR(cpu->regs[26], (SP + 80) + 8);
    goto L_1c5cf4;
L_1c5fa8:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1c5fb8ULL; PB_CALL(25, cpu, tlb, cpu->regs[1]);
    goto L_1c5e20;
L_1c5fbc:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1c5e2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1c5e2c;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 8));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1c5fe0ULL; PB_CALL(26, cpu, tlb, cpu->regs[1]);
    goto L_1c5e2c;
L_1c5fe4:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x1c5ff4ULL; PB_CALL(27, cpu, tlb, cpu->regs[1]);
    goto L_1c5ed8;
    /* nop */
    /* nop */
}
