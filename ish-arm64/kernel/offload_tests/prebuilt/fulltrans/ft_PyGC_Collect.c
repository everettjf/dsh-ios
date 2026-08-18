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

void ft_PyGC_Collect(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1e9c28ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[20], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[19], (cpu->regs[20] + 16));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 124));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e9c94;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 312));
    cpu->regs[19] = cpu->regs[19] + 112ULL;
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9c94;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 96));
    PB_STRW((cpu->regs[19] + 200), cpu->regs[0]);
    PB_STR((cpu->regs[20] + 96), 0ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1e9c68ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x196c00ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 96));
    PB_STR((cpu->regs[20] + 96), cpu->regs[21]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1e9c7cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STRW((cpu->regs[19] + 200), 0ULL);
L_1e9c84:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e9c94:
    cpu->regs[20] = 0ULL;
    goto L_1e9c84;
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_1e9cd0;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1e9cccULL; PB_CALL(4, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9d30;
L_1e9cd0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])!=0) goto L_1e9d90;
L_1e9cd8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])!=0) goto L_1e9d80;
L_1e9ce0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])!=0) goto L_1e9d70;
L_1e9ce8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])!=0) goto L_1e9d60;
L_1e9cf0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])!=0) goto L_1e9d50;
L_1e9cf8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    if ((cpu->regs[0])!=0) goto L_1e9d40;
L_1e9d00:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 128));
    if ((cpu->regs[0])!=0) goto L_1e9d24;
L_1e9d08:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x1de120ULL); return; };
L_1e9d24:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9d2cULL; PB_CALL(6, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e9d08;
L_1e9d30:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1e9d40:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9d48ULL; PB_CALL(7, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e9d00;
    goto L_1e9d30;
L_1e9d50:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9d58ULL; PB_CALL(8, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e9cf8;
    goto L_1e9d30;
L_1e9d60:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9d68ULL; PB_CALL(9, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e9cf0;
    goto L_1e9d30;
L_1e9d70:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9d78ULL; PB_CALL(10, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e9ce8;
    goto L_1e9d30;
L_1e9d80:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9d88ULL; PB_CALL(11, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e9ce0;
    goto L_1e9d30;
L_1e9d90:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e9d98ULL; PB_CALL(12, cpu, tlb, cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e9cd8;
    goto L_1e9d30;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0] + (66ULL << 12);
    cpu->regs[19] = cpu->regs[20] + 384ULL;
    goto L_1e9dc4;
L_1e9db8:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STRW((cpu->regs[19] + 1296), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1e9dc4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe1dc0ULL);
L_1e9dc4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 1296));
    cpu->regs[2] = ((uint32_t)(cpu->regs[1] - 1ULL));
    cpu->regs[0] = cpu->regs[19] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[2])) << 3);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1e9db8;
    cpu->regs[20] = cpu->regs[20] + 384ULL;
    goto L_1e9de8;
L_1e9ddc:
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 656));
    PB_STRW((cpu->regs[20] + 1300), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1e9de8ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdfce0ULL);
L_1e9de8:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 1300));
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] - 1ULL));
    cpu->regs[2] = cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[1])) << 3);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9ddc;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0] + (66ULL << 12);
    cpu->regs[19] = cpu->regs[19] + 2048ULL;
    cpu->regs[20] = cpu->regs[19] - 296ULL;
L_1e9e1c:
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 640));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9e3c;
    cpu->regs[19] = cpu->regs[19] - 296ULL;
L_1e9e28:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 1288));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9e50;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e9e3c:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[20] + 640), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3)));
    cpu->regs[30] = PB_BASE + 0x1e9e4cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    goto L_1e9e1c;
L_1e9e50:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 1288), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19] + (((uint64_t)(int64_t)(int32_t)(cpu->regs[0])) << 3);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 648));
    cpu->regs[30] = PB_BASE + 0x1e9e64ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    goto L_1e9e28;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0] + (66ULL << 12);
    cpu->regs[19] = cpu->regs[19] + 3072ULL;
L_1e9e7c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + -16));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9e90;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e9e90:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_STR((cpu->regs[19] + -24), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 32), 0ULL);
    cpu->regs[30] = PB_BASE + 0x1e9ea4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xe1dc0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + -16));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + -16), cpu->regs[0]);
    goto L_1e9e7c;
    /* nop */
    /* nop */
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1e9f18;
L_1e9ee8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1e9f40;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e9efcULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1a1380ULL);
    if ((cpu->regs[0])==0) goto L_1e9f20;
