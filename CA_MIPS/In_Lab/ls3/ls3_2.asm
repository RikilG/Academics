.data

.text

main:
	# read float 1
	li $v0, 6
	syscall
	mov.s $f2, $f0
	
	# read float 2  
	li $v0, 6
	syscall
	mov.s $f3. $f0
	
	add.s $f12, $f2, $f3
	
	li $v0, 2
	syscall
	
	li $v0, 10
	syscall
