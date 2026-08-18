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

void ft_PyMapping_Size(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    if ((cpu->regs[0])==0) goto L_15bce0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 112));
    if ((cpu->regs[3])==0) goto L_15bc9c;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    if ((cpu->regs[3])==0) goto L_15bc9c;
    cpu->regs[1] = PB_BASE + 0x15d000ULL;
    cpu->regs[1] = cpu->regs[1] + 296ULL;
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_NE) goto L_15bcc0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
L_15bc94:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_15bc9c:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 104));
    if ((cpu->regs[0])==0) goto L_15bcac;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])!=0) goto L_15bccc;
L_15bcac:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 3016ULL;
    cpu->regs[30] = PB_BASE + 0x15bcb8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x234660ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_15bc94;
L_15bcc0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_15bccc:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 2992ULL;
    cpu->regs[30] = PB_BASE + 0x15bcd8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x234660ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_15bc94;
L_15bce0:
    cpu->regs[30] = PB_BASE + 0x15bce4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x96bd4ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_15bc94;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[3];
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 96));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 96));
    FLAG_CMP(cpu->regs[3], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    cpu->regs[4] = (FLAG_NE) ? 1 : 0;
    if ((cpu->regs[2])==0) goto L_15be40;
    PB_LDR(cpu->regs[23], (cpu->regs[2] + 40));
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_15bd78;
L_15bd38:
    if ((cpu->regs[23])==0) goto L_15bf90;
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2400));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15bd54ULL; PB_CALL(4, cpu, tlb, cpu->regs[23]);
    cpu->regs[4] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_15bf70;
L_15bd60:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_15bd78:
    PB_STR((SP + 64), cpu->regs[25]);
    PB_LDR(cpu->regs[25], (cpu->regs[3] + 40));
    FLAG_CMP(cpu->regs[23], cpu->regs[25]);
    if (FLAG_EQ) goto L_15c028;
    if ((cpu->regs[23])==0) goto L_15be50;
    if ((cpu->regs[25])==0) goto L_15befc;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 344));
    if ((cpu->regs[2])==0) goto L_15bf0c;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_15be00;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_15bf2c;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_15be00;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_15bf2c;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_15be00;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_EQ) goto L_15bf2c;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_15be00;
    cpu->regs[2] = cpu->regs[2] + 24ULL;
    cpu->regs[3] = 3ULL;
L_15bde8:
    PB_LDR(cpu->regs[4], (cpu->regs[2] + (cpu->regs[3] << 3)));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_EQ) goto L_15bf2c;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_NE) goto L_15bde8;
L_15be00:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2400));
L_15be08:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15be18ULL; PB_CALL(5, cpu, tlb, cpu->regs[23]);
    cpu->regs[4] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_EQ) goto L_15bf78;
L_15be24:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_15be40:
    PB_STR((SP + 64), cpu->regs[25]);
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_15c030;
    PB_LDR(cpu->regs[25], (cpu->regs[3] + 40));
    if ((cpu->regs[25])==0) goto L_15c03c;
L_15be50:
    cpu->regs[23] = cpu->regs[25];
    cpu->regs[25] = 0ULL;
L_15be58:
    if ((cpu->regs[23])==0) goto L_15be88;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15be6cULL; PB_CALL(6, cpu, tlb, cpu->regs[23]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    cpu->regs[4] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_15be24;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_15bfd4;
L_15be88:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 96));
    if ((cpu->regs[0])==0) goto L_15beb4;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 40));
    FLAG_CMP(cpu->regs[3], cpu->regs[25]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[23], cpu->regs[3]); } else { FLAG_CMP(0, 0); }
    cpu->regs[0] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[1]))) & (((uint32_t)(cpu->regs[0]))), 0);
    if (FLAG_NE) goto L_15bfe8;
L_15beb4:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 24));
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_NE) goto L_15bf9c;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 3104ULL;
    cpu->regs[30] = PB_BASE + 0x15bef0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11f220ULL);
L_15bef0:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[4] = 0ULL;
    goto L_15bd60;
L_15befc:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2400));
L_15bf04:
    cpu->regs[25] = 0ULL;
    goto L_15be08;
L_15bf0c:
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_15bf2c;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 256));
    if ((cpu->regs[1])!=0) goto L_15bf0c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3488));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_15be00;
