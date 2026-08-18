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

void ft_PyNumber_Divmod(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = PB_BASE + 0x298000ULL;
    cpu->regs[2] = 32ULL;
    cpu->regs[3] = cpu->regs[3] + 1432ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x12cb24ULL); return; };
    /* nop */
    /* nop */
    SP = SP - 80ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[5], (cpu->regs[3] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 168));
    if (!((cpu->regs[3] >> 24) & 1)) goto L_170c4c;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 168));
    if (!((cpu->regs[2] >> 24) & 1)) goto L_170c4c;
    cpu->regs[3] = SP + 24ULL;
    cpu->regs[2] = SP + 32ULL;
    cpu->regs[30] = PB_BASE + 0x170b64ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x150ac0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_170c88;
    cpu->regs[1] = cpu->tls_ptr;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x170b84ULL; PB_CALL(3, cpu, tlb, cpu->regs[2]);
    cpu->regs[20] = cpu->regs[1] + cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[19], (SP + 32));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[4] + (64ULL << 12);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 7696));
    if ((cpu->regs[0])==0) goto L_170c24;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 7852));
    PB_LDR(cpu->regs[5], (cpu->regs[0] + 24));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] - 1ULL));
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 2708));
    PB_STR((cpu->regs[1] + 7696), cpu->regs[5]);
    PB_STRW((cpu->regs[1] + 7852), cpu->regs[2]);
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_170c90;
    cpu->regs[1] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
L_170bcc:
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 208));
    cpu->regs[2] = cpu->regs[0] - 16ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + -8));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    PB_LDR(cpu->regs[5], (SP + 24));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[4];
    PB_STR((cpu->regs[4] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[0] + -16), cpu->regs[3]); PB_STR((cpu->regs[0] + -16) + 8, cpu->regs[1]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[2]);
    PB_STR((cpu->regs[0] + 24), cpu->regs[19]); PB_STR((cpu->regs[0] + 24) + 8, cpu->regs[5]);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
L_170bfc:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_170c44;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_170c24:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2640));
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x170c34ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdc988ULL);
    if ((cpu->regs[0])==0) goto L_170c58;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    goto L_170bcc;
L_170c44:
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x170c4cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x7c170ULL);
L_170c4c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2400));
    goto L_170bfc;
L_170c58:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_170c6c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_170cb0;
L_170c6c:
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_170c84;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_170cbc;
L_170c84:
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
L_170c88:
    cpu->regs[0] = 0ULL;
    goto L_170bfc;
L_170c90:
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x170c98ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 16));
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_170bcc;
L_170cb0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x170cb8ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_170c6c;
L_170cbc:
    cpu->regs[30] = PB_BASE + 0x170cc0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    goto L_170bfc;
    SP += -144; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    PB_LDR(cpu->regs[24], (cpu->regs[0] + 16));
    PB_STR((SP + 120), cpu->regs[2]);
    PB_LDR(cpu->regs[5], (cpu->regs[1] + 16));
    cpu->regs[24] = cpu->regs[24] >> 3;
    cpu->regs[21] = cpu->regs[24] + 1ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[19] = cpu->regs[5] >> 3;
    cpu->regs[30] = PB_BASE + 0x170d08ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xe1608ULL);
    if ((cpu->regs[0])==0) goto L_171778;
    PB_STR((SP + 80), cpu->regs[27]); PB_STR((SP + 80) + 8, cpu->regs[28]);
    cpu->regs[28] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x170d1cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_171788;
    cpu->regs[0] = cpu->regs[20] + (cpu->regs[19] << 2);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[8] = cpu->regs[19] - 1ULL;
    cpu->regs[25] = cpu->regs[24];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 20));
    if ((cpu->regs[0])==0) goto L_1717ac;
    cpu->regs[0] = (((uint64_t)(cpu->regs[0])) == 0) ? 64 : (uint64_t)__builtin_clzll(((uint64_t)(cpu->regs[0])));
    cpu->regs[1] = 64ULL;
    cpu->regs[0] = ((uint32_t)(cpu->regs[1] - cpu->regs[0]));
