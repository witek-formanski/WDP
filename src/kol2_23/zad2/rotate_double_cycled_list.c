/*
T(n) = O(n)
M(n) = O(1)
*/

typedef struct elem elem;

struct elem {
    int val;
    elem *next, *other;
};

typedef elem* dwu_lista;

void rotate(dwu_lista lst) {
    elem* start = lst;
    if (!start) return;

    elem* me = start->next;
    elem* he = me->next->other;
    while (me != start) {
        me->other = he;
        he->other = me;

        me = me->next;
        he = me->next->other;
    }
}