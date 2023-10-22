#include <iostream>
#include <vector>
#include <utility>

// dekompresuj(6, {1, 3, 3, 9, 42, 3}) == {1, 2, 2, 5, 11, 11, 2}
// t nie zawiera zer
std::pair<int, int> decompress_number(int compressed)
{
    int i = 1;
    while (compressed % 2 == 0)
    {
        i++;
        compressed /= 2;
    }
    int k = (compressed + 1) / 2;
    std::pair<int, int> decompressed;
    decompressed.first = i;
    decompressed.second = k;
    return decompressed;
}

std::vector<int> decompress_array(int n, int t[])
{
    std::vector<int> decompressed_array;
    for (int i = 0; i < n; i++)
    {
        std::pair<int, int> decompressed = decompress_number(t[i]);
        for (int j = 0; j < decompressed.first; j++)
        {
            decompressed_array.push_back(decompressed.second);
        }
    }

    return decompressed_array;
}

int main()
{
    int n; // 5
    std::cin >> n;

    int* x = (int*)malloc((size_t)n * sizeof(int)); // 1 6 9 42 3
    for (int i = 0; i < n; i++)
        std::cin >> x[i];

    std::vector<int> decompressed_array = decompress_array(n, x);

    for (auto i : decompressed_array)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    free(x);

    return 0;
}