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

void ft_PyDict_SetItemString(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 48ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[20] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x18eb24ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xdea4cULL);
    PB_STR((SP + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18ebbc;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x18eb40ULL; PB_CALL(2, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[30] = PB_BASE + 0x18eb50ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdb740ULL);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[20], (SP + 0));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18eb64ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[19] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_18eba4;
L_18eb70:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_18eba0;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
L_18eba0:
    cpu->regs[30] = PB_BASE + 0x18eba4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_18eba4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_18eb70;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18ebb8ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18eb70;
L_18ebbc:
    cpu->regs[19] = 4294967295ULL;
    goto L_18eb70;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3000));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_18ebe0;
    cpu->regs[0] = 1ULL;
    goto L_18ebe4;
L_18ebe0:
    { PB_CALL(7, cpu, tlb, PB_BASE + 0xe2424ULL); return; };
L_18ebe4:
    cpu->regs[3] = cpu->tls_ptr;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[4] = cpu->regs[0];
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x18ec04ULL; PB_CALL(8, cpu, tlb, cpu->regs[5]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[3] = cpu->regs[0] + (66ULL << 12);
    cpu->regs[3] = cpu->regs[3] + 3072ULL;
    PB_LDR(cpu->regs[19], cpu->regs[3]); cpu->regs[3] += -8;
    if ((cpu->regs[19])!=0) goto L_18ec3c;
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_18ec80;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3000));
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    { PB_CALL(9, cpu, tlb, PB_BASE + 0xe2424ULL); return; };
L_18ec3c:
    cpu->regs[30] = PB_BASE + 0x18ec40ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdb548ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[3] + 16));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[19] + 24), cpu->regs[4]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
    PB_STRW((cpu->regs[3] + 16), cpu->regs[1]);
    PB_STR((cpu->regs[19] + 16), 0ULL);
    cpu->regs[30] = PB_BASE + 0x18ec68ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x187e20ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18ec70ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xd9444ULL);
L_18ec70:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_18ec80:
    cpu->regs[1] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[19] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[1] = cpu->regs[1] + 2048ULL;
    cpu->regs[19] = cpu->regs[19] + 2232ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 184));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_18ec70;
    PB_STRW((cpu->regs[1] + 184), cpu->regs[0]);
    goto L_18ec70;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x18ecb4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x18ecbcULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xe2500ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3000));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_18ed24;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x18ece8ULL; PB_CALL(15, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] + (66ULL << 12);
    cpu->regs[1] = cpu->regs[1] + 3064ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 16));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(15ULL)));
    if (FLAG_GT) goto L_18ed3c;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_STR((cpu->regs[19] + 16), cpu->regs[2]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STR((cpu->regs[1] + 8), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_STRW((cpu->regs[1] + 16), cpu->regs[0]);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_18ed24:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
L_18ed28:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[16] = cpu->regs[1];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_18ed3c:
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 320));
    goto L_18ed28;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[19] + (66ULL << 12);
    cpu->regs[19] = cpu->regs[19] + 3072ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[8];
    cpu->regs[30] = PB_BASE + 0x18ed68ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xd94a0ULL);
    PB_STR((cpu->regs[19] + -8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18f13c;
    cpu->regs[0] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x18ed78ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2496));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0x18ed98ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f320;
L_18eda4:
    cpu->regs[0] = 114ULL;
    cpu->regs[30] = PB_BASE + 0x18edacULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[30] = PB_BASE + 0x18edc4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f308;
L_18edd0:
    cpu->regs[0] = 115ULL;
    cpu->regs[30] = PB_BASE + 0x18edd8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[30] = PB_BASE + 0x18edf0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f2f0;
L_18edfc:
    cpu->regs[0] = 11ULL;
    cpu->regs[30] = PB_BASE + 0x18ee04ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[30] = PB_BASE + 0x18ee1cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f2d8;
L_18ee28:
    cpu->regs[0] = 32ULL;
    cpu->regs[30] = PB_BASE + 0x18ee30ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2952));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0x18ee50ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f2c0;
L_18ee5c:
    cpu->regs[0] = 108ULL;
    cpu->regs[30] = PB_BASE + 0x18ee64ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[30] = PB_BASE + 0x18ee7cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f2a8;
L_18ee88:
    cpu->regs[0] = 10ULL;
    cpu->regs[30] = PB_BASE + 0x18ee90ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2688));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18eeb0ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f290;
L_18eebc:
    cpu->regs[0] = 103ULL;
    cpu->regs[30] = PB_BASE + 0x18eec4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3608));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18eee4ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f278;
L_18eef0:
    cpu->regs[0] = 111ULL;
    cpu->regs[30] = PB_BASE + 0x18eef8ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2944));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18ef18ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f260;
L_18ef24:
    cpu->regs[0] = 104ULL;
    cpu->regs[30] = PB_BASE + 0x18ef2cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2880));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18ef4cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f248;
L_18ef58:
    cpu->regs[0] = 17ULL;
    cpu->regs[30] = PB_BASE + 0x18ef60ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 4080));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18ef80ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f230;
L_18ef8c:
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x18ef94ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3088));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18efb4ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f218;
L_18efc0:
    cpu->regs[0] = 21ULL;
    cpu->regs[30] = PB_BASE + 0x18efc8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3920));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18efe8ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f200;
