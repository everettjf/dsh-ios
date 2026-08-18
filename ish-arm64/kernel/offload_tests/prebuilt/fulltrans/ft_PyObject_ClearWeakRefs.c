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

void ft_PyObject_ClearWeakRefs(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    if ((cpu->regs[0])==0) goto L_13f8c8;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 208));
    if ((cpu->regs[0])==0) goto L_13f8c8;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0));
    if ((cpu->regs[21])!=0) goto L_13f8b0;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (((cpu->regs[2] >> 31) & 1)) goto L_13f73c;
L_13f720:
    cpu->regs[19] = cpu->regs[0] + cpu->regs[1];
L_13f724:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0));
    if ((cpu->regs[20])!=0) goto L_13f77c;
L_13f72c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_13f73c:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    cpu->regs[19] = cpu->regs[1] + cpu->regs[0];
    if (!((cpu->regs[2] >> 1) & 1)) goto L_13f724;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x13f75cULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 360));
    cpu->regs[3] = 40ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[2] = 46016ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 16)) | ((0x5ULL & 0xffff) << 16);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] * cpu->regs[3] + cpu->regs[2];
    goto L_13f720;
L_13f77c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    if ((cpu->regs[0])==0) goto L_13f814;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
L_13f788:
    cpu->regs[23] = cpu->regs[20];
    if ((cpu->regs[20])==0) goto L_13f8d8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[19] = 0ULL;
L_13f798:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    if ((cpu->regs[0])!=0) goto L_13f798;
    cpu->regs[30] = PB_BASE + 0x13f7a8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x121f0cULL);
    cpu->regs[22] = cpu->regs[0];
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_NE) goto L_13f840;
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 24));
    PB_STR((cpu->regs[20] + 24), 0ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x13f7c4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1a1f20ULL);
    if ((cpu->regs[19])==0) goto L_13f7fc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_13f7e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f7e0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1bed80ULL);
L_13f7e0:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_13f7fc;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_13f7fc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f7fcULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_13f7fc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x121f40ULL); return; };
L_13f814:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x13f81cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1a1f20ULL);
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0));
    if ((cpu->regs[20])==0) goto L_13f72c;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    if ((cpu->regs[0])!=0) goto L_13f788;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x13f838ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1a1f20ULL);
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 0));
    goto L_13f788;
L_13f840:
    cpu->regs[0] = cpu->regs[19] << 1;
    cpu->regs[30] = PB_BASE + 0x13f848ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdb480ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_13f8e0;
    cpu->regs[24] = cpu->regs[0] + 24ULL;
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[26] = cpu->regs[24];
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[27] = 0ULL;
L_13f864:
    FLAG_CMP(cpu->regs[27], cpu->regs[19]);
    if (FLAG_GE) goto L_13f910;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 24));
    PB_LDR(cpu->regs[25], (cpu->regs[23] + 48));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_13f938;
    PB_LDRW(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_13f890;
    PB_STRW((cpu->regs[23] + 0), cpu->regs[1]);
L_13f890:
    PB_STR((cpu->regs[26] + 0), cpu->regs[23]); PB_STR((cpu->regs[26] + 0) + 8, cpu->regs[0]);
L_13f894:
    cpu->regs[0] = cpu->regs[23];
    PB_STR((cpu->regs[23] + 24), 0ULL);
    cpu->regs[27] = cpu->regs[27] + 1ULL;
    cpu->regs[26] = cpu->regs[26] + 16ULL;
    cpu->regs[23] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x13f8acULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1a1f20ULL);
    goto L_13f864;
L_13f8b0:
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    cpu->regs[0] = cpu->regs[0] + 1464ULL;
    cpu->regs[1] = 946ULL;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x9bb50ULL); return; };
L_13f8c8:
    cpu->regs[0] = PB_BASE + 0x288000ULL;
    cpu->regs[1] = 946ULL;
    cpu->regs[0] = cpu->regs[0] + 1464ULL;
    { PB_CALL(12, cpu, tlb, PB_BASE + 0x9bb50ULL); return; };
