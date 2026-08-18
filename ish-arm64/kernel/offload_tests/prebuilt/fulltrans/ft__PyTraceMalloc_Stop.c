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

void ft__PyTraceMalloc_Stop(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2840));
    cpu->regs[30] = PB_BASE + 0x1ebc08ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 2708));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ebc20;
L_1ebc10:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2840));
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x17faa0ULL); return; };
L_1ebc20:
    cpu->regs[1] = cpu->regs[19] + 2760ULL;
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 2708), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1ebc30ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x17ac80ULL);
    cpu->regs[1] = cpu->regs[19] + 2720ULL;
    cpu->regs[0] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1ebc3cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x17ac80ULL);
    cpu->regs[1] = cpu->regs[19] + 2800ULL;
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1ebc48ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x17ac80ULL);
    cpu->regs[30] = PB_BASE + 0x1ebc4cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x90a18ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2760));
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 2792));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 2872));
    cpu->regs[30] = PB_BASE + 0x1ebc5cULL; PB_CALL(7, cpu, tlb, cpu->regs[2]);
    PB_STR((cpu->regs[19] + 2872), 0ULL);
    goto L_1ebc10;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = cpu->regs[1] + 3568ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 1488));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ebc88ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1e9fc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1ebccc;
L_1ebc90:
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2968ULL;
    cpu->regs[30] = PB_BASE + 0x1ebca4ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e9fc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1ebcd8;
L_1ebcac:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 992));
    if ((cpu->regs[0])==0) goto L_1ebcbc;
    cpu->regs[30] = PB_BASE + 0x1ebcb8ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1c208cULL);
    PB_STR((cpu->regs[19] + 992), 0ULL);
L_1ebcbc:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    goto L_1ebce4;
L_1ebccc:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ebcd4ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ebc90;
L_1ebcd8:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ebce0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ebcac;
L_1ebce4:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 944));
    if ((cpu->regs[0])!=0) goto L_1ebd70;
L_1ebcfc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 952));
    if ((cpu->regs[0])==0) goto L_1ebd20;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 952), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebd20;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ebd20;
    cpu->regs[30] = PB_BASE + 0x1ebd20ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ebd20:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 960));
    if ((cpu->regs[0])==0) goto L_1ebd44;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 960), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebd44;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ebd44;
    cpu->regs[30] = PB_BASE + 0x1ebd44ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ebd44:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 984));
    if ((cpu->regs[0])==0) goto L_1ebd64;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 984), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebd64;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ebd90;
L_1ebd64:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1ebd70:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 944), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ebcfc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ebcfc;
    cpu->regs[30] = PB_BASE + 0x1ebd8cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ebcfc;
L_1ebd90:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
    /* nop */
    { PB_CALL(17, cpu, tlb, PB_BASE + 0xd7784ULL); return; };
    SP = SP - 80ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 2632));
    if ((cpu->regs[1])!=0) goto L_1ebe6c;
L_1ebdd8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2640));
    if ((cpu->regs[0])!=0) goto L_1ebec4;
L_1ebde0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2648));
    if ((cpu->regs[0])!=0) goto L_1ebe88;
L_1ebde8:
    cpu->regs[30] = PB_BASE + 0x1ebdecULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1ec2a0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2656));
    if ((cpu->regs[0])!=0) goto L_1ebe20;
L_1ebdf4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1ebe64;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    SP = SP + 80ULL;
    return;
L_1ebe20:
    cpu->regs[1] = SP;
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 0), 0ULL); PB_STR((SP + 0) + 8, 0ULL);
    PB_STR((SP + 16), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1ebe34ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x7c1d0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 2656));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ebe54;
    PB_LDR(cpu->regs[0], (SP + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1ebe54;
    cpu->regs[0] = cpu->regs[19] + 2680ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ebe54ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c1d0ULL);
L_1ebe54:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2656));
    cpu->regs[30] = PB_BASE + 0x1ebe5cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_STR((cpu->regs[19] + 2656), 0ULL);
    goto L_1ebdf4;
