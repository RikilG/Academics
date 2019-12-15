#lang racket

( define ( zeros ls count )
   ( cond
      ( ( null? ls) count)
      ( ( zero? (car ls) )
        ( zeros (cdr ls) ( + count 1) ) )
      ( else (zeros (cdr ls) count ) )
    )
)

; call using ( zeros '(1 2 0 0 2 4) 0)