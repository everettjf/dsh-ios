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

void ft__PyCrossInterpreterData_UnregisterClass(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x80c28ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_LDR(cpu->regs[1], (cpu->regs[1] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 168));
    PB_LDR(cpu->regs[19], (cpu->regs[1] + 16));
    PB_STR((SP + 32), cpu->regs[21]);
    if (((cpu->regs[0] >> 9) & 1)) goto L_80c48;
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 96));
    cpu->regs[19] = cpu->regs[19] + 72ULL;
    goto L_80c50;
L_80c48:
    cpu->regs[19] = cpu->regs[19] + (93ULL << 12);
    cpu->regs[19] = cpu->regs[19] + 2304ULL;
L_80c50:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[1] = 1ULL;
    cpu->regs[21] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x80c60ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x17f520ULL);
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x80c6cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x809ccULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_80cb4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 32), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_80cb0;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0)); PB_LDR(cpu->regs[0], (cpu->regs[20] + 0) + 8);
    if ((cpu->regs[1])==0) goto L_80c94;
    PB_STR((cpu->regs[1] + 8), cpu->regs[0]);
    goto L_80c98;
L_80c94:
    PB_STR((cpu->regs[19] + 8), cpu->regs[0]);
L_80c98:
    if ((cpu->regs[0])==0) goto L_80ca0;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
L_80ca0:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 24));
    cpu->regs[30] = PB_BASE + 0x80ca8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdce4cULL);
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x80cb0ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xd7784ULL);
L_80cb0:
    cpu->regs[21] = 1ULL;
L_80cb4:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[30] = PB_BASE + 0x80cbcULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x17faa0ULL);
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 40));
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[1])==0) goto L_80cec;
    cpu->regs[30] = PB_BASE + 0x80cecULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x13f6ecULL);
L_80cec:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x80cf4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcd00ULL);
    cpu->regs[30] = PB_BASE + 0x80cf8ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x22b880ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x80d00ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 8));
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 320));
    cpu->regs[30] = PB_BASE + 0x80d10ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_80d34;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_80d34;
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(12, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_80d34:
    PB_LDR(cpu->regs[19], (SP + 16));
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_80d5c;
    cpu->regs[30] = PB_BASE + 0x80d5cULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x13f6ecULL);
L_80d5c:
    PB_LDR(cpu->regs[20], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 320));
    cpu->regs[30] = PB_BASE + 0x80d6cULL; PB_CALL(14, cpu, tlb, cpu->regs[1]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_80d90;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_80d90;
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    { PB_CALL(15, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_80d90:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x80db8ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x1fc8e0ULL);
    cpu->regs[6] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_80df4;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_80dd0;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 40));
    goto L_80dd8;
L_80dd0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
L_80dd8:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    if ((cpu->regs[2])==0) goto L_80de8;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    goto L_80df0;
L_80de8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3336));
L_80df0:
    cpu->regs[30] = PB_BASE + 0x80df4ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x1fdda0ULL);
L_80df4:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[6];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3800ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x80e24ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
    cpu->regs[2] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16)); PB_LDR(cpu->regs[3], (cpu->regs[0] + 16) + 8);
    FLAG_CMP(cpu->regs[1], 1ULL);
    if (FLAG_LE) goto L_80e70;
    if ((cpu->regs[3])!=0) goto L_80e70;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[4]);
    if (FLAG_NE) goto L_80e70;
    PB_LDR(cpu->regs[4], (cpu->regs[2] + 56));
    if ((cpu->regs[4])!=0) goto L_80e70;
    PB_LDRW(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[2] + 24), cpu->regs[1]);
    cpu->regs[3] = ((uint32_t)(cpu->regs[3] + 1ULL)); FLAG_CMP(cpu->regs[3], 0);
    if (FLAG_EQ) goto L_80e84;
    PB_STRW((cpu->regs[0] + 0), cpu->regs[3]);
    goto L_80e84;
L_80e70:
    cpu->regs[4] = cpu->regs[3] + cpu->regs[1];
    PB_STR((cpu->regs[2] + 24), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[0] + 32ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[3];
    { PB_CALL(19, cpu, tlb, PB_BASE + 0xe9c70ULL); return; };
L_80e84:
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 16));
    cpu->regs[30] = PB_BASE + 0x80ea4ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1fc8e0ULL);
    cpu->regs[6] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_80ee0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_80ebc;
    PB_LDR(cpu->regs[0], (cpu->regs[6] + 40));
    goto L_80ec4;
L_80ebc:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
L_80ec4:
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    if ((cpu->regs[2])==0) goto L_80ed4;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
    goto L_80edc;
L_80ed4:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3336));
L_80edc:
    cpu->regs[30] = PB_BASE + 0x80ee0ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1f6100ULL);
L_80ee0:
    PB_LDR(cpu->regs[19], (SP + 16));
    cpu->regs[0] = cpu->regs[6];
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
    SP += -32; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 16));
    cpu->regs[30] = PB_BASE + 0x80f0cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1fc8e0ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_80f48;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    if ((cpu->regs[0])==0) goto L_80f24;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
    goto L_80f2c;
L_80f24:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
L_80f2c:
    PB_LDR(cpu->regs[2], (cpu->regs[20] + 16));
    if ((cpu->regs[2])==0) goto L_80f3c;
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 40));
    goto L_80f44;
L_80f3c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3336));
L_80f44:
    cpu->regs[30] = PB_BASE + 0x80f48ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x80f58ULL);
L_80f48:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 32;
    return;
L_80f58:
    cpu->regs[9] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[9], (cpu->regs[9] + 2272));
    cpu->regs[3] = 0ULL;
    cpu->regs[8] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[8], (cpu->regs[8] + 3472));
    cpu->regs[7] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[7], (cpu->regs[7] + 3240));
L_80f74:
    FLAG_CMP(cpu->regs[3], cpu->regs[2]);
    if (FLAG_GE) goto L_80fa8;
    PB_LDRB(cpu->regs[5], (cpu->regs[1] + cpu->regs[3]));
    PB_LDRB(cpu->regs[4], (cpu->regs[1] + cpu->regs[3]));
    PB_LDRW(cpu->regs[6], (cpu->regs[9] + (cpu->regs[5] << 2)));
    if (!((cpu->regs[6] >> 0) & 1)) goto L_80f94;
    PB_LDRB(cpu->regs[4], (cpu->regs[7] + cpu->regs[5]));
    goto L_80f9c;
L_80f94:
    if (!((cpu->regs[6] >> 1) & 1)) goto L_80f9c;
    PB_LDRB(cpu->regs[4], (cpu->regs[8] + cpu->regs[5]));
L_80f9c:
    PB_STRB((cpu->regs[0] + cpu->regs[3]), cpu->regs[4]);
    cpu->regs[3] = cpu->regs[3] + 1ULL;
    goto L_80f74;
L_80fa8:
    return;
    { PB_CALL(24, cpu, tlb, PB_BASE + 0x235c8cULL); return; };
}
