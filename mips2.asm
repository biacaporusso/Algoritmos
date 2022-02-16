.data
	array:
		.align 2	# alinha palavra na posi��o correta
		.space 20	# array de 5 inteiros
		
	ent: .asciiz "Insira os valores do vetor: "
	
	arrayOrdenado:
		.align 2
		.space 20

.text
	main:
		move $t0, $zero	# indice do array
		li $t1, 20	# tamanho do array
		li $v0, 4	# codigo de impressao de string
		la $a0, ent	# carrega o endere�o da string
		syscall		# impress�o da string
	
	leitura:
		beq $t0, $t1, saileitura
		li $v0, 5	# codigo de leitura de inteiro
		syscall		# leitura do inteiro
		move $t2, $v0	# movendo o inteiro  inserido para o registrador $t2
		sw $t2, $array($t0)	# armazenando o valor inserido no array
		add $t0, $t0, 4		# atualizando o indice do array
		j leitura
	
# --------------------------------------------------------------------------------------------------------
	a) ordenarArray:
	# i = 0
	# enquanto i < tamanho do vetor:
	# pega o vetor [i]
	# se vetor [i] < x entao vetor[i] = valor
	# i++
	
	b) somaPares:
	# i = 0
	# enquanto i < tamanho do vetor:
	# se vetor[i] % 2 = 0 ent�o � par
	# add vetor[i] em um registrador
	# i++
	
	c, d) verifica k:
	# leitura de inteiro K
	# i = 0
	# enquanto i < tamanho do vetor:
	# se vetor[i] > k ent�o registrador = registrador + 1
	# i++
	# verificar tambem 2*k e igual a k
	
	e) atividade 4 fala de inteiros perfeitos
	
	# serve pra ver como joga o elemento do vetor pro terminal de novo (load word/store word)	
	saiDoLoop:
		move $t0, $zero		# indice do array
		imprime:
			beq $t0, $t2, saiDaImpressao
			li $v0, 1
			lw $a0, array($t0)
			syscall
			
			add $t0, $t0, 4
			j imprime