L_170d48:
    cpu->regs[27] = 30ULL;
    cpu->regs[26] = cpu->regs[22] + 24ULL;
    cpu->regs[27] = ((uint32_t)(cpu->regs[27] - cpu->regs[0]));
    if ((cpu->regs[19])==0) goto L_170e68;
    cpu->regs[1] = cpu->regs[19] + 6ULL;
    cpu->regs[4] = 24ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[1] << 2;
    cpu->regs[0] = cpu->regs[1] - 28ULL;
    cpu->regs[0] = cpu->regs[0] >> 2;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[0] & 3ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_170dec;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_170dc4;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_170da4;
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + 24));
    cpu->regs[4] = 28ULL;
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[27] & 63);
    cpu->regs[7] = ((uint32_t)(cpu->regs[3] & 1073741823ULL));
    cpu->regs[2] = ((cpu->regs[3] >> 30) & 0xffffffffULL);
    PB_STRW((cpu->regs[22] + 24), cpu->regs[7]);
L_170da4:
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[2] = cpu->regs[2];
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[27] & 63);
    cpu->regs[2] = cpu->regs[3] | cpu->regs[2];
    cpu->regs[7] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[22] + cpu->regs[4]), cpu->regs[7]);
    cpu->regs[2] = ((cpu->regs[2] >> 30) & 0xffffffffULL);
    cpu->regs[4] = cpu->regs[4] + 4ULL;
L_170dc4:
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[2] = cpu->regs[2];
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[27] & 63);
    cpu->regs[2] = cpu->regs[3] | cpu->regs[2];
    cpu->regs[7] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[22] + cpu->regs[4]), cpu->regs[7]);
    cpu->regs[4] = cpu->regs[4] + 4ULL;
    cpu->regs[2] = ((cpu->regs[2] >> 30) & 0xffffffffULL);
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_EQ) goto L_170e68;
L_170dec:
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[2] = cpu->regs[2];
    cpu->regs[0] = cpu->regs[4] + 4ULL;
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[27] & 63);
    cpu->regs[2] = cpu->regs[3] | cpu->regs[2];
    cpu->regs[7] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[22] + cpu->regs[4]), cpu->regs[7]);
    cpu->regs[2] = ((cpu->regs[2] >> 30) & 0xffffffffULL);
    cpu->regs[4] = cpu->regs[4] + 8ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + cpu->regs[0]));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[27] & 63);
    cpu->regs[2] = cpu->regs[3] | cpu->regs[2];
    cpu->regs[7] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[22] + cpu->regs[0]), cpu->regs[7]);
    cpu->regs[2] = ((cpu->regs[2] >> 30) & 0xffffffffULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[27] & 63);
    cpu->regs[2] = cpu->regs[3] | cpu->regs[2];
    cpu->regs[7] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[22] + cpu->regs[4]), cpu->regs[7]);
    cpu->regs[4] = cpu->regs[0] + 8ULL;
    cpu->regs[2] = ((cpu->regs[2] >> 30) & 0xffffffffULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[20] + cpu->regs[4]));
    cpu->regs[3] = cpu->regs[3] << (cpu->regs[27] & 63);
    cpu->regs[2] = cpu->regs[3] | cpu->regs[2];
    cpu->regs[7] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[22] + cpu->regs[4]), cpu->regs[7]);
    cpu->regs[4] = cpu->regs[0] + 12ULL;
    cpu->regs[2] = ((cpu->regs[2] >> 30) & 0xffffffffULL);
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_NE) goto L_170dec;
L_170e68:
    cpu->regs[20] = cpu->regs[28] + 24ULL;
    if ((cpu->regs[24])==0) goto L_170f8c;
    cpu->regs[9] = cpu->regs[24] + 6ULL;
    cpu->regs[3] = 24ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[9] = cpu->regs[9] << 2;
    cpu->regs[0] = cpu->regs[9] - 28ULL;
    cpu->regs[0] = cpu->regs[0] >> 2;
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[0] = cpu->regs[0] & 3ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_170f08;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_170edc;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_170ebc;
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + 24));
    cpu->regs[3] = 28ULL;
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[27] & 63);
    cpu->regs[4] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    cpu->regs[1] = ((cpu->regs[2] >> 30) & 0xffffffffULL);
    PB_STRW((cpu->regs[28] + 24), cpu->regs[4]);
L_170ebc:
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + cpu->regs[3]));
    cpu->regs[1] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[27] & 63);
    cpu->regs[1] = cpu->regs[2] | cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[28] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
    cpu->regs[3] = cpu->regs[3] + 4ULL;
