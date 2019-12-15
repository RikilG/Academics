#lang racket


(define ans 0)
(display "Take Input List : ")
(define arr (map string->number (string-split (read-line))))
(define (sumUpRecursive arr) (if (null? arr) 0 (+ (car arr) sumUpRecursive (cdr arr))))
(sumUpRecursive arr)