L_18eff4:
    cpu->regs[0] = 20ULL;
    cpu->regs[30] = PB_BASE + 0x18effcULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3568));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18f01cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f1e8;
L_18f028:
    cpu->regs[0] = 4ULL;
    cpu->regs[30] = PB_BASE + 0x18f030ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3864));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18f050ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f1d0;
L_18f05c:
    cpu->regs[0] = 13ULL;
    cpu->regs[30] = PB_BASE + 0x18f064ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 4032));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[30] = PB_BASE + 0x18f084ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f1b8;
L_18f090:
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x18f098ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 0));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    cpu->regs[30] = PB_BASE + 0x18f0b0ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f1a0;
L_18f0bc:
    cpu->regs[0] = 3ULL;
    cpu->regs[30] = PB_BASE + 0x18f0c4ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2344));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18f0e4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f188;
L_18f0f0:
    cpu->regs[0] = 110ULL;
    cpu->regs[30] = PB_BASE + 0x18f0f8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18f338;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3072));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x18f118ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xddf30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_18f338;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_18f170;
L_18f124:
    PB_STR((cpu->regs[21] + 0), 0ULL); PB_STR((cpu->regs[21] + 0) + 8, 0ULL);
    PB_STR((cpu->regs[21] + 16), 0ULL); PB_STR((cpu->regs[21] + 16) + 8, 0ULL);
L_18f12c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_18f13c:
    cpu->regs[1] = cpu->regs[21] + 4ULL;
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[2] = PB_BASE + 0x281000ULL;
    cpu->regs[0] = cpu->regs[0] + 3096ULL;
    cpu->regs[2] = cpu->regs[2] + 2192ULL;
    PB_STR((cpu->regs[1] + 0), 0ULL); PB_STR((cpu->regs[1] + 0) + 8, 0ULL);
    cpu->regs[3] = 1ULL;
    PB_STR((cpu->regs[21] + 20), 0ULL);
    PB_STRW((cpu->regs[21] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[21] + 8), cpu->regs[0]); PB_STR((cpu->regs[21] + 8) + 8, cpu->regs[2]);
    PB_STRW((cpu->regs[21] + 28), 0ULL);
    goto L_18f12c;
L_18f170:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18f124;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f184ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18f124;
L_18f188:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18f0f0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f19cULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18f0f0;
L_18f1a0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18f0bc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f1b4ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18f0bc;
L_18f1b8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18f090;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f1ccULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18f090;
L_18f1d0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18f05c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f1e4ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18f05c;
L_18f1e8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18f028;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f1fcULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18f028;
L_18f200:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18eff4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f214ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18eff4;
L_18f218:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18efc0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f22cULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18efc0;
L_18f230:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18ef8c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f244ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18ef8c;
L_18f248:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18ef58;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f25cULL; PB_CALL(64, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18ef58;
L_18f260:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18ef24;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f274ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18ef24;
L_18f278:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18eef0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f28cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18eef0;
L_18f290:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18eebc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f2a4ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18eebc;
L_18f2a8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18ee88;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f2bcULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18ee88;
L_18f2c0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18ee5c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f2d4ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18ee5c;
L_18f2d8:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18ee28;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f2ecULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18ee28;
L_18f2f0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18edfc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f304ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18edfc;
L_18f308:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18edd0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f31cULL; PB_CALL(72, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18edd0;
L_18f320:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18eda4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f334ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18eda4;
L_18f338:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18f340ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[1] = cpu->regs[21] + 4ULL;
    cpu->regs[0] = PB_BASE + 0x2b7000ULL;
    cpu->regs[0] = cpu->regs[0] + 1840ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[0] = cpu->regs[0] + 3096ULL;
    cpu->regs[2] = PB_BASE + 0x283000ULL;
    PB_STR((cpu->regs[1] + 0), 0ULL); PB_STR((cpu->regs[1] + 0) + 8, 0ULL);
    cpu->regs[2] = cpu->regs[2] + 3512ULL;
    PB_STR((cpu->regs[21] + 20), 0ULL);
    PB_STRW((cpu->regs[21] + 0), cpu->regs[3]);
    PB_STR((cpu->regs[21] + 8), cpu->regs[0]); PB_STR((cpu->regs[21] + 8) + 8, cpu->regs[2]);
    PB_STRW((cpu->regs[21] + 28), 0ULL);
    goto L_18f12c;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    if ((cpu->regs[2])!=0) goto L_18f3f0;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_18f424;
L_18f3a8:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2760));
L_18f3b0:
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[0] = 5ULL;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 2248));
    cpu->regs[5] = cpu->regs[5] + 3208ULL;
    cpu->regs[30] = PB_BASE + 0x18f3d0ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xe0f0cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_18f40c;
L_18f3dc:
    cpu->regs[19] = cpu->regs[20];
L_18f3e0:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_18f3f0:
    cpu->regs[0] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[3]); PB_STR((SP + 32) + 8, cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x18f3fcULL; PB_CALL(76, cpu, tlb, PB_BASE + 0xde9e0ULL);
    PB_LDR(cpu->regs[3], (SP + 32)); PB_LDR(cpu->regs[1], (SP + 32) + 8);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_18f3b0;
    goto L_18f3e0;
L_18f40c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_18f3dc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18f420ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18f3dc;
L_18f424:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    goto L_18f3a8;
}
