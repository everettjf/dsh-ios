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

void ft__PyThreadState_DeleteExcept(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = 1ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[22], (cpu->regs[21] + 96));
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    cpu->regs[30] = PB_BASE + 0x1e9930ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 72));
    FLAG_CMP(cpu->regs[19], cpu->regs[20]);
    if (FLAG_NE) goto L_1e9940;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
L_1e9940:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if ((cpu->regs[0])!=0) goto L_1e9974;
L_1e9948:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    if ((cpu->regs[1])!=0) goto L_1e99b0;
L_1e9950:
    PB_STR((cpu->regs[19] + 0), 0ULL); PB_STR((cpu->regs[19] + 0) + 8, 0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 32));
    PB_STR((cpu->regs[21] + 72), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1e9960ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x17faa0ULL);
L_1e9960:
    if ((cpu->regs[20])!=0) goto L_1e9980;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e9974:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    PB_STR((cpu->regs[0] + 8), cpu->regs[1]);
    goto L_1e9948;
L_1e9980:
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e998cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1ef260ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[0] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 2336ULL;
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_EQ) goto L_1e99a8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e99a8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xd7784ULL);
L_1e99a8:
    cpu->regs[20] = cpu->regs[19];
    goto L_1e9960;
L_1e99b0:
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_1e9950;
    /* nop */
    /* nop */
    SP = SP - 80ULL;
    cpu->regs[5] = 57888ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = SP + 8ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 24), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[5];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9a04ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1e3100ULL);
    PB_LDR(cpu->regs[19], (SP + 8));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e9b1c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1e9a58;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e9a2cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1e9b50ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9a58;
    cpu->regs[4] = 44840ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[4];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1e9a4cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1e9b1c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1e9b04;
L_1e9a58:
    cpu->regs[22] = 0ULL;
L_1e9a5c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e9a64ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[2] = 57792ULL;
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1e9a74ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e3100ULL);
    PB_LDR(cpu->regs[19], (SP + 8));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e9b2c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[19], cpu->regs[0]); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1e9ac8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e9a9cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1e9b50ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9ac8;
    cpu->regs[0] = 44840ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1e9abcULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1e9b2c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1e9b3c;
L_1e9ac8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e9ad0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e9b38;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[22];
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    SP = SP + 80ULL;
    return;
L_1e9b04:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1e9a58;
    cpu->regs[22] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e9b18ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e9a5c;
L_1e9b1c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[22] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1e9b28ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1e9a5c;
L_1e9b2c:
    cpu->regs[22] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x1e9b34ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1e9ac8;
L_1e9b38:
    cpu->regs[30] = PB_BASE + 0x1e9b3cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e9b3c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e9ac8;
    cpu->regs[30] = PB_BASE + 0x1e9b4cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e9ac8;
L_1e9b50:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[1] + 712ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1e9b64ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11d200ULL);
    if ((cpu->regs[0])==0) goto L_1e9b98;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1e9b74ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1e9bac;
L_1e9b80:
    if (((cpu->regs[20] >> 31) & 1)) goto L_1e9ba4;
L_1e9b84:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = (FLAG_GT) ? 1 : 0;
L_1e9b90:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e9b98:
    cpu->regs[30] = PB_BASE + 0x1e9b9cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x121fa0ULL);
    cpu->regs[0] = 0ULL;
    goto L_1e9b90;
L_1e9ba4:
    cpu->regs[30] = PB_BASE + 0x1e9ba8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1e9b84;
L_1e9bac:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e9b80;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e9bc0ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e9b80;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_1e9c04;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 8));
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2280));
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_NE) goto L_1e9c04;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 2ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1e9bf4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11ebb0ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    cpu->regs[0] = (FLAG_EQ) ? 1 : 0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_1e9c04:
    cpu->regs[0] = 0ULL;
    return;
}
