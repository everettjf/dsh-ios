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

void ft_PyNumber_InPlaceOr(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 96));
    PB_STR((SP + 32), cpu->regs[21]);
    if ((cpu->regs[2])==0) goto L_12bb38;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 224));
    if ((cpu->regs[2])!=0) goto L_12bb70;
L_12bb38:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2400));
L_12bb40:
    cpu->regs[2] = 120ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12bb50ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_EQ) goto L_12bba4;
L_12bb5c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_12bb70:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2400));
    cpu->regs[30] = PB_BASE + 0x12bb7cULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_12bb5c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12bb40;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12bb40;
    cpu->regs[30] = PB_BASE + 0x12bba0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_12bb40;
L_12bba4:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x28a000ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[2] = cpu->regs[2] + 1504ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x1ac810ULL); return; };
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_12bc4c;
    cpu->regs[1] = cpu->regs[2] & 9223372036854775807ULL;
    FLAG_CMP((cpu->regs[2]) & (9223372036854775806ULL), 0);
    if (FLAG_NE) goto L_12bc14;
L_12bbe8:
    if ((cpu->regs[1])==0) goto L_12bc00;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0xe7640ULL); return; };
L_12bc00:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0xe7640ULL); return; };
L_12bc14:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x285000ULL;
L_12bc1c:
    cpu->regs[0] = cpu->regs[21] + 1320ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    PB_STR((SP + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x12bc30ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x116fa0ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_12bc78;
L_12bc38:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_12bc4c:
    cpu->regs[1] = cpu->regs[3];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[21] + 1320ULL;
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12bc64ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x81c64ULL);
    PB_LDR(cpu->regs[2], (SP + 56));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_12bc38;
    cpu->regs[1] = cpu->regs[2] & 9223372036854775807ULL;
    FLAG_CMP((cpu->regs[2]) & (9223372036854775806ULL), 0);
    if (FLAG_NE) goto L_12bc1c;
L_12bc78:
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_12bbe8;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[4];
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 96));
    if ((cpu->regs[3])==0) goto L_12bcb8;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[5]))));
    if ((cpu->regs[3])!=0) goto L_12bcec;
L_12bcb8:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
L_12bcc0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12bcccULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x11a7a0ULL);
    cpu->regs[5] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_12bd30;
L_12bcd8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_12bcec:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2400));
    PB_STRW((SP + 60), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12bcfcULL; PB_CALL(10, cpu, tlb, cpu->regs[3]);
    cpu->regs[5] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (SP + 60));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_12bcd8;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_12bcc0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_12bcc0;
    PB_STRW((SP + 60), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x12bd28ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDRW(cpu->regs[2], (SP + 60));
    goto L_12bcc0;
L_12bd30:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    { PB_CALL(12, cpu, tlb, PB_BASE + 0x1ac810ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_12bdac;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[21] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_LE) goto L_12bdbc;
L_12bd88:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((cpu->regs[2] + (cpu->regs[21] << 3)), cpu->regs[20]);
    PB_STR((cpu->regs[19] + 16), cpu->regs[1]);
L_12bd9c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_12bdac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[21] + 1ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LT) goto L_12bd88;
L_12bdbc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x12bdc4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe5550ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_12bde0;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((cpu->regs[1] + (cpu->regs[21] << 3)), cpu->regs[20]);
    goto L_12bd9c;
L_12bde0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x12bde8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c408ULL);
    cpu->regs[0] = 0ULL;
    goto L_12bd9c;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_12bed0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_12bf40;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 32)); PB_LDR(cpu->regs[4], (cpu->regs[0] + 32) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 32));
    FLAG_CMP(cpu->regs[3], cpu->regs[5]);
    if (FLAG_GT) goto L_12bf28;
    cpu->regs[1] = cpu->regs[3] << 4;
    cpu->regs[2] = PB_BASE + 0x51d000ULL;
    cpu->regs[2] = cpu->regs[2] + 3600ULL;
    cpu->regs[6] = cpu->regs[4] + (cpu->regs[3] << 4);
    cpu->regs[2] = cpu->regs[2] + 1784ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[4] + cpu->regs[1]));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12bed8;
    cpu->regs[1] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_LT) goto L_12beb0;
    PB_LDR(cpu->regs[7], (cpu->regs[6] + 16));
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[7], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12bedc;
    cpu->regs[1] = cpu->regs[3] + 2ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_LT) goto L_12beb0;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 32));
    FLAG_CMP(cpu->regs[6], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[6], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12bedc;
    cpu->regs[1] = cpu->regs[3] + 3ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_LT) goto L_12beb0;
L_12be90:
    cpu->regs[3] = cpu->regs[1] << 4;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + cpu->regs[3]));
    FLAG_CMP(cpu->regs[6], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[6], cpu->regs[2]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12bf14;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_GE) goto L_12be90;
