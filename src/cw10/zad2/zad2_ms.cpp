#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void push_vector(vector<T> &vec, const vector<T> &values)
{
    for (int c : values)
    {
        vec.push_back(c);
    }
}

// generate array 0 ... n-1
// if i is prime, then results[i] is true. Otherwise results[i] = false
vector<bool> generate_prime_array(int n)
{
    vector<bool> isPrime(n,true);
    isPrime[0] = false;
    isPrime[1] = false;
    isPrime[2] = true;

    for (int i = 2; i * i <= n; i++)
    {
        if (!isPrime[i])
            continue;
        int j = i * i;
        while (j < n)
        {
            isPrime[j] = false;
            j += i;
        }
    }
    return isPrime;
}

// n>=6
// let: Hipoteza Goldbacha zachodzi
vector<int> parity_sum(int n)
{
    vector<bool> isPrime = generate_prime_array(n);
    int i = 1;
    while (true)
    {
        if (isPrime[i] && isPrime[n - i])
        {
            vector<int> results{i, n - i};
            return results;
        }
        i++;
    }
}

vector<int> rozklad(int n)
{
    vector<int> results;
    if (n <= 1)
        return results;
    if (n == 2)
    {
        results.push_back(2);
        return results;
    }
    if (n == 4)
    {
        results.push_back(2);
        results.push_back(2);
        return results;
    }

    vector<int> parityResults;
    if (n % 2 != 0)
    {
        results.push_back(3);
        parityResults = rozklad(n - 3);
    }
    else
    {
        parityResults = parity_sum(n);
    }

    push_vector(results, parityResults);
    parityResults.clear();
    return results;
}

bool is_prime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool check(int n, const vector<int> r)
{
    if (r.size() > 3)
        return false;
    if (n % 2 == 0)
    {
        if (r.size() > 2)
            return false;
    }

    int sum = 0;
    for (int c : r)
    {
        if (!is_prime(c))
            return false;
        sum += c;
    }
    return sum == n;
}

int main()
{
    for (int i = 2; i < 100; i++)
    {
        vector<int> r = rozklad(i);
        cout << i;
        if (!check(i, r))
        {
            cout << " wrong: ";
        }
        else
            cout << " good: ";
        for (int c : r)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}