L_170edc:
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + cpu->regs[3]));
    cpu->regs[1] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[27] & 63);
    cpu->regs[1] = cpu->regs[2] | cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[28] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[1] >> 30;
    cpu->regs[3] = cpu->regs[3] + 4ULL;
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[9], cpu->regs[3]);
    if (FLAG_EQ) goto L_170f88;
L_170f08:
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + cpu->regs[3]));
    cpu->regs[1] = cpu->regs[1];
    cpu->regs[7] = cpu->regs[3] + 4ULL;
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[27] & 63);
    cpu->regs[1] = cpu->regs[2] | cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[28] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + cpu->regs[7]));
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[27] & 63);
    cpu->regs[1] = cpu->regs[2] | cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[28] + cpu->regs[7]), cpu->regs[4]);
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + cpu->regs[3]));
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[27] & 63);
    cpu->regs[1] = cpu->regs[2] | cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[28] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[3] = cpu->regs[7] + 8ULL;
    cpu->regs[1] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
    PB_LDRW(cpu->regs[2], (cpu->regs[23] + cpu->regs[3]));
    cpu->regs[2] = cpu->regs[2] << (cpu->regs[27] & 63);
    cpu->regs[1] = cpu->regs[2] | cpu->regs[1];
    cpu->regs[4] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[28] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[1] >> 30;
    cpu->regs[3] = cpu->regs[7] + 12ULL;
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[9], cpu->regs[3]);
    if (FLAG_NE) goto L_170f08;
L_170f88:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_17142c;
L_170f8c:
    cpu->regs[0] = cpu->regs[28] + (cpu->regs[24] << 2);
    cpu->regs[8] = cpu->regs[22] + (cpu->regs[8] << 2);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20));
    PB_LDRW(cpu->regs[0], (cpu->regs[8] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_HS) goto L_171428;
L_170fa4:
    cpu->regs[21] = cpu->regs[25] - cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x170fb0ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xe1608ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_171748;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[23] = cpu->regs[19] << 2;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[7] = cpu->regs[20] + (cpu->regs[21] << 2);
    PB_STR((SP + 136), cpu->regs[2]);
    cpu->regs[1] = cpu->regs[23] - 4ULL;
    cpu->regs[0] = cpu->regs[23] - 8ULL;
    cpu->regs[25] = cpu->regs[7] - 4ULL;
    cpu->regs[8] = cpu->regs[2] + (cpu->regs[21] << 2);
    FLAG_CMP(cpu->regs[20], cpu->regs[7]);
    if (FLAG_HS) goto L_171188;
    PB_LDRW(cpu->regs[1], (cpu->regs[26] + cpu->regs[1]));
    cpu->regs[7] = cpu->regs[7] + cpu->regs[23];
    PB_LDRW(cpu->regs[0], (cpu->regs[26] + cpu->regs[0]));
    cpu->regs[21] = cpu->regs[1];
    PB_STR((SP + 112), cpu->regs[0]);
    PB_STRW((SP + 132), cpu->regs[1]);
L_170ffc:
    PB_STR((SP + 96), cpu->regs[8]); PB_STR((SP + 96) + 8, cpu->regs[7]);
    cpu->regs[30] = PB_BASE + 0x171004ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x12cde0ULL);
    PB_LDR(cpu->regs[8], (SP + 96)); PB_LDR(cpu->regs[7], (SP + 96) + 8);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_171734;
    PB_LDRW(cpu->regs[12], (cpu->regs[7] + -4));
    PB_LDRW(cpu->regs[3], (cpu->regs[7] + -12)); PB_LDRW(cpu->regs[2], (cpu->regs[7] + -12) + 4);
    cpu->regs[1] = ((cpu->regs[12] & 0xffffffffULL) << 30);
    PB_LDRW(cpu->regs[4], (SP + 112));
    cpu->regs[1] = cpu->regs[1] | cpu->regs[2];
    cpu->regs[2] = (cpu->regs[21] ? cpu->regs[1] / cpu->regs[21] : 0);
    cpu->regs[1] = cpu->regs[1] - cpu->regs[2] * cpu->regs[21];
    cpu->regs[11] = cpu->regs[2];
    cpu->regs[4] = (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[4];
    cpu->regs[13] = cpu->regs[3] | (cpu->regs[1] << 30);
    FLAG_CMP(cpu->regs[13], cpu->regs[4]);
    if (FLAG_LO) goto L_1713dc;
L_17103c:
    if ((cpu->regs[19])==0) goto L_1714f0;
    cpu->regs[1] = cpu->regs[19] & 3ULL; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[3] = 0ULL;
    if (FLAG_EQ) goto L_1710cc;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_17109c;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_171078;
    PB_LDRW(cpu->regs[2], (cpu->regs[26] + 0));
    cpu->regs[3] = 1ULL;
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[25],&_s,4); cpu->regs[1] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[1] = cpu->regs[1] - (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[11];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + 0), cpu->regs[2]);
    cpu->regs[0] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
