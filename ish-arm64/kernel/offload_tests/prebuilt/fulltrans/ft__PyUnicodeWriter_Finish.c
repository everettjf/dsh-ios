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

void ft__PyUnicodeWriter_Finish(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    PB_STR((SP + 16), cpu->regs[19]);
    if ((cpu->regs[1])==0) goto L_11ce90;
    PB_LDRB(cpu->regs[2], (cpu->regs[0] + 53));
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[0] + 0), 0ULL);
    if ((((uint32_t)(cpu->regs[2])))!=0) goto L_11ced8;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    cpu->regs[0] = cpu->regs[19];
    if (FLAG_EQ) goto L_11ce84;
    cpu->regs[30] = PB_BASE + 0x11ce80ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x11cf20ULL);
    if ((cpu->regs[0])==0) goto L_11cee8;
L_11ce84:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(2, cpu, tlb, PB_BASE + 0xee10cULL); return; };
L_11ce90:
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if ((cpu->regs[2])==0) goto L_11ceb8;
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[0] + 0), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_11ceb8;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_11ceb8;
    cpu->regs[0] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x11ceb8ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_11ceb8:
    cpu->regs[19] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 2248));
    cpu->regs[1] = cpu->regs[19] + (4ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 8080));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_11cf04;
L_11ced0:
    cpu->regs[0] = 24464ULL;
    cpu->regs[19] = cpu->regs[19] + cpu->regs[0];
L_11ced8:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_11cee8:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_11cefc;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_11cf0c;
L_11cefc:
    cpu->regs[19] = 0ULL;
    goto L_11ced8;
L_11cf04:
    PB_STRW((cpu->regs[1] + 8080), cpu->regs[0]);
    goto L_11ced0;
L_11cf0c:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[19] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x11cf18ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_11ced8;
    /* nop */
L_11cf20:
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[1];
    cpu->regs[20] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[3] = ((cpu->regs[1] >> 2) & 0x7ULL);
    cpu->regs[4] = ((uint32_t)(((cpu->regs[1] >> 6) & 0x1ULL)));
    if (!((cpu->regs[1] >> 6) & 1)) goto L_11d05c;
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_NE) goto L_11d074;
    cpu->regs[0] = 18446744073709551575ULL;
    cpu->regs[2] = 40ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
L_11cf58:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[19]);
    if (FLAG_LT) goto L_11d004;
    PB_LDRW(cpu->regs[0], (cpu->regs[20] + 32));
    cpu->regs[3] = cpu->regs[19] * cpu->regs[3] + cpu->regs[3];
    cpu->regs[2] = cpu->regs[3] + cpu->regs[2];
    if (!((cpu->regs[0] >> 6) & 1)) goto L_11d030;
    if (!((cpu->regs[1] >> 5) & 1)) goto L_11d0d4;
L_11cf78:
    if (((cpu->regs[2] >> 63) & 1)) goto L_11cffc;
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[1] = PB_BASE + 0xe5000ULL;
    cpu->regs[21] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[21] + 2248));
    cpu->regs[1] = cpu->regs[1] + 1744ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[21] + 200));
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 176));
    FLAG_CMP(cpu->regs[3], cpu->regs[1]);
    cpu->regs[1] = cpu->regs[20];
    if (FLAG_NE) goto L_11cff0;
    cpu->regs[30] = PB_BASE + 0x11cfa8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe56e0ULL);
    if ((cpu->regs[0])==0) goto L_11cff8;
L_11cfac:
    PB_LDRW(cpu->regs[1], (cpu->regs[21] + 2708));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_11d0a8;
L_11cfb4:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 32));
    cpu->regs[2] = 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    PB_STR((cpu->regs[0] + 16), cpu->regs[19]);
    cpu->regs[2] = ((uint32_t)(((cpu->regs[1] >> 2) & 0x7ULL)));
    if (!((cpu->regs[1] >> 5) & 1)) goto L_11d0cc;
    if (!((cpu->regs[1] >> 6) & 1)) goto L_11d010;
    cpu->regs[1] = cpu->regs[0] + 40ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_NE) goto L_11d01c;
L_11cfdc:
    PB_STRB((cpu->regs[1] + cpu->regs[19]), 0ULL);
    PB_LDR(cpu->regs[21], (SP + 32));
L_11cfe4:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_11cff0:
    cpu->regs[30] = PB_BASE + 0x11cff4ULL; PB_CALL(6, cpu, tlb, cpu->regs[3]);
    if ((cpu->regs[0])!=0) goto L_11cfac;
L_11cff8:
    PB_LDR(cpu->regs[21], (SP + 32));
L_11cffc:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x11d004ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x187e20ULL);
L_11d004:
    cpu->regs[30] = PB_BASE + 0x11d008ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x22d780ULL);
    cpu->regs[0] = 0ULL;
    goto L_11cfe4;
L_11d010:
    cpu->regs[1] = cpu->regs[0] + 56ULL;
L_11d014:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_11cfdc;
L_11d01c:
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_11d088;
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STRH((cpu->regs[1] + (cpu->regs[19] << 1)), 0ULL);
    goto L_11cfe4;
L_11d030:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    if ((cpu->regs[0])==0) goto L_11cf78;
    if (((cpu->regs[1] >> 5) & 1)) goto L_11d0b8;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 56));
L_11d040:
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_11cf78;
    PB_STR((SP + 56), cpu->regs[2]);
    cpu->regs[30] = PB_BASE + 0x11d050ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0xdfce0ULL);
    PB_STR((cpu->regs[20] + 40), 0ULL); PB_STR((cpu->regs[20] + 40) + 8, 0ULL);
    PB_LDR(cpu->regs[2], (SP + 56));
    goto L_11cf78;
L_11d05c:
    FLAG_CMP(cpu->regs[3], 1ULL);
    if (FLAG_NE) goto L_11d094;
    cpu->regs[0] = 18446744073709551559ULL;
    cpu->regs[2] = 56ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    goto L_11cf58;
L_11d074:
    cpu->regs[0] = 18446744073709551575ULL;
    cpu->regs[2] = 40ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    cpu->regs[0] = (cpu->regs[3] ? cpu->regs[0] / cpu->regs[3] : 0);
    goto L_11cf58;
L_11d088:
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_STRW((cpu->regs[1] + (cpu->regs[19] << 2)), 0ULL);
    goto L_11cfe4;
L_11d094:
    cpu->regs[0] = 18446744073709551559ULL;
    cpu->regs[2] = 56ULL;
    cpu->regs[0] = (cpu->regs[0] & ~(0xffffULL << 48)) | ((0x7fffULL & 0xffff) << 48);
    cpu->regs[0] = (cpu->regs[3] ? cpu->regs[0] / cpu->regs[3] : 0);
    goto L_11cf58;
L_11d0a8:
    PB_STR((SP + 56), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x11d0b0ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[0], (SP + 56));
    goto L_11cfb4;
L_11d0b8:
    FLAG_CMP(((uint32_t)(cpu->regs[4])), ((uint32_t)(0ULL)));
    cpu->regs[3] = cpu->regs[20] + 40ULL;
    cpu->regs[1] = cpu->regs[20] + 56ULL;
    cpu->regs[1] = (FLAG_EQ) ? cpu->regs[1] : cpu->regs[3];
    goto L_11d040;
L_11d0cc:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 56));
    goto L_11d014;
L_11d0d4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    if ((cpu->regs[0])==0) goto L_11cf78;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 56));
    goto L_11d040;
}
