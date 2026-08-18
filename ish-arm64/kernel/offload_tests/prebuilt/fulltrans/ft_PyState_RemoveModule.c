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

void ft_PyState_RemoveModule(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[1] = cpu->regs[0];
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa0ce4ULL; PB_CALL(1, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 72));
    if ((cpu->regs[2])!=0) goto L_a0d00;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xa0c4cULL); return; };
L_a0d00:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2936));
    cpu->regs[2] = PB_BASE + 0x2a3000ULL;
    cpu->regs[2] = cpu->regs[2] + 1912ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xa0d18ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1d5980ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = 0ULL;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1] + 16ULL;
L_a0d48:
    if ((cpu->regs[20])==0) goto L_a0d54;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    goto L_a0d58;
L_a0d54:
    cpu->regs[0] = 0ULL;
L_a0d58:
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_GE) goto L_a0e74;
    PB_LDR(cpu->regs[19], (cpu->regs[23] + (cpu->regs[21] << 3)));
    if ((cpu->regs[19])!=0) goto L_a0d70;
L_a0d68:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_a0d48;
L_a0d70:
    PB_LDRW(cpu->regs[6], (cpu->regs[19] + 24));
    PB_LDRW(cpu->regs[5], (cpu->regs[19] + 32));
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_LE) goto L_a0da4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 384ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa0da0ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a0e7c;
L_a0da4:
    if (!((cpu->regs[6] >> 31) & 1)) goto L_a0db0;
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_NE) goto L_a0dc4;
L_a0db0:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 28));
    if (!((cpu->regs[3] >> 31) & 1)) goto L_a0dec;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 36));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_a0dec;
L_a0dc4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[4] = cpu->regs[6];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 28));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 36));
    cpu->regs[1] = cpu->regs[1] + 432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa0de8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a0e7c;
L_a0dec:
    FLAG_CMP(((uint32_t)(cpu->regs[6])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_NE) goto L_a0e20;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 36));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_LE) goto L_a0e20;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[6];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 504ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa0e1cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a0e7c;
L_a0e20:
    PB_LDRW(cpu->regs[24], (cpu->regs[19] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_a0e64;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_a0e64;
    FLAG_CMP(((uint32_t)(cpu->regs[24])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_a0d68;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0xa0e44ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x26a740ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a0e7c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    if ((cpu->regs[1])==0) goto L_a0d68;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xa0e5cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a0d68;
    goto L_a0e7c;
L_a0e64:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0xa0e6cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x26a740ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a0d68;
    goto L_a0e7c;
L_a0e74:
    cpu->regs[0] = 1ULL;
    goto L_a0e80;
L_a0e7c:
    cpu->regs[0] = 0ULL;
L_a0e80:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_a0e94:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xa0eb0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a0ebc;
L_a0eb4:
    cpu->regs[0] = 0ULL;
    goto L_a1080;
L_a0ebc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(19ULL)));
    if (FLAG_EQ) goto L_a107c;
    if (FLAG_HI) goto L_a0ee0;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_a0fd4;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_a0f7c;
    goto L_a1060;
L_a0ee0:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(20ULL)));
    if (FLAG_EQ) goto L_a0ef4;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(21ULL)));
    if (FLAG_EQ) goto L_a107c;
    goto L_a1060;
L_a0ef4:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa0f04ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a0eb4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a107c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2216));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a107c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2392));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a107c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2320));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a107c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2520));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a107c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 1968ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa0f78ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a0eb4;
L_a0f7c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_a1060;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_a1060;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2216));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a107c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a107c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2320));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a107c;
    goto L_a1060;
L_a0fd4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_a1060;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_a1008;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 8));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(4ULL)));
    if (FLAG_NE) goto L_a1060;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
L_a1008:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_a1060;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2216));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a1038;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2280));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_a1060;
L_a1038:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_a1060;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2320));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a107c;
L_a1060:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x297000ULL;
    cpu->regs[1] = cpu->regs[1] + 1072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa1078ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a0eb4;
L_a107c:
    cpu->regs[0] = 1ULL;
L_a1080:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_a108c:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 40));
    PB_LDRW(cpu->regs[5], (cpu->regs[1] + 48));
    PB_STR((SP + 64), cpu->regs[25]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_LE) goto L_a10dc;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2976));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 384ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    cpu->regs[30] = PB_BASE + 0xa10d8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a1124;
