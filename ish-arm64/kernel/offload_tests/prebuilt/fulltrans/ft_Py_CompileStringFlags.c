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

void ft_Py_CompileStringFlags(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    cpu->regs[4] = 4294967295ULL;
    { PB_CALL(1, cpu, tlb, PB_BASE + 0x193104ULL); return; };
L_cf904:
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[2] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[30] = PB_BASE + 0xcf92cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x85fa8ULL);
    if ((cpu->regs[0])==0) goto L_cf998;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    FLAG_CMP((((uint32_t)(cpu->regs[2]))) & (((uint32_t)(4294967293ULL))), 0);
    cpu->regs[2] = PB_BASE + 0x2a8000ULL;
    cpu->regs[2] = cpu->regs[2] + 232ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[0] + 32),&_a,4); tlb_read(tlb,(cpu->regs[0] + 36),&_b,4); cpu->regs[22]=(uint64_t)(int64_t)_a; cpu->regs[23]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[19] = PB_BASE + 0x2a8000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0));
    cpu->regs[19] = cpu->regs[19] + 256ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[0] + 40),&_a,4); tlb_read(tlb,(cpu->regs[0] + 44),&_b,4); cpu->regs[24]=(uint64_t)(int64_t)_a; cpu->regs[25]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[19] = (FLAG_NE) ? cpu->regs[19] : cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0xcf960ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x26d060ULL);
    cpu->regs[7] = cpu->regs[0];
    cpu->regs[6] = cpu->regs[19];
    cpu->regs[5] = cpu->regs[25];
    PB_LDR(cpu->regs[25], (SP + 64));
    cpu->regs[4] = cpu->regs[24];
    cpu->regs[3] = cpu->regs[23];
    cpu->regs[2] = cpu->regs[22];
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x280d00ULL); return; };
L_cf998:
    cpu->regs[30] = PB_BASE + 0xcf99cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_cf9a8;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[20] + 96), cpu->regs[0]);
L_cf9a8:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_cf9c0:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_cf9ec;
    cpu->regs[30] = PB_BASE + 0xcf9ecULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x94950ULL);
L_cf9ec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_cfa04;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_cfa44;
L_cfa04:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 640ULL;
    cpu->regs[30] = PB_BASE + 0xcfa14ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_cfa24;
L_cfa18:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_cfa3c;
L_cfa24:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfa2cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x10ca20ULL);
    if ((cpu->regs[0])==0) goto L_cfa18;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
L_cfa3c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_cfa44:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_cfa84;
    cpu->regs[30] = PB_BASE + 0xcfa84ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x94950ULL);
L_cfa84:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_cfc14;
    cpu->regs[1] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[1] = 6000ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_cfab8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfab0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x94950ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_cfafc;
L_cfab8:
    PB_LDRW(cpu->regs[22], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 601ULL;
    cpu->regs[30] = PB_BASE + 0xcfac8ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_cfb24;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_cfafc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 603ULL;
    cpu->regs[30] = PB_BASE + 0xcfae8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_cfb24;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_cfb0c;
L_cfafc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_cfb7c;
L_cfb0c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 602ULL;
    cpu->regs[30] = PB_BASE + 0xcfb18ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_cfb24;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[22]);
