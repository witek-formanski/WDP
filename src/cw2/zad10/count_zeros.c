int factorial(int x) {
    int x_factorial = 1;
    for (int i = 1; i < x; ++i) {
        x_factorial *= i;
    }

    return x_factorial;
}

// Lagrange's formula: https://en.wikipedia.org/wiki/Legendre%27s_formula

// liczba wielokrotności dwójek w rozkładzie n! jest zawsze większa lub równa
// niż liczba wielokrotności piątek

int count_zeros(int n) {
    int ans = 0;
    while (n) {
        n /= 5;
        ans += n;
    }
    return ans;
}