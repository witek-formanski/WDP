// zliczanie zad. 2

#include <iostream>
#include <vector>
#include <algorithm>

// binary search for zero
// ciąg jest ściśle monotoniczny (rosnący lub malejący)

int abs_min(std::vector<int> v) {
    int left = 0;
    int right = (int)(v.size() - 1);
    int middle;

    // check if the sequence is increasing or decreasing
    bool is_decreasing = (v[left] < v[right]);

    // we look for the smallest element greater than 0
    while (left < right) {
        middle = (left + right) / 2;
        if ((is_decreasing && v[middle] > 0) || (!is_decreasing && v[middle] <= 0)) {
            right = middle;
        } else {
            left = middle + 1;
        }
    }
    // right == left

    // compare this element and the one that preceeds it
    return std::min(abs(v[right]), abs(v[right-1]));
}

int main() {
    // std::vector<int> v{-10, -8, -2, 3, 5, 11, 200};
    // std::vector<int> v{200, 11, 5, 3, -2, -8, -10};

    int n;
    std::cin >> n;

    std::vector<int> v;
    int el;
    for (auto i = 0; i < n; i++) {
        std::cin >> el;
        v.push_back(el);
    }

    std::cout << abs_min(v);

    return 0;
}