L_cfb24:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    if ((cpu->regs[20])==0) goto L_cfb7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0xcfb40ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_cfb7c;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x2a8000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[0] + 28),&_a,4); tlb_read(tlb,(cpu->regs[0] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 232ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[20] + 20),&_a,4); tlb_read(tlb,(cpu->regs[20] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    PB_LDR(cpu->regs[7], (cpu->regs[20] + 8));
    cpu->regs[7] = cpu->regs[7] + 32ULL;
    cpu->regs[30] = PB_BASE + 0xcfb70ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0xcfb74ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_cfbf0;
    goto L_cfc10;
L_cfb7c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_cfc10;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfb90ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x10642cULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_cfc04;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0xcfba4ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_cfc04;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfbb4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_cfc04;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfbc0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x117288ULL);
    if ((cpu->regs[0])==0) goto L_cfc04;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x287000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[22] + 28),&_a,4); tlb_read(tlb,(cpu->regs[22] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 1576ULL;
L_cfbd8:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[20] + 32),&_a,4); tlb_read(tlb,(cpu->regs[20] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[30] = PB_BASE + 0xcfbe8ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0xcfbecULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_cfc10;
L_cfbf0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_cfc18;
L_cfc04:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_cfc2c;
L_cfc10:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
L_cfc14:
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_cfc18:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_cfc2c:
    cpu->regs[1] = PB_BASE + 0xc8000ULL;
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + 3580ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xcfc40ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xf26e0ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_cfc7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfc4cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_cfc7c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0xcfc60ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_cfc7c;
    cpu->regs[6] = PB_BASE + 0x2a8000ULL;
    cpu->regs[6] = cpu->regs[6] + 280ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[0] + 28),&_a,4); tlb_read(tlb,(cpu->regs[0] + 32),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    goto L_cfbd8;
L_cfc7c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_cfc10;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 35ULL;
    cpu->regs[30] = PB_BASE + 0xcfc94ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_cfcf4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfca4ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_cfcf4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 22ULL;
    cpu->regs[30] = PB_BASE + 0xcfcb4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_cfcf4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfcc0ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_cfcf4;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[6] = PB_BASE + 0x2a8000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[0] + 40),&_a,4); tlb_read(tlb,(cpu->regs[0] + 44),&_b,4); cpu->regs[4]=(uint64_t)(int64_t)_a; cpu->regs[5]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[6] = cpu->regs[6] + 344ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[20] + 20),&_a,4); tlb_read(tlb,(cpu->regs[20] + 24),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[30] = PB_BASE + 0xcfce8ULL; PB_CALL(30, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0xcfcecULL; PB_CALL(31, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_cfbf0;
    goto L_cfc10;
L_cfcf4:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    goto L_cfc10;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_cfd28;
    cpu->regs[30] = PB_BASE + 0xcfd28ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x94950ULL);
L_cfd28:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_cfd94;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 57ULL;
    cpu->regs[30] = PB_BASE + 0xcfd40ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_cfd90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 650ULL;
    cpu->regs[30] = PB_BASE + 0xcfd54ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_cfd90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfd60ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x10ef20ULL);
    cpu->regs[2] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_cfd90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 2ULL;
    cpu->regs[30] = PB_BASE + 0xcfd74ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xcf904ULL);
    cpu->regs[30] = PB_BASE + 0xcfd78ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_cfd94;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_cfd9c;
L_cfd90:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_cfd94:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_cfd9c:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_cfdec;
    cpu->regs[30] = PB_BASE + 0xcfdecULL; PB_CALL(38, cpu, tlb, PB_BASE + 0x94950ULL);
L_cfdec:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_cfe04;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_cff5c;
L_cfe04:
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfe10ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_cff50;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_cfe38;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfe38ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x94950ULL);
L_cfe38:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_cfec4;
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0xcfe4cULL; PB_CALL(41, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_cfeb8;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_cfed4;
    goto L_cfec4;
L_cfe60:
    cpu->regs[30] = PB_BASE + 0xcfe64ULL; PB_CALL(42, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_cfe98;
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_EQ) goto L_cfee0;
L_cfe74:
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[21] << 3)), cpu->regs[26]);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
L_cfe80:
    cpu->regs[1] = 12ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcfe8cULL; PB_CALL(43, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[1])!=0) goto L_cfe60;
