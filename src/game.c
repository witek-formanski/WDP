// przegrywająca jest para (nieprarzysta, nieparzysta), wszystkie inne wygrywają

int play(int a, int b) // assumption: a and b relatively prime (gcd(a,b) = 1)
{
    if (a < 1 || b < 1)
    {
        // printf("invalid input values provided");
        return -1;
    }

    if (a == 1 && b == 1)
    {
        return 0;
    }

    if (a % 2 == 0)
    {
        return 1;
    }

    if (b % 2 == 0)
    {
        return 2;
    }

    if (a > b)
    {
        return 1;
    }

    if (a < b)
    {
        return 2;
    }
}