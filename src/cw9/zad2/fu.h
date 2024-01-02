#include <vector>

typedef struct fu *find_union;

find_union create_fu(int label);

// find graph's core
int find(find_union p);

bool equivalent(find_union p, find_union q);

// attach smaller tree as child of bigger one
void union_fu(find_union p, find_union q);

int size (find_union p);

std::vector<int> elements(find_union p);