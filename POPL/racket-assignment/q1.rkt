#lang racket

(define x '(1 2 3) )

(
    define (sumUpRecursive l) (
        if (null? l) 0
            (+ (car l) (sumUpRecursive (cdr l)))
    )
)

(define (sumUpTailRecursion l [n 0])
    (if (null? l) (+ n 0) (sumUpTailRecursion (cdr l) (+ n (car l))) ))