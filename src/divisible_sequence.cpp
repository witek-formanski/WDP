#include <iostream>
#include <vector>

int main() {
    int n;

    std::cin >> n;

    if (n <= 0) {
        std::cout << "n must be a positive integer." << std::endl;
        return 1;
    }

    std::vector<int> t(n);

    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }

    int max_divisible_fragment = 0;
    int current_divisible_fragment = 1;

    for (int i = 0; i < n - 1; i++) 
    {
        if (t[i + 1] % t[i] == 0) 
        {
            current_divisible_fragment++;
        } 
        else 
        {
            if (current_divisible_fragment > max_divisible_fragment) 
            {
                max_divisible_fragment = current_divisible_fragment;
            }
            current_divisible_fragment = 1;
        }
    }


    if (current_divisible_fragment > max_divisible_fragment) 
    {
        max_divisible_fragment = current_divisible_fragment;
    }

    std::cout << max_divisible_fragment;

    return 0;
}