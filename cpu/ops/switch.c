/* switch.c - Switches through CPU opcodes. */

#include <vr4300i.h>

void vr4300i_exec(struct _vr4300i *vr) {
	/* unique opcodes. */
	switch((vr -> op >> 0x1A) & 0x3F) {
		case 0x9:
			ns4_vr4300i_addiu(vr);
			break;
		case 0x8:
			ns4_vr4300i_addi(vr);
			break;
		case 0x3c:
			ns4_vr4300i_scd(vr);
			break;
		case 0x3:
			ns4_vr4300i_jal(vr);
			break;
		case 0x2:
			ns4_vr4300i_j(vr);
			break;
		case 0x7:
			ns4_vr4300i_bgtz(vr);
			break;
		case 0x6:
			ns4_vr4300i_blez(vr);
			break;
		case 0x5:
			ns4_vr4300i_bne(vr);
			break;
		case 0x4:
			ns4_vr4300i_beq(vr);
			break;
		case 0x3f:
			ns4_vr4300i_sd(vr);
			break;
		case 0x28:
			ns4_vr4300i_sb(vr);
			break;
		case 0x29:
			ns4_vr4300i_sh(vr);
			break;
		case 0x22:
			ns4_vr4300i_lwl(vr);
			break;
		case 0x23:
			ns4_vr4300i_lw(vr);
			break;
		case 0x20:
			ns4_vr4300i_lb(vr);
			break;
		case 0x21:
			ns4_vr4300i_lh(vr);
			break;
		case 0x26:
			ns4_vr4300i_lwr(vr);
			break;
		case 0x27:
			ns4_vr4300i_lwu(vr);
			break;
		case 0x24:
			ns4_vr4300i_lbu(vr);
			break;
		case 0x25:
			ns4_vr4300i_lhu(vr);
			break;
		case 0x1b:
			ns4_vr4300i_ldr(vr);
			break;
		case 0x1a:
			ns4_vr4300i_ldl(vr);
			break;
		case 0x34:
			ns4_vr4300i_lld(vr);
			break;
		case 0x37:
			ns4_vr4300i_ld(vr);
			break;
		case 0x30:
			ns4_vr4300i_ll(vr);
			break;
		case 0x38:
			ns4_vr4300i_sc(vr);
			break;
		case 0xc:
			ns4_vr4300i_andi(vr);
			break;
		case 0xb:
			ns4_vr4300i_sltiu(vr);
			break;
		case 0xa:
			ns4_vr4300i_slti(vr);
			break;
		case 0xf:
			ns4_vr4300i_lui(vr);
			break;
		case 0xe:
			ns4_vr4300i_xori(vr);
			break;
		case 0xd:
			ns4_vr4300i_ori(vr);
			break;
		case 0x19:
			ns4_vr4300i_daddiu(vr);
			break;
		case 0x18:
			ns4_vr4300i_daddi(vr);
			break;
		case 0x17:
			ns4_vr4300i_bgtzl(vr);
			break;
		case 0x16:
			ns4_vr4300i_blezl(vr);
			break;
		case 0x15:
			ns4_vr4300i_bnel(vr);
			break;
		case 0x14:
			ns4_vr4300i_beql(vr);
			break;
		case 0x2b:
			ns4_vr4300i_sw(vr);
			break;
		case 0x2c:
			ns4_vr4300i_sdl(vr);
			break;
		case 0x2a:
			ns4_vr4300i_swl(vr);
			break;
		case 0x2f:
			ns4_vr4300i_cache(vr);
			break;
		case 0x2d:
			ns4_vr4300i_sdr(vr);
			break;
		case 0x2e:
			ns4_vr4300i_swr(vr);
			break;

		/* class opcodes. */
		case 0x1:
			goto class_0x1;
			break;
		case 0x0:
			goto class_0x0;
			break;
		case 0x10:
			goto class_0x10;
			break;
		default:
			ns4_assert(0, NS4_WARN, "Invalid opcode (0x%02x).\n", ((vr -> op >> 0x1A) & 0x3F));
			break;
	}
	return;

class_0x1:
	/* 0x1 class opcodes. */
	switch((vr -> op >> 0x10) & 0x1F) {
		case 0x1:
			ns4_vr4300i_bgez(vr);
			break;
		case 0x11:
			ns4_vr4300i_bgezal(vr);
			break;
		case 0x13:
			ns4_vr4300i_bgezall(vr);
			break;
		case 0x3:
			ns4_vr4300i_bgezl(vr);
			break;
		case 0x0:
			ns4_vr4300i_bltz(vr);
			break;
		case 0x10:
			ns4_vr4300i_bltzal(vr);
			break;
		case 0x12:
			ns4_vr4300i_bltzall(vr);
			break;
		case 0x2:
			ns4_vr4300i_bltzl(vr);
			break;
		case 0xc:
			ns4_vr4300i_teqi(vr);
			break;
		case 0x8:
			ns4_vr4300i_tgei(vr);
			break;
		case 0x9:
			ns4_vr4300i_tgeiu(vr);
			break;
		case 0xa:
			ns4_vr4300i_tlti(vr);
			break;
		case 0xb:
			ns4_vr4300i_tltiu(vr);
			break;
		case 0xe:
			ns4_vr4300i_tnei(vr);
			break;
	}
	return;

class_0x0:
	/* 0x0 class opcodes. */
	switch((vr -> op) & 0x3F) {
		case 0xf:
			ns4_vr4300i_sync(vr);
			break;
		case 0x20:
			ns4_vr4300i_add(vr);
			break;
		case 0x21:
			ns4_vr4300i_addu(vr);
			break;
		case 0x24:
			ns4_vr4300i_and(vr);
			break;
		case 0x2c:
			ns4_vr4300i_dadd(vr);
			break;
		case 0x2d:
			ns4_vr4300i_daddu(vr);
			break;
		case 0x1e:
			ns4_vr4300i_ddiv(vr);
			break;
		case 0x1f:
			ns4_vr4300i_ddivu(vr);
			break;
		case 0x1a:
			ns4_vr4300i_div(vr);
			break;
		case 0x1b:
			ns4_vr4300i_divu(vr);
			break;
		case 0x1c:
			ns4_vr4300i_dmult(vr);
			break;
		case 0x1d:
			ns4_vr4300i_dmultu(vr);
			break;
		case 0x38:
			ns4_vr4300i_dsll(vr);
			break;
		case 0x3c:
			ns4_vr4300i_dsll32(vr);
			break;
		case 0x14:
			ns4_vr4300i_dsllv(vr);
			break;
		case 0x3b:
			ns4_vr4300i_dsra(vr);
			break;
		case 0x3f:
			ns4_vr4300i_dsra32(vr);
			break;
		case 0x17:
			ns4_vr4300i_dsrav(vr);
			break;
		case 0x3a:
			ns4_vr4300i_dsrl(vr);
			break;
		case 0x3e:
			ns4_vr4300i_dsrl32(vr);
			break;
		case 0x16:
			ns4_vr4300i_dsrlv(vr);
			break;
		case 0x2e:
			ns4_vr4300i_dsub(vr);
			break;
		case 0x2f:
			ns4_vr4300i_dsubu(vr);
			break;
		case 0x10:
			ns4_vr4300i_mfhi(vr);
			break;
		case 0x12:
			ns4_vr4300i_mflo(vr);
			break;
		case 0x11:
			ns4_vr4300i_mthi(vr);
			break;
		case 0x13:
			ns4_vr4300i_mtlo(vr);
			break;
		case 0x18:
			ns4_vr4300i_mult(vr);
			break;
		case 0x19:
			ns4_vr4300i_multu(vr);
			break;
		case 0x27:
			ns4_vr4300i_nor(vr);
			break;
		case 0x25:
			ns4_vr4300i_or(vr);
			break;
		case 0x0:
			ns4_vr4300i_sll(vr);
			break;
		case 0x4:
			ns4_vr4300i_sllv(vr);
			break;
		case 0x2a:
			ns4_vr4300i_slt(vr);
			break;
		case 0x2b:
			ns4_vr4300i_sltu(vr);
			break;
		case 0x3:
			ns4_vr4300i_sra(vr);
			break;
		case 0x7:
			ns4_vr4300i_srav(vr);
			break;
		case 0x2:
			ns4_vr4300i_srl(vr);
			break;
		case 0x6:
			ns4_vr4300i_srlv(vr);
			break;
		case 0x22:
			ns4_vr4300i_sub(vr);
			break;
		case 0x23:
			ns4_vr4300i_subu(vr);
			break;
		case 0x26:
			ns4_vr4300i_xor(vr);
			break;
		case 0x9:
			ns4_vr4300i_jalr(vr);
			break;
		case 0x8:
			ns4_vr4300i_jr(vr);
			break;
		case 0xd:
			ns4_vr4300i_break(vr);
			break;
		case 0xc:
			ns4_vr4300i_syscall(vr);
			break;
		case 0x34:
			ns4_vr4300i_teq(vr);
			break;
		case 0x30:
			ns4_vr4300i_tge(vr);
			break;
		case 0x31:
			ns4_vr4300i_tgeu(vr);
			break;
		case 0x32:
			ns4_vr4300i_tlt(vr);
			break;
		case 0x33:
			ns4_vr4300i_tltu(vr);
			break;
		case 0x36:
			ns4_vr4300i_tne(vr);
			break;
	}
	return;

class_0x10:
	/* 0x10 class opcodes. */
	switch((vr -> op) & 0x3F) {
		case 0x18:
			ns4_vr4300i_eret(vr);
			break;
		case 0x0:
			ns4_vr4300i_mfc0(vr);
			break;
		case 0x0:
			ns4_vr4300i_mtc0(vr);
			break;
		case 0x8:
			ns4_vr4300i_tlbp(vr);
			break;
		case 0x1:
			ns4_vr4300i_tlbr(vr);
			break;
		case 0x2:
			ns4_vr4300i_tlbwi(vr);
			break;
		case 0x6:
			ns4_vr4300i_tlbwr(vr);
			break;
	}
	return;

}

