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

void ft_PyImport_Import(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -80; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[1] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x145e54ULL; PB_CALL(1, cpu, tlb, cpu->regs[2]);
    PB_STR((SP + 48), cpu->regs[23]); PB_STR((SP + 48) + 8, cpu->regs[24]);
    cpu->regs[19] = cpu->regs[1] + cpu->regs[0];
    PB_STR((SP + 64), cpu->regs[25]); PB_STR((SP + 64) + 8, cpu->regs[26]);
    PB_LDR(cpu->regs[23], (cpu->regs[1] + cpu->regs[0]));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x145e6cULL; PB_CALL(2, cpu, tlb, PB_BASE + 0xd8bc0ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14613c;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 56));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    if ((cpu->regs[3])==0) goto L_1460ac;
L_145e84:
    PB_LDRB(cpu->regs[0], (cpu->regs[3] + 70));
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(1ULL)));
    if (FLAG_EQ) goto L_145eac;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_LDR(cpu->regs[1], (cpu->regs[3] + 56));
    cpu->regs[2] = cpu->regs[0] + 192ULL;
    do { int32_t _s=0; tlb_read(tlb,(cpu->regs[0] + 176),&_s,4); cpu->regs[0] = (uint64_t)(int64_t)_s; } while(0);
    cpu->regs[0] = cpu->regs[2] + (cpu->regs[0] << 1);
    FLAG_CMP(cpu->regs[1], cpu->regs[0]);
    if (FLAG_LO) goto L_1460a4;
L_145eac:
    PB_LDR(cpu->regs[19], (cpu->regs[3] + 24));
    if ((cpu->regs[19])==0) goto L_1460ac;
    PB_LDRW(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_145ecc;
    PB_STRW((cpu->regs[19] + 0), cpu->regs[0]);
L_145ecc:
    cpu->regs[4] = 26488ULL;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[26] + cpu->regs[4];
    cpu->regs[30] = PB_BASE + 0x145edcULL; PB_CALL(3, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[20] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_146144;
L_145ee4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 8));
    cpu->regs[1] = 29112ULL;
    cpu->regs[1] = cpu->regs[26] + cpu->regs[1];
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 168));
    if (!((cpu->regs[0] >> 29) & 1)) goto L_14611c;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x145f00ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0xe3ac0ULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14615c;
L_145f08:
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    cpu->regs[5] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[1] + 3360ULL;
    cpu->regs[4] = cpu->regs[19];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x145f2cULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xe6d90ULL);
    if ((cpu->regs[0])==0) goto L_145fc0;
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    if (((cpu->regs[3] >> 31) & 1)) goto L_145f44;
    cpu->regs[3] = cpu->regs[3] - 1ULL;
    PB_STR((cpu->regs[0] + 0), cpu->regs[3]);
    if ((cpu->regs[3])==0) goto L_146180;
L_145f44:
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x145f50ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0x11c380ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_146004;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_145fcc;
L_145f60:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_145fe0;
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_145f90;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_145f90;
L_145f7c:
    PB_LDR(cpu->regs[1], (cpu->regs[24] + 8));
    cpu->regs[0] = cpu->regs[24];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x145f8cULL; PB_CALL(7, cpu, tlb, cpu->regs[1]);
L_145f8c:
    if ((cpu->regs[21])==0) goto L_145fa4;
L_145f90:
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_145fa4;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_146070;
L_145fa4:
    cpu->regs[0] = cpu->regs[25];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[23], (SP + 48)); PB_LDR(cpu->regs[24], (SP + 48) + 8);
    PB_LDR(cpu->regs[25], (SP + 64)); PB_LDR(cpu->regs[26], (SP + 64) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 80;
    return;
L_145fc0:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[25] = 0ULL;
    if (((cpu->regs[0] >> 31) & 1)) goto L_145f60;
L_145fcc:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_146044;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_145fec;
L_145fe0:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_146084;
L_145fec:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_145f90;
L_145ff4:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[24] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_145f8c;
    goto L_145f7c;
L_146004:
    PB_LDR(cpu->regs[0], (cpu->regs[23] + 96));
    if ((cpu->regs[0])==0) goto L_146014;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 8));
    if ((cpu->regs[0])!=0) goto L_14602c;
