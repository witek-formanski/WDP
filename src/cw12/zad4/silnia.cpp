/*
    5! = 4 * 4! + 3 * 3! + 2 * 2! + 1 * 1! + 1
    5! = 4 * 24 + 18 + 4 + 1 + 1
*/

#include <iostream>
#include <vector>

class Program {
    std::vector<int> factorials_map;
    std::vector<int> factorial_indexes;

    void set_factorials_map(int n) {
        if (n < 0)
            return;

        factorials_map.push_back(1);
        int i = 0;

        while (factorials_map[i] < n) {
            i++;
            factorials_map.push_back(factorials_map[i - 1] * i);
        }

        factorials_map.pop_back();
    }

    int get_highest_factorial(int n) {
        int left = 0;
        int right = factorials_map.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (factorials_map[mid] <= n) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }

    void factorials(int n) {
        if (!n)
            return;

        int i = get_highest_factorial(n);
        factorial_indexes.push_back(i);
        factorials(n - factorials_map[i]);
    }

    void print() {
        for (int factorial : factorial_indexes)
            std::cout << factorial << " ";
        std::cout << "\n";

        for (int factorial : factorial_indexes)
            std::cout << factorials_map[factorial] << " ";
        std::cout << "\n";
    }

   public:
    Program(int n) {
        set_factorials_map(n);
        factorials(n);
        print();
    }
};

int main() {
    Program(169);
    Program(42);
}