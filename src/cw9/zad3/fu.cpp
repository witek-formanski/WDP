#include <vector>
#include <cstdlib>
#include "fu.h"

using namespace std;

template<typename T>
struct fu
{
    T label;
    find_union<T> up;
    int rank, size;
    vector<find_union<T>> elems;
};

template<typename T>
find_union<T> create_fu(T label)
{
    find_union<T> res = (find_union<T>)malloc(sizeof(fu<T>));
    res->label = label;
    res->up = NULL;
    res->rank = 0;
    res->size = 1;
    res->elems= {};
    return res;
}

template<typename T>
find_union<T> go_up(find_union<T> p)
{
    if (p->up == NULL)
        return p;
    return (p->up = go_up(p->up));
}

template<typename T>
int find(find_union<T> p)
{
    return go_up(p)->label;
}

template<typename T>
bool equivalent(find_union<T> p, find_union<T> q)
{
    return go_up(p) == go_up(q);
}

template<typename T>
void union_fu(find_union<T> p, find_union<T> q)
{
    find_union<T> rp = go_up(p);
    find_union<T> rq = go_up(q);
    if (rp == rq)
        return;
    if (rp->rank > rq->rank)
    {
        rq->up = rp;
        rp->size += rq->size;
        rp->elems.push_back(rq);
    }
    else
    {
        rp->up = rq;
        rq->size += rp->size;
        rq->elems.push_back(rp);
        if (rq->rank == rp->rank)
            rq->rank++;
    }
}

template<typename T>
int size(find_union<T> p)
{
    return go_up(p)->size;
}

template<typename T>
void _traverse(find_union<T> p, vector<int> &res)
{
    res.push_back(p->label);
    for (find_union<T> q : p->elems)
    {
        _traverse(q, res);
    }
}

template<typename T>
vector<int> elements(find_union<T> p)
{
    vector<int> res;
    _traverse(go_up(p), res);
    return res;
}