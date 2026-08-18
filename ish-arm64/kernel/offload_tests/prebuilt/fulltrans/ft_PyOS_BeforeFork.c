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

void ft_PyOS_BeforeFork(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[2] = cpu->tls_ptr;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x8474cULL; PB_CALL(1, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 3872));
    cpu->regs[30] = PB_BASE + 0x84764ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x84774ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0x1bdc90ULL); return; };
L_84774:
    if ((cpu->regs[0])==0) goto L_84848;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x8479cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x278de4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_847b8;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x1fa20cULL); return; };
L_847b8:
    if ((((uint32_t)(cpu->regs[21])))==0) goto L_847c0;
    cpu->regs[30] = PB_BASE + 0x847c0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x220364ULL);
L_847c0:
    cpu->regs[20] = 0ULL;
L_847c4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[20], cpu->regs[0]);
    if (FLAG_GE) goto L_84810;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + (cpu->regs[20] << 3)));
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x847e0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x179564ULL);
    if ((cpu->regs[0])!=0) goto L_847f0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x847ecULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_84808;
L_847f0:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_84808;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_84808;
    cpu->regs[30] = PB_BASE + 0x84808ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_84808:
    cpu->regs[20] = cpu->regs[20] + 1ULL;
    goto L_847c4;
L_84810:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_84838;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_84838;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_84838:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_84848:
    return;
    SP = SP - 240ULL;
    cpu->regs[1] = PB_BASE + 0x295000ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = cpu->regs[1] + 2904ULL;
    PB_STR((SP + 176), cpu->regs[29]); PB_STR((SP + 176) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 176ULL;
    PB_STR((SP + 192), cpu->regs[19]); PB_STR((SP + 192) + 8, cpu->regs[20]);
    PB_STR((SP + 208), cpu->regs[21]); PB_STR((SP + 208) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    PB_STR((SP + 224), cpu->regs[23]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 168), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[0] = cpu->regs[0] + 2344ULL;
    cpu->regs[30] = PB_BASE + 0x84890ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7beb0ULL);
    if ((cpu->regs[0])==0) goto L_8492c;
    cpu->regs[19] = SP + 8ULL;
    cpu->regs[1] = 1ULL;
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = 159ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x848b0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b840ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = PB_BASE + 0x299000ULL;
    cpu->regs[20] = cpu->regs[20] + 1688ULL;
    cpu->regs[21] = SP;
    PB_STRB((cpu->regs[19] + cpu->regs[1]), 0ULL);
    cpu->regs[30] = PB_BASE + 0x848ccULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x7b1c0ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = SP;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[19] = 19ULL;
    PB_STR((SP + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x848e4ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x7b310ULL);
L_848e4:
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[1] = (FLAG_NE) ? 1 : 0;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_84910;
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = 0ULL;
    cpu->regs[19] = ((uint32_t)(cpu->regs[19] - 1ULL));
    cpu->regs[30] = PB_BASE + 0x8490cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x7b310ULL);
    goto L_848e4;
L_84910:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(0ULL)));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_EQ) goto L_8492c;
    cpu->regs[30] = PB_BASE + 0x84920ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7bd80ULL);
    cpu->regs[19] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[0]));
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_GT) goto L_84a9c;
L_8492c:
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[2] = 59144ULL;
    cpu->regs[23] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[23], (cpu->regs[23] + 3080));
    cpu->regs[0] = cpu->regs[21] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x84948ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1d5800ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_84968;
    PB_LDR(cpu->regs[0], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_84aec;
    goto L_84b20;
L_84968:
    cpu->regs[1] = 34416ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x84974ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_849b0;
    cpu->regs[30] = PB_BASE + 0x84980ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_84b04;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_84b04;
    PB_LDR(cpu->regs[0], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_84b20;
    cpu->regs[0] = cpu->regs[19];
    goto L_84a14;
L_849b0:
    cpu->regs[0] = 35664ULL;
    cpu->regs[1] = cpu->regs[21] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x849c0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_84a2c;
    cpu->regs[30] = PB_BASE + 0x849ccULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_849e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_849e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x849e8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_849e8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_84b04;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_84b04;
    PB_LDR(cpu->regs[0], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_84b20;
    cpu->regs[0] = cpu->regs[20];
L_84a14:
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    PB_LDR(cpu->regs[23], (SP + 224));
    SP = SP + 240ULL;
    { PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_84a2c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_84a48;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_84a48;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x84a48ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_84a48:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x84a50ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x15bc60ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x84a5cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x15bc60ULL);
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x84a64ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x121fa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_84a80;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_84a80;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x84a80ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_84a80:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_84a9c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_84a9c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x84a9cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_84a9c:
    FLAG_CMP(cpu->regs[19], 1ULL);
    if (FLAG_LE) goto L_84b04;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3360));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x84ab4ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7ae40ULL);
    cpu->regs[1] = 1ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x2a0000ULL;
    cpu->regs[2] = cpu->regs[2] + 2360ULL;
    cpu->regs[30] = PB_BASE + 0x84ad0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x24d184ULL);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_84b20;
L_84aec:
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    PB_LDR(cpu->regs[23], (SP + 224));
    SP = SP + 240ULL;
    { PB_CALL(32, cpu, tlb, PB_BASE + 0x121fa0ULL); return; };
L_84b04:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_84b24;
L_84b20:
    cpu->regs[30] = PB_BASE + 0x84b24ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x7c170ULL);
L_84b24:
    PB_LDR(cpu->regs[23], (SP + 224));
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    SP = SP + 240ULL;
    return;
}
