/*
    T(n) = O(log n)
    M(n) = O(log n)

    generowany ciąg nie jest najkrótszy z możliwych
*/

#include <iostream>
#include <vector>

int get_bits_count(int n) {
    int count = 0;
    while (n != 0) {
        n /= 2;
        count++;
    }

    return count;
}

std::vector<int> not_the_shortest_sequence(int n) {
    int temp = 1;
    std::vector<int> sequence{temp};
    if (n == 1)
        return sequence;

    int bits_count = get_bits_count(n);
    for (int i = bits_count - 2; i >= 0; i--) {
        temp *= 2;
        sequence.push_back(temp);
        if ((n & (1 << i)) >> i) {
            temp += 1;
            sequence.push_back(temp);
        }
    }

    return sequence;
}

void print_vector(std::vector<int> vect) {
    for (int x : vect)
        std::cout << x << " ";
    std::cout << "\n";
}

int main() {
    for (int i = 1; i <= 100; i++)
        print_vector(not_the_shortest_sequence(i));
}