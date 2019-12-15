.data
    str0:
        .asciiz "\nMul:"
    str1:
        .asciiz "\nDiv:"
    f1:
        .float 3.0
    f2:
        .float 7.0
.text
main:
    l.s $f2, f1
    l.s $f4, f2
    la $a0, str0
    li $v0, 4
    syscall
    mul.s $f12, $f4, $f2
    li $v0, 2 # print from $a0
    syscall
    la $a0, str1
    li $v0, 4
    syscall
    div.s $f12, $f4, $f2
    li $v0, 2 # print from $a0
    syscall
    la $a0, str0
    li $v0, 4
    syscall
    # mfhi $a0
    # li $v0, 2 # print from $a0
    # syscall
    # Modify to also print the modulo / remainder
    li $v0, 10
    syscall