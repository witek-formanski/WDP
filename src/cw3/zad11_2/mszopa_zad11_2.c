#include <stdio.h>
#include <stdlib.h>

int can_place_on_first(int size)
{
    return size >= 0;
}

int neg2_of_int(long long int n, int wynik[], int size)
{
    if (!can_place_on_first(size))
    {
        return 0;
    }
    if (n == 0)
    {
        wynik[0] = -1;
        return 1;
    }

    if (n > 0)
    {
        int bit = -(n % 2);
        wynik[0] = bit;
        return neg2_of_int(-(n / 2), wynik + 1, size - 1);
    }
    else
    {
        int bit = (-n) % 2;
        wynik[0] = bit;

        return neg2_of_int(-(n) / 2, wynik + 1, size - 1);
    }
}

void print_long_long_int_base_n2(int wynik[])
{
    int i = 0;
    int bit = wynik[i++];

    while (bit > -1)
    {
        printf("%d", bit);
        bit = wynik[i++];
    }
}

int main()
{
    long long int n;
    scanf("%ld", &n);

    int size;
    scanf("%d", &size);

    int* results = (int*)malloc((size_t)size * sizeof(int));

    int hasFit = neg2_of_int(n, results, size);    
    if(hasFit){
        print_long_long_int_base_n2(results);
    }
}