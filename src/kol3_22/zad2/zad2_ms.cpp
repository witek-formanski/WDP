#define START_I 2

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum stepType
{
    multiply = 0,
    increment = 1
};

typedef struct s *step;
struct s
{
    int i = -1;
    int j = -1;
    stepType type;
    int prevI;
};

step make_default(int lastFoundI)
{
    step newStep = (step)malloc(sizeof(s));
    newStep->i = lastFoundI;
    newStep->j = lastFoundI + 1;
    newStep->prevI = lastFoundI;
    newStep->type = multiply;
    return newStep;
}

bool next_step(step step)
{
    if (step->type == increment)
        return false;
    if (step->j >= START_I)
    {
        step->j--;
        return true;
    }
    if (step->i >= START_I)
    {
        step->i--;
        step->j = step->prevI;
        return true;
    }
    step->type = increment;
    return true;
}

int calculate_step(step stepToBeMade, const vector<int> sequence)
{
    if (stepToBeMade->type == increment)
    {
        return sequence[stepToBeMade->prevI] + 1;
    }
    return sequence[stepToBeMade->i] * sequence[stepToBeMade->j];
}

// try take next step
// return false when there is need to step back
bool try_next_step(step previousStep, const vector<bool> takenSteps, vector<int> &sequence, int n)
{
    int prev = sequence[previousStep->prevI];
    int currVal;
    do
    {
        if (!next_step(previousStep))
            return false;
        currVal = calculate_step(previousStep, sequence);
    } while (currVal <= prev || takenSteps[currVal] || currVal > n);
    sequence[previousStep->prevI + 1] = currVal;
    return true;
}

// change best found sequence if better
void update_best(vector<int> &best, int *bestLength, const vector<int> toBeChecked, int length)
{
    if (*bestLength > length)
    {
        *bestLength = length;
        for (int i = 0; i < *bestLength; i++)
        {
            best[i] = toBeChecked[i];
        }
        // leave unwanted elems untouched (we will resize anyways)
    }
}

// according (hopefully) to tips from email written by test-checkers
// multiplication before incrementing is a better strategy: Mikołaj Bilski
// also special thanks to: Marcin Rolbiecki
// works for 1<=n<=2111
vector<int> ciag(int n)
{
    if (n == 1)
        return {1};
    if (n == 2)
        return {1, 2};

    vector<int> currBestSequence(n, 0);
    int currentBestLength = n + 1;

    for (int length = START_I + 1; length <= n && length < currentBestLength; length++)
    {
        vector<int> sequence(length);
        sequence[0] = 1;
        sequence[1] = 2;

        stack<step> steps;
        steps.push(make_default(START_I - 1));

        vector<bool> wasChecked(n + 1, false);
        wasChecked[1] = true;
        wasChecked[2] = true;

        int stepsToBeMade = length - START_I;

        while (!steps.empty())
        {
            step currentStep = steps.top();
            int currentStepsCount = START_I + steps.size() - 1;
            if (sequence.back() == n)
            {
                // found the shortest one
                update_best(currBestSequence, &currentBestLength, sequence, length);
                break;
            }
            if (sequence[currentStep->prevI] > n / 2)
            {
                // futher multiplication is pointless, fill with incremetation
                vector<int> filled(sequence.begin(), sequence.begin() + 2 + steps.size() - 1);
                while (filled.back() < n)
                {
                    filled.push_back(filled.back() + 1);
                    currentStepsCount++;
                }
                update_best(currBestSequence, &currentBestLength, filled, currentStepsCount);
                filled.clear();
                free(currentStep);
                steps.pop();
                continue;
            }

            if (!try_next_step(currentStep, wasChecked, sequence, n))
            {
                // abort, no further opportunities
                free(currentStep);
                steps.pop();
                continue;
            }

            wasChecked[sequence[currentStep->prevI]] = true;
            if (steps.size() < stepsToBeMade)
            {
                steps.push(make_default(currentStep->prevI + 1));
            }
        }

        while (!steps.empty())
        {
            free(steps.top());
            steps.pop();
        }
    }

    currBestSequence.resize(currentBestLength);
    return currBestSequence;
}

int main()
{
    int n;
    cin >> n;
    // for (int n = 1;; n++)
    // {
    //     cout<<n<<"."<<endl;
    vector<int> sequence = ciag(n);
    for (int c : sequence)
    {
        cout << c << " ";
    }
    cout << endl;
    sequence.clear();
    //}
    return 0;
}
