#include <limits.h>
#include <algorithm>
#include <iostream>

class CurrentChange {
   public:
    bool possible;
    int coinsCount;

    CurrentChange(bool possible, int coinsCount) {
        this->possible = possible;
        this->coinsCount = coinsCount;
    }
};

CurrentChange** GetChangesTable(int change) {
    CurrentChange** changes = new CurrentChange*[change + 1];
    changes[0] = new CurrentChange(true, 0);

    return changes;
}

void FindPossibleChanges(int coins[], int coinsSize, int change, CurrentChange** changes) {
    for (int currentChange = 1; currentChange <= change; currentChange++) {
        changes[currentChange] = new CurrentChange(false, INT_MAX);
        for (int coinIndex = 0; coinIndex < coinsSize; coinIndex++) {
            if (currentChange == coins[coinIndex] || (currentChange > coins[coinIndex] && changes[currentChange - coins[coinIndex]]->possible)) {
                changes[currentChange]->possible = true;
                break;
            }
        }
    }
}

void CountCoins(int coins[], int coinsSize, int change, CurrentChange** changes) {
    for (int currentChange = 1; currentChange <= change; currentChange++) {
        if (!changes[currentChange]->possible)
            continue;

        for (int coinIndex = 0; coinIndex < coinsSize; coinIndex++) {
            if (currentChange < coins[coinIndex] || !changes[currentChange - coins[coinIndex]]->possible)
                continue;

            if (currentChange == coins[coinIndex]) {
                changes[currentChange]->coinsCount = 1;
                break;
            }

            changes[currentChange]->coinsCount = std::min(
                changes[currentChange - coins[coinIndex]]->coinsCount + 1,
                changes[currentChange]->coinsCount);
        }
    }
}

void Print(int change, CurrentChange** changes) {
    for (int i = 0; i <= change; i++) {
        std::cout << i << ":\t" << changes[i]->coinsCount << "\n";
    }
}

void DeleteChanges(CurrentChange** changes, int change) {
    for (int i = 0; i <= change; i++) {
        delete changes[i];
    }
    delete[] changes;
}

int GetMinimalNumberOfCoinsInChange(int coins[], int coinsSize, int change, bool debug) {
    CurrentChange** changes = GetChangesTable(change);

    FindPossibleChanges(coins, coinsSize, change, changes);
    CountCoins(coins, coinsSize, change, changes);

    int minimalNumberOfCoinsInChange = changes[change]->coinsCount;

    if (debug) Print(change, changes);

    DeleteChanges(changes, change);

    return minimalNumberOfCoinsInChange;
}

int main() {
    std::cout << GetMinimalNumberOfCoinsInChange(new int[4]{2, 3, 20, 50}, 4, 21, false) << "\n";
    std::cout << GetMinimalNumberOfCoinsInChange(new int[4]{2, 3, 20, 50}, 4, 80, true) << "\n";
}