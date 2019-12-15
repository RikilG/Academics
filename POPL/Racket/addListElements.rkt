#lang racket

( define ( sum ls )
   ( if (null? ls) 0
        ( + (car ls) (sum (cdr ls) ) )
    )
)

; call using ( sum '(1 2 3) )