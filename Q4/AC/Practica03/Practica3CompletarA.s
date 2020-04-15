.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo
	movl 	$1, -8(%ebp)
	movl	12(%ebp), %esi		# elements
for:			
	movl    8(%ebp), %ecx           # @vec[0]
	cmpl 	-8(%ebp), %esi
	jle	fifor
	movl	-8(%ebp), %ebx		# i
	movl	(%ecx, %ebx, 4), %ecx	# ecx = vector[i]
if:
	cmpl	 %ecx, -4(%ebp)	
	jge    	endif
	movl	 %ecx, -4(%ebp)
endif:
	incl 	-8(%ebp)
	jmp 	for
fifor:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