L_a10dc:
    cpu->regs[19] = cpu->regs[1];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_a10ec;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_NE) goto L_a1100;
L_a10ec:
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 44));
    if (!((cpu->regs[3] >> 31) & 1)) goto L_a112c;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 52));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_EQ) goto L_a112c;
L_a1100:
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2976));
    cpu->regs[4] = cpu->regs[0];
    PB_LDRW(cpu->regs[2], (cpu->regs[19] + 44));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 52));
    cpu->regs[1] = cpu->regs[1] + 432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 0));
    cpu->regs[30] = PB_BASE + 0xa1124ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x11f220ULL);
L_a1124:
    cpu->regs[0] = 0ULL;
    goto L_a1528;
L_a112c:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_NE) goto L_a1160;
    PB_LDRW(cpu->regs[4], (cpu->regs[19] + 52));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_LE) goto L_a1160;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2976));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 504ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[5] + 0));
    cpu->regs[30] = PB_BASE + 0xa115cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a1124;
L_a1160:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0)); PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0) + 4);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_LE) goto L_a1190;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3704));
    cpu->regs[1] = PB_BASE + 0x289000ULL;
    cpu->regs[1] = cpu->regs[1] + 3496ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa118cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a1124;
L_a1190:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(5ULL)));
    if (FLAG_EQ) goto L_a1324;
    if (FLAG_HI) goto L_a11c4;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_a1238;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_a124c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_a11e0;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(2ULL)));
    if (FLAG_EQ) goto L_a11f0;
    goto L_a14c0;
L_a11c4:
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(7ULL)));
    if (FLAG_EQ) goto L_a142c;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(8ULL)));
    if (FLAG_EQ) goto L_a1480;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(6ULL)));
    if (FLAG_EQ) goto L_a13fc;
    goto L_a14c0;
L_a11e0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa11ecULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xa0e94ULL);
    goto L_a14e0;
L_a11f0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_a14dc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2296));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a14dc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2016ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa1230ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_a14e0;
L_a1238:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa1248ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xa1540ULL);
    goto L_a14bc;
L_a124c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_a125c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    goto L_a1260;
L_a125c:
    cpu->regs[1] = 0ULL;
L_a1260:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_a1270;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_a1274;
L_a1270:
    cpu->regs[0] = 0ULL;
L_a1274:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a1298;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2072ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa1294ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a13bc;
L_a1298:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])!=0) goto L_a12c0;
L_a12a0:
    PB_LDR(cpu->regs[22], (cpu->regs[19] + 8));
    cpu->regs[21] = 0ULL;
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
    cpu->regs[24] = cpu->regs[22] + 16ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2296));
    goto L_a1300;
L_a12c0:
    cpu->regs[30] = PB_BASE + 0xa12c4ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x974d8ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a12a0;
    goto L_a13bc;
L_a12cc:
    cpu->regs[1] = 0ULL;
L_a12d0:
    cpu->regs[0] = cpu->regs[20];
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_GE) goto L_a14f0;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + (cpu->regs[21] << 3)));
    cpu->regs[1] = cpu->regs[2];
    PB_LDRW(cpu->regs[3], (cpu->regs[2] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(20ULL)));
    if (FLAG_NE) goto L_a1318;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[25]);
    if (FLAG_NE) goto L_a130c;
L_a12fc:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
L_a1300:
    if ((cpu->regs[22])==0) goto L_a12cc;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    goto L_a12d0;
L_a130c:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 8));
    FLAG_CMP(cpu->regs[2], cpu->regs[23]);
    if (FLAG_EQ) goto L_a12fc;
L_a1318:
    cpu->regs[30] = PB_BASE + 0xa131cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xa0e94ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a12fc;
    goto L_a13bc;
L_a1324:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_a1334;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    goto L_a1338;
L_a1334:
    cpu->regs[1] = 0ULL;
L_a1338:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_a1348;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_a134c;
L_a1348:
    cpu->regs[0] = 0ULL;