L_13f8d8:
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    goto L_13f72c;
L_13f8e0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x1cd8e0ULL); return; };
L_13f8f8:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    if ((cpu->regs[1])==0) goto L_13f908;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    cpu->regs[30] = PB_BASE + 0x13f908ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1bed80ULL);
L_13f908:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[24] = cpu->regs[24] + 16ULL;
L_13f910:
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    if (FLAG_LT) goto L_13f8f8;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_13f92c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_13f954;
L_13f92c:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_13f7fc;
L_13f938:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[1] = cpu->regs[2] - 1ULL;
    if (((cpu->regs[2] >> 31) & 1)) goto L_13f894;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_13f894;
    cpu->regs[30] = PB_BASE + 0x13f950ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13f894;
L_13f954:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x13f95cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    goto L_13f7fc;
    if ((cpu->regs[0])==0) goto L_13f9cc;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
L_13f988:
    cpu->regs[19] = cpu->regs[21];
L_13f98c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 176));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 208));
    if ((cpu->regs[1])==0) goto L_13f9d0;
    cpu->regs[30] = PB_BASE + 0x13f9a0ULL; PB_CALL(17, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 0));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 176));
    cpu->regs[19] = cpu->regs[21];
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 208));
    cpu->regs[30] = PB_BASE + 0x13f9b8ULL; PB_CALL(18, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[21])!=0) goto L_13f98c;
L_13f9bc:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_13f9cc:
    return;
L_13f9d0:
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 0));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13f9dcULL; PB_CALL(19, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[21])!=0) goto L_13f988;
    goto L_13f9bc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[5]);
    if (FLAG_HS) goto L_13fa58;
    if ((cpu->regs[2])!=0) goto L_13fa14;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[2] = cpu->regs[1] + 1ULL;
    cpu->regs[3] = 0ULL;
    { PB_CALL(20, cpu, tlb, PB_BASE + 0x129a00ULL); return; };
L_13fa14:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[1] << 3;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + cpu->regs[3]));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_13fa30;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_13fa30:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[4] + cpu->regs[3]), cpu->regs[2]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_13fa4c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_13fa4c;
    cpu->regs[30] = PB_BASE + 0x13fa4cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_13fa4c:
    cpu->regs[0] = 0ULL;
L_13fa50:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_13fa58:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3880));
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 936ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x13fa70ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_13fa50;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[22], (cpu->regs[0] + 8) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 168));
    if (!((cpu->regs[1] >> 23) & 1)) goto L_13fb3c;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 32));
    cpu->regs[19] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_13fafc;
L_13fab0:
    cpu->regs[20] = 0ULL;
    /* nop */
    /* nop */
    /* nop */
L_13fac0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(16ULL)));
    if (FLAG_NE) goto L_13faec;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    if (((cpu->regs[0] >> 0) & 1)) goto L_13faec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + cpu->regs[0]));
    if ((cpu->regs[2])==0) goto L_13faec;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[21] + cpu->regs[0]), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_13fb0c;
L_13faec:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 40ULL;
    FLAG_CMP(cpu->regs[22], cpu->regs[20]);
    if (FLAG_NE) goto L_13fac0;
L_13fafc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_13fb0c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[2];
    if ((cpu->regs[1])!=0) goto L_13faec;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 40ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13fb30ULL; PB_CALL(23, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[20], cpu->regs[22]);
    if (FLAG_NE) goto L_13fac0;
    goto L_13fafc;
L_13fb3c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3408ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x13fb58ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x11f220ULL);
    FLAG_CMP(cpu->regs[22], 0ULL);
    if (FLAG_LE) goto L_13fafc;
    cpu->regs[19] = 0ULL;
    goto L_13fab0;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 120));
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 120));
    if ((cpu->regs[1])==0) goto L_13fddc;
L_13fb8c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x13fb94ULL; PB_CALL(25, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 24));
    cpu->regs[1] = 36123ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0x134ULL & 0xffff) << 16);
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[1];
    cpu->regs[1] = 16963ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 8));
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    cpu->regs[20] = cpu->regs[0] * cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])==0) goto L_13fe4c;
L_13fbc4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13fbccULL; PB_CALL(26, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[20];
    cpu->regs[1] = 16963ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 8));
    cpu->regs[20] = cpu->regs[0] * cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])==0) goto L_13fea4;
L_13fbf4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13fbfcULL; PB_CALL(27, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 96));
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[20];
    cpu->regs[1] = 16963ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 8));
    cpu->regs[20] = cpu->regs[0] * cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])==0) goto L_13fe18;