L_1e9f00:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1e9f08:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e9f18:
    cpu->regs[30] = PB_BASE + 0x1e9f1cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1e9ee8;
L_1e9f20:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1e9f00;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1e9f34ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x118420ULL);
    if ((cpu->regs[0])!=0) goto L_1e9f00;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_1e9f00;
L_1e9f40:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1e9f08;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[1] = cpu->regs[1] + 3584ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[20], (cpu->regs[0] + 1488));
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e9f74ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1e9fc0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e9f9c;
L_1e9f78:
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3608ULL;
    cpu->regs[30] = PB_BASE + 0x1e9f8cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1e9fc0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e9fa8;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e9f9c:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e9fa4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1e9f78;
L_1e9fa8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(24, cpu, tlb, PB_BASE + 0x1fa20cULL); return; };
    /* nop */
    /* nop */
L_1e9fc0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[19] = cpu->regs[1];
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_1e9ffc;
L_1e9fd8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 352));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[30] = PB_BASE + 0x1e9fecULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    cpu->regs[0] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[0] >> 31)));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1e9ffc:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 720ULL;
    cpu->regs[30] = PB_BASE + 0x1ea008ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xa8500ULL);
    goto L_1e9fd8;
    SP = SP - 176ULL;
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_STR((SP + 128), cpu->regs[23]); PB_STR((SP + 128) + 8, cpu->regs[24]);
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    PB_STR((SP + 24), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[21], (cpu->regs[23] + 944));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((SP + 72), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    if ((cpu->regs[21])==0) goto L_1ea4f8;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
    PB_LDRW(cpu->regs[22], (cpu->regs[23] + 1488));
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_1ea65c;
L_1ea054:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 360));
    cpu->regs[1] = PB_BASE + 0x2b1000ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    cpu->regs[1] = cpu->regs[1] + 3368ULL;
    cpu->regs[30] = PB_BASE + 0x1ea06cULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea6c8;
L_1ea070:
    cpu->regs[20] = PB_BASE + 0x3db000ULL;
    cpu->regs[19] = cpu->regs[20] + 2816ULL;
    cpu->regs[19] = cpu->regs[19] + 352ULL;
L_1ea07c:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if ((cpu->regs[1])==0) goto L_1ea0a0;
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x1ea090ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1e9fc0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1ea6b8;
    cpu->regs[19] = cpu->regs[19] + 8ULL;
    goto L_1ea07c;
L_1ea0a0:
    cpu->regs[19] = cpu->regs[20] + 2816ULL;
    cpu->regs[19] = cpu->regs[19] + 448ULL;
L_1ea0a8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((SP + 16), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1ea0e8;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_1ea6a4;
L_1ea0bc:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 352));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ea0c8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xedfe0ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea680;
L_1ea0d0:
    PB_LDR(cpu->regs[1], (SP + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 352));
    cpu->regs[30] = PB_BASE + 0x1ea0dcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea75c;
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    goto L_1ea0a8;
L_1ea0e8:
    cpu->regs[30] = PB_BASE + 0x1ea0ecULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea754;
L_1ea0f4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2680));
    PB_STR((SP + 32), cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1ea714;
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[26] = SP + 64ULL;
    cpu->regs[25] = SP + 56ULL;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 3536));
    cpu->regs[24] = SP + 48ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((SP + 8), cpu->regs[0]);
    PB_STR((SP + 48), 0ULL);
L_1ea134:
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ea148ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0xecfc8ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ea2bc;
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[1] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1ea158ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ea134;
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_1ea6f4;
L_1ea160:
    if ((cpu->regs[20])==0) goto L_1ea1bc;
    PB_LDR(cpu->regs[0], (SP + 64));
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea170ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xe1700ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea6ec;
    PB_LDR(cpu->regs[1], (SP + 56));
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1ea188ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[28] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea6e0;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ea19cULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xe548cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea6e0;
L_1ea1a0:
    cpu->regs[0] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1ea1a8ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea1bc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1ea6d4;
L_1ea1bc:
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (SP + 56));
    cpu->regs[30] = PB_BASE + 0x1ea1ccULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe97e4ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1ea134;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea1d8ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea134;
