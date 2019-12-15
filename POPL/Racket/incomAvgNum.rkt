#lang racket

(define (avgnums l)
  (let ( (sum 0) (count 0) )
    (dolist (item 1)
            (begin (set! sum ( + sum item) )
                   (set! count (1+ count)))))
  (