L_15bf2c:
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2400));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15bf44ULL; PB_CALL(8, cpu, tlb, cpu->regs[25]);
    cpu->regs[4] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[24]);
    if (FLAG_NE) goto L_15be24;
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15bf04;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15bf04;
    cpu->regs[25] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15bf6cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15be08;
L_15bf70:
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = 0ULL;
L_15bf78:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15bfb8;
L_15bf80:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[23] = cpu->regs[25];
    cpu->regs[25] = cpu->regs[0];
    goto L_15be58;
L_15bf90:
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = 0ULL;
    goto L_15be88;
L_15bf9c:
    PB_LDR(cpu->regs[5], (cpu->regs[21] + 8));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 3168ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 24));
    cpu->regs[30] = PB_BASE + 0x15bfb4ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_15bef0;
L_15bfb8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15bf80;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    cpu->regs[30] = PB_BASE + 0x15bfd0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15bf80;
L_15bfd4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15be88;
    cpu->regs[30] = PB_BASE + 0x15bfe4ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15be88;
L_15bfe8:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x15bff8ULL; PB_CALL(13, cpu, tlb, cpu->regs[3]);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2400));
    cpu->regs[4] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_15be24;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15beb4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15beb4;
    cpu->regs[30] = PB_BASE + 0x15c024ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15beb4;
L_15c028:
    PB_LDR(cpu->regs[25], (SP + 64));
    goto L_15bd38;
L_15c030:
    cpu->regs[25] = 0ULL;
    cpu->regs[23] = 0ULL;
    goto L_15be88;
L_15c03c:
    cpu->regs[23] = 0ULL;
    goto L_15be88;
    SP = SP - 320ULL;
    PB_STR((SP + 224), cpu->regs[29]); PB_STR((SP + 224) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 224ULL;
    PB_STR((SP + 288), cpu->regs[25]); PB_STR((SP + 288) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[0];
    PB_STR((SP + 240), cpu->regs[19]); PB_STR((SP + 240) + 8, cpu->regs[20]);
    PB_STR((SP + 256), cpu->regs[21]); PB_STR((SP + 256) + 8, cpu->regs[22]);
    PB_STR((SP + 272), cpu->regs[23]); PB_STR((SP + 272) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    PB_STR((SP + 304), cpu->regs[27]); PB_STR((SP + 304) + 8, cpu->regs[28]);
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 216), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_STR((SP + 48), 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_15c7a0;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 24) & 1)) goto L_15c7a0;
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_15c5c4;
L_15c0a8:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_15c3ec;
L_15c0b4:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 8));
    PB_STR((SP + 64), cpu->regs[23]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 24) & 1)) goto L_15c524;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_15c790;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 16));
    PB_STR((SP + 56), 0ULL);
    cpu->regs[1] = cpu->regs[2] & 3ULL;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_15c4dc;
    cpu->regs[2] = cpu->regs[2] >> 3;
    cpu->regs[0] = 1ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1];
    cpu->regs[19] = 0ULL;
    cpu->regs[2] = cpu->regs[2] * cpu->regs[0];
    if ((cpu->regs[2])==0) goto L_15c4b0;
L_15c100:
    cpu->regs[0] = cpu->regs[23] + (cpu->regs[2] << 2);
    cpu->regs[22] = cpu->regs[2] - 1ULL; FLAG_CMP(cpu->regs[22], 0);
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + 20));
    if (FLAG_LE) { FLAG_CMP(cpu->regs[24], 3ULL); } else { FLAG_CMP(1, 0); }
    if (FLAG_LS) goto L_15c2c4;
    PB_LDRW(cpu->regs[1], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] + 1ULL));
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_GT) goto L_15cc38;
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 2248));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_15c634;
L_15c130:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 3240));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15cc20;
L_15c138:
    cpu->regs[20] = 2ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_15c174;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(3ULL)));
    if (FLAG_LS) goto L_15c35c;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(7ULL)));
    if (FLAG_LS) goto L_15c3e4;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(15ULL)));
    if (FLAG_LS) goto L_15c3f4;
    cpu->regs[20] = 32ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(31ULL)));
    if (FLAG_LS) goto L_15c174;
L_15c168:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] << 1));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(cpu->regs[20])));
    if (FLAG_HS) goto L_15c168;
