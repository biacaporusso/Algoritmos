#
.text

li $a0, 4	# 4 bytes (inteiro)
li $v0, 9	# codigo de aloca��o din�mica heap
syscall		# aloca 4 bytes (endere�o em $v0)
move $t0, $v0	# move para $t0
li $t1, 3 	# aux = 3
sw $t1, ($t0)	# *n = 3
#---------------------------------------------------------------
li $a0, 40 	# 40 bytes (espa�o para 10 inteiros)
li $v0, 9	# codigo de aloca��o din�mica heap
syscall		# aloca 40 bytes
move $t1, $v0	# move para $t1 o endere�o
li $t2, 7	# aux = 7
sw $t2, ($t1)	# v[0] = 7
li $t2, 11	# aux = 11
li $t2, 12($t1)	# v[3] = 11
li $t2, 34 	# aux = 34
sw $t2, 32($t1)	# v[8] = 34
#----------------------------------------------------------------
li $a0, 20	# 20 bytes (espa�o para 20 char)
li $v0, 9	# codigo de aloca��o din�mica heap
syscall		# aloca 20 bytes
move $a0, $v0	# endere�o base da string
li $a1, 20	# numero maximo de caracteres
li $v0, 8	# codigo para leitura de string
syscall		# scanf("%s", s)







