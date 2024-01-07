#include <iostream>
#include <vector>

std::vector<int> iter_perm(const std::vector<int> p, unsigned int k) {
    std::vector<int> vec = p;
    int n = (int)vec.size();

    // znajdźmy cykle w wektorze
    std::vector<std::vector<int>> cycles;
    for (int i = 0; i < (int)vec.size(); i++) {
        if (vec[i] < 0)
            continue; // already visited

        std::vector<int> currCycle;

        int cycleIndex = i;
        do {
            currCycle.push_back(cycleIndex);

            int nextIndex = vec[cycleIndex];
            vec[cycleIndex] -= n; // mark index as visited
            cycleIndex = nextIndex;
        } while (vec[cycleIndex] >= 0);

        cycles.push_back(currCycle);
    }

    // iterate every cycle
    for (auto cycle : cycles) {
        int advance = k % (int)cycle.size();

        for (int i = 0; i < (int)cycle.size(); i++) {
            vec[cycle[i]] = p[cycle[(i + advance) % cycle.size()]];
        }
    }

    return vec;
}

int main() {
    auto out = iter_perm({3, 4, 2, 5, 1, 0}, 1);

    for (auto i : out)
        std::cout << i << " ";
}