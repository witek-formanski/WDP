/*
T(n) = O(nlogn) - przez sortowanie
M(n) = O(1)
*/

#include <algorithm>
#include <vector>

int bars(std::vector<int> v) {
    int ans = 0;
    std::sort(v.begin(), v.end());
    int median = v[v.size()/2];
    for (auto el : v)
        ans += abs(el - median);
    
    return ans;
}