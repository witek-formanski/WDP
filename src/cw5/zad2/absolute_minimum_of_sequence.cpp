// zliczanie zad. 2

#include <iostream>
#include <vector>

// binary search for zero
// ciąg jest ściśle monotoniczny (rosnący lub malejący)

int abs_min(std::vector<int> v) {
    int left = 0;
    int right = v.size() - 1;
    int middle;

    // check if the sequence is increasing or decreasing

    // we look for the smallest element greater than 0
    while (left < right) {
        middle = (left + right) / 2;
        if (v[middle] > 0) {
            right = middle;
        } else  // (v[middle] <= 0)
        {
            left = middle + 1;
        }
    }

    // compare this element and the one that preceeds it
    // return...
}

int main() {
    std::vector<int> v{-10, -8, -2, 3, 5, 11, 200};

    std::cout << abs_min(v);
}