L_146014:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3544));
    cpu->regs[2] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x14602cULL; PB_CALL(8, cpu, tlb, PB_BASE + 0x120824ULL);
L_14602c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    cpu->regs[25] = 0ULL;
    if (((cpu->regs[0] >> 31) & 1)) goto L_146054;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_146054;
L_146044:
    PB_LDR(cpu->regs[1], (cpu->regs[19] + 8));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x146054ULL; PB_CALL(9, cpu, tlb, cpu->regs[1]);
L_146054:
    if ((cpu->regs[20])==0) goto L_146060;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_146100;
L_146060:
    if ((cpu->regs[24])==0) goto L_145f90;
L_146064:
    PB_LDR(cpu->regs[0], (cpu->regs[24] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_145f8c;
    goto L_145ff4;
L_146070:
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 8));
    cpu->regs[0] = cpu->regs[21];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x146080ULL; PB_CALL(10, cpu, tlb, cpu->regs[1]);
    goto L_145fa4;
L_146084:
    cpu->regs[19] = cpu->regs[25];
L_146088:
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 8));
    cpu->regs[0] = cpu->regs[20];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 48));
    cpu->regs[30] = PB_BASE + 0x146098ULL; PB_CALL(11, cpu, tlb, cpu->regs[1]);
L_146098:
    cpu->regs[25] = cpu->regs[19];
    if ((cpu->regs[24])!=0) goto L_146064;
    goto L_145f8c;
L_1460a4:
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 8));
    if ((cpu->regs[3])!=0) goto L_145e84;
L_1460ac:
    cpu->regs[0] = PB_BASE + 0x283000ULL;
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[0] + 136ULL;
    cpu->regs[3] = 0ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[1] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1460c8ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x1c5bc0ULL);
    cpu->regs[25] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_14613c;
    cpu->regs[26] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[26], (cpu->regs[26] + 2248));
    cpu->regs[3] = 26488ULL;
    cpu->regs[2] = cpu->regs[25];
    cpu->regs[0] = PB_BASE + 0x28d000ULL;
    cpu->regs[1] = cpu->regs[26] + cpu->regs[3];
    cpu->regs[0] = cpu->regs[0] + 3352ULL;
    cpu->regs[30] = PB_BASE + 0x1460f0ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xe3f40ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_146134;
    cpu->regs[20] = cpu->regs[25];
    goto L_145ee4;
L_146100:
    cpu->regs[19] = cpu->regs[25];
    cpu->regs[25] = cpu->regs[20];
L_146108:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[25] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_146098;
    cpu->regs[20] = cpu->regs[25];
    goto L_146088;
L_14611c:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x146124ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0xed3ccULL);
    cpu->regs[24] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_145f08;
    cpu->regs[24] = 0ULL;
    goto L_14602c;
L_146134:
    PB_LDR(cpu->regs[0], (cpu->regs[25] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_146150;
L_14613c:
    cpu->regs[25] = 0ULL;
    goto L_145f8c;
L_146144:
    cpu->regs[20] = 0ULL;
    cpu->regs[24] = 0ULL;
    goto L_14602c;
L_146150:
    cpu->regs[19] = 0ULL;
    cpu->regs[24] = 0ULL;
    goto L_146108;
L_14615c:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3544));
    cpu->regs[0] = 29112ULL;
    cpu->regs[24] = 0ULL;
    cpu->regs[2] = cpu->regs[26] + cpu->regs[0];
    cpu->regs[0] = cpu->regs[23];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    cpu->regs[30] = PB_BASE + 0x14617cULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x120824ULL);
    goto L_14602c;
L_146180:
    cpu->regs[30] = PB_BASE + 0x146184ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_145f44;
    SP = SP - 144ULL;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_STR((SP + 80), cpu->regs[29]); PB_STR((SP + 80) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 80ULL;
    PB_STR((SP + 96), cpu->regs[19]); PB_STR((SP + 96) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[3];
    PB_STR((SP + 112), cpu->regs[21]); PB_STR((SP + 112) + 8, cpu->regs[22]);
    PB_STR((SP + 128), cpu->regs[23]);
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 0));
    PB_STR((SP + 72), cpu->regs[4]);
    cpu->regs[4] = 0ULL;
    cpu->regs[0] = cpu->regs[1];
    if ((cpu->regs[3])!=0) goto L_14628c;
    cpu->regs[20] = cpu->regs[2] - 1ULL;
    FLAG_CMP(cpu->regs[2], 0ULL);
    if (FLAG_LE) goto L_146344;
    FLAG_CMP(cpu->regs[1], 0ULL);
    if (FLAG_NE) { FLAG_CMP(cpu->regs[2], 5ULL); } else { FLAG_CMP(0, 1); }
    if (FLAG_GT) goto L_146344;
    PB_LDR(cpu->regs[21], (cpu->regs[1] + 0));
    if ((cpu->regs[20])==0) goto L_146314;
