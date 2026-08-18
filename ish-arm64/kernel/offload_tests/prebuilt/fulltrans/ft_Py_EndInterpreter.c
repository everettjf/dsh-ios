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

void ft_Py_EndInterpreter(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x82a9cULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_STR((SP + 32), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_EQ) goto L_82ac8;
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 2440ULL;
    cpu->regs[1] = cpu->regs[1] + 3152ULL;
    cpu->regs[30] = PB_BASE + 0x82ac8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x91ebcULL);
L_82ac8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((cpu->regs[0])==0) goto L_82aec;
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 2440ULL;
    cpu->regs[1] = cpu->regs[1] + 3176ULL;
    cpu->regs[30] = PB_BASE + 0x82aecULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x91ebcULL);
L_82aec:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[21] + 44), cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82afcULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1e9380ULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82b04ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x1e94ccULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[0] + 3928ULL;
    cpu->regs[30] = PB_BASE + 0x82b10ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x1e9804ULL);
    PB_LDR(cpu->regs[20], (cpu->regs[21] + 72));
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_NE) goto L_82b24;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    if ((cpu->regs[0])==0) goto L_82b3c;
L_82b24:
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x29f000ULL;
    cpu->regs[0] = cpu->regs[0] + 2440ULL;
    cpu->regs[1] = cpu->regs[1] + 3208ULL;
    cpu->regs[30] = PB_BASE + 0x82b3cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x91ebcULL);
L_82b3c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x82b48ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1e98e0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0x82b50ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e9f50ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x82b58ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x1ea00cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0x82b60ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x1ebc64ULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x82b68ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x159390ULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2248));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_NE) goto L_82b88;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 96));
    PB_STR((cpu->regs[1] + 2504), 0ULL);
L_82b88:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x1f61c8ULL); return; };
    { PB_CALL(14, cpu, tlb, PB_BASE + 0x26e704ULL); return; };
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 8) + 8);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[0] = cpu->regs[0] + (cpu->regs[1] << 3);
    { PB_CALL(15, cpu, tlb, PB_BASE + 0x7aeb0ULL); return; };
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_82be0;
L_82bd4:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_82bfc;
    goto L_82bf0;
L_82be0:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x82be8ULL; PB_CALL(16, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_82bd4;
    goto L_82c44;
L_82bf0:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x82bf8ULL; PB_CALL(17, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_82c44;
L_82bfc:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_82c10;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x82c0cULL; PB_CALL(18, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_82c44;
L_82c10:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])==0) goto L_82c24;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x82c20ULL; PB_CALL(19, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_82c44;
L_82c24:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 40));
    if ((cpu->regs[0])==0) goto L_82c44;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_82c44:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_82c84;
L_82c78:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 16));
    if ((cpu->regs[0])!=0) goto L_82c94;
    goto L_82ca0;
L_82c84:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x82c8cULL; PB_CALL(20, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_82c78;
    goto L_82cc0;
L_82c94:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x82c9cULL; PB_CALL(21, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_82cc0;
L_82ca0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])==0) goto L_82cc0;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_82cc0:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    { PB_CALL(22, cpu, tlb, PB_BASE + 0x272aa0ULL); return; };
    { PB_CALL(23, cpu, tlb, PB_BASE + 0x272a24ULL); return; };
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3664));
    return;
    SP = SP - 96ULL;
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 3080));
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[1] = cpu->regs[2];
    PB_LDR(cpu->regs[5], (cpu->regs[4] + 0));
    PB_STR((SP + 40), cpu->regs[5]);
    cpu->regs[5] = 0ULL;
    if ((cpu->regs[3])==0) goto L_82d24;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 16));
    goto L_82d28;
L_82d24:
    cpu->regs[2] = 0ULL;
L_82d28:
    FLAG_CMP(cpu->regs[3], 0ULL);
    cpu->regs[20] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 3080));
    if (FLAG_EQ) { FLAG_CMP(cpu->regs[1], 0ULL); } else { FLAG_CMP(0, 0); }
    if (FLAG_LE) goto L_82d4c;
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[1], 2ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_LE) goto L_82d78;
L_82d4c:
    cpu->regs[2] = SP + 24ULL;
    PB_STR((SP + 0), cpu->regs[2]);
    cpu->regs[4] = PB_BASE + 0x522000ULL;
    cpu->regs[4] = cpu->regs[4] + 528ULL;
    cpu->regs[4] = cpu->regs[4] + 1400ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 2ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x82d74ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_82dcc;
L_82d78:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 0));
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_82d98;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x82d8cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1227a0ULL);
    cpu->regs[2] = cpu->regs[0];
    if (!((cpu->regs[0] >> 31) & 1)) goto L_82d9c;
    goto L_82dcc;
