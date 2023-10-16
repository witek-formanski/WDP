#include <stdbool.h>

// zad. 11 tablice

/*
minus binary 11 -> 11111
11 = (-5)(-2) + 1
-5 = 3(-2) + 1
3 = (-1)(-2) + 1
-1 = 1(-2) + 1
1 = 0(-2) + 1

binary 11 -> 1101
11 = 5 * 2 + 1
5 = 2 * 2 + 1
2 = 1 * 2 + 0
1 = 0 * 2 + 1

12 = (-6)(-2) + 0


*/

// typedef enum boolean
// {
//     false = 0,
//     true = 1
// } bool;

bool neg2_of_int(long long int n, int result[], int size)
{
    if (size <= 0)
    {
        return false;
    }

    if (n==0)
    {
        result[0] = -1;
        return true;
    }

    if (n>0)
    {
        result[0] = (int)(n % 2);
        return neg2_of_int(-(n/2), result+1, size-1);
    }

    return true;
}

//================================================================

/*
nowy pomysł
ostatni (najmniej znaczący bit) przy dodawaniu 1:
0 -> 1
11 -> 00
01 -> 10 i do prefiksu (długość -2) dodać 1

*/