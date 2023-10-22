#include <iostream>
#include <vector>
#include <utility>

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
            counter = 1;
        }
    }
    return compressed_array;
}

int main()
{
    int n; // 7
    std::cin >> n; 

    int* x = (int*)malloc((size_t)n * sizeof(int)); // 1 2 2 5 11 11 2
    for (int i = 0; i < n; i++)
        std::cin >> x[i];

    std::vector<int> compressed_array = compress_array(n, x);

    for (auto i : compressed_array)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}