L_15c174:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] >> 2));
    cpu->regs[27] = cpu->regs[26];
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_15c210;
L_15c180:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c18cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15c92c;
    if ((cpu->regs[27])==0) goto L_15c1b0;
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_15c1b0;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[2]);
    if ((cpu->regs[2])==0) goto L_15c39c;
L_15c1b0:
    PB_LDR(cpu->regs[21], (SP + 56));
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[21])!=0) goto L_15c3b8;
L_15c1bc:
    cpu->regs[27] = cpu->regs[28];
    cpu->regs[21] = 0ULL;
L_15c1c4:
    FLAG_CMP((((uint32_t)(cpu->regs[24]))) & (((uint32_t)(cpu->regs[20]))), 0);
    if (FLAG_EQ) goto L_15c208;
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c1d8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15c92c;
    if ((cpu->regs[27])==0) goto L_15c1fc;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15c1fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15c364;
L_15c1fc:
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[21])!=0) goto L_15c5e8;
    cpu->regs[27] = cpu->regs[28];
L_15c208:
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] >> 1));
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_15c180;
L_15c210:
    cpu->regs[22] = cpu->regs[22] - 1ULL; FLAG_CMP(cpu->regs[22], 0);
    if (FLAG_GE) goto L_15d118;
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_15c9a8;
L_15c21c:
    cpu->regs[22] = 0ULL;
L_15c220:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15c5d0;
L_15c228:
    PB_LDR(cpu->regs[0], (SP + 64));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_15c49c;
L_15c234:
    PB_LDR(cpu->regs[0], (SP + 56));
    if ((cpu->regs[0])==0) goto L_15c250;
L_15c23c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15c250;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15c34c;
L_15c250:
    if ((cpu->regs[22])==0) goto L_15c268;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c268;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15c378;
L_15c268:
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_15c284;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15c284;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15c38c;
L_15c284:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 216));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_15c63c;
    PB_LDR(cpu->regs[29], (SP + 224)); PB_LDR(cpu->regs[30], (SP + 224) + 8);
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[19], (SP + 240)); PB_LDR(cpu->regs[20], (SP + 240) + 8);
    PB_LDR(cpu->regs[21], (SP + 256)); PB_LDR(cpu->regs[22], (SP + 256) + 8);
    PB_LDR(cpu->regs[23], (SP + 272)); PB_LDR(cpu->regs[24], (SP + 272) + 8);
    PB_LDR(cpu->regs[25], (SP + 288)); PB_LDR(cpu->regs[26], (SP + 288) + 8);
    PB_LDR(cpu->regs[27], (SP + 304)); PB_LDR(cpu->regs[28], (SP + 304) + 8);
    SP = SP + 320ULL;
    return;
L_15c2c4:
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_LS) goto L_15c43c;
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15c2d8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15c988;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 3240));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15c300;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 3240), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15c3fc;
L_15c300:
    PB_LDR(cpu->regs[20], (SP + 56));
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])!=0) goto L_15c640;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_15c410;
L_15c314:
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_15c9a8;
L_15c318:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15c5cc;
    PB_LDR(cpu->regs[0], (SP + 64));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_15c4c0;
    PB_LDR(cpu->regs[0], (SP + 56));
    if ((cpu->regs[0])==0) goto L_15c268;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15c268;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15c268;
    cpu->regs[22] = 0ULL;
L_15c34c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x15c358ULL; PB_CALL(18, cpu, tlb, cpu->regs[1]);
    goto L_15c250;
L_15c35c:
    cpu->regs[20] = 4ULL;
    goto L_15c174;
L_15c364:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x15c374ULL; PB_CALL(19, cpu, tlb, cpu->regs[1]);
    goto L_15c1fc;
L_15c378:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x15c388ULL; PB_CALL(20, cpu, tlb, cpu->regs[1]);
    goto L_15c268;
L_15c38c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x15c398ULL; PB_CALL(21, cpu, tlb, cpu->regs[1]);
    goto L_15c284;
L_15c39c:
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 8));
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x15c3acULL; PB_CALL(22, cpu, tlb, cpu->regs[1]);
    PB_STR((SP + 48), 0ULL);
    PB_LDR(cpu->regs[21], (SP + 56));
    if ((cpu->regs[21])==0) goto L_15c1bc;
