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

void ft__PyCrossInterpreterData_RegisterClass(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (((cpu->regs[0] >> 31) & 1)) goto L_807f0;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 400ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x807ecULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11f220ULL);
    goto L_80810;
L_807f0:
    cpu->regs[21] = cpu->regs[1];
    if ((cpu->regs[1])!=0) goto L_80818;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[1] = cpu->regs[1] + 432ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x80810ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11f220ULL);
L_80810:
    cpu->regs[20] = 4294967295ULL;
    goto L_808a8;
L_80818:
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x8082cULL; PB_CALL(3, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 168));
    PB_LDR(cpu->regs[0], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 16));
    if (((cpu->regs[2] >> 9) & 1)) goto L_80848;
    PB_LDR(cpu->regs[19], (cpu->regs[22] + 96));
    cpu->regs[19] = cpu->regs[19] + 72ULL;
    goto L_80850;
L_80848:
    cpu->regs[19] = cpu->regs[22] + (93ULL << 12);
    cpu->regs[19] = cpu->regs[19] + 2304ULL;
L_80850:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = 1ULL;
    cpu->regs[30] = PB_BASE + 0x8085cULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x17f520ULL);
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x80868ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x808bcULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x80874ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x809ccULL);
    if ((cpu->regs[0])==0) goto L_8088c;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[20] = 0ULL;
    cpu->regs[1] = cpu->regs[1] + 1ULL;
    PB_STR((cpu->regs[0] + 32), cpu->regs[1]);
    goto L_808a0;
L_8088c:
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x8089cULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x80a64ULL);
    cpu->regs[20] = cpu->regs[0];
L_808a0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x808a8ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x17faa0ULL);
L_808a8:
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_808bc:
    cpu->regs[0] = cpu->regs[0] + (93ULL << 12);
    cpu->regs[0] = cpu->regs[0] + 2304ULL;
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_809c8;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 8));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[1];
    if ((cpu->regs[0])!=0) goto L_809bc;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2760));
    cpu->regs[30] = PB_BASE + 0x808f0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x19878cULL);
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = PB_BASE + 0x87000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1984ULL;
    cpu->regs[30] = PB_BASE + 0x80904ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x80a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_80920;
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1896ULL;
    cpu->regs[1] = cpu->regs[1] + 456ULL;
    cpu->regs[30] = PB_BASE + 0x80920ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x91ebcULL);
L_80920:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2280));
    cpu->regs[2] = PB_BASE + 0x9e000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 2596ULL;
    cpu->regs[30] = PB_BASE + 0x80938ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x80a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_80954;
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1896ULL;
    cpu->regs[1] = cpu->regs[1] + 512ULL;
    cpu->regs[30] = PB_BASE + 0x80954ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x91ebcULL);
L_80954:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2392));
    cpu->regs[2] = PB_BASE + 0xa2000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 444ULL;
    cpu->regs[30] = PB_BASE + 0x8096cULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x80a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_80988;
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1896ULL;
    cpu->regs[1] = cpu->regs[1] + 568ULL;
    cpu->regs[30] = PB_BASE + 0x80988ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x91ebcULL);
L_80988:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2520));
    cpu->regs[2] = PB_BASE + 0x90000ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[2] + 1640ULL;
    cpu->regs[30] = PB_BASE + 0x809a0ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x80a64ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_809bc;
    cpu->regs[0] = PB_BASE + 0x2b8000ULL;
    cpu->regs[0] = cpu->regs[0] + 2096ULL;
    cpu->regs[1] = PB_BASE + 0x299000ULL;
    cpu->regs[0] = cpu->regs[0] + 1896ULL;
    cpu->regs[1] = cpu->regs[1] + 624ULL;
    cpu->regs[30] = PB_BASE + 0x809bcULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x91ebcULL);
L_809bc:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_809c8:
    return;
L_809cc:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[1];
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 8));
L_809e8:
    if ((cpu->regs[19])==0) goto L_80a50;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    if ((cpu->regs[0])==0) goto L_80a38;
    cpu->regs[30] = PB_BASE + 0x809f8ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1a1decULL);
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 2760));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_80a38;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0)); PB_LDR(cpu->regs[20], (cpu->regs[19] + 0) + 8);
    if ((cpu->regs[0])==0) goto L_80a18;
    PB_STR((cpu->regs[0] + 8), cpu->regs[20]);
    goto L_80a1c;
L_80a18:
    PB_STR((cpu->regs[21] + 8), cpu->regs[20]);
L_80a1c:
    if ((cpu->regs[20])==0) goto L_80a24;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
L_80a24:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 24));
    cpu->regs[30] = PB_BASE + 0x80a2cULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x80a34ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0xd7784ULL);
    goto L_80a48;
L_80a38:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[0], cpu->regs[22]);
    if (FLAG_EQ) goto L_80a50;
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
L_80a48:
    cpu->regs[19] = cpu->regs[20];
    goto L_809e8;
L_80a50:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_80a64:
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[0] = 48ULL;
    cpu->regs[30] = PB_BASE + 0x80a88ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xd7700ULL);
    if ((cpu->regs[0])==0) goto L_80ac8;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    PB_STR((cpu->regs[19] + 16), 0ULL); PB_STR((cpu->regs[19] + 16) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 0), 0ULL); PB_STR((cpu->regs[19] + 0) + 8, 0ULL);
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    PB_STR((cpu->regs[19] + 32), cpu->regs[1]); PB_STR((cpu->regs[19] + 32) + 8, cpu->regs[22]);
    if (!((cpu->regs[0] >> 9) & 1)) goto L_80ad0;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x80ab8ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xe1700ULL);
    PB_STR((cpu->regs[19] + 24), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_80ad0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x80ac8ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xd7784ULL);
L_80ac8:
    cpu->regs[0] = 4294967295ULL;
    goto L_80ae8;
L_80ad0:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 8));
    PB_STR((cpu->regs[19] + 8), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_80ae0;
    PB_STR((cpu->regs[0] + 0), cpu->regs[19]);
L_80ae0:
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[21] + 8), cpu->regs[19]);
L_80ae8:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
}
