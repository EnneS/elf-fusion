	.cpu arm7tdmi
	.eabi_attribute 20, 1
	.eabi_attribute 21, 1
	.eabi_attribute 23, 3
	.eabi_attribute 24, 1
	.eabi_attribute 25, 1
	.eabi_attribute 26, 1
	.eabi_attribute 30, 6
	.eabi_attribute 34, 0
	.eabi_attribute 18, 4
	.file	"affichage_elf.c"
	.text
	.global	OS_ABI
	.section	.rodata
	.align	2
.LC0:
	.ascii	"System V\000"
	.align	2
.LC1:
	.ascii	"HP-UX\000"
	.align	2
.LC2:
	.ascii	"NetBSD\000"
	.align	2
.LC3:
	.ascii	"Linux\000"
	.align	2
.LC4:
	.ascii	"GNU Hurd\000"
	.align	2
.LC5:
	.ascii	"Solaris\000"
	.align	2
.LC6:
	.ascii	"AIX\000"
	.align	2
.LC7:
	.ascii	"IRIX\000"
	.align	2
.LC8:
	.ascii	"FreeBSD\000"
	.align	2
.LC9:
	.ascii	"Tru64\000"
	.align	2
.LC10:
	.ascii	"Novell Modesto\000"
	.align	2
.LC11:
	.ascii	"OpenBSD\000"
	.align	2
.LC12:
	.ascii	"OpenVMS\000"
	.align	2
.LC13:
	.ascii	"NonStop Kernel\000"
	.align	2
.LC14:
	.ascii	"AROS\000"
	.align	2
.LC15:
	.ascii	"Fenix OS\000"
	.align	2
.LC16:
	.ascii	"CloudABI\000"
	.data
	.align	2
	.type	OS_ABI, %object
	.size	OS_ABI, 68
OS_ABI:
	.word	.LC0
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.word	.LC4
	.word	.LC5
	.word	.LC6
	.word	.LC7
	.word	.LC8
	.word	.LC9
	.word	.LC10
	.word	.LC11
	.word	.LC12
	.word	.LC13
	.word	.LC14
	.word	.LC15
	.word	.LC16
	.global	HEADER_TYPE
	.section	.rodata
	.align	2
.LC17:
	.ascii	"NONE\000"
	.align	2
.LC18:
	.ascii	"REL\000"
	.align	2
.LC19:
	.ascii	"EXEC\000"
	.align	2
.LC20:
	.ascii	"DYN\000"
	.align	2
.LC21:
	.ascii	"CORE\000"
	.data
	.align	2
	.type	HEADER_TYPE, %object
	.size	HEADER_TYPE, 20
HEADER_TYPE:
	.word	.LC17
	.word	.LC18
	.word	.LC19
	.word	.LC20
	.word	.LC21
	.global	SECTION_TYPE
	.section	.rodata
	.align	2
.LC22:
	.ascii	"NULL\000"
	.align	2
.LC23:
	.ascii	"PROGBITS\000"
	.align	2
.LC24:
	.ascii	"SYMTAB\000"
	.align	2
.LC25:
	.ascii	"STRTAB\000"
	.align	2
.LC26:
	.ascii	"RELA\000"
	.align	2
.LC27:
	.ascii	"HASH\000"
	.align	2
.LC28:
	.ascii	"DYNAMIC\000"
	.align	2
.LC29:
	.ascii	"NOTE\000"
	.align	2
.LC30:
	.ascii	"NOBITS\000"
	.align	2
.LC31:
	.ascii	"SHLIB\000"
	.align	2
.LC32:
	.ascii	"DYNSYM\000"
	.align	2
.LC33:
	.ascii	" \000"
	.align	2
.LC34:
	.ascii	"INIT_ARRAY\000"
	.align	2
.LC35:
	.ascii	"FINI_ARRAY\000"
	.align	2
.LC36:
	.ascii	"PREINIT_ARRAY\000"
	.align	2
.LC37:
	.ascii	"GROUP\000"
	.align	2
.LC38:
	.ascii	"SYMTAB_SHNDX\000"
	.align	2
.LC39:
	.ascii	"NUM\000"
	.data
	.align	2
	.type	SECTION_TYPE, %object
	.size	SECTION_TYPE, 80
SECTION_TYPE:
	.word	.LC22
	.word	.LC23
	.word	.LC24
	.word	.LC25
	.word	.LC26
	.word	.LC27
	.word	.LC28
	.word	.LC29
	.word	.LC30
	.word	.LC18
	.word	.LC31
	.word	.LC32
	.word	.LC33
	.word	.LC33
	.word	.LC34
	.word	.LC35
	.word	.LC36
	.word	.LC37
	.word	.LC38
	.word	.LC39
	.global	SYMBOL_TYPE
	.section	.rodata
	.align	2
.LC40:
	.ascii	"NOTYPE\000"
	.align	2
.LC41:
	.ascii	"OBJECT\000"
	.align	2
.LC42:
	.ascii	"FUNC\000"
	.align	2
.LC43:
	.ascii	"SECTION\000"
	.align	2
.LC44:
	.ascii	"FILE\000"
	.align	2
.LC45:
	.ascii	"COMMON\000"
	.align	2
.LC46:
	.ascii	"TLS\000"
	.align	2
.LC47:
	.ascii	"LOOS\000"
	.align	2
.LC48:
	.ascii	"GNU_IFUNC\000"
	.align	2
.LC49:
	.ascii	"HIOS\000"
	.align	2
.LC50:
	.ascii	"LOPROC\000"
	.align	2
.LC51:
	.ascii	"HIPROC\000"
	.data
	.align	2
	.type	SYMBOL_TYPE, %object
	.size	SYMBOL_TYPE, 52
