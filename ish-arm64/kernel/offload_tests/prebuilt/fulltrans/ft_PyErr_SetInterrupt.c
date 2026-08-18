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

void ft_PyErr_SetInterrupt(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[0] = 2ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0xa2970ULL); return; };
    SP = SP - 32ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2832ULL;
    PB_STRW((SP + 4), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xa2a30ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a2a58;
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0xa2a3cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xa2970ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a2a60;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 2488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa2a58ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_a2a58:
    cpu->regs[0] = 0ULL;
    goto L_a2a68;
L_a2a60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a2a68:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_a2a88;
    cpu->regs[30] = PB_BASE + 0xa2a88ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a2a88:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa2ab0ULL; PB_CALL(6, cpu, tlb, cpu->regs[3]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
L_a2ac8:
    cpu->regs[0] = cpu->regs[21] + 3928ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[19])));
    if (FLAG_LE) goto L_a2b14;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[19])) << 3)));
    if ((cpu->regs[0])==0) goto L_a2b0c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa2af4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_a2b20;
    if (FLAG_EQ) goto L_a2b0c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 3944));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa2b0cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x228300ULL);
L_a2b0c:
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] + 1ULL));
    goto L_a2ac8;
L_a2b14:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_a2b24;
L_a2b20:
    cpu->regs[0] = 0ULL;
L_a2b24:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 320));
    PB_STR((SP + 64), cpu->regs[25]);
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a2b88;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[22] + 24));
    cpu->regs[1] = cpu->regs[1] + 2848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[23] + 24));
    cpu->regs[30] = PB_BASE + 0xa2b84ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a2ca8;
L_a2b88:
    cpu->regs[24] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[22];
L_a2b90:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xa2b98ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x86618ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a2ba4;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 256));
    goto L_a2b90;
L_a2ba4:
    cpu->regs[20] = cpu->regs[23];
L_a2ba8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa2bb0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x86618ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a2bbc;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 256));
    goto L_a2ba8;
L_a2bbc:
    FLAG_CMP(cpu->regs[21], cpu->regs[20]);
    if (FLAG_NE) goto L_a2be0;
L_a2bc4:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 168));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 168));
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[1];
    FLAG_CMP((cpu->regs[0]) & (24ULL), 0);
    if (FLAG_NE) goto L_a2c84;
    cpu->regs[0] = 1ULL;
    goto L_a2cac;
L_a2be0:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 256));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 256));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_a2c84;
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 288));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_a2c10;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 288));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_a2c10;
    cpu->regs[19] = cpu->regs[19] + 8ULL;
L_a2c10:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 208));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_a2c2c;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 208));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_a2c2c;
    cpu->regs[19] = cpu->regs[19] + 8ULL;
L_a2c2c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    if (!((cpu->regs[0] >> 9) & 1)) goto L_a2c84;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    if (!((cpu->regs[0] >> 9) & 1)) goto L_a2c84;
    PB_LDR(cpu->regs[25], (cpu->regs[21] + 864));
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 864));
    FLAG_CMP(cpu->regs[25], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_a2c6c;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xa2c5cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_a2c84;
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 16));
    cpu->regs[19] = cpu->regs[19] + (cpu->regs[0] << 3);
L_a2c6c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_a2c84;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_a2bc4;
L_a2c84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[22] + 24));
    cpu->regs[2] = cpu->regs[24];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[1] + 2904ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[23] + 24));
    cpu->regs[30] = PB_BASE + 0xa2ca8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11f220ULL);
L_a2ca8:
    cpu->regs[0] = 0ULL;
L_a2cac:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa2cdcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe1564ULL);
    if ((cpu->regs[0])!=0) goto L_a2cec;
L_a2ce0:
    cpu->regs[30] = PB_BASE + 0xa2ce4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = 1ULL;
    goto L_a2d28;
L_a2cec:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0xa2cfcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x12ba40ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a2d1c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a2d1c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa2d1cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a2d1c:
    FLAG_CMP(cpu->regs[19], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a2ce0;
    cpu->regs[0] = ((uint32_t)(cpu->regs[19] & 1ULL));
L_a2d28:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0xa2d4cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xdb480ULL);
    if ((cpu->regs[0])==0) goto L_a2e60;
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a2d68;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_a2d68:
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xa2d70ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x276fa0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_a2d80;
L_a2d78:
    cpu->regs[20] = 18446744073709551615ULL;
    goto L_a2e40;
L_a2d80:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_a2dc4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a2da4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_a2da8;
L_a2da4:
    cpu->regs[0] = 4294967295ULL;
L_a2da8:
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a2db8;
L_a2db4:
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_a2db8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_a2e30;
L_a2dc4:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a2dd8;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_a2dd8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 40));
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 2ULL;
    cpu->regs[1] = cpu->regs[1] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0xa2df4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_a2d78;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_a2e1c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_a2db4;
    goto L_a2db8;
L_a2e1c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a2e30;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_a2e30:
    PB_STR((cpu->regs[19] + 40), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa2e3cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xd7ea0ULL);
    cpu->regs[20] = cpu->regs[0];
L_a2e40:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a2e64;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a2e64;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa2e5cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a2e64;
L_a2e60:
    cpu->regs[20] = 18446744073709551615ULL;
L_a2e64:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
