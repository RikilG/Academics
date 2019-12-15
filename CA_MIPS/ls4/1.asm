# this program checks whether the given int is even or odd
.data
    input:  .asciiz "Enter input number: "
    odd:    .asciiz "\nInput number is ODD\n"
    even:   .asciiz "\nInput number is EVEN\n"

.text
main:

# print statement
la $a0, input
li $v0, 4
syscall

# take input number
li $v0, 5
syscall
move $a0, $v0

# check if number is odd by anding with 1
andi $t0, $a0, 1
beq $t0, $zero, EVEN

ODD:
    # print number is odd
    la $a0, odd
    li $v0, 4
    syscall
    j EXIT

EVEN:
    # print number is even\
    la $a0, even
    li $v0, 4
    syscall

EXIT:
    # End of program
    li $v0, 10
    syscall