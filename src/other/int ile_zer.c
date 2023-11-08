int ile_zer(int a, int b) {
    return count_zeros(b) - count_zeros(a);
}

int count_zeros(int a) {
    int exponent;
    int count = 0;
    while(exponent < b) {
        count += (b / pow(10, exponent) ) * pow(10, exponent - 1);
    }
}