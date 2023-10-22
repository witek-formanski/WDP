#include <iostream>
#include <vector>
#include <utility>

int compress_number(int i, int k)
{
    return (1 << (i - 1)) * (2 * k - 1);
}

std::vector<int> compress_array(int n, int t[])
{
    std::vector<int> compressed_vect;
    int index = 0;
    int counter = 1;

    while (index < n)
    {
        int temp = t[index];

        index++;

        if (temp == t[index])
            counter++;
        else // if (temp != t[index])
        {
            int compressed = compress_number(counter, temp);
            compressed_vect.push_back(compressed);
            counter = 1;
        }
    }

    return compressed_vect;
}

int main()
{
    int n; // 7
    std::cin >> n; 

    int* t = (int*)malloc((size_t)n * sizeof(int)); // 1 2 2 5 11 11 2
    for (int i = 0; i < n; i++)
        std::cin >> t[i];

    std::vector<int> compressed_vect = compress_array(n, t);

    for (auto i : compressed_vect)
        std::cout << i << " ";
    std::cout << "\n";

    free(t);
    
    return 0;
}
