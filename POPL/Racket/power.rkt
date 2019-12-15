#lang racket

; power of a number

( define pow ( lambda (m n)
                ( if (= n 0) 1 ( * m (pow m (- n 1))))
                )
   )

; call using ( pow 4 5 )