L_15c3b8:
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15c3c8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15cabc;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15c3d8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 48));
    PB_STR((SP + 48), 0ULL);
    goto L_15c1c4;
L_15c3e4:
    cpu->regs[20] = 8ULL;
    goto L_15c174;
L_15c3ec:
    PB_STRW((cpu->regs[23] + 0), cpu->regs[0]);
    goto L_15c0b4;
L_15c3f4:
    cpu->regs[20] = 16ULL;
    goto L_15c174;
L_15c3fc:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 3248));
    cpu->regs[0] = cpu->regs[0] + 3240ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x15c40cULL; PB_CALL(25, cpu, tlb, cpu->regs[1]);
    goto L_15c300;
L_15c410:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c41cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15ca30;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[27] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x15c434ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 48), 0ULL);
    goto L_15c314;
L_15c43c:
    if (FLAG_NE) goto L_15c5b4;
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 2248));
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[1] = cpu->regs[28] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0x15c454ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15c990;
    cpu->regs[0] = cpu->regs[28] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0x15c468ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[1], (SP + 56));
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[1])==0) goto L_15c314;
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c480ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15c930;
L_15c488:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c490ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 48));
    PB_STR((SP + 48), 0ULL);
    goto L_15c314;
L_15c49c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15c234;
    cpu->regs[30] = PB_BASE + 0x15c4acULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c234;
L_15c4b0:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2248));
    cpu->regs[27] = cpu->regs[5] + 3240ULL;
    goto L_15c318;
L_15c4c0:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15c914;
    PB_LDR(cpu->regs[0], (SP + 56));
    if ((cpu->regs[0])==0) goto L_15c268;
    cpu->regs[22] = 0ULL;
    goto L_15c23c;
L_15c4dc:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15c8fc;
L_15c4e4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c4f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15c920;
L_15c4f8:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2216));
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[0] = cpu->regs[26];
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 96));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 40));
    cpu->regs[30] = PB_BASE + 0x15c51cULL; PB_CALL(33, cpu, tlb, cpu->regs[3]);
    cpu->regs[27] = cpu->regs[0];
    goto L_15c284;
L_15c524:
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_15c534;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
L_15c534:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_15caa0;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_15ca50;
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = 0ULL;
L_15c558:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    FLAG_CMP(cpu->regs[0], 8ULL);
    if (FLAG_LS) goto L_15c614;
L_15c564:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_15c67c;
L_15c574:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 16));
    cpu->regs[1] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_15cb18;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] >> 3;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_GT) goto L_15cb18;
    PB_LDR(cpu->regs[23], (SP + 64));
L_15c598:
    cpu->regs[2] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[0] & 3ULL;
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1];
    cpu->regs[0] = cpu->regs[0] >> 3;
    cpu->regs[2] = cpu->regs[2] * cpu->regs[0];
    if ((cpu->regs[2])!=0) goto L_15c100;
L_15c5b4:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2248));
    cpu->regs[27] = cpu->regs[5] + 3240ULL;
    goto L_15c314;
L_15c5c4:
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    goto L_15c0a8;
L_15c5cc:
    cpu->regs[22] = 0ULL;
L_15c5d0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c228;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15c5e4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c228;
L_15c5e8:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15c5f8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15cabc;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15c608ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 48));
    PB_STR((SP + 48), 0ULL);
    goto L_15c208;
L_15c614:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_15c564;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2248));
    cpu->regs[22] = 0ULL;
    cpu->regs[27] = cpu->regs[5] + 3208ULL;
    goto L_15c220;
L_15c634:
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    goto L_15c130;
L_15c63c:
    cpu->regs[30] = PB_BASE + 0x15c640ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7c170ULL);
