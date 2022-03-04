.data
	ent: .asciiz "Insira o valor de Vet["
	ent2: .asciiz "]: "
	.align 2
	vet:
		#.align 2
		.space 20
		
.text

	main:
		la $a0, vet	# endere�o do vetor como par�metro
		jal leitura 	# jump and link , leitura(vet)
		move $a0, $v0	# endere�o do vetor retornado
		jal escrita 	# escrita(vet)
		li $v0, 10 	# codigo para finalizar o programa
		syscall		# finaliza o programa
		
	leitura:
		move $t0, $a0	# salva o endere�o base de vet
		move $t1, $t0 	# endere�o de vet[i]
		li $t2, 0 	# i = 0		
	
	l:
		la $a0, ent	# carrega o endere�o da string
		li $v0, 4	# codigo de impressao de string
		syscall		# impress�o da string
		move $a0, $t2	# carrega o indice do vetor
		li $v0, 1	# codigo de impress�o de inteiro
		syscall		# imprime o indice i
		la $a0, ent2	# carrega o endere�o da string
		li $v0, 4	# codigo de impressao de string
		syscall		# impress�o da string	
		li $v0, 5	# codigo de leitura de inteiro
		syscall 	# leitura do valor
		sw $v0, ($t1)	# salva o valor lido em vet[i
		add $t1, $t1, 4	# endere�o de vet[i+1]
		add $t2, $t2, 1	# i++
		move $v0, $t0	# endere�o de vet para retorno
		jr $ra		# retorna para a main
		
	escrita: 
		move $t0, $a0	# salva o endere�o base de vet
		move $t1, $t0	# endere�o de vet[i]
		li $t2, 0	# i = 0
	e:	
		lw $a0, ($t1)	# carrega o valor de vet[i]
		li $v0, 1	# codigo de impressao de inteiro
		syscall		# imprime vet[i]
		li $a0, 32	# codigo ASCII para espa�o
		li $v0, 11	# codigo de impress�o de caractere
		syscall		# imprime um espa�o
		add $t1, $t1, 4	# ndere�o de vet[i+1]
		add $t2, $t2, 1	# i++
		blt $t2, 5, e	# if (i < 5) goto e
		move $v0, $t0	# endere�o de vet para retorno
		jr $ra		# retorna para a main
	
	
	
	
	
	
	
	
	
	
