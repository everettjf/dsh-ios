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

void ft_PyObject_DelItem(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    cpu->regs[29] = SP;
    if (FLAG_EQ) goto L_1449a8;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 112));
    if ((cpu->regs[3])==0) goto L_1449b8;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 16));
    if ((cpu->regs[3])==0) goto L_1449b8;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[16] = cpu->regs[3];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[2] = 0ULL;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1449a8:
    cpu->regs[30] = PB_BASE + 0x1449acULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x96bd4ULL);
L_1449ac:
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1449b8:
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 104));
    if ((cpu->regs[0])==0) goto L_144a10;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 96));
    if ((cpu->regs[3])==0) goto L_144a08;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 264));
    if ((cpu->regs[3])==0) goto L_144a08;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3880));
    cpu->regs[0] = cpu->regs[2];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x1449e8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_144a28;
L_1449f4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[3];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x1bf2a0ULL); return; };
L_144a08:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 40));
    if ((cpu->regs[0])!=0) goto L_144a38;
L_144a10:
    cpu->regs[1] = cpu->regs[4];
    cpu->regs[0] = PB_BASE + 0x28d000ULL;
    cpu->regs[0] = cpu->regs[0] + 96ULL;
    cpu->regs[30] = PB_BASE + 0x144a20ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x234660ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    goto L_1449ac;
L_144a28:
    cpu->regs[30] = PB_BASE + 0x144a2cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1449f4;
    PB_LDR(cpu->regs[19], (SP + 16));
    goto L_1449ac;
L_144a38:
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[30] = PB_BASE + 0x144a44ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x234660ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    goto L_1449ac;
    SP = SP - 64ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x144a7cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xe7e88ULL);
    if ((cpu->regs[0])==0) goto L_144c08;
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x137000ULL;
    cpu->regs[0] = cpu->regs[0] + 928ULL;
    cpu->regs[22] = SP;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 224));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_144ac4;
    goto L_144b78;
L_144aa4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x144aacULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_144c1c;
L_144ab8:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_144c34;
    if (FLAG_EQ) goto L_144b3c;
L_144ac4:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x144adcULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x137460ULL);
    PB_LDR(cpu->regs[19], (SP + 0));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_144b9c;
    if ((cpu->regs[19])!=0) goto L_144aa4;
L_144ae8:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_144afc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_144b8c;
L_144afc:
    cpu->regs[30] = PB_BASE + 0x144b00ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_144bf4;
L_144b04:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
L_144b0c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_144b98;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_144b3c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_144b50;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_144c10;
L_144b50:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3184));
    goto L_144b0c;
L_144b5c:
    cpu->regs[30] = PB_BASE + 0x144b60ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_144bdc;
L_144b6c:
    FLAG_CMP(((uint32_t)(cpu->regs[22])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_144c34;
    if (FLAG_EQ) goto L_144b3c;
L_144b78:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x144b80ULL; PB_CALL(12, cpu, tlb, cpu->regs[19]);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_144b5c;
    goto L_144ae8;
L_144b8c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x144b94ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_144afc;
L_144b98:
    cpu->regs[30] = PB_BASE + 0x144b9cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7c170ULL);
L_144b9c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_144bb8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x144bb4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x252128ULL);
    if ((cpu->regs[19])==0) goto L_144ae8;
L_144bb8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((SP + 0), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_144ae8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_144ae8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x144bd8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_144ae8;
L_144bdc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_144b6c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x144bf0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_144b6c;
L_144bf4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2368));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x144c04ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x121d30ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_144c58;
L_144c08:
    cpu->regs[0] = 0ULL;
    goto L_144b0c;
L_144c10:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x144c18ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_144b50;
L_144c1c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_144ab8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x144c30ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_144ab8;
L_144c34:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_144c08;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_144c08;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x144c50ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    goto L_144b0c;
L_144c58:
    cpu->regs[30] = PB_BASE + 0x144c5cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_144b04;
}
