.data
	array:
		.align 2	# alinha palavra na posição correta
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
	
# --------------------------------------------------------------------------------------------------------
	a) ordenarArray:
	# i = 0
	move $t0, $zero	# indice do array
	li $t9, 9999	# auxiliar pra fazer as comparações
	# enquanto i < tamanho do vetor:
	beq $t0, $t1, saiOrdenacao	# for i=0; i<N, i++
	# pega o elemento do vetor [i]
	lw $a2, array($t0)
	# se vetor [i] < x entao vetor[i] = valor
	blt $a2, $t9, insereVetor
	# senão, i++
	add $t0, $t0, 1
	
	insereVetor
	
	int k = 9999;
	for (i=0; i<N; i++) {
	    for (j=0; j<N; j++) {
	        if (vet[j] < k) {
	            ordenado[j] = vet[j];
	
	b) somaPares:
	# i = 0
	# enquanto i < tamanho do vetor:
	# se vetor[i] % 2 = 0 então é par
	# add vetor[i] em um registrador
	# i++
	
	c, d) verifica k:
	# leitura de inteiro K
	# i = 0
	# enquanto i < tamanho do vetor:
	# se vetor[i] > k então registrador = registrador + 1
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
