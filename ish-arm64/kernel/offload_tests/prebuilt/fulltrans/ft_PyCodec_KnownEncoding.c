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

void ft_PyCodec_KnownEncoding(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0xa6c9cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1c7344ULL);
    if ((cpu->regs[0])!=0) goto L_a6cac;
    cpu->regs[30] = PB_BASE + 0xa6ca4ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = 0ULL;
    goto L_a6cc8;
L_a6cac:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a6cc4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a6cc4;
    cpu->regs[30] = PB_BASE + 0xa6cc4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a6cc4:
    cpu->regs[0] = 1ULL;
L_a6cc8:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0xa6ce8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    if ((cpu->regs[1])==0) goto L_a6cf4;
    cpu->regs[30] = PB_BASE + 0xa6cf4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x13f6ecULL);
L_a6cf4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6cfcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x88f3cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6d08ULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a6d2c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a6d2c;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_a6d2c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0xa6d50ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a6d6c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a6d6c;
    cpu->regs[30] = PB_BASE + 0xa6d6cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a6d6c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6d74ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1ef630ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6d7cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x13f6ecULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0xa6d8cULL; PB_CALL(13, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a6db0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a6db0;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_a6db0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0xa6dd4ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a6df0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a6df0;
    cpu->regs[30] = PB_BASE + 0xa6df0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a6df0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0xa6df8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6e00ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1ef630ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6e08ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x13f6ecULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0xa6e18ULL; PB_CALL(20, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a6e3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a6e3c;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_a6e3c:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP = SP - 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[3] = 25968ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xa6e88ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x122b00ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a6ecc;
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa6ea0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1d3764ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a6eb8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_a6ec0;
L_a6eb8:
    cpu->regs[19] = cpu->regs[20];
    goto L_a6eec;
L_a6ec0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6ec8ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a6eb8;
L_a6ecc:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = cpu->regs[1] + 3536ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa6eecULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11f220ULL);
L_a6eec:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a6f0c;
    cpu->regs[30] = PB_BASE + 0xa6f0cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a6f0c:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[3] = 25816ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xa6f60ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x122b00ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a6fa4;
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa6f78ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d3764ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a6f90;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_a6f98;
L_a6f90:
    cpu->regs[19] = cpu->regs[20];
    goto L_a6fc4;
L_a6f98:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa6fa0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a6f90;
L_a6fa4:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = cpu->regs[1] + 3584ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa6fc4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x11f220ULL);
L_a6fc4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a6fe4;
    cpu->regs[30] = PB_BASE + 0xa6fe4ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a6fe4:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP = SP - 48ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = SP + 4ULL;
    cpu->regs[3] = 26208ULL;
    cpu->regs[1] = cpu->regs[1] + cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0xa7038ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x122b00ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_a707c;
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (SP + 4));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa7050ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x1d3764ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a7068;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_a7070;
L_a7068:
    cpu->regs[19] = cpu->regs[20];
    goto L_a709c;
L_a7070:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa7078ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a7068;
L_a707c:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 8));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3368));
    cpu->regs[1] = cpu->regs[1] + 3632ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xa709cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x11f220ULL);
L_a709c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_a70bc;
    cpu->regs[30] = PB_BASE + 0xa70bcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x7c170ULL);
L_a70bc:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 48ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16)); PB_LDR(cpu->regs[2], (cpu->regs[19] + 16) + 8);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_a7100;
    cpu->regs[3] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[3]);
    if (FLAG_HS) goto L_a7114;
    goto L_a7110;
L_a7100:
    if (FLAG_LS) goto L_a7114;
    cpu->regs[3] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[0], cpu->regs[3]);
    if (FLAG_HS) goto L_a7114;
L_a7110:
    __builtin_trap();
L_a7114:
    cpu->regs[30] = PB_BASE + 0xa7118ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0xa7120ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x120dccULL);
    if ((cpu->regs[0])==0) goto L_a7168;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_NE) goto L_a7168;
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_a7144;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_a7144:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_a7158;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_a7160;
L_a7158:
    cpu->regs[0] = cpu->regs[19];
    goto L_a7168;
L_a7160:
    cpu->regs[30] = PB_BASE + 0xa7164ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_a7158;
L_a7168:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_a7174:
    SP = SP - 176ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRB(cpu->regs[0], (SP + 176));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[23]); PB_STR((SP + 80) + 8, cpu->regs[24]);
    cpu->regs[24] = cpu->regs[7];
    PB_STR((SP + 96), cpu->regs[25]); PB_STR((SP + 96) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[3];
    cpu->regs[26] = cpu->regs[4];
    PB_STR((SP + 112), cpu->regs[27]); PB_STR((SP + 112) + 8, cpu->regs[28]);
    cpu->regs[27] = cpu->regs[5];
    cpu->regs[28] = cpu->regs[6];
    PB_STRW((SP + 140), cpu->regs[0]);
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_EQ) goto L_a71f8;
    FLAG_CMP(cpu->regs[5], 0ULL);
    cpu->regs[23] = cpu->regs[5] + 8ULL;
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    cpu->regs[23] = (FLAG_NE) ? cpu->regs[23] : 0ULL;
    cpu->regs[22] = cpu->regs[7] + 8ULL;
    FLAG_CMP(cpu->regs[7], 0ULL);
    cpu->regs[22] = (FLAG_NE) ? cpu->regs[22] : 0ULL;
    cpu->regs[4] = cpu->regs[4] + 8ULL;
    cpu->regs[3] = cpu->regs[3] + 8ULL;
    cpu->regs[21] = 0ULL;
    PB_STR((SP + 152), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[6] + 8ULL;
    PB_STR((SP + 144), cpu->regs[0]);
    goto L_a72d0;
L_a71f8:
    cpu->regs[21] = 0ULL;
L_a71fc:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    PB_LDR(cpu->regs[3], (SP + 184)); PB_LDR(cpu->regs[4], (SP + 184) + 8);
    PB_LDRB(cpu->regs[2], (SP + 140));
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_GE) goto L_a72dc;
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[27])==0) goto L_a7228;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if (((cpu->regs[1] >> 63) & 1)) goto L_a7228;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_a7228:
    cpu->regs[1] = cpu->regs[20];
    if ((cpu->regs[24])==0) goto L_a7240;
    PB_LDR(cpu->regs[5], (cpu->regs[24] + 0));
    if (((cpu->regs[5] >> 63) & 1)) goto L_a7240;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[5];
