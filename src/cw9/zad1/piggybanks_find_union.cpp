#include <vector>

typedef struct fu* find_union;
struct fu {
    int label;
    find_union up;
    int rank, size;
    std::vector<find_union> elems;
};

find_union create_fu(int label) {
    fu* res = new fu{label, nullptr, 0, 1, {}};
    return res;
}

find_union go_up(find_union p) {
    if (p->up == nullptr) return p;
    p->up = go_up(p->up);
    return p->up;
}

bool equivalent(find_union p, find_union q) {
    return go_up(p) == go_up(q);
}

void union_fu(find_union p, find_union q) {
    find_union rp = go_up(p);
    find_union rq = go_up(q);
    if (rp == rq) return;
    if (rp->rank > rq->rank) {
        rq->up = rp;
        rp->size += rq->size;
        rp->elems.push_back(rq);
    } else {
        rp->up = rq;
        rq->size += rp->size;
        rq->elems.push_back(rp);
        if (rq->rank == rp->rank) rq->rank++;
    }
}

int piggybanks_find_union(int piggybanks[], int n) {
    find_union* cycles = new find_union[n];
    int count = 0;

    for (int i = 0; i < n; i++) cycles[i] = create_fu(i);

    for (int i = 0; i < n; i++) {
        if (equivalent(cycles[i], cycles[piggybanks[i]]))
            count++;
        else
            union_fu(cycles[i], cycles[piggybanks[i]]);
    }

    for (int i = 0; i < n; i++) delete cycles[i];
    delete[] cycles;

    return count;
}

#include <iostream>

int main() {
    int tab[8] = {2, 0, 4, 6, 0, 7, 3, 5};
    std::cout << piggybanks_find_union(tab, 8);
}