L_15c640:
    cpu->regs[22] = SP + 48ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c654ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15c930;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c664ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[21], (SP + 48));
    PB_STR((SP + 48), 0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_15cac8;
    cpu->regs[27] = cpu->regs[21];
    goto L_15c314;
L_15c67c:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x15c684ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x170a04ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15c8a4;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    PB_STR((SP + 64), cpu->regs[1]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15c8b0;
L_15c69c:
    cpu->regs[0] = SP + 64ULL;
    PB_STR((SP + 48), 0ULL);
    cpu->regs[30] = PB_BASE + 0x15c6a8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x22d820ULL);
    PB_LDR(cpu->regs[0], (SP + 64));
    if ((cpu->regs[0])==0) goto L_15c8a4;
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_15ca48;
L_15c6bc:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_15c6cc;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
L_15c6cc:
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 2248));
    cpu->regs[0] = SP + 80ULL;
    cpu->regs[27] = cpu->regs[26];
    cpu->regs[22] = cpu->regs[20];
    cpu->regs[21] = cpu->regs[28] + 3240ULL;
    cpu->regs[23] = cpu->regs[28] + 3208ULL;
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = SP + 72ULL;
    PB_STR((SP + 16), cpu->regs[0]);
L_15c6f4:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_15c7dc;
    PB_LDR(cpu->regs[3], (SP + 8)); PB_LDR(cpu->regs[2], (SP + 8) + 8);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c714ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x150ac0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15c850;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_15c7c4;
L_15c724:
    PB_LDR(cpu->regs[24], (SP + 72)); PB_LDR(cpu->regs[25], (SP + 72) + 8);
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x15c734ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 0));
    cpu->regs[27] = cpu->regs[0];
    if (!((cpu->regs[2] >> 31) & 1)) goto L_15c7ac;
L_15c740:
    if ((cpu->regs[27])==0) goto L_15c848;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15c750ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1b07c0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[27] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_15c770;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_15c770;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c770ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_15c770:
    if ((cpu->regs[24])==0) goto L_15c848;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15c830;
L_15c77c:
    cpu->regs[21] = cpu->regs[23];
    cpu->regs[27] = cpu->regs[22];
    cpu->regs[23] = cpu->regs[24];
    cpu->regs[22] = cpu->regs[25];
    goto L_15c6f4;
L_15c790:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15ca14;
L_15c798:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15c9fc;
L_15c7a0:
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2400));
    goto L_15c284;
L_15c7ac:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_15c740;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x15c7c0ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c740;
L_15c7c4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15c724;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c7d8ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c724;
L_15c7dc:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c7f8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c7f8;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x15c7f8ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_15c7f8:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15cbf0;
L_15c800:
    cpu->regs[1] = cpu->regs[28] + 3240ULL;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c80cULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x129848ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if ((cpu->regs[0])!=0) goto L_15cbac;
    if (!((cpu->regs[1] >> 31) & 1)) goto L_15cb94;
L_15c818:
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    PB_STR((SP + 48), cpu->regs[21]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15cb7c;
L_15c824:
    cpu->regs[26] = cpu->regs[21];
    PB_STR((SP + 48), 0ULL);
    goto L_15c574;
L_15c830:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c77c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15c844ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c77c;
L_15c848:
    cpu->regs[27] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[25];
L_15c850:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c864;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15c8c8;
L_15c864:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c878;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15c8d4;
L_15c878:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c88c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15c8e0;
L_15c88c:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c8a0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15c8ec;
L_15c8a0:
    PB_STR((SP + 48), 0ULL);
L_15c8a4:
    cpu->regs[22] = 0ULL;
    cpu->regs[27] = 0ULL;
    goto L_15c220;
L_15c8b0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c69c;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x15c8c4ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c69c;
L_15c8c8:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c8d0ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c864;
L_15c8d4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15c8dcULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c878;
L_15c8e0:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x15c8e8ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c88c;
L_15c8ec:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15c8f4ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_STR((SP + 48), 0ULL);
    goto L_15c8a4;
L_15c8fc:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c4e4;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15c910ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c4e4;
L_15c914:
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15c91cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c234;
L_15c920:
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x15c928ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c4f8;
L_15c92c:
    if ((cpu->regs[27])==0) goto L_15c8a4;
L_15c930:
    cpu->regs[21] = 0ULL;
L_15c934:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    cpu->regs[22] = 0ULL;
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c94c;
L_15c940:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15cb60;
L_15c94c:
    cpu->regs[27] = 0ULL;
L_15c950:
    if ((cpu->regs[21])==0) goto L_15c220;
L_15c954:
    cpu->regs[24] = SP + 88ULL;
L_15c958:
    cpu->regs[19] = 0ULL;
L_15c95c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15c978;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15c978;
    cpu->regs[30] = PB_BASE + 0x15c978ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_15c978:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    FLAG_CMP(cpu->regs[19], cpu->regs[21]);
    if (FLAG_EQ) goto L_15c220;
    goto L_15c95c;
L_15c988:
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 2248));
L_15c990:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 3240));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c8a4;
    cpu->regs[27] = cpu->regs[28] + 3240ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[21] = 0ULL;
    goto L_15c940;
