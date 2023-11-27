/*
T(n) = O(n)
M(n) = O(1)
*/

typedef struct elem elem;

struct elem {
    int val;
    elem* next;
};

typedef elem* list;

int count_elements(list l) {
    int count = 0;
    while (l) {
        l = l->next;
        ++count;
    }
    return count;
}

list get_common_suffix(list l, list m) {
    for (int i = 0; i < count_elements(l) - count_elements(m); ++i)
        l = l->next;
    for (int i = 0; i < count_elements(m) - count_elements(l); ++i)
        m = m->next;

    while (l != m) {
        l = l->next;
        m = m->next;
    }

    return l;
}