L_1ea1dc:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ea1e8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea76c;
    cpu->regs[1] = cpu->regs[28];
    cpu->regs[30] = PB_BASE + 0x1ea1f8ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ea250;
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_1ea218;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1ea218;
    PB_LDR(cpu->regs[0], (SP + 40));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ea218ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xabed8ULL);
L_1ea218:
    if ((cpu->regs[20])==0) goto L_1ea234;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea228ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xe1700ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ea784;
    cpu->regs[30] = PB_BASE + 0x1ea234ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1fa20cULL);
L_1ea234:
    PB_LDR(cpu->regs[2], (SP + 8));
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ea244ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe97e4ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1ea250;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea250ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x1fa20cULL);
L_1ea250:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea26c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ea26c;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x1ea26cULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ea26c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea288;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ea288;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ea288ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ea288:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1ea290ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0xe8060ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_1ea1dc;
    cpu->regs[30] = PB_BASE + 0x1ea29cULL; PB_CALL(50, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1ea2a8;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea2a8ULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x1fa20cULL);
L_1ea2a8:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea2bc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1ea774;
L_1ea2bc:
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
L_1ea2c0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (SP + 32));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_1ea5cc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ea2d8ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0x1c17e0ULL);
L_1ea2d8:
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 360));
    cpu->regs[30] = PB_BASE + 0x1ea2e8ULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x18fc80ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea5c4;
L_1ea2f0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 360));
    cpu->regs[30] = PB_BASE + 0x1ea2f8ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0x1c17e0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 360));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 1736));
    cpu->regs[30] = PB_BASE + 0x1ea304ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x1904c0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ea5ac;
L_1ea308:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ea310ULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (SP + 24));
    cpu->regs[19] = cpu->regs[23] + 112ULL;
    cpu->regs[30] = PB_BASE + 0x1ea31cULL; PB_CALL(57, cpu, tlb, PB_BASE + 0x1eac2cULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 16));
    if (((cpu->regs[1] >> 5) & 1)) goto L_1ea338;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 208));
    if ((cpu->regs[0])==0) goto L_1ea338;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[6], 0ULL);
    if (FLAG_GT) goto L_1ea530;
L_1ea338:
    if ((cpu->regs[20])==0) goto L_1ea398;
    PB_LDR(cpu->regs[21], (cpu->regs[20] + 16));
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2760));
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    if (((cpu->regs[21] >> 63) & 1)) goto L_1ea37c;
L_1ea350:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + (cpu->regs[21] << 3)));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_LE) goto L_1ea374;
    FLAG_CMP(cpu->regs[19], cpu->regs[24]);
    if (FLAG_NE) goto L_1ea428;
L_1ea374:
    cpu->regs[21] = cpu->regs[21] - 1ULL;
L_1ea378:
    if (!((cpu->regs[21] >> 63) & 1)) goto L_1ea350;
L_1ea37c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea398;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ea398;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ea398ULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ea398:
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_1ea618;
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 352));
    cpu->regs[30] = PB_BASE + 0x1ea3a4ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x1eb360ULL);
L_1ea3a4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 360));
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea3b0ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0x1eb360ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 952));
    if ((cpu->regs[0])==0) goto L_1ea49c;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 3536));
    goto L_1ea3cc;
L_1ea3c4:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 952));
    cpu->regs[19] = cpu->regs[19] + 1ULL;
L_1ea3cc:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[19], cpu->regs[2]);
    if (FLAG_GE) goto L_1ea48c;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[1] = cpu->regs[20];
    PB_LDR(cpu->regs[5], (cpu->regs[0] + (cpu->regs[19] << 3)));
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1ea3ecULL; PB_CALL(61, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1ea3c4;
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1ea3f8ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0x190cccULL);
    if ((cpu->regs[0])==0) goto L_1ea3c4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    if ((cpu->regs[1])==0) goto L_1ea3c4;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((cpu->regs[0] + 32), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_1ea3c4;
    cpu->regs[0] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ea3c4;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1ea424ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea3c4;
L_1ea428:
    PB_LDR(cpu->regs[25], (cpu->regs[0] + 24));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ea434ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x18fc40ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 360));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1ea374;
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 352));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_EQ) goto L_1ea374;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_1ea45c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_1ea45c:
    if ((((uint32_t)(cpu->regs[22])))!=0) goto L_1ea63c;
