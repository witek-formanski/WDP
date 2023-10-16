// #include "game.h"
#include <stdio.h>

// int play(int a, int b) // assumption: a and b relatively prime (gcd(a,b) = 1)
// {
//     if (a < 1 || b < 1)
//     {
//         // printf("invalid input values provided");
//         return -1;
//     }

//     if (a == 1 && b == 1)
//     {
//         return 0;
//     }

//     if (a % 2 == 0)
//     {
//         return 1;
//     }

//     if (b % 2 == 0)
//     {
//         return 2;
//     }

//     if (a > b)
//     {
//         return 1;
//     }

//     if (a < b)
//     {
//         return 2;
//     }

//     return -2;
// }

int greatest_common_divisor(int a, int b) // NWD - algorym Euklidesa
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a; // lub b - obie zmienne przechowują wynik NWD(a,b)
}

void make_relatively_first(int *a, int *b)
{
    int gcd = greatest_common_divisor(*a, *b);
    *a /= gcd;
    *b /= gcd;
}

int play_game(int a, int b)
{
    int counter = 0;
    int decision = 1;
    int winner;
    while (decision != 0)
    {
        decision = play(a, b);
        ++counter;
        switch (decision)
        {
        case -1:
            // printf("invalid input values provided");
            return -1;
        case 0:
            // printf("the game is over\n");
            // (counter % 2 == 0) ? printf("player one wins\n") : printf("player two wins\n");
            winner = (counter % 2 == 0) ? 0 : 1;
            return winner;
        case 1:
            --a;
            make_relatively_first(&a, &b);
            // printf("a = %d", a);
            // printf(", b = %d\n", b);
            break;
        case 2:
            --b;
            make_relatively_first(&a, &b);
            // printf("a = %d", a);
            // printf(", b = %d\n", b);
            break;
        default:
            break;
        }
    }

    return -2;
}

int main()
{
    int a, b;
    if(!scanf("%d", &a)) printf("invalid a provided\n");
    if(!scanf("%d", &b)) printf("invalid b provided\n");

    printf("%d", play_game(a, b));

    return 0;
}