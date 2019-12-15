.data
	inum: .word 42
	fnum: .float 0.0
.text
	lw $t0, inum
	mtc1 $t0, $f6
	cvt.s.w $f8, $f6
	s.s $f8, fnum
	mov.s $f12, $f8
	li $v0, 2
	syscall

	cvt.d.s $f6, $f8
	li $v0, 2
	syscall

	li $v0, 10
	syscall
