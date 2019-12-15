#lang racket

(require racket/include)
(include "q1.rkt")
(require racket/trace)
(trace sumUpRecursive)
(trace sumUpTailRecursive)
(sumUpRecursive '(1 2 4 23))
(sumUpTailRecursive '(1 2 4 23) 0)