L_a134c:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_a1370;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2136ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa136cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a13bc;
L_a1370:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa1380ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a13bc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
L_a1388:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(24ULL)));
    if (FLAG_EQ) goto L_a13c4;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(21ULL)));
    if (FLAG_NE) goto L_a13a4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    goto L_a1388;
L_a13a4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2216ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa13bcULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_a13bc:
    cpu->regs[0] = 0ULL;
    goto L_a14e0;
L_a13c4:
    cpu->regs[21] = 0ULL;
L_a13c8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_a13d8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    goto L_a13dc;
L_a13d8:
    cpu->regs[1] = 0ULL;
L_a13dc:
    cpu->regs[2] = cpu->regs[21] + 2ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_GE) goto L_a1500;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[2] << 3)));
    cpu->regs[30] = PB_BASE + 0xa13f0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x26a740ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a13bc;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    goto L_a13c8;
L_a13fc:
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_a141c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2280ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa1418ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a13bc;
L_a141c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    if ((cpu->regs[0])==0) goto L_a14dc;
    cpu->regs[30] = PB_BASE + 0xa1428ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x974d8ULL);
    goto L_a14e0;
L_a142c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])!=0) goto L_a1440;
L_a1434:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    if ((cpu->regs[1])!=0) goto L_a144c;
    goto L_a14dc;
L_a1440:
    cpu->regs[30] = PB_BASE + 0xa1444ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x974d8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a13bc;
    goto L_a1434;
L_a144c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])!=0) goto L_a1470;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2312ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa146cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a13bc;
L_a1470:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa147cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xa108cULL);
    goto L_a14e0;
L_a1480:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    if ((cpu->regs[1])==0) goto L_a1494;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_GT) goto L_a14b0;
L_a1494:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2376ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa14acULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a13bc;
L_a14b0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa14bcULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xa1540ULL);
L_a14bc:
    if (!((cpu->regs[0] >> 31) & 1)) goto L_a14e0;
L_a14c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2416ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa14d8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a13bc;
L_a14dc:
    cpu->regs[0] = 1ULL;
L_a14e0:
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[20] + 0), cpu->regs[1]);
    goto L_a1528;
L_a14f0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa14fcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xa1540ULL);
    goto L_a14bc;
L_a1500:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa1510ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xa1540ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a13bc;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xa1524ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xa1540ULL);
    goto L_a14bc;
L_a1528:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_a1540:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[1] + 16ULL;
L_a1568:
    if ((cpu->regs[19])==0) goto L_a1574;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    goto L_a1578;
L_a1574:
    cpu->regs[1] = 0ULL;
L_a1578:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    FLAG_CMP(cpu->regs[20], cpu->regs[1]);
    if (FLAG_GE) goto L_a159c;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + (cpu->regs[20] << 3)));
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0xa1594ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xa108cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a1568;
    goto L_a15a0;
L_a159c:
    cpu->regs[0] = 1ULL;
L_a15a0:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_a15b4:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1] + 16ULL;
L_a15d4:
    if ((cpu->regs[19])==0) goto L_a15e0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    goto L_a15e4;
L_a15e0:
    cpu->regs[0] = 0ULL;
L_a15e4:
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_GE) goto L_a16c8;
    PB_LDR(cpu->regs[6], (cpu->regs[22] + (cpu->regs[20] << 3)));
    PB_LDRW(cpu->regs[7], (cpu->regs[6] + 24));
    PB_LDRW(cpu->regs[5], (cpu->regs[6] + 32));
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_LE) goto L_a1624;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[3] = cpu->regs[5];
    cpu->regs[2] = cpu->regs[7];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 384ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa1620ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a1668;
L_a1624:
    if (!((cpu->regs[7] >> 31) & 1)) goto L_a1630;
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_NE) goto L_a1644;
L_a1630:
    PB_LDRW(cpu->regs[3], (cpu->regs[6] + 28));
    if (!((cpu->regs[3] >> 31) & 1)) goto L_a1670;
    PB_LDRW(cpu->regs[0], (cpu->regs[6] + 36));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_EQ) goto L_a1670;
L_a1644:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[6] + 28));
    cpu->regs[4] = cpu->regs[7];
    PB_LDRW(cpu->regs[3], (cpu->regs[6] + 36));
    cpu->regs[1] = cpu->regs[1] + 432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa1668ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11f220ULL);