L_1ea460:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ea468ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x1eb350ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea374;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ea374;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    cpu->regs[30] = PB_BASE + 0x1ea488ULL; PB_CALL(66, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea378;
L_1ea48c:
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea498ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0x1ac20cULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ea524;
L_1ea49c:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 944));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[23] + 944), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ea4bc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ea4bc;
    cpu->regs[30] = PB_BASE + 0x1ea4bcULL; PB_CALL(68, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1ea4bc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1ea51c;
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[25], (SP + 144)); PB_LDR(cpu->regs[26], (SP + 144) + 8);
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    PB_LDR(cpu->regs[0], (SP + 24));
    SP = SP + 176ULL;
    goto L_1eac2c;
L_1ea4f8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_1ea66c;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    PB_STR((SP + 144), cpu->regs[25]); PB_STR((SP + 144) + 8, cpu->regs[26]);
L_1ea51c:
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[30] = PB_BASE + 0x1ea524ULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1ea524:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 952));
    cpu->regs[30] = PB_BASE + 0x1ea52cULL; PB_CALL(70, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea49c;
L_1ea530:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3896));
    FLAG_CMP((cpu->regs[1]) & (4ULL), 0);
    cpu->regs[5] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = PB_BASE + 0x294000ULL;
    cpu->regs[5] = cpu->regs[5] + 784ULL;
    cpu->regs[1] = cpu->regs[1] + 736ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[3] = PB_BASE + 0x294000ULL;
    cpu->regs[3] = cpu->regs[3] + 968ULL;
    cpu->regs[5] = (FLAG_EQ) ? cpu->regs[5] : cpu->regs[1];
    cpu->regs[4] = 0ULL;
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea56cULL; PB_CALL(71, cpu, tlb, PB_BASE + 0xca768ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1ea5b8;
L_1ea570:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 16));
    if (!((cpu->regs[0] >> 2) & 1)) goto L_1ea338;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 208));
    cpu->regs[30] = PB_BASE + 0x1ea580ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x14d650ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea5fc;
    cpu->regs[30] = PB_BASE + 0x1ea58cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0x1c85e0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea5fc;
    cpu->regs[1] = cpu->regs[21] + 32ULL;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 976ULL;
    cpu->regs[30] = PB_BASE + 0x1ea5a4ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0xa8500ULL);
    PB_STR((SP + 16), cpu->regs[21]);
    goto L_1ea604;
L_1ea5ac:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea5b4ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea308;
L_1ea5b8:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea5c0ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea570;
L_1ea5c4:
    cpu->regs[30] = PB_BASE + 0x1ea5c8ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea2f0;
L_1ea5cc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 39280ULL;
    cpu->regs[1] = SP + 64ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 64), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1ea5f0ULL; PB_CALL(78, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])!=0) goto L_1ea2d8;
    cpu->regs[30] = PB_BASE + 0x1ea5f8ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea2d8;
L_1ea5fc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 208));
    cpu->regs[30] = PB_BASE + 0x1ea604ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x1fa20cULL);
L_1ea604:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1ea60cULL; PB_CALL(81, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[30] = PB_BASE + 0x1ea614ULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x18d760ULL);
    goto L_1ea338;
L_1ea618:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1016ULL;
    cpu->regs[30] = PB_BASE + 0x1ea624ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xabed8ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 352));
    cpu->regs[30] = PB_BASE + 0x1ea62cULL; PB_CALL(84, cpu, tlb, PB_BASE + 0x1eb360ULL);
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1048ULL;
    cpu->regs[30] = PB_BASE + 0x1ea638ULL; PB_CALL(85, cpu, tlb, PB_BASE + 0xabed8ULL);
    goto L_1ea3a4;
L_1ea63c:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1ea460;
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 992ULL;
    cpu->regs[30] = PB_BASE + 0x1ea658ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0xabed8ULL);
    goto L_1ea460;
L_1ea65c:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 888ULL;
    cpu->regs[30] = PB_BASE + 0x1ea668ULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xa8500ULL);
    goto L_1ea054;
L_1ea66c:
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    PB_LDR(cpu->regs[23], (SP + 128)); PB_LDR(cpu->regs[24], (SP + 128) + 8);
    SP = SP + 176ULL;
    return;
L_1ea680:
    PB_LDR(cpu->regs[1], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 96));
    if ((cpu->regs[1])==0) goto L_1ea698;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    if ((cpu->regs[1])==0) goto L_1ea698;
    cpu->regs[30] = PB_BASE + 0x1ea698ULL; PB_CALL(88, cpu, tlb, PB_BASE + 0x1fa20cULL);
