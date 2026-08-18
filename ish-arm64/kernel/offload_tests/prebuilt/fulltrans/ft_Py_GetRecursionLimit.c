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

void ft_Py_GetRecursionLimit(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[1] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x22089cULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 376));
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[5] = SP + 8ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    cpu->regs[4] = SP + 16ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[2] = 1ULL;
    PB_STR((SP + 8), 0ULL);
    cpu->regs[30] = PB_BASE + 0x220900ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_22098c;
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_220964;
L_220918:
    PB_LDR(cpu->regs[2], (SP + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_220994;
    if ((cpu->regs[2])!=0) goto L_220930;
L_220928:
    cpu->regs[2] = 0ULL;
    if ((cpu->regs[1])==0) goto L_220974;
L_220930:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x220938ULL; PB_CALL(3, cpu, tlb, cpu->regs[19]);
L_220938:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_220970;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_220964:
    cpu->regs[1] = 0ULL;
    PB_STR((SP + 16), 0ULL);
    goto L_220918;
L_220970:
    cpu->regs[30] = PB_BASE + 0x220974ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c170ULL);
L_220974:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 1072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x22098cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_22098c:
    cpu->regs[0] = 0ULL;
    goto L_220938;
L_220994:
    PB_STR((SP + 8), 0ULL);
    goto L_220928;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 8));
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2209c4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])==0) goto L_220a1c;
L_2209c8:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x2209d4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe31ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_220a04;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 272));
    if ((cpu->regs[3])==0) goto L_220a44;
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_220a04:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[1] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0xed3ccULL); return; };
L_220a1c:
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x220a28ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_2209c8;
L_220a30:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_220a44:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_220a30;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_220a30;
    /* nop */
    /* nop */
    goto L_220a64;
L_220a64:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x220a78ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1c1aecULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_220a9c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 152));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 80));
    cpu->regs[2] = 32ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[1] = cpu->regs[1] + 8ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    goto L_220aac;
L_220a9c:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_220aac:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 0));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    if ((cpu->regs[4])!=0) goto L_220afc;
    cpu->regs[1] = ((uint32_t)(cpu->regs[2] & 255ULL));
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x220ad0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x220b10ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_220aec;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_220ae8;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[0]);
L_220ae8:
    PB_STR((cpu->regs[19] + 0), cpu->regs[4]);
L_220aec:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_220afc:
    PB_LDRW(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_220aec;
    PB_STRW((cpu->regs[4] + 0), cpu->regs[0]);
    goto L_220aec;
L_220b10:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = ((uint32_t)(cpu->regs[1] & 255ULL));
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[30] = PB_BASE + 0x220b2cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdb480ULL);
    if ((cpu->regs[0])==0) goto L_220b88;
    PB_LDRW(cpu->regs[7], (cpu->regs[19] + 72));
    cpu->regs[3] = 0ULL;
    cpu->regs[5] = 0ULL;
L_220b3c:
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_LE) goto L_220b88;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 104));
    cpu->regs[2] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]));
    cpu->regs[4] = cpu->regs[4] + cpu->regs[3];
    cpu->regs[2] = cpu->regs[0] + (cpu->regs[2] << 3);
    PB_LDRB(cpu->regs[4], (cpu->regs[4] + 32));
    FLAG_CMP((((uint32_t)(cpu->regs[20]))) & (((uint32_t)(cpu->regs[4]))), 0);
    if (FLAG_EQ) goto L_220b80;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 96));
    cpu->regs[5] = ((uint32_t)(cpu->regs[5] + 1ULL));
    cpu->regs[4] = cpu->regs[4] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[3])) << 3);
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 24));
    PB_LDRW(cpu->regs[4], (cpu->regs[6] + 0));
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL)); FLAG_CMP(cpu->regs[4], 0);
    if (FLAG_NE) goto L_220b94;
    PB_STR((cpu->regs[2] + 24), cpu->regs[6]);
