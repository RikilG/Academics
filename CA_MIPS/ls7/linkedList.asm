.data
input:  .asciiz "enter 0 to stop: "
output: .asciiz "Linked List: "
space:  .asciiz " "

.text
main:

li $s0, 0   # head = NULL
li $s1, 0   # tail = NULL

# start by getting input
getInput:
    la $a0, input
    li $v0, 4
    syscall

    li $v0, 5
    syscall

    # 0 input indicates end of input. so run program
    beq $v0, $0, runProgram

    move $a0, $v0
    jal createNode
    j getInput


runProgram:
    # traverse the input linked list
    jal traverseList
    # end of program
    li $v0, 10
    syscall


createNode:
    move $t0, $a0   # copy data to $t0 so we van use $a0
    # create a new node, addr is in $v0 after allocation
    li $a0, 8
    li $v0, 9
    syscall
    # if root is NULL, then
    beq $s0, $0, createRoot
    # else, tail has the last created node's addr($s1)
    sw $v0, 4($s1)  # set previous node's(addr in tail) "next-addr" to new node
    move $s1, $v0   # set new node as tail now
    sw $t0, 0($s1)  # set data of new node
    sw $0, 4($s1)   # set "next-addr" pointer to NULL

    jr $ra

    createRoot:
    move $s0, $v0   # set head
    move $s1, $v0   # set tail
    sw $t0, 0($s0)  # copy data from $t0
    sw $0, 4($s0)   # set "next-addr" to NULL

    jr $ra


traverseList:
    la $a0, output
    li $v0, 4
    syscall

    # start from head node = $s0
    # load current node addr in $t0
    move $t0, $s0   # initially, current node is head itself
    loop:
        # base case: check if ptr is NULL
        beq $t0, $0, done
        # print current node data
        lw $a0, 0($t0)
        li $v0, 1
        syscall
        # print a space
        la $a0, space
        li $v0, 4
        syscall
        # move to next node
        lw $t0, 4($t0)
        j loop
    done:
    jr $ra