L_a7240:
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    cpu->regs[30] = PB_BASE + 0xa7248ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x24f5d0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_a72f4;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[19] = cpu->regs[19] + cpu->regs[1];
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
    goto L_a71fc;
L_a7264:
    if ((cpu->regs[27])==0) goto L_a72e4;
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    if (((cpu->regs[1] >> 63) & 1)) goto L_a72e4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
L_a7278:
    if ((cpu->regs[24])==0) goto L_a72ec;
    PB_LDR(cpu->regs[2], (cpu->regs[24] + 0));
    if (((cpu->regs[2] >> 63) & 1)) goto L_a72ec;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
L_a728c:
    PB_LDRB(cpu->regs[2], (SP + 140));
    cpu->regs[7] = cpu->regs[22];
    PB_STRB((SP + 0), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (SP + 184)); PB_LDR(cpu->regs[5], (SP + 184) + 8);
    PB_STR((SP + 8), cpu->regs[2]); PB_STR((SP + 8) + 8, cpu->regs[5]);
    PB_LDR(cpu->regs[6], (SP + 144)); PB_LDR(cpu->regs[2], (SP + 144) + 8);
    cpu->regs[5] = cpu->regs[23];
    PB_STR((SP + 160), cpu->regs[3]); PB_STR((SP + 160) + 8, cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0xa72b0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xa7174ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_a72f4;
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    cpu->regs[21] = cpu->regs[21] + 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[28] + 0));
    cpu->regs[19] = cpu->regs[19] + cpu->regs[1];
    PB_LDR(cpu->regs[3], (SP + 160)); PB_LDR(cpu->regs[4], (SP + 160) + 8);
    cpu->regs[20] = cpu->regs[20] + cpu->regs[0];
L_a72d0:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GT) goto L_a7264;
L_a72dc:
    cpu->regs[0] = 1ULL;
    goto L_a72f4;
L_a72e4:
    cpu->regs[0] = cpu->regs[19];
    goto L_a7278;
L_a72ec:
    cpu->regs[1] = cpu->regs[20];
    goto L_a728c;
L_a72f4:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[23], (SP + 80)); PB_LDR(cpu->regs[24], (SP + 80) + 8);
    PB_LDR(cpu->regs[25], (SP + 96)); PB_LDR(cpu->regs[26], (SP + 96) + 8);
    PB_LDR(cpu->regs[27], (SP + 112)); PB_LDR(cpu->regs[28], (SP + 112) + 8);
    SP = SP + 176ULL;
    return;
L_a7314:
    cpu->regs[1] = cpu->regs[0];
    PB_LDRB(cpu->regs[0], (cpu->regs[0] + 64));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a73e0;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xa733cULL; PB_CALL(42, cpu, tlb, cpu->regs[3]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[3] = 1ULL;
    PB_STRB((cpu->regs[1] + 64), cpu->regs[3]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 200));
    if ((cpu->regs[0])==0) goto L_a7368;
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[2] = ((uint32_t)(cpu->regs[2] + 1ULL)); FLAG_CMP(cpu->regs[2], 0);
    if (FLAG_EQ) goto L_a7364;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[2]);
L_a7364:
    PB_STR((cpu->regs[1] + 56), cpu->regs[0]);
L_a7368:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 192));
    if ((cpu->regs[19])==0) goto L_a73c8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_a7380;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_a7380:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa7388ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x120dccULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_a73a8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_a73a8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xa73a8ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a73a8:
    if ((cpu->regs[20])==0) goto L_a73d0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_a73c8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_a73c8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xa73c8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_a73c8:
    cpu->regs[0] = 0ULL;
    goto L_a73d4;
L_a73d0:
    cpu->regs[0] = 1ULL;
L_a73d4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_a73e0:
    cpu->regs[0] = 0ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xa73fcULL; PB_CALL(46, cpu, tlb, PB_BASE + 0xa7314ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a7414;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(47, cpu, tlb, PB_BASE + 0x99d04ULL); return; };
L_a7414:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xa743cULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xa7314ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a7454;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(49, cpu, tlb, PB_BASE + 0x99dc4ULL); return; };
L_a7454:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0xa7478ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xa7314ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_a7490;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(51, cpu, tlb, PB_BASE + 0x99dc4ULL); return; };
L_a7490:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
