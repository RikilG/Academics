# code for bubble sort using the given boilerplate code in labsheet

.data
list:   .word   17, 5, 92, 87, 41, 10, 23, 55, 72, 36
space:  .asciiz " "
debug:  .asciiz "debug\n"

.text
main:
li $s7,10       # size of the list(sz)
addi $s3,$s7,-1 # $s3 = Stop = sz-1
la $a0, list

# bubble sort code here
outer_loop:
    la $s0, list            # load list base address as this changes every iteration
    inner_loop:
        addi $s1, $s0, 4    # next addr = curr addr + 1 (incr by 4 bytes for word)
        lw $t4, ($s0)       # list[curr]
        lw $t5, ($s1)       # list[next]
        ble $t4, $t5, no_swap#do not swap if list[curr] <= list[curr+1]
        swap:
            sw $t4, ($s1)
            sw $t5, ($s0)
        no_swap:
        addi $s0, $s0, 4    # increment $s0 for next iteration
        # calc end address
        sll $a1, $s3, 2
        add $s4, $a0, $a1
        blt $s0, $s4, inner_loop# do this while s0 is < s3 (= s7-1 = arrlen(list)-1)
    addi $s3, $s3, -1       # decrement $s3 by 1 to run for $s3 no of 
    bne $s3, $zero, outer_loop

exit:
    la $t0,list
    li $t2,0    # as a counter while printing the list

print:
    # print the array here
    # print the current word
    lw $a0,($t0)    # load current word in $a0
    li $v0,1
    syscall

    # print space
    la $a0,space
    li $v0,4
    syscall

    addi $t0,$t0,4  #point to next word
    addi $t2,$t2,1  #counter++
    blt $t2,$s7,print

exit_prog:
    # end of program
    li $v0,10
    syscall