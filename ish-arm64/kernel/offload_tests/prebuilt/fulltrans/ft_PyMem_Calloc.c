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

void ft_PyMem_Calloc(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[2])==0) goto L_dbde8;
    FLAG_CMP(cpu->regs[2], 56ULL);
    if (FLAG_NE) goto L_dbe00;
    cpu->regs[0] = 37449ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x4924ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[0] | (cpu->regs[0] << 27);
L_dbde0:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HI) goto L_dbe0c;
L_dbde8:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 136));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 152));
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_dbe00:
    cpu->regs[0] = 9223372036854775807ULL;
    cpu->regs[0] = (cpu->regs[2] ? cpu->regs[0] / cpu->regs[2] : 0);
    goto L_dbde0;
L_dbe0c:
    cpu->regs[0] = 0ULL;
    return;
    /* nop */
    /* nop */
    /* nop */
    PB_LDR(cpu->regs[7], (cpu->regs[0] + 16));
    cpu->regs[6] = cpu->regs[0] + 192ULL;
    FLAG_CMP(cpu->regs[7], 0ULL);
    if (FLAG_LE) goto L_dbec8;
    cpu->regs[17] = PB_BASE + 0x2b7000ULL;
    cpu->regs[17] = cpu->regs[17] + 1840ULL;
    cpu->regs[10] = cpu->regs[17] + 1808ULL;
    cpu->regs[9] = cpu->regs[17] + 2064ULL;
    cpu->regs[8] = cpu->regs[17] + 2320ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[11] = 31868ULL;
    cpu->regs[13] = 32124ULL;
    cpu->regs[15] = 32125ULL;
    cpu->regs[12] = 25724ULL;
    cpu->regs[14] = 31844ULL;
    cpu->regs[16] = 17ULL;
L_dbe68:
    cpu->regs[5] = cpu->regs[1] << 1;
    PB_LDRB(cpu->regs[2], (cpu->regs[6] + cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(254ULL)));
    if (FLAG_EQ) goto L_dbf60;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(253ULL)));
    if (FLAG_EQ) goto L_dbf80;
L_dbe80:
    PB_LDRB(cpu->regs[1], (cpu->regs[10] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_dbf04;
    PB_LDRB(cpu->regs[1], (cpu->regs[9] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    PB_LDRB(cpu->regs[2], (cpu->regs[8] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]))));
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_dbf10;
L_dbe94:
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] | (cpu->regs[3] << 8)));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[11])));
    if (FLAG_EQ) goto L_dbf24;
    if (FLAG_GT) goto L_dbee0;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[12])));
    if (FLAG_EQ) goto L_dbf4c;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[14])));
    if (FLAG_EQ) goto L_dbecc;
L_dbeb4:
    cpu->regs[3] = cpu->regs[1];
L_dbeb8:
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[4]));
    FLAG_CMP(cpu->regs[1], cpu->regs[7]);
    if (FLAG_LT) goto L_dbe68;
L_dbec8:
    return;
L_dbecc:
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 1ULL));
    cpu->regs[3] = 86ULL;
    cpu->regs[2] = (((uint64_t)(((int64_t)(cpu->regs[2] << 32)) >> 32) & 0xffffffffULL) << 1);
    PB_STRB((cpu->regs[6] + cpu->regs[2]), cpu->regs[3]);
    goto L_dbeb4;
L_dbee0:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[13])));
    if (FLAG_EQ) goto L_dbf38;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[15])));
    if (FLAG_NE) goto L_dbeb4;
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 1ULL));
    cpu->regs[3] = 4294967198ULL;
    cpu->regs[2] = (((uint64_t)(((int64_t)(cpu->regs[2] << 32)) >> 32) & 0xffffffffULL) << 1);
    PB_STRB((cpu->regs[6] + cpu->regs[2]), cpu->regs[3]);
    goto L_dbeb4;
L_dbf04:
    cpu->regs[2] = cpu->regs[17] + 2320ULL;
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + ((uint64_t)(uint32_t)(cpu->regs[1]))));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_dbe94;
L_dbf10:
    cpu->regs[5] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + cpu->regs[2]));
    PB_STRH((cpu->regs[6] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[5])) << 1)), cpu->regs[16]);
    goto L_dbeb8;
