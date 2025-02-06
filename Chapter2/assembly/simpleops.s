	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 15, 0	sdk_version 15, 2
	.syntax unified
	.globl	_main                           @ -- Begin function main
	.p2align	2
	.code	32                              @ @main
_main:
@ %bb.0:
	sub	sp, sp, #12
	mov	r0, #0
	str	r0, [sp, #8]
	mov	r1, #1
	str	r1, [sp, #4]
	ldr	r1, [sp, #4]
	add	r1, r1, #2
	str	r1, [sp, #4]
	ldr	r1, [sp, #4]
	sub	r1, r1, #14
	str	r1, [sp, #4]
	ldr	r2, [sp, #4]
	mov	r3, #100
	mul	r1, r2, r3
	str	r1, [sp]
	ldr	r1, [sp, #4]
	ldr	r2, [sp]
	add	r2, r2, r2, lsl #1
	add	r1, r1, r2, lsl #1
	str	r1, [sp, #4]
	add	sp, sp, #12
	bx	lr
                                        @ -- End function
.subsections_via_symbols