L_171078:
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[3] << 2)));
    PB_LDRW(cpu->regs[2], (cpu->regs[26] + (cpu->regs[3] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] - (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[11];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[3] << 2)), cpu->regs[2]);
    cpu->regs[0] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
L_17109c:
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[3] << 2)));
    PB_LDRW(cpu->regs[2], (cpu->regs[26] + (cpu->regs[3] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] - (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[11];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[3] << 2)), cpu->regs[2]);
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 30);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    cpu->regs[0] = cpu->regs[1];
    FLAG_CMP(cpu->regs[3], cpu->regs[19]);
    if (FLAG_EQ) goto L_171168;
L_1710cc:
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[3] << 2)));
    cpu->regs[4] = cpu->regs[3] + 1ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[26] + (cpu->regs[3] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] - (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[11];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[3] << 2)), cpu->regs[2]);
    cpu->regs[0] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
    cpu->regs[3] = cpu->regs[3] + 2ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[4] << 2)));
    PB_LDRW(cpu->regs[2], (cpu->regs[26] + (cpu->regs[4] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] - (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[11];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[4] << 2)), cpu->regs[2]);
    cpu->regs[0] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[3] << 2)));
    PB_LDRW(cpu->regs[2], (cpu->regs[26] + (cpu->regs[3] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] - (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[11];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[3] << 2)), cpu->regs[2]);
    cpu->regs[3] = cpu->regs[4] + 2ULL;
    cpu->regs[0] = ((cpu->regs[1] >> 30) & 0xffffffffULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[3] << 2)));
    PB_LDRW(cpu->regs[2], (cpu->regs[26] + (cpu->regs[3] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + cpu->regs[1]));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[1] = cpu->regs[1] - (uint64_t)(uint32_t)cpu->regs[2] * (uint64_t)(uint32_t)cpu->regs[11];
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[3] << 2)), cpu->regs[2]);
    cpu->regs[1] = (uint64_t)((int64_t)cpu->regs[1] >> 30);
    cpu->regs[3] = cpu->regs[4] + 3ULL;
    cpu->regs[0] = cpu->regs[1];
    FLAG_CMP(cpu->regs[3], cpu->regs[19]);
    if (FLAG_NE) goto L_1710cc;
L_171168:
    FLAG_CMP(cpu->regs[12], (uint64_t)(-(int64_t)(cpu->regs[1])));
    if (FLAG_LT) goto L_17151c;
L_171170:
    cpu->regs[25] = cpu->regs[25] - 4ULL;
    cpu->regs[8] += -4; PB_STRW(cpu->regs[8], cpu->regs[11]);
    cpu->regs[0] = cpu->regs[25] + 4ULL;
    cpu->regs[7] = cpu->regs[7] - 4ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_LO) goto L_170ffc;
L_171188:
    if ((cpu->regs[19])==0) goto L_171360;
    cpu->regs[0] = cpu->regs[23] - 4ULL;
    cpu->regs[4] = 4294967295ULL;
    cpu->regs[4] = ((uint32_t)(cpu->regs[4] << (cpu->regs[27] & 63)));
    cpu->regs[1] = cpu->regs[23] + 20ULL;
    cpu->regs[0] = cpu->regs[0] >> 2;
    cpu->regs[4] = ((uint32_t)((~cpu->regs[4])));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] & 7ULL; FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_171294;
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_EQ) goto L_171270;
    FLAG_CMP(cpu->regs[0], 2ULL);
    if (FLAG_EQ) goto L_171254;
    FLAG_CMP(cpu->regs[0], 3ULL);
    if (FLAG_EQ) goto L_171238;
    FLAG_CMP(cpu->regs[0], 4ULL);
    if (FLAG_EQ) goto L_17121c;
    FLAG_CMP(cpu->regs[0], 5ULL);
    if (FLAG_EQ) goto L_171200;
    FLAG_CMP(cpu->regs[0], 6ULL);
    if (FLAG_NE) goto L_1714c8;