L_dbf24:
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 1ULL));
    cpu->regs[3] = 88ULL;
    cpu->regs[2] = (((uint64_t)(((int64_t)(cpu->regs[2] << 32)) >> 32) & 0xffffffffULL) << 1);
    PB_STRB((cpu->regs[6] + cpu->regs[2]), cpu->regs[3]);
    goto L_dbeb4;
L_dbf38:
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 1ULL));
    cpu->regs[3] = 4294967194ULL;
    cpu->regs[2] = (((uint64_t)(((int64_t)(cpu->regs[2] << 32)) >> 32) & 0xffffffffULL) << 1);
    PB_STRB((cpu->regs[6] + cpu->regs[2]), cpu->regs[3]);
    goto L_dbeb4;
L_dbf4c:
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] - 1ULL));
    cpu->regs[3] = 84ULL;
    cpu->regs[2] = (((uint64_t)(((int64_t)(cpu->regs[2] << 32)) >> 32) & 0xffffffffULL) << 1);
    PB_STRB((cpu->regs[6] + cpu->regs[2]), cpu->regs[3]);
    goto L_dbeb4;
L_dbf60:
    PB_LDR(cpu->regs[18], (cpu->regs[0] + 168));
    PB_LDR(cpu->regs[2], (cpu->regs[18] + 40));
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + cpu->regs[5]));
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(253ULL)));
    if (FLAG_NE) goto L_dbe80;
L_dbf74:
    PB_LDR(cpu->regs[2], (cpu->regs[18] + 56));
    PB_LDRB(cpu->regs[2], (cpu->regs[2] + cpu->regs[1]));
    goto L_dbe80;
L_dbf80:
    PB_LDR(cpu->regs[18], (cpu->regs[0] + 168));
    goto L_dbf74;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xdbfa4ULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[1] * cpu->regs[2];
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[4] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_dc0b8;
L_dbfd4:
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    FLAG_CMP(cpu->regs[0], 511ULL);
    if (FLAG_HI) goto L_dc078;
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[0] = cpu->regs[21] + 3960ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] >> 4));
    cpu->regs[1] = ((cpu->regs[4] & 0xfffffffULL) << 1);
    PB_LDR(cpu->regs[3], (cpu->regs[0] + (cpu->regs[1] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    if (FLAG_EQ) goto L_dc09c;
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 8));
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    PB_STR((cpu->regs[3] + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_dc040;
L_dc01c:
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xdc028ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7aee0ULL);
    cpu->regs[5] = cpu->regs[0];
L_dc02c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[5];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_dc040:
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 40)); PB_LDRW(cpu->regs[6], (cpu->regs[3] + 40) + 4);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[6])));
    if (FLAG_LS) goto L_dc05c;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 24));
    PB_STR((cpu->regs[1] + 24), cpu->regs[0]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[1]);
    goto L_dc01c;
L_dc05c:
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] + 1ULL));
    cpu->regs[1] = cpu->regs[3] + ((cpu->regs[0]) & 0xffffffffULL);
    PB_STR((cpu->regs[3] + 8), cpu->regs[1]);
    cpu->regs[4] = ((uint32_t)(cpu->regs[0] + (cpu->regs[4] << 4)));
    PB_STRW((cpu->regs[3] + 40), cpu->regs[4]);
    PB_STR((cpu->regs[3] + ((uint64_t)(uint32_t)(cpu->regs[0]))), 0ULL);
    if ((cpu->regs[5])!=0) goto L_dc01c;
L_dc078:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xdc084ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd83a0ULL);
    cpu->regs[5] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_dc02c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 5048));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[21] + 5048), cpu->regs[0]);
    goto L_dc02c;
L_dc09c:
    cpu->regs[1] = cpu->regs[4];
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0xdc0a8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd8ff0ULL);
    cpu->regs[5] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 56));
    if ((cpu->regs[5])!=0) goto L_dc01c;
    goto L_dc078;
L_dc0b8:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 1712));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_dc0dc;
    cpu->regs[1] = cpu->regs[4] + 24ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[4] = cpu->regs[4] + (18ULL << 12);
    cpu->regs[4] = cpu->regs[4] + 1936ULL;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[0], cpu->regs[4]); } else { FLAG_CMP(0, 1); }
    if (FLAG_NE) goto L_dbfd4;
L_dc0dc:
    cpu->regs[21] = cpu->regs[0];
    goto L_dbfd4;
}
