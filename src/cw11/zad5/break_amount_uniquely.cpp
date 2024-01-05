#include <iostream>
#include <vector>

class CurrentAmount {
   public:
    int lastUnique;
    bool* possibleBreak;
    bool unique;
    int uniqueBreakerBanknoteIndex;

    CurrentAmount() {}

    CurrentAmount(int size) {
        possibleBreak = new bool[size]{0};
    }

    ~CurrentAmount() {
        delete[] possibleBreak;
    }
};

int BreakAmountUniquely(const std::vector<int>& banknotes, int amount, bool debug) {
    if (amount < banknotes[0])
        return 0;

    int highestUniqueAmonut, sum;
    CurrentAmount** amounts = new CurrentAmount*[amount + 1];

    for (int i = 0; i <= amount; i++) {
        amounts[i] = new CurrentAmount(banknotes.size());
    }

    amounts[0]->unique = true;

    for (int currentAmount = 1; currentAmount <= amount; currentAmount++) {
        sum = 0;

        for (int banknoteIndex = banknotes.size() - 1; banknoteIndex >= 0; banknoteIndex--) {
            amounts[currentAmount]->possibleBreak[banknoteIndex] =
                (currentAmount < banknotes[banknoteIndex] || amounts[currentAmount - banknotes[banknoteIndex]]->unique == false)
                    ? false
                    : true;
            if (amounts[currentAmount]->possibleBreak[banknoteIndex] == 1) {
                sum++;
                amounts[currentAmount]->uniqueBreakerBanknoteIndex = banknoteIndex;
            }
            // sum += amounts[currentAmount]->possibleBreak[banknoteIndex];
        }
        // amounts[currentAmount]->unique =
        //     (sum == 1)
        //         ? true
        //         : false;
        if (sum == 0) {
            amounts[currentAmount]->unique = false;
        } else if (sum == 1) {
            amounts[currentAmount]->unique = true;
        } else if (sum > 1) {
            bool* visited = new bool[banknotes.size()]{false};
            for (int banknoteIndex = 0; banknoteIndex < banknotes.size(); banknoteIndex++) {
                if (visited[banknoteIndex]) continue;

                visited[banknoteIndex] = true;
                if (!amounts[currentAmount]->possibleBreak[banknoteIndex]) continue;

                // if (amounts[currentAmount]->possibleBreak[banknoteIndex] == true) {
                banknoteIndex = amounts[currentAmount - banknotes[banknoteIndex]]->uniqueBreakerBanknoteIndex;

                // amounts[currentAmount]->possibleBreak[banknoteIndex] = false;
                while (!visited[banknoteIndex]) {
                    // if (amounts[currentAmount]->possibleBreak[banknoteIndex] == true) {
                    visited[banknoteIndex] = true;
                    amounts[currentAmount]->possibleBreak[banknoteIndex] = false;
                    banknoteIndex = amounts[currentAmount - banknotes[banknoteIndex]]->uniqueBreakerBanknoteIndex;
                    // } else {
                    //     std::cout << "wowowow!\n";
                    // }
                }
                // }

                sum = 0;

                for (int banknoteIndex = banknotes.size() - 1; banknoteIndex >= 0; banknoteIndex--) {
                    // amounts[currentAmount]->possibleBreak[banknoteIndex] =
                    //     (currentAmount < banknotes[banknoteIndex] || amounts[currentAmount - banknotes[banknoteIndex]]->unique == false)
                    //         ? false
                    //         : true;
                    if (amounts[currentAmount]->possibleBreak[banknoteIndex] == 1) {
                        sum++;
                        amounts[currentAmount]->uniqueBreakerBanknoteIndex = banknoteIndex;
                    }
                    // sum += amounts[currentAmount]->possibleBreak[banknoteIndex];
                }
            }
        }

        amounts[currentAmount]->unique =
            (sum == 1)
                ? true
                : false;

        amounts[currentAmount]->lastUnique =
            (amounts[currentAmount]->unique)
                ? currentAmount
                : amounts[currentAmount - 1]->lastUnique;
    }

    for (int currentAmount = amount; currentAmount >= 0; currentAmount--) {
        if (amounts[currentAmount]->unique) {
            highestUniqueAmonut = currentAmount;
            break;
        }
    }

    if (debug) {
        std::cout << "\t";
        for (int j = 0; j < banknotes.size(); j++) {
            std::cout << banknotes[j] << " ";
        }
        std::cout << "\n";

        for (int i = 1; i <= amount; i++) {
            std::cout << i << ":\t";
            for (int j = 0; j < banknotes.size(); j++) {
                std::cout << amounts[i]->possibleBreak[j] << " ";
            }
            std::cout << "\n";
        }
    }

    for (int i = 0; i <= amount; i++) {
        delete amounts[i];
    }
    delete[] amounts;

    return highestUniqueAmonut;
}

int main() {
    // std::cout << true + true + true - 5 * true << "\n";
    // std::cout << BreakAmountUniquely({7, 8, 9, 10}, 18, true) << "\n";
    std::cout << BreakAmountUniquely({7, 8, 9, 10}, 19, true) << "\n";
}