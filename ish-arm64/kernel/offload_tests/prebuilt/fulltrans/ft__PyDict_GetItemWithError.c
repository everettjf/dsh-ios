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

void ft__PyDict_GetItemWithError(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
L_1977e4:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 120));
    cpu->regs[30] = PB_BASE + 0x197808ULL; PB_CALL(1, cpu, tlb, cpu->regs[1]);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_197828;
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xe35f0ULL); return; };
L_197828:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    /* nop */
    /* nop */
    SP = SP - 160ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 64), cpu->regs[29]); PB_STR((SP + 64) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 64ULL;
    PB_STR((SP + 80), cpu->regs[19]); PB_STR((SP + 80) + 8, cpu->regs[20]);
    PB_STR((SP + 96), cpu->regs[21]); PB_STR((SP + 96) + 8, cpu->regs[22]);
    PB_STR((SP + 112), cpu->regs[23]); PB_STR((SP + 112) + 8, cpu->regs[24]);
    PB_STR((SP + 128), cpu->regs[25]); PB_STR((SP + 128) + 8, cpu->regs[26]);
    PB_STR((SP + 144), cpu->regs[27]); PB_STR((SP + 144) + 8, cpu->regs[28]);
    cpu->regs[28] = cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[2] = 0ULL;
    FLAG_CMP(cpu->regs[28], 1ULL);
    if (FLAG_LE) goto L_197ec8;
    PB_LDR(cpu->regs[25], (cpu->regs[1] + 0));
    cpu->regs[23] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3680));
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[3], (cpu->regs[25] + 8));
    FLAG_CMP(cpu->regs[3], cpu->regs[0]);
    if (FLAG_NE) goto L_197e24;
    PB_LDR(cpu->regs[26], (cpu->regs[1] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_197ee8;
    cpu->regs[21] = cpu->regs[1] + 16ULL;
    cpu->regs[20] = cpu->regs[28] - 2ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1978c4ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdc780ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197d14;
    cpu->regs[4] = 0ULL;
    cpu->regs[19] = 0ULL;
L_1978d4:
    FLAG_CMP(cpu->regs[20], cpu->regs[19]);
    if (FLAG_GT) goto L_197a84;
    if ((cpu->regs[4])!=0) goto L_197ccc;
    cpu->regs[20] = cpu->regs[24];
L_1978e4:
    if ((cpu->regs[23])!=0) goto L_197c00;
L_1978e8:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 16));
    if ((cpu->regs[0])!=0) goto L_197abc;
    cpu->regs[22] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[22], (cpu->regs[22] + 3216));
L_1978f8:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_197ac8;
L_197904:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x197910ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x18e1e4ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197e68;
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_NE) goto L_197c68;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2248));
    cpu->regs[19] = 1ULL;
L_19792c:
    cpu->regs[0] = 31608ULL;
    cpu->regs[2] = SP + 24ULL;
    cpu->regs[1] = cpu->regs[27] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x197940ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x112290ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_197c9c;
    PB_LDR(cpu->regs[0], (SP + 24));
    if ((cpu->regs[0])==0) goto L_197ebc;
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = 2ULL;
    PB_STR((SP + 32), cpu->regs[26]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    cpu->regs[30] = PB_BASE + 0x197960ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x192f90ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_197980;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_197980;
    cpu->regs[30] = PB_BASE + 0x197980ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_197980:
    if ((cpu->regs[21])==0) goto L_197eb0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x19798cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x197f40ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_197e84;
    cpu->regs[2] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1979a4ULL; PB_CALL(9, cpu, tlb, cpu->regs[1]);
    cpu->regs[1] = cpu->regs[25];
    cpu->regs[5] = 0ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + cpu->regs[0]));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1979c0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xf3100ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197eb0;
    FLAG_CMP(cpu->regs[24], cpu->regs[20]);
    if (FLAG_NE) goto L_197cac;
L_1979d0:
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[1] = SP + 32ULL;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[2] = 3ULL;
    PB_STR((SP + 32), cpu->regs[26]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1979ecULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x192f90ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197a14;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_197a14;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2872));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_197bb4;
L_197a14:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x197a1cULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x197a24ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x197a2cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x197a34ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0xdce4cULL);
    FLAG_CMP(cpu->regs[24], cpu->regs[20]);
    if (FLAG_NE) goto L_197d1c;