L_13fc24:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13fc2cULL; PB_CALL(28, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 136));
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[20];
    cpu->regs[1] = 16963ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 8));
    cpu->regs[20] = cpu->regs[0] * cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])==0) goto L_13fecc;
L_13fc54:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13fc5cULL; PB_CALL(29, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 40));
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[20];
    cpu->regs[1] = 16963ULL;
    cpu->regs[1] = (cpu->regs[1] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 8));
    cpu->regs[20] = cpu->regs[0] * cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])==0) goto L_13fe74;
L_13fc84:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13fc8cULL; PB_CALL(30, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    cpu->regs[0] = cpu->regs[0] ^ cpu->regs[20];
    cpu->regs[4] = 16963ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[19] + 48),&_a,4); tlb_read(tlb,(cpu->regs[19] + 52),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[1]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[19] + 56),&_a,4); tlb_read(tlb,(cpu->regs[19] + 60),&_b,4); cpu->regs[5]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[0] = cpu->regs[1] ^ cpu->regs[0];
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[19] + 68),&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    PB_LDR(cpu->regs[8], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4];
    cpu->regs[0] = cpu->regs[5] ^ cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4];
    cpu->regs[0] = cpu->regs[3] ^ cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4];
    cpu->regs[0] = cpu->regs[2] ^ cpu->regs[0];
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4];
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[0];
    cpu->regs[1] = cpu->regs[1] * cpu->regs[4];
    cpu->regs[1] = cpu->regs[8] ^ cpu->regs[1];
    cpu->regs[0] = cpu->regs[1] * cpu->regs[4];
    FLAG_CMP(cpu->regs[8], 0ULL);
    if (FLAG_LE) goto L_13fd64;
    cpu->regs[12] = PB_BASE + 0x2b7000ULL;
    cpu->regs[12] = cpu->regs[12] + 1840ULL;
    cpu->regs[11] = cpu->regs[12] + 1808ULL;
    cpu->regs[10] = cpu->regs[12] + 2064ULL;
    cpu->regs[9] = cpu->regs[12] + 2320ULL;
    cpu->regs[5] = cpu->regs[19] + 192ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = 0ULL;
L_13fd0c:
    cpu->regs[7] = cpu->regs[3] << 1;
    cpu->regs[6] = cpu->regs[5] + (cpu->regs[3] << 1);
    PB_LDRB(cpu->regs[1], (cpu->regs[5] + cpu->regs[7]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(254ULL)));
    if (FLAG_EQ) goto L_13fd7c;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(253ULL)));
    if (FLAG_EQ) goto L_13fe9c;
L_13fd28:
    PB_LDRB(cpu->regs[3], (cpu->regs[11] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]))));
    cpu->regs[7] = ((uint32_t)(cpu->regs[2] + 1ULL));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_13fd9c;
    PB_LDRB(cpu->regs[1], (cpu->regs[10] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]))));
    PB_LDRB(cpu->regs[3], (cpu->regs[6] + 1));
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[0];
    PB_LDRB(cpu->regs[2], (cpu->regs[9] + ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]))));
    cpu->regs[1] = cpu->regs[1] * cpu->regs[4];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + cpu->regs[7]));
    cpu->regs[1] = cpu->regs[3] ^ cpu->regs[1];
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    cpu->regs[0] = cpu->regs[1] * cpu->regs[4];
    FLAG_CMP(cpu->regs[8], cpu->regs[3]);
    if (FLAG_GT) goto L_13fd0c;
L_13fd64:
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe10;
L_13fd6c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_13fd7c:
    PB_LDR(cpu->regs[13], (cpu->regs[19] + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[13] + 40));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[7]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(253ULL)));
    if (FLAG_NE) goto L_13fd28;
L_13fd90:
    PB_LDR(cpu->regs[1], (cpu->regs[13] + 56));
    PB_LDRB(cpu->regs[1], (cpu->regs[1] + cpu->regs[3]));
    goto L_13fd28;
