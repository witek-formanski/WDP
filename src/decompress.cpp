#include <iostream>
#include <vector>
#include <utility>

// dekompresuj(6, {1, 3, 3, 9, 42, 3}) == {1, 2, 2, 5, 11, 11, 2}
// dekompresowana tablica t nie zawiera zer

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
    std::vector<int> decompressed_vect;
    for (int i = 0; i < n; i++)
    {
        std::pair<int, int> decompressed = decompress_number(t[i]);
        for (int j = 0; j < decompressed.first; j++)
        {
            decompressed_vect.push_back(decompressed.second);
        }
    }

    return decompressed_vect;
}

int main()
{
    int n; // 5
    std::cin >> n;

    int *t = (int *)malloc((size_t)n * sizeof(int)); // 1 6 9 42 3
    for (int i = 0; i < n; i++)
        std::cin >> t[i];

    std::vector<int> decompressed_vect = decompress_array(n, t);

    for (auto i : decompressed_vect)
        std::cout << i << " ";
    std::cout << "\n";

    free(t);

    return 0;
}