L_1461e0:
    PB_LDR(cpu->regs[19], (cpu->regs[0] + 8));
    if ((cpu->regs[19])==0) goto L_1461f0;
    cpu->regs[20] = cpu->regs[2] - 2ULL; FLAG_CMP(cpu->regs[20], 0);
    if (FLAG_EQ) goto L_1463a0;
L_1461f0:
    PB_LDR(cpu->regs[23], (cpu->regs[0] + 16));
    if ((cpu->regs[23])==0) goto L_1462dc;
    cpu->regs[20] = cpu->regs[20] - 1ULL; FLAG_CMP(cpu->regs[20], 0);
    if (FLAG_EQ) goto L_146394;
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 24));
    if ((cpu->regs[22])==0) goto L_1462ec;
L_146208:
    FLAG_CMP(cpu->regs[20], 1ULL);
    if (FLAG_EQ) goto L_146328;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[1] = SP + 28ULL;
    cpu->regs[30] = PB_BASE + 0x14621cULL; PB_CALL(17, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 28));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_14634c;
L_146228:
    cpu->regs[0] = 2147483648ULL;
    cpu->regs[0] = cpu->regs[4] + cpu->regs[0];
    cpu->regs[1] = 4294967295ULL;
    FLAG_CMP(cpu->regs[0], cpu->regs[1]);
    if (FLAG_HI) goto L_14634c;
    FLAG_CMP(cpu->regs[4], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_146374;
L_146244:
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[2] = cpu->regs[23];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x146258ULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x13b400ULL);
L_146258:
    cpu->regs[1] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 3080));
    PB_LDR(cpu->regs[3], (SP + 72));
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_146324;
    PB_LDR(cpu->regs[23], (SP + 128));
    PB_LDR(cpu->regs[29], (SP + 80)); PB_LDR(cpu->regs[30], (SP + 80) + 8);
    PB_LDR(cpu->regs[19], (SP + 96)); PB_LDR(cpu->regs[20], (SP + 96) + 8);
    PB_LDR(cpu->regs[21], (SP + 112)); PB_LDR(cpu->regs[22], (SP + 112) + 8);
    SP = SP + 144ULL;
    return;
L_14628c:
    PB_LDR(cpu->regs[22], (cpu->regs[3] + 16));
    cpu->regs[22] = cpu->regs[2] + cpu->regs[22];
    cpu->regs[20] = cpu->regs[22] - 1ULL;
L_146298:
    cpu->regs[1] = SP + 32ULL;
    PB_STR((SP + 0), cpu->regs[1]);
    cpu->regs[4] = PB_BASE + 0x51e000ULL;
    cpu->regs[4] = cpu->regs[4] + 3856ULL;
    cpu->regs[1] = cpu->regs[2];
    cpu->regs[3] = cpu->regs[19];
    cpu->regs[4] = cpu->regs[4] + 1904ULL;
    cpu->regs[7] = 0ULL;
    cpu->regs[6] = 5ULL;
    cpu->regs[5] = 1ULL;
    cpu->regs[2] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x1462c8ULL; PB_CALL(19, cpu, tlb, PB_BASE + 0x14bee8ULL);
    if ((cpu->regs[0])==0) goto L_14638c;
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 0));
    if ((cpu->regs[20])==0) goto L_146330;
    cpu->regs[2] = cpu->regs[22];
    goto L_1461e0;
L_1462dc:
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 24));
    if ((cpu->regs[22])==0) goto L_1462f0;
    cpu->regs[23] = 0ULL;
    goto L_146208;
L_1462ec:
    cpu->regs[22] = cpu->regs[23];
