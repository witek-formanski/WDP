#include "kol.h"
#include <cstdlib>
#include <algorithm>

struct list {
    interesant *head, *tail;
};

interesant *new_interesant(int id, interesant *l1, interesant *l2) {
    interesant *client = (interesant *)malloc(sizeof(interesant));
    client->id = id;
    client->l1 = l1;
    client->l2 = l2;
    return client;
}

list create_list() {
    list res;
    res.head = (interesant *)malloc(sizeof(interesant));
    res.tail = (interesant *)malloc(sizeof(interesant));
    res.head->l1 = NULL;
    res.head->l2 = res.tail;
    res.tail->l1 = NULL;
    res.tail->l2 = res.head;
    return res;
}

bool is_empty(const list l) {
    return l.head->l2 == l.tail;
}

interesant *front(const list l) {
    return l.head->l2;
}

interesant *back(const list l) {
    return l.tail->l2;
}

void link(interesant *el, interesant *old, interesant *nw) {
    if (!el) return;

    if (el->l1 == old)
        el->l1 = nw;
    else
        el->l2 = nw;
}

void push_back(list &l, interesant *el) {
    el->l1 = l.tail;
    el->l2 = l.tail->l2;
    link(l.tail->l2, l.tail, el);
    l.tail->l2 = el;
}

void remove_interesant(interesant *el) {
    link(el->l1, el, el->l2);
    link(el->l2, el, el->l1);
}

void pop_front(list &l) {
    if (!is_empty(l)) remove_interesant(l.head->l2);
}

void reverse(list &l) {
    interesant *tmp = l.head;
    l.head = l.tail;
    l.tail = tmp;
}

static std::vector<list> Queues;
static int Count;

void otwarcie_urzedu(int m) {
    Queues.resize(m);
    for (int i = 0; i < m; ++i)
        Queues[i] = create_list();
    Count = 0;
}

interesant *nowy_interesant(int k) {
    push_back(Queues[k], new_interesant(Count++, NULL, NULL));
    return back(Queues[k]);
}

int numerek(interesant *i) {
    return i->id;
}

interesant *obsluz(int k) {
    if (is_empty(Queues[k])) return NULL;

    interesant *i = front(Queues[k]);
    pop_front(Queues[k]);
    return i;
}

void zmiana_okienka(interesant *i, int k) {
    remove_interesant(i);
    push_back(Queues[k], i);
}

void append(list &l1, list &l2) {
    interesant *b = l1.tail;
    interesant *f = l2.head;
    link(b->l2, b, f->l2);
    link(f->l2, f, b->l2);
    b->l2 = f;
    f->l2 = b;
    l1.tail = l2.tail;
    l2.head = f;
    l2.tail = b;
}

void zamkniecie_okienka(int k1, int k2) {
    append(Queues[k2], Queues[k1]);
}

std::vector<interesant *> get_fragment(interesant *prev, interesant *curr, interesant *i2, bool flag) {
    std::vector<interesant *> fragment{prev};

    while (curr != i2 && curr != NULL) {
        fragment.push_back(curr);

        if (curr->l2 != prev) {
            prev = curr;
            curr = flag ? curr->l1 : curr->l2;
        } else {
            prev = curr;
            curr = curr->l1;
        }
    }

    fragment.push_back(curr);
    return fragment;
}

std::vector<interesant *> fast_track(interesant *i1, interesant *i2) {
    if (!i1 || !i2) return std::vector<interesant *>();

    if (i1 == i2) {
        remove_interesant(i1);
        return std::vector<interesant *>{i1};
    }

    std::vector<interesant *> fragment;
    if (i1->id > i2->id) {
        fragment = fast_track(i2, i1);
        std::reverse(fragment.begin(), fragment.end());
        return fragment;
    }

    fragment = get_fragment(i1, i1->l1, i2, true);
    if (fragment.back() == NULL) fragment = get_fragment(i1, i1->l2, i2, false);

    for (interesant *elem : fragment)
        remove_interesant(elem);
    return fragment;
}

void naczelnik(int k) {
    reverse(Queues[k]);
}

std::vector<interesant *> zamkniecie_urzedu() {
    std::vector<interesant *> remaining;
    for (list l : Queues) {
        while (!is_empty(l)) {
            remaining.push_back(front(l));
            pop_front(l);
        }
        free(l.head);
        free(l.tail);
    }
    return remaining;
}