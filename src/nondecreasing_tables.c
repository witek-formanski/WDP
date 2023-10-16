/*
i       0   1   2   3   4   5   6
a[i]    -10 -10 -3  0   0   2   2
b[j]    -5  -3  -3  -3  2
j       0   1   2   3   4   5   6


*/

int count_distint(int a[], int n) //assumption: nondecreasing
{
    
}

int union_size(int a[], int n, int b[], int m) //assumption: nondecreasing
{
    if (n == 0)
        return count_distint(b, m);
    if (m == 0)
        return count_distint(a, n);

    int min_val = min(a[0], b[0]);
    int i = 0, j = 0;
    while (a[i] == min_val)
        ++i;
    while (b[j] == min_val)
        ++j;

    return union_size(a + i, n - i, b + j, m - j) + 1;
}
