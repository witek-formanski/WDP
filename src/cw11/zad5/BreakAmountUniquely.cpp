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

CurrentAmount** GetAmountsTable(const std::vector<int>& banknotes, int amount) {
    CurrentAmount** amounts = new CurrentAmount*[amount + 1];

    for (int i = 0; i <= amount; i++) {
        amounts[i] = new CurrentAmount(banknotes.size());
    }

    amounts[0]->unique = true;

    return amounts;
}

void SetPossibleBreaks(const std::vector<int>& banknotes, CurrentAmount** amounts, int currentAmount) {
    for (int banknoteIndex = 0; banknoteIndex < banknotes.size(); banknoteIndex++) {
        amounts[currentAmount]->possibleBreak[banknoteIndex] =
            (currentAmount < banknotes[banknoteIndex] || !amounts[currentAmount - banknotes[banknoteIndex]]->unique)
                ? false
                : true;
    }
}

int GetSumOfPossibleBreaks(const std::vector<int>& banknotes, CurrentAmount** amounts, int currentAmount) {
    int sum = 0;
    for (int banknoteIndex = banknotes.size() - 1; banknoteIndex >= 0; banknoteIndex--) {
        if (amounts[currentAmount]->possibleBreak[banknoteIndex] == 1) {
            sum++;
            amounts[currentAmount]->uniqueBreakerBanknoteIndex = banknoteIndex;
        }
    }

    return sum;
}

// 15 = 7 + 8 = 8 + 7
int SubstractTheSameSetduplicates(const std::vector<int>& banknotes, CurrentAmount** amounts, int currentAmount) {
    bool* visited = new bool[banknotes.size()]{false};
    for (int banknoteIndex = 0; banknoteIndex < banknotes.size(); banknoteIndex++) {
        if (visited[banknoteIndex]) continue;

        visited[banknoteIndex] = true;
        if (!amounts[currentAmount]->possibleBreak[banknoteIndex]) continue;

        banknoteIndex = amounts[currentAmount - banknotes[banknoteIndex]]->uniqueBreakerBanknoteIndex;

        while (!visited[banknoteIndex]) {
            visited[banknoteIndex] = true;
            amounts[currentAmount]->possibleBreak[banknoteIndex] = false;
            banknoteIndex = amounts[currentAmount - banknotes[banknoteIndex]]->uniqueBreakerBanknoteIndex;
        }
    }
    
    return GetSumOfPossibleBreaks(banknotes, amounts, currentAmount);
}

void SetUniqueFlag(CurrentAmount** amounts, int currentAmount, int sum) {
    amounts[currentAmount]->unique =
        (sum == 1)
            ? true
            : false;
}

void SetLastUniqueValue(CurrentAmount** amounts, int currentAmount, int sum) {
    amounts[currentAmount]->lastUnique =
        (amounts[currentAmount]->unique)
            ? currentAmount
            : amounts[currentAmount - 1]->lastUnique;
}

int GetHighestUniqueAmonut(int amount, CurrentAmount** amounts) {
    for (int currentAmount = amount; currentAmount >= 0; currentAmount--) {
        if (amounts[currentAmount]->unique)
            return currentAmount;
    }
}

void Print(const std::vector<int>& banknotes, int amount, CurrentAmount** amounts) {
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

void DeleteAmounts(int amount, CurrentAmount** amounts) {
    for (int i = 0; i <= amount; i++) {
        delete amounts[i];
    }
    delete[] amounts;
}

int BreakAmountUniquely(const std::vector<int>& banknotes, int amount, bool debug) {
    if (amount < banknotes[0])
        return 0;

    int highestUniqueAmonut, sum;
    CurrentAmount** amounts = GetAmountsTable(banknotes, amount);

    for (int currentAmount = 1; currentAmount <= amount; currentAmount++) {
        SetPossibleBreaks(banknotes, amounts, currentAmount);
        sum = GetSumOfPossibleBreaks(banknotes, amounts, currentAmount);

        if (sum > 1)
            sum = SubstractTheSameSetduplicates(banknotes, amounts, currentAmount);

        SetUniqueFlag(amounts, currentAmount, sum);
        SetLastUniqueValue(amounts, currentAmount, sum);
    }

    highestUniqueAmonut = GetHighestUniqueAmonut(amount, amounts);

    if (debug) 
        Print(banknotes, amount, amounts);

    DeleteAmounts(amount, amounts);

    return highestUniqueAmonut;
}

int main() {
    std::cout << BreakAmountUniquely({7, 8, 9, 10}, 18, true) << "\n";
    std::cout << BreakAmountUniquely({7, 8, 9, 10}, 19, true) << "\n";
}