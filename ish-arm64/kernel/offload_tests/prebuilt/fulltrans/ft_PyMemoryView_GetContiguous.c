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

void ft_PyMemoryView_GetContiguous(struct cpu_state *cpu, struct tlb *tlb) {
(void)tlb;(void)cpu;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    cpu->regs[1] = 284ULL;
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[23] = ((uint32_t)(cpu->regs[2] & 255ULL));
    cpu->regs[30] = PB_BASE + 0x9bc20ULL; PB_CALL(1, cpu, tlb, PB_BASE + 0x1cdbacULL);
    if ((cpu->regs[0])==0) goto L_9bcac;
    cpu->regs[19] = cpu->regs[0];
    cpu->regs[22] = cpu->regs[0] + 56ULL;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(512ULL)));
    if (FLAG_NE) goto L_9bc60;
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 32));
    if ((((uint32_t)(cpu->regs[0])))==0) goto L_9bc60;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2792));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 792ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9bc54ULL; PB_CALL(2, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9bc98;
    goto L_9bcac;
L_9bc60:
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[0] = cpu->regs[22];
    cpu->regs[30] = PB_BASE + 0x9bc6cULL; PB_CALL(3, cpu, tlb, PB_BASE + 0x14cdc4ULL);
    if ((((uint32_t)(cpu->regs[0])))!=0) goto L_9be48;
    FLAG_CMP(((uint32_t)(cpu->regs[20])), ((uint32_t)(512ULL)));
    if (FLAG_NE) goto L_9bcb4;
    cpu->regs[0] = PB_BASE + 0x44f000ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 2792));
    cpu->regs[1] = PB_BASE + 0x2a3000ULL;
    cpu->regs[1] = cpu->regs[1] + 832ULL;
    PB_LDR(cpu->regs[0], (cpu->regs[0] + 0));
    cpu->regs[30] = PB_BASE + 0x9bc90ULL; PB_CALL(4, cpu, tlb, PB_BASE + 0x1d5940ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9bcac;
L_9bc98:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9bcac;
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9bcacULL; PB_CALL(5, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9bcac:
    cpu->regs[19] = 0ULL;
    goto L_9be48;
L_9bcb4:
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 16));
    cpu->regs[0] = 0ULL;
    cpu->regs[30] = PB_BASE + 0x9bcc0ULL; PB_CALL(6, cpu, tlb, PB_BASE + 0xe9c70ULL);
    cpu->regs[21] = cpu->regs[0];
    if ((cpu->regs[0])==0) goto L_9bd90;
    cpu->regs[1] = 284ULL;
    cpu->regs[30] = PB_BASE + 0x9bcd0ULL; PB_CALL(7, cpu, tlb, PB_BASE + 0x1ce164ULL);
    PB_LDR(cpu->regs[1], (cpu->regs[21] + 0));
    cpu->regs[20] = cpu->regs[0];
    if (((cpu->regs[1] >> 31) & 1)) goto L_9bcf0;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9bcf0;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9bcf0ULL; PB_CALL(8, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9bcf0:
    if ((cpu->regs[20])==0) goto L_9bd90;
    PB_LDR(cpu->regs[21], (cpu->regs[22] + 40));
    if ((cpu->regs[21])==0) goto L_9bdbc;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9bd04ULL; PB_CALL(9, cpu, tlb, PB_BASE + 0x7c0d0ULL);
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    cpu->regs[30] = PB_BASE + 0x9bd0cULL; PB_CALL(10, cpu, tlb, PB_BASE + 0xdbd90ULL);
    if ((cpu->regs[0])!=0) goto L_9bd20;
    cpu->regs[30] = PB_BASE + 0x9bd14ULL; PB_CALL(11, cpu, tlb, PB_BASE + 0x22d780ULL);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9bd3c;
    goto L_9bd90;
L_9bd20:
    cpu->regs[1] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9bd28ULL; PB_CALL(12, cpu, tlb, PB_BASE + 0x7b130ULL);
    PB_LDRW(cpu->regs[1], (cpu->regs[20] + 16));
    PB_STR((cpu->regs[20] + 72), cpu->regs[0]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] | 2ULL));
    PB_STRW((cpu->regs[20] + 16), cpu->regs[1]);
    goto L_9bdbc;
