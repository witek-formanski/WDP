#include <vector>
#include <algorithm>
#include <utility>

std::vector< std::pair<int, int> > get_indexes_and_values(std::vector<int> v) {
   std::vector< std::pair<int, int> > ind;
    
    for (int i = 0; i < v.size(); i++)
        ind.push_back({i, v[i]});
    
    return ind;
}

bool second_smaller(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second;
}

bool emerged_peak(std::vector<std::pair<int, int>> ind, std::vector<bool> visited, int i) {
    if ((ind[i].first == 0 || !visited[ind[i].first - 1]) && (ind[i].first == ind.size() - 1 || !visited[ind[i].first + 1]))
        return true;
    
    return false;
}

bool flooded_peak(const std::vector<std::pair<int, int>> ind, const std::vector<bool> visited, int i) {
    if (ind[i].first == 0 || ind[i].first == ind.size() - 1)
        return false;

    if (visited[ind[i].first - 1] && visited[ind[i].first + 1])
        return true;
    
    return false;
}

int get_max_islands_count(const std::vector<int> v) {
    int count = 0, max_count = 0;
    std::vector<std::pair<int, int>> ind = get_indexes_and_values(v);    
    std::vector<bool> visited(ind.size(), false);
    
    std::sort(ind.begin(), ind.end(), second_smaller);

    for (int i = ind.size() - 1; i > 0; i--) {
        visited[ind[i].first] = true;

        if (emerged_peak(ind, visited, i))
            max_count = std::max(++count, max_count);
        else if (flooded_peak(ind, visited, i)) 
            max_count = std::max(--count, max_count);
    }

    return max_count;
}

#include <iostream>

int main() {
    std::vector<int> v = {5, 12, 4, 10, 24, 20, 12, 18, 42, 30, 20, 35, 8};
    std::cout << get_max_islands_count(v);
}