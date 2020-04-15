.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo    
		movl 		$0, %ebx      # contador = 0;
		movl 		8(%ebp), %esi     # @mata
		movl 		12(%ebp), %edi    # @matb
		movl  		16(%ebp), %edx     # %edx ← n
		imul		%edx, %edx     # %edx ← n*n
loop:	cmpl 		%edx, %ebx
		jge 		filoop
		movdqu		(%ebx, %esi), %xmm1
		paddb		%xmm1, %xmm1
		paddb		%xmm1, %xmm1
		paddb		%xmm1, %xmm1
		paddb		%xmm1, %xmm1
		movdqu		%xmm1, (%ebx, %edi)
		addl 		$16,	 %ebx
		jmp 		loop
filoop:

# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
