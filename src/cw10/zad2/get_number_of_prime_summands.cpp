/*
T(n) = O(log(n))
M(n) = O(1)
*/


bool is_prime(int n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;

    return true;
}

int get_number_of_prime_summands(int n) {
    if (is_prime(n)) 
        return 1;
    if (n % 2 == 0 || is_prime(n - 2)) 
        return 2;

    return 3;
}