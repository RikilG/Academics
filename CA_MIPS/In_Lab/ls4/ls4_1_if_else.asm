.data
even_str:	.asciiz "Input integer is even."
odd_str:	.asciiz "Input integer is odd."

.text
main:
	# scan int
	li $v0, 5
	syscall
	
	move $a0, $v0
	
	# and $a0 with 1 to check last binary digit
	andi $a0, $a0, 1
	
	# branch to even label if $a0 is 0
	beq $a0, $zero, even_int
	
	odd_int:
		# input is odd
		la $a0, odd_str
		li $v0, 4
		syscall
		j exit
	
	even_int:
		# input is even
		la $a0, even_str
		li $v0, 4
		syscall
	
	exit:
		# exit program
		li $v0, 10
		syscall
