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

void ft_PyObject_CallObject(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x208e90ULL; PB_CALL(1, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[3] + cpu->regs[0]));
    if ((cpu->regs[2])==0) goto L_208eb0;
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 8));
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 168));
    if (!((cpu->regs[3] >> 26) & 1)) goto L_208ec0;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[3] = 0ULL;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0x12660cULL); return; };
L_208eb0:
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    { PB_CALL(3, cpu, tlb, PB_BASE + 0xe742cULL); return; };
L_208ec0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2736));
    cpu->regs[2] = PB_BASE + 0x296000ULL;
    cpu->regs[2] = cpu->regs[2] + 3864ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x208ed8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5980ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP = SP - 32ULL;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    cpu->regs[4] = 29464ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[1] = SP;
    cpu->regs[2] = 1ULL;
    PB_STR((SP + 0), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x208f28ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x152e40ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_208f50;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    SP = SP + 32ULL;
    return;
L_208f50:
    cpu->regs[30] = PB_BASE + 0x208f54ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x7c170ULL);
    /* nop */
    /* nop */
    /* nop */
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    if ((cpu->regs[0])==0) goto L_208f9c;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[1] + 24), 0ULL);
    if (((cpu->regs[2] >> 31) & 1)) goto L_208f9c;
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_208f9c;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x208f90ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
L_208f9c:
    cpu->regs[0] = 0ULL;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
    FLAG_CMP(cpu->regs[0], cpu->regs[20]);
    if (FLAG_EQ) goto L_2090ac;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    PB_STR((cpu->regs[0] + 24), 0ULL);
    PB_STR((cpu->regs[19] + 16), cpu->regs[19]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[19]);
L_208fcc:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    if ((cpu->regs[0])==0) goto L_208ff0;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 72), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_208ff0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_208ff0;
    cpu->regs[30] = PB_BASE + 0x208ff0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_208ff0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 88));
    if ((cpu->regs[0])==0) goto L_209010;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 88), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_209010;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2090cc;
L_209010:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 112));
    if ((cpu->regs[0])==0) goto L_209030;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 112), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_209030;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2090bc;
L_209030:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 120));
    if ((cpu->regs[0])==0) goto L_209050;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 120), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_209050;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2090c4;
L_209050:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 128));
    if ((cpu->regs[0])==0) goto L_209070;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 128), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_209070;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_2090b4;
L_209070:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 136));
    if ((cpu->regs[0])==0) goto L_209094;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 136), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_209094;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_209094;
    cpu->regs[30] = PB_BASE + 0x209094ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_209094:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x20909cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x2090e0ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_2090ac:
    cpu->regs[20] = 0ULL;
    goto L_208fcc;
L_2090b4:
    cpu->regs[30] = PB_BASE + 0x2090b8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_209070;
L_2090bc:
    cpu->regs[30] = PB_BASE + 0x2090c0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_209030;
L_2090c4:
    cpu->regs[30] = PB_BASE + 0x2090c8ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_209050;
L_2090cc:
    cpu->regs[30] = PB_BASE + 0x2090d0ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_209010;
    /* nop */
    /* nop */
    /* nop */
L_2090e0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
L_2090f0:
    cpu->regs[1] = cpu->regs[19];
L_2090f4:
    if ((cpu->regs[19])!=0) goto L_209104;
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_209104:
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 24));
    cpu->regs[2] = cpu->regs[3] - 1ULL;
    if (((cpu->regs[3] >> 31) & 1)) goto L_2090f0;
    PB_STR((cpu->regs[1] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_2090f0;
    cpu->regs[30] = PB_BASE + 0x209124ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[1] = cpu->regs[19];
    goto L_2090f4;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x208ac4ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
    cpu->regs[30] = PB_BASE + 0x20914cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18d760ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x209154ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1a8480ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x209160ULL; PB_CALL(19, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_209174;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_209180;
L_209174:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_209180:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(20, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
}
