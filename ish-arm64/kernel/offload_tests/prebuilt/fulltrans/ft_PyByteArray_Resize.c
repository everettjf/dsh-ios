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

void ft_PyByteArray_Resize(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_NE) goto L_1e6c4c;
L_1e6c3c:
    cpu->regs[0] = 0ULL;
L_1e6c40:
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_1e6c4c:
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 48), cpu->regs[23]);
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 40)); PB_LDR(cpu->regs[0], (cpu->regs[19] + 40) + 8);
    PB_LDR(cpu->regs[23], (cpu->regs[19] + 24)); PB_LDR(cpu->regs[22], (cpu->regs[19] + 24) + 8);
    cpu->regs[30] = PB_BASE + 0x1e6c64ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1e70a4ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_1e6d7c;
    cpu->regs[0] = cpu->regs[21] - cpu->regs[22];
    cpu->regs[22] = cpu->regs[20] + 1ULL;
    cpu->regs[1] = cpu->regs[0] + cpu->regs[22];
    FLAG_CMP(cpu->regs[1], cpu->regs[23]);
    if (FLAG_LS) goto L_1e6cc8;
    fr[30] = (double)(cpu->regs[23]);
    fr[29] = 1.125;
    fr[31] = (double)(cpu->regs[20]);
    fr[29] = fr[30] * fr[29];
    FCMP(fr[31], fr[29]);
    if (FLAG_LS) goto L_1e6cec;
    if (((cpu->regs[22] >> 63) & 1)) goto L_1e6d78;
L_1e6c98:
    if ((cpu->regs[0])!=0) goto L_1e6d0c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e6ca8ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x11d0e4ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e6d78;
L_1e6cb0:
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[22]);
    PB_STR((cpu->regs[19] + 32), cpu->regs[21]); PB_STR((cpu->regs[19] + 32) + 8, cpu->regs[21]);
    PB_STRB((cpu->regs[21] + cpu->regs[20]), 0ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e6c3c;
L_1e6cc8:
    FLAG_CMP(cpu->regs[20], cpu->regs[23]);
    if (FLAG_LO) goto L_1e6c98;
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]);
    if ((cpu->regs[20])==0) goto L_1e6d8c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 40));
L_1e6cdc:
    PB_STRB((cpu->regs[0] + cpu->regs[20]), 0ULL);
    PB_LDR(cpu->regs[23], (SP + 48));
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e6c3c;
L_1e6cec:
    cpu->regs[22] = cpu->regs[20] + (cpu->regs[20] >> 3);
    FLAG_CMP(cpu->regs[20], 8ULL);
    if (FLAG_LS) goto L_1e6d04;
    cpu->regs[22] = cpu->regs[22] + 6ULL;
    if (!((cpu->regs[22] >> 63) & 1)) goto L_1e6c98;
    goto L_1e6d78;
L_1e6d04:
    cpu->regs[22] = cpu->regs[22] + 3ULL;
    goto L_1e6c98;
L_1e6d0c:
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x1e6d14ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xd8e60ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e6d78;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    if ((cpu->regs[2])==0) goto L_1e6d6c;
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 40));
L_1e6d28:
    FLAG_CMP(cpu->regs[2], cpu->regs[20]);
    cpu->regs[2] = (FLAG_LS) ? cpu->regs[2] : cpu->regs[20];
    FLAG_CMP(cpu->regs[21], cpu->regs[1]);
    if (FLAG_LO) goto L_1e6d5c;
    if (FLAG_LS) goto L_1e6d48;
    cpu->regs[0] = cpu->regs[1] + cpu->regs[2];
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_LO) goto L_1e6d68;
L_1e6d48:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1e6d50ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x7c090ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[30] = PB_BASE + 0x1e6d58ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdfce0ULL);
    goto L_1e6cb0;
L_1e6d5c:
    cpu->regs[0] = cpu->regs[21] + cpu->regs[2];
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_HS) goto L_1e6d48;
L_1e6d68:
    __builtin_trap();
L_1e6d6c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3336));
    goto L_1e6d28;
L_1e6d78:
    cpu->regs[30] = PB_BASE + 0x1e6d7cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x22d780ULL);
