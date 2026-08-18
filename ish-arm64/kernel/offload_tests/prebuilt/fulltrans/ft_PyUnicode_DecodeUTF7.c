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

void ft_PyUnicode_DecodeUTF7(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[3] = 0ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x17804cULL); return; };
    SP = SP - 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[2] = SP;
    cpu->regs[1] = PB_BASE + 0x296000ULL;
    cpu->regs[1] = cpu->regs[1] + 2136ULL;
    PB_STR((SP + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0xc7d28ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c7d34;
L_c7d2c:
    cpu->regs[20] = 0ULL;
    goto L_c7d80;
L_c7d34:
    PB_LDR(cpu->regs[2], (SP + 0));
    cpu->regs[0] = 2ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 72));
    cpu->regs[30] = PB_BASE + 0xc7d44ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_c7d2c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3792));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc7d60ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x208e6cULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c7d80;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c7d80;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xc7d80ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c7d80:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_c7da0;
    cpu->regs[30] = PB_BASE + 0xc7da0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c7da0:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 112ULL;
    cpu->regs[4] = cpu->tls_ptr;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xc7ddcULL; PB_CALL(7, cpu, tlb, cpu->regs[3]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[1];
    cpu->regs[24] = cpu->regs[2];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[1], (cpu->regs[4] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_LDR(cpu->regs[4], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[3] = SP + 8ULL;
    cpu->regs[4] = cpu->regs[4] + (66ULL << 12);
    cpu->regs[2] = SP + 16ULL;
    cpu->regs[4] = cpu->regs[4] + 3064ULL;
    cpu->regs[1] = cpu->regs[1] + 208ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[4] + 24));
    PB_STR((SP + 8), 0ULL); PB_STR((SP + 8) + 8, 0ULL);
    cpu->regs[30] = PB_BASE + 0xc7e34ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_c7e60;
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xc7e44ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1fa720ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c7e68;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc7e60ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_c7e60:
    cpu->regs[0] = 0ULL;
    goto L_c8008;
L_c7e68:
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xc7e70ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdc3e0ULL);
    PB_STR((SP + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_c7e60;
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 16));
    if ((cpu->regs[25])!=0) goto L_c7e9c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[1] = cpu->regs[1] + 288ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc7e98ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c7fe8;
L_c7e9c:
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 3640));
    cpu->regs[22] = 0ULL;
    cpu->regs[20] = 0ULL;
L_c7eac:
    FLAG_CMP(cpu->regs[22], cpu->regs[25]);
    if (FLAG_GE) goto L_c7f10;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[22] << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_c7fe8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 168));
    if (((cpu->regs[1] >> 30) & 1)) goto L_c7ef0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[1] = cpu->regs[1] + 352ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc7eecULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c7fe8;
L_c7ef0:
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    cpu->regs[30] = PB_BASE + 0xc7ef8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11e0a4ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LT) goto L_c7fe8;
    if (FLAG_NE) { FLAG_CMP(cpu->regs[20], 0ULL); } else { FLAG_CMP(0, 1); }
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    cpu->regs[20] = (FLAG_NE) ? 1 : 0;
    goto L_c7eac;
L_c7f10:
    FLAG_CMP(cpu->regs[21], cpu->regs[19]);
    cpu->regs[20] = ((uint32_t)(cpu->regs[20] & 1ULL));
    if (FLAG_NE) goto L_c7f3c;
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_c7fa0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[1] = cpu->regs[1] + 416ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc7f38ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_c7fe8;
L_c7f3c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3792));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_NE) goto L_c7f58;
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_c7fa0;
    goto L_c7fa4;
L_c7f58:
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_c7fa0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3640));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xc7f70ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x136260ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c7fe8;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_c7fa0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    cpu->regs[1] = cpu->regs[1] + 464ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xc7f9cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_c7fe8;
L_c7fa0:
    cpu->regs[21] = cpu->regs[19];
L_c7fa4:
    if ((cpu->regs[21])!=0) goto L_c7fb4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3792));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 0));
L_c7fb4:
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xc7fc4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe2424ULL);
    if ((cpu->regs[0])==0) goto L_c7fe8;
    PB_LDR(cpu->regs[2], (SP + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_c7fdc;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_c7fdc:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_STR((cpu->regs[0] + 72), cpu->regs[2]); PB_STR((cpu->regs[0] + 72) + 8, cpu->regs[1]);
    goto L_c8008;
L_c7fe8:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_c7e60;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_c7e60;
    cpu->regs[30] = PB_BASE + 0xc8004ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_c7e60;
L_c8008:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_EQ) goto L_c8028;
    cpu->regs[30] = PB_BASE + 0xc8028ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x7c170ULL);
L_c8028:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0xc805cULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x137bd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_c80d8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_c8088;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_c8088;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c8088;
    cpu->regs[30] = PB_BASE + 0xc8088ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c8088:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])==0) goto L_c80ac;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 104), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_c80ac;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_c80ac;
    cpu->regs[30] = PB_BASE + 0xc80acULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_c80ac:
    cpu->regs[1] = PB_BASE + 0x2a7000ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[5] = cpu->regs[19] + 104ULL;
    cpu->regs[1] = cpu->regs[1] + 504ULL;
    cpu->regs[4] = cpu->regs[19] + 96ULL;
    cpu->regs[3] = cpu->regs[19] + 88ULL;
    cpu->regs[2] = cpu->regs[19] + 80ULL;
    cpu->regs[30] = PB_BASE + 0xc80ccULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1404d0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_c80e0;
    PB_STR((cpu->regs[19] + 80), 0ULL);
    PB_STR((cpu->regs[19] + 104), 0ULL);
L_c80d8:
    cpu->regs[0] = 4294967295ULL;
    goto L_c810c;
L_c80e0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 80));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c80f4;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_c80f4:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 104));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_c8108;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_c8108:
    cpu->regs[0] = 0ULL;
L_c810c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
