int encode_in_one_integer(int n, int m) {
    int ans = 0;
    while (n || m) {
        ans += n & 1;
        ans <<= 1;
        ans += m & 1;
        ans <<= 1;
        n >>= 1;
        m >>= 1;
    }
    return ans;
}

struct pair {
    int n;
    int m;
};

int decode_from_integer(int encoded) {
    int n = 0;
    while (encoded) {
        encoded >>= 1;
        n += encoded & 1;
        encoded >>= 1;
    }
    return n;

    // ToDo: finish it
}