L_13fd9c:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[13] = 16963ULL;
    cpu->regs[0] = cpu->regs[1] ^ cpu->regs[0];
    cpu->regs[13] = (cpu->regs[13] & ~(0xffffULL << 16)) | ((0xfULL & 0xffff) << 16);
    cpu->regs[7] = cpu->regs[12] + 2320ULL;
    PB_LDRB(cpu->regs[1], (cpu->regs[6] + 1));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL));
    cpu->regs[0] = cpu->regs[0] * cpu->regs[13];
    PB_LDRB(cpu->regs[3], (cpu->regs[7] + ((uint64_t)(uint32_t)(cpu->regs[3]))));
    cpu->regs[1] = cpu->regs[1] ^ cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] + cpu->regs[2]));
    cpu->regs[0] = cpu->regs[1] * cpu->regs[13];
    cpu->regs[3] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[2]));
    FLAG_CMP(cpu->regs[8], cpu->regs[2]);
    if (FLAG_GT) goto L_13fd0c;
    goto L_13fd64;
L_13fddc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13fde4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])!=0) goto L_13fe00;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13fdf0ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 120));
    if ((cpu->regs[1])!=0) goto L_13fb8c;
L_13fe00:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x13fe08ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x23d444ULL);
L_13fe08:
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_13fd6c;
L_13fe10:
    cpu->regs[0] = 18446744073709551614ULL;
    goto L_13fd6c;
L_13fe18:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13fe20ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])!=0) goto L_13fe3c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13fe2cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])!=0) goto L_13fc24;
L_13fe3c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x13fe44ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x23d444ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_13fd6c;
L_13fe4c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13fe54ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])!=0) goto L_13fe3c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13fe60ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])!=0) goto L_13fbc4;
    goto L_13fe3c;
L_13fe74:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13fe7cULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])!=0) goto L_13fe3c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13fe88ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])!=0) goto L_13fc84;
    goto L_13fe3c;
L_13fe9c:
    PB_LDR(cpu->regs[13], (cpu->regs[19] + 168));
    goto L_13fd90;
L_13fea4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13feacULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])!=0) goto L_13fe3c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13feb8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])!=0) goto L_13fbf4;
    goto L_13fe3c;
L_13fecc:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13fed4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xdb420ULL);
    if ((cpu->regs[0])!=0) goto L_13fe3c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x13fee0ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x18e404ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_13fe08;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 120));
    if ((cpu->regs[1])!=0) goto L_13fc54;
    goto L_13fe3c;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x13ff28ULL; PB_CALL(45, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[22], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[2] & 9223372036854775807ULL; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_140068;
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_13ffd8;
L_13ff4c:
    if ((cpu->regs[3])!=0) goto L_1400f4;
L_13ff50:
    cpu->regs[1] = cpu->regs[2] - 1ULL;
    cpu->regs[0] = cpu->regs[20] + 8ULL;
    cpu->regs[30] = PB_BASE + 0x13ff5cULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xdc780ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_140050;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[22] + 36), cpu->regs[1]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1400b8;
L_13ff78:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    if ((cpu->regs[2])==0) goto L_1400cc;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x13ff90ULL; PB_CALL(47, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_140058;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_140058;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x13ffb8ULL; PB_CALL(48, cpu, tlb, cpu->regs[1]);
    PB_LDRW(cpu->regs[1], (cpu->regs[22] + 36));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[22] + 36), cpu->regs[1]);
L_13ffc4:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_13ffd8:
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 344));
    if ((cpu->regs[4])==0) goto L_1400dc;
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 16));
    FLAG_CMP(cpu->regs[5], 0ULL);
    if (FLAG_LE) goto L_140048;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_EQ) goto L_13ff4c;
    FLAG_CMP(cpu->regs[5], 1ULL);
    if (FLAG_EQ) goto L_140048;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_EQ) goto L_13ff4c;
    FLAG_CMP(cpu->regs[5], 2ULL);
    if (FLAG_EQ) goto L_140048;
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[6]);
    if (FLAG_EQ) goto L_13ff4c;
    FLAG_CMP(cpu->regs[5], 3ULL);
    if (FLAG_EQ) goto L_140048;
    cpu->regs[4] = cpu->regs[4] + 24ULL;
    cpu->regs[6] = 3ULL;
L_140030:
    PB_LDR(cpu->regs[7], (cpu->regs[4] + (cpu->regs[6] << 3)));
    cpu->regs[6] = cpu->regs[6] + 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[7]);
    if (FLAG_EQ) goto L_13ff4c;
    FLAG_CMP(cpu->regs[5], cpu->regs[6]);
    if (FLAG_NE) goto L_140030;
