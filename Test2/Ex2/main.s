	.file	"main.c"
	.text
	.section	.rodata
.LC2:
	.string	"Choose how to sort: "
.LC3:
	.string	"%d"
.LC4:
	.string	"Not a valid input\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$400, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, %edi
	call	time@PLT
	movl	%eax, %edi
	call	srand@PLT
	movq	compareModel@GOTPCREL(%rip), %rax
	movq	%rax, -384(%rbp)
	movq	compareModelDesc@GOTPCREL(%rip), %rax
	movq	%rax, -376(%rbp)
	movq	compareMaxSpeed@GOTPCREL(%rip), %rax
	movq	%rax, -368(%rbp)
	movq	compareMaxSpeedDesc@GOTPCREL(%rip), %rax
	movq	%rax, -360(%rbp)
	movq	comparePrice@GOTPCREL(%rip), %rax
	movq	%rax, -352(%rbp)
	movq	comparePriceDesc@GOTPCREL(%rip), %rax
	movq	%rax, -344(%rbp)
	movl	$0, -388(%rbp)
	jmp	.L2
.L3:
	leaq	-336(%rbp), %rdx
	movl	-388(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rdx, %rax
	movq	%rax, %rdi
	call	randomName@PLT
	movl	$3000, %esi
	movl	$100, %edi
	call	randint@PLT
	movl	%eax, %edx
	movl	-388(%rbp), %eax
	cltq
	salq	$5, %rax
	addq	%rbp, %rax
	subq	$315, %rax
	movb	%dl, (%rax)
	movsd	.LC0(%rip), %xmm0
	movq	.LC1(%rip), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %xmm0
	call	randReal@PLT
	movq	%xmm0, %rax
	movl	-388(%rbp), %edx
	movslq	%edx, %rdx
	salq	$5, %rdx
	addq	%rbp, %rdx
	subq	$312, %rdx
	movq	%rax, (%rdx)
	addl	$1, -388(%rbp)
.L2:
	cmpl	$9, -388(%rbp)
	jle	.L3
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	-392(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-392(%rbp), %eax
	testl	%eax, %eax
	jle	.L4
	movl	-392(%rbp), %eax
	cmpl	$6, %eax
	jle	.L5
.L4:
	movq	stderr(%rip), %rax
	movq	%rax, %rcx
	movl	$18, %edx
	movl	$1, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	call	fwrite@PLT
	movl	$-1, %eax
	jmp	.L7
.L5:
	movl	-392(%rbp), %eax
	subl	$1, %eax
	cltq
	movq	-384(%rbp,%rax,8), %rdx
	leaq	-336(%rbp), %rax
	movq	%rdx, %rcx
	movl	$32, %edx
	movl	$10, %esi
	movq	%rax, %rdi
	call	qsort@PLT
	leaq	-336(%rbp), %rax
	movq	%rax, %rdi
	call	print@PLT
	movl	$0, %eax
.L7:
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L8
	call	__stack_chk_fail@PLT
.L8:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.long	0
	.long	1090021888
	.align 8
.LC1:
	.long	0
	.long	1083129856
	.ident	"GCC: (Ubuntu 11.2.0-19ubuntu1) 11.2.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
