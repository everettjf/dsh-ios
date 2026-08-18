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

void ft_PyObject_CopyData(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 240ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 176), cpu->regs[29]); PB_STR((SP + 176) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 176ULL;
    PB_STR((SP + 192), cpu->regs[19]); PB_STR((SP + 192) + 8, cpu->regs[20]);
    PB_STR((SP + 208), cpu->regs[21]); PB_STR((SP + 208) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 160));
    PB_STR((SP + 224), cpu->regs[23]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 168), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    if ((cpu->regs[1])==0) goto L_9a8a0;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    if ((cpu->regs[1])==0) goto L_9a8a0;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 160));
    if ((cpu->regs[1])==0) goto L_9a8a0;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    if ((cpu->regs[1])==0) goto L_9a8a0;
    cpu->regs[19] = SP + 88ULL;
    cpu->regs[2] = 285ULL;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9a898ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11e5ccULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9a8c0;
    goto L_9a8b8;
L_9a8a0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 3320ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9a8b8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_9a8b8:
    cpu->regs[23] = 4294967295ULL;
    goto L_9aaa0;
L_9a8c0:
    cpu->regs[20] = SP + 8ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 284ULL;
    cpu->regs[30] = PB_BASE + 0x9a8d4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x11e5ccULL);
    cpu->regs[23] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9a8e8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9a8e4ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_9a8b8;
L_9a8e8:
    PB_LDR(cpu->regs[21], (SP + 24));
    PB_LDR(cpu->regs[0], (SP + 104));
    FLAG_CMP(cpu->regs[0], cpu->regs[21]);
    if (FLAG_GE) goto L_9a924;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2792));
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[1] + 3376ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9a910ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9a918ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9a920ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_9a8b8;
L_9a924:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 67ULL;
    cpu->regs[30] = PB_BASE + 0x9a930ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x14cdc4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9a944;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 67ULL;
    cpu->regs[30] = PB_BASE + 0x9a940ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x14cdc4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9a964;
L_9a944:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 70ULL;
    cpu->regs[30] = PB_BASE + 0x9a950ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x14cdc4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9a9b0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 70ULL;
    cpu->regs[30] = PB_BASE + 0x9a960ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x14cdc4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9a9b0;
L_9a964:
    PB_LDR(cpu->regs[1], (SP + 8));
    PB_LDR(cpu->regs[0], (SP + 88));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HS) goto L_9a984;
    cpu->regs[2] = cpu->regs[0] + cpu->regs[21];
    FLAG_CMP(cpu->regs[1], cpu->regs[2]);
    if (FLAG_HS) goto L_9a994;
L_9a980:
    __builtin_trap();
L_9a984:
    if (FLAG_LS) goto L_9a994;
    cpu->regs[2] = cpu->regs[1] + cpu->regs[21];
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_LO) goto L_9a980;
L_9a994:
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9a99cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7c090ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9a9a4ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9a9acULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_9aaa0;
L_9a9b0:
    do { int32_t _s=0; tlb_read(tlb,(SP + 44),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[30] = PB_BASE + 0x9a9bcULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9a9d0;
    PB_LDRW(cpu->regs[1], (SP + 44));
    cpu->regs[0] = 0ULL;
    goto L_9a9e8;
L_9a9d0:
    cpu->regs[30] = PB_BASE + 0x9a9d4ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9a9dcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9a9e4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x11ec60ULL);
    goto L_9a8b8;
L_9a9e8:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_9a9fc;
    PB_STR((cpu->regs[22] + (cpu->regs[0] << 3)), 0ULL);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    goto L_9a9e8;
L_9a9fc:
    PB_LDR(cpu->regs[2], (SP + 56));
    cpu->regs[0] = 0ULL;
    cpu->regs[21] = 1ULL;
L_9aa08:
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_9aa6c;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + (cpu->regs[0] << 3)));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[21] = cpu->regs[21] * cpu->regs[3];
    goto L_9aa08;
L_9aa20:
    PB_LDR(cpu->regs[2], (SP + 56));
    cpu->regs[1] = cpu->regs[22];
    PB_LDRW(cpu->regs[0], (SP + 44));
    cpu->regs[30] = PB_BASE + 0x9aa30ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x860ecULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9aa38ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x8884cULL);
    cpu->regs[9] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9aa44ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x8884cULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (SP + 32));
    FLAG_CMP(cpu->regs[9], cpu->regs[0]);
    if (FLAG_HS) goto L_9aa74;
    cpu->regs[0] = cpu->regs[9] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_9a980;
L_9aa60:
    cpu->regs[21] = cpu->regs[21] - 1ULL;
    cpu->regs[0] = cpu->regs[9];
    cpu->regs[30] = PB_BASE + 0x9aa6cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c090ULL);
L_9aa6c:
    if ((cpu->regs[21])!=0) goto L_9aa20;
    goto L_9aa88;
L_9aa74:
    if (FLAG_LS) goto L_9aa60;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[2];
    FLAG_CMP(cpu->regs[9], cpu->regs[0]);
    if (FLAG_HS) goto L_9aa60;
    goto L_9a980;
L_9aa88:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9aa90ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9aa98ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9aaa0ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x11ec60ULL);
L_9aaa0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 168));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9aac0;
    cpu->regs[30] = PB_BASE + 0x9aac0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9aac0:
    PB_LDR(cpu->regs[29], (SP + 176)); PB_LDR(cpu->regs[30], (SP + 176) + 8);
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[23], (SP + 224));
    PB_LDR(cpu->regs[19], (SP + 192)); PB_LDR(cpu->regs[20], (SP + 192) + 8);
    PB_LDR(cpu->regs[21], (SP + 208)); PB_LDR(cpu->regs[22], (SP + 208) + 8);
    SP = SP + 240ULL;
    return;
    SP = SP - 144ULL;
    FLAG_CMP(cpu->regs[0], 0ULL);
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 96), cpu->regs[29]); PB_STR((SP + 96) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 96ULL;
    PB_STR((SP + 112), cpu->regs[19]); PB_STR((SP + 112) + 8, cpu->regs[20]);
    PB_STR((SP + 128), cpu->regs[21]); PB_STR((SP + 128) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    if (FLAG_NE) { FLAG_CMP(cpu->regs[21], 0ULL); } else { FLAG_CMP(0, 0); }
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 88), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9ab1c;
    cpu->regs[20] = cpu->regs[2];
    if ((cpu->regs[2])!=0) goto L_9ab24;
L_9ab1c:
    cpu->regs[30] = PB_BASE + 0x9ab20ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x96bd4ULL);
    goto L_9ab3c;
L_9ab24:
    cpu->regs[22] = SP + 8ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9ab34ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x11e5ccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9ab44;
L_9ab3c:
    cpu->regs[19] = 4294967295ULL;
    goto L_9ab5c;
L_9ab44:
    PB_LDR(cpu->regs[0], (SP + 8));
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9ab5cULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x11ec60ULL);
L_9ab5c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 88));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_9ab7c;
    cpu->regs[30] = PB_BASE + 0x9ab7cULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x7c170ULL);
L_9ab7c:
    PB_LDR(cpu->regs[29], (SP + 96)); PB_LDR(cpu->regs[30], (SP + 96) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 112)); PB_LDR(cpu->regs[20], (SP + 112) + 8);
    PB_LDR(cpu->regs[21], (SP + 128)); PB_LDR(cpu->regs[22], (SP + 128) + 8);
    SP = SP + 144ULL;
    return;
}
