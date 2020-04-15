.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo
	movl	$0,-4(%ebp)	#res = 0
	movl 	$0,-8(%ebp)	#i = 0
	movl 	12(%ebp),%ecx	#ecx = salto
for1:
	cmpl 	$3,-8(%ebp)	#i - 3 >= 0
	jge 	fifor1		
	movl 	$0,-12(%ebp)	#j = 0
for2:
	cmpl 	$3,-12(%ebp)	#j - 3 >= 0
	jge 	fifor2		
	movl	-8(%ebp),%esi	#esi = i
	movl	-12(%ebp),%ebx	#ebx = j
	imul 	$3,%esi,%edx	#edx = i * 3
	addl 	%ebx,%edx	#edx = i*3+j
        imul    $4,%edx,%edx	#edx = (i*3+j)*4
	addl 	8(%ebp),%edx	#edx = @Matriz + (i*3+j)*4 (edx = Matriz[i][j])
	movl 	(%edx), %edx
	addl	%edx,-4(%ebp)	#res += Matriz[i][j]
	addl	%ecx,-12(%ebp)	#j += salto
	jmp	for2		
fifor2:
	addl 	%ecx,-8(%ebp)	#i += salto
	jmp 	for1
fifor1:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
