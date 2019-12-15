.data
str:    .asciiz "hello world!"
newLine:.asciiz "\n"

.text
main:
# print the string
la $a0, str
li $v0, 4
syscall
# print newline
la $a0, newLine
li $v0, 4
syscall

# load str to start counting
la $a0, str

# using bne in loop
# initialize $v0 to -1 to avoid counting \0
# li $v0, -1
# loop2:
#     lb $t0, ($a0)
#     addi $a0, $a0, 1
#     addi $v0, $v0, 1
#     bne $t0, $zero, loop2

# using beq and j in loop
# initialize count to 0(using $v0) (to avoid counting '\0')
li $v0, 0
loop:
    lb $t0, ($a0)
    beq $t0, $zero, BREAK
    addi $a0, $a0, 1
    addi $v0, $v0, 1
    j loop

BREAK:
# print count in $v0
move $a0, $v0
li $v0, 1
syscall

EXIT:
    # End of program
    li $v0, 10
    syscall