L_1ebe64:
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1ebe6cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1ebe6c:
    cpu->regs[30] = PB_BASE + 0x1ebe70ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x226640ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2632));
    cpu->regs[30] = PB_BASE + 0x1ebe78ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x17faa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2632));
    cpu->regs[30] = PB_BASE + 0x1ebe80ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1c208cULL);
    PB_STR((cpu->regs[19] + 2632), 0ULL);
    goto L_1ebdd8;
L_1ebe88:
    cpu->regs[20] = 0ULL;
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[21] = 192ULL;
L_1ebe94:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2648));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[0] + (uint64_t)(uint32_t)cpu->regs[20] * (uint64_t)(uint32_t)cpu->regs[21];
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x1ebea8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x280450ULL);
    FLAG_CMP(cpu->regs[20], 65ULL);
    if (FLAG_NE) goto L_1ebe94;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 2648));
    cpu->regs[30] = PB_BASE + 0x1ebeb8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[21], (SP + 64));
    PB_STR((cpu->regs[19] + 2648), 0ULL);
    goto L_1ebde8;
L_1ebec4:
    cpu->regs[30] = PB_BASE + 0x1ebec8ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1c208cULL);
    PB_STR((cpu->regs[19] + 2640), 0ULL);
    goto L_1ebde0;
    SP = SP - 160ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    PB_STR((SP + 144), cpu->regs[25]);
    PB_LDR(cpu->regs[0], (cpu->regs[4] + 0));
    PB_STR((SP + 72), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    if ((cpu->regs[3])==0) goto L_1ec0d0;
    cpu->regs[2] = SP + 32ULL;
    PB_STRW((SP + 0), 0ULL);
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[7] = 0ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[3] + 16));
    cpu->regs[4] = cpu->regs[4] + 2880ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ebf3cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1ec340ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ec238;
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 0));
    if ((cpu->regs[21])==0) goto L_1ec228;
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 8));
    if ((cpu->regs[23])!=0) goto L_1ec1c4;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 2760));
L_1ebf5c:
    PB_LDR(cpu->regs[22], (cpu->regs[20] + 16));
    if ((cpu->regs[22])==0) goto L_1ec074;
    cpu->regs[21] = cpu->regs[21] - 1ULL; FLAG_CMP(cpu->regs[21], 0);
    if (FLAG_NE) goto L_1ec07c;
L_1ebf6c:
    cpu->regs[24] = 0ULL;
L_1ebf70:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[5] = 57888ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1ebf84ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x1c7cb0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ec144;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1ec280;
L_1ebf9c:
    FLAG_CMP(cpu->regs[23], cpu->regs[1]);
    if (FLAG_NE) goto L_1ec1e4;
    cpu->regs[23] = 0ULL;
L_1ebfa8:
    FLAG_CMP(cpu->regs[22], cpu->regs[1]);
    if (FLAG_EQ) goto L_1ec0c8;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if (!((cpu->regs[1] >> 28) & 1)) goto L_1ec240;
L_1ebfbc:
    cpu->regs[20] = 0ULL;
L_1ebfc0:
    PB_LDR(cpu->regs[1], (cpu->regs[25] + 16));
    cpu->regs[21] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[20]));
    FLAG_CMP(cpu->regs[1], cpu->regs[20]);
    if (FLAG_LE) goto L_1ebff8;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    if (FLAG_GT) goto L_1ec118;
L_1ebfd8:
    cpu->regs[21] = cpu->regs[25] + (cpu->regs[21] << 3);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    cpu->regs[30] = PB_BASE + 0x1ebfecULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ec130;
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] + 1ULL));
    goto L_1ebfc0;
L_1ebff8:
    if ((cpu->regs[22])==0) goto L_1ec0b4;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1ec00cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1e31c0ULL);
L_1ec00c:
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ec130;
    if ((((uint32_t)(cpu->regs[24])))!=0) goto L_1ec164;
L_1ec014:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ec028;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1ec1d8;
L_1ec028:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
L_1ec030:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1ec038ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1ec1a8;
    PB_LDR(cpu->regs[25], (SP + 144));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    SP = SP + 160ULL;
    return;
L_1ec074:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
L_1ec07c:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 24));
    if ((cpu->regs[19])==0) goto L_1ec14c;
    cpu->regs[24] = 0ULL;
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_NE) goto L_1ec1ac;
L_1ec090:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[19], cpu->regs[1]);
    if (FLAG_EQ) goto L_1ebf70;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1ebf9c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_1ebf9c;
