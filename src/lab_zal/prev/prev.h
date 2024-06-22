#ifndef _PREV_H
#define _PREV_H 1

#include <vector>

void init(const std::vector<int> &seq);
int prevInRange(int i, int lo, int hi); // max{ j : 0 <= j <= i && seq[j] \in [lo..hi] } or -1
void pushBack(int value);
void done();

#endif
