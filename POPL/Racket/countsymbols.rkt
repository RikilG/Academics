#lang racket

; count no of symbols in top level of list

( define ( countsymbols l )
   ( if (null? l)
        0
        ( + ( if (symbol? (car l) ) 1 0 )
            ( countsymbols (cdr l) )
         )
    )
)

; call using ( countsymbols '(1 2 d f g 3 4) )
; call using ( countsymbols '(1 2 a b '(0 0) '(1 2 a b) ) )