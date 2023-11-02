int count_ones(unsigned int n) {
    int ans = 0;
    while (n) {
        ans += n & 1;
        n >>= 1;
    }
    return ans;
}