L_1462f0:
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[1] = SP + 28ULL;
    cpu->regs[30] = PB_BASE + 0x1462fcULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x129708ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDRW(cpu->regs[1], (SP + 28));
    if ((((uint32_t)(cpu->regs[1])))!=0) goto L_146384;
    cpu->regs[23] = cpu->regs[22];
    cpu->regs[22] = 0ULL;
    goto L_146228;
L_146314:
    cpu->regs[22] = 0ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[4] = 0ULL;
    goto L_146244;
L_146324:
    cpu->regs[30] = PB_BASE + 0x146328ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0x7c170ULL);
L_146328:
    cpu->regs[4] = 0ULL;
    goto L_146244;
L_146330:
    cpu->regs[4] = 0ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[23] = 0ULL;
    cpu->regs[19] = 0ULL;
    goto L_146244;
L_146344:
    cpu->regs[22] = cpu->regs[2];
    goto L_146298;
L_14634c:
    cpu->regs[20] = cpu->regs[22];
    cpu->regs[22] = cpu->regs[23];
L_146354:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2584));
    cpu->regs[23] = cpu->regs[22];
    cpu->regs[1] = PB_BASE + 0x28c000ULL;
    cpu->regs[22] = cpu->regs[20];
    cpu->regs[1] = cpu->regs[1] + 336ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x146374ULL; PB_CALL(22, cpu, tlb, PB_BASE + 0x1d5940ULL);
L_146374:
    cpu->regs[30] = PB_BASE + 0x146378ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xe1f30ULL);
    if ((cpu->regs[0])!=0) goto L_14638c;
    cpu->regs[4] = 4294967295ULL;
    goto L_146244;
L_146384:
    cpu->regs[20] = 0ULL;
    goto L_146354;
L_14638c:
    cpu->regs[0] = 0ULL;
    goto L_146258;
L_146394:
    cpu->regs[4] = 0ULL;
    cpu->regs[22] = 0ULL;
    goto L_146244;
L_1463a0:
    cpu->regs[4] = 0ULL;
    cpu->regs[22] = 0ULL;
    cpu->regs[23] = 0ULL;
    goto L_146244;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 16));
    return;
    /* nop */
    /* nop */
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[3] = cpu->tls_ptr;
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[0];
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 2160));
    cpu->regs[0] = cpu->regs[0] + 2160ULL;
    cpu->regs[30] = PB_BASE + 0x1463e4ULL; PB_CALL(24, cpu, tlb, cpu->regs[4]);
    PB_LDR(cpu->regs[4], (cpu->regs[3] + cpu->regs[0]));
    cpu->regs[3] = cpu->regs[3] + cpu->regs[0];
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 16));
    cpu->regs[5] = cpu->regs[4] + (64ULL << 12);
    PB_LDR(cpu->regs[19], (cpu->regs[5] + 7680));
    if ((cpu->regs[19])==0) goto L_146478;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2248));
    PB_STR((cpu->regs[5] + 7680), 0ULL);
    PB_LDRW(cpu->regs[0], (cpu->regs[0] + 2708));
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_1464a8;
    cpu->regs[0] = 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
L_146418:
    PB_LDR(cpu->regs[3], (cpu->regs[4] + 208));
    PB_LDRW(cpu->regs[0], (cpu->regs[2] + 0));
    PB_STR((cpu->regs[19] + 16), cpu->regs[20]); PB_STR((cpu->regs[19] + 16) + 8, cpu->regs[1]);
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_146460;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_STR((cpu->regs[19] + 32), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 8));
    cpu->regs[1] = cpu->regs[19] - 16ULL;
L_14643c:
    cpu->regs[0] = cpu->regs[0] & 3ULL;
    PB_STR((cpu->regs[2] + 0), cpu->regs[1]);
    cpu->regs[0] = cpu->regs[0] | cpu->regs[2];
    PB_STR((cpu->regs[19] + -16), cpu->regs[3]); PB_STR((cpu->regs[19] + -16) + 8, cpu->regs[0]);
    PB_STR((cpu->regs[3] + 8), cpu->regs[1]);