L_220b80:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_220b3c;
L_220b88:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_220b94:
    PB_STRW((cpu->regs[6] + 0), cpu->regs[4]);
    PB_STR((cpu->regs[2] + 24), cpu->regs[6]);
    goto L_220b80;
    SP = SP - 112ULL;
    cpu->regs[2] = cpu->tls_ptr;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    PB_STR((SP + 96), cpu->regs[23]); PB_STR((SP + 96) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x220bf0ULL; PB_CALL(13, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 96));
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_EQ) goto L_220ca4;
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 96));
    if ((cpu->regs[2])==0) goto L_220ca4;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 240));
    cpu->regs[2] = PB_BASE + 0x220000ULL;
    cpu->regs[2] = cpu->regs[2] + 2976ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    cpu->regs[22] = (FLAG_EQ) ? 1 : 0;
    if ((cpu->regs[0])==0) goto L_220ce0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 240));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_220ce0;
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_EQ) goto L_220d10;
L_220c34:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
L_220c48:
    cpu->regs[22] = 0ULL;
L_220c4c:
    cpu->regs[4] = 33616ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[4];
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x220c60ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_EQ) goto L_220cc8;
L_220c6c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_220d0c;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[23], (SP + 96)); PB_LDR(cpu->regs[24], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
L_220ca4:
    if ((cpu->regs[0])==0) goto L_220cbc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 240));
    cpu->regs[0] = PB_BASE + 0x220000ULL;
    cpu->regs[0] = cpu->regs[0] + 2976ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_220c34;
L_220cbc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    goto L_220c6c;
L_220cc8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_220cbc;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_220db0;
L_220ce0:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_220cbc;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    cpu->regs[3] = 32784ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x220d04ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    goto L_220c6c;
L_220d0c:
    cpu->regs[30] = PB_BASE + 0x220d10ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_220d10:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x220d18ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdd1a8ULL);
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_220d38;
L_220d24:
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[22] = 1ULL;
    goto L_220c4c;
L_220d38:
    cpu->regs[6] = 32784ULL;
    cpu->regs[1] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[24] + cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x220d4cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x250360ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_220dc4;
    if (FLAG_EQ) goto L_220d24;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2400));
    cpu->regs[5] = 32784ULL;
    cpu->regs[1] = cpu->regs[24] + cpu->regs[5];
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[21];
    PB_STR((SP + 8), cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[20]); PB_STR((SP + 16) + 8, cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x220d7cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x161820ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[23]);
    if (FLAG_NE) goto L_220c6c;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[2], (SP + 8));
    if (((cpu->regs[0] >> 31) & 1)) goto L_220c48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_220c48;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x220da8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[2], (SP + 8));
    goto L_220c48;
L_220db0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_220ce0;
    cpu->regs[30] = PB_BASE + 0x220dc0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_220ce0;
L_220dc4:
    cpu->regs[1] = 0ULL;
    goto L_220c6c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x297000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[3] = cpu->regs[3] + 2760ULL;
    cpu->regs[1] = cpu->regs[1] + 320ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[0] + 328ULL;
    cpu->regs[30] = PB_BASE + 0x220dfcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_220e34;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    if ((cpu->regs[0])!=0) goto L_220e20;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_220e14:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_220e20:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_220e14;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_220e14;
L_220e34:
    cpu->regs[0] = 0ULL;
    goto L_220e14;
    /* nop */
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x220e4cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1c17e0ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = PB_BASE + 0x298000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[3] = cpu->regs[3] + 1144ULL;
    cpu->regs[1] = cpu->regs[1] + 320ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x287000ULL;
    cpu->regs[0] = cpu->regs[0] + 328ULL;
    cpu->regs[30] = PB_BASE + 0x220e90ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xee244ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_220eb4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    if ((cpu->regs[0])!=0) goto L_220ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_220ea8:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_220eb4:
    cpu->regs[0] = 0ULL;
    goto L_220ea8;
L_220ebc:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_220ea8;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_220ea8;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x220ef4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x141d48ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_220f44;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_GT) goto L_220f28;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x220f14ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x220f70ULL);
    if ((cpu->regs[0])==0) goto L_220f44;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_220f58;
