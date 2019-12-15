# this program finds multiples of number below 100

.data
input:  .asciiz "Enter number: "
space:  .asciiz " "

.text
main:
# print input string
la $a0, input
li $v0, 4
syscall

# take input number
li $v0, 5
syscall
move $t1, $v0

# set multiplier
li $t0, 1
# set max number
li $a1, 100

loop:
    mul $t2, $t0, $t1
    # break if number is > 100
    bgt $t2, $a1, exit
    # print number
    move $a0, $t2
    li $v0, 1
    syscall
    # print space
    la $a0, space
    li $v0, 4
    syscall
    # increment count
    addi $t0, $t0, 1
    j loop

exit:
    # End of program
    li $v0, 10
    syscall