L_197a3c:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_197aa4;
L_197a44:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 56));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_197d3c;
    PB_LDR(cpu->regs[29], (SP + 64)); PB_LDR(cpu->regs[30], (SP + 64) + 8);
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[19], (SP + 80)); PB_LDR(cpu->regs[20], (SP + 80) + 8);
    PB_LDR(cpu->regs[21], (SP + 96)); PB_LDR(cpu->regs[22], (SP + 96) + 8);
    PB_LDR(cpu->regs[23], (SP + 112)); PB_LDR(cpu->regs[24], (SP + 112) + 8);
    PB_LDR(cpu->regs[25], (SP + 128)); PB_LDR(cpu->regs[26], (SP + 128) + 8);
    PB_LDR(cpu->regs[27], (SP + 144)); PB_LDR(cpu->regs[28], (SP + 144) + 8);
    SP = SP + 160ULL;
    return;
L_197a84:
    PB_LDR(cpu->regs[3], (cpu->regs[21] + (cpu->regs[19] << 3)));
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_197ad0;
L_197a94:
    if ((cpu->regs[4])!=0) goto L_197f08;
    cpu->regs[4] = 0ULL;
L_197a9c:
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_1978d4;
L_197aa4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_197a44;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x197ab8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_197a44;
L_197abc:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 8));
    goto L_1978f8;
L_197ac8:
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
    goto L_197904;
L_197ad0:
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2248));
    cpu->regs[5] = 30656ULL;
    cpu->regs[2] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[3];
    cpu->regs[1] = cpu->regs[27] + cpu->regs[5];
    PB_STR((SP + 0), cpu->regs[3]); PB_STR((SP + 0) + 8, cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x197af0ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x112290ULL);
    PB_LDR(cpu->regs[4], (SP + 8));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197d7c;
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[3], (SP + 0));
    if ((cpu->regs[0])==0) goto L_197a94;
    cpu->regs[1] = cpu->regs[24];
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x197b10ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x120dccULL);
    cpu->regs[27] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 24));
    PB_LDR(cpu->regs[4], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_197b38;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_197b38;
    cpu->regs[30] = PB_BASE + 0x197b34ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[4], (SP + 0));
L_197b38:
    if ((cpu->regs[27])==0) goto L_197d7c;
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 26) & 1)) goto L_197dc0;
    if ((cpu->regs[4])!=0) goto L_197b68;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x197b54ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197d68;
    cpu->regs[0] = 0ULL;
L_197b60:
    FLAG_CMP(cpu->regs[19], cpu->regs[0]);
    if (FLAG_NE) goto L_197d40;
L_197b68:
    PB_LDR(cpu->regs[2], (cpu->regs[4] + 16));
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[3] = cpu->regs[27];
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x197b80ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1ac20cULL);
    PB_LDR(cpu->regs[1], (cpu->regs[27] + 0));
    PB_LDR(cpu->regs[4], (SP + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197dac;
    if (((cpu->regs[1] >> 31) & 1)) goto L_197a9c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_197a9c;
    cpu->regs[0] = cpu->regs[27];
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x197ba8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdcac8ULL);
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    PB_LDR(cpu->regs[4], (SP + 0));
    goto L_1978d4;
L_197bb4:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[25], cpu->regs[2]);
    if (FLAG_EQ) goto L_197a14;
    if ((cpu->regs[2])==0) goto L_197e44;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[3] = cpu->regs[26];
    cpu->regs[4] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[1] + 168ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x197be4ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x11f220ULL);
L_197be4:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197bf8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_197e74;
L_197bf8:
    cpu->regs[25] = 0ULL;
    goto L_197a14;
L_197c00:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22] + (cpu->regs[28] << 3);
    cpu->regs[30] = PB_BASE + 0x197c0cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1a6ed0ULL);
    cpu->regs[23] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197df8;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2248));
    cpu->regs[2] = 50360ULL;
    cpu->regs[1] = cpu->regs[27] + cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x197c28ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1977e4ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_197c94;
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_197c40;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_197c40:
    cpu->regs[1] = 50360ULL;
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[27] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x197c50ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x197f6cULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_197c9c;
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 8));
    cpu->regs[19] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197904;
    goto L_19792c;
L_197c68:
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_197c78;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_197c78:
    PB_LDR(cpu->regs[0], (cpu->regs[22] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_197e0c;
L_197c80:
    cpu->regs[22] = cpu->regs[19];
    cpu->regs[19] = 1ULL;
    cpu->regs[27] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[27], (cpu->regs[27] + 2248));
    goto L_19792c;
L_197c94:
    cpu->regs[30] = PB_BASE + 0x197c98ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_1978e8;
L_197c9c:
    cpu->regs[25] = 0ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_197a14;
L_197cac:
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[1] + 56ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x197cc0ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1a340cULL);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1979d0;
    cpu->regs[25] = 0ULL;
    goto L_197a14;
