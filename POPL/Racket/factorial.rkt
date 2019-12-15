#lang racket

; factorial

( define factorial (lambda(n)
                     ( if (< n 2)
                          1
                          (* n (factorial (- n 1)))
                      )
                    )
)

; call using 