L_cfe98:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[27]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xcfea8ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_cfefc;
L_cfeb0:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xcfeb8ULL; PB_CALL(45, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_cfeb8:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xcfec4ULL; PB_CALL(46, cpu, tlb, PB_BASE + 0x22d780ULL);
L_cfec4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_cff50;
L_cfed4:
    cpu->regs[21] = 0ULL;
    cpu->regs[22] = 1ULL;
    goto L_cfe80;
L_cfee0:
    cpu->regs[22] = cpu->regs[22] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22] << 3;
    cpu->regs[30] = PB_BASE + 0xcfef0ULL; PB_CALL(47, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_cfeb0;
    cpu->regs[20] = cpu->regs[0];
    goto L_cfe74;
L_cfefc:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_LE) goto L_cff20;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_cfefc;
L_cff20:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xcff28ULL; PB_CALL(48, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xcff44ULL; PB_CALL(49, cpu, tlb, PB_BASE + 0x118accULL);
L_cff44:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_cff5c;
L_cff50:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    goto L_cff44;
L_cff5c:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
L_cff7c:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_cffa8;
    cpu->regs[30] = PB_BASE + 0xcffa8ULL; PB_CALL(50, cpu, tlb, PB_BASE + 0x94950ULL);
L_cffa8:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_cffc0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0000;
L_cffc0:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcffccULL; PB_CALL(51, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])!=0) goto L_cffdc;
L_cffd0:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_cfff8;
L_cffdc:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xcffe4ULL; PB_CALL(52, cpu, tlb, PB_BASE + 0xcf9c0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_cffd0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
L_cfff8:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_d0000:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d004c;
    cpu->regs[30] = PB_BASE + 0xd004cULL; PB_CALL(53, cpu, tlb, PB_BASE + 0x94950ULL);
L_d004c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d0064;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d01bc;
L_d0064:
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0070ULL; PB_CALL(54, cpu, tlb, PB_BASE + 0xcff7cULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d01b0;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_d0098;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0098ULL; PB_CALL(55, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0098:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0124;
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0xd00acULL; PB_CALL(56, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0118;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_d0134;
    goto L_d0124;
L_d00c0:
    cpu->regs[30] = PB_BASE + 0xd00c4ULL; PB_CALL(57, cpu, tlb, PB_BASE + 0xcff7cULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d00f8;
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_EQ) goto L_d0140;
L_d00d4:
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[21] << 3)), cpu->regs[26]);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
L_d00e0:
    cpu->regs[1] = 12ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd00ecULL; PB_CALL(58, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[1])!=0) goto L_d00c0;
