.data
space:	.asciiz	" "

.text
main:
li $s0, 0	# s0 always points to root node of binary tree, initially NULL

get_input:	# get num to be inserted into tree, 0 = terminates
	li $v0, 5	# get input from user
	syscall

	beq $v0, $zero, break_of_loop	# stop input if zero is entered

	move $a0, $v0	# $a0=number to be inserted
	move $a1, $s0	# $a1=ptr to root(addr of root), initially NULL

	jal insert_in_tree

	move $s0, $v0	# return value $v0 is addr to root storing in $s0
	j get_input

break_of_loop: # label to exit from above loop
	move $a0, $s0
	jal inorder_traversal	# inorder traversal where $a0 now holds address of root node

	# end of program
	li $v0, 10
	syscall

insert_in_tree:
	# check for base case(root==NULL)
	# if(root==NULL) then
	bne $a1, $zero, not_base_case	

	move $t0, $a0	# store data from $a0 in temp reg

	li $a0, 12	# asking for 12 bytes (4 addr + 4 addr + 4 int=data)
	li $v0, 9
	syscall		# now $v0 points to allocated memory

	move $a0, $t0	# move data back to $a0
	sw $zero, 0($v0)# set left addr pointer to NULL
	sw $zero, 4($v0)# set right addr pointer to NULL
	sw $a0,	8($v0)	# store data in node

	jr $ra		# end of case if(root==NULL)
	# endif

	not_base_case:
		# if(root!=NULL) // if root already has a value
		# store current values in stack - $a0, $a1, $ra
		addi $sp, $sp, -12
		sw $a0, 0($sp)	# number value
		sw $a1, 4($sp)	# root address
		sw $ra, 8($sp)	# return address as this is a recursive call

		lw $t0, 0($a1)	# left ptr addr
		lw $t1, 4($a1)	# right ptr addr
		lw $t2, 8($a1)	# data in current node

		# if(node->data < $a0) //go left
		# if(node->data > $a0) //go right
		blt $t2, $a0, right
		
		left:
			addi $a1, $a1, 0	# in this case, 0($a0) points to left
			move $s1, $a1
			lw $a1, ($a1)
			jal insert_in_tree	# returned new node addr is in $v0 will be stored in returnNonBase
			j returnNonBase

		right:
			addi $a1, $a1, 4	# in this case, 4($a0) points to right
			move $s1, $a1
			lw $a1, ($a1)
			jal insert_in_tree	# returned new node addr is in $v0 will be stored in returnNonBase
			#j returnNonBase

		returnNonBase:
			sw $v0, ($s1)
			lw $a0, 0($sp)
			lw $a1, 4($sp)
			lw $ra, 8($sp)
			addi $sp, $sp, 12
			move $v0, $a1	# this will be stored back in $s0 in main function call. so in the last recursive call, this will be the root address
			jr $ra
##########END OF INSERT_IN_TREE FUNCTION##########

inorder_traversal:
	# $a0 holds root addr initially
	beq $a0, $zero, return_inorder

	addi $sp, $sp, -8
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	
	# traverse left, print middle, traverse right
	lw $a0, 0($a0)	# load left addr
	jal inorder_traversal

	# print curr node data
	lw $a0, 4($sp)	# first get curr node address
	lw $a0, 8($a0)	# next load data of this node
	li $v0, 1
	syscall		# this node's data is printed now

	lw $a0, 4($a0)	# load right addr
	jal inorder_traversal

	# restore register values
	lw $a0, 4($sp)
	lw $ra, 0($sp)
	addi $sp, $sp, 8

	return_inorder:
	jr $ra
##########END OF INORDER_TRAVERSAL FUNCTION##########
