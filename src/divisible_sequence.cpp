#include <iostream>
#include <vector>
#include "common_library.h"

int get_current_divisible_fragment_length(std::vector<int> tab, int i)
{
    int current_divisible_fragment = 1;
    for (int j = i; j > 1; --j)
    {
        if (!(tab[i] % tab[j-1]))
        {
            return current_divisible_fragment;
        }

        ++current_divisible_fragment;
    }

    return current_divisible_fragment;
}

int get_max_divisible_fragment(std::vector<int> tab, int n)
{
    int max_divisible_fragment = 0;

    for (int i = n; i > 1; --i) 
    {
        int current_divisible_fragment = get_current_divisible_fragment_length(tab, i);
        max_divisible_fragment = max(current_divisible_fragment, max_divisible_fragment);
    }
    return max_divisible_fragment;
}

int main() {
    int n;

    std::cin >> n;

    if (n <= 0) 
    {
        std::cout << "n must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> tab;

    for (int i = 0; i < n; i++) 
    {
        std::cin >> tab[i];
    }



    std::cout << get_max_divisible_fragment(tab, n);

    return 0;
}