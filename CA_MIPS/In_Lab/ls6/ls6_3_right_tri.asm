.data
input:	.asciiz	"Enter base of triangle: "
star:	.asciiz	"*"
nline:	.asciiz	"\n"
END:	.asciiz	"\nEnd of Program\n"

.text
main:
	la $a0, input
	li $v0, 4
	syscall
	
	li $v0, 5
	syscall
	
	move $s0, $v0
	
	li $t0, 0
	loop_rows:
		# store temp reg
		addi $sp, $sp, -4
		sw $t0, ($sp)
		
		move $a0, $t0
		addi $a0, $a0, 1
		jal print_star_line
		
		# restore temp reg value
		lw $t0, ($sp)
		addi $sp, $sp, 4
		addi $t0, $t0, 1
		bne $t0, $s0, loop_rows
	
	la $a0, END
	li $v0, 4
	syscall
	
	li $v0, 10
	syscall

print_star_line:
	# store current arg
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
	# print new line '\n'
	la $a0, nline
	li $v0, 4
	syscall
	
	# restore current arg and return
	lw $a0, ($sp)
	addi $sp, $sp, 4
	jr $ra
