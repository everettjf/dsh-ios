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

void ft__PyLong_UnsignedInt_Converter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (!((cpu->regs[1] >> 24) & 1)) goto L_9ece0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_NE) goto L_9ece0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[1] = cpu->regs[1] + 1976ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9ecdcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9ecf8;
L_9ece0:
    cpu->regs[30] = PB_BASE + 0x9ece4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x13ae90ULL);
    cpu->regs[2] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9ed00;
    cpu->regs[30] = PB_BASE + 0x9ecf4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_9ed0c;
L_9ecf8:
    cpu->regs[0] = 0ULL;
    goto L_9ed30;
L_9ed00:
    cpu->regs[0] = 4294967295ULL;
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_LS) goto L_9ed28;
L_9ed0c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 1640ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9ed24ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_9ecf8;
L_9ed28:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[2]);
L_9ed30:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9ed64ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9ed78;
    cpu->regs[30] = PB_BASE + 0x9ed74ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_9eef8;
L_9ed78:
    cpu->regs[0] = ((uint32_t)(cpu->regs[3] & 61440ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(32768ULL)));
    if (FLAG_EQ) goto L_9edc0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(16384ULL)));
    if (FLAG_EQ) goto L_9edc8;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(40960ULL)));
    if (FLAG_EQ) goto L_9edd0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(24576ULL)));
    if (FLAG_EQ) goto L_9edd8;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(8192ULL)));
    if (FLAG_EQ) goto L_9ede0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4096ULL)));
    if (FLAG_EQ) goto L_9ede8;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(49152ULL)));
    cpu->regs[1] = 63ULL;
    cpu->regs[0] = 115ULL;
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    goto L_9edec;
L_9edc0:
    cpu->regs[0] = 45ULL;
    goto L_9edec;
L_9edc8:
    cpu->regs[0] = 100ULL;
    goto L_9edec;
L_9edd0:
    cpu->regs[0] = 108ULL;
    goto L_9edec;
L_9edd8:
    cpu->regs[0] = 98ULL;
    goto L_9edec;
L_9ede0:
    cpu->regs[0] = 99ULL;
    goto L_9edec;
L_9ede8:
    cpu->regs[0] = 112ULL;
L_9edec:
    FLAG_CMP((cpu->regs[3]) & (256ULL), 0);
    cpu->regs[1] = 45ULL;
    cpu->regs[8] = 114ULL;
    cpu->regs[8] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[8];
    FLAG_CMP((cpu->regs[3]) & (128ULL), 0);
    cpu->regs[5] = 119ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[3] & 64ULL));
    cpu->regs[5] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[5];
    if (!((cpu->regs[3] >> 11) & 1)) goto L_9ee24;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    cpu->regs[1] = 83ULL;
    cpu->regs[2] = 115ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    goto L_9ee30;
L_9ee24:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    cpu->regs[2] = 120ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
L_9ee30:
    cpu->regs[4] = 0ULL;
    FLAG_CMP((cpu->regs[3]) & (32ULL), 0);
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] & ~0xffULL) | ((cpu->regs[0] >> 0) & 0xffULL))));
    cpu->regs[1] = 45ULL;
    cpu->regs[7] = 114ULL;
    cpu->regs[7] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[7];
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] & ~(0xffULL << 8)) | ((cpu->regs[8] & 0xffULL) << 8))));
    FLAG_CMP((cpu->regs[3]) & (16ULL), 0);
    cpu->regs[6] = 119ULL;
    cpu->regs[9] = ((uint32_t)(cpu->regs[3] & 8ULL));
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] & ~(0xffULL << 16)) | ((cpu->regs[5] & 0xffULL) << 16))));
    cpu->regs[6] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[6];
    cpu->regs[4] = ((uint32_t)(((cpu->regs[4] & ~(0xffULL << 24)) | ((cpu->regs[2] & 0xffULL) << 24))));
    PB_STRW((SP + 8), cpu->regs[4]);
    if (!((cpu->regs[3] >> 10) & 1)) goto L_9ee80;
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(0ULL)));
    cpu->regs[1] = 83ULL;
    cpu->regs[0] = 115ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    goto L_9ee8c;
L_9ee80:
    FLAG_CMP(((uint32_t)(cpu->regs[9])), ((uint32_t)(0ULL)));
    cpu->regs[0] = 120ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
L_9ee8c:
    FLAG_CMP((cpu->regs[3]) & (4ULL), 0);
    cpu->regs[0] = 45ULL;
    cpu->regs[5] = 114ULL;
    cpu->regs[5] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[5];
    FLAG_CMP((cpu->regs[3]) & (2ULL), 0);
    PB_STRB((SP + 12), cpu->regs[7]);
    PB_STRB((SP + 13), cpu->regs[6]);
    cpu->regs[4] = 119ULL;
    PB_STRB((SP + 14), cpu->regs[1]);
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[4];
    cpu->regs[1] = ((uint32_t)(cpu->regs[3] & 1ULL));
    if (!((cpu->regs[3] >> 9) & 1)) goto L_9eed0;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[0] = 84ULL;
    cpu->regs[1] = 116ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
    goto L_9eedc;
L_9eed0:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(0ULL)));
    cpu->regs[1] = 120ULL;
    cpu->regs[2] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[1];
L_9eedc:
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[1] = 10ULL;
    PB_STRB((SP + 15), cpu->regs[5]);
    PB_STRB((SP + 16), cpu->regs[4]);
    PB_STRB((SP + 17), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x9eef4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1ec0ULL);
    goto L_9eefc;
L_9eef8:
    cpu->regs[0] = 0ULL;
L_9eefc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_9ef1c;
    cpu->regs[30] = PB_BASE + 0x9ef1cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9ef1c:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x9ef38ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9ef4c;
    cpu->regs[30] = PB_BASE + 0x9ef48ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_9ef58;
L_9ef4c:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = cpu->regs[3] & 61440ULL;
    { PB_CALL(11, cpu, tlb, PB_BASE + 0xe1564ULL); return; };
L_9ef58:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x9ef74ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9ef88;
    cpu->regs[30] = PB_BASE + 0x9ef84ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_9ef94;
L_9ef88:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = cpu->regs[3] & 4095ULL;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0xe1564ULL); return; };
L_9ef94:
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_9efa0:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x9efb0ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9efd0;
    cpu->regs[30] = PB_BASE + 0x9efbcULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_9efd8;
L_9efd0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
L_9efd8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    goto L_9efa0;
    goto L_9efa0;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x9eff8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9f018;
    cpu->regs[30] = PB_BASE + 0x9f004ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_9f038;
L_9f018:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 61440ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(49152ULL)));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
L_9f038:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x9f050ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9f070;
    cpu->regs[30] = PB_BASE + 0x9f05cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_9f090;
L_9f070:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 61440ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4096ULL)));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
L_9f090:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x9f0a8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9f0c8;
    cpu->regs[30] = PB_BASE + 0x9f0b4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_9f0e8;
L_9f0c8:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 61440ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(24576ULL)));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
L_9f0e8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x9f100ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1dcbc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9f120;
    cpu->regs[30] = PB_BASE + 0x9f10cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe1f30ULL);
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[1] : 0ULL;
    goto L_9f140;
L_9f120:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3184));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] & 61440ULL));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(8192ULL)));
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[0] : cpu->regs[2];
L_9f140:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
