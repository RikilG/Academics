.data
	str0:
	.asciiz "\nMul:"
	str1:
	.asciiz "\nDiv:"
	w1:
	.word 300
	w2:
	.word 7
	
.text
main:
	lw $t0, w1
	lw $t1, w2
	la $a0, str0
	li $v0, 4
	syscall
	mul $a0, $t0, $t1
	li $v0,1
	# print from $a0
	syscall
	la $a0, str1
	li $v0, 4
	syscall
	div $a0, $t0, $t1
	li $v0,1
	# print from $a0
	syscall
	# Modify to also print the modulo / remainder
	li $v0,10
	syscall