L_1ea698:
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    goto L_1ea0d0;
L_1ea6a4:
    PB_LDR(cpu->regs[1], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 912ULL;
    cpu->regs[30] = PB_BASE + 0x1ea6b4ULL; PB_CALL(89, cpu, tlb, PB_BASE + 0xa8500ULL);
    goto L_1ea0bc;
L_1ea6b8:
    cpu->regs[0] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 8ULL;
    cpu->regs[30] = PB_BASE + 0x1ea6c4ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea07c;
L_1ea6c8:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea6d0ULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea070;
L_1ea6d4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ea6dcULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea1bc;
L_1ea6e0:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea6e8ULL; PB_CALL(93, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea1a0;
L_1ea6ec:
    cpu->regs[30] = PB_BASE + 0x1ea6f0ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea1bc;
L_1ea6f4:
    PB_LDR(cpu->regs[1], (SP + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_1ea160;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 936ULL;
    cpu->regs[30] = PB_BASE + 0x1ea710ULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xabed8ULL);
    goto L_1ea160;
L_1ea714:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1ea71cULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xe7e88ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea74c;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 936ULL;
    PB_STR((SP + 40), cpu->regs[0]);
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    PB_STR((SP + 8), cpu->regs[0]);
    PB_STR((SP + 160), cpu->regs[27]); PB_STR((SP + 160) + 8, cpu->regs[28]);
    cpu->regs[28] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[28], (cpu->regs[28] + 3536));
    goto L_1ea288;
L_1ea74c:
    cpu->regs[30] = PB_BASE + 0x1ea750ULL; PB_CALL(97, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea2c0;
L_1ea754:
    cpu->regs[30] = PB_BASE + 0x1ea758ULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea0f4;
L_1ea75c:
    cpu->regs[0] = 0ULL;
    cpu->regs[19] = cpu->regs[19] + 16ULL;
    cpu->regs[30] = PB_BASE + 0x1ea768ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea0a8;
L_1ea76c:
    cpu->regs[30] = PB_BASE + 0x1ea770ULL; PB_CALL(100, cpu, tlb, PB_BASE + 0x1fa20cULL);
    goto L_1ea288;
L_1ea774:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x1ea77cULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[27], (SP + 160)); PB_LDR(cpu->regs[28], (SP + 160) + 8);
    goto L_1ea2c0;
L_1ea784:
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = 2ULL;
    cpu->regs[30] = PB_BASE + 0x1ea794ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xe1204ULL);
    cpu->regs[27] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1ea7ac;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1ea7a8ULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xe548cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1ea7b4;
L_1ea7ac:
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ea7b4ULL; PB_CALL(104, cpu, tlb, PB_BASE + 0x1fa20cULL);
L_1ea7b4:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x1ea7bcULL; PB_CALL(105, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1ea234;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1ea234;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x1ea7d8ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea234;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1ea7f4ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[30] = PB_BASE + 0x1ea7f8ULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x1ea820ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
    /* nop */
    /* nop */
L_1ea820:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 72));
    if ((cpu->regs[0])==0) goto L_1ea850;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ea850;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ea908;
L_1ea850:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 80));
    if ((cpu->regs[0])==0) goto L_1ea864;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 80), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1ea8f4;
L_1ea864:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])==0) goto L_1ea878;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 88), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1ea974;
L_1ea878:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    if ((cpu->regs[0])==0) goto L_1ea88c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1ea94c;
L_1ea88c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 104));
    if ((cpu->regs[0])==0) goto L_1ea8a0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 104), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1ea960;
L_1ea8a0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])==0) goto L_1ea8b4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 112), 0ULL);
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1ea938;
L_1ea8b4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    if ((cpu->regs[0])==0) goto L_1ea8d4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 120), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ea8d4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1ea930;
L_1ea8d4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 128));
    if ((cpu->regs[0])!=0) goto L_1ea910;
L_1ea8dc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1ea8e4ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xe2500ULL);
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1ea8f4:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ea864;
    cpu->regs[30] = PB_BASE + 0x1ea904ULL; PB_CALL(110, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea864;
L_1ea908:
    cpu->regs[30] = PB_BASE + 0x1ea90cULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea850;
L_1ea910:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 128), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1ea8dc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ea8dc;
    cpu->regs[30] = PB_BASE + 0x1ea92cULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea8dc;
