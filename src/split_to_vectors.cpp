#include <vector>
#include <iostream>

// split_to_vectors(3, {1, 2, 3, 4, 5, 6, 7}) = {{1, 4, 7}, {2, 5}, {3, 6}}\)

std::vector<std::vector<int>> split_to_vectors(int k, std::vector<int> x)
{
    std::vector<std::vector<int>> result;
    for (auto i = 0; i < k; i++)
    {
        std::vector<int> vect;
        auto temp = i;
        while (temp < x.size())
        {
            vect.push_back(x[temp]);
            temp += k;
        }
        result.push_back(vect);
    }
    
    return result;
}

int main()
{
    std::vector<int> x{1, 2, 3, 4, 5, 6, 7};
    auto k = 3;

    auto result = split_to_vectors(k, x);

    for (auto i = 0; i < k; i++)
    {
        for (auto j : result[i])
        {
            std::cout << j << " ";
        }
        std::cout << "\n";
    }
 
    return 0;
}