L_1e6d7c:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    goto L_1e6c40;
L_1e6d8c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3336));
    goto L_1e6cdc;
    /* nop */
    /* nop */
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1e6dbcULL; PB_CALL(7, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_LDR(cpu->regs[19], (cpu->regs[1] + cpu->regs[0]));
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    cpu->regs[0] = 57792ULL;
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), 0ULL);
    cpu->regs[0] = cpu->regs[20] + cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x1e6de4ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x1e6fa0ULL);
    cpu->regs[1] = 57888ULL;
    cpu->regs[0] = cpu->regs[20] + cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x1e6df0ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x1e6fa0ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 96));
    PB_STR((cpu->regs[19] + 96), cpu->regs[21]);
    PB_LDR(cpu->regs[21], (SP + 32));
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    { PB_CALL(10, cpu, tlb, PB_BASE + 0x18d760ULL); return; };
    SP = SP - 64ULL;
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_STR((SP + 16), cpu->regs[29]); PB_STR((SP + 16) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 16ULL;
    PB_STR((SP + 32), cpu->regs[19]); PB_STR((SP + 32) + 8, cpu->regs[20]);
    PB_LDRW(cpu->regs[2], (cpu->regs[0] + 16));
    PB_LDR(cpu->regs[3], (cpu->regs[1] + 0));
    PB_STR((SP + 8), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(0ULL)));
    if (FLAG_LE) goto L_1e6f80;
    PB_LDRW(cpu->regs[1], (cpu->regs[0] + 20));
    cpu->regs[19] = cpu->regs[0];
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_1e6f60;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 192));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 120));
    FLAG_CMP(cpu->regs[2], cpu->regs[1]);
    if (FLAG_NE) goto L_1e6f48;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 168));
    if ((cpu->regs[1])==0) goto L_1e6ed4;
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 16));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e6f08;
L_1e6e68:
    PB_LDRB(cpu->regs[1], (cpu->regs[19] + 93));
    cpu->regs[0] = cpu->regs[19];
    PB_STRB((cpu->regs[19] + 95), cpu->regs[1]);
    cpu->regs[30] = PB_BASE + 0x1e6e78ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x157930ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e6f20;
    PB_LDR(cpu->regs[4], (cpu->regs[19] + 32));
    cpu->regs[1] = 44840ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 0), cpu->regs[4]);
    cpu->regs[0] = cpu->regs[0] + cpu->regs[1];
    cpu->regs[1] = SP;
    cpu->regs[30] = PB_BASE + 0x1e6ea8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x147564ULL);
L_1e6ea8:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 8));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_1e6f28;
    PB_LDR(cpu->regs[29], (SP + 16)); PB_LDR(cpu->regs[30], (SP + 16) + 8);
    PB_LDR(cpu->regs[19], (SP + 32)); PB_LDR(cpu->regs[20], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1e6ed4:
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e6edcULL; PB_CALL(13, cpu, tlb, PB_BASE + 0x1e6ba0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_1e6f20;
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1e6eecULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x1227a0ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    cpu->regs[21] = cpu->regs[0];
    if (!((cpu->regs[1] >> 31) & 1)) goto L_1e6f30;
L_1e6ef8:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(0ULL)));
    PB_LDR(cpu->regs[21], (SP + 48));
    if (FLAG_LT) goto L_1e6f20;
    if (FLAG_EQ) goto L_1e6e68;
L_1e6f08:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3800ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e6f20ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_1e6f20:
    cpu->regs[0] = 0ULL;
    goto L_1e6ea8;
L_1e6f28:
    PB_STR((SP + 48), cpu->regs[21]);
    cpu->regs[30] = PB_BASE + 0x1e6f30ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e6f30:
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_1e6ef8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x1e6f44ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e6ef8;
L_1e6f48:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3664));
    cpu->regs[30] = PB_BASE + 0x1e6f54ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x93a2cULL);
    if ((cpu->regs[0])!=0) goto L_1e6e68;
    cpu->regs[0] = 0ULL;
    goto L_1e6ea8;
L_1e6f60:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[1] = cpu->regs[1] + 2232ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e6f78ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1e6ea8;
L_1e6f80:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2976));
    cpu->regs[1] = PB_BASE + 0x28e000ULL;
    cpu->regs[1] = cpu->regs[1] + 3864ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e6f98ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    goto L_1e6ea8;
L_1e6fa0:
    SP = SP - 64ULL;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3080));
    cpu->regs[1] = SP + 8ULL;
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_STR((SP + 48), cpu->regs[19]);
    PB_LDR(cpu->regs[3], (cpu->regs[2] + 0));
    PB_STR((SP + 24), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1e6fccULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x1e3100ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1e709c;
L_1e6fd4:
    PB_LDR(cpu->regs[19], (SP + 8));
    if ((cpu->regs[19])==0) goto L_1e7020;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    cpu->regs[4] = 44840ULL;
    cpu->regs[1] = SP + 16ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + cpu->regs[4];
    cpu->regs[2] = 9223372036854775809ULL;
    PB_STR((SP + 16), cpu->regs[19]);
    cpu->regs[30] = PB_BASE + 0x1e7000ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x147564ULL);
    if ((cpu->regs[0])==0) goto L_1e7094;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    if (!((cpu->regs[2] >> 31) & 1)) goto L_1e706c;
L_1e700c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1e7020;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_1e704c;
L_1e7020:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_1e7068;
    PB_LDR(cpu->regs[19], (SP + 48));
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 64ULL;
    return;
L_1e704c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_EQ) goto L_1e7080;
L_1e7068:
    cpu->regs[30] = PB_BASE + 0x1e706cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x7c170ULL);
L_1e706c:
    cpu->regs[2] = cpu->regs[2] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[2]);
    if ((cpu->regs[2])!=0) goto L_1e700c;
    cpu->regs[30] = PB_BASE + 0x1e707cULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1e700c;
L_1e7080:
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 48));
    SP = SP + 64ULL;
    { PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL); return; };
L_1e7094:
    cpu->regs[30] = PB_BASE + 0x1e7098ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1e700c;
L_1e709c:
    cpu->regs[30] = PB_BASE + 0x1e70a0ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0x121fa0ULL);
    goto L_1e6fd4;
L_1e70a4:
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_GT) goto L_1e70b4;
    cpu->regs[0] = 1ULL;
    return;
L_1e70b4:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2792));
    SP += -16; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = PB_BASE + 0x293000ULL;
    cpu->regs[29] = SP;
    cpu->regs[1] = cpu->regs[1] + 3464ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1e70d4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x1d5940ULL);
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 16;
    return;
}