L_1ea930:
    cpu->regs[30] = PB_BASE + 0x1ea934ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea8d4;
L_1ea938:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ea8b4;
    cpu->regs[30] = PB_BASE + 0x1ea948ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea8b4;
L_1ea94c:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ea88c;
    cpu->regs[30] = PB_BASE + 0x1ea95cULL; PB_CALL(115, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea88c;
L_1ea960:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ea8a0;
    cpu->regs[30] = PB_BASE + 0x1ea970ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea8a0;
L_1ea974:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1ea878;
    cpu->regs[30] = PB_BASE + 0x1ea984ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1ea878;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1ea99cULL; PB_CALL(118, cpu, tlb, PB_BASE + 0x1915a0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    PB_LDRW(cpu->regs[4], (cpu->regs[1] + 208));
    cpu->regs[30] = PB_BASE + 0x1ea9acULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xdcd00ULL);
    if ((((uint32_t)(cpu->regs[4])))!=0) goto L_1eaa30;
L_1ea9b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    if ((cpu->regs[0])!=0) goto L_1eaa24;
L_1ea9b8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])!=0) goto L_1ea9f4;
L_1ea9c0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x1ea9c8ULL; PB_CALL(120, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 48));
    cpu->regs[30] = PB_BASE + 0x1ea9d0ULL; PB_CALL(121, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])!=0) goto L_1eaa1c;
L_1ea9d8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_1ea9f4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 96));
    if ((cpu->regs[1])==0) goto L_1ea9c0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1eaa10;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_1ea9c0;
L_1eaa10:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eaa18ULL; PB_CALL(122, cpu, tlb, cpu->regs[1]);
    goto L_1ea9c0;
L_1eaa1c:
    cpu->regs[30] = PB_BASE + 0x1eaa20ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    goto L_1ea9d8;
L_1eaa24:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eaa2cULL; PB_CALL(124, cpu, tlb, PB_BASE + 0x13f6ecULL);
    goto L_1ea9b8;
L_1eaa30:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 48));
    if ((cpu->regs[1])==0) goto L_1ea9b0;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1080ULL;
    cpu->regs[30] = PB_BASE + 0x1eaa44ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xabed8ULL);
    goto L_1ea9b0;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[24] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[24], (cpu->regs[24] + 2248));
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[3];
    PB_STRW((cpu->regs[24] + 1536), 0ULL);
    if ((cpu->regs[2])==0) goto L_1eaa94;
    cpu->regs[20] = PB_BASE + 0x28a000ULL;
    cpu->regs[20] = cpu->regs[20] + 1920ULL;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x1eaa90ULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xedfe0ULL);
    if ((cpu->regs[0])==0) goto L_1eaae4;
L_1eaa94:
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1eaaa4ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x1964c0ULL);
    if ((cpu->regs[0])==0) goto L_1eaabc;
L_1eaaa8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1eaabc:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])==0) goto L_1eaac8;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
L_1eaac8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3440));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_1eab0c;
L_1eaadc:
    cpu->regs[0] = 0ULL;
    goto L_1eaaa8;
L_1eaae4:
    cpu->regs[30] = PB_BASE + 0x1eaae8ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1eaadc;
    PB_LDR(cpu->regs[2], (cpu->regs[23] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 360));
    cpu->regs[30] = PB_BASE + 0x1eab00ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x18eaf0ULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1eaa94;
    cpu->regs[0] = 0ULL;
    goto L_1eaaa8;
L_1eab0c:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[24] + 1536), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    goto L_1eaaa8;
    /* nop */
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[2];
    cpu->regs[20] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 1ULL);
    if (FLAG_HI) goto L_1eab68;
L_1eab3c:
    FLAG_CMP(cpu->regs[19], 0ULL);
    if (FLAG_LE) goto L_1eab88;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
L_1eab48:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3448));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1eab58ULL; PB_CALL(130, cpu, tlb, PB_BASE + 0x1d2ec0ULL);
L_1eab58:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1eab68:
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[0] + 1096ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1eab80ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1eab3c;
    goto L_1eab58;
