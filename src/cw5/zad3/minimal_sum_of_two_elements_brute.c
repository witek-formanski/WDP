int minimal_sum_of_two_elements_brute(int n, int t[]) {
    if (n < 2) return -1;

    int min_sum = abs(t[0] + t[1]);
    for (int i = 1; i < n - 1; i++) {
        min_sum = min(min_sum, abs(t[i], t[i+1]));
    }

    return min_sum;
}