L_15c9a8:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_15c21c;
    cpu->regs[21] = 0ULL;
L_15c9bc:
    PB_LDR(cpu->regs[1], (SP + 56));
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15c9c8ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1b07c0ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15c934;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c9e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15cb70;
L_15c9e8:
    PB_STR((SP + 48), 0ULL);
    cpu->regs[27] = cpu->regs[19];
    cpu->regs[22] = 0ULL;
    if ((cpu->regs[21])==0) goto L_15c220;
    goto L_15c954;
L_15c9fc:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c7a0;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x15ca10ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c7a0;
L_15ca14:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c798;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15ca28ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c798;
L_15ca2c:
    cpu->regs[27] = cpu->regs[21];
L_15ca30:
    if ((cpu->regs[27])==0) goto L_15c8a4;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15c8a4;
    cpu->regs[22] = 0ULL;
    cpu->regs[21] = 0ULL;
    goto L_15c940;
L_15ca48:
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    goto L_15c6bc;
L_15ca50:
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x15ca5cULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x170a04ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15c8a4;
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_STR((SP + 56), cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15ca84;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15cb0c;
L_15ca84:
    cpu->regs[0] = SP + 56ULL;
    PB_STR((SP + 48), 0ULL);
    cpu->regs[30] = PB_BASE + 0x15ca90ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x22d820ULL);
    PB_LDR(cpu->regs[20], (SP + 56));
    if ((cpu->regs[20])==0) goto L_15c8a4;
    cpu->regs[19] = 1ULL;
    goto L_15c558;
L_15caa0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 3240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x15cab8ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_15c8a4;
L_15cabc:
    cpu->regs[21] = 0ULL;
L_15cac0:
    cpu->regs[27] = cpu->regs[28];
    goto L_15c934;
L_15cac8:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15cad4ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15ca2c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15cae8ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[27];
    PB_STR((SP + 48), 0ULL);
    cpu->regs[30] = PB_BASE + 0x15cafcULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_15c488;
    cpu->regs[21] = 0ULL;
    goto L_15c934;
L_15cb0c:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x15cb14ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15ca84;
L_15cb18:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15cb28ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1736a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15c8a4;
    PB_LDR(cpu->regs[20], (SP + 48));
    if (((cpu->regs[1] >> 31) & 1)) goto L_15cb50;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15cb50;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15cb50ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_15cb50:
    PB_LDR(cpu->regs[23], (SP + 64));
    cpu->regs[26] = cpu->regs[20];
    PB_STR((SP + 48), 0ULL);
    goto L_15c598;
L_15cb60:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[27] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15cb6cULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c950;
L_15cb70:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cb78ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c9e8;
L_15cb7c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c824;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x15cb90ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c824;
L_15cb94:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_15c818;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cba8ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c818;
L_15cbac:
    if (((cpu->regs[1] >> 31) & 1)) goto L_15cbbc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_15cc08;
L_15cbbc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15cbd0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_15cc14;
L_15cbd0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 3272ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x15cbe8ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_STR((SP + 48), 0ULL);
    goto L_15c8a4;
L_15cbf0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c800;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15cc04ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c800;
L_15cc08:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cc10ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15cbbc;
L_15cc14:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x15cc1cULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15cbd0;
L_15cc20:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 3240), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15c138;
    cpu->regs[0] = cpu->regs[28] + 3240ULL;
    cpu->regs[30] = PB_BASE + 0x15cc34ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15c138;
L_15cc38:
    FLAG_CMP(cpu->regs[1], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_15d0fc;
L_15cc40:
    cpu->regs[1] = cpu->regs[26];
    cpu->regs[0] = cpu->regs[26];
    PB_STR((SP + 88), cpu->regs[26]);
    cpu->regs[30] = PB_BASE + 0x15cc50ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15ce08;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15cc64ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[20], (SP + 56));
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15cc98;
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15cc80ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15ce08;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15cc90ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[22], (SP + 48));
    PB_STR((SP + 48), 0ULL);
