#lang racket

; add squares of list

( define (sumsq l)
   (if (null? l)
       0
       ( + (expt ( car l) 2 )
           (sumsq (cdr l) )
       )
   )
)