SYMBOL_TYPE:
	.word	.LC40
	.word	.LC41
	.word	.LC42
	.word	.LC43
	.word	.LC44
	.word	.LC45
	.word	.LC46
	.word	.LC39
	.word	.LC47
	.word	.LC48
	.word	.LC49
	.word	.LC50
	.word	.LC51
	.global	SYMBOL_LIEN
	.section	.rodata
	.align	2
.LC52:
	.ascii	"LOCAL\000"
	.align	2
.LC53:
	.ascii	"GLOBAL\000"
	.align	2
.LC54:
	.ascii	"WEAK\000"
	.align	2
.LC55:
	.ascii	" HIOS\000"
	.data
	.align	2
	.type	SYMBOL_LIEN, %object
	.size	SYMBOL_LIEN, 84
SYMBOL_LIEN:
	.word	.LC52
	.word	.LC53
	.word	.LC54
	.word	.LC39
	.word	.LC33
	.word	.LC33
	.word	.LC33
	.word	.LC33
	.word	.LC33
	.word	.LC33
	.word	.LC33
	.word	.LC47
	.word	.LC55
	.word	.LC50
	.word	.LC33
	.word	.LC51
	.space	20
	.global	SYMBOL_VISIBILITY
	.section	.rodata
	.align	2
.LC56:
	.ascii	"DEFAULT \000"
	.align	2
.LC57:
	.ascii	"INTERNAL\000"
	.align	2
.LC58:
	.ascii	"HIDDEN\000"
	.align	2
.LC59:
	.ascii	"PROTECTED\000"
	.data
	.align	2
	.type	SYMBOL_VISIBILITY, %object
	.size	SYMBOL_VISIBILITY, 16
SYMBOL_VISIBILITY:
	.word	.LC56
	.word	.LC57
	.word	.LC58
	.word	.LC59
	.section	.rodata
	.align	2
.LC60:
	.ascii	"En t\303\252te ELF :\000"
	.align	2
.LC61:
	.ascii	"Magique : \000"
	.align	2
.LC62:
	.ascii	"%.2x \000"
	.align	2
.LC63:
	.ascii	"Classe : \000"
	.align	2
.LC64:
	.ascii	"ELF64\000"
	.align	2
.LC65:
	.ascii	"ELF32\000"
	.align	2
.LC66:
	.ascii	"Donn\303\251es : Little Endian\000"
	.align	2
.LC67:
	.ascii	"Donn\303\251es : Big Endian\000"
	.align	2
.LC68:
	.ascii	"OS/ABI : %s\012\000"
	.align	2
.LC69:
	.ascii	"Vesrsion ABI: 0x%x\012\000"
	.align	2
.LC70:
	.ascii	"Type : \000"
	.align	2
.LC71:
	.ascii	"OS\000"
	.align	2
.LC72:
	.ascii	"PROC\000"
	.align	2
.LC73:
	.ascii	"Version : \000"
	.align	2
.LC74:
	.ascii	"autre que l'original\000"
	.align	2
.LC75:
	.ascii	"1 (current)\000"
	.align	2
.LC76:
	.ascii	"Default\000"
	.align	2
.LC77:
	.ascii	"Adresse du point d'entr\303\251e: 0x%.2x\012\000"
	.align	2
.LC78:
	.ascii	"D\303\251but des en-t\303\252tes de programme: %d ("
	.ascii	"octet dans le fichier)\012\000"
	.align	2
.LC79:
	.ascii	"D\303\251but des en-t\303\252tes de sections: %d (o"
	.ascii	"ctet dans le fichier)\012\000"
	.align	2
.LC80:
	.ascii	"Fanions : 0x%x\012\000"
	.align	2
.LC81:
	.ascii	"Taille de cet en-t\303\252te : 52 (octet)\000"
	.align	2
.LC82:
	.ascii	"Taille de l'en-t\303\252te du programme: %d (octet)"
	.ascii	"\012\000"
	.align	2
.LC83:
	.ascii	"Nombre d'en-t\303\252te du programme: %d\012\000"
	.align	2
.LC84:
	.ascii	"Taille des en-t\303\252tes de section: %d (octet)\012"
	.ascii	"\000"
	.align	2
.LC85:
	.ascii	"Nombre d'en-t\303\252tes de section:  %d (octet)\012"
	.ascii	"\000"
	.align	2
.LC86:
	.ascii	"Table d'indexes des cha\303\256nes d'en-t\303\252te"
	.ascii	" de section: %d\012\000"
	.text
	.align	2
	.global	print_elf_header
	.syntax unified
	.arm
	.fpu softvfp
	.type	print_elf_header, %function