L_1711e4:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[2] = ((cpu->regs[2] & 0xffffffffULL) << 30);
    cpu->regs[0] = cpu->regs[2] | cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] - 4ULL;
L_171200:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[2] = ((cpu->regs[2] & 0xffffffffULL) << 30);
    cpu->regs[0] = cpu->regs[2] | cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] - 4ULL;
L_17121c:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[2] = ((cpu->regs[2] & 0xffffffffULL) << 30);
    cpu->regs[0] = cpu->regs[2] | cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] - 4ULL;
L_171238:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[2] = ((cpu->regs[2] & 0xffffffffULL) << 30);
    cpu->regs[0] = cpu->regs[2] | cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] - 4ULL;
L_171254:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[2] = ((cpu->regs[2] & 0xffffffffULL) << 30);
    cpu->regs[0] = cpu->regs[2] | cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] - 4ULL;
L_171270:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[2] = ((cpu->regs[2] & 0xffffffffULL) << 30);
    cpu->regs[0] = cpu->regs[2] | cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] - 4ULL;
    FLAG_CMP(cpu->regs[1], 20ULL);
    if (FLAG_EQ) goto L_171360;
L_171294:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[2] = ((cpu->regs[2] & 0xffffffffULL) << 30);
    cpu->regs[3] = cpu->regs[1] - 4ULL;
    cpu->regs[0] = cpu->regs[2] | cpu->regs[0];
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[1] - 8ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[3]));
    cpu->regs[0] = cpu->regs[0] | (cpu->regs[2] << 30);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[3]), cpu->regs[0]);
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] | (cpu->regs[2] << 30);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[3] - 8ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] | (cpu->regs[2] << 30);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[3] - 12ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] | (cpu->regs[2] << 30);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[3] - 16ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] | (cpu->regs[2] << 30);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[3] - 20ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] | (cpu->regs[2] << 30);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[3] - 24ULL;
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[0] = cpu->regs[0] | (cpu->regs[2] << 30);
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[3] - 28ULL;
    FLAG_CMP(cpu->regs[3], 48ULL);
    if (FLAG_NE) goto L_171294;
L_171360:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_171384;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_171384;
    PB_LDR(cpu->regs[1], (cpu->regs[28] + 8));
    cpu->regs[0] = cpu->regs[28];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x171384ULL; PB_CALL(13, cpu, tlb, cpu->regs[1]);
L_171384:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    cpu->regs[0] = cpu->regs[1] >> 3;
    if ((cpu->regs[0])==0) goto L_17139c;
    cpu->regs[3] = cpu->regs[22] + (cpu->regs[0] << 2);
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 20));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_17143c;
L_17139c:
    PB_LDR(cpu->regs[0], (SP + 120));
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 16));
    PB_STR((cpu->regs[0] + 0), cpu->regs[22]);
    cpu->regs[0] = cpu->regs[1] >> 3;
    if ((cpu->regs[0])==0) goto L_1713bc;
    cpu->regs[3] = cpu->regs[24] + (cpu->regs[0] << 2);
    PB_LDRW(cpu->regs[2], (cpu->regs[3] + 20));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_17145c;
L_1713bc:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_1713c4:
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 144;
    return;
L_1713dc:
    PB_LDRW(cpu->regs[4], (SP + 132));
    cpu->regs[11] = ((uint32_t)(cpu->regs[2] - 1ULL));
    cpu->regs[2] = 1073741823ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[4] + cpu->regs[1]));
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_HI) goto L_17103c;
L_1713f4:
    PB_LDRW(cpu->regs[4], (SP + 112));
    cpu->regs[2] = ((cpu->regs[1] & 0xffffffffULL) << 30);
    cpu->regs[2] = cpu->regs[2] | cpu->regs[3];
    cpu->regs[4] = (uint64_t)(uint32_t)cpu->regs[11] * (uint64_t)(uint32_t)cpu->regs[4];
    FLAG_CMP(cpu->regs[4], cpu->regs[2]);
    if (FLAG_LS) goto L_17103c;
    PB_LDRW(cpu->regs[2], (SP + 132));
    cpu->regs[11] = ((uint32_t)(cpu->regs[11] - 1ULL));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[2] = 1073741823ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_LS) goto L_1713f4;
    goto L_17103c;
