#include "gra.h"

int graj(int a, int b)
{
    if (a == b)
    {
        return 0;
    }

    if (a % 2 == 0)
    {
        return 1;
    }

    if (b == 1)
    {
        return 1;
    }

    return 2;
}