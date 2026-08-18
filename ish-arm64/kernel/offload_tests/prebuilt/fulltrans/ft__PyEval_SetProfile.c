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

void ft__PyEval_SetProfile(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_bd91c:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xbd940ULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[1];
    cpu->regs[21] = cpu->regs[2];
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1984ULL;
    cpu->regs[30] = PB_BASE + 0xbd960ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x181ea8ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_bdacc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] + (93ULL << 12);
    PB_LDRB(cpu->regs[1], (cpu->regs[0] + 832));
    if (!((cpu->regs[1] >> 0) & 1)) goto L_bd99c;
L_bd974:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 64));
    FLAG_CMP(cpu->regs[22], 0ULL);
    cpu->regs[20] = (FLAG_NE) ? 1 : 0;
    PB_STR((cpu->regs[19] + 64), cpu->regs[22]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] - cpu->regs[1]));
    if ((cpu->regs[21])!=0) goto L_bda84;
    goto L_bda94;
L_bd99c:
    cpu->regs[1] = 1ULL;
    PB_STRB((cpu->regs[0] + 832), cpu->regs[1]);
    cpu->regs[4] = 1ULL;
    cpu->regs[1] = PB_BASE + 0x9c000ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 644ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[30] = PB_BASE + 0xbd9c0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x24108cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdacc;
    cpu->regs[20] = PB_BASE + 0x9c000ULL;
    cpu->regs[20] = cpu->regs[20] + 636ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[3] = 13ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[30] = PB_BASE + 0xbd9e4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x24108cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdacc;
    cpu->regs[4] = 3ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[4];
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[30] = PB_BASE + 0xbda00ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x24108cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdacc;
    cpu->regs[1] = PB_BASE + 0x9c000ULL;
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[1] = cpu->regs[1] + 624ULL;
    cpu->regs[3] = 12ULL;
    cpu->regs[2] = 3ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[30] = PB_BASE + 0xbda20ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x24108cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdacc;
    cpu->regs[20] = PB_BASE + 0x9c000ULL;
    cpu->regs[20] = cpu->regs[20] + 376ULL;
    cpu->regs[3] = 4ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[30] = PB_BASE + 0xbda44ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x24108cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdacc;
    cpu->regs[2] = 6ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[3] = 15ULL;
    cpu->regs[30] = PB_BASE + 0xbda60ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x24108cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdacc;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[3] = 16ULL;
    cpu->regs[2] = 5ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[30] = PB_BASE + 0xbda7cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x24108cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_bd974;
    goto L_bdacc;
L_bda84:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_bda94;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[1]);
L_bda94:
    PB_STR((cpu->regs[19] + 80), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0xbda9cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 16));
    cpu->regs[1] = 12319ULL;
    cpu->regs[0] = 6ULL;
    cpu->regs[3] = cpu->regs[3] + (88ULL << 12);
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 21320));
    cpu->regs[2] = cpu->regs[2] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[20])); FLAG_CMP(cpu->regs[2], 0);
    PB_STR((cpu->regs[3] + 21320), cpu->regs[2]);
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[1] : 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x2411a4ULL); return; };
L_bdacc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2760));
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xbdb08ULL; PB_CALL(12, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[0]));
    FLAG_CMP(cpu->regs[2], cpu->regs[3]);
    if (FLAG_NE) goto L_bdb30;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xbdb20ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xbd91cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_bdb40;
L_bdb24:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_bdb44;
L_bdb30:
    cpu->regs[1] = PB_BASE + 0xc6000ULL;
    cpu->regs[1] = cpu->regs[1] + 2984ULL;
    cpu->regs[30] = PB_BASE + 0xbdb3cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xbd91cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_bdb24;
L_bdb40:
    cpu->regs[0] = 0ULL;
L_bdb44:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_bdb7c;
L_bdb64:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0xbdb6cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_bdba4;
    goto L_bdb9c;
L_bdb7c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a5000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 2000ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xbdb94ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdb64;
    goto L_bdc28;
L_bdb9c:
    cpu->regs[30] = PB_BASE + 0xbdba0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_bdc28;
L_bdba4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0xbdbacULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x13ae00ULL);
    cpu->regs[19] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_bdbc0;
    cpu->regs[30] = PB_BASE + 0xbdbbcULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_bdc28;
L_bdbc0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xbdbc8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x9718cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdc28;
    cpu->regs[0] = 131071ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LS) goto L_bdbf8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a5000ULL;
    cpu->regs[1] = cpu->regs[1] + 2016ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xbdbf4ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_bdc28;
L_bdbf8:
    FLAG_CMP((((uint32_t)(cpu->regs[19]))) & (((uint32_t)(98304ULL))), 0);
    if (FLAG_EQ) goto L_bdc30;
    cpu->regs[0] = 32784ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 16)) | ((0x1ULL & 0xffff) << 16);
    FLAG_CMP(((uint32_t)(((uint32_t)(cpu->regs[0] & ~(cpu->regs[19]))))), 0);
    if (FLAG_EQ) goto L_bdc30;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 3792ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xbdc28ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x11f220ULL);
L_bdc28:
    cpu->regs[0] = 0ULL;
    goto L_bdc48;
L_bdc30:
    cpu->regs[1] = ((uint32_t)(cpu->regs[19] & 4294868991ULL));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xbdc3cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x2411a4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_bdc28;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_bdc48:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
