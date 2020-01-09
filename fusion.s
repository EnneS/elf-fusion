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
	.file	"fusion.c"
	.text
	.section	.rodata
	.align	2
.LC0:
	.ascii	"Usage:\012%s [ --help ] file1 file2\012\012\000"
	.text
	.align	2
	.global	usage
	.syntax unified
	.arm
	.fpu softvfp
	.type	usage, %function
usage:
	@ args = 0, pretend = 0, frame = 8
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{fp, lr}
	add	fp, sp, #4
	sub	sp, sp, #8
	str	r0, [fp, #-8]
	ldr	r3, .L2
	ldr	r3, [r3]
	ldr	r3, [r3, #12]
	ldr	r2, [fp, #-8]
	ldr	r1, .L2+4
	mov	r0, r3
	bl	fprintf
	nop
	sub	sp, fp, #4
	@ sp needed
	pop	{fp, pc}
.L3:
	.align	2
.L2:
	.word	_impure_ptr
	.word	.LC0
	.size	usage, .-usage
	.section	.rodata
	.align	2
.LC1:
	.ascii	"r\000"
	.align	2
.LC2:
	.ascii	"\012 ____ 2 ____ \000"
	.align	2
.LC3:
	.ascii	"\012 ____ FUSION ____ \000"
	.text
	.align	2
	.global	main
	.syntax unified
	.arm
	.fpu softvfp
	.type	main, %function
main:
	@ args = 0, pretend = 0, frame = 400
	@ frame_needed = 1, uses_anonymous_args = 0
	push	{r4, fp, lr}
	add	fp, sp, #8
	sub	sp, sp, #652
	str	r0, [fp, #-408]
	str	r1, [fp, #-412]
	mov	r3, #0
	str	r3, [fp, #-16]
	mov	r3, #0
	str	r3, [fp, #-20]
	ldr	r3, [fp, #-408]
	cmp	r3, #1
	bgt	.L5
	ldr	r3, [fp, #-412]
	ldr	r3, [r3]
	mov	r0, r3
	bl	usage
	mov	r0, #1
	bl	exit
.L5:
	ldr	r3, [fp, #-412]
	add	r3, r3, #4
	ldr	r3, [r3]
	ldr	r1, .L7
	mov	r0, r3
	bl	fopen
	str	r0, [fp, #-16]
	ldr	r3, [fp, #-412]
	add	r3, r3, #8
	ldr	r3, [r3]
	ldr	r1, .L7
	mov	r0, r3
	bl	fopen
	str	r0, [fp, #-20]
	sub	r3, fp, #148
	ldr	r1, [fp, #-16]
	mov	r0, r3
	bl	read_elf_data
	sub	r3, fp, #276
	ldr	r1, [fp, #-20]
	mov	r0, r3
	bl	read_elf_data
	mov	r0, sp
	sub	r3, fp, #132
	mov	r2, #112
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #148
	ldm	r3, {r0, r1, r2, r3}
	bl	print_section_header_table
	mov	r3, #7
	str	r3, [sp, #112]
	mov	r0, sp
	sub	r3, fp, #132
	mov	r2, #112
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #148
	ldm	r3, {r0, r1, r2, r3}
	bl	print_section_data
	ldr	r0, .L7+4
	bl	puts
	mov	r3, #7
	str	r3, [sp, #112]
	mov	r0, sp
	sub	r3, fp, #260
	mov	r2, #112
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #276
	ldm	r3, {r0, r1, r2, r3}
	bl	print_section_data
	ldr	r0, .L7+8
	bl	puts
	sub	r4, fp, #404
	add	r0, sp, #116
	sub	r3, fp, #276
	mov	r2, #128
	mov	r1, r3
	bl	memcpy
	mov	r0, sp
	sub	r3, fp, #136
	mov	r2, #116
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #148
	ldm	r3, {r1, r2, r3}
	mov	r0, r4
	bl	concat_progbits
	mov	r0, sp
	sub	r3, fp, #388
	mov	r2, #112
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #404
	ldm	r3, {r0, r1, r2, r3}
	bl	print_section_header_table
	mov	r3, #5
	str	r3, [sp, #112]
	mov	r0, sp
	sub	r3, fp, #388
	mov	r2, #112
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #404
	ldm	r3, {r0, r1, r2, r3}
	bl	print_section_data
	mov	r0, sp
	sub	r3, fp, #132
	mov	r2, #112
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #148
	ldm	r3, {r0, r1, r2, r3}
	bl	free_elf_data
	mov	r0, sp
	sub	r3, fp, #260
	mov	r2, #112
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #276
	ldm	r3, {r0, r1, r2, r3}
	bl	free_elf_data
	mov	r0, sp
	sub	r3, fp, #388
	mov	r2, #112
	mov	r1, r3
	bl	memcpy
	sub	r3, fp, #404
	ldm	r3, {r0, r1, r2, r3}
	bl	free_elf_data
	ldr	r0, [fp, #-16]
	bl	fclose
	ldr	r0, [fp, #-20]
	bl	fclose
	mov	r3, #0
	mov	r0, r3
	sub	sp, fp, #8
	@ sp needed
	pop	{r4, fp, pc}
.L8:
	.align	2
.L7:
	.word	.LC1
	.word	.LC2
	.word	.LC3
	.size	main, .-main
	.ident	"GCC: (GNU Tools for Arm Embedded Processors 7-2018-q2-update) 7.3.1 20180622 (release) [ARM/embedded-7-branch revision 261907]"