L_171428:
    cpu->regs[1] = 0ULL;
L_17142c:
    cpu->regs[24] = cpu->regs[28] + (cpu->regs[24] << 2);
    cpu->regs[25] = cpu->regs[21];
    PB_STRW((cpu->regs[24] + 24), cpu->regs[1]);
    goto L_170fa4;
L_17143c:
    cpu->regs[2] = cpu->regs[0] - 1ULL; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_1714fc;
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 16));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_171484;
L_17144c:
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[2] = cpu->regs[1] | (cpu->regs[2] << 3);
    PB_STR((cpu->regs[22] + 16), cpu->regs[2]);
    goto L_17139c;
L_17145c:
    cpu->regs[2] = cpu->regs[0] - 1ULL; FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_171508;
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 16));
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_1714a4;
L_17146c:
    cpu->regs[1] = cpu->regs[1] & 3ULL;
    cpu->regs[2] = cpu->regs[1] | (cpu->regs[2] << 3);
    PB_STR((cpu->regs[24] + 16), cpu->regs[2]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1713c4;
L_171484:
    cpu->regs[2] = cpu->regs[0] - 2ULL;
L_171488:
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    if ((cpu->regs[2])==0) goto L_1714fc;
    PB_LDRW(cpu->regs[4], (cpu->regs[26] + (cpu->regs[3] << 2)));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1714e8;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_17144c;
    goto L_17139c;
L_1714a4:
    cpu->regs[2] = cpu->regs[0] - 2ULL;
L_1714a8:
    cpu->regs[3] = cpu->regs[2] - 1ULL;
    if ((cpu->regs[2])==0) goto L_171508;
    PB_LDR(cpu->regs[4], (SP + 136));
    PB_LDRW(cpu->regs[4], (cpu->regs[4] + (cpu->regs[3] << 2)));
    if ((((uint32_t)(cpu->regs[4])))==0) goto L_1714e0;
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_17146c;
    goto L_1713bc;
L_1714c8:
    PB_LDRW(cpu->regs[0], (cpu->regs[28] + cpu->regs[1]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[4] & cpu->regs[0]));
    cpu->regs[0] = cpu->regs[0] >> (cpu->regs[27] & 63);
    PB_STRW((cpu->regs[22] + cpu->regs[1]), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[23] + 16ULL;
    goto L_1711e4;
L_1714e0:
    cpu->regs[2] = cpu->regs[3];
    goto L_1714a8;
L_1714e8:
    cpu->regs[2] = cpu->regs[3];
    goto L_171488;
L_1714f0:
    if (!((cpu->regs[12] >> 31) & 1)) goto L_171170;
L_1714f4:
    cpu->regs[11] = ((uint32_t)(cpu->regs[11] - 1ULL));
    goto L_171170;
L_1714fc:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[22] + 16), cpu->regs[0]);
    goto L_17139c;
L_171508:
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[24] + 16), cpu->regs[0]);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_1713c4;
L_17151c:
    cpu->regs[1] = cpu->regs[19] & 7ULL; FLAG_CMP(cpu->regs[1], 0);
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = 0ULL;
    if (FLAG_EQ) goto L_171640;
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_EQ) goto L_171618;
    FLAG_CMP(cpu->regs[1], 2ULL);
    if (FLAG_EQ) goto L_1715f8;
    FLAG_CMP(cpu->regs[1], 3ULL);
    if (FLAG_EQ) goto L_1715d8;
    FLAG_CMP(cpu->regs[1], 4ULL);
    if (FLAG_EQ) goto L_1715b8;
    FLAG_CMP(cpu->regs[1], 5ULL);
    if (FLAG_EQ) goto L_171598;
    FLAG_CMP(cpu->regs[1], 6ULL);
    if (FLAG_EQ) goto L_171578;
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + 0));
    cpu->regs[0] = 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + 0), cpu->regs[3]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] >> 30));