L_140048:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x140050ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1985a8ULL);
L_140050:
    cpu->regs[20] = 0ULL;
    goto L_13ffc4;
L_140058:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 36));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[22] + 36), cpu->regs[0]);
    goto L_13ffc4;
L_140068:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x140070ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x22b084ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_140050;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 3320ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x140094ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_140050;
L_14009c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_140050;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1400b4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_13ffc4;
L_1400b8:
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    cpu->regs[30] = PB_BASE + 0x1400c8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x26c444ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_13ff78;
L_1400cc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_14009c;
    cpu->regs[20] = 0ULL;
    goto L_13ffc4;
L_1400dc:
    cpu->regs[4] = cpu->regs[1];
L_1400e0:
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 256));
    if ((cpu->regs[4])==0) goto L_140138;
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_EQ) goto L_13ff4c;
    goto L_1400e0;
L_1400f4:
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 16));
    if ((cpu->regs[0])==0) goto L_13ff50;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x140104ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x22b084ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_140050;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = cpu->regs[1] + 4072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x140128ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_14009c;
    cpu->regs[20] = 0ULL;
    goto L_13ffc4;
L_140138:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3488));
    FLAG_CMP(cpu->regs[0], cpu->regs[4]);
    if (FLAG_EQ) goto L_13ff4c;
    goto L_140048;
    SP = SP - 160ULL;
    cpu->regs[4] = 31823ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 16)) | ((0x4f4fULL & 0xffff) << 16);
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    cpu->regs[3] = 9223372036854775807ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 32)) | ((0x3aULL & 0xffff) << 32);
    cpu->regs[5] = 0ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 144), cpu->regs[21]); PB_STR((SP + 144) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = SP + 48ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 104), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    cpu->regs[1] = cpu->regs[1] + 2664ULL;
    cpu->regs[2] = 44ULL;
    cpu->regs[0] = SP + 53ULL;
    PB_STR((SP + 24), cpu->regs[3]); PB_STR((SP + 24) + 8, cpu->regs[19]);
    PB_STR((SP + 40), cpu->regs[19]);
    PB_STR((SP + 48), cpu->regs[4]); PB_STR((SP + 48) + 8, cpu->regs[5]);
    PB_STR((SP + 64), 0ULL); PB_STR((SP + 64) + 8, 0ULL);
    PB_STR((SP + 80), 0ULL); PB_STR((SP + 80) + 8, 0ULL);
    PB_STRH((SP + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1401c8ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = SP + 40ULL;
    cpu->regs[3] = SP + 32ULL;
    cpu->regs[2] = SP + 16ULL;
    PB_STRB((SP + 97), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1401e4ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1402c4;
    PB_LDR(cpu->regs[1], (SP + 32));
    FLAG_CMP(cpu->regs[1], cpu->regs[19]);
    if (FLAG_EQ) goto L_1402ac;
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 8));
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x14020cULL; PB_CALL(58, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 96));
    PB_LDR(cpu->regs[21], (cpu->regs[2] + cpu->regs[0]));
    if ((cpu->regs[3])==0) goto L_140330;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 264));
    if ((cpu->regs[0])==0) goto L_140330;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x14022cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1402b4;
L_140238:
    PB_LDR(cpu->regs[0], (SP + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_140310;
L_140244:
    PB_LDR(cpu->regs[1], (SP + 16)); PB_LDR(cpu->regs[3], (SP + 16) + 8);
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 168));
    if (((cpu->regs[0] >> 26) & 1)) goto L_1402cc;
    if (!((cpu->regs[0] >> 28) & 1)) goto L_140354;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x140264ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1405a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1402a0;
L_140268:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_140270:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_14032c;
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
L_1402a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    goto L_140270;
L_1402ac:
    cpu->regs[2] = 0ULL;
    goto L_140238;
L_1402b4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 96));
    if ((cpu->regs[0])==0) goto L_140238;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])==0) goto L_140238;
L_1402c4:
    cpu->regs[0] = 0ULL;
    goto L_140270;
L_1402cc:
    PB_LDR(cpu->regs[22], (cpu->regs[1] + 16));
    cpu->regs[19] = cpu->regs[1] + 24ULL;
    cpu->regs[21] = 0ULL;
