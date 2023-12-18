/*
szachownica jest wymiarów w x w
maksymalna liczba kolorów == liczba składowych w grafie G
G:  V - wieża, E - wiersz lub kolumna

czy da się uzyskać O(w), gdzie w to liczba wierszy/kolumn?

O(w log(w))
*/

#include <utility>
#include <vector>
#include <map>

typedef struct row_or_col {
    int index;
    bool is_row;
};

row_or_col new_label(int index, bool is_row) {
     row_or_col label;
    label.index = index;
    label.is_row = is_row;
    return label;
}

typedef struct fu* find_union;
struct fu {
    row_or_col label;
    find_union up;
    int rank, size;
    std::vector<find_union> elems;
};

find_union create_fu(row_or_col label) {
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

int get_max_colors_count(const std::vector<std::pair<int, int>> &towers) {
    int count = 0, row, col;
    std::map<int, find_union> cols, rows;
    for (int i = 0; i < towers.size(); i++) {
        row = towers[i].first;
        col = towers[i].second;
        if (rows.count(row) + cols.count(col)) {
            count++;
            rows[row] = create_fu(new_label(row, true));
            cols[col] = create_fu(new_label(col, false));
        }
        else if (rows.count(row) + cols.count(col) == 2) {
            if (!equivalent(rows[row], cols[col]))
                count--;
        }
        else if (rows.count(row)) 
            cols[col] = create_fu(new_label(col, false));
        else
            rows[row] = create_fu(new_label(row, true));
        
        union_fu(rows[row], cols[col]);
    }

    return count;
}