L_171578:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_171598:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_1715b8:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_1715d8:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_1715f8:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
L_171618:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_EQ) goto L_1714f4;
L_171640:
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    cpu->regs[4] = cpu->regs[0] + 1ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[0] + 2ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[4] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[4] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + (cpu->regs[2] >> 30)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[4] << 2)), cpu->regs[3]);
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + (cpu->regs[2] >> 30)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[4] + 2ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + (cpu->regs[2] >> 30)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[4] + 3ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + (cpu->regs[2] >> 30)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[4] + 4ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + (cpu->regs[2] >> 30)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[4] + 5ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + (cpu->regs[2] >> 30)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[4] + 6ULL;
    PB_LDRW(cpu->regs[3], (cpu->regs[26] + (cpu->regs[0] << 2)));
    PB_LDRW(cpu->regs[1], (cpu->regs[25] + (cpu->regs[0] << 2)));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[3]));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] + (cpu->regs[2] >> 30)));
    cpu->regs[3] = ((uint32_t)(cpu->regs[2] & 1073741823ULL));
    PB_STRW((cpu->regs[25] + (cpu->regs[0] << 2)), cpu->regs[3]);
    cpu->regs[0] = cpu->regs[4] + 7ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] >> 30));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_171640;
    cpu->regs[11] = ((uint32_t)(cpu->regs[11] - 1ULL));
    goto L_171170;
L_171734:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_171748;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1717d4;
L_171748:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_17175c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1717b4;
L_17175c:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_171770;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1717c0;
L_171770:
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
L_171774:
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
L_171778:
    cpu->regs[24] = 0ULL;
    PB_LDR(cpu->regs[0], (SP + 120));
    PB_STR((cpu->regs[0] + 0), 0ULL);
    goto L_1713c4;
L_171788:
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_171774;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[28] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_171774;
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1717a4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_171778;
L_1717ac:
    cpu->regs[0] = 0ULL;
    goto L_170d48;
L_1717b4:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1717bcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_17175c;
L_1717c0:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1717c8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[27], (SP + 80)); PB_LDR(cpu->regs[28], (SP + 80) + 8);
    goto L_171778;
L_1717d4:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1717dcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_171748;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
L_1717f0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    if ((cpu->regs[1])==0) goto L_171874;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_17181c;
L_171800:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x17180cULL; PB_CALL(18, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_17187c;
L_171810:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_17181c:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x171824ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_171850;
    cpu->regs[30] = PB_BASE + 0x171830ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xe7e88ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_171848;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1718c8;
L_171848:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])!=0) goto L_171800;
L_171850:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_171874;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_171874;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_171874;
    cpu->regs[30] = PB_BASE + 0x171874ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_171874:
    cpu->regs[0] = 0ULL;
    goto L_171810;
L_17187c:
    cpu->regs[30] = PB_BASE + 0x171880ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1718ac;
L_171884:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1718d4;
L_17188c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1717f0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1717f0;
    cpu->regs[30] = PB_BASE + 0x1718a8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1717f0;
L_1718ac:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1718bcULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_171874;
    cpu->regs[30] = PB_BASE + 0x1718c4ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_171884;
L_1718c8:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1718d0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_171848;
L_1718d4:
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2368));
L_1718e0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    if ((cpu->regs[1])==0) goto L_17191c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_171928;
L_1718f0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 224));
    cpu->regs[30] = PB_BASE + 0x1718fcULL; PB_CALL(27, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_171908;
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_171810;
L_171908:
    cpu->regs[30] = PB_BASE + 0x17190cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_171968;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0x171918ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_171964;
L_17191c:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = 0ULL;
    goto L_171810;
L_171928:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x171930ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_17195c;
    cpu->regs[30] = PB_BASE + 0x17193cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe7e88ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    if (((cpu->regs[1] >> 31) & 1)) goto L_171954;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_171978;
L_171954:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])!=0) goto L_1718f0;
L_17195c:
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_171850;
L_171964:
    cpu->regs[30] = PB_BASE + 0x171968ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x121fa0ULL);
L_171968:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_1718e0;
    PB_LDR(cpu->regs[21], (SP + 32));
    goto L_17188c;
L_171978:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x171980ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_171954;
}