L_d00f8:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[27]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd0108ULL; PB_CALL(59, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d015c;
L_d0110:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd0118ULL; PB_CALL(60, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_d0118:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xd0124ULL; PB_CALL(61, cpu, tlb, PB_BASE + 0x22d780ULL);
L_d0124:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_d01b0;
L_d0134:
    cpu->regs[21] = 0ULL;
    cpu->regs[22] = 1ULL;
    goto L_d00e0;
L_d0140:
    cpu->regs[22] = cpu->regs[22] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22] << 3;
    cpu->regs[30] = PB_BASE + 0xd0150ULL; PB_CALL(62, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_d0110;
    cpu->regs[20] = cpu->regs[0];
    goto L_d00d4;
L_d015c:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_LE) goto L_d0180;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_d015c;
L_d0180:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd0188ULL; PB_CALL(63, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xd01a4ULL; PB_CALL(64, cpu, tlb, PB_BASE + 0x118accULL);
L_d01a4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d01bc;
L_d01b0:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    goto L_d01a4;
L_d01bc:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
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
    if (FLAG_NE) goto L_d0208;
    cpu->regs[30] = PB_BASE + 0xd0208ULL; PB_CALL(65, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0208:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d0220;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0258;
L_d0220:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd022cULL; PB_CALL(66, cpu, tlb, PB_BASE + 0x118d8cULL);
    if ((cpu->regs[0])!=0) goto L_d0250;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_d0250;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0xd0248ULL; PB_CALL(67, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_d0250;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_d0250:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_d0258:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d0298;
    cpu->regs[30] = PB_BASE + 0xd0298ULL; PB_CALL(68, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0298:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d02b0;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d02ec;
L_d02b0:
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd02bcULL; PB_CALL(69, cpu, tlb, PB_BASE + 0x118420ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d02d0;
L_d02c4:
    cpu->regs[20] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    goto L_d02e4;
L_d02d0:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 22ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xd02e0ULL; PB_CALL(70, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d02c4;
L_d02e4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_d02ec:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_d0304:
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d0330;
    cpu->regs[30] = PB_BASE + 0xd0330ULL; PB_CALL(71, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0330:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d0348;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0388;
L_d0348:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0354ULL; PB_CALL(72, cpu, tlb, PB_BASE + 0x156be0ULL);
    if ((cpu->regs[0])!=0) goto L_d0364;
L_d0358:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_d0380;
L_d0364:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd036cULL; PB_CALL(73, cpu, tlb, PB_BASE + 0xcf9c0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0358;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[0] = cpu->regs[0] + 1584ULL;
L_d0380:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_d0388:
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -96; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 80), cpu->regs[27]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d03d4;
    cpu->regs[30] = PB_BASE + 0xd03d4ULL; PB_CALL(74, cpu, tlb, PB_BASE + 0x94950ULL);
L_d03d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d03ec;
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0544;
L_d03ec:
    PB_LDRW(cpu->regs[25], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd03f8ULL; PB_CALL(75, cpu, tlb, PB_BASE + 0xd0304ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0538;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_d0420;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0420ULL; PB_CALL(76, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0420:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d04ac;
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0xd0434ULL; PB_CALL(77, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d04a0;
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))==0) goto L_d04bc;
    goto L_d04ac;
L_d0448:
    cpu->regs[30] = PB_BASE + 0xd044cULL; PB_CALL(78, cpu, tlb, PB_BASE + 0xd0304ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0480;
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_EQ) goto L_d04c8;
L_d045c:
    PB_LDRW(cpu->regs[27], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[20] + (cpu->regs[21] << 3)), cpu->regs[26]);
    cpu->regs[21] = cpu->regs[21] + 1ULL;
L_d0468:
    cpu->regs[1] = 12ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0474ULL; PB_CALL(79, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    if ((cpu->regs[1])!=0) goto L_d0448;
L_d0480:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[27]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd0490ULL; PB_CALL(80, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[22] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d04e4;
L_d0498:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd04a0ULL; PB_CALL(81, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_d04a0:
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xd04acULL; PB_CALL(82, cpu, tlb, PB_BASE + 0x22d780ULL);
L_d04ac:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_d0538;
L_d04bc:
    cpu->regs[21] = 0ULL;
    cpu->regs[22] = 1ULL;
    goto L_d0468;
L_d04c8:
    cpu->regs[22] = cpu->regs[22] << 1;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[22] << 3;
    cpu->regs[30] = PB_BASE + 0xd04d8ULL; PB_CALL(83, cpu, tlb, PB_BASE + 0xe5680ULL);
    if ((cpu->regs[0])==0) goto L_d0498;
    cpu->regs[20] = cpu->regs[0];
    goto L_d045c;
L_d04e4:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[21], cpu->regs[23]);
    if (FLAG_LE) goto L_d0508;
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[20] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_d04e4;
L_d0508:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0xd0510ULL; PB_CALL(84, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[3], (cpu->regs[19] + 144));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[1] = cpu->regs[24];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0xd052cULL; PB_CALL(85, cpu, tlb, PB_BASE + 0x118accULL);
L_d052c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0544;
L_d0538:
    cpu->regs[0] = 0ULL;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[25]);
    goto L_d052c;
L_d0544:
    PB_LDR(cpu->regs[27], (SP + 80));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 96;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d0594;
    cpu->regs[30] = PB_BASE + 0xd0594ULL; PB_CALL(86, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0594:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d07cc;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 637ULL;
    cpu->regs[30] = PB_BASE + 0xd05acULL; PB_CALL(87, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0644;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0xd05bcULL; PB_CALL(88, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0644;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd05ccULL; PB_CALL(89, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0644;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 12ULL;
    cpu->regs[30] = PB_BASE + 0xd05e0ULL; PB_CALL(90, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0644;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd05ecULL; PB_CALL(91, cpu, tlb, PB_BASE + 0x156be0ULL);
    if ((cpu->regs[0])==0) goto L_d0644;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd05f8ULL; PB_CALL(92, cpu, tlb, PB_BASE + 0xc8e90ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0644;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0xd060cULL; PB_CALL(93, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0644;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2416));
    cpu->regs[6] = PB_BASE + 0x2a8000ULL;
    do { int32_t _a=0,_b=0; tlb_read(tlb,(cpu->regs[20] + 32),&_a,4); tlb_read(tlb,(cpu->regs[20] + 36),&_b,4); cpu->regs[2]=(uint64_t)(int64_t)_a; cpu->regs[3]=(uint64_t)(int64_t)_b; } while(0);
    cpu->regs[5] = 18446744073709551611ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[6] = cpu->regs[6] + 392ULL;
    cpu->regs[4] = cpu->regs[5];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0638ULL; PB_CALL(94, cpu, tlb, PB_BASE + 0x280d00ULL);
    cpu->regs[30] = PB_BASE + 0xd063cULL; PB_CALL(95, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_d07cc;
    goto L_d07b4;
L_d0644:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d07cc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 637ULL;
    cpu->regs[30] = PB_BASE + 0xd065cULL; PB_CALL(96, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d06a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0xd066cULL; PB_CALL(97, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d06a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd067cULL; PB_CALL(98, cpu, tlb, PB_BASE + 0x10e6a0ULL);
    if ((cpu->regs[0])==0) goto L_d06a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0688ULL; PB_CALL(99, cpu, tlb, PB_BASE + 0xc8e90ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d06a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd069cULL; PB_CALL(100, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_d06cc;
L_d06a0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d07cc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 637ULL;
    cpu->regs[30] = PB_BASE + 0xd06b8ULL; PB_CALL(101, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d06e4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd06c8ULL; PB_CALL(102, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d06e4;
L_d06cc:
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[3] = cpu->regs[3] + 2008ULL;
    goto L_d07a0;
L_d06e4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d07cc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 637ULL;
    cpu->regs[30] = PB_BASE + 0xd06fcULL; PB_CALL(103, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d07c8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 16ULL;
    cpu->regs[30] = PB_BASE + 0xd070cULL; PB_CALL(104, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d07c8;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 6000ULL;
    cpu->regs[2] = ((uint32_t)(cpu->regs[0] + 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[2]);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[1])));
    if (FLAG_NE) goto L_d0730;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0730ULL; PB_CALL(105, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0730:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0758;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd0748ULL; PB_CALL(106, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_d077c;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d0768;
L_d0758:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    goto L_d07c8;
L_d0768:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0xd0774ULL; PB_CALL(107, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_d077c;
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
L_d077c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    if ((cpu->regs[0])==0) goto L_d07c8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[3] = PB_BASE + 0x2a8000ULL;
    cpu->regs[3] = cpu->regs[3] + 440ULL;
    cpu->regs[2] = 0ULL;
L_d07a0:
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd07acULL; PB_CALL(108, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[30] = PB_BASE + 0xd07b0ULL; PB_CALL(109, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_d07cc;
L_d07b4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[1] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    goto L_d07d4;
L_d07c8:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_d07cc:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
L_d07d4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d081c;
    cpu->regs[30] = PB_BASE + 0xd081cULL; PB_CALL(110, cpu, tlb, PB_BASE + 0x94950ULL);
L_d081c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0984;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 57ULL;
    cpu->regs[30] = PB_BASE + 0xd0834ULL; PB_CALL(111, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d08b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 650ULL;
    cpu->regs[30] = PB_BASE + 0xd0848ULL; PB_CALL(112, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d08b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0854ULL; PB_CALL(113, cpu, tlb, PB_BASE + 0x10c56cULL);
    if ((cpu->regs[0])==0) goto L_d08b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 651ULL;
    cpu->regs[30] = PB_BASE + 0xd0864ULL; PB_CALL(114, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d08b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0870ULL; PB_CALL(115, cpu, tlb, PB_BASE + 0x10ef20ULL);
    if ((cpu->regs[0])==0) goto L_d08b0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd0880ULL; PB_CALL(116, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d08b0;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[3] + 2008ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xd08a4ULL; PB_CALL(117, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[30] = PB_BASE + 0xd08a8ULL; PB_CALL(118, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_d0984;
    goto L_d096c;
L_d08b0:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0984;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 57ULL;
    cpu->regs[30] = PB_BASE + 0xd08c8ULL; PB_CALL(119, cpu, tlb, PB_BASE + 0xf2728ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0980;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 650ULL;
    cpu->regs[30] = PB_BASE + 0xd08dcULL; PB_CALL(120, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0980;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd08ecULL; PB_CALL(121, cpu, tlb, PB_BASE + 0x10c56cULL);
    if ((cpu->regs[0])==0) goto L_d0980;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 651ULL;
    cpu->regs[30] = PB_BASE + 0xd08fcULL; PB_CALL(122, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0980;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0908ULL; PB_CALL(123, cpu, tlb, PB_BASE + 0x10ef20ULL);
    if ((cpu->regs[0])==0) goto L_d0980;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0xd0918ULL; PB_CALL(124, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0980;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd0928ULL; PB_CALL(125, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0980;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 5ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xd093cULL; PB_CALL(126, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d0980;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2656));
    cpu->regs[2] = 0ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 20));
    cpu->regs[3] = PB_BASE + 0x2a8000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[3] + 480ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xd0964ULL; PB_CALL(127, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[30] = PB_BASE + 0xd0968ULL; PB_CALL(128, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_d0984;
L_d096c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d098c;
L_d0980:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_d0984:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_d098c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d09d4;
    cpu->regs[30] = PB_BASE + 0xd09d4ULL; PB_CALL(129, cpu, tlb, PB_BASE + 0x94950ULL);
L_d09d4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0adc;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 647ULL;
    cpu->regs[30] = PB_BASE + 0xd09ecULL; PB_CALL(130, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0a38;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd09f8ULL; PB_CALL(131, cpu, tlb, PB_BASE + 0x119360ULL);
    if ((cpu->regs[0])==0) goto L_d0a38;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd0a08ULL; PB_CALL(132, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0a38;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[3] + 2008ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xd0a2cULL; PB_CALL(133, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[30] = PB_BASE + 0xd0a30ULL; PB_CALL(134, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_d0adc;
    goto L_d0ac4;
L_d0a38:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0adc;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 647ULL;
    cpu->regs[30] = PB_BASE + 0xd0a50ULL; PB_CALL(135, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0ad8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0a60ULL; PB_CALL(136, cpu, tlb, PB_BASE + 0x119360ULL);
    if ((cpu->regs[0])==0) goto L_d0ad8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0xd0a70ULL; PB_CALL(137, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0ad8;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd0a80ULL; PB_CALL(138, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0ad8;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 5ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xd0a94ULL; PB_CALL(139, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d0ad8;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2656));
    cpu->regs[2] = 0ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 20));
    cpu->regs[3] = PB_BASE + 0x2a8000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[3] + 544ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xd0abcULL; PB_CALL(140, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[30] = PB_BASE + 0xd0ac0ULL; PB_CALL(141, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_d0adc;
L_d0ac4:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0ae4;
L_d0ad8:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_d0adc:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_d0ae4:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d0b2c;
    cpu->regs[30] = PB_BASE + 0xd0b2cULL; PB_CALL(142, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0b2c:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0c34;
    PB_LDRW(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 642ULL;
    cpu->regs[30] = PB_BASE + 0xd0b44ULL; PB_CALL(143, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0b90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0b50ULL; PB_CALL(144, cpu, tlb, PB_BASE + 0x119360ULL);
    if ((cpu->regs[0])==0) goto L_d0b90;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd0b60ULL; PB_CALL(145, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0b90;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2416));
    cpu->regs[2] = 0ULL;
    cpu->regs[3] = PB_BASE + 0x285000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[3] + 2008ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xd0b84ULL; PB_CALL(146, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[30] = PB_BASE + 0xd0b88ULL; PB_CALL(147, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_d0c34;
    goto L_d0c1c;
L_d0b90:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0c34;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 642ULL;
    cpu->regs[30] = PB_BASE + 0xd0ba8ULL; PB_CALL(148, cpu, tlb, PB_BASE + 0xf2728ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0c30;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0bb8ULL; PB_CALL(149, cpu, tlb, PB_BASE + 0x119360ULL);
    if ((cpu->regs[0])==0) goto L_d0c30;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 11ULL;
    cpu->regs[30] = PB_BASE + 0xd0bc8ULL; PB_CALL(150, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0c30;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 4ULL;
    cpu->regs[30] = PB_BASE + 0xd0bd8ULL; PB_CALL(151, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0c30;
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[2] = 5ULL;
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0xd0becULL; PB_CALL(152, cpu, tlb, PB_BASE + 0xf7270ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_d0c30;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2656));
    cpu->regs[2] = 0ULL;
    PB_LDRW(cpu->regs[4], (cpu->regs[20] + 20));
    cpu->regs[3] = PB_BASE + 0x2a8000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[3] + 608ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0xd0c14ULL; PB_CALL(153, cpu, tlb, PB_BASE + 0x26acc4ULL);
    cpu->regs[30] = PB_BASE + 0xd0c18ULL; PB_CALL(154, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])==0) goto L_d0c34;
L_d0c1c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0c3c;
L_d0c30:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[21]);
L_d0c34:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_d0c3c:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
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
    if (FLAG_NE) goto L_d0c80;
    cpu->regs[30] = PB_BASE + 0xd0c80ULL; PB_CALL(155, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0c80:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0cc4;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 7ULL;
    cpu->regs[30] = PB_BASE + 0xd0c98ULL; PB_CALL(156, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])!=0) goto L_d0ca4;
L_d0c9c:
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    goto L_d0cc4;
L_d0ca4:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0cacULL; PB_CALL(157, cpu, tlb, PB_BASE + 0x1179e4ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0c9c;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = 8ULL;
    cpu->regs[30] = PB_BASE + 0xd0cc0ULL; PB_CALL(158, cpu, tlb, PB_BASE + 0xf2728ULL);
    if ((cpu->regs[0])==0) goto L_d0c9c;
L_d0cc4:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 144));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] - 1ULL));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[0]);
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[2] = 6000ULL;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 144));
    PB_STR((SP + 64), cpu->regs[25]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[1] + 1ULL));
    PB_STRW((cpu->regs[0] + 144), cpu->regs[3]);
    FLAG_CMP(((uint32_t)(cpu->regs[1])), ((uint32_t)(cpu->regs[2])));
    if (FLAG_NE) goto L_d0d14;
    cpu->regs[30] = PB_BASE + 0xd0d14ULL; PB_CALL(159, cpu, tlb, PB_BASE + 0x94950ULL);
L_d0d14:
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_d0d3c;
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    cpu->regs[0] = 8ULL;
    cpu->regs[30] = PB_BASE + 0xd0d28ULL; PB_CALL(160, cpu, tlb, PB_BASE + 0xdbd90ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d0d4c;
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xd0d3cULL; PB_CALL(161, cpu, tlb, PB_BASE + 0x22d780ULL);
L_d0d3c:
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0e0c;
L_d0d4c:
    PB_LDRW(cpu->regs[23], (cpu->regs[19] + 96));
    if ((((uint32_t)(cpu->regs[23])))!=0) goto L_d0d3c;
    cpu->regs[22] = 0ULL;
    cpu->regs[24] = 1ULL;
L_d0d5c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0d64ULL; PB_CALL(162, cpu, tlb, PB_BASE + 0x19e3e8ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0da0;
    FLAG_CMP(cpu->regs[24], cpu->regs[22]);
    if (FLAG_NE) goto L_d0d90;
    cpu->regs[24] = cpu->regs[24] << 1;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[24] << 3;
    cpu->regs[30] = PB_BASE + 0xd0d84ULL; PB_CALL(163, cpu, tlb, PB_BASE + 0xe5680ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0db8;
    cpu->regs[21] = cpu->regs[0];
L_d0d90:
    PB_LDRW(cpu->regs[20], (cpu->regs[19] + 16));
    PB_STR((cpu->regs[21] + (cpu->regs[22] << 3)), cpu->regs[25]);
    cpu->regs[22] = cpu->regs[22] + 1ULL;
    goto L_d0d5c;
L_d0da0:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 32));
    PB_STRW((cpu->regs[19] + 16), cpu->regs[20]);
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0xd0db0ULL; PB_CALL(164, cpu, tlb, PB_BASE + 0x10c8e8ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_d0dd8;
L_d0db8:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd0dc0ULL; PB_CALL(165, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    cpu->regs[0] = 1ULL;
    PB_STRW((cpu->regs[19] + 96), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0xd0dccULL; PB_CALL(166, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
    goto L_d0e0c;
L_d0dd8:
    cpu->regs[0] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[23]));
    FLAG_CMP(cpu->regs[22], cpu->regs[23]);
    if (FLAG_LE) goto L_d0dfc;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[0] << 3;
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] + 1ULL));
    PB_LDR(cpu->regs[2], (cpu->regs[21] + cpu->regs[0]));
    PB_STR((cpu->regs[1] + cpu->regs[0]), cpu->regs[2]);
    goto L_d0dd8;
L_d0dfc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0xd0e04ULL; PB_CALL(167, cpu, tlb, PB_BASE + 0xdc0e4ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[19] + 144));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] - 1ULL));
L_d0e0c:
    PB_LDR(cpu->regs[25], (SP + 64));
    PB_STRW((cpu->regs[19] + 144), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    SP = SP - 112ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2248));
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 0));
    PB_STR((SP + 72), cpu->regs[1]);
    cpu->regs[1] = 0ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[1] = 54664ULL;
    cpu->regs[1] = cpu->regs[2] + cpu->regs[1];
    cpu->regs[2] = PB_BASE + 0x288000ULL;
    cpu->regs[2] = cpu->regs[2] + 1800ULL;
    cpu->regs[30] = PB_BASE + 0xd0e78ULL; PB_CALL(168, cpu, tlb, PB_BASE + 0x1d604cULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_d0f30;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 168));
    if (((cpu->regs[0] >> 27) & 1)) goto L_d0eac;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x2a8000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 800ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0xd0ea8ULL; PB_CALL(169, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_d0ecc;
L_d0eac:
    cpu->regs[0] = 0ULL;
    PB_STR((SP + 8), 0ULL);
    PB_STRW((SP + 16), 0ULL);
    PB_STR((SP + 24), cpu->regs[20]); PB_STR((SP + 24) + 8, 0ULL);
    PB_STR((SP + 40), 0ULL); PB_STR((SP + 40) + 8, 0ULL);
    cpu->regs[30] = PB_BASE + 0xd0ec4ULL; PB_CALL(170, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    PB_STR((SP + 64), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_d0ed4;
L_d0ecc:
    cpu->regs[20] = 0ULL;
    goto L_d0f08;
L_d0ed4:
    cpu->regs[0] = SP + 8ULL;
    cpu->regs[30] = PB_BASE + 0xd0edcULL; PB_CALL(171, cpu, tlb, PB_BASE + 0x194b90ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (SP + 64));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_d0efc;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_d0efc;
    cpu->regs[30] = PB_BASE + 0xd0efcULL; PB_CALL(172, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_d0efc:
    PB_LDR(cpu->regs[0], (SP + 48));
    if ((cpu->regs[0])==0) goto L_d0f08;
    cpu->regs[30] = PB_BASE + 0xd0f08ULL; PB_CALL(173, cpu, tlb, PB_BASE + 0xdc0e4ULL);
L_d0f08:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_d0f1c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])==0) goto L_d0f24;
L_d0f1c:
    cpu->regs[19] = cpu->regs[20];
    goto L_d0f30;
L_d0f24:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0xd0f2cULL; PB_CALL(174, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_d0f1c;
L_d0f30:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 72));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_d0f50;
    cpu->regs[30] = PB_BASE + 0xd0f50ULL; PB_CALL(175, cpu, tlb, PB_BASE + 0x7c170ULL);
L_d0f50:
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    SP = SP + 112ULL;
    return;
}
