.data
stra:   .asciiz "Enter number a: "
strb:   .asciiz "Enter number b: "
newLine:.asciiz "\n"

.text
main:
    # print for a
    la $a0, stra
    li $v0, 4
    syscall

    # read a
    li $v0, 5
    syscall
    move $t0, $v0

    # print for b
    la $a0, strb
    li $v0, 4
    syscall

    # read b
    li $v0, 5
    syscall
    move $t1, $v0

    # add two numbers and print
    add $a0, $t0, $t1
    li $v0, 1
    syscall
    #newline
    la $a0, newLine
    li $v0, 4
    syscall

    # subtract and print
    sub $a0, $t0, $t1
    li $v0, 1
    syscall
    #newline
    la $a0, newLine
    li $v0, 4
    syscall

    # end of program
    li $v0, 10
    syscall