L_12beb0:
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]);
L_12beb8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_12bed0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_12bf34;
L_12bed0:
    cpu->regs[0] = 0ULL;
    goto L_12bf08;
L_12bed8:
    cpu->regs[1] = cpu->regs[3];
L_12bedc:
    cpu->regs[3] = cpu->regs[1] << 4;
    cpu->regs[0] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
L_12bee8:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[3]));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 40));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 40), cpu->regs[2]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_12bf08;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_12bf08:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_12bf14:
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[2]);
    FLAG_CMP(cpu->regs[5], cpu->regs[1]);
    if (FLAG_GE) goto L_12bee8;
    goto L_12beb8;
L_12bf28:
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    PB_STR((cpu->regs[19] + 32), cpu->regs[3]);
    goto L_12beb8;
L_12bf34:
    cpu->regs[30] = PB_BASE + 0x12bf38ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_12bf08;
L_12bf40:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[1] = PB_BASE + 0x28b000ULL;
    cpu->regs[1] = cpu->regs[1] + 392ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x12bf58ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    goto L_12bf08;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -16));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[1])==0) goto L_12c104;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + -8));
    cpu->regs[3] = PB_BASE + 0x12b000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 18446744073709551612ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 48));
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[3] + 3944ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + -8));
    cpu->regs[1] = cpu->regs[1] & 1ULL;
    PB_STR((cpu->regs[22] + -16), 0ULL); PB_STR((cpu->regs[22] + -16) + 8, cpu->regs[1]);
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_12c11c;
L_12bfcc:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x12bfe0ULL; PB_CALL(17, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[23], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[23])==0) goto L_12c170;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 152));
    cpu->regs[1] = cpu->regs[23] + 152ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_GT) goto L_12c184;
L_12bff8:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 192));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[2])!=0) goto L_12c128;
L_12c008:
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 40));
    FLAG_CMP(cpu->regs[20], 0ULL);
    if (FLAG_LE) goto L_12c0e0;
    cpu->regs[21] = PB_BASE + 0x51d000ULL;
    cpu->regs[21] = cpu->regs[21] + 3600ULL;
    cpu->regs[21] = cpu->regs[21] + 1784ULL;
L_12c020:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_12c044;
L_12c030:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[21]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_12c030;
L_12c044:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[20] = cpu->regs[20] - 1ULL;
    cpu->regs[2] = cpu->regs[1] - 1ULL;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_12c0c8;
L_12c054:
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    if ((cpu->regs[20])!=0) goto L_12c020;
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 40));
    cpu->regs[0] = cpu->regs[22] + 64ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_12c0ec;
L_12c06c:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 136));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    cpu->regs[30] = PB_BASE + 0x12c084ULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0x12c094ULL; PB_CALL(19, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[23])==0) goto L_12c0b4;
L_12c098:
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[23] + 152), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_12c0b4;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 160));
    if ((cpu->regs[2])!=0) goto L_12c134;
L_12c0b4:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_12c0c8:
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_12c054;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x12c0dcULL; PB_CALL(20, cpu, tlb, cpu->regs[1]);
    goto L_12c054;
L_12c0e0:
    cpu->regs[0] = cpu->regs[22] + 64ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_12c06c;
L_12c0ec:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0x12c0fcULL; PB_CALL(21, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[23])!=0) goto L_12c098;
    goto L_12c0b4;
L_12c104:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = PB_BASE + 0x12b000ULL;
    cpu->regs[0] = cpu->regs[0] + 3944ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_12bfcc;
L_12c11c:
    PB_LDR(cpu->regs[23], (cpu->regs[22] + 192));
    if ((cpu->regs[23])==0) goto L_12c008;
    cpu->regs[23] = 0ULL;
L_12c128:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x12c130ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_12c008;
L_12c134:
    PB_STRW((cpu->regs[23] + 152), cpu->regs[1]);
    goto L_12c158;
L_12c13c:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[2] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 48));
    cpu->regs[1] = cpu->regs[1] & 18446744073709551612ULL;
    PB_STR((cpu->regs[23] + 160), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x12c154ULL; PB_CALL(23, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 160));
L_12c158:
    cpu->regs[0] = cpu->regs[2];
    if ((cpu->regs[2])!=0) goto L_12c13c;
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 152));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[23] + 152), cpu->regs[0]);
    goto L_12c0b4;
L_12c170:
    cpu->regs[30] = PB_BASE + 0x12c174ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x7c39cULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49ULL)));
    if (FLAG_LE) goto L_12bff8;
L_12c184:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + -8));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->regs[2] & 3ULL;
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_STR((cpu->regs[22] + -8), cpu->regs[0]);
    PB_STR((cpu->regs[1] + 8), cpu->regs[22]);
    goto L_12c0b4;
}
