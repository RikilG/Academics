.data
myMsg: .asciiz "Hello World!!!\n"

.text
main:
    la $a0, myMsg
    li $v0, 4
    syscall

    # Program Exit
    li $v0, 10
    syscall