print_elf_header:
	@ args = 128, pretend = 16, frame = 64
	@ frame_needed = 1, uses_anonymous_args = 0
	sub	sp, sp, #16
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #64
	add	ip, fp, #4
	stm	ip, {r0, r1, r2, r3}
	sub	ip, fp, #64
	add	lr, fp, #4
	ldmia	lr!, {r0, r1, r2, r3}
	stmia	ip!, {r0, r1, r2, r3}
	ldmia	lr!, {r0, r1, r2, r3}
	stmia	ip!, {r0, r1, r2, r3}
	ldmia	lr!, {r0, r1, r2, r3}
	stmia	ip!, {r0, r1, r2, r3}
	ldr	r3, [lr]
	str	r3, [ip]
	ldr	r0, .L16
	bl	puts
	ldr	r0, .L16+4
	bl	printf
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L2
.L3:
	sub	r2, fp, #64
	ldr	r3, [fp, #-8]
	add	r3, r2, r3
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r1, r3
	ldr	r0, .L16+8
	bl	printf
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L2:
	ldr	r3, [fp, #-8]
	cmp	r3, #15
	ble	.L3
	mov	r0, #10
	bl	putchar
	ldr	r0, .L16+12
	bl	printf
	ldrb	r3, [fp, #-60]	@ zero_extendqisi2
	cmp	r3, #2
	bne	.L4
	ldr	r0, .L16+16
	bl	printf
	b	.L5
.L4:
	ldr	r0, .L16+20
	bl	printf
.L5:
	mov	r0, #10
	bl	putchar
	ldrb	r3, [fp, #-59]	@ zero_extendqisi2
	cmp	r3, #1
	bne	.L6
	ldr	r0, .L16+24
	bl	printf
	b	.L7
.L6:
	ldr	r0, .L16+28
	bl	printf
.L7:
	mov	r0, #10
	bl	putchar
	ldrb	r3, [fp, #-57]	@ zero_extendqisi2
	mov	r2, r3
	ldr	r3, .L16+32
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r0, .L16+36
	bl	printf
	ldrb	r3, [fp, #-56]	@ zero_extendqisi2
	mov	r1, r3
	ldr	r0, .L16+40
	bl	printf
	ldr	r0, .L16+44
	bl	printf
	ldrh	r3, [fp, #-48]
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-12]
	cmp	r3, #4
	bgt	.L8
	ldr	r2, .L16+48
	ldr	r3, [fp, #-12]
	ldr	r3, [r2, r3, lsl #2]
	mov	r0, r3
	bl	puts
	b	.L9
.L8:
	ldr	r3, [fp, #-12]
	cmp	r3, #253
	ble	.L10
	ldr	r3, [fp, #-12]
	cmp	r3, #65280
	bge	.L10
	ldr	r0, .L16+52
	bl	puts
	b	.L9
.L10:
	ldr	r3, [fp, #-12]
	cmp	r3, #65280
	blt	.L9
	ldr	r3, [fp, #-12]
	cmp	r3, #65536
	bge	.L9
	ldr	r0, .L16+56
	bl	puts
.L9:
	mov	r0, #10
	bl	putchar
	ldr	r0, .L16+60
	bl	printf
	ldr	r3, [fp, #-44]
	cmp	r3, #0
	beq	.L12
	cmp	r3, #1
	beq	.L13
	b	.L15
.L12:
	ldr	r0, .L16+64
	bl	printf
	b	.L14
.L13:
	ldr	r0, .L16+68
	bl	printf
	b	.L14
.L15:
	ldr	r0, .L16+72
	bl	printf
	nop
.L14:
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-40]
	mov	r1, r3
	ldr	r0, .L16+76
	bl	printf
	ldr	r3, [fp, #-36]
	mov	r1, r3
	ldr	r0, .L16+80
	bl	printf
	ldr	r3, [fp, #-32]
	mov	r1, r3
	ldr	r0, .L16+84
	bl	printf
	ldr	r3, [fp, #-28]
	mov	r1, r3
	ldr	r0, .L16+88
	bl	printf
	ldr	r0, .L16+92
	bl	puts
	ldrh	r3, [fp, #-22]
	mov	r1, r3
	ldr	r0, .L16+96
	bl	printf
	ldrh	r3, [fp, #-20]
	mov	r1, r3
	ldr	r0, .L16+100
	bl	printf
	ldrh	r3, [fp, #-18]
	mov	r1, r3
	ldr	r0, .L16+104
	bl	printf
	ldrh	r3, [fp, #-16]
	mov	r1, r3
	ldr	r0, .L16+108
	bl	printf
	ldrh	r3, [fp, #-14]
	mov	r1, r3
	ldr	r0, .L16+112
	bl	printf
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	add	sp, sp, #16
	bx	lr
.L17:
	.align	2
.L16:
	.word	.LC60
	.word	.LC61
	.word	.LC62
	.word	.LC63
	.word	.LC64
	.word	.LC65
	.word	.LC66
	.word	.LC67
	.word	OS_ABI
	.word	.LC68
	.word	.LC69
	.word	.LC70
	.word	HEADER_TYPE
	.word	.LC71
	.word	.LC72
	.word	.LC73
	.word	.LC74
	.word	.LC75
	.word	.LC76
	.word	.LC77
	.word	.LC78
	.word	.LC79
	.word	.LC80
	.word	.LC81
	.word	.LC82
	.word	.LC83
	.word	.LC84
	.word	.LC85
	.word	.LC86
	.size	print_elf_header, .-print_elf_header
	.section	.rodata
	.align	2
.LC87:
	.ascii	"Il y a %ld en-t\303\252te de sections, commen\303\247"
	.ascii	"ant au d\303\251calage 0x%lx\012\012\000"
	.align	2
.LC88:
	.ascii	"En-t\303\252tes de section:\000"
	.align	2
.LC89:
	.ascii	"  [No] Nom                Type         Addr     Dec"
	.ascii	"a   Taille ES Flg Ln Inf Al\000"
	.align	2
.LC90:
	.ascii	"  [%2d]\000"
	.align	2
.LC91:
	.ascii	" %-18s\000"
	.align	2
.LC92:
	.ascii	" %-12s\000"
	.align	2
.LC93:
	.ascii	"USER\000"
	.align	2
.LC94:
	.ascii	" %8.8x\000"
	.align	2
.LC95:
	.ascii	" %6.6x\000"
	.align	2
.LC96:
	.ascii	" %2.2x\000"
	.align	2
.LC98:
	.ascii	" %3s\000"
	.align	2
.LC99:
	.ascii	" %2d\000"
	.align	2
.LC100:
	.ascii	" %3d\000"
	.align	2
.LC101:
	.ascii	"Key to Flags:\012\011W (write), A (alloc), X (execu"
	.ascii	"te), M (merge), S (strings), I (info),\012\011L (li"
	.ascii	"nk order), O (extra OS processing required), G (gro"
	.ascii	"up), T (TLS), \012\011C (compressed), x (unknown), "
	.ascii	"o (OS specific), E (exclude),\012\011y (purecode), "
	.ascii	"p (processor specific)\000"
	.align	2
.LC97:
	.ascii	"\000\000\000\000"
	.text
	.align	2
	.global	print_section_header_table
	.syntax unified
	.arm
	.fpu softvfp
	.type	print_section_header_table, %function
print_section_header_table:
	@ args = 128, pretend = 16, frame = 40
	@ frame_needed = 1, uses_anonymous_args = 0
	sub	sp, sp, #16
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #40
	add	ip, fp, #4
	stm	ip, {r0, r1, r2, r3}
	ldr	r3, [fp, #56]
	str	r3, [fp, #-16]
	ldr	r3, [fp, #36]
	str	r3, [fp, #-20]
	ldrh	r3, [fp, #52]
	str	r3, [fp, #-24]
	ldr	r3, [fp, #72]
	str	r3, [fp, #-28]
	ldr	r2, [fp, #-20]
	ldr	r1, [fp, #-24]
	ldr	r0, .L39
	bl	printf
	ldr	r0, .L39+4
	bl	puts
	ldr	r0, .L39+8
	bl	puts
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L19
.L38:
	ldr	r1, [fp, #-8]
	ldr	r0, .L39+12
	bl	printf
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3]
	ldr	r2, [fp, #-28]
	add	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L39+16
	bl	printf
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #4]
	str	r3, [fp, #-32]
	ldr	r3, [fp, #-32]
	cmp	r3, #11
	bgt	.L20
	ldr	r2, .L39+20
	ldr	r3, [fp, #-32]
	ldr	r3, [r2, r3, lsl #2]
	mov	r1, r3
	ldr	r0, .L39+24
	bl	printf
	b	.L21
.L20:
	ldr	r3, [fp, #-32]
	cmn	r3, #-1610612735
	ble	.L22
	ldr	r3, [fp, #-32]
	cmn	r3, #-1879048191
	bgt	.L22
	ldr	r1, .L39+28
	ldr	r0, .L39+24
	bl	printf
	b	.L21
.L22:
	ldr	r3, [fp, #-32]
	cmn	r3, #-1879048191
	ble	.L23
	ldr	r1, .L39+32
	ldr	r0, .L39+24
	bl	printf
	b	.L21
.L23:
	ldr	r3, [fp, #-32]
	cmp	r3, #0
	bge	.L24
	ldr	r3, [fp, #-32]
	cmn	r3, #1879048193
	bhi	.L24
	ldr	r1, .L39+36
	ldr	r0, .L39+24
	bl	printf
	b	.L21
.L24:
	ldr	r1, .L39+40
	ldr	r0, .L39+24
	bl	printf
.L21:
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #12]
	mov	r1, r3
	ldr	r0, .L39+44
	bl	printf
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #16]
	mov	r1, r3
	ldr	r0, .L39+48
	bl	printf
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #20]
	mov	r1, r3
	ldr	r0, .L39+48
	bl	printf
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #36]
	mov	r1, r3
	ldr	r0, .L39+52
	bl	printf
	ldr	r3, .L39+56
	ldr	r3, [r3]
	str	r3, [fp, #-40]
	mov	r3, #0
	str	r3, [fp, #-12]
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #8]
	str	r3, [fp, #-36]
	ldr	r3, [fp, #-36]
	and	r3, r3, #1
	cmp	r3, #0
	beq	.L25
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #87
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L25:
	ldr	r3, [fp, #-36]
	and	r3, r3, #2
	cmp	r3, #0
	beq	.L26
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #65
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L26:
	ldr	r3, [fp, #-36]
	and	r3, r3, #4
	cmp	r3, #0
	beq	.L27
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #88
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L27:
	ldr	r3, [fp, #-36]
	and	r3, r3, #16
	cmp	r3, #0
	beq	.L28
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #77
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L28:
	ldr	r3, [fp, #-36]
	and	r3, r3, #32
	cmp	r3, #0
	beq	.L29
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #83
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L29:
	ldr	r3, [fp, #-36]
	and	r3, r3, #64
	cmp	r3, #0
	beq	.L30
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #73
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L30:
	ldr	r3, [fp, #-36]
	and	r3, r3, #128
	cmp	r3, #0
	beq	.L31
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #76
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L31:
	ldr	r3, [fp, #-36]
	and	r3, r3, #256
	cmp	r3, #0
	beq	.L32
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #79
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L32:
	ldr	r3, [fp, #-36]
	and	r3, r3, #2048
	cmp	r3, #0
	beq	.L33
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #67
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L33:
	ldr	r3, [fp, #-36]
	and	r3, r3, #512
	cmp	r3, #0
	beq	.L34
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #71
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L34:
	ldr	r3, [fp, #-36]
	and	r3, r3, #1024
	cmp	r3, #0
	beq	.L35
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #84
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L35:
	ldr	r3, [fp, #-36]
	and	r3, r3, #267386880
	cmp	r3, #0
	beq	.L36
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #111
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L36:
	ldr	r3, [fp, #-36]
	and	r3, r3, #-268435456
	cmp	r3, #0
	beq	.L37
	sub	r2, fp, #40
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, #112
	strb	r2, [r3]
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L37:
	sub	r3, fp, #40
	mov	r1, r3
	ldr	r0, .L39+60
	bl	printf
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #24]
	mov	r1, r3
	ldr	r0, .L39+64
	bl	printf
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #28]
	mov	r1, r3
	ldr	r0, .L39+68
	bl	printf
	ldr	r2, [fp, #-8]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-16]
	add	r3, r3, r2
	ldr	r3, [r3, #32]
	mov	r1, r3
	ldr	r0, .L39+64
	bl	printf
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L19:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-24]
	cmp	r2, r3
	bhi	.L38
	ldr	r0, .L39+72
	bl	puts
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	add	sp, sp, #16
	bx	lr
.L40:
	.align	2
.L39:
	.word	.LC87
	.word	.LC88
	.word	.LC89
	.word	.LC90
	.word	.LC91
	.word	SECTION_TYPE
	.word	.LC92
	.word	.LC71
	.word	.LC72
	.word	.LC93
	.word	.LC33
	.word	.LC94
	.word	.LC95
	.word	.LC96
	.word	.LC97
	.word	.LC98
	.word	.LC99
	.word	.LC100
	.word	.LC101
	.size	print_section_header_table, .-print_section_header_table
	.global	__aeabi_uidiv
	.global	__aeabi_uidivmod
	.section	.rodata
	.align	2
.LC102:
	.ascii	"Dump hexad\303\251cimal de la section '%s':\012\000"
	.align	2
.LC103:
	.ascii	"  0x%.8x \000"
	.align	2
.LC104:
	.ascii	"%.2x\000"
	.align	2
.LC105:
	.ascii	"\000"
	.align	2
.LC106:
	.ascii	"%*s\000"
	.align	2
.LC107:
	.ascii	"Section '%s' n'a pas de donn\303\251e \303\240 dump"
	.ascii	".\000"
	.text
	.align	2
	.global	print_section_data
	.syntax unified
	.arm
	.fpu softvfp
	.type	print_section_data, %function
print_section_data:
	@ args = 132, pretend = 16, frame = 48
	@ frame_needed = 1, uses_anonymous_args = 0
	sub	sp, sp, #16
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #48
	add	ip, fp, #4
	stm	ip, {r0, r1, r2, r3}
	ldr	r3, [fp, #56]
	str	r3, [fp, #-20]
	ldr	r3, [fp, #72]
	str	r3, [fp, #-24]
	ldr	r2, [fp, #60]
	ldr	r3, [fp, #132]
	lsl	r3, r3, #2
	add	r3, r2, r3
	ldr	r3, [r3]
	str	r3, [fp, #-28]
	ldr	r2, [fp, #132]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-20]
	add	r3, r3, r2
	ldr	r3, [r3, #20]
	str	r3, [fp, #-32]
	ldr	r2, [fp, #132]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-20]
	add	r3, r3, r2
	ldr	r3, [r3]
	ldr	r2, [fp, #-24]
	add	r3, r2, r3
	str	r3, [fp, #-36]
	ldr	r3, [fp, #-32]
	cmp	r3, #0
	beq	.L42
	mov	r3, #4
	str	r3, [fp, #-40]
	ldr	r3, [fp, #-40]
	lsl	r3, r3, #2
	mov	r1, r3
	ldr	r0, [fp, #-32]
	bl	__aeabi_uidiv
	mov	r3, r0
	str	r3, [fp, #-44]
	ldr	r3, [fp, #-32]
	lsl	r2, r3, #1
	ldr	r3, [fp, #-40]
	lsl	r3, r3, #3
	mov	r1, r3
	mov	r0, r2
	bl	__aeabi_uidivmod
	mov	r3, r1
	str	r3, [fp, #-48]
	ldr	r2, [fp, #-40]
	mov	r3, r2
	lsl	r3, r3, #3
	add	r2, r3, r2
	ldr	r3, [fp, #-48]
	sub	r2, r2, r3
	ldr	r3, [fp, #-48]
	add	r1, r3, #7
	cmp	r3, #0
	movlt	r3, r1
	movge	r3, r3
	asr	r3, r3, #3
	rsb	r3, r3, #0
	add	r3, r2, r3
	str	r3, [fp, #-52]
	ldr	r1, [fp, #-36]
	ldr	r0, .L57
	bl	printf
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L43
.L55:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #4
	mov	r1, r3
	ldr	r0, .L57+4
	bl	printf
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L44
.L49:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-32]
	cmp	r3, r2
	bls	.L45
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-28]
	add	r3, r3, r2
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r1, r3
	ldr	r0, .L57+8
	bl	printf
.L45:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	add	r3, r3, #1
	mov	r2, r3
	ldr	r3, [fp, #-32]
	cmp	r3, r2
	bls	.L46
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	add	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-28]
	add	r3, r3, r2
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r1, r3
	ldr	r0, .L57+8
	bl	printf
.L46:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	add	r3, r3, #2
	mov	r2, r3
	ldr	r3, [fp, #-32]
	cmp	r3, r2
	bls	.L47
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-12]
	add	r3, r3, #2
	add	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-28]
	add	r3, r3, r2
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r1, r3
	ldr	r0, .L57+8
	bl	printf
.L47:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-12]
	add	r3, r2, r3
	add	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-32]
	cmp	r3, r2
	bls	.L48
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-12]
	add	r3, r3, #3
	add	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-28]
	add	r3, r3, r2
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r1, r3
	ldr	r0, .L57+12
	bl	printf
.L48:
	ldr	r3, [fp, #-12]
	add	r3, r3, #4
	str	r3, [fp, #-12]
.L44:
	ldr	r3, [fp, #-40]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-12]
	cmp	r2, r3
	movlt	r3, #1
	movge	r3, #0
	and	r2, r3, #255
	ldr	r3, [fp, #-8]
	ldr	r1, [fp, #-40]
	mul	r0, r1, r3
	lsl	r1, r0, #2
	ldr	r3, [fp, #-12]
	add	r3, r1, r3
	mov	r1, r3
	ldr	r3, [fp, #-32]
	cmp	r3, r1
	movhi	r3, #1
	movls	r3, #0
	and	r3, r3, #255
	and	r3, r3, r2
	and	r3, r3, #255
	cmp	r3, #0
	bne	.L49
	ldr	r3, [fp, #-40]
	lsl	r3, r3, #2
	mov	r1, r3
	ldr	r0, [fp, #-32]
	bl	__aeabi_uidiv
	mov	r3, r0
	mov	r2, r3
	ldr	r3, [fp, #-8]
	cmp	r2, r3
	bne	.L50
	ldr	r2, .L57+16
	ldr	r1, [fp, #-52]
	ldr	r0, .L57+20
	bl	printf
.L50:
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L51
.L54:
	bl	__locale_ctype_ptr
	mov	r1, r0
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r0, r2, r3
	lsl	r2, r0, #2
	ldr	r3, [fp, #-16]
	add	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-28]
	add	r3, r3, r2
	ldrb	r3, [r3]	@ zero_extendqisi2
	add	r3, r3, #1
	add	r3, r1, r3
	ldrb	r3, [r3]	@ zero_extendqisi2
	and	r3, r3, #151
	cmp	r3, #0
	beq	.L52
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-40]
	mul	r1, r2, r3
	lsl	r2, r1, #2
	ldr	r3, [fp, #-16]
	add	r3, r2, r3
	mov	r2, r3
	ldr	r3, [fp, #-28]
	add	r3, r3, r2
	ldrb	r3, [r3]	@ zero_extendqisi2
	mov	r0, r3
	bl	putchar
	b	.L53
.L52:
	mov	r0, #46
	bl	putchar
.L53:
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L51:
	ldr	r3, [fp, #-40]
	lsl	r3, r3, #2
	ldr	r2, [fp, #-16]
	cmp	r2, r3
	movlt	r3, #1
	movge	r3, #0
	and	r2, r3, #255
	ldr	r3, [fp, #-8]
	ldr	r1, [fp, #-40]
	mul	r0, r1, r3
	lsl	r1, r0, #2
	ldr	r3, [fp, #-16]
	add	r3, r1, r3
	mov	r1, r3
	ldr	r3, [fp, #-32]
	cmp	r3, r1
	movhi	r3, #1
	movls	r3, #0
	and	r3, r3, #255
	and	r3, r3, r2
	and	r3, r3, #255
	cmp	r3, #0
	bne	.L54
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L43:
	ldr	r2, [fp, #-8]
	ldr	r3, [fp, #-44]
	cmp	r2, r3
	ble	.L55
	b	.L56
.L42:
	ldr	r1, [fp, #-36]
	ldr	r0, .L57+24
	bl	printf
.L56:
	mov	r0, #10
	bl	putchar
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	add	sp, sp, #16
	bx	lr
.L58:
	.align	2
.L57:
	.word	.LC102
	.word	.LC103
	.word	.LC104
	.word	.LC62
	.word	.LC105
	.word	.LC106
	.word	.LC107
	.size	print_section_data, .-print_section_data
	.section	.rodata
	.align	2
.LC108:
	.ascii	"La table de symboles \302\253\302\240.symtab\302\240"
	.ascii	"\302\273 contient %ld entr\303\251es\302\240:\012\000"
	.align	2
.LC109:
	.ascii	"   Num:    Valeur Tail Type    Lien   Vis      Ndx "
	.ascii	"Nom\000"
	.align	2
.LC110:
	.ascii	"%6d:\000"
	.align	2
.LC111:
	.ascii	"%10.8x\000"
	.align	2
.LC112:
	.ascii	"%5d \000"
	.align	2
.LC113:
	.ascii	"%-8s\000"
	.align	2
.LC114:
	.ascii	"%-7s\000"
	.align	2
.LC115:
	.ascii	"UND\000"
	.align	2
.LC116:
	.ascii	"%4s\000"
	.align	2
.LC117:
	.ascii	"%4d\000"
	.align	2
.LC118:
	.ascii	"%5s\000"
	.text
	.align	2
	.global	print_symbol_table
	.syntax unified
	.arm
	.fpu softvfp
	.type	print_symbol_table, %function
print_symbol_table:
	@ args = 128, pretend = 16, frame = 40
	@ frame_needed = 1, uses_anonymous_args = 0
	sub	sp, sp, #16
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #40
	add	ip, fp, #4
	stm	ip, {r0, r1, r2, r3}
	ldr	r3, [fp, #80]
	str	r3, [fp, #-16]
	ldr	r3, [fp, #84]
	str	r3, [fp, #-20]
	ldr	r3, [fp, #88]
	str	r3, [fp, #-24]
	ldr	r1, [fp, #-20]
	ldr	r0, .L72
	bl	printf
	ldr	r0, .L72+4
	bl	puts
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L60
.L70:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #4
	ldr	r2, [fp, #-16]
	add	r3, r2, r3
	sub	ip, fp, #44
	ldm	r3, {r0, r1, r2, r3}
	stm	ip, {r0, r1, r2, r3}
	ldr	r1, [fp, #-8]
	ldr	r0, .L72+8
	bl	printf
	ldr	r3, [fp, #-40]
	mov	r1, r3
	ldr	r0, .L72+12
	bl	printf
	ldr	r3, [fp, #-36]
	mov	r1, r3
	ldr	r0, .L72+16
	bl	printf
	ldrb	r3, [fp, #-32]	@ zero_extendqisi2
	and	r3, r3, #15
	str	r3, [fp, #-12]
	ldr	r3, [fp, #-12]
	sub	r3, r3, #16
	cmp	r3, #5
	ldrls	pc, [pc, r3, asl #2]
	b	.L71
.L63:
	.word	.L62
	.word	.L71
	.word	.L64
	.word	.L65
	.word	.L71
	.word	.L66
.L62:
	mov	r3, #8
	str	r3, [fp, #-12]
	b	.L67
.L64:
	mov	r3, #9
	str	r3, [fp, #-12]
	b	.L67
.L65:
	mov	r3, #10
	str	r3, [fp, #-12]
	b	.L67
.L66:
	mov	r3, #11
	str	r3, [fp, #-12]
	b	.L67
.L71:
	nop
.L67:
	ldr	r2, .L72+20
	ldr	r3, [fp, #-12]
	ldr	r3, [r2, r3, lsl #2]
	mov	r1, r3
	ldr	r0, .L72+24
	bl	printf
	ldrb	r3, [fp, #-32]	@ zero_extendqisi2
	lsr	r3, r3, #4
	and	r3, r3, #255
	mov	r2, r3
	ldr	r3, .L72+28
	ldr	r3, [r3, r2, lsl #2]
	mov	r1, r3
	ldr	r0, .L72+32
	bl	printf
	ldrb	r3, [fp, #-31]	@ zero_extendqisi2
	and	r3, r3, #3
	ldr	r2, .L72+36
	ldr	r3, [r2, r3, lsl #2]
	mov	r1, r3
	ldr	r0, .L72+24
	bl	printf
	ldrh	r3, [fp, #-30]
	str	r3, [fp, #-28]
	ldr	r3, [fp, #-28]
	cmp	r3, #0
	bne	.L68
	ldr	r1, .L72+40
	ldr	r0, .L72+44
	bl	printf
	b	.L69
.L68:
	ldr	r1, [fp, #-28]
	ldr	r0, .L72+48
	bl	printf
.L69:
	ldr	r3, [fp, #-44]
	ldr	r2, [fp, #-24]
	add	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L72+52
	bl	printf
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L60:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-20]
	cmp	r2, r3
	bhi	.L70
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	add	sp, sp, #16
	bx	lr
.L73:
	.align	2
.L72:
	.word	.LC108
	.word	.LC109
	.word	.LC110
	.word	.LC111
	.word	.LC112
	.word	SYMBOL_TYPE
	.word	.LC113
	.word	SYMBOL_LIEN
	.word	.LC114
	.word	SYMBOL_VISIBILITY
	.word	.LC115
	.word	.LC116
	.word	.LC117
	.word	.LC118
	.size	print_symbol_table, .-print_symbol_table
	.section	.rodata
	.align	2
.LC119:
	.ascii	"Section de r\303\251adressage '%s' \303\240 l'adres"
	.ascii	"se de d\303\251calage 0x%x contient %ld entr\303\251"
	.ascii	"es:\012\000"
	.align	2
.LC120:
	.ascii	" D\303\251calage   Info   Type  Val.-sym  Noms-symb"
	.ascii	"oles\000"
	.align	2
.LC121:
	.ascii	"%-10.8x\000"
	.align	2
.LC122:
	.ascii	"%-9.8x\000"
	.align	2
.LC123:
	.ascii	"%4d \000"
	.align	2
.LC124:
	.ascii	"%9.8x \000"
	.align	2
.LC125:
	.ascii	"%14s\000"
	.align	2
.LC126:
	.ascii	"%-8.8x\000"
	.align	2
.LC127:
	.ascii	"%-12s\000"
	.text
	.align	2
	.global	print_relocation_table
	.syntax unified
	.arm
	.fpu softvfp
	.type	print_relocation_table, %function
print_relocation_table:
	@ args = 128, pretend = 16, frame = 136
	@ frame_needed = 1, uses_anonymous_args = 0
	sub	sp, sp, #16
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #136
	add	ip, fp, #4
	stm	ip, {r0, r1, r2, r3}
	ldr	r3, [fp, #104]
	str	r3, [fp, #-24]
	ldr	r3, [fp, #108]
	str	r3, [fp, #-28]
	ldr	r3, [fp, #96]
	str	r3, [fp, #-32]
	ldr	r3, [fp, #100]
	str	r3, [fp, #-36]
	ldr	r3, [fp, #72]
	str	r3, [fp, #-40]
	ldr	r3, [fp, #80]
	str	r3, [fp, #-44]
	ldr	r3, [fp, #56]
	str	r3, [fp, #-48]
	mov	r3, #0
	str	r3, [fp, #-8]
	b	.L75
.L78:
	ldr	r3, [fp, #-8]
	lsl	r3, r3, #4
	ldr	r2, [fp, #-24]
	add	r3, r2, r3
	sub	ip, fp, #104
	ldm	r3, {r0, r1, r2, r3}
	stm	ip, {r0, r1, r2, r3}
	ldr	r3, [fp, #-92]
	str	r3, [fp, #-72]
	ldr	r3, [fp, #-100]
	str	r3, [fp, #-76]
	ldr	r3, [fp, #-96]
	ldr	r2, [fp, #-40]
	add	r1, r2, r3
	ldr	r3, [fp, #-76]
	ldr	r2, [fp, #-72]
	ldr	r0, .L83
	bl	printf
	ldr	r0, .L83+4
	bl	puts
	mov	r3, #0
	str	r3, [fp, #-12]
	b	.L76
.L77:
	ldr	r2, [fp, #-104]
	ldr	r3, [fp, #-12]
	lsl	r3, r3, #3
	add	r2, r2, r3
	sub	r3, fp, #112
	ldm	r2, {r0, r1}
	stm	r3, {r0, r1}
	ldr	r3, [fp, #-112]
	mov	r1, r3
	ldr	r0, .L83+8
	bl	printf
	ldr	r3, [fp, #-108]
	mov	r1, r3
	ldr	r0, .L83+12
	bl	printf
	ldr	r3, [fp, #-108]
	and	r3, r3, #255
	str	r3, [fp, #-80]
	ldr	r1, [fp, #-80]
	ldr	r0, .L83+16
	bl	printf
	ldr	r3, [fp, #-108]
	lsr	r3, r3, #8
	str	r3, [fp, #-84]
	ldr	r1, [fp, #-84]
	ldr	r0, .L83+20
	bl	printf
	ldr	r3, [fp, #-84]
	lsl	r3, r3, #4
	ldr	r2, [fp, #-44]
	add	r3, r2, r3
	ldrh	r3, [r3, #14]
	str	r3, [fp, #-88]
	ldr	r2, [fp, #-88]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-48]
	add	r3, r3, r2
	ldr	r3, [r3]
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L83+24
	bl	printf
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-12]
	add	r3, r3, #1
	str	r3, [fp, #-12]
.L76:
	ldr	r2, [fp, #-100]
	ldr	r3, [fp, #-12]
	cmp	r2, r3
	bhi	.L77
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-8]
	add	r3, r3, #1
	str	r3, [fp, #-8]
.L75:
	ldr	r3, [fp, #-8]
	ldr	r2, [fp, #-28]
	cmp	r2, r3
	bhi	.L78
	mov	r3, #0
	str	r3, [fp, #-16]
	b	.L79
.L82:
	ldr	r3, [fp, #-16]
	lsl	r3, r3, #4
	ldr	r2, [fp, #-32]
	add	r3, r2, r3
	sub	ip, fp, #128
	ldm	r3, {r0, r1, r2, r3}
	stm	ip, {r0, r1, r2, r3}
	ldr	r3, [fp, #-116]
	str	r3, [fp, #-52]
	ldr	r3, [fp, #-124]
	str	r3, [fp, #-56]
	ldr	r3, [fp, #-120]
	ldr	r2, [fp, #-40]
	add	r1, r2, r3
	ldr	r3, [fp, #-56]
	ldr	r2, [fp, #-52]
	ldr	r0, .L83
	bl	printf
	ldr	r0, .L83+4
	bl	puts
	mov	r3, #0
	str	r3, [fp, #-20]
	b	.L80
.L81:
	ldr	r1, [fp, #-128]
	ldr	r2, [fp, #-20]
	mov	r3, r2
	lsl	r3, r3, #1
	add	r3, r3, r2
	lsl	r3, r3, #2
	add	r2, r1, r3
	sub	r3, fp, #140
	ldm	r2, {r0, r1, r2}
	stm	r3, {r0, r1, r2}
	ldr	r3, [fp, #-140]
	mov	r1, r3
	ldr	r0, .L83+8
	bl	printf
	ldr	r3, [fp, #-136]
	mov	r1, r3
	ldr	r0, .L83+12
	bl	printf
	ldr	r3, [fp, #-136]
	and	r3, r3, #255
	str	r3, [fp, #-60]
	ldr	r1, [fp, #-60]
	ldr	r0, .L83+16
	bl	printf
	ldr	r3, [fp, #-136]
	lsr	r3, r3, #8
	str	r3, [fp, #-64]
	ldr	r1, [fp, #-64]
	ldr	r0, .L83+28
	bl	printf
	ldr	r3, [fp, #-64]
	lsl	r3, r3, #4
	ldr	r2, [fp, #-44]
	add	r3, r2, r3
	ldrh	r3, [r3, #14]
	str	r3, [fp, #-68]
	ldr	r2, [fp, #-68]
	mov	r3, r2
	lsl	r3, r3, #2
	add	r3, r3, r2
	lsl	r3, r3, #3
	mov	r2, r3
	ldr	r3, [fp, #-48]
	add	r3, r3, r2
	ldr	r3, [r3]
	ldr	r2, [fp, #-40]
	add	r3, r2, r3
	mov	r1, r3
	ldr	r0, .L83+32
	bl	printf
	mov	r0, #10
	bl	putchar
	ldr	r3, [fp, #-20]
	add	r3, r3, #1
	str	r3, [fp, #-20]
.L80:
	ldr	r2, [fp, #-124]
	ldr	r3, [fp, #-20]
	cmp	r2, r3
	bhi	.L81
	ldr	r3, [fp, #-16]
	add	r3, r3, #1
	str	r3, [fp, #-16]
.L79:
	ldr	r3, [fp, #-16]
	ldr	r2, [fp, #-36]
	cmp	r2, r3
	bhi	.L82
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, lr}
	add	sp, sp, #16
	bx	lr
.L84:
	.align	2
.L83:
	.word	.LC119
	.word	.LC120
	.word	.LC121
	.word	.LC122
	.word	.LC123
	.word	.LC124
	.word	.LC125
	.word	.LC126
	.word	.LC127
	.size	print_relocation_table, .-print_relocation_table
	.ident	"GCC: (GNU Tools for Arm Embedded Processors 7-2018-q2-update) 7.3.1 20180622 (release) [ARM/embedded-7-branch revision 261907]"