L_1402d8:
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_GE) goto L_140268;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + (cpu->regs[21] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 168));
    if (!((cpu->regs[4] >> 28) & 1)) goto L_140378;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = 4294967295ULL;
    PB_STR((SP + 0), cpu->regs[2]); PB_STR((SP + 0) + 8, cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x140300ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x1405a0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1402a0;
    PB_LDR(cpu->regs[2], (SP + 0)); PB_LDR(cpu->regs[3], (SP + 0) + 8);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_1402d8;
L_140310:
    cpu->regs[1] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x14031cULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x146a64ULL);
    PB_LDR(cpu->regs[2], (SP + 0));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_140244;
    cpu->regs[0] = 0ULL;
    goto L_140270;
L_14032c:
    cpu->regs[30] = PB_BASE + 0x140330ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x7c170ULL);
L_140330:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = PB_BASE + 0x28c000ULL;
    cpu->regs[2] = cpu->regs[2] + 2680ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x14034cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x1d5980ULL);
    cpu->regs[0] = 0ULL;
    goto L_140270;
L_140354:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 24));
    cpu->regs[1] = cpu->regs[1] + 2808ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x140370ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_140270;
L_140378:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 2752ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x140394ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 0ULL;
    goto L_140270;
    /* nop */
    SP = SP - 176ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3080));
    PB_STR((SP + 112), cpu->regs[29]); PB_STR((SP + 112) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 112ULL;
    PB_STR((SP + 128), cpu->regs[19]); PB_STR((SP + 128) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    PB_STR((SP + 144), cpu->regs[21]); PB_STR((SP + 144) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = SP + 48ULL;
    PB_STR((SP + 160), cpu->regs[23]); PB_STR((SP + 160) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[4];
    cpu->regs[4] = 31823ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 16)) | ((0x4f4fULL & 0xffff) << 16);
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    PB_STR((SP + 104), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[4] = (cpu->regs[4] & ~(0xffffULL << 32)) | ((0x3aULL & 0xffff) << 32);
    cpu->regs[5] = 0ULL;
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[3] = 9223372036854775807ULL;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
    cpu->regs[2] = 44ULL;
    cpu->regs[0] = SP + 53ULL;
    PB_STR((SP + 16), 0ULL); PB_STR((SP + 16) + 8, cpu->regs[3]);
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[19]);
    PB_STR((SP + 48), cpu->regs[4]); PB_STR((SP + 48) + 8, cpu->regs[5]);
    PB_STR((SP + 64), 0ULL); PB_STR((SP + 64) + 8, 0ULL);
    PB_STR((SP + 80), 0ULL); PB_STR((SP + 80) + 8, 0ULL);
    PB_STRH((SP + 96), 0ULL);
    cpu->regs[30] = PB_BASE + 0x140424ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x7b5d0ULL);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[4] = SP + 40ULL;
    cpu->regs[3] = SP + 32ULL;
    cpu->regs[2] = SP + 8ULL;
    PB_STRB((SP + 97), 0ULL);
    cpu->regs[30] = PB_BASE + 0x140440ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1404c4;
    PB_LDR(cpu->regs[0], (SP + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_EQ) goto L_14045c;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x140458ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x146a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1404c4;
L_14045c:
    PB_LDR(cpu->regs[0], (SP + 40));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_1404b8;
L_140468:
    PB_LDR(cpu->regs[0], (SP + 16));
    PB_STR((cpu->regs[23] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    cpu->regs[0] = 1ULL;
L_140484:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 104));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1404cc;
    PB_LDR(cpu->regs[29], (SP + 112)); PB_LDR(cpu->regs[30], (SP + 112) + 8);
    PB_LDR(cpu->regs[19], (SP + 128)); PB_LDR(cpu->regs[20], (SP + 128) + 8);
    PB_LDR(cpu->regs[21], (SP + 144)); PB_LDR(cpu->regs[22], (SP + 144) + 8);
    PB_LDR(cpu->regs[23], (SP + 160)); PB_LDR(cpu->regs[24], (SP + 160) + 8);
    SP = SP + 176ULL;
    return;
L_1404b8:
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[30] = PB_BASE + 0x1404c0ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x146a64ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_140468;
L_1404c4:
    cpu->regs[0] = 0ULL;
    goto L_140484;
L_1404cc:
    cpu->regs[30] = PB_BASE + 0x1404d0ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x7c170ULL);
}
