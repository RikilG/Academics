#lang racket

(define (sumUpTailRecursion arr) (if(empty? arr) 0 (+ (first arr) (sumUpTailRecursion (rest arr)))))
(define (length arr) (if(empty? arr) 0 (+ 1 (length (rest arr)))))

;(define ans 0)
(display "Take List Input: ")
(define arr (map string->number (string-split (read-line))))
(display "Sum of the Given List is ")
(sumUpTailRecursion arr)
(display "Length of the List is ")
(length arr)

