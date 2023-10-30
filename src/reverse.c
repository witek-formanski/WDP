// n >= 0
int reverse(int n) {
    int aux = 0;
    while (n) {
        aux *= 10;
        aux += n % 10;
        n /= 10;
    }
    return aux;
}