L_146450:
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
L_146460:
    PB_STRW((cpu->regs[2] + 0), cpu->regs[0]);
    cpu->regs[1] = cpu->regs[19] - 16ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + -8));
    PB_STR((cpu->regs[19] + 32), cpu->regs[2]);
    PB_LDR(cpu->regs[2], (cpu->regs[3] + 8));
    goto L_14643c;
L_146478:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2224));
    PB_STR((SP + 40), cpu->regs[1]); PB_STR((SP + 40) + 8, cpu->regs[2]);
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x14648cULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xd8d60ULL);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[3], (SP + 56));
    PB_LDR(cpu->regs[1], (SP + 40)); PB_LDR(cpu->regs[2], (SP + 40) + 8);
    if ((cpu->regs[0])==0) goto L_1464d4;
    PB_LDR(cpu->regs[0], (cpu->regs[3] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[0] + 16));
    goto L_146418;
L_1464a8:
    cpu->regs[0] = cpu->regs[19];
    PB_STR((SP + 40), cpu->regs[1]); PB_STR((SP + 40) + 8, cpu->regs[2]);
    PB_STR((SP + 56), cpu->regs[3]);
    cpu->regs[30] = PB_BASE + 0x1464b8ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0x98264ULL);
    PB_LDR(cpu->regs[3], (SP + 56));
    cpu->regs[0] = 1ULL;
    PB_LDR(cpu->regs[1], (SP + 40)); PB_LDR(cpu->regs[2], (SP + 40) + 8);
    PB_LDR(cpu->regs[3], (cpu->regs[3] + 0));
    PB_LDR(cpu->regs[4], (cpu->regs[3] + 16));
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    goto L_146418;
L_1464d4:
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_1464e8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_146508;
L_1464e8:
    PB_LDR(cpu->regs[0], (cpu->regs[1] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_146450;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[1] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_146450;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[30] = PB_BASE + 0x146504ULL; PB_CALL(27, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_146450;
L_146508:
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x146510ULL; PB_CALL(28, cpu, tlb, PB_BASE + 0xdcac8ULL);
    PB_LDR(cpu->regs[1], (SP + 40));
    goto L_1464e8;
    /* nop */
    /* nop */
    SP = SP - 96ULL;
    PB_STR((SP + 48), cpu->regs[29]); PB_STR((SP + 48) + 8, cpu->regs[30]);
    cpu->regs[29] = SP + 48ULL;
    PB_STR((SP + 64), cpu->regs[19]); PB_STR((SP + 64) + 8, cpu->regs[20]);
    cpu->regs[19] = cpu->regs[0];
    PB_LDR(cpu->regs[2], (cpu->regs[1] + 8));
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (cpu->regs[0] + 0));
    PB_STR((SP + 40), cpu->regs[3]);
    cpu->regs[3] = 0ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[2] + 96));
    if ((cpu->regs[0])==0) goto L_1465b0;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 264));
    if ((cpu->regs[0])==0) goto L_1465b0;
    cpu->regs[2] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 3880));
    cpu->regs[0] = cpu->regs[1];
    PB_LDR(cpu->regs[1], (cpu->regs[2] + 0));
    cpu->regs[30] = PB_BASE + 0x146570ULL; PB_CALL(29, cpu, tlb, PB_BASE + 0x123dd0ULL);
    cpu->regs[1] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_EQ) goto L_14673c;
    if (((cpu->regs[0] >> 63) & 1)) goto L_14674c;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    cpu->regs[0] = cpu->regs[19];
    if (FLAG_NE) goto L_146778;
