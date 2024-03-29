value(racket).
value(gold).
value(platinum).
value(silver).


hates(mary, jane).
hates(tom, john).
hates(mom, cats).
hates(sam, cats).
hates(alice, bob).

near(mary, jane).
near(tom, john).
near(tom, mom).

murder(X, Y):-
    hates(X,Y),
    near(X,Y).


owns(john, book(title1, author1)).
owns(mary, book(title2, author2)).
owns(tom, book(title3, author3)).
owns(john, book(title3, auhor(name41, name42))).
owns(mary, book(title5, auhor(name51, name52))).

population(china, 100).
population(india, 85).
population(usa, 30).
population(germany, 9).

area(china, 10).
area(india, 4).
area(usa, 12).
area(germany, 2).


density(X,Y) :-
    population(X, Pop),
    area(X, Ar),
    Y is Pop/Ar.


fact(0,1).
fact(X, F) :-
    X>0,
    N1 is X-1,
    fact(N1, F1),
    F is F1*X.


issorted([]).
issorted([_]).
issorted([X,Y|T]):-
    X=<Y, issorted([Y|T]).


member(X, [X|_]).
member(X, [_|Y]):-
    member(X,Y).

bigger(N, M) :-
    (   N < M ),
    write('The Bigger number is '), write(M), !.
bigger(N,M) :-
    (   N > M),
    write('The Bigger number is '), write(N).
bigger(N, M) :-
    N =:= M,
    write('Numbers are same').

max1(X, Y, X):- X>Y, !.
max1(X, Y, Y):- X<Y.
