#include <vector>

template<typename T>
struct fu;

template<typename T>
using find_union = fu<T>*;

template<typename T>
find_union<T> create_fu(T label);

// find graph's core
template<typename T>
int find(find_union<T> p);

template<typename T>
bool equivalent(find_union<T> p, find_union<T> q);

// attach smaller tree as child of bigger one
template<typename T>
void union_fu(find_union<T> p, find_union<T> q);

template<typename T>
int size (find_union<T> p);

template<typename T>
std::vector<int> elements(find_union<T> p);