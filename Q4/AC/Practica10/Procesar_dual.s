	.text
	.align 4
	.globl procesar
	.type	procesar, @function

procesar:
	 	pushl %ebp
        movl %esp, %ebp
        subl $16, %esp
        pushl %ebx
		pushl %esi
		pushl %edi
	    movl $0, %ebx      		# contador = 0;
		movl 8(%ebp), %esi     	# @mata
		movl 12(%ebp), %edi    	# @matb
       	movl  16(%ebp), %edx

		movl $15, %ecx
		test %ecx, %esi
		jne	no16mat				# test mata

		movl $15, %ecx
		test 
		jne	no16mat

loop1:
		cmpl %edx, %ebx
		jge filoop
		movdqa	(%ebx, %esi), %xmm1
		paddb	%xmm1, %xmm1
		paddb	%xmm1, %xmm1
		paddb	%xmm1, %xmm1
		paddb	%xmm1, %xmm1
		movdqa	%xmm1, (%ebx, %edi)
		addl 	$16, %ebx
		jmp 		loop1

no16mat:
		cmpl %edx, %ebx
		jge filoop
		movdqu	(%ebx, %esi), %xmm1
		paddb	%xmm1, %xmm1
		paddb	%xmm1, %xmm1
		paddb	%xmm1, %xmm1
		paddb	%xmm1, %xmm1
		movdqu	%xmm1, (%ebx, %edi)
		addl 	$16,	 %ebx
		jmp 		no16mat;

filoop:
		popl %edi
		popl %esi
		popl %ebx
		movl %ebp, %esp
		popl %ebp
		ret
