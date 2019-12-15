# This program uses *bne* in loop construct

.data
my_str:	.asciiz "This is my string."	# has 18 characters

.text
main:
	# load address of string into a0
	la $a0, my_str
	li $v0, -1		# initialize count variable to -1: as we are also reading '\0' character
	
	strlen:
		lb $t0, ($a0)			# load value pointed by a0 to t0
		addi $a0, $a0, 1		# increment a0 ( like incrementing pointer)
		addi $v0, $v0, 1		# increment count
		bne $t0, $zero, strlen	# check condition for '\0' and loop again
	
	# move and print value to console
	move $a0, $v0
	li $v0, 1
	syscall
	
	# exit program
	li $v0, 10
	syscall
