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

void ft__Py_device_encoding(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x9b360ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1c8ae8ULL);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9b36cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x7bdb0ULL);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9b378ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1c8c40ULL);
    if ((((uint32_t)(cpu->regs[19])))==0) goto L_9b3b8;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 2964));
    if ((((uint32_t)(cpu->regs[1])))==0) goto L_9b3ac;
    cpu->regs[2] = cpu->regs[0] + (4ULL << 12);
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 8464));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9b3a0;
    PB_STRW((cpu->regs[2] + 8464), cpu->regs[1]);
L_9b3a0:
    cpu->regs[1] = 24848ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    goto L_9b3c0;
L_9b3ac:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(4, cpu, tlb, PB_BASE + 0x21720cULL); return; };
L_9b3b8:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
L_9b3c0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[5] = cpu->regs[0];
    cpu->regs[6] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[6] = cpu->regs[6] + 3576ULL;
    cpu->regs[1] = cpu->regs[1] + 3584ULL;
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[5] + 8));
    cpu->regs[0] = cpu->regs[0] + 3600ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[5] + 24)); PB_LDR(cpu->regs[4], (cpu->regs[5] + 24) + 8);
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[6];
    { PB_CALL(5, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[4] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[4] = cpu->regs[4] + 3576ULL;
    cpu->regs[1] = cpu->regs[1] + 3584ULL;
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 8));
    cpu->regs[0] = cpu->regs[0] + 3648ULL;
    PB_LDRB(cpu->regs[5], (cpu->regs[3] + 32));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    FLAG_CMP(((uint32_t)(cpu->regs[5])), ((uint32_t)(0ULL)));
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[4];
    { PB_CALL(6, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 3672ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    { PB_CALL(7, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    FLAG_CMP(cpu->regs[1], 4ULL);
    cpu->regs[2] = PB_BASE + 0x2a2000ULL;
    cpu->regs[3] = PB_BASE + 0x2a2000ULL;
    cpu->regs[2] = cpu->regs[2] + 3688ULL;
    cpu->regs[3] = cpu->regs[3] + 3736ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] - 3ULL;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = (FLAG_EQ) ? cpu->regs[3] : cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x9b478ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    if ((cpu->regs[0])==0) goto L_9b4b0;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x9b48cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e31c0ULL);
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9b4b4;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9b4b4;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9b4acULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9b4b4;
L_9b4b0:
    cpu->regs[20] = 4294967295ULL;
L_9b4b4:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[1] + 3784ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 16));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 32));
    PB_LDRW(cpu->regs[3], (cpu->regs[3] + 88));
    { PB_CALL(11, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[2] + 3824ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 2760));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 16));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    FLAG_CMP(cpu->regs[4], 0ULL);
    cpu->regs[3] = (FLAG_GT) ? cpu->regs[3] : cpu->regs[2];
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    { PB_CALL(12, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 34));
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if (!((cpu->regs[2] >> 0) & 1)) goto L_9b534;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + 1ULL)); FLAG_CMP(cpu->regs[1], 0);
    if (FLAG_EQ) goto L_9b568;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[1]);
    goto L_9b568;
L_9b534:
    PB_LDRB(cpu->regs[2], (cpu->regs[1] + 32));
    if (((cpu->regs[2] >> 0) & 1)) goto L_9b554;
    PB_LDRB(cpu->regs[3], (cpu->regs[1] + 33));
    cpu->regs[2] = 45ULL;
    cpu->regs[1] = 126ULL;
    FLAG_CMP((cpu->regs[3]) & (1ULL), 0);
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[2];
    goto L_9b558;
L_9b554:
    cpu->regs[1] = 43ULL;
