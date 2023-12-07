/*
T(n) = O(n)
M(n) = O(n)

0   1   2   3   4   5   6   7
2   0   4   6   0   7   3   5
0   1   0   3   0   5   3   5
+1                      +1  +1
*/

#include <vector>

int piggybanks_dfs(std::vector<int> piggybanks) {
    std::vector<int> cycles(piggybanks.size(), -1);
    int closed_cycles_count = 0;
    int next_pig;
    for (int i = 0; i < piggybanks.size(); i++) {
        if (cycles[i] == -1) {
            cycles[i] = i;
            next_pig = piggybanks[i];
            while (cycles[next_pig] == -1) {
                cycles[next_pig] = i;
                next_pig = piggybanks[next_pig];
            }
            if (next_pig == i) closed_cycles_count++;
        }
    }

    return closed_cycles_count;
}

#include <iostream>

int main() {
    std::cout << piggybanks_dfs({2, 0, 4, 6, 0, 7, 3, 5});
}

// inny pomysł: find-union