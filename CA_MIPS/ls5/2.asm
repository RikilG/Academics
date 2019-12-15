# reverse a input string of length 5

.data
input:  .asciiz "Enter string: "
str:    .space  6
strrev: .space  6
newLine:.asciiz "\n"

.text
main:
# print input string
la $a0, input
li $v0, 4
syscall

# take input
la $a0, str         # address to store string
li $a1, 6           # including \0
li $v0, 8
syscall

add $t1, $a0, $zero # to find addr of last letter
la $t2, newLine     # load newline character

last_letter_loop:
    # to make $t1 point to last letter of str
    lb $t3, ($t1)
    beq $t3, $t2, last_letter_loop_break
    beq $t3, $zero, last_letter_loop_break
    addi $t1, $t1, 1
    j last_letter_loop

last_letter_loop_break:
    # decrement $t1 as it now points to \0 or \n
    addi $t1, $t1, -1
    la $a0, strrev      # load address to reverse string to be stored
    add $t0, $a0, $zero # load base strrev address into $t0
    la $t2, str         # load base address of original string to break loop

reverse_loop:
    # in this loop, we reverse string
    blt $t1, $t2, reverse_loop_break# we have reached start of input string
    lb $t3, ($t1)
    sb $t3, ($t0)
    addi $t1, $t1, -1   # decrement $t1
    addi $t0, $t0, 1    # increment #t0
    j reverse_loop

reverse_loop_break:
    # string has been reversed successfully
    # print reverse string
    la $a0, strrev
    li $v0, 4
    syscall
    # print newLine
    la $a0, newLine
    li $v0, 4
    syscall
    # print actual string
    la $a0, str
    li $v0, 4
    syscall
    # print newLine
    la $a0, newLine
    li $v0, 4
    syscall

exit:
    # End of program
    li $v0, 10
    syscall