L_9bd3c:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9bd90;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9bd50ULL; PB_CALL(13, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9bd90;
L_9bd54:
    cpu->regs[23] = ((uint32_t)(cpu->regs[23] & 4294967293ULL));
    cpu->regs[0] = cpu->regs[20];
    FLAG_CMP(((uint32_t)(cpu->regs[23])), ((uint32_t)(65ULL)));
    if (FLAG_NE) goto L_9be28;
    cpu->regs[30] = PB_BASE + 0x9bd68ULL; PB_CALL(14, cpu, tlb, PB_BASE + 0x22fc80ULL);
L_9bd68:
    PB_STR((cpu->regs[20] + 64), 0ULL);
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9bd74ULL; PB_CALL(15, cpu, tlb, PB_BASE + 0x1cebe0ULL);
    cpu->regs[1] = cpu->regs[22];
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9bd80ULL; PB_CALL(16, cpu, tlb, PB_BASE + 0x2754d0ULL);
    FLAG_CMP(cpu->regs[0], (uint64_t)(-(int64_t)(1ULL)));
    if (FLAG_NE) goto L_9bd94;
    PB_LDR(cpu->regs[0], (cpu->regs[21] + 0));
    if (!((cpu->regs[0] >> 31) & 1)) goto L_9be30;
L_9bd90:
    cpu->regs[21] = 0ULL;
L_9bd94:
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9bda8;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[19] + 0), cpu->regs[0]);
    if ((cpu->regs[0])==0) goto L_9bdb0;
L_9bda8:
    cpu->regs[19] = cpu->regs[21];
    goto L_9be48;
L_9bdb0:
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9bdb8ULL; PB_CALL(17, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9bda8;
L_9bdbc:
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 36));
    cpu->regs[1] = 0ULL;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9bdccULL; PB_CALL(18, cpu, tlb, PB_BASE + 0x21c1e8ULL);
    cpu->regs[21] = cpu->regs[0];
    PB_LDR(cpu->regs[1], (cpu->regs[20] + 0));
    if (((cpu->regs[1] >> 31) & 1)) goto L_9bdec;
    cpu->regs[1] = cpu->regs[1] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[1]);
    if ((cpu->regs[1])!=0) goto L_9bdec;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9bdecULL; PB_CALL(19, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9bdec:
    if ((cpu->regs[21])==0) goto L_9bd90;
    cpu->regs[20] = cpu->regs[21] + 56ULL;
    PB_LDRW(cpu->regs[2], (cpu->regs[22] + 36));
    PB_LDR(cpu->regs[1], (cpu->regs[22] + 24));
    cpu->regs[0] = 0ULL;
    PB_STR((cpu->regs[20] + 24), cpu->regs[1]);
L_9be04:
    cpu->regs[1] = ((cpu->regs[0] & 0xffffffffULL) << 3);
    FLAG_CMP(((uint32_t)(cpu->regs[2])), ((uint32_t)(cpu->regs[0])));
    if (FLAG_LE) goto L_9bd54;
    PB_LDR(cpu->regs[4], (cpu->regs[22] + 48));
    cpu->regs[0] = cpu->regs[0] + 1ULL;
    PB_LDR(cpu->regs[3], (cpu->regs[20] + 48));
    PB_LDR(cpu->regs[4], (cpu->regs[4] + cpu->regs[1]));
    PB_STR((cpu->regs[3] + cpu->regs[1]), cpu->regs[4]);
    goto L_9be04;
L_9be28:
    cpu->regs[30] = PB_BASE + 0x9be2cULL; PB_CALL(20, cpu, tlb, PB_BASE + 0x863b8ULL);
    goto L_9bd68;
L_9be30:
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[21] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9bd90;
    cpu->regs[0] = cpu->regs[21];
    cpu->regs[30] = PB_BASE + 0x9be44ULL; PB_CALL(21, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9bd90;
L_9be48:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
    SP += -64; PB_STR(SP, cpu->regs[29]); PB_STR(SP + 8, cpu->regs[30]);
    cpu->regs[29] = SP;
    PB_STR((SP + 16), cpu->regs[19]); PB_STR((SP + 16) + 8, cpu->regs[20]);
    cpu->regs[20] = cpu->regs[1];
    PB_STR((SP + 32), cpu->regs[21]); PB_STR((SP + 32) + 8, cpu->regs[22]);
    cpu->regs[22] = cpu->regs[2];
    cpu->regs[21] = cpu->regs[3];
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 24));
    PB_LDR(cpu->regs[1], (cpu->regs[1] + 0));
    PB_LDRW(cpu->regs[2], (cpu->regs[1] + 64));
    PB_LDRW(cpu->regs[1], (cpu->regs[1] + 72));
    PB_STR((SP + 48), cpu->regs[23]);
    cpu->regs[1] = ((uint32_t)(cpu->regs[1] + cpu->regs[2]));
    cpu->regs[1] = ((uint64_t)(int64_t)(int32_t)(cpu->regs[1]));
    cpu->regs[30] = PB_BASE + 0x9be9cULL; PB_CALL(22, cpu, tlb, PB_BASE + 0xdc988ULL);
    cpu->regs[19] = cpu->regs[0];
    if ((cpu->regs[0])!=0) goto L_9bec4;
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9bf54;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9bf54;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9bec0ULL; PB_CALL(23, cpu, tlb, PB_BASE + 0xdcac8ULL);
    goto L_9bf54;
