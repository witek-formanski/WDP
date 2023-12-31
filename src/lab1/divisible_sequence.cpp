#include <algorithm>
#include <iostream>
#include <vector>

int get_current_divisible_fragment_length(int t[], int i) {
    int current_divisible_fragment = 1;

    for (int j = i - 1; j >= 0; j--) {
        if (!t[j] || t[i] % t[j]) {
            return current_divisible_fragment;
        }

        ++current_divisible_fragment;
    }

    return current_divisible_fragment;
}

int get_max_divisible_fragment(int t[], int n) {
    int max_divisible_fragment = 0;

    int i = n - 1;
    while (i >= 1) {
        int current_divisible_fragment =
            get_current_divisible_fragment_length(t, i);
        max_divisible_fragment =
            std::max(current_divisible_fragment, max_divisible_fragment);
        i -= current_divisible_fragment;
    }

    return max_divisible_fragment;
}

int main() {
    int n;

    std::cin >> n;

    if (n <= 0) {
        std::cout << "n must be a positive integer" << std::endl;
        return 1;
    }

    int *t = new int[n];

    int value;
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        t[i] = value;
    }

    std::cout << get_max_divisible_fragment(t, n);

    delete[] t;

    return 0;
}