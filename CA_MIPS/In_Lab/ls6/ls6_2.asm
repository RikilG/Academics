.data
	input:	.space	100
	newLine:.asciiz	"\n"
	vowels: .asciiz "aeiou"

.text

main:
	la $a0, input
	li $a1, 100
	li $v0, 8
	syscall
	
	jal count_vowel
	
	move $a0, $v0
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall

count_vowel:
	addi $sp, $sp, -8	# store input args
	sw $a0, ($sp)
	sw $a1, 4($sp)
	
	li $v0, 0			# ans variable
	la $t2, vowels
	lb $t3, 0($t2)
	lb $t4, 1($t2)
	lb $t5, 2($t2)
	lb $t6, 3($t2)
	lb $t7, 4($t2)
	for_loop:
		lb $t1, ($a0)
		
		beq $t1, $t3, incr
		beq $t1, $t4, incr
		beq $t1, $t5, incr
		beq $t1, $t6, incr
		beq $t1, $t7, incr
		j continue
		
		incr:
			addi $v0, $v0, 1
		continue:
			addi $a0, $a0, 1
			bne $t1, $zero, for_loop
	
	lw $a1, 4($sp)
	lw $a0, ($sp)
	addi $sp, $sp, 8	# retrive stored data
	
	jr $ra
	
	