L_82d98:
    cpu->regs[2] = 0ULL;
L_82d9c:
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_82de0;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    { PB_CALL(26, cpu, tlb, PB_BASE + 0x158168ULL); return; };
L_82dcc:
    PB_LDR(cpu->regs[0], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[0] = cpu->regs[0] - cpu->regs[1]; FLAG_CMP(cpu->regs[0], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_82de4;
L_82de0:
    cpu->regs[30] = PB_BASE + 0x82de4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x7c170ULL);
L_82de4:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    SP = SP + 96ULL;
    return;
    SP = SP - 64ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    cpu->regs[4] = SP;
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]); PB_STR((SP + 48) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 8), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[3] = 1ULL;
    cpu->regs[1] = cpu->regs[1] + 240ULL;
    cpu->regs[2] = cpu->regs[3];
    PB_STR((SP + 0), 0ULL);
    cpu->regs[30] = PB_BASE + 0x82e4cULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x116904ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_82ea0;
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2584));
    PB_LDR(cpu->regs[0], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x82e64ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_82e7c;
    cpu->regs[30] = PB_BASE + 0x82e74ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_82ea8;
    goto L_82ea0;
L_82e7c:
    cpu->regs[0] = 2147483648ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[1] = 4294967295ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_LS) goto L_82ea8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = PB_BASE + 0x2a0000ULL;
    cpu->regs[1] = cpu->regs[1] + 624ULL;
    cpu->regs[30] = PB_BASE + 0x82ea0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_82ea0:
    cpu->regs[20] = 0ULL;
    goto L_82f18;
L_82ea8:
    cpu->regs[30] = PB_BASE + 0x82eacULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x1ce1e0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_82ea0;
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[19] + 32ULL;
    cpu->regs[30] = PB_BASE + 0x82ec4ULL; PB_CALL(33, cpu, tlb, cpu->regs[21]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_82eec;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_STR((cpu->regs[19] + 40), 0ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_82ea0;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_82ea0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82ee8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_82ea0;
L_82eec:
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82ef8ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1ce788ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_82f18;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_82f18;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x82f18ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_82f18:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_82f38;
    cpu->regs[30] = PB_BASE + 0x82f38ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x7c170ULL);
L_82f38:
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    PB_LDR(cpu->regs[21], (SP + 48)); PB_LDR(cpu->regs[22], (SP + 48) + 8);
    SP = SP + 64ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x82f5cULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1d25e0ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 48));
    if ((cpu->regs[1])!=0) goto L_82fb8;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x82f84ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x1d1d40ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_82fa8;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 24), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_82fa8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_82fa8;
    cpu->regs[30] = PB_BASE + 0x82fa8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_82fa8:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_82fb8:
    cpu->regs[0] = 0ULL;
    return;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 24));
    cpu->regs[3] = cpu->regs[1];
    cpu->regs[1] = cpu->regs[2];
    if ((cpu->regs[0])==0) goto L_82fd8;
    cpu->regs[16] = cpu->regs[3];
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_82fd8:
    cpu->regs[0] = 0ULL;
    return;
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[0] = cpu->regs[0] + 16ULL;
    cpu->regs[29] = SP;
    cpu->regs[30] = PB_BASE + 0x82ff0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11ec60ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[2];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])!=0) goto L_8302c;
L_83020:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 24));
    if ((cpu->regs[0])!=0) goto L_8303c;
    goto L_83048;
L_8302c:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x83034ULL; PB_CALL(42, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_83020;
    goto L_8307c;
L_8303c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x83044ULL; PB_CALL(43, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_8307c;
L_83048:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 32));
    if ((cpu->regs[0])==0) goto L_8305c;
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x83058ULL; PB_CALL(44, cpu, tlb, cpu->regs[19]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_8307c;
L_8305c:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    if ((cpu->regs[0])==0) goto L_8307c;
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[16] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    prebuilt_call(cpu, tlb, cpu->regs[16]); return;
L_8307c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_830b4;
L_830a4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(45, cpu, tlb, PB_BASE + 0xe3ac0ULL); return; };
L_830b4:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1168ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x830ccULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_830a4;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    FLAG_CMP(cpu->regs[2], 2ULL);
    if (FLAG_NE) goto L_83108;
L_830f8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[1], (cpu->regs[19] + 0) + 8);
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(47, cpu, tlb, PB_BASE + 0x83134ULL); return; };
L_83108:
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    cpu->regs[3] = 2ULL;
    cpu->regs[0] = cpu->regs[0] + 1176ULL;
    cpu->regs[2] = cpu->regs[3];
    cpu->regs[30] = PB_BASE + 0x83120ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0x116fa0ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_830f8;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
}
