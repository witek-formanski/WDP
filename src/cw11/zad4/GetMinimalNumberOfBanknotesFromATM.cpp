/*
    T(n, k) = O(n * k^2)
    M(n, k) = O(n * k^2)

    n - liczba nominałów
    k - kwota
*/

#include <limits.h>

#include <algorithm>
#include <iostream>

class Combination {
   public:
    int val;
    int* banknotesLeft;

    Combination(int val, int size) {
        this->val = val;
        this->banknotesLeft = new int[size]{-1};
    }

    ~Combination() {
        delete[] banknotesLeft;
    }
};

class Amount {
   public:
    int minBanknotesInTotal;
    int minIndex;
    Combination** combinations;

    Amount(int minBanknotesInTotal, int minIndex, int size) {
        this->minBanknotesInTotal = minBanknotesInTotal;
        this->minIndex = minIndex;
        combinations = new Combination*[size];
        for (int i = 0; i < size; i++)
            combinations[i] = new Combination(INT_MAX, size);
    }

    ~Amount() {
        delete[] combinations;
    }
};

Amount** InitAmountsTable(int amount, int banknotesLeft[], int banknotesSize) {
    Amount** amounts = new Amount*[amount + 1];
    amounts[0] = new Amount(0, 0, banknotesSize);
    amounts[0]->combinations[0]->val = 0;
    for (int b = 0; b < banknotesSize; b++)
        amounts[0]->combinations[0]->banknotesLeft[b] = banknotesLeft[b];

    for (int a = 1; a <= amount; a++)
        amounts[a] = new Amount(INT_MAX, -1, banknotesSize);

    return amounts;
}

void CountBanknotes(int banknotes[], int banknotesLeft[], int banknotesSize, int amount, Amount** amounts) {
    int prevLeft;
    Amount* prevAmount;
    for (int a = 1; a <= amount; a++) {
        for (int b = 0; b < banknotesSize; b++) {
            if (a < banknotes[b])
                continue;

            prevAmount = amounts[a - banknotes[b]];
            if (prevAmount->minBanknotesInTotal == INT_MAX)
                continue;

            prevLeft = prevAmount->combinations[prevAmount->minIndex]->banknotesLeft[b];
            if (prevLeft == 0)
                continue;

            amounts[a]->combinations[b]->val = prevAmount->minBanknotesInTotal + 1;
            amounts[a]->combinations[b]->banknotesLeft[b] = prevLeft - 1;

            for (int i = 0; i < banknotesSize; i++) {
                if (i == b)
                    continue;

                amounts[a]->combinations[b]->banknotesLeft[i] = 
                    prevAmount->combinations[prevAmount->minIndex]->banknotesLeft[i];
            }

            if (amounts[a]->combinations[b]->val >= amounts[a]->minBanknotesInTotal)
                continue;
                
            amounts[a]->minBanknotesInTotal = amounts[a]->combinations[b]->val;
            amounts[a]->minIndex = b;
        }
    }
}

void Print(int banknotes[], int banknotesSize, int amount, Amount** amounts) {
    std::cout << "\t";
    for (int b = 0; b < banknotesSize; b++)
        std::cout << banknotes[b] << " ";
    std::cout << "\n";

    for (int a = 0; a <= amount; a++) {
        std::cout << a << ":\t";
        for (int b = 0; b < banknotesSize; b++)
            std::cout << amounts[a]->combinations[b]->val << " ";
        std::cout << "\t\t\t" << amounts[a]->minBanknotesInTotal << "\n";
    }
}

void DeleteAmounts(Amount** amounts, int amount) {
    for (int i = 0; i <= amount; i++)
        delete amounts[i];
    delete[] amounts;
}

int GetMinimalNumberOfBanknotesFromATM(int banknotes[], int banknotesLeft[], int banknotesSize, int amount, bool debug) {
    if (banknotes[0] < 1 || banknotesSize < 1)
        return -1;

    Amount** amounts = InitAmountsTable(amount, banknotesLeft, banknotesSize);

    CountBanknotes(banknotes, banknotesLeft, banknotesSize, amount, amounts);

    int minimalNumberOfBanknotesInAmount = amounts[amount]->minBanknotesInTotal;

    if (debug) Print(banknotes, banknotesSize, amount, amounts);

    DeleteAmounts(amounts, amount);

    return minimalNumberOfBanknotesInAmount;
}

int main() {
    std::cout << GetMinimalNumberOfBanknotesFromATM(new int[3]{3, 7, 12}, new int[3]{8, 3, 2}, 3, 69, false) << "\n";
    std::cout << GetMinimalNumberOfBanknotesFromATM(new int[3]{3, 7, 12}, new int[3]{8, 3, 2}, 3, 80, true) << "\n";
}