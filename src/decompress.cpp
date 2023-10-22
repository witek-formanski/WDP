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

int compress_number(int i, int k)
{
    return (1 << (i - 1)) * (2 * k - 1);
}

std::vector<int> compress_array(int n, int arr[])
{
    std::vector<int> compressed_array;
    int index = 0;
    int counter = 1;
    while (index < n)
    {
        int temp = arr[index];

        index++;
        if (temp == arr[index])
            counter++;
        else // if (temp !=arr[index])
        {
            int compressed = compress_number(counter, temp);
            compressed_array.push_back(compressed);
            // temp = arr[index];
            counter = 1;
        }
    }
    return compressed_array;
}

int main()
{
    int n = 6;

    int x[]{1, 3, 3, 9, 42, 3};

    std::vector<int> decompressed_array = decompress_array(n, x);

    for (auto i : decompressed_array)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    int m = decompressed_array.size();
    int *decompressed_static_array = &decompressed_array[0];

    // for (int i = 0; i < m; i++)
    // {
    //     std::cout << decompressed_static_array[i] << " ";
    // }
    // std::cout << "\n";

    std::vector<int> compressed_array = compress_array(m, decompressed_static_array);

    for (auto i : compressed_array)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}