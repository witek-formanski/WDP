/*
złożoność czasowa:
    przy założeniu, że operacje bitowe i arytmetyczne są w O(1):
    T(n) = O(1)

    tak naprawdę:
    T(n) = O(n)

złożoność pamięciowa:
    M(n) = O(n)

JESCZE KRÓTSZY KOD!!!
*/

int s(int n){return n&~0u/3;}

#include <stdio.h>

int main() {
    printf("%d", s(-44));
}