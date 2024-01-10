/*
sortujemy po końcach
przeglądamy od najwcześniejszych
*/

#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>

bool compare_second(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.second < b.second;
}

int kinoman(std::vector<std::pair<int, int>> teletydzien) {
    std::sort(teletydzien.begin(), teletydzien.end(), compare_second);
    int liczba_filmow = 0;
    int i = 0, j = 1;
    while (i < teletydzien.size()) {
        liczba_filmow++;
        while (teletydzien[j].first <= teletydzien[i].second && j < teletydzien.size())
            j++;
        i = j++;
    }

    return liczba_filmow;
}

int main() {
    std::cout << kinoman({{1, 5}, {2, 3}, {3, 6}, {4, 7}, {9, 11}}) << "\n";
}