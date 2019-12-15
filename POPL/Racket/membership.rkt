#lang racket

(define (member a lis)
  ( cond
     ( (null? lis) "Element not found" )
     ( (eq? a (car lis)) #t )
     ( else (member a (cdr lis) ) )
   )
)

; call using ( member 2 '(1 2 3 4 5) )