L_a1668:
    cpu->regs[0] = 0ULL;
    goto L_a16cc;
L_a1670:
    FLAG_CMP(((uint32_t)(cpu->regs[7])), ((uint32_t)(cpu->regs[5])));
    if (FLAG_NE) goto L_a16a4;
    PB_LDRW(cpu->regs[4], (cpu->regs[6] + 36));
    FLAG_CMP(((uint32_t)(cpu->regs[3])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_LE) goto L_a16a4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[7];
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[1] = cpu->regs[1] + 504ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa16a0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_a1668;
L_a16a4:
    PB_LDR(cpu->regs[1], (cpu->regs[6] + 8));
    if ((cpu->regs[1])!=0) goto L_a16b4;
L_a16ac:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_a15d4;
L_a16b4:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa16c0ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a16ac;
    goto L_a1668;
L_a16c8:
    cpu->regs[0] = 1ULL;
L_a16cc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xa16f8ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xa15b4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a1848;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa1708ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xa15b4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a1848;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])!=0) goto L_a1728;
L_a1714:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa1720ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xa15b4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a1744;
    goto L_a1848;
L_a1728:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    if ((cpu->regs[1])==0) goto L_a1714;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa173cULL; PB_CALL(47, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a1714;
    goto L_a1848;
L_a1744:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_a175c;
L_a174c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    if ((cpu->regs[1])!=0) goto L_a1778;
    cpu->regs[2] = 0ULL;
    goto L_a177c;
L_a175c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    if ((cpu->regs[1])==0) goto L_a174c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa1770ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a174c;
    goto L_a1848;
L_a1778:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
L_a177c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])==0) goto L_a178c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_a1790;
L_a178c:
    cpu->regs[0] = 0ULL;
L_a1790:
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 8));
    if ((cpu->regs[3])==0) goto L_a17a0;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    goto L_a17a4;
L_a17a0:
    cpu->regs[3] = 0ULL;
L_a17a4:
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_GE) goto L_a17cc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2440ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa17c8ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a1848;
L_a17cc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_a17dc;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    goto L_a17e0;
L_a17dc:
    cpu->regs[2] = 0ULL;
L_a17e0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_a17f0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    goto L_a17f4;
L_a17f0:
    cpu->regs[0] = 0ULL;
L_a17f4:
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_EQ) goto L_a1818;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2488ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa1814ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a1848;
L_a1818:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa1828ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x26a050ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a1848;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[3] = 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[2] = cpu->regs[3];
    { PB_CALL(52, cpu, tlb, PB_BASE + 0x26a050ULL); return; };
L_a1848:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = PB_BASE + 0x28f000ULL;
    cpu->regs[1] = cpu->regs[1] + 1104ULL;
    cpu->regs[30] = PB_BASE + 0xa187cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x26a008ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a1894;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(54, cpu, tlb, PB_BASE + 0x2694a0ULL); return; };
L_a1894:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    if ((cpu->regs[1])==0) goto L_a18c8;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if ((cpu->regs[0])!=0) goto L_a1940;
L_a18c8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 2560ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa18e0ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_a1938;
L_a18e4:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa18f4ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a1938;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xa190cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x26a050ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_a1938;
    cpu->regs[21] = cpu->regs[21] + 1ULL;
L_a1914:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = 2ULL;
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_GE) goto L_a194c;
    PB_LDR(cpu->regs[22], (cpu->regs[23] + (cpu->regs[21] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0xa1934ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x26a0f0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a18e4;
L_a1938:
    cpu->regs[0] = 0ULL;
    goto L_a1950;
L_a1940:
    cpu->regs[23] = cpu->regs[1] + 16ULL;
    cpu->regs[21] = 0ULL;
    goto L_a1914;
L_a194c:
    cpu->regs[0] = 1ULL;
L_a1950:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    if ((cpu->regs[0])==0) goto L_a1984;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a19c8;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    return;
L_a1984:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 32));
    if ((cpu->regs[0])==0) goto L_a19c0;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xa1998ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1f058cULL);
    if ((cpu->regs[0])!=0) goto L_a19a8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    goto L_a19b8;
L_a19a8:
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a19b8;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
L_a19b8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_a19c0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_a19c8:
    return;
}
