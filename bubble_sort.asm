# =============================================================================================================================
# ============================================= ALGORITMO BUBBLE SORT CRESCENTE ===============================================
# =============================================================================================================================

.data
	valores: 2, 3, 1
.text
.globl main
main:
	# argumentos da função
	li $a0, 3		# tamanho do array
	la $a1, valores		# endereço do primeiro elemento do array
	
	# chamando a função de ordenação
	jal bubble_sort
end:
	li $v0, 10
	syscall
	
# função de ordenação
bubble_sort:
	addi $sp, $sp, 40	ajusta a pilha pra guardar os 10 valores que vão ser usados
	
	#guardando os valores na pilha:
	sw $ra, 36 ($sp)
	sw $a0, 32 ($sp)
	sw $a1, 28 ($sp)
	sw $t0, 24 ($sp)
	sw $t1, 20 ($sp)
	sw $t2, 16 ($sp)
	sw $t3, 12 ($sp)
	sw $t4, 8 ($sp)
	sw $t5, 4 ($sp)
	sw $t6, 0 ($sp)
	
	li $t0, 1	# troca = 1
	
	while:
		bne $t0, 1, end_while	# se $t0 diferente de 1 saia do loop
		li $t0, 0	# troca = 0
		move $t1, $zero	# i = 0
	
		for:
			mul $t1, $zero, 4 	# calculando o valor do offset para pegar valores[i]
			add $t2, $t2, $a1	# adicionando o offset para encontrar o endereço de valor
			lw $t3, 0($t2)		# aux = valores[i]
	
	
	
	
	
	
	
	
	
	