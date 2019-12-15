#lang racket
; Assume merge takes time complexity T(n)
; where n is length of both lists combined
; T(n) is proved as O(n) below
; Lists are linked lists - so appending at head is O(1)
(define (merge list1 list2)
    (cond
        ; if list1 is empty, return list2
        ; Complexity - O(1)
        ( (null? list1) list2 )

        ; if list2 is empty, return list1
        ; Complexity - O(1)
        ( (null? list2) list1 )

        ; if first element of list1 is greater than list2, then append it to the list returned by 
        ;   merging the remaining of list1 with list2
        ; Complexity - O(1):append to begining of list + T(n-1):perform merge on (n-1) elements
        ( (< (car list1) (car list2)) (append (list (car list1)) (merge (cdr list1) list2)) )

        ; if first element of list2 is greater than list1, then append it to the list returned by 
        ;   merging the remaining of list2 with list1
        ; Complexity - O(1):append to begining of list + T(n-1):perform merge on (n-1) elements
        ( (> (car list1) (car list2)) (append (list (car list2)) (merge list1 (cdr list2))) )

        ; if elements of both lists are equal, then take both elements (as they must appear together),
        ;   combine them, and pre-append to the list obtaining by merging remaining elements of both lists
        ; Complexity - O(1):append list of 2 elements to begining of list + T(n-2):perform merge on (n-2) elements
        ;   but, O(1) + T(n-1) > O(1) + T(n-2)
        ;   so, we can take upper bound as O(1) + T(n-1) for this step
        ( (= (car list1) (car list2)) (append (list (car list1) (car list2)) (merge (cdr list1) (cdr list2))) )
    )
    ; We get => T(n) = O(1) + T(n-1)
    ;               = O(1) + O(1) + T(n-2)
    ; Finally, T(n) = O(1)*n-times = O(n)
    ; COMPLEXITY of merge is O(n)
)

; Returns first half of the array
(define (firstHalf array length)
    (if (zero? length)
        (list)
        (append (list (car array)) (firstHalf (cdr array) (- length 1)))
    )
)

; Returns second half of the array
(define (secondHalf array length)
    (if (zero? length)
        array
        (secondHalf (cdr array) (- length 1))
    )
)

; Assume merge-sort takes time complexity T(n)
; where n is length of both lists combined
; T(n) is proved as O(nlogn) below
(define (mergesort lst)
    ; Calculate length of list
    ; Complexity O(n)
    (define len (length lst))
    (cond
        ; if lenght of list is 1, return that element
        ; Complexity - O(1)
        ((= len 1) lst)
        (else
            ; Complexity of merge - proved above as O(n)
            ; Complexity of first halp elements to merge sort - T(n/2)
            ; Complexity of second half elements to merge sort - T(n/2)
            (merge  (mergesort (firstHalf lst (ceiling (/ len 2))))
                    (mergesort (secondHalf lst (ceiling (/ len 2))))
            )
        )
    )
    ; We get T(n) = 2*T(n/2) + O(n)
    ; By solving the above equation using master theorem, we get O(nlogn)
    ; Or we can also see that nlogn is the solution of the equation by substitution
    ; Complexity of mergesort is O(nlogn)
)