L_220f20:
    cpu->regs[0] = 0ULL;
    goto L_220f48;
L_220f28:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 1160ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x220f44ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x11f220ULL);
L_220f44:
    cpu->regs[0] = 4294967295ULL;
L_220f48:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_220f58:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_220f20;
    cpu->regs[30] = PB_BASE + 0x220f68ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_220f48;
L_220f70:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_220fdc;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 16));
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_GT) goto L_220ff8;
    if ((cpu->regs[2])==0) goto L_220fdc;
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_220fb0;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_220fb0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x220fbcULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x221080ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_220fd4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_22106c;
L_220fd4:
    FLAG_CMP(cpu->regs[22], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_221010;
L_220fdc:
    if ((cpu->regs[20])!=0) goto L_221018;
L_220fe0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_220fe8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_220ff8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x298000ULL;
    cpu->regs[1] = cpu->regs[1] + 1200ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x221010ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x11f220ULL);
L_221010:
    cpu->regs[0] = 0ULL;
    goto L_220fe8;
L_221018:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])==0) goto L_220fe0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x221028ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x2500c0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_221010;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22103cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x221428ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22105c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_22105c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22105cULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_22105c:
    FLAG_CMP(cpu->regs[20], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_220fe0;
    cpu->regs[0] = 0ULL;
    goto L_220fe8;
L_22106c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x221074ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_220fd4;
    /* nop */
    /* nop */
L_221080:
    SP = SP - 80ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 64), cpu->regs[23]); PB_STR((SP + 64) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2680));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_EQ) goto L_221154;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[1] = 48360ULL;
    cpu->regs[2] = SP;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[20] + cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x2210e4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2212e4;
    PB_LDR(cpu->regs[22], (SP + 0));
    if ((cpu->regs[22])!=0) goto L_2211c4;
    cpu->regs[0] = 47904ULL;
    cpu->regs[2] = SP;
    cpu->regs[1] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x221108ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x112290ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_2212e4;
    PB_LDR(cpu->regs[20], (SP + 0));
    if ((cpu->regs[20])!=0) goto L_2212b8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_2212f4;
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 80ULL;
    { PB_CALL(37, cpu, tlb, PB_BASE + 0x221428ULL); return; };
L_221154:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22115cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x2500c0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_2212e8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x221170ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x221428ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_221190;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221190;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x221190ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_221190:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_2212f0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 64)); PB_LDR(cpu->regs[24], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_2211c4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2211ccULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x179564ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_2211ec;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2211ec;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x2211ecULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2211ec:
    if ((cpu->regs[20])==0) goto L_2212e4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2211f8ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe7e88ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[24] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_221218;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221218;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x221218ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_221218:
    if ((cpu->regs[24])==0) goto L_2212e4;
    cpu->regs[22] = 0ULL;
L_221220:
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_221284;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x22122cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_221284;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x221240ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_221310;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x221258ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe97e4ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_2212f8;
L_221264:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_221220;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_221220;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x221280ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221220;
L_221284:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_2212a0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_2212a0;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x2212a0ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2212a0:
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_2212e4;
    cpu->regs[30] = PB_BASE + 0x2212a8ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    cpu->regs[20] = (FLAG_NE) ? 0xffffffffULL : 0;
    goto L_221190;
L_2212b8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2212c0ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x179564ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_2212e0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_2212e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x2212e0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_2212e0:
    if ((cpu->regs[19])!=0) goto L_221318;
L_2212e4:
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
L_2212e8:
    cpu->regs[20] = 4294967295ULL;
    goto L_221190;
L_2212f0:
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
L_2212f4:
    cpu->regs[30] = PB_BASE + 0x2212f8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2212f8:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_221264;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x22130cULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_221264;
L_221310:
    cpu->regs[22] = 4294967295ULL;
    goto L_221264;
L_221318:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x221324ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x221428ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_22133c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_221344;
L_22133c:
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    goto L_221190;
L_221344:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x22134cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    goto L_221190;
    /* nop */
    /* nop */
    /* nop */
}
