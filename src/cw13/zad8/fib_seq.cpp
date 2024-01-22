/*
zaczynamy od tyłu (od n w dół)
tworzymy tablicę od 1 do n
inicjalizujemy wszystko poza n na -1
idziemy BFSem
w każdym kroku wykonujemy każde możliwe 
pojedyncze działanie (podzielenie przez fib mniejsze niż n + 1 i odjęcie)
jeżeli działanie miałoby nas doprowadzić do miejsca w tablicy
odwiedzonego wcześniej, to go nie wykonujemy
kończymy gdy dotrzemy do pierwszego elementu tablicy
(zamiast tablicy może być mapa)

ścieżka ma długość co najwyżej 2logn (suma bitów i jedynek w zapisie binarnym n)
ciąg fib rośnie wykładniczo, więc liczb fib mniejszych równych n jest logn

M(n) = O(n)
T(n) = O(log^2 n)
*/