L_197ccc:
    cpu->regs[0] = cpu->regs[4];
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x197cd8ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0xdc740ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[4], (SP + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_197cfc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[4] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_197cfc;
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x197cfcULL; PB_CALL(30, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_197cfc:
    if ((cpu->regs[20])!=0) goto L_1978e4;
L_197d00:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197d14;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_197d88;
L_197d14:
    cpu->regs[25] = 0ULL;
    goto L_197a44;
L_197d1c:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197a3c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_197a3c;
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[30] = PB_BASE + 0x197d38ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_197a3c;
L_197d3c:
    cpu->regs[30] = PB_BASE + 0x197d40ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x7c170ULL);
L_197d40:
    PB_LDR(cpu->regs[2], (cpu->regs[21] + (cpu->regs[0] << 3)));
    cpu->regs[3] = cpu->regs[0] << 3;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_197d58;
    PB_STRW((cpu->regs[2] + 0), cpu->regs[1]);
L_197d58:
    PB_LDR(cpu->regs[1], (cpu->regs[4] + 24));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_STR((cpu->regs[1] + cpu->regs[3]), cpu->regs[2]);
    goto L_197b60;
L_197d68:
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197d7c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_197d98;
L_197d7c:
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x197d84ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xdce4cULL);
    goto L_197d00;
L_197d88:
    cpu->regs[0] = cpu->regs[24];
    cpu->regs[25] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x197d94ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_197a44;
L_197d98:
    PB_STR((SP + 0), cpu->regs[4]);
L_197d9c:
    cpu->regs[0] = cpu->regs[27];
    cpu->regs[30] = PB_BASE + 0x197da4ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[4], (SP + 0));
    goto L_197d7c;
L_197dac:
    if (((cpu->regs[1] >> 31) & 1)) goto L_197d7c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_197d7c;
    goto L_197d9c;
L_197dc0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[1] = cpu->regs[1] + 4056ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x197ddcULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[27] + 0));
    PB_LDR(cpu->regs[4], (SP + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197d7c;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[27] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_197d7c;
    goto L_197d9c;
L_197df8:
    cpu->regs[22] = 0ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_197a14;
L_197e0c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[22] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_197c80;
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x197e20ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_197c80;
L_197e24:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3968ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x197e40ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_197a44;
L_197e44:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3296));
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[3] = cpu->regs[25];
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 72ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x197e64ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_197be4;
L_197e68:
    cpu->regs[25] = 0ULL;
    cpu->regs[21] = 0ULL;
    goto L_197a14;
L_197e74:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[25] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x197e80ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_197a14;
L_197e84:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    if ((((uint32_t)(cpu->regs[19])))!=0) goto L_197f28;
    cpu->regs[2] = PB_BASE + 0x286000ULL;
    cpu->regs[2] = cpu->regs[2] + 3912ULL;
L_197e9c:
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 8));
    cpu->regs[1] = PB_BASE + 0x287000ULL;
    cpu->regs[1] = cpu->regs[1] + 0ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 24));
    cpu->regs[30] = PB_BASE + 0x197eb0ULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11f220ULL);
L_197eb0:
    cpu->regs[25] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_197a14;
L_197ebc:
    cpu->regs[30] = PB_BASE + 0x197ec0ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0xd94a0ULL);
    cpu->regs[21] = cpu->regs[0];
    goto L_197980;
L_197ec8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 3928ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x197ee4ULL; PB_CALL(43, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_197a44;
L_197ee8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x286000ULL;
    cpu->regs[25] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 4016ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x197f04ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1d5940ULL);
    goto L_197a44;
L_197f08:
    cpu->regs[0] = cpu->regs[4];
    cpu->regs[1] = cpu->regs[3];
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[30] = PB_BASE + 0x197f18ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xe548cULL);
    PB_LDR(cpu->regs[4], (SP + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_197d7c;
    cpu->regs[19] = cpu->regs[19] + 1ULL;
    goto L_1978d4;
L_197f28:
    PB_LDR(cpu->regs[2], (cpu->regs[22] + 24));
    goto L_197e9c;
    { PB_CALL(46, cpu, tlb, PB_BASE + 0xd94a0ULL); return; };
    /* nop */
    /* nop */
    /* nop */
}
