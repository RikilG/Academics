.data

myMsg: .asciiz "Enter number-1. " 
myMsg2: .asciiz "Enter number-2." 


.text

main:
	
	la $a0,myMsg
	li $v0,4
	syscall

	li $v0,5
	syscall

	move $a0,$v0

	la $a0,myMsg2
	li $v0,4
	syscall

	li $v0,5
	syscall

	move $a1,$v0

	add $a0,$a0,$a1
	
	li $v0,1
	syscall 

	li $v0,10
	syscall
	