L_1465a0:
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    { PB_CALL(30, cpu, tlb, PB_BASE + 0x151828ULL); return; };
L_1465b0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2224));
    FLAG_CMP(cpu->regs[2], cpu->regs[0]);
    if (FLAG_NE) goto L_1467d0;
    cpu->regs[20] = SP + 32ULL;
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[21] = SP + 24ULL;
    cpu->regs[0] = cpu->regs[1];
    cpu->regs[2] = cpu->regs[21];
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = SP + 16ULL;
    cpu->regs[30] = PB_BASE + 0x1465e0ULL; PB_CALL(31, cpu, tlb, PB_BASE + 0x146840ULL);
    if (((cpu->regs[0] >> 31) & 1)) goto L_146820;
    PB_LDR(cpu->regs[22], (SP + 16));
    cpu->regs[2] = cpu->regs[21];
    PB_LDR(cpu->regs[21], (cpu->regs[19] + 16));
    cpu->regs[1] = cpu->regs[20];
    cpu->regs[3] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x146600ULL; PB_CALL(32, cpu, tlb, PB_BASE + 0x146b24ULL);
    cpu->regs[20] = cpu->regs[0];
    FLAG_CMP(cpu->regs[0], 0ULL);
    if (FLAG_LE) goto L_146700;
    PB_LDR(cpu->regs[1], (SP + 32));
    FLAG_CMP(cpu->regs[22], 1ULL);
    if ((cpu->regs[1])!=0) goto L_146668;
    if (FLAG_NE) goto L_14666c;
    FLAG_CMP(cpu->regs[21], cpu->regs[0]);
    if (FLAG_EQ) goto L_146728;
L_146624:
    cpu->regs[2] = cpu->regs[1] + cpu->regs[20];
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x146630ULL; PB_CALL(33, cpu, tlb, PB_BASE + 0x134b80ULL);
    cpu->regs[4] = cpu->regs[0];
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
L_146638:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[2], (SP + 40));
    PB_LDR(cpu->regs[1], (cpu->regs[0] + 0));
    cpu->regs[2] = cpu->regs[2] - cpu->regs[1]; FLAG_CMP(cpu->regs[2], 0);
    cpu->regs[1] = 0ULL;
    if (FLAG_NE) goto L_146778;
    PB_LDR(cpu->regs[29], (SP + 48)); PB_LDR(cpu->regs[30], (SP + 48) + 8);
    cpu->regs[0] = cpu->regs[4];
    PB_LDR(cpu->regs[19], (SP + 64)); PB_LDR(cpu->regs[20], (SP + 64) + 8);
    SP = SP + 96ULL;
    return;
L_146668:
    if (FLAG_EQ) goto L_146624;
L_14666c:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 32));
    cpu->regs[21] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    cpu->regs[2] = ((uint32_t)(((cpu->regs[0] >> 6) & 0x1ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_146810;
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_146780;
    cpu->regs[19] = cpu->regs[19] + 40ULL;
    cpu->regs[3] = 127ULL;
L_146688:
    cpu->regs[1] = cpu->regs[3];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x146694ULL; PB_CALL(34, cpu, tlb, PB_BASE + 0xdf5a4ULL);
    cpu->regs[4] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_146820;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 32));
    cpu->regs[8] = ((uint32_t)(((cpu->regs[0] >> 2) & 0x7ULL)));
    if (!((cpu->regs[0] >> 5) & 1)) goto L_146808;
    FLAG_CMP((((uint32_t)(cpu->regs[0]))) & (((uint32_t)(64ULL))), 0);
    cpu->regs[6] = cpu->regs[4] + 56ULL;
    cpu->regs[0] = cpu->regs[4] + 40ULL;
    cpu->regs[6] = (FLAG_EQ) ? cpu->regs[6] : cpu->regs[0];
L_1466b8:
    PB_LDR(cpu->regs[7], (SP + 32));
    cpu->regs[5] = 0ULL;
L_1466c0:
    cpu->regs[2] = cpu->regs[7];
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1466d0ULL; PB_CALL(35, cpu, tlb, PB_BASE + 0x12b440ULL);
    cpu->regs[3] = cpu->regs[0];
    cpu->regs[0] = cpu->regs[8];
    cpu->regs[2] = cpu->regs[5];
    cpu->regs[1] = cpu->regs[6];
    cpu->regs[30] = PB_BASE + 0x1466e4ULL; PB_CALL(36, cpu, tlb, PB_BASE + 0x11ce20ULL);
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    PB_LDR(cpu->regs[0], (SP + 16));
    cpu->regs[7] = cpu->regs[7] + cpu->regs[0];
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_NE) goto L_1466c0;
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    goto L_146638;
L_146700:
    cpu->regs[4] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[4], (cpu->regs[4] + 2248));
    cpu->regs[1] = cpu->regs[4] + (4ULL << 12);
    PB_LDRW(cpu->regs[0], (cpu->regs[1] + 8080));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_NE) goto L_14682c;
