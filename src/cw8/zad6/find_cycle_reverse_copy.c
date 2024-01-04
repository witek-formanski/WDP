#include <stdlib.h>

typedef struct elem elem;

struct elem {
    int val;
    elem* next;
};

typedef elem* list;

list reverse(list l) {
    list m = l, r = l;
    l = NULL;
    while (m) {  // m == r
        m = r->next;
        r->next = l;
        l = r;
        r = m;
    }

    return l;
}

/* 
dwa pomysły:
1. 
trzymamy w pamięci l i r = reverse(l)
r będzie miało wspólny początek z l,
ale cykl będzie odwrócony
iterujemy przez prefiksy l i r 
aż nie natrafimy na różne pointery
gdy pointery się zaczną różnić,
natrafiliśmy na cykl
wystarczy przeiterować się przez cykl
aż nie natrafimy na pointer,
od którego zaczęliśmy 
albo pamiętać poprzedni pointer
2.
bez reverse(l) w pamięci
liczymy długość przejścia listy od początku
przez cykl i do początku, czyli
a + b + a = 2a + b,
gdzie a to długość prefiksu,
a b to długość cyklu
przesuwamy się do (2a + b)/2 = a + b/2 elementu
wiemy, że jesteśmy w cyklu
iterujemy przez cykl, licząc jego długość (b)

*/
