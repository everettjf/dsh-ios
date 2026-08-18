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

void ft__Py_GetConfigsAsDict(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[30] = PB_BASE + 0xb07bcULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[30] = PB_BASE + 0xb07c8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2456));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_b07f0;
    cpu->regs[30] = PB_BASE + 0xb07e4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_b0810;
    goto L_b1108;
L_b07f0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b0808;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_b0808:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
L_b0810:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 2616ULL;
    cpu->regs[30] = PB_BASE + 0xb0824ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0844;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0844;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0844ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0844:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2232));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0858ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2648ULL;
    cpu->regs[30] = PB_BASE + 0xb0874ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0894;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0894;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0894ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0894:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3176));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_b08b8;
    cpu->regs[30] = PB_BASE + 0xb08acULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdea4cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_b08d8;
    goto L_b1108;
L_b08b8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_b08d0;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_b08d0:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2760));
L_b08d8:
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[1] = cpu->regs[1] + 2680ULL;
    cpu->regs[30] = PB_BASE + 0xb08ecULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[22] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_b090c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b090c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb090cULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b090c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3872));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0920ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2720ULL;
    cpu->regs[30] = PB_BASE + 0xb093cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b095c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b095c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb095cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b095c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2608));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0970ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2760ULL;
    cpu->regs[30] = PB_BASE + 0xb098cULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b09ac;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b09ac;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb09acULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b09ac:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 4008));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb09c0ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2776ULL;
    cpu->regs[30] = PB_BASE + 0xb09dcULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b09fc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b09fc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb09fcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b09fc:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3944));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0a10ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2792ULL;
    cpu->regs[30] = PB_BASE + 0xb0a2cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0a4c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0a4c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0a4cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0a4c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3512));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0a60ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2808ULL;
    cpu->regs[30] = PB_BASE + 0xb0a7cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0a9c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0a9c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0a9cULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0a9c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3952));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0ab0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2824ULL;
    cpu->regs[30] = PB_BASE + 0xb0accULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0aec;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0aec;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0aecULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0aec:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3688));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0b00ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2848ULL;
    cpu->regs[30] = PB_BASE + 0xb0b1cULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0b3c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0b3c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0b3cULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0b3c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3272));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0b50ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2864ULL;
    cpu->regs[30] = PB_BASE + 0xb0b6cULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0b8c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0b8c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0b8cULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0b8c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2648));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0ba0ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2880ULL;
    cpu->regs[30] = PB_BASE + 0xb0bbcULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0bdc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0bdc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0bdcULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0bdc:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3384));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0bf0ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2896ULL;
    cpu->regs[30] = PB_BASE + 0xb0c0cULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0c2c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0c2c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0c2cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0c2c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2328));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0c40ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2920ULL;
    cpu->regs[30] = PB_BASE + 0xb0c5cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0c7c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0c7c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0c7cULL; PB_CALL(44, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0c7c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3128));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0c90ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2936ULL;
    cpu->regs[30] = PB_BASE + 0xb0cacULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0ccc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0ccc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0cccULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0ccc:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3696));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0ce0ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 2968ULL;
    cpu->regs[30] = PB_BASE + 0xb0cfcULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0d1c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0d1c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0d1cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0d1c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3712));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0d30ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3000ULL;
    cpu->regs[30] = PB_BASE + 0xb0d4cULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0d6c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0d6c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0d6cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0d6c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2752));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0d80ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3024ULL;
    cpu->regs[30] = PB_BASE + 0xb0d9cULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0dbc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0dbc;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0dbcULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0dbc:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3376));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0dd0ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3048ULL;
    cpu->regs[30] = PB_BASE + 0xb0decULL; PB_CALL(58, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0e0c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0e0c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0e0cULL; PB_CALL(59, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0e0c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3304));
    do { int32_t _s=0; tlb_read(tlb,cpu->regs[0],&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0e20ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3080ULL;
    cpu->regs[30] = PB_BASE + 0xb0e3cULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_b0e5c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0e5c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb0e5cULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b0e5c:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3208ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb0e74ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b110c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_b1124;
L_b0e80:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0xb0e94ULL; PB_CALL(64, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[20], (cpu->regs[23] + 96));
    cpu->regs[30] = PB_BASE + 0xb0ea4ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b1108;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 2936),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0eb4ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_b0edc;
L_b0ebc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b1108;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b1108;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb0ed8ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b1108;
L_b0edc:
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3592ULL;
    cpu->regs[30] = PB_BASE + 0xb0ef0ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b113c;
L_b0efc:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 2940),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[20] = cpu->regs[20] + 2936ULL;
    cpu->regs[30] = PB_BASE + 0xb0f0cULL; PB_CALL(69, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    cpu->regs[30] = PB_BASE + 0xb0f28ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b1154;
L_b0f34:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 8),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0f40ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3608ULL;
    cpu->regs[30] = PB_BASE + 0xb0f5cULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b116c;
L_b0f68:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 12),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0f74ULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3624ULL;
    cpu->regs[30] = PB_BASE + 0xb0f90ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b1184;
L_b0f9c:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 16),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0fa8ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3096ULL;
    cpu->regs[30] = PB_BASE + 0xb0fc4ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b119c;
L_b0fd0:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 20),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb0fdcULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3120ULL;
    cpu->regs[30] = PB_BASE + 0xb0ff8ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b11b4;
L_b1004:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 24),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb1010ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3136ULL;
    cpu->regs[30] = PB_BASE + 0xb102cULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b11cc;
L_b1038:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 28),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb1044ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3160ULL;
    cpu->regs[30] = PB_BASE + 0xb1060ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b11e4;
L_b106c:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 32),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb1078ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x28a000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3640ULL;
    cpu->regs[30] = PB_BASE + 0xb1094ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[24] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b11fc;
L_b10a0:
    if (((cpu->regs[24] >> 31) & 1)) goto L_b0ebc;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[20] + 36),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[30] = PB_BASE + 0xb10acULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xe2620ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_b0ebc;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3176ULL;
    cpu->regs[30] = PB_BASE + 0xb10c8ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[22] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (!((cpu->regs[1] >> 31) & 1)) goto L_b1214;
L_b10d4:
    if (((cpu->regs[22] >> 31) & 1)) goto L_b0ebc;
    cpu->regs[1] = PB_BASE + 0x2a4000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3192ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb10ecULL; PB_CALL(87, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b110c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_b122c;
L_b10f8:
    cpu->regs[0] = cpu->regs[23] + 1280ULL;
    cpu->regs[30] = PB_BASE + 0xb1100ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1add60ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_b1244;
L_b1108:
    cpu->regs[19] = 0ULL;
L_b110c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xb1114ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xb1120ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_b1278;
L_b1124:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b0e80;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb1138ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b0e80;
L_b113c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0efc;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb1150ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b0efc;
L_b1154:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0f34;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb1168ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b0f34;
L_b116c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0f68;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb1180ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b0f68;
L_b1184:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0f9c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb1198ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b0f9c;
L_b119c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b0fd0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb11b0ULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b0fd0;
L_b11b4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b1004;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb11c8ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b1004;
L_b11cc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b1038;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb11e0ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b1038;
L_b11e4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b106c;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb11f8ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b106c;
L_b11fc:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b10a0;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xb1210ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b10a0;
L_b1214:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_b10d4;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xb1228ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b10d4;
L_b122c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b10f8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb1240ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_b10f8;
L_b1244:
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 720ULL;
    cpu->regs[30] = PB_BASE + 0xb1258ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_b110c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_b1278;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_b1278;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xb1278ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_b1278:
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
}