L_146718:
    cpu->regs[0] = 24464ULL;
    cpu->regs[4] = cpu->regs[4] + cpu->regs[0];
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    goto L_146638;
L_146728:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x146730ULL; PB_CALL(37, cpu, tlb, PB_BASE + 0x1c5c40ULL);
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[4] = cpu->regs[0];
    goto L_146638;
L_14673c:
    PB_STR((SP + 8), cpu->regs[0]);
    cpu->regs[30] = PB_BASE + 0x146744ULL; PB_CALL(38, cpu, tlb, PB_BASE + 0xe1f30ULL);
    PB_LDR(cpu->regs[1], (SP + 8));
    if ((cpu->regs[0])!=0) goto L_1467ec;
L_14674c:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 3080));
    PB_LDR(cpu->regs[3], (SP + 40));
    PB_LDR(cpu->regs[2], (cpu->regs[0] + 0));
    cpu->regs[3] = cpu->regs[3] - cpu->regs[2]; FLAG_CMP(cpu->regs[3], 0);
    cpu->regs[2] = 0ULL;
    if (FLAG_NE) goto L_146778;
    PB_LDR(cpu->regs[2], (cpu->regs[19] + 16));
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[1] = cpu->regs[1] + cpu->regs[2];
    goto L_1465a0;
L_146778:
    PB_STR((SP + 80), cpu->regs[21]); PB_STR((SP + 80) + 8, cpu->regs[22]);
    cpu->regs[30] = PB_BASE + 0x146780ULL; PB_CALL(39, cpu, tlb, PB_BASE + 0x7c170ULL);
L_146780:
    cpu->regs[19] = cpu->regs[19] + 56ULL;
L_146784:
    cpu->regs[4] = 256ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(2ULL)));
    if (FLAG_NE) goto L_1467f4;
L_146790:
    cpu->regs[2] = cpu->regs[1];
    cpu->regs[3] = 0ULL;
    cpu->regs[5] = 0ULL;
L_14679c:
    cpu->regs[1] = cpu->regs[19];
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x1467a8ULL; PB_CALL(40, cpu, tlb, PB_BASE + 0x12b440ULL);
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[3])));
    if (FLAG_LS) goto L_1467bc;
    cpu->regs[3] = cpu->regs[0];
    FLAG_CMP(((uint32_t)(cpu->regs[0])), ((uint32_t)(cpu->regs[4])));
    if (FLAG_HS) goto L_146688;
L_1467bc:
    cpu->regs[5] = cpu->regs[5] + 1ULL;
    cpu->regs[2] = cpu->regs[2] + cpu->regs[22];
    FLAG_CMP(cpu->regs[20], cpu->regs[5]);
    if (FLAG_NE) goto L_14679c;
    goto L_146688;
L_1467d0:
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2736));
    cpu->regs[1] = PB_BASE + 0x28d000ULL;
    PB_LDR(cpu->regs[2], (cpu->regs[2] + 24));
    cpu->regs[1] = cpu->regs[1] + 3848ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x1467ecULL; PB_CALL(41, cpu, tlb, PB_BASE + 0x11f220ULL);
L_1467ec:
    cpu->regs[4] = 0ULL;
    goto L_146638;
L_1467f4:
    FLAG_CMP(((uint32_t)(cpu->regs[21])), ((uint32_t)(4ULL)));
    cpu->regs[4] = 65536ULL;
    cpu->regs[0] = 128ULL;
    cpu->regs[4] = (FLAG_EQ) ? cpu->regs[4] : cpu->regs[0];
    goto L_146790;
L_146808:
    PB_LDR(cpu->regs[6], (cpu->regs[4] + 56));
    goto L_1466b8;
L_146810:
    PB_LDR(cpu->regs[19], (cpu->regs[19] + 56));
    if ((((uint32_t)(cpu->regs[2])))==0) goto L_146784;
    cpu->regs[3] = 127ULL;
    goto L_146688;
L_146820:
    PB_LDR(cpu->regs[21], (SP + 80)); PB_LDR(cpu->regs[22], (SP + 80) + 8);
    cpu->regs[4] = 0ULL;
    goto L_146638;
L_14682c:
    PB_STRW((cpu->regs[1] + 8080), cpu->regs[0]);
    goto L_146718;
    /* nop */
    /* nop */
    /* nop */
}
