#lang racket

( define (even x)
   ( if ( = 0 (modulo x 2 ) )
        ( display "even" )
        ( display "odd" )
    )
)