.data
readR: .asciiz "enter radius: "
myDb: .double 3.14
peri: .asciiz "Perimeter is : "

.text
main:
    # Read r
    li $v0, 5
    syscall

    mov $t0, $v0

    

    # End Program
    li $v0, 10
    syscall