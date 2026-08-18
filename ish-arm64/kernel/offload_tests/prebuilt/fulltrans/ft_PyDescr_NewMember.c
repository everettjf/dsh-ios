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

void ft_PyDescr_NewMember(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[0];
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 24));
    if (((cpu->regs[0] >> 3) & 1)) goto L_18d380;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 0));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2552));
    cpu->regs[30] = PB_BASE + 0x18d36cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xde700ULL);
    if ((cpu->regs[0])==0) goto L_18d374;
    PB_STR((cpu->regs[0] + 40), cpu->regs[19]);
L_18d374:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_18d380:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2936));
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[1] = cpu->regs[1] + 1728ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x18d398ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_18d374;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x18d3c0ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe1564ULL);
    if ((cpu->regs[0])==0) goto L_18d4b8;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18d3d4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe1700ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18d4cc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x18d3e4ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1a08ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18d43c;
L_18d3ec:
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18d3fcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xddf30ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_18d414;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_18d4c0;
L_18d414:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_18d428;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_18d4fc;
L_18d428:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_18d43c:
    cpu->regs[30] = PB_BASE + 0x18d440ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18d490;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 168));
    if (((cpu->regs[0] >> 1) & 1)) goto L_18d458;
    PB_STR((cpu->regs[21] + 360), cpu->regs[1]);
    goto L_18d3ec;
L_18d458:
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x18d46cULL; PB_CALL(8, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[21] + 360));
    cpu->regs[4] = 40ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 16));
    cpu->regs[0] = cpu->regs[0] * cpu->regs[4] + cpu->regs[2];
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_STR((cpu->regs[0] + 13280), cpu->regs[1]);
    goto L_18d3ec;
L_18d490:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18d4a4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18d4f0;
L_18d4a4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18d4b8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_18d508;
L_18d4b8:
    cpu->regs[21] = 4294967295ULL;
    goto L_18d428;
L_18d4c0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x18d4c8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18d414;
L_18d4cc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_18d4b8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_18d4b8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x18d4ecULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18d428;
L_18d4f0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18d4f8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18d4a4;
L_18d4fc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x18d504ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18d428;
L_18d508:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[21] = 4294967295ULL;
    cpu->regs[30] = PB_BASE + 0x18d514ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_18d428;
    /* nop */
    /* nop */
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 168));
    if (((cpu->regs[2] >> 31) & 1)) goto L_18d53c;
L_18d530:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 208));
    cpu->regs[0] = cpu->regs[1] + cpu->regs[0];
    return;
L_18d53c:
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 168));
    if (!((cpu->regs[2] >> 1) & 1)) goto L_18d530;
    cpu->regs[2] = cpu->tls_ptr;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x18d560ULL; PB_CALL(14, cpu, tlb, cpu->regs[3]);
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[2] = 46016ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 360));
    cpu->regs[3] = 40ULL;
    cpu->regs[2] = (cpu->regs[2] & ~(0xffffULL << 16)) | ((0x5ULL & 0xffff) << 16);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[1] * cpu->regs[3] + cpu->regs[2];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    return;
    PB_STR((cpu->regs[1] + 0), 0ULL);
    PB_STR((cpu->regs[2] + 0), 0ULL);
    if ((cpu->regs[0])==0) goto L_18d5c4;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 24));
    if ((cpu->regs[3])!=0) goto L_18d5c4;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3288));
    FLAG_CMP(cpu->regs[4], cpu->regs[3]);
    if (FLAG_NE) goto L_18d5c8;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 48));
    if ((cpu->regs[0])==0) goto L_18d5c4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_18d5c8;
L_18d5c4:
    return;
L_18d5c8:
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 8));
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3632));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 4056));
    FLAG_CMP(cpu->regs[4], cpu->regs[3]);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[4], cpu->regs[1]); } else { FLAG_CMP(0, 0); }
    if (FLAG_NE) goto L_18d5c4;
    PB_STR((cpu->regs[2] + 0), cpu->regs[0]);
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3288));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x18d614ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_18d648;
    PB_STR((cpu->regs[0] + 40), 0ULL); PB_STR((cpu->regs[0] + 40) + 8, 0ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    PB_STR((cpu->regs[19] + 16), cpu->regs[21]);
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    if ((cpu->regs[20])!=0) goto L_18d65c;
L_18d630:
    cpu->regs[1] = PB_BASE + 0x1bf000ULL;
    cpu->regs[1] = cpu->regs[1] + 96ULL;
    PB_STR((cpu->regs[19] + 24), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[19];
    PB_STR((cpu->regs[19] + 56), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x18d648ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1984ULL);
L_18d648:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_18d65c:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_18d630;
    PB_STRW((cpu->regs[20] + 0), cpu->regs[0]);
    goto L_18d630;
}
