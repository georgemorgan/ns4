#ifndef __vr4300i_h__
#define __vr4300i_h__

#include <ns4.h>

/*

Main

  00h = r0/reg0     08h = t0/reg8     10h = s0/reg16    18h = t8/reg24
  01h = at/reg1     09h = t1/reg9     11h = s1/reg17    19h = t9/reg25
  02h = v0/reg2     0Ah = t2/reg10    12h = s2/reg18    1Ah = k0/reg26
  03h = v1/reg3     0Bh = t3/reg11    13h = s3/reg19    1Bh = k1/reg27
  04h = a0/reg4     0Ch = t4/reg12    14h = s4/reg20    1Ch = gp/reg28
  05h = a1/reg5     0Dh = t5/reg13    15h = s5/reg21    1Dh = sp/reg29
  06h = a2/reg6     0Eh = t6/reg14    16h = s6/reg22    1Eh = s8/reg30
  07h = a3/reg7     0Fh = t7/reg15    17h = s7/reg23    1Fh = ra/reg31

COP0

  00h = Index       08h = BadVAddr    10h = Config      18h = *RESERVED*
  01h = Random      09h = Count       11h = LLAddr      19h = *RESERVED*
  02h = EntryLo0    0Ah = EntryHi     12h = WatchLo     1Ah = PErr
  03h = EntryLo1    0Bh = Compare     13h = WatchHi     1Bh = CacheErr
  04h = Context     0Ch = Status      14h = XContext    1Ch = TagLo
  05h = PageMask    0Dh = Cause       15h = *RESERVED*  1Dh = TagHi
  06h = Wired       0Eh = EPC         16h = *RESERVED*  1Eh = ErrorEPC
  07h = *RESERVED*  0Fh = PRevID      17h = *RESERVED*  1Fh = *RESERVED*

 */

struct _vr4300i_cop0 {
    uint64_t index;
    uint64_t random;
    uint64_t EntryLo0;
    uint64_t EntryLo1;
    uint64_t Context;
    uint64_t PageMask;
    uint64_t Wired;
    uint64_t reserved0;
    uint64_t BadVAddr;
    uint64_t Count;
    uint64_t LLAddr;
    uint64_t WatchLo;
    uint64_t WatchHi;
    uint64_t XContext;
    uint64_t reserved1;
    uint64_t reserved2;
    uint64_t reserved3;
    uint64_t reserved4;
    uint64_t reserved5;
    uint64_t PErr;
    uint64_t CacheErr;
    uint64_t TagLo;
    uint64_t TagHi;
    uint64_t ErrorEPC;
    uint64_t reserved6;
};

struct _vr4300i {
    /* The CPU's memory controller. */
    struct _ns4_mc *mc;
    /* Access the registers as an array. */
    uint64_t *regs;
    /* Primary general purpose registers. */
    uint64_t r0;
    uint64_t at;
    uint64_t v0;
    uint64_t v1;
    uint64_t a0;
    uint64_t a1;
    uint64_t a2;
    uint64_t a3;
    uint64_t t0;
    uint64_t t1;
    uint64_t t2;
    uint64_t t3;
    uint64_t t4;
    uint64_t t5;
    uint64_t t6;
    uint64_t t7;
    uint64_t s0;
    uint64_t s1;
    uint64_t s2;
    uint64_t s3;
    uint64_t s4;
    uint64_t s5;
    uint64_t s6;
    uint64_t s7;
    uint64_t t8;
    uint64_t t9;
    uint64_t k0;
    uint64_t k1;
    uint64_t gp;
    uint64_t sp;
    uint64_t s8;
    uint64_t ra;
    /* The current opcode. */
    uint32_t op;
    /* The program counter. */
    uint64_t pc;
    /* COP0 core. */
    struct _vr4300i_cop0 cop0;
};

/* String versions of the registers for debugging. */
extern const char *regstrs[];

/* Creates a VR4300i CPU. */
void vr4300i_create(struct _vr4300i *vr, struct _ns4_mc *mc);
/* Executes the entire CPU's pipeline for one instruction. */
void vr4300i_step(struct _vr4300i *vr);
/* Performs an instruction. */
void vr4300i_exec(struct _vr4300i *vr);

#endif
