#lang racket

;factorial using tail recursion
; tail recursion: accumulator

(define (tail-fact n [acc 1])
  (if (= n 1)
      acc
      (tail-fact (- n 1) (* n acc) )
   )
)

; call using