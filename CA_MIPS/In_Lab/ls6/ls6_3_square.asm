.data
input:	.asciiz	"Enter side: "
star:	.asciiz	"*"
nline:	.asciiz	"\n"

.text
main:
	la $a0, input
	li $v0, 4
	syscall
	
	li $v0, 5
	syscall
	
	move $s0, $v0
	
	# USING FUNCTION CALLS
	li $t1, 0	# variable i
	
	loop1:		# for(int i=0;i!=side;i++)
		move $a0, $s0
		addi $sp, $sp, -4
		sw $t1, ($sp)
		jal print_star_line
		lw $t1, ($sp)
		addi $sp, $sp, 4
		add $t1, $t1, 1
		bne $t1, $s0, loop1
	
	
	li $v0, 10
	syscall

print_star_line:
	addi $sp, $sp, -4
	sw $a0, ($sp)
	move $t0, $a0
	li $t2, 0	# variable j; resets to zero after every loop
	loop2:		# for(int j=0;j!=side;j++)
		la $a0, star
		li $v0, 4
		syscall
		add $t2, $t2, 1
		bne $t2, $t0, loop2
	la $a0, nline
	li $v0, 4
	syscall
	lw $a0, ($sp)
	addi $sp, $sp, 4
	jr $ra
