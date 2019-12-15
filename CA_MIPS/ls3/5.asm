.data
    str0:
        .asciiz "\nMul:"
    str1:
        .asciiz "\nDiv:"
    w1:
        .word 3
    w2:
        .word 7
.text
main:
    lw $t2, w1
    lw $t4, w2
    mtc1 $t2, $f12

    cvt.s.w $f2, $f12
    # li $v0, 2
    # syscall
    cvt.s.w $f12, $f12
    mul.s $f12, $f2, $f12
    li $v0, 2
    syscall
    
    li $v0, 10
    syscall