/*
    T(n, k) = O(n * k)
    M(n, k) = M(k)

    n - liczba odważników
    k - suma odważników

    inny pomysł: problem plecakowy
*/

#include <iostream>

int KeepScaleInBalance(int weights[], int size) {
    int sum = 0, heaviestWeight = -1, weightsCombined = 0;
    for (int i = 0; i < size; i++)
        sum += weights[i];

    bool* possible = new bool[sum + 1]{true};

    for (int i = 0; i < size; i++) {
        weightsCombined += weights[i];
        for (int j = weights[i]; j <= weightsCombined; j++) {
            if (possible[j - weights[i]] && possible[j])
                heaviestWeight = i;

            if (possible[j - weights[i]])
                possible[j] = true;
        }
    }

    delete[] possible;
    return weights[heaviestWeight];
}

int main() {
    std::cout << KeepScaleInBalance(new int[8]{0, 1, 1, 2, 5, 11, 16, 36}, 8) << "\n";
    std::cout << KeepScaleInBalance(new int[8]{0, 1, 1, 2, 5, 11, 16, 37}, 8) << "\n";
}