/*
    T(n, k) = O(n^2 * k)
    M(n, k) = O(n * k)

    n - liczba nominałów
    k - kwota
*/

#include <limits.h>
#include <algorithm>
#include <iostream>

class CurrentAmount {
   public:
    int breaksCount;
    int* coinsCombinations;

    CurrentAmount(int coinsCount, int coinsSize) {
        this->breaksCount = coinsCount;
        coinsCombinations = new int[coinsSize]{0};
    }
};

CurrentAmount** GetAmountsTable(int amount) {
    return new CurrentAmount*[amount + 1];
}

void InitAmounts(int coins[], int coinsSize, int amount, CurrentAmount** amounts) {
    for (int a = 0; a <= amount; a++) {
        amounts[a] = new CurrentAmount(0, coinsSize);
        for (int c = 0; c < coinsSize; c++) {
            if (a < coins[c])
                continue;

            if (a == coins[c]) {
                amounts[a]->coinsCombinations[c] = 1;
                break;
            }

            if (amounts[a - coins[c]]->coinsCombinations[c] == 0)
                continue;

            amounts[a]->coinsCombinations[c] = 1;
        }
    }
}

void FindAllCombinations(int coins[], int coinsSize, int amount, CurrentAmount** amounts) {
    for (int greater = 1; greater < coinsSize; greater++) {
        for (int smaller = 0; smaller < greater; smaller++) {
            for (int a = 1; a <= amount; a++) {
                if (a < coins[greater])
                    continue;

                amounts[a]->coinsCombinations[smaller] += amounts[a - coins[greater]]->coinsCombinations[smaller];
            }
        }
    }
}

void CountPossibleBreaks(int coins[], int coinsSize, int amount, CurrentAmount** amounts) {
    for (int a = 0; a <= amount; a++) {
        for (int c = 0; c < coinsSize; c++) {
            amounts[a]->breaksCount += amounts[a]->coinsCombinations[c];
        }
    }
}

void Print(int coins[], int coinsSize, int amount, CurrentAmount** amounts) {
    std::cout << "\t";
    for (int c = 0; c < coinsSize; c++) {
        std::cout << coins[c] << " ";
    }
    std::cout << "\n";

    for (int i = 0; i <= amount; i++) {
        std::cout << i << ":\t";
        for (int c = 0; c < coinsSize; c++) {
            std::cout << amounts[i]->coinsCombinations[c] << " ";
        }
        std::cout << "\t" << amounts[i]->breaksCount << "\n";
    }
}

void DeleteAmounts(CurrentAmount** amounts, int amount) {
    for (int i = 0; i <= amount; i++) {
        delete amounts[i];
    }
    delete[] amounts;
}

int CountPossibleWaysToBreakAmount(int coins[], int coinsSize, int amount, bool debug) {
    if (coins[0] < 1 || coinsSize < 1)
        return -1;

    CurrentAmount** amounts = GetAmountsTable(amount);

    InitAmounts(coins, coinsSize, amount, amounts);
    FindAllCombinations(coins, coinsSize, amount, amounts);
    CountPossibleBreaks(coins, coinsSize, amount, amounts);

    int possibleWaysToBreakAmount = amounts[amount]->breaksCount;

    if (debug) Print(coins, coinsSize, amount, amounts);

    DeleteAmounts(amounts, amount);

    return possibleWaysToBreakAmount;
}

int main() {
    std::cout << CountPossibleWaysToBreakAmount(new int[4]{2, 3, 20, 50}, 4, 21, false) << "\n";
    std::cout << CountPossibleWaysToBreakAmount(new int[3]{2, 3, 5}, 3, 80, true) << "\n";
}