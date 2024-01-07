/*
    T(n, k) = O(n * k)
    M(n, k) = O(n * k)

    n - liczba nominałów
    k - kwota
*/

#include <limits.h>
#include <algorithm>
#include <iostream>

class Amount {
   public:
    int banknoteTypes;
    int* banknoteCombinations;

    Amount(int banknoteTypes, int banknotesSize) {
        this->banknoteTypes = banknoteTypes;
        banknoteCombinations = new int[banknotesSize]{0};
    }

    ~Amount() {
        delete[] banknoteCombinations;
    }
};

Amount** InitAmountsTable(int amount, int banknotesSize) {
    Amount** amounts = new Amount*[amount + 1];
    amounts[0] = new Amount(0, banknotesSize);
    for (int a = 1; a <= amount; a++) {
        amounts[a] = new Amount(-1, banknotesSize);
    }

    return amounts;
}

void SetBanknoteCombinations(int banknotes[], int banknotesSize, int amount, Amount** amounts) {
    int currentMin;
    for (int a = 1; a <= amount; a++) {
        currentMin = INT_MAX;
        for (int b = 0; b < banknotesSize; b++) {
            if (a < banknotes[b])
                continue;
            
            if (amounts[a - banknotes[b]]->banknoteTypes == -1)
                continue;

            amounts[a]->banknoteCombinations[b] =
                (!amounts[a - banknotes[b]]->banknoteCombinations[b])
                    ? amounts[a - banknotes[b]]->banknoteTypes + 1
                    : amounts[a]->banknoteCombinations[b] = std::min(
                        amounts[a - banknotes[b]]->banknoteTypes + 1,
                        amounts[a - banknotes[b]]->banknoteCombinations[b]);
            
            currentMin = std::min(amounts[a]->banknoteCombinations[b], currentMin);
        }
        if (currentMin != INT_MAX)
            amounts[a]->banknoteTypes = currentMin;
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
            std::cout << amounts[a]->banknoteCombinations[b] << " ";
        std::cout << "\t" << amounts[a]->banknoteTypes << "\n";
    }
}

void DeleteAmounts(Amount** amounts, int amount) {
    for (int i = 0; i <= amount; i++)
        delete amounts[i];
    delete[] amounts;
}

int GetSmallestDifferentBanknotesCount(int banknotes[], int banknotesSize, int amount, bool debug) {
    if (banknotes[0] < 1 || banknotesSize < 1)
        return -1;

    Amount** amounts = InitAmountsTable(amount, banknotesSize);

    SetBanknoteCombinations(banknotes, banknotesSize, amount, amounts);

    int smallestDifferentBanknotesCount = amounts[amount]->banknoteTypes;

    if (debug) Print(banknotes, banknotesSize, amount, amounts);

    DeleteAmounts(amounts, amount);

    return smallestDifferentBanknotesCount;
}

int main() {
    std::cout << GetSmallestDifferentBanknotesCount(new int[5]{6, 11, 13, 15, 19}, 5, 41, false) << "\n";
    std::cout << GetSmallestDifferentBanknotesCount(new int[5]{6, 11, 13, 15, 19}, 5, 666, false) << "\n";
    std::cout << GetSmallestDifferentBanknotesCount(new int[5]{6, 11, 13, 15, 19}, 5, 80, true) << "\n";
}