L_1eab88:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    goto L_1eab48;
    /* nop */
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 16));
    cpu->regs[30] = PB_BASE + 0x1eabc0ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0x137bd0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1eabf4;
    if ((cpu->regs[21])==0) goto L_1eabf0;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 72));
    FLAG_CMP(cpu->regs[21], 1ULL);
    if (FLAG_NE) goto L_1eac0c;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_NE) goto L_1eac04;
L_1eabe8:
    PB_STR((cpu->regs[20] + 72), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x1eabf0ULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x18d760ULL);
L_1eabf0:
    cpu->regs[0] = 0ULL;
L_1eabf4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1eac04:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
    goto L_1eabe8;
L_1eac0c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_1eac1c;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[1]);
L_1eac1c:
    PB_STR((cpu->regs[20] + 72), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1eac24ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = 0ULL;
    goto L_1eabf4;
L_1eac2c:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 16));
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 312));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1eac64;
    cpu->regs[19] = cpu->regs[19] + 112ULL;
    cpu->regs[4] = 1ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 2ULL;
    PB_STRW((cpu->regs[19] + 200), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x1eac60ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0x106540ULL);
    PB_STRW((cpu->regs[19] + 200), 0ULL);
L_1eac64:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_1eacbc;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 88));
    if ((cpu->regs[1])==0) goto L_1eacbc;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_1eaca4;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])==0) goto L_1eacbc;
L_1eaca4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eacacULL; PB_CALL(136, cpu, tlb, cpu->regs[1]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1eacb4ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_1eacf4;
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_1eace4;
L_1eacbc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    if ((cpu->regs[0])==0) goto L_1eace0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 16), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eace0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1eace0;
    cpu->regs[30] = PB_BASE + 0x1eace0ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_1eace0:
    cpu->regs[20] = 0ULL;
L_1eace4:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1eacf4:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 48));
    if ((cpu->regs[2])==0) goto L_1ead28;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 1688ULL;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
L_1ead08:
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    cpu->regs[0] = PB_BASE + 0x294000ULL;
    cpu->regs[0] = cpu->regs[0] + 1104ULL;
    cpu->regs[30] = PB_BASE + 0x1ead18ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xabed8ULL);
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1ead20ULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x1fa20cULL);
    if ((((uint32_t)(cpu->regs[20])))==0) goto L_1eacbc;
    goto L_1eace4;
L_1ead28:
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[3] + 240ULL;
    goto L_1ead08;
    /* nop */
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[3];
    cpu->regs[20] = cpu->regs[4];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[1] = 48ULL;
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[5];
    cpu->regs[30] = PB_BASE + 0x1ead74ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0x1085d0ULL);
    if ((cpu->regs[0])==0) goto L_1ead8c;
    cpu->regs[1] = 14ULL;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    PB_STR((cpu->regs[0] + 8), cpu->regs[23]);
    PB_STRW((cpu->regs[0] + 32), cpu->regs[21]); PB_STRW((cpu->regs[0] + 32) + 4, cpu->regs[22]);
    PB_STRW((cpu->regs[0] + 40), cpu->regs[19]); PB_STRW((cpu->regs[0] + 40) + 4, cpu->regs[20]);
L_1ead8c:
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1eada0:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    if ((cpu->regs[0])==0) goto L_1eadc4;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[2] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_1eadc4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_1eadcc;
L_1eadc4:
    cpu->regs[0] = 0ULL;
    return;
L_1eadcc:
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x1eadd8ULL; PB_CALL(142, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_EQ) goto L_1eae68;
L_1eae0c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1eae58;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0x1eae24ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_1eae48;
L_1eae28:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_1eae30:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_1eae38:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_1eae48:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1eae50ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x19a5e8ULL);
    if ((cpu->regs[0])!=0) goto L_1eae30;
    goto L_1eae28;
L_1eae58:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_1eae38;
L_1eae68:
    cpu->regs[30] = PB_BASE + 0x1eae6cULL; PB_CALL(145, cpu, tlb, PB_BASE + 0x94950ULL);
    goto L_1eae0c;
    goto L_1eada0;
    /* nop */
    /* nop */
    /* nop */
    goto L_1eae84;
L_1eae84:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1eae98ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x18cbf0ULL);
    cpu->regs[30] = PB_BASE + 0x1eae9cULL; PB_CALL(147, cpu, tlb, PB_BASE + 0x159340ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
    /* nop */
    /* nop */
    { PB_CALL(148, cpu, tlb, PB_BASE + 0x159340ULL); return; };
}
