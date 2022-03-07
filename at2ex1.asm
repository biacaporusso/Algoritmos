.data

mVetA: .asciiz "Vetor A: \n"
mVetB: .asciiz "Vetor B: \n"
mN: .asciiz "N: "
	
.text

li $v0, 4	# codigo de impressao de string
la $a0, mN	# carrega o endere�o da string
syscall		# impress�o da string

li $v0, 5	# codigo de leitura de inteiro
syscall		# leitura do inteiro
move $t1, $v0	# $t1 = N

li $t0, 0	# $t0 = i 

li $v0, 4	# codigo de impressao de string
la $a0, mVetA	# carrega o endere�o da string
syscall		# impress�o da string

mul $s1, $t1, 4	# $s1 = quantidade de mem�ria a ser alocada (4*N)
loopLeitura:
	beq $t0, $t1, endLoopLeitura	# quando $t0 = $t1 termina a leitura
	
	li $v0, 5	# codigo de leitura de inteiro
	syscall		# leitura do inteiro
	move $t2, $v0	# $t2 = aux (elemento inserido)
	
	#mul $s1, $t1, 4	# $s1 = quantidade de mem�ria a ser alocada (4*N)
	move $a0, $s1	# $a0 <- $s1 (argumento da fun��o de alocar)
	li $v0, 9	# codigo de aloca��o din�mica heap
	syscall		# aloca 4*N bytes (endere�o em $v0)
	move $t9, $v0	# move para $t9 o endere�o 
	sw $t2, ($t9)	# 
	add $t9, $t9, 4	# proxima posi��o do vetor
	add $t0, $t0, 1	# i = i+1
	j loopLeitura	
	
endLoopLeitura:
