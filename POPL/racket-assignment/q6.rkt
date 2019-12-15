#lang racket

(define (makeTree . lst) lst)

(define (leaf node)
    (empty? (cdr node))
)

(define (printPathsTailRecursive node)
    (define (localTRecursive node tillnow)
        (let ([reversePath (cons (car node) tillnow)])
            (cond
                ( (leaf node) (println (reverse reversePath)))
                ( else
                    (for ([child (cdr node)])
                        (localTRecursive child reversePath)
                    )
                )
            )
        )
    )
    (localTRecursive node '())
)

(define (printPathsRecursive node)
    (define (localRecursive node)
        (cond
            ((leaf node) (list (list (car node))))
            (else
                (for/fold ([paths '()])
                    ([child (cdr node)])
                    (append paths
                        (for/list ([path (localRecursive child)])
                            (cons (car node) path)
                        ) 
                    )
                )
            )
        )
    )
    (for ([path (localRecursive node)])
        (println path)
    )
)


; (define root
;     (makeTree 1
;         (makeTree 2
;             (makeTree 6)
;             (makeTree 7
;                 (makeTree 8)
;             )
;         )
;         (makeTree 3
;             (makeTree 9
;                 (makeTree 10)
;                 (makeTree 11)
;             )
;         )
;         (makeTree 4)
;         (makeTree 5)
;     )
; )

; (printPathsTailRecursive root)
; (printPathsRecursive root)
