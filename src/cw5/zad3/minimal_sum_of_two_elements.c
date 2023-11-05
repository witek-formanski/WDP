// t[] - non-decreasing

// a, b, c, d : N
// ...., -a, -b, c, d, ...

// bin-search for zero
// then compare 4 elements (3 pairs) closest to zero


int minimal_sum_of_two_elements(int n, int t[]) {
    int left = 0;
    int right = n -1;
    int middle;

    while (left < right) {
        middle = (left + right) / 2;
        if (t[middle] < 0)
            left = middle + 1;
        else
            right = middle;
    }

    int min_sum = -1;

    for (int i = max(middle - 2, 0); i < min(middle + 2, n - 1); i++) {
        min_sum = min(abs(t[i], t[i+1]), min_sum);
    }
    
    return min_sum;
}