L_9b558:
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x29b000ULL;
    cpu->regs[0] = cpu->regs[0] + 1640ULL;
    { PB_CALL(13, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_9b568:
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x9b580ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22624));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_9b5b0;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3856ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    { PB_CALL(15, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_9b5b0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3872ULL;
    { PB_CALL(16, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x9b5d8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xecf64ULL);
    cpu->regs[0] = cpu->regs[0] + (88ULL << 12);
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 22624));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    FLAG_CMP(cpu->regs[0], cpu->regs[2]);
    if (FLAG_NE) goto L_9b608;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3888ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    { PB_CALL(18, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_9b608:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3896ULL;
    { PB_CALL(19, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 32));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[2])==0) goto L_9b64c;
    if ((cpu->regs[0])==0) goto L_9b634;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    goto L_9b63c;
L_9b634:
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 1504ULL;
L_9b63c:
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 3904ULL;
    { PB_CALL(20, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_9b64c:
    if ((cpu->regs[0])==0) goto L_9b658;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    goto L_9b660;
L_9b658:
    cpu->regs[1] = PB_BASE + 0x2a1000ULL;
    cpu->regs[1] = cpu->regs[1] + 1504ULL;
L_9b660:
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 3944ULL;
    { PB_CALL(21, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[1] + 3976ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 16)); PB_LDR(cpu->regs[2], (cpu->regs[3] + 16) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 32));
    { PB_CALL(22, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[5] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x9b6a8ULL; PB_CALL(23, cpu, tlb, cpu->regs[6]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[19] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = cpu->regs[2];
    cpu->regs[24] = cpu->regs[4];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[25] = cpu->regs[3];
    PB_LDR(cpu->regs[0], (cpu->regs[5] + cpu->regs[0]));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 16));
    cpu->regs[22] = cpu->regs[21] + (66ULL << 12);
    cpu->regs[21] = cpu->regs[21] + (66ULL << 12);
    cpu->regs[22] = cpu->regs[22] + 1688ULL;
    cpu->regs[21] = cpu->regs[21] + 1752ULL;
L_9b6dc:
    if (!((cpu->regs[20] >> 0) & 1)) goto L_9b7bc;
    PB_LDR(cpu->regs[4], (cpu->regs[22] + 0));
    if ((cpu->regs[4])==0) goto L_9b7bc;
    cpu->regs[3] = cpu->regs[24];
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9b6fcULL; PB_CALL(24, cpu, tlb, cpu->regs[4]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9b7bc;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_9b74c;
    if (FLAG_HI) goto L_9b730;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_9b758;
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(2ULL)));
    cpu->regs[0] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = PB_BASE + 0x2a2000ULL;
    cpu->regs[0] = cpu->regs[0] + 4000ULL;
    cpu->regs[1] = cpu->regs[1] + 4048ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    goto L_9b760;
L_9b730:
    FLAG_CMP(((uint32_t)(cpu->regs[19])), ((uint32_t)(4ULL)));
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 24ULL;
    cpu->regs[1] = cpu->regs[1] + 0ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    goto L_9b760;
L_9b74c:
    cpu->regs[5] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[5] + 4072ULL;
    goto L_9b760;
L_9b758:
    cpu->regs[5] = PB_BASE + 0x2a2000ULL;
    cpu->regs[1] = cpu->regs[5] + 4024ULL;
L_9b760:
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 56ULL;
    cpu->regs[30] = PB_BASE + 0x9b770ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9b798;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9b790;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
L_9b790:
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2760));
L_9b798:
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x9b7a0ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x1fa20cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[26] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9b7bc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9b7bc;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x9b7bcULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9b7bc:
    cpu->regs[22] = cpu->regs[22] + 8ULL;
    cpu->regs[20] = ((uint32_t)((uint64_t)((int64_t)cpu->regs[20] >> 1)));
    FLAG_CMP(cpu->regs[22], cpu->regs[21]);
    if (FLAG_NE) goto L_9b6dc;
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x29a000ULL;
    cpu->regs[0] = cpu->regs[0] + 920ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    { PB_CALL(28, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x9b810ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[0] + 96ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(30, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 104ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    { PB_CALL(31, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 128ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 16));
    { PB_CALL(32, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[19] = cpu->regs[0] + 1752ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[2];
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[23] = PB_BASE + 0x295000ULL;
    cpu->regs[24] = cpu->regs[3];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    cpu->regs[23] = cpu->regs[23] + 1912ULL;
    PB_LDRB(cpu->regs[22], (cpu->regs[0] + 1816));
L_9b888:
    if ((((uint32_t)(cpu->regs[22])))==0) goto L_9b9a0;
    if (!((cpu->regs[22] >> 0) & 1)) goto L_9b994;
    PB_LDR(cpu->regs[3], (cpu->regs[19] + 0));
    cpu->regs[2] = cpu->regs[24];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9b8a4ULL; PB_CALL(33, cpu, tlb, cpu->regs[3]);
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9b994;
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 40));
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x9b8b8ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    cpu->regs[26] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9b8dc;
L_9b8c0:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9b968;
    PB_STRW((cpu->regs[1] + 0), cpu->regs[0]);
    goto L_9b968;
L_9b8dc:
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(3ULL)));
    if (FLAG_EQ) goto L_9b910;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(4ULL)));
    if (FLAG_EQ) goto L_9b91c;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_9b928;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(2ULL)));
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 152ULL;
    cpu->regs[1] = cpu->regs[1] + 208ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[0];
    goto L_9b930;
