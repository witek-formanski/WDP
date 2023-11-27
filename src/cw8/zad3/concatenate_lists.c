#include <stdlib.h>

typedef struct elem elem;

struct elem {
    int val;
    elem* next;
};

typedef elem* list;

list concatenate_lists_recursive(list l, list m) {
    if (l == NULL)
        return m;

    if (m == NULL)
        return l;

    list p = l->next;
    l->next = concatenate_lists_recursive(m, l);

    return l;
}

list concatenate_lists_iterative(list l, list m) {
    list concatenated = l;
    list temp_l, temp_m;

    while (l && m) {
        temp_l = l->next;
        temp_m = m->next;
        l->next = m;
        if (temp_l) m->next = temp_l;
        l = temp_l;
        m = temp_m;
    }

    return concatenated;
}