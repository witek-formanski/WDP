/*
T(n) = O(n sqrt(n))
M(n) = O(n)
*/

#include <stdexcept>
#include <vector>

/*
O(sqrt(n))

n > primes.back()
*/
bool is_next_prime(int n, const std::vector<int> primes) {
    if (n <= 1) return false;

    for (int i = 0; primes[i] * primes[i] < n; i++)
        if (n % primes[i] == 0) return false;

    return true;
}

// O(log(n))
bool is_in_primes(int n, const std::vector<int> primes) {
    int l = 0, r = primes.size() - 1, m;

    while (l < r) {
        m = (l + r) / 2;

        if (primes[m] == n) return true;
        else if (primes[m] > n)
            r = m;
        else
            l = m + 1;
    }

    return primes[l] == n;
}

// O(n sqrt(n))
std::vector<int> get_primes(int n) {
    if (n <= 1) return std::vector<int>();

    std::vector<int> primes{2};

    for (int i = 3; i <= n; i++)
        if (is_next_prime(i, primes))
            primes.push_back(i);

    return primes;
}

// O(n)
std::vector<int> get_prime_summands_of_even_number(int n, const std::vector<int> primes) {
    if (n <= 3 || n % 2) 
        return std::vector<int>();

    int i = 0, j = primes.size() - 1;

    while (primes[i] + primes[j] != n) {
        if (i > j)
            throw std::runtime_error("Goldbach's conjecture refuted!");
        
        if (primes[i] + primes[j] < n)
            i++;
        else
            j--;
    }

    return std::vector<int>{primes[i], primes[j]};
}

// O(n sqrt(n))
std::vector<int> get_prime_summands(int n) {
    if (n <= 1) return std::vector<int>();

    std::vector<int> primes = get_primes(n);

    if (is_in_primes(n, primes))
        return std::vector<int>{n};
    if (n % 2 == 0)
        return get_prime_summands_of_even_number(n, primes);
    if (is_in_primes(n - 2, primes))
        return std::vector<int>{2, n - 2};

    std::vector<int> summands = get_prime_summands_of_even_number(n - 3, primes);
    return std::vector<int>{3, summands[0], summands[1]};
}

#include <iostream>

int main() {
    for (int i = 0; i <= 100; i++) {
        std::cout << i << ": ";
        for (auto summand : get_prime_summands(i))
            std::cout << summand << " ";
        std::cout << "\n";
    }
}