L_9b910:
    cpu->regs[4] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[4] + 240ULL;
    goto L_9b930;
L_9b91c:
    cpu->regs[4] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[4] + 280ULL;
    goto L_9b930;
L_9b928:
    cpu->regs[4] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[4] + 176ULL;
L_9b930:
    cpu->regs[2] = cpu->regs[26];
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[0] = cpu->regs[0] + 1312ULL;
    cpu->regs[30] = PB_BASE + 0x9b940ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x1abcc0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[26] + 0));
    cpu->regs[25] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_9b960;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[26] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9b960;
    cpu->regs[0] = cpu->regs[26];
    cpu->regs[30] = PB_BASE + 0x9b960ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9b960:
    if ((cpu->regs[25])!=0) goto L_9b970;
    goto L_9b8c0;
L_9b968:
    cpu->regs[25] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[25], (cpu->regs[25] + 2760));
L_9b970:
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x9b978ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1fa20cULL);
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9b994;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9b994;
    cpu->regs[0] = cpu->regs[25];
    cpu->regs[30] = PB_BASE + 0x9b994ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9b994:
    cpu->regs[22] = ((uint32_t)(cpu->regs[22] >> 1));
    cpu->regs[19] = cpu->regs[19] + 8ULL;
    goto L_9b888;
L_9b9a0:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 40));
    PB_LDR(cpu->regs[20], (cpu->regs[0] + 24));
    if ((((uint32_t)(cpu->regs[3])))!=0) goto L_9b9e0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9b9dcULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x2273c0ULL);
    cpu->regs[3] = cpu->regs[0];
L_9b9e0:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 0));
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 112)); PB_LDR(cpu->regs[4], (cpu->regs[2] + 112) + 8);
    cpu->regs[0] = cpu->regs[0] + 320ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(40, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[1] + 368ULL;
    PB_LDRW(cpu->regs[1], (cpu->regs[2] + 16));
    { PB_CALL(41, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[1] + 408ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 32));
    { PB_CALL(42, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[2] = cpu->regs[0];
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[1] + 448ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 32));
    { PB_CALL(43, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    cpu->regs[30] = PB_BASE + 0x9ba54ULL; PB_CALL(44, cpu, tlb, PB_BASE + 0x1ab164ULL);
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 24));
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 16));
    FLAG_CMP(cpu->regs[0], 1ULL);
    if (FLAG_NE) goto L_9ba80;
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x29f000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 3704ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    { PB_CALL(45, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_9ba80:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = PB_BASE + 0x2a0000ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    cpu->regs[0] = cpu->regs[0] + 760ULL;
    { PB_CALL(46, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 480ULL;
    { PB_CALL(47, cpu, tlb, PB_BASE + 0x81608ULL); return; };
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 520ULL;
    { PB_CALL(48, cpu, tlb, PB_BASE + 0x81608ULL); return; };
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 112)); PB_LDR(cpu->regs[1], (cpu->regs[0] + 112) + 8);
    cpu->regs[2] = cpu->regs[0];
    PB_LDRW(cpu->regs[4], (cpu->regs[0] + 68));
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    cpu->regs[4] = ((uint32_t)((FLAG_NE) ? cpu->regs[4] : (~0ULL)));
    if ((cpu->regs[3])==0) goto L_9badc;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 28) & 1)) goto L_9badc;
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 552ULL;
    { PB_CALL(49, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_9badc:
    cpu->regs[3] = cpu->regs[4];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 600ULL;
    { PB_CALL(50, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 16));
    cpu->regs[1] = cpu->regs[0];
    if ((cpu->regs[3])!=0) goto L_9bb04;
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 648ULL;
    { PB_CALL(51, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
L_9bb04:
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 8));
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 672ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    { PB_CALL(52, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[2])!=0) goto L_9bb38;
    cpu->regs[3] = PB_BASE + 0x299000ULL;
    cpu->regs[2] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = cpu->regs[3] + 240ULL;
    cpu->regs[2] = cpu->regs[2] + 1504ULL;
    goto L_9bb40;
L_9bb38:
    cpu->regs[3] = PB_BASE + 0x2a1000ULL;
    cpu->regs[3] = cpu->regs[3] + 888ULL;
L_9bb40:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = PB_BASE + 0x2a3000ULL;
    cpu->regs[0] = cpu->regs[0] + 712ULL;
    { PB_CALL(53, cpu, tlb, PB_BASE + 0x1abcc0ULL); return; };
}
