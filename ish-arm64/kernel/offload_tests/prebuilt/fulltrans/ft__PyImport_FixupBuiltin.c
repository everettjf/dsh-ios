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

void ft__PyImport_FixupBuiltin(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -48; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]);
    cpu->regs[21] = cpu->regs[2];
    cpu->regs[30] = PB_BASE + 0x190960ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0xde9e0ULL);
    if ((cpu->regs[0])==0) goto L_1909e0;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[1] = cpu->regs[0];
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x190978ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xe97e4ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_1909d8;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[20] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x190990ULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x1909e8ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_1909cc;
L_190998:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_1909b4;
L_1909a0:
    PB_LDR(cpu->regs[21], (SP + 32));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 48;
    return;
L_1909b4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_1909a0;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1909c8ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_1909a0;
L_1909cc:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x1909d8ULL; PB_CALL(5, cpu, tlb, PB_BASE + 0x144960ULL);
L_1909d8:
    cpu->regs[20] = 4294967295ULL;
    goto L_190998;
L_1909e0:
    cpu->regs[20] = 4294967295ULL;
    goto L_1909a0;
L_1909e8:
    SP = SP - 96ULL;
    cpu->regs[3] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 3080));
    PB_STR((SP + 32), cpu->regs[29]); PB_STR((SP + 32) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 32ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 0));
    PB_STR((SP + 24), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    if ((cpu->regs[0])==0) goto L_190cb4;
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    cpu->regs[21] = cpu->regs[1];
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3536));
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[30] = PB_BASE + 0x190a2cULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe270cULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_190cac;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x190a38ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x190cccULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_190c4c;
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x190a54ULL; PB_CALL(8, cpu, tlb, cpu->regs[1]);
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[2] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[19];
    PB_LDR(cpu->regs[23], (cpu->regs[3] + cpu->regs[0]));
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 16));
    cpu->regs[30] = PB_BASE + 0x190a6cULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x190d00ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_190c38;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_190bf8;
    FLAG_CMP(cpu->regs[21], cpu->regs[22]);
    if (FLAG_NE) goto L_190b54;
    cpu->regs[1] = PB_BASE + 0x282000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 3624ULL;
    cpu->regs[30] = PB_BASE + 0x190a94ULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xe9950ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_190b40;
L_190a98:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
L_190aa0:
    cpu->regs[1] = 1ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1920));
    cpu->regs[30] = PB_BASE + 0x190aacULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x17f520ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1928));
    if ((cpu->regs[0])==0) goto L_190bac;
L_190ab4:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x190ac0ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x190e28ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_190bf0;
    cpu->regs[1] = cpu->regs[0];
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1928));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 24));
    cpu->regs[30] = PB_BASE + 0x190ad8ULL; PB_CALL(13, cpu, tlb, cpu->regs[2]);
    if ((cpu->regs[0])!=0) goto L_190c14;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1928));
    cpu->regs[2] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x190aecULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xd8a64ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_190c6c;
L_190af4:
    cpu->regs[0] = 4294967295ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
L_190afc:
    cpu->regs[19] = 0ULL;
L_190b00:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 1920));
    cpu->regs[30] = PB_BASE + 0x190b08ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x17faa0ULL);
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[23], (SP + 80));
L_190b18:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 24));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_190c28;
    PB_LDR(cpu->regs[29], (SP + 32)); PB_LDR(cpu->regs[30], (SP + 32) + 8);
    SP = SP + 96ULL;
    return;
L_190b40:
    cpu->regs[1] = PB_BASE + 0x283000ULL;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 136ULL;
    cpu->regs[30] = PB_BASE + 0x190b50ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xe9950ULL);
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_190a98;
L_190b54:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    if ((cpu->regs[0])!=0) goto L_190c7c;
L_190b5c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x190b64ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x18fc40ULL);
    if ((cpu->regs[0])==0) goto L_190c38;
    cpu->regs[30] = PB_BASE + 0x190b6cULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x18fc80ULL);
    PB_STR((cpu->regs[19] + 32), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_190c38;
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_190aa0;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 56));
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_190aa0;
L_190b98:
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 0ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_190b18;
L_190bac:
    cpu->regs[6] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[6], (cpu->regs[6] + 2808));
    cpu->regs[4] = SP;
    cpu->regs[5] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[5], (cpu->regs[5] + 3120));
    cpu->regs[2] = PB_BASE + 0x1eb000ULL;
    cpu->regs[1] = PB_BASE + 0x227000ULL;
    cpu->regs[2] = cpu->regs[2] + 3488ULL;
    cpu->regs[1] = cpu->regs[1] + 2028ULL;
    cpu->regs[0] = PB_BASE + 0x190000ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 3968ULL;
    PB_STR((SP + 0), cpu->regs[6]); PB_STR((SP + 0) + 8, cpu->regs[5]);
    cpu->regs[30] = PB_BASE + 0x190be4ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x1825a0ULL);
    PB_STR((cpu->regs[20] + 1928), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_190ab4;
    cpu->regs[30] = PB_BASE + 0x190bf0ULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x22d780ULL);
L_190bf0:
    cpu->regs[19] = 4294967295ULL;
    goto L_190b00;
L_190bf8:
    cpu->regs[20] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[20], (cpu->regs[20] + 2248));
    PB_LDR(cpu->regs[1], (cpu->regs[23] + 16));
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 48));
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_EQ) goto L_190aa0;
    goto L_190b98;
L_190c14:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 24));
    if ((cpu->regs[1])==0) goto L_190c9c;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x190c24ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xd7784ULL);
    goto L_190afc;
L_190c28:
    PB_STR((SP + 48), cpu->regs[19]); PB_STR((SP + 48) + 8, cpu->regs[20]);
    PB_STR((SP + 64), cpu->regs[21]); PB_STR((SP + 64) + 8, cpu->regs[22]);
    PB_STR((SP + 80), cpu->regs[23]);
    cpu->regs[30] = PB_BASE + 0x190c38ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x7c170ULL);
L_190c38:
    PB_LDR(cpu->regs[23], (SP + 80));
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_190b18;
L_190c4c:
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = 1183ULL;
    cpu->regs[0] = cpu->regs[0] + 920ULL;
    cpu->regs[30] = PB_BASE + 0x190c5cULL; PB_CALL(23, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
    goto L_190b18;
L_190c6c:
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x190c74ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0xd7784ULL);
    cpu->regs[30] = PB_BASE + 0x190c78ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0x22d780ULL);
    goto L_190bf0;
L_190c7c:
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    PB_STR((cpu->regs[19] + 32), 0ULL);
    if (((cpu->regs[1] >> 31) & 1)) goto L_190b5c;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_190b5c;
    cpu->regs[30] = PB_BASE + 0x190c98ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_190b5c;
L_190c9c:
    PB_STR((cpu->regs[0] + 24), cpu->regs[19]);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x190ca8ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xd7784ULL);
    goto L_190af4;
L_190cac:
    PB_LDR(cpu->regs[19], (SP + 48)); PB_LDR(cpu->regs[20], (SP + 48) + 8);
    PB_LDR(cpu->regs[21], (SP + 64)); PB_LDR(cpu->regs[22], (SP + 64) + 8);
L_190cb4:
    cpu->regs[0] = PB_BASE + 0x284000ULL;
    cpu->regs[1] = 1177ULL;
    cpu->regs[0] = cpu->regs[0] + 920ULL;
    cpu->regs[30] = PB_BASE + 0x190cc4ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0x9bb50ULL);
    cpu->regs[0] = 4294967295ULL;
    goto L_190b18;
}
