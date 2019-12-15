.data
input:	.asciiz	"Enter number: "
star:	.asciiz	"*"
nline:	.asciiz	"\n"

.text
main:
	la $a0, input
	li $v0, 4
	syscall
	
	li $v0, 5
	syscall
	
	move $a0, $v0	# $a0 is the input number => fact($a1) = $a1*fact($a1-1)
	
	jal fact
	
	# ans is stored in $v0
	move $a0, $v0
	
	li $v0, 1
	syscall
	
	li $v0, 10
	syscall
	
	

fact:
	# if arg is 0, then return with 1 as ans
	beq $a0, $zero, return
	
	# store current arg and return address
	addi $sp, $sp, -8
	sw $a0, ($sp)
	sw $ra, 4($sp)
	
	addi $a0, $a0, -1
	jal fact
	
	# restore this functions actual arg and return address
	lw $a0, ($sp)
	lw $ra, 4($sp)
	addi $sp, $sp, 8
	
	# multiply this functions arg to return value of recursive fact => n*fact(n-1)
	mul $v0, $a0, $v0
	jr $ra
	
	return:
	li $v0, 1	# load ans as 1
	jr $ra
