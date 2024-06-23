#include <iostream>
#include <math.h>

int get_lollipops_count(int rolls)
{
    auto lollipops_double = log2(rolls);
    auto lollipops = static_cast<int>(lollipops_double);
    if (lollipops_double > lollipops)
    {
        lollipops++;
    }

    return lollipops;
}

int main()
{
    int rolls;
    std::cin >> rolls;
    
    std::cout << get_lollipops_count(rolls) << "\n";

    return 0;
}