/*
    Author: Jan Kwieciński
    O(n^2) solution using hashmap
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>

int trojki(const std::vector<int> v)
{
    std::unordered_map <int, int> sum_map;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i+1; j < v.size(); j++) sum_map[v[i] + v[j]]++;
    }

    int result  = 0;
    for (int i = 0; i < v.size(); i++) result += sum_map[v[i]];
    return result;
}

int main()
{
    std::vector<int> v = {4, 2, 1, 5, 8, 1};
    assert(trojki(v) == 3);
}