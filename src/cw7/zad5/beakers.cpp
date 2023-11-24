/*
T(n,k) = O(k)
M(n,k) = O(k)

algorytm HUffmana
*/

#include <algorithm>
#include <vector>
// #include <deque>
#include <queue>

float get_min_and_increment(std::vector<float>::const_iterator it, std::queue<float> q) {
    float min;
    if (*it == std::min(*it, q.front())) {
        min = *it;
        *it++;
    } else {
        min = q.front();
        q.pop();
    }
    return min;
}

float beakers(const std::vector<float> v, int k) {
    float min_sum;
    auto it = v.begin();
    std::queue<float> q;

    for (int i = 0; i < k; i++) {
        min_sum = get_min_and_increment(it, q);
        min_sum += get_min_and_increment(it, q);
        q.push(min_sum);
    }

    return std::min(*it, q.front());
}