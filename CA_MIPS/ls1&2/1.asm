.data
myMsg: .asciiz "Enter a number: "

.text
main:
    la $a0, myMsg
    li $v0, 4
    syscall

    li $v0, 5
    syscall

    move $a0, $v0

    li $v0, 1
    syscall

    li $v0, 10
    syscall