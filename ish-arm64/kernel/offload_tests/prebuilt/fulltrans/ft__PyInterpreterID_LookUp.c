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

void ft__PyInterpreterID_LookUp(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 32ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = SP;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xab5e8ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xab4f8ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ab618;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_ab62c;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[0], (SP + 0));
    SP = SP + 32ULL;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x97004ULL); return; };
L_ab618:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[2]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ab630;
L_ab62c:
    cpu->regs[30] = PB_BASE + 0xab630ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ab630:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    SP = SP + 32ULL;
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 2ULL));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_HI) goto L_ab794;
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2920));
    cpu->regs[30] = PB_BASE + 0xab68cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ab794;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xab698ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe270cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ab6b4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[19] = (FLAG_EQ) ? 1 : 0;
    goto L_ab75c;
L_ab6b4:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2280));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[0] = cpu->regs[20];
    if (FLAG_NE) goto L_ab714;
    cpu->regs[1] = SP + 4ULL;
    cpu->regs[30] = PB_BASE + 0xab6d4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x273c60ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_ab6f0;
    cpu->regs[30] = PB_BASE + 0xab6e4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_ab6f0;
L_ab6e8:
    cpu->regs[19] = 0ULL;
    goto L_ab7a8;
L_ab6f0:
    PB_LDRW(cpu->regs[0], (SP + 4));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_ab75c;
    if (((cpu->regs[3] >> 63) & 1)) goto L_ab70c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    cpu->regs[19] = (FLAG_EQ) ? 1 : 0;
    goto L_ab75c;
L_ab70c:
    cpu->regs[19] = 0ULL;
    goto L_ab75c;
L_ab714:
    cpu->regs[30] = PB_BASE + 0xab718ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1cb0b0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_ab794;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 16));
    cpu->regs[30] = PB_BASE + 0xab724ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7b0f0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_ab6e8;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xab738ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11ed08ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_ab7a8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_ab7a8;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xab758ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_ab7a8;
L_ab75c:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(2ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    FLAG_CMP((((uint32_t)(cpu->regs[19]))) & (((uint32_t)(cpu->regs[0]))), 0);
    if (FLAG_NE) goto L_ab7a0;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(3ULL)));
    cpu->regs[0] = ((uint32_t)(cpu->regs[19] ^ 1ULL));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3184));
    cpu->regs[2] = (FLAG_EQ) ? 1 : 0;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3664));
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(cpu->regs[2]))), 0);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[1];
    goto L_ab7a8;
L_ab794:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2400));
    goto L_ab7a8;
L_ab7a0:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3664));
L_ab7a8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_ab7c8;
    cpu->regs[30] = PB_BASE + 0xab7c8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ab7c8:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP = SP - 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    if ((cpu->regs[1])!=0) goto L_ab81c;
    PB_STR((cpu->regs[19] + 0), 0ULL); PB_STR((cpu->regs[19] + 0) + 8, 0ULL);
L_ab814:
    cpu->regs[0] = 0ULL;
    goto L_ab844;
L_ab81c:
    cpu->regs[0] = SP;
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xab828ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x226230ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_ab840;
    PB_LDR(cpu->regs[0], (SP + 0));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0xab83cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x27e5c4ULL);
    goto L_ab814;
L_ab840:
    cpu->regs[0] = 4294967295ULL;
L_ab844:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_ab864;
    cpu->regs[30] = PB_BASE + 0xab864ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_ab864:
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 48ULL;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[6];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[22] = cpu->regs[4];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[3];
    cpu->regs[23] = cpu->regs[5];
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[25] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xab8acULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x16a2f0ULL);
    fr[31] = -1.0;
    FCMP(fr[0], fr[31]);
    if (FLAG_NE) goto L_ab8e4;
    cpu->regs[30] = PB_BASE + 0xab8bcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_ab8e4;
    PB_LDR(cpu->regs[2], (cpu->regs[25] + 8));
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = cpu->regs[1] + 1224ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xab8e0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_ab90c;
L_ab8e4:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    cpu->regs[19] = ((cpu->regs[19] >> 3) & 0x1ULL);
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[1] = 6ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[19] << 2));
    cpu->regs[1] = (FLAG_GE) ? cpu->regs[21] : cpu->regs[1];
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xab904ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x225020ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_ab914;
L_ab90c:
    cpu->regs[20] = 0ULL;
    goto L_ab9a4;
L_ab914:
    cpu->regs[30] = PB_BASE + 0xab918ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[23])==0) goto L_ab984;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xab930ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x11db70ULL);
    if ((cpu->regs[0])!=0) goto L_ab940;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xab93cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_ab90c;
L_ab940:
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    cpu->regs[20] = cpu->regs[0] + cpu->regs[21];
    if (FLAG_LS) goto L_ab958;
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_HS) goto L_ab96c;
    goto L_ab968;
L_ab958:
    if (FLAG_HS) goto L_ab96c;
    cpu->regs[1] = cpu->regs[19] + cpu->regs[21];
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_ab96c;
L_ab968:
    __builtin_trap();
L_ab96c:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xab978ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xab980ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_ab9a4;
L_ab984:
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xab990ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xab99cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((cpu->regs[22] + 0), cpu->regs[21]);
    if ((cpu->regs[21])==0) goto L_ab90c;
L_ab9a4:
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
}
