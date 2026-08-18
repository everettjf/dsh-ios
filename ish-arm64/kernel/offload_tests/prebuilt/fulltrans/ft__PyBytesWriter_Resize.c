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

void ft__PyBytesWriter_Resize(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 28));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c6cc4;
L_1c6c64:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 32));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 24));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c6d30;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[19] + 36ULL;
    cpu->regs[22] = cpu->regs[21] - cpu->regs[23];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1c6d60;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c6c8cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xe9c70ULL);
L_1c6c8c:
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1c6dbc;
    if ((cpu->regs[22])!=0) goto L_1c6ce8;
L_1c6c98:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_STRW((cpu->regs[19] + 32), 0ULL);
L_1c6ca0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 32));
    PB_STR((cpu->regs[19] + 8), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c6d1c;
    cpu->regs[19] = cpu->regs[19] + 36ULL;
L_1c6cb0:
    cpu->regs[0] = cpu->regs[19] + cpu->regs[22];
L_1c6cb4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1c6cc4:
    cpu->regs[0] = 4ULL;
    cpu->regs[1] = 9223372036854775807ULL;
    cpu->regs[0] = (cpu->regs[0] ? (uint64_t)((int64_t)cpu->regs[2] / (int64_t)cpu->regs[0]) : 0);
    cpu->regs[0] = (uint64_t)(-(int64_t)cpu->regs[0]);
    cpu->regs[1] = cpu->regs[0] + cpu->regs[1];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_LT) goto L_1c6c64;
    cpu->regs[20] = cpu->regs[2] - cpu->regs[0];
    goto L_1c6c64;
L_1c6ce8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 24));
    cpu->regs[2] = cpu->regs[0] + 32ULL;
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1c6dd4;
L_1c6cf4:
    FLAG_CMP(cpu->regs[2], cpu->regs[23]);
    if (FLAG_HS) goto L_1c6dc4;
    cpu->regs[0] = cpu->regs[2] + cpu->regs[22];
    FLAG_CMP(cpu->regs[23], cpu->regs[0]);
    if (FLAG_LO) goto L_1c6dd0;
L_1c6d08:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1c6d18ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7c090ULL);
    goto L_1c6c98;
L_1c6d1c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c6d70;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 0));
    cpu->regs[19] = cpu->regs[19] + 32ULL;
    goto L_1c6cb0;
L_1c6d30:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1c6d88;
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[22] = cpu->regs[21] - cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6d4cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x13e868ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c6ca0;
L_1c6d50:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6d58ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1fa1e0ULL);
    cpu->regs[0] = 0ULL;
    goto L_1c6cb4;
L_1c6d60:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c6d6cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1fc8e0ULL);
    goto L_1c6c8c;
L_1c6d70:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])!=0) goto L_1c6dac;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 3336));
    goto L_1c6cb0;
L_1c6d88:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])!=0) goto L_1c6db4;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 3336));
L_1c6d98:
    cpu->regs[22] = cpu->regs[21] - cpu->regs[22];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c6da4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1e6c20ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1c6ca0;
    goto L_1c6d50;
L_1c6dac:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 40));
    goto L_1c6cb0;
L_1c6db4:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 40));
    goto L_1c6d98;
L_1c6dbc:
    PB_LDR(cpu->regs[23], (SP + 48));
    goto L_1c6d50;
L_1c6dc4:
    if (FLAG_LS) goto L_1c6d08;
    FLAG_CMP(cpu->regs[2], cpu->regs[21]);
    if (FLAG_HS) goto L_1c6d08;
L_1c6dd0:
    __builtin_trap();
L_1c6dd4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    if ((cpu->regs[1])!=0) goto L_1c6de8;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3336));
    goto L_1c6cf4;
L_1c6de8:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 40));
    goto L_1c6cf4;
    SP = SP - 64ULL;
    cpu->regs[2] = PB_BASE + 0x28b000ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[2] = cpu->regs[2] + 128ULL;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = SP;
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c6e2cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1c6f50ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1c6f28;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[20], (SP + 0));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c6e44ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1c7344ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c6e50ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xd7784ULL);
    if ((cpu->regs[19])==0) goto L_1c6f48;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[1] = cpu->regs[1] + 1472ULL;
    cpu->regs[30] = PB_BASE + 0x1c6e64ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x11d200ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_1c6e7c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1c6f3c;
L_1c6e7c:
    if ((cpu->regs[20])==0) goto L_1c6f48;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c6e8cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1b0ec0ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_1c6ea4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1c6f30;
L_1c6ea4:
    if ((cpu->regs[19])==0) goto L_1c6f14;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6eb0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x17c9c0ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1c6f08;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[30] = PB_BASE + 0x1c6ec0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xd7784ULL);
    PB_STR((cpu->regs[21] + 0), cpu->regs[22]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6eccULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    cpu->regs[0] = 0ULL;
L_1c6ed4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1c6f00;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
L_1c6f00:
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x1c6f08ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1c6f08:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6f10ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[30] = PB_BASE + 0x1c6f14ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1c6f14:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c6f1cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c6f24ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
L_1c6f28:
    cpu->regs[0] = 4294967295ULL;
    goto L_1c6ed4;
L_1c6f30:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1c6f38ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c6ea4;
L_1c6f3c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1c6f44ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1c6e7c;
L_1c6f48:
    cpu->regs[20] = 0ULL;
    goto L_1c6f14;
L_1c6f50:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[29] = SP;
    cpu->regs[4] = cpu->regs[5];
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1c6f74ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1c6fd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(2ULL)));
    if (FLAG_EQ) goto L_1c6f8c;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1c6fb0;
L_1c6f80:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1c6f8c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 128ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1c6fa8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11f220ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1c6f80;
L_1c6fb0:
    cpu->regs[30] = PB_BASE + 0x1c6fb4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_1c6f80;
    /* nop */
}
