﻿#include <iostream>
#include <algorithm>

struct only_zeros
{
    bool flag = true;
};

int** fill_matrix(std::string a, std::string b, size_t n, size_t m, only_zeros* detector)
{
    int** matrix = new int*[n];
    for (size_t i = 0; i < n; ++i)
    {
        matrix[i] = new int[m];
        for (size_t j = 0; j < m; ++j)
        {
            if (a[i] == b[j])
            {
                matrix[i][j] = 1;
                detector->flag = false;
            }
            else
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

int get_longest_nonzero_diagonal(int** matrix, size_t n, size_t m)
{
    int longest = 1;
    for (size_t i = 1; i < n; ++i)
    {
        for (size_t j = 1; j < m; ++j)
        {
            if (matrix[i][j] > 0 && matrix[i-1][j-1] > 0)
            {
                matrix[i][j] += matrix[i-1][j-1];
                longest = std::max(matrix[i][j], longest);
            }
        }
    }

    return longest;
}

int get_longest_common_substring_length(std::string a, std::string b)
{
    size_t n = a.length();
    size_t m = b.length();
    only_zeros detector;
    int** matrix = fill_matrix(a, b, n, m, &detector);
    if (detector.flag == true)
    {
        return 0;
    }
    return get_longest_nonzero_diagonal(matrix, n, m);

}

int main()
{
    std::string a, b;
    std::cin >> a >> b;

    std::cout << get_longest_common_substring_length(a, b) << "\n";

    return 0;
}