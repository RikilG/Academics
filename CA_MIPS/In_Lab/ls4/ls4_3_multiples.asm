# this program finds multiples of given number below 100

.data
input_str:	.asciiz	"Input a number: "
space:		.asciiz	" "

.text
main:
	# ask a number from the user
	la $a0, input_str
	li $v0, 4
	syscall
	
	li $v0, 5
	syscall
	
	move $t0, $v0 	# $a0 has user input stored
	li	 $a3, 100	# max number until multiples are printed

	# $t0: input number, $a1: multiplier, $a2: current value, $a3: max value, a4: space ;)
	li $a1, 1
	
	factors:
		mul $a2, $t0, $a1
		bgt $a2, $a3, exit
		move $a0, $a2
		li $v0, 1
		syscall
		la $a0, space	# give a space
		li $v0, 4
		syscall
		addi $a1, $a1, 1
		j factors
	
	exit:
		li $v0, 10
		syscall
