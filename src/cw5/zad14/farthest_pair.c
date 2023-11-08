/*
i               0   1   2   3   4   5   6   7   8   9   10  11  12  13  14
a[i]            7   6   5   4   5   6   7   2   3   4   5   6   5   4   3
max_suffix[i]   7   7   7   7   7   7   7   6   6   6   6   6   5   4   3
min_prefix[i]   7   6   5   4   4   4   4   2   2   2   2   2   2   2   2



// not used:
index_m_suf[i]  6   6   6   6   6   6   6   11  11  11  11  11  12  13  14
index_m_pref[i] 0   1   2   3   3   3   3   7   7   7   7   7   7   7   7
*/

#include <stdio.h>
#include <stdlib.h>

// (i, j). i < j, a[i] < a[j], j-n <- max, returns j-i
int *get_min_prefix(int n, int a[]) {
    int *min_prefix = (int *)malloc((size_t)n * sizeof(int));
    int current_min = a[0];

    for (int i = 0; i < n; i++) {
        if (a[i] < current_min)
            current_min = a[i];
        min_prefix[i] = current_min;
    }

    return min_prefix;
}

int *get_max_suffix(int n, int a[]) {
    int *max_suffix = (int *)malloc((size_t)n * sizeof(int));
    int current_max = a[0];

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] < current_max)
            current_max = a[i];
        max_suffix[i] = current_max;
    }

    return max_suffix;
}

int farthest_pair(int n, int a[]) {
    int *max_suffix = get_max_suffix(n, a);
    int *min_prefix = get_min_prefix(n, a);
    int ind_suf = 0; 
    int ind_pref = 0; 
    int ans = 0;
    while (ind_suf < n && ind_pref < n) {
        if (max_suffix[ind_suf] <= min_prefix[ind_pref])
            ind_pref++;
        else {
            if (ind_suf - ind_pref > ans)
                ans = ind_suf - ind_pref;
            ind_suf++;
        }
    }

    return ans;
}