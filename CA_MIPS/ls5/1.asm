# program to check whether input string is a palindrome or not

.data
input:  .asciiz "Enter a string: "
str:    .space  20
is_pal: .asciiz "Entered string is a PALINDROME"
not_pal:.asciiz "Entered string is a NOT a PALINDROME"
newLine:.asciiz "\n"

.text
main:
# print input string
la $a0, input
li $v0, 4
syscall

# take input string
li $v0, 8
la $a0, str # address to store input string
li $a1, 20  # no of characters to scan
syscall

# print string
li $v0, 4
syscall

# find the length of string
add $t0, $a0, $zero    # copy string address to $t0
li $t1, 0               # count variable init to 0
lb $t3, newLine         # load newline character
loop:
    lb $t2, ($t0)
    beq $t2, $t3, loop_break
    beq $t2, $zero, loop_break
    addi $t1, $t1, 1    # increment loop counter(not really necessary)
    addi $t0, $t0, 1    # increment address to end of string
    j loop

loop_break:
    # currently $t0 points to \0 or \n. so move back one step
    addi $t0, $t0, -1   # now points to last char of str
    add $t2, $a0, $zero# load base address to $t2

palin_loop:
    bge $t2, $t0, lbl_pal#palindrome found as all chars are equal
    # $t2-first character in string
    # $t0-last character in string
    lb $t3, ($t2)       # load first char pointed
    lb $t4, ($t0)       # load second char pointed
    bne $t3, $t4, lbl_not_pal
    addi $t2, $t2, 1
    addi $t0, $t0, -1
    j palin_loop

lbl_not_pal:
    # print not a palindrome
    la $a0, not_pal
    li $v0, 4
    syscall
    j exit

lbl_pal:
    # print is a palindrome
    la $a0, is_pal
    li $v0, 4
    syscall

exit:
    # End of program
    li $v0, 10
    syscall