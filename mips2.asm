.data
	array:
		.align 2	# alinha palavra na posição correta
		.space 20	# array de 5 inteiros
	ent: .asciiz "Insira os valores do vetor: "

.text
	main:
		move $t0, $zero	# indice do array
		li $t1, 20	# tamanho do array
		li $v0, 4	# codigo de impressao de string
		la $a0, ent	# carrega o endereço da string
		syscall		# impressão da string
	
	leitura:
		beq $t0, $t1, saileitura
		li $v0, 5	# codigo de leitura de inteiro
		syscall		# leitura do inteiro
		move $t2, $v0	# movendo o inteiro  inserido para o registrador $t2
		sw $t2, $array($t0)	# armazenando o valor inserido no array
		add $t0, $t0, 4		# atualizando o indice do array
		j leitura
	
# -----------------------------------------------------------------------------------------
		
	saiDoLoop:
		move $t0, $zero		# indice do array
		imprime:
			beq $t0, $t2, saiDaImpressao
			li $v0, 1
			lw $a0, array($t0)
			syscall
			
			add $t0, $t0, 4
			j imprime
			
	saiDaImpressao: