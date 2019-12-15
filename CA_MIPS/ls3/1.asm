.data
myfloat:    .float  3.14
mydouble:   .double 3.14
newline:    .asciiz "\n"

.text
main:
    # print float
    l.s $f12, myfloat
    li $v0, 2
    syscall
    # newline
    la $a0, newline
    li $v0, 4
    syscall

    # print double
    l.d $f12, mydouble
    li $v0, 3
    syscall
    # newline
    la $a0, newline
    li $v0, 4
    syscall

    # read float
    li $v0, 6
    syscall
    # print float
    mov.s $f12, $f0
    li $v0, 2
    syscall
    # newline
    la $a0, newline
    li $v0, 4
    syscall

    # read double
    li $v0, 7
    syscall
    # print float
    mov.d $f12, $f0
    li $v0, 3
    syscall
    # newline
    la $a0, newline
    li $v0, 4
    syscall

    # end of program
    li $v0, 10
    syscall