L_1ec0b4:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 1024ULL;
    cpu->regs[30] = PB_BASE + 0x1ec0c4ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1e3340ULL);
    goto L_1ec00c;
L_1ec0c8:
    cpu->regs[22] = 0ULL;
    goto L_1ebfbc;
L_1ec0d0:
    cpu->regs[2] = SP + 32ULL;
    PB_STRW((SP + 0), 0ULL);
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x520000ULL;
    cpu->regs[4] = cpu->regs[4] + 16ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[4] = cpu->regs[4] + 2880ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[5] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ec0fcULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1ec340ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ec238;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    PB_LDR(cpu->regs[25], (cpu->regs[20] + 0));
    cpu->regs[23] = cpu->regs[22];
    goto L_1ebf6c;
L_1ec118:
    if ((cpu->regs[23])!=0) goto L_1ec268;
    cpu->regs[0] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1688ULL;
    cpu->regs[30] = PB_BASE + 0x1ec12cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1e3340ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ebfd8;
L_1ec130:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ec144;
L_1ec138:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1ec218;
L_1ec144:
    cpu->regs[20] = 0ULL;
    goto L_1ec030;
L_1ec14c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[30] = PB_BASE + 0x1ec154ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[24] = cpu->regs[0];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1ebf70;
    cpu->regs[20] = 0ULL;
    goto L_1ec030;
L_1ec164:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 44840ULL;
    cpu->regs[1] = SP + 24ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 24), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1ec188ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1ec130;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (((cpu->regs[2] >> 31) & 1)) goto L_1ec014;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1ec014;
    cpu->regs[30] = PB_BASE + 0x1ec1a4ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ec014;
L_1ec1a8:
    cpu->regs[30] = PB_BASE + 0x1ec1acULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1ec1ac:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[30] = PB_BASE + 0x1ec1b4ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[24] = cpu->regs[0];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1ec090;
    cpu->regs[20] = 0ULL;
    goto L_1ec030;
L_1ec1c4:
    cpu->regs[21] = cpu->regs[21] - 1ULL; FLAG_CMP(cpu->regs[21], 0);
    if (FLAG_NE) goto L_1ebf5c;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    goto L_1ebf6c;
L_1ec1d8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ec1e0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ec028;
L_1ec1e4:
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 28) & 1)) goto L_1ebfa8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 1400ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1ec20cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1ec138;
    goto L_1ec144;
L_1ec218:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ec224ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ec030;
L_1ec228:
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 2760));
    cpu->regs[23] = cpu->regs[22];
    goto L_1ebf6c;
L_1ec238:
    cpu->regs[25] = 0ULL;
    goto L_1ec030;
L_1ec240:
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2736));
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[1] + 1448ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    cpu->regs[30] = PB_BASE + 0x1ec25cULL; PB_CALL(45, cpu, tlb, PB_BASE + 0x11f220ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1ec138;
    goto L_1ec144;
L_1ec268:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x1ec278ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ebfd8;
    goto L_1ec130;
L_1ec280:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ec028;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ec028;
    cpu->regs[30] = PB_BASE + 0x1ec298ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ec028;
    /* nop */
L_1ec2a0:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 2536));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ec2d0;
L_1ec2bc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 2544));
    if ((cpu->regs[0])!=0) goto L_1ec31c;
L_1ec2c4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1ec2d0:
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = PB_BASE + 0x51e000ULL;
    cpu->regs[19] = cpu->regs[19] + 3856ULL;
    cpu->regs[19] = cpu->regs[19] + 2568ULL;
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[21] + 2536), 0ULL);
L_1ec2e8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 4));
    cpu->regs[1] = cpu->regs[19] + 16ULL;
    cpu->regs[2] = 0ULL;
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ec304;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STRW((cpu->regs[19] + 4), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1ec304ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x7c030ULL);
L_1ec304:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    cpu->regs[19] = cpu->regs[19] + 176ULL;
    FLAG_CMP(cpu->regs[20], 5ULL);
    if (FLAG_NE) goto L_1ec2e8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    goto L_1ec2bc;
L_1ec31c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[21] + 2544), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ec2c4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ec2c4;
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(49, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
}
