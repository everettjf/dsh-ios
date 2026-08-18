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

void ft_PyThread_start_new_thread(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP = SP - 128ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 2248));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 440));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((SP + 72), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    if ((((uint32_t)(cpu->regs[3])))==0) goto L_226920;
L_226820:
    cpu->regs[20] = SP + 16ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x22682cULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x7ab50ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_226900;
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x226844ULL; PB_CALL(2, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    if ((cpu->regs[0])==0) goto L_226918;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 16));
    cpu->regs[0] = 2097152ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 88));
    FLAG_CMP(cpu->regs[1], 0ULL);
    cpu->regs[1] = (FLAG_NE) ? cpu->regs[1] : cpu->regs[0];
L_226860:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226868ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x7be60ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_226908;
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226878ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7b7a0ULL);
    cpu->regs[0] = 16ULL;
    cpu->regs[30] = PB_BASE + 0x226880ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xd7700ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_226900;
    PB_STR((cpu->regs[0] + 0), cpu->regs[21]); PB_STR((cpu->regs[0] + 0) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x226000ULL;
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[2] = cpu->regs[2] + 2536ULL;
    cpu->regs[30] = PB_BASE + 0x2268a4ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7b1a0ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x2268b4ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x7b390ULL);
    if ((((uint32_t)(cpu->regs[20])))!=0) goto L_2268f8;
    PB_LDR(cpu->regs[0], (SP + 8));
    cpu->regs[30] = PB_BASE + 0x2268c0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x7bee0ULL);
    PB_LDR(cpu->regs[0], (SP + 8));
L_2268c4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_2268f4;
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 128ULL;
    return;
L_2268f4:
    cpu->regs[30] = PB_BASE + 0x2268f8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c170ULL);
L_2268f8:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x226900ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xd7784ULL);
L_226900:
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_2268c4;
L_226908:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226910ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x7b390ULL);
    cpu->regs[0] = 18446744073709551615ULL;
    goto L_2268c4;
L_226918:
    cpu->regs[1] = 2097152ULL;
    goto L_226860;
L_226920:
    cpu->regs[30] = PB_BASE + 0x226924ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x17ac10ULL);
    goto L_226820;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x226938ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    cpu->regs[0] = PB_BASE + 0x226000ULL;
    cpu->regs[0] = cpu->regs[0] + 2344ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_2269b0;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x226968ULL; PB_CALL(14, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[20], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226978ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcdb0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_2269dc;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x226984ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x22698cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[30] = PB_BASE + 0x22699cULL; PB_CALL(18, cpu, tlb, cpu->regs[1]);
    if ((cpu->regs[20])==0) goto L_2269dc;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0xdce80ULL); return; };
L_2269b0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x2269b8ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x2269c0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdce4cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 320));
    cpu->regs[16] = cpu->regs[1];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_2269dc:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0)); PB_LDR(cpu->regs[20], (cpu->regs[0] + 0) + 8);
    cpu->regs[30] = PB_BASE + 0x2269fcULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x226a04ULL; PB_CALL(23, cpu, tlb, cpu->regs[19]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    /* nop */
}
