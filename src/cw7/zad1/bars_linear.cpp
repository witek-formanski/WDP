/*
T(n) = O(n)
M(n) = O(1)
*/

//https://cs.stackexchange.com/questions/1914/find-median-of-unsorted-array-in-on-time

#include <algorithm>
#include <vector>

int median_of_medians() {
    return 0;
}

int bars_linear(std::vector<int> v) {
    int ans = 0;
    int median = median_of_medians();
    for (auto el : v)
        ans += abs(el - median);
    
    return ans;
}