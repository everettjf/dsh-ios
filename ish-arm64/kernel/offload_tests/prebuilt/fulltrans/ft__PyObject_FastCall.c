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

void ft__PyObject_FastCall(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x192948ULL; PB_CALL(1, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[5] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[5];
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xe742cULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_192a7c;
L_192984:
    cpu->regs[19] = cpu->regs[2] & 9223372036854775807ULL;
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_HI) goto L_1929f8;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 304));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1929a0ULL; PB_CALL(3, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_192a74;
    if ((cpu->regs[19])==0) goto L_1929ec;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_192a3c;
    FLAG_CMP(cpu->regs[19], 2ULL);
    if (FLAG_NE) goto L_192aa0;
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 8));
L_1929c8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1929d0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x192aa8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_192a58;
L_1929d8:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1929ec:
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = 0ULL;
    goto L_1929c8;
L_1929f8:
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 3472ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x192a10ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_192a74;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 304));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x192a24ULL; PB_CALL(6, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_192a74;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    if (((cpu->regs[2] >> 31) & 1)) goto L_192aa0;
L_192a3c:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 3480ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x192a58ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11f220ULL);
L_192a58:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_192a74;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_192a74;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x192a74ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_192a74:
    cpu->regs[20] = 0ULL;
    goto L_1929d8;
L_192a7c:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[0] + 3960ULL;
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x192a90ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x81c64ULL);
    PB_LDR(cpu->regs[2], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_192984;
    cpu->regs[20] = 0ULL;
    goto L_1929d8;
L_192aa0:
    cpu->regs[2] = 0ULL;
    goto L_1929c8;
L_192aa8:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_192b50;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[19] = cpu->regs[2];
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_192c64;
    if ((cpu->regs[2])==0) goto L_192c5c;
    cpu->regs[20] = cpu->regs[1];
L_192adc:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x192ae8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xed18cULL);
    if ((cpu->regs[0])==0) goto L_192c54;
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_192afc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[2]);
L_192afc:
    cpu->regs[22] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[19] = cpu->regs[0];
L_192b08:
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_192b1c;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[2]);
L_192b1c:
    PB_STR((cpu->regs[21] + 16), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x192b24ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    PB_STR((cpu->regs[21] + 24), cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x192b30ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    PB_STR((cpu->regs[21] + 32), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x192b3cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = 0ULL;
L_192b40:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_192b50:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x192b64ULL; PB_CALL(14, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192b74ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x280648ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_192d70;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 0));
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 52));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_192d4c;
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 72));
    if ((cpu->regs[19])==0) goto L_192d28;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 104));
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 32));
    if (((cpu->regs[0] >> 6) & 1)) goto L_192d0c;
L_192ba0:
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[0] = 26712ULL;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    PB_LDRW(cpu->regs[26], (cpu->regs[23] + 72));
    PB_LDRW(cpu->regs[22], (cpu->regs[23] + 88));
    cpu->regs[24] = cpu->regs[24] + cpu->regs[0];
    cpu->regs[22] = ((uint32_t)(cpu->regs[26] - cpu->regs[22]));
L_192bc0:
    FLAG_CMP(((uint32_t)(cpu->regs[26])), ((uint32_t)(cpu->regs[22])));
    if (FLAG_LE) goto L_192ce4;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    cpu->regs[25] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[22]));
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x192be0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x12b670ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_192cdc;
    cpu->regs[25] = cpu->regs[20] + (cpu->regs[25] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 72));
    if ((cpu->regs[0])==0) goto L_192c34;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2872));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_192c34;
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 16));
    if ((cpu->regs[20])==0) goto L_192cb4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_192c88;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_192c70;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_192adc;
L_192c34:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 3608ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192c4cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_192c54:
    cpu->regs[0] = 4294967295ULL;
    goto L_192b40;
L_192c5c:
    cpu->regs[22] = 0ULL;
    goto L_192b08;
L_192c64:
    cpu->regs[22] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_192b08;
L_192c70:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    cpu->regs[22] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_192b08;
L_192c88:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3296));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 3672ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x192ca4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_192b40;
L_192cb4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 3640ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192cccULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_192b40;
L_192cdc:
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] + 1ULL));
    goto L_192bc0;
L_192ce4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 3712ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192cfcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_192b40;
L_192d0c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 56));
    cpu->regs[1] = cpu->regs[23] + 192ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[0] = (uint64_t)((int64_t)cpu->regs[0] >> 1);
    if (((cpu->regs[0] >> 31) & 1)) goto L_192ba0;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    if ((cpu->regs[19])!=0) goto L_192ba0;
L_192d28:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 3584ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192d40ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_192b40;
L_192d4c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 3560ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192d64ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_192b40;
L_192d70:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 3528ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x192d88ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_192b40;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->regs[1];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_192dbc;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[0], 9ULL);
    if (FLAG_EQ) goto L_192dd8;
L_192dbc:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 16) + 8);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(24, cpu, tlb, PB_BASE + 0xed4ccULL); return; };
L_192dd8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[2] = 26712ULL;
    cpu->regs[0] = cpu->regs[4];
    PB_STR((SP + 40), cpu->regs[4]);
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x192df4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x12b670ULL);
    PB_LDR(cpu->regs[4], (SP + 40));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_192dbc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0x115f60ULL); return; };
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[6] = cpu->regs[0];
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[29] = SP;
    if ((cpu->regs[2])==0) goto L_192e64;
L_192e24:
    PB_LDR(cpu->regs[1], (cpu->regs[5] + 8));
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_192ebc;
    cpu->regs[1] = cpu->regs[7];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x192e40ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_192e70;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 40));
    cpu->regs[1] = cpu->regs[5];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[2] = 0ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 16));
    FLAG_CMP((cpu->regs[3]) & (512ULL), 0);
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[7] : 0ULL;
    { PB_CALL(28, cpu, tlb, PB_BASE + 0xddd20ULL); return; };
L_192e64:
    if ((cpu->regs[1])==0) goto L_192f00;
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 8));
    goto L_192e24;
L_192e70:
    PB_LDR(cpu->regs[2], (cpu->regs[6] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_192e94;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    FLAG_CMP((cpu->regs[1]) & (268435456ULL), 0);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : 0ULL;
L_192e94:
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 24));
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[7] + 24));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[3] = cpu->regs[3] + 2216ULL;
    cpu->regs[1] = cpu->regs[1] + 3960ULL;
    cpu->regs[30] = PB_BASE + 0x192eb0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11f220ULL);
L_192eb0:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_192ebc:
    PB_LDR(cpu->regs[2], (cpu->regs[6] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_192ee0;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    FLAG_CMP((cpu->regs[3]) & (268435456ULL), 0);
    cpu->regs[2] = (FLAG_NE) ? cpu->regs[2] : 0ULL;
L_192ee0:
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 24));
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[7] + 24));
    cpu->regs[3] = cpu->regs[3] + 2216ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 3888ULL;
    cpu->regs[30] = PB_BASE + 0x192efcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_192eb0;
L_192f00:
    PB_LDR(cpu->regs[2], (cpu->regs[6] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_192f24;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    FLAG_CMP((cpu->regs[1]) & (268435456ULL), 0);
    cpu->regs[1] = (FLAG_EQ) ? 0ULL : cpu->regs[2];
L_192f24:
    PB_LDR(cpu->regs[4], (cpu->regs[6] + 16));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[3] = cpu->regs[3] + 2216ULL;
    cpu->regs[1] = cpu->regs[1] + 3816ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 24));
    cpu->regs[30] = PB_BASE + 0x192f44ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_192eb0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x192f5cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x192f64ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x192f6cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x192f74ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
}