L_9bec4:
    cpu->regs[23] = cpu->regs[0] + 72ULL;
    cpu->regs[0] = cpu->regs[20] + 48ULL;
    cpu->regs[1] = cpu->regs[23];
    cpu->regs[30] = PB_BASE + 0x9bed4ULL; PB_CALL(24, cpu, tlb, PB_BASE + 0x1371e4ULL);
    cpu->regs[0] = 4294967294ULL;
    PB_STRB((cpu->regs[19] + 67), cpu->regs[0]);
    PB_STR((cpu->regs[20] + 24), cpu->regs[23]);
    cpu->regs[0] = 1ULL;
    PB_STRB((cpu->regs[19] + 142), cpu->regs[0]);
    PB_LDR(cpu->regs[0], (cpu->regs[20] + 0));
    if (((cpu->regs[0] >> 31) & 1)) goto L_9bf04;
    cpu->regs[0] = cpu->regs[0] - 1ULL;
    PB_STR((cpu->regs[20] + 0), cpu->regs[0]);
    if ((cpu->regs[0])!=0) goto L_9bf04;
    cpu->regs[0] = cpu->regs[20];
    cpu->regs[30] = PB_BASE + 0x9bf04ULL; PB_CALL(25, cpu, tlb, PB_BASE + 0xdcac8ULL);
L_9bf04:
    PB_STR((cpu->regs[19] + 16), 0ULL);
    PB_STR((cpu->regs[19] + 40), 0ULL); PB_STR((cpu->regs[19] + 40) + 8, 0ULL);
    if ((cpu->regs[22])!=0) goto L_9bf18;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[22], (cpu->regs[0] + 120));
L_9bf18:
    PB_LDRW(cpu->regs[0], (cpu->regs[22] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9bf28;
    PB_STRW((cpu->regs[22] + 0), cpu->regs[0]);
L_9bf28:
    PB_STR((cpu->regs[19] + 24), cpu->regs[22]);
    if ((cpu->regs[21])!=0) goto L_9bf38;
    PB_LDR(cpu->regs[0], (cpu->regs[19] + 72));
    PB_LDR(cpu->regs[21], (cpu->regs[0] + 128));
L_9bf38:
    PB_LDRW(cpu->regs[0], (cpu->regs[21] + 0));
    cpu->regs[0] = ((uint32_t)(cpu->regs[0] + 1ULL)); FLAG_CMP(cpu->regs[0], 0);
    if (FLAG_EQ) goto L_9bf48;
    PB_STRW((cpu->regs[21] + 0), cpu->regs[0]);
L_9bf48:
    PB_STR((cpu->regs[19] + 32), cpu->regs[21]);
    cpu->regs[0] = cpu->regs[19];
    cpu->regs[30] = PB_BASE + 0x9bf54ULL; PB_CALL(26, cpu, tlb, PB_BASE + 0xd9444ULL);
L_9bf54:
    PB_LDR(cpu->regs[23], (SP + 48));
    cpu->regs[0] = cpu->regs[19];
    PB_LDR(cpu->regs[19], (SP + 16)); PB_LDR(cpu->regs[20], (SP + 16) + 8);
    PB_LDR(cpu->regs[21], (SP + 32)); PB_LDR(cpu->regs[22], (SP + 32) + 8);
    PB_LDR(cpu->regs[29], SP); PB_LDR(cpu->regs[30], SP + 8); SP += 64;
    return;
}
