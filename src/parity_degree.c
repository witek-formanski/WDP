int parity_degree(int x) {
    int degree = 0;
    if (x == 0) return -1;

    while (x % 2 == 0) {
        ++degree;
        x /= 2;
    }
    return degree;
}