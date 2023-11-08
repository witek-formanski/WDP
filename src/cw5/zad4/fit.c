#include <stdlib.h>
#include <math.h>

int fit(int c, int n, int t[]) {
    int l = 0;
    int r = n - 1;
    int mini = abs(c + t[0] + t[n-1]);
    int sum;

    while (l < r && mini > 0)
    {
        sum = c + t[l] + t[r];
        mini = min(mini, abs(sum));

        if (sum > 0)
            r--;
        else
            l++;

        return mini;
    }
}