L_15cc98:
    cpu->regs[24] = SP + 88ULL;
    cpu->regs[28] = SP + 48ULL;
    cpu->regs[27] = cpu->regs[24];
    cpu->regs[21] = 1ULL;
L_15cca8:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    PB_STR((cpu->regs[27] + 8), 0ULL);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15ccb8ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15ce0c;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x15ccccULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((cpu->regs[27] + 8), cpu->regs[25]);
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15cd04;
    cpu->regs[2] = cpu->regs[28];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x15cce8ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15ce0c;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x15ccf8ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 48));
    PB_STR((cpu->regs[27] + 8), cpu->regs[0]);
    PB_STR((SP + 48), 0ULL);
L_15cd04:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[27] = cpu->regs[27] + 8ULL;
    FLAG_CMP(cpu->regs[21], 16ULL);
    if (FLAG_NE) goto L_15cca8;
    if ((cpu->regs[22])==0) goto L_15cd20;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_15d0e4;
L_15cd20:
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 16));
    cpu->regs[0] = 1ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2248));
    cpu->regs[2] = cpu->regs[1] & 3ULL;
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2];
    cpu->regs[1] = cpu->regs[1] >> 3;
    cpu->regs[2] = cpu->regs[23] + 24ULL;
    cpu->regs[27] = cpu->regs[5] + 3240ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[23] = cpu->regs[0] * cpu->regs[1];
    cpu->regs[0] = SP + 48ULL;
    PB_STR((SP + 16), cpu->regs[0]);
    cpu->regs[23] = cpu->regs[23] - 1ULL;
    PB_STR((SP + 40), cpu->regs[2]);
L_15cd60:
    if (((cpu->regs[23] >> 63) & 1)) goto L_15cf74;
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + (cpu->regs[23] << 2)));
    PB_STRW((SP + 36), cpu->regs[0]);
    cpu->regs[0] = 29ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    goto L_15cd9c;
L_15cd7c:
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] + 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_15ce24;
L_15cd88:
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((SP + 24), cpu->regs[0]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15d0dc;
L_15cd9c:
    PB_LDRB(cpu->regs[1], (SP + 24));
    PB_LDRW(cpu->regs[0], (SP + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] >> (cpu->regs[1] & 63)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] & 1ULL));
    cpu->regs[22] = ((uint32_t)(cpu->regs[0] | (cpu->regs[22] << 1)));
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_15cd7c;
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cdc0ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d064;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cdd4ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15d110;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15cdecULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15cac0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15cdfcULL; PB_CALL(92, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 48));
    PB_STR((SP + 48), 0ULL);
    goto L_15cd88;
L_15ce08:
    cpu->regs[21] = 1ULL;
L_15ce0c:
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 3240));
    if (((cpu->regs[0] >> 31) & 1)) goto L_15d104;
    cpu->regs[27] = cpu->regs[5] + 3240ULL;
    goto L_15c940;
L_15ce24:
    cpu->regs[25] = 0ULL;
    PB_STRW((SP + 8), cpu->regs[22]);
L_15ce2c:
    PB_LDR(cpu->regs[0], (SP + 8));
    if (!((cpu->regs[0] >> 0) & 1)) goto L_15cf60;
    cpu->regs[0] = 5ULL;
    cpu->regs[22] = ((uint32_t)(cpu->regs[0] - cpu->regs[25]));
L_15ce3c:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15ce48ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d064;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15ce5cULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15cf00;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15ce74ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15cac0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15ce84ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 48));
    PB_STR((SP + 48), 0ULL);
L_15ce8c:
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] - 1ULL)); FLAG_CMP(cpu->regs[22], 0);
    if (FLAG_NE) goto L_15ce3c;
    PB_LDRW(cpu->regs[0], (SP + 8));
    cpu->regs[1] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 1)));
    cpu->regs[0] = cpu->regs[27];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3)));
    cpu->regs[30] = PB_BASE + 0x15cea8ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d064;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cebcULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15ceec;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15ced4ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15cac0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15cee4ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[28], (SP + 48));
    PB_STR((SP + 48), 0ULL);
L_15ceec:
    cpu->regs[27] = cpu->regs[28];
    FLAG_CMP(((uint32_t)(cpu->regs[25])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_15cf08;
    cpu->regs[25] = 0ULL;
    goto L_15cd88;
L_15cf00:
    cpu->regs[27] = cpu->regs[28];
    goto L_15ce8c;
L_15cf08:
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15cf14ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d064;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cf28ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15cf58;
    PB_LDR(cpu->regs[2], (SP + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15cf40ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15cac0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15cf50ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[28], (SP + 48));
    PB_STR((SP + 48), 0ULL);
L_15cf58:
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] - 1ULL));
    goto L_15ceec;
L_15cf60:
    PB_LDRW(cpu->regs[0], (SP + 8));
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] + 1ULL));
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 1)));
    PB_STRW((SP + 8), cpu->regs[0]);
    goto L_15ce2c;
L_15cf74:
    cpu->regs[23] = 0ULL;
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_15d040;
L_15cf7c:
    if (!((cpu->regs[22] >> 0) & 1)) goto L_15d0d0;
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] - cpu->regs[23]));
    cpu->regs[0] = SP + 48ULL;
    PB_STR((SP + 8), cpu->regs[0]);
L_15cf8c:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cf98ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d064;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15cfacULL; PB_CALL(106, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15cfdc;
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15cfc4ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15cac0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15cfd4ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[28], (SP + 48));
    PB_STR((SP + 48), 0ULL);
L_15cfdc:
    cpu->regs[25] = ((uint32_t)(cpu->regs[25] - 1ULL)); FLAG_CMP(cpu->regs[25], 0);
    if (FLAG_NE) goto L_15d06c;
    cpu->regs[22] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[22] >> 1)));
    cpu->regs[0] = cpu->regs[28];
    PB_LDR(cpu->regs[1], (cpu->regs[24] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[22])) << 3)));
    cpu->regs[30] = PB_BASE + 0x15cff4ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d060;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15d008ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15d038;
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15d020ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15c934;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15d030ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[27], (SP + 48));
    PB_STR((SP + 48), 0ULL);
L_15d038:
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_15d074;
L_15d040:
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_15d04c;
L_15d044:
    cpu->regs[22] = 0ULL;
    goto L_15c958;
L_15d04c:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 16));
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_15c9bc;
    goto L_15d044;
L_15d060:
    cpu->regs[27] = cpu->regs[28];
L_15d064:
    if ((cpu->regs[27])!=0) goto L_15c934;
    goto L_15d044;
L_15d06c:
    cpu->regs[27] = cpu->regs[28];
    goto L_15cf8c;
L_15d074:
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15d080ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x148760ULL);
    PB_STR((SP + 48), cpu->regs[0]);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_15d064;
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x15d094ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_STR((SP + 48), 0ULL);
    if ((cpu->regs[20])==0) goto L_15d0c4;
    cpu->regs[2] = SP + 48ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15d0acULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x1736a0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_15cac0;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x15d0bcULL; PB_CALL(116, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[28], (SP + 48));
    PB_STR((SP + 48), 0ULL);
L_15d0c4:
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] - 1ULL));
    cpu->regs[27] = cpu->regs[28];
    goto L_15d038;
L_15d0d0:
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    cpu->regs[22] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[22] >> 1)));
    goto L_15cf7c;
L_15d0dc:
    cpu->regs[23] = cpu->regs[23] - 1ULL;
    goto L_15cd60;
L_15d0e4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_15cd20;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x15d0f8ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_15cd20;
L_15d0fc:
    PB_STRW((cpu->regs[26] + 0), cpu->regs[0]);
    goto L_15cc40;
L_15d104:
    cpu->regs[24] = SP + 88ULL;
    cpu->regs[27] = 0ULL;
    goto L_15c958;
L_15d110:
    cpu->regs[27] = cpu->regs[28];
    goto L_15cd88;
L_15d118:
    cpu->regs[0] = cpu->regs[23] + 24ULL;
    cpu->regs[20] = 536870912ULL;
    PB_LDRW(cpu->regs[24], (cpu->regs[0] + (cpu->regs[22] << 2)));
    goto L_15c180;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    return;
    cpu->regs[0] = cpu->regs[1];
    { PB_CALL(118, cpu, tlb, PB_BASE + 0x14d650ULL); return; };
    /* nop */
    /* nop */
}
