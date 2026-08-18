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

void ft_PyObject_RichCompare(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x11ed2cULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_LDR(cpu->regs[23], (cpu->regs[3] + cpu->regs[0]));
    if (FLAG_EQ) goto L_11f004;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[19] = cpu->regs[1];
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + 36));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_STRW((cpu->regs[23] + 36), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_11ee30;
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[4]);
    if (FLAG_NE) goto L_11ee60;
L_11ed70:
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 200));
    if ((cpu->regs[3])==0) goto L_11f048;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2400));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x11ed90ULL; PB_CALL(2, cpu, tlb, cpu->regs[3]);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_EQ) goto L_11edc0;
L_11ed9c:
    PB_LDRW(cpu->regs[0], (cpu->regs[23] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[23] + 36), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_11edac:
    cpu->regs[0] = cpu->regs[3];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_11edc0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[24] = 0ULL;
    if (!((cpu->regs[0] >> 31) & 1)) goto L_11ef68;
L_11edcc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 200));
    if ((cpu->regs[3])==0) goto L_11ee04;
L_11edd8:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3464));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 2)));
    cpu->regs[30] = PB_BASE + 0x11edf0ULL; PB_CALL(3, cpu, tlb, cpu->regs[3]);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_11ed9c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_11f02c;
L_11ee04:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_11ef90;
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    if (FLAG_EQ) goto L_11f05c;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3184));
L_11ee1c:
    PB_LDRW(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_11ed9c;
    PB_STRW((cpu->regs[3] + 0), cpu->regs[0]);
    goto L_11ed9c;
L_11ee30:
    cpu->regs[1] = PB_BASE + 0x288000ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[1] + 3968ULL;
    cpu->regs[30] = PB_BASE + 0x11ee40ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x26c444ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_11eff8;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 8));
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_EQ) goto L_11ed70;
    /* nop */
    /* nop */
    /* nop */
L_11ee60:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 344));
    if ((cpu->regs[0])==0) goto L_11eed4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_11ed70;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_11eef8;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_11ed70;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 32));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_11eef8;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_11ed70;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 40));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_EQ) goto L_11eef8;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_11ed70;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[3] = 3ULL;
L_11eeb8:
    PB_LDR(cpu->regs[5], (cpu->regs[0] + (cpu->regs[3] << 3)));
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    FLAG_CMP(cpu->regs[5], cpu->regs[2]);
    if (FLAG_EQ) goto L_11eef8;
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_NE) goto L_11eeb8;
    goto L_11ed70;
L_11eed4:
    cpu->regs[0] = cpu->regs[4];
L_11eed8:
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_EQ) goto L_11eef8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 256));
    if ((cpu->regs[0])!=0) goto L_11eed8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3488));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_11ed70;
L_11eef8:
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 200));
    if ((cpu->regs[3])==0) goto L_11ed70;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3464));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2400));
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[2], (cpu->regs[2] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 2)));
    cpu->regs[30] = PB_BASE + 0x11ef20ULL; PB_CALL(5, cpu, tlb, cpu->regs[3]);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_11ed9c;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_11f068;
L_11ef34:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 200));
    if ((cpu->regs[3])==0) goto L_11ee04;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x11ef50ULL; PB_CALL(6, cpu, tlb, cpu->regs[3]);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_NE) goto L_11ed9c;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_11ee04;
    cpu->regs[24] = 1ULL;
L_11ef68:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_11ef88;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x11ef88ULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
L_11ef88:
    if ((((uint32_t)(cpu->regs[24])))==0) goto L_11edcc;
    goto L_11ee04;
L_11ef90:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_11efdc;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x3da000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[0] + 2560ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[0] + 1696ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[2] + 24));
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[20])) << 3)));
    cpu->regs[2] = cpu->regs[2] + 3984ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 24));
    cpu->regs[30] = PB_BASE + 0x11efd4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x225d40ULL);
    cpu->regs[3] = 0ULL;
    goto L_11ed9c;
L_11efdc:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3664));
    FLAG_CMP(cpu->regs[22], cpu->regs[19]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    cpu->regs[3] = (FLAG_NE) ? cpu->regs[3] : cpu->regs[0];
    goto L_11ee1c;
L_11eff8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
L_11effc:
    cpu->regs[3] = 0ULL;
    goto L_11edac;
L_11f004:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])==0) goto L_11f014;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_11effc;
L_11f014:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = 858ULL;
    cpu->regs[0] = cpu->regs[0] + 3944ULL;
    cpu->regs[30] = PB_BASE + 0x11f024ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[3] = 0ULL;
    goto L_11edac;
L_11f02c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11ee04;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x11f044ULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    goto L_11ee04;
L_11f048:
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 200));
    if ((cpu->regs[3])==0) goto L_11ee04;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2400));
    goto L_11edd8;
L_11f05c:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3664));
    goto L_11ee1c;
L_11f068:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11ef34;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x11f080ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    goto L_11ef34;
}
