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

void ft_PyUnicode_DecodeLocaleAndSize(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xacb7cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1b2a10ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x193360ULL); return; };
    SP = SP - 64ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    cpu->regs[1] = cpu->regs[1] + 3096ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0xacbd0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x192780ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_acc10;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0xacbe0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x27e524ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_acc10;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0xacbf4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x259a00ULL);
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[30] = PB_BASE + 0xacbfcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7baf0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_acc18;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xacc10ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_acc10:
    cpu->regs[0] = 0ULL;
    goto L_acc20;
L_acc18:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_acc20:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_acc40;
    cpu->regs[30] = PB_BASE + 0xacc40ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_acc40:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0xacc64ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[21], (cpu->regs[0] + 0));
    cpu->regs[19] = cpu->regs[0];
    PB_STRW((cpu->regs[0] + 0), cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0xacc74ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xacc88ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[0] + 1576ULL;
    cpu->regs[30] = PB_BASE + 0xacc98ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1fa220ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xacca0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x121f40ULL);
    PB_STRW((cpu->regs[19] + 0), cpu->regs[21]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 80ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 40), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xacce8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_accfc;
    cpu->regs[30] = PB_BASE + 0xaccf8ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_acd30;
L_accfc:
    cpu->regs[20] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xacd10ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7b7b0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_acd24;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0xacd1cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1b2720ULL);
    cpu->regs[0] = 0ULL;
    goto L_acd34;
L_acd24:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xacd2cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x9daf0ULL);
    goto L_acd34;
L_acd30:
    cpu->regs[0] = 0ULL;
L_acd34:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_acd54;
    cpu->regs[30] = PB_BASE + 0xacd54ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c170ULL);
L_acd54:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[2] - 2ULL;
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 72), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_acdbc;
L_acda4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0xacdacULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_acde4;
    goto L_acddc;
L_acdbc:
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + 1624ULL;
    cpu->regs[3] = 3ULL;
    cpu->regs[2] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xacdd4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_acda4;
    goto L_ace48;
L_acddc:
    cpu->regs[30] = PB_BASE + 0xacde0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_ace48;
L_acde4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(cpu->regs[20], 2ULL);
    if (FLAG_LE) goto L_acdf8;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 16));
    goto L_acdfc;
L_acdf8:
    cpu->regs[19] = 0ULL;
L_acdfc:
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 32));
    cpu->regs[20] = SP + 8ULL;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0xace0cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xab7e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ace48;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xace20ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xab7e0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_ace48;
    cpu->regs[19] = SP + 40ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xace3cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x7ab30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ace50;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[30] = PB_BASE + 0xace48ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1b2720ULL);
L_ace48:
    cpu->regs[0] = 0ULL;
    goto L_ace58;
L_ace50:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xace58ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x9daf0ULL);
L_ace58:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ace78;
    cpu->regs[30] = PB_BASE + 0xace78ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ace78:
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_acec4;
L_aceac:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[30] = PB_BASE + 0xaceb4ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_acef0;
    goto L_acee8;
L_acec4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a4000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 0ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xacedcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_aceac;
L_acee0:
    cpu->regs[0] = 0ULL;
    goto L_ad038;
L_acee8:
    cpu->regs[30] = PB_BASE + 0xaceecULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_acee0;
L_acef0:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xacf04ULL; PB_CALL(32, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[22], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[30] = PB_BASE + 0xacf18ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1b03a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_acf3c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[2] + 1640ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xacf38ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_acee0;
L_acf3c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[19] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(63ULL)));
    if (FLAG_LS) goto L_acf68;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2976));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = PB_BASE + 0x298000ULL;
    cpu->regs[2] = cpu->regs[2] + 2488ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xacf64ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_acee0;
L_acf68:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xacf70ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x11d7acULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_acfb8;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xacf80ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1e9bc4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_acfc4;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xacf94ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1e9bc4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_acfc8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[2] + 1704ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xacfb4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d5980ULL);
    goto L_acee0;
L_acfb8:
    cpu->regs[21] = PB_BASE + 0x81000ULL;
    cpu->regs[21] = cpu->regs[21] + 3924ULL;
    goto L_acfc8;
L_acfc4:
    cpu->regs[21] = 1ULL;
L_acfc8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xacfd0ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x12d024ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_acee0;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xacfe0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1d3690ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_acffc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xacff8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_acee0;
L_acffc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[1] = 472ULL;
    cpu->regs[19] = cpu->regs[1] + (((cpu->regs[19]) & 0xffffffffULL) << 4);
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_ad024;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
L_ad024:
    PB_STR((cpu->regs[19] + 0), cpu->regs[20]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[0] = (FLAG_NE) ? cpu->regs[0] : cpu->regs[1];
L_ad038:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
L_ad060:
    cpu->regs[30] = PB_BASE + 0xad064ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xad070ULL; PB_CALL(44, cpu, tlb, cpu->regs[19]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xad07cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if ((((uint32_t)(cpu->regs[21])))==0) goto L_ad0a0;
    cpu->regs[30] = PB_BASE + 0xad084ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x7bae0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_ad0ac;
    cpu->regs[30] = PB_BASE + 0xad094ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x12cde0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ad060;
L_ad098:
    cpu->regs[0] = 0ULL;
    goto L_ad0c0;
L_ad0a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_ad0c0;
L_ad0ac:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xad0bcULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ad098;
L_ad0c0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[5] = SP + 16ULL;
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    cpu->regs[4] = SP + 8ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 112), cpu->regs[21]);
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = SP + 12ULL;
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[2] + 1784ULL;
    cpu->regs[30] = PB_BASE + 0xad11cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x22ee90ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ad174;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[20] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    PB_LDRW(cpu->regs[21], (SP + 8)); PB_LDRW(cpu->regs[19], (SP + 8) + 4);
    cpu->regs[30] = PB_BASE + 0xad138ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xa99c8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ad174;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xad14cULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x7ac00ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ad168;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xad164ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ad174;
L_ad168:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_ad178;
L_ad174:
    cpu->regs[0] = 0ULL;
L_ad178:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ad198;
    cpu->regs[30] = PB_BASE + 0xad198ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ad198:
    PB_LDR(cpu->regs[21], (SP + 112));
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[4] = SP + 16ULL;
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 112), cpu->regs[21]);
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 72), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = SP + 12ULL;
    cpu->regs[2] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[2] + 1808ULL;
    cpu->regs[30] = PB_BASE + 0xad1f4ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x22ee90ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ad244;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[20] = SP + 24ULL;
    PB_LDRW(cpu->regs[21], (SP + 12));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xad210ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xa99c8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ad244;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xad220ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x7b290ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ad238;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3024));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xad234ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1b2720ULL);
    goto L_ad244;
L_ad238:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_ad248;
L_ad244:
    cpu->regs[0] = 0ULL;
L_ad248:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ad268;
    cpu->regs[30] = PB_BASE + 0xad268ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ad268:
    PB_LDR(cpu->regs[21], (SP + 112));
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    SP = SP + 128ULL;
    return;
}
