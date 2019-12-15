.data
no1:    .asciiz "Enter double 1: "
no2:    .asciiz "Enter double 2: "
addn:   .asciiz "Addition is: "
subn:   .asciiz "Subtraction is: "
newline:.asciiz "\n"

.text
main:

    # scan first double
    la $a0, no1
    li $v0, 4
    syscall
    li $v0, 7
    syscall
    mov.d $f2, $f0

    # scan second double
    la $a0, no2
    li $v0, 4
    syscall
    li $v0, 7
    syscall
    mov.d $f4, $f0

    # add and print
    add.d $f12, $f2, $f4
    li $v0, 3
    syscall
    # newline
    la $a0, newline
    li $v0, 4
    syscall

    # sub and print
    sub.d $f12, $f2, $f4
    li $v0, 3
    syscall
    # newline
    li $v0, 4
    syscall

    # end of program
    li $v0, 10
    syscall