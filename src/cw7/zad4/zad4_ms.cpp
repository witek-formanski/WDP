#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// T(n) = O(nlogn)
// M(n) = O(n)
// https://math.stackexchange.com/questions/3974110/sorting-an-array-to-get-the-maximum-combined-sum-of-the-differences-between-ever
std::vector<float> przekładaniec(const std::vector<float> x)
{
    vector<float> sorted(x.size());
    copy(x.begin(), x.end(), sorted.begin());
    sort(sorted.begin(), sorted.end());

    vector<float> results(x.size());
    if (x.size() % 2 == 0)
    {
        bool ascending = true;
        int smallestI = (x.size() / 2) - 1, biggestI = x.size() / 2;
        for (int i = 0; i < x.size() / 2; i++)
        {
            if (ascending)
            {
                results[i] = sorted[smallestI--];
                results[x.size() - 1 - i] = sorted[biggestI++];
            }
            else
            {
                results[i] = sorted[biggestI++];
                results[x.size() - 1 - i] = sorted[smallestI--];
            }
            ascending = !ascending;
        }
    }
    else{
        bool shouldPutSmallest = true;
        int smallestI = 0, biggestI = x.size() - 1 - 1;
        int pivot = x.size()/2;
        results[pivot] = sorted[x.size()-1];
        for (int i = 1; i <= pivot; i++)
        {
            if (shouldPutSmallest)
            {
                results[pivot-i] = sorted[smallestI++];
                results[pivot+i] = sorted[smallestI++];
            }
            else
            {
                results[pivot-i] = sorted[biggestI--];
                results[pivot+i] = sorted[biggestI--];
            }
            shouldPutSmallest = !shouldPutSmallest;
        }
    }

    return results;
}

float sum(const std::vector<float> x)
{
    float sum = 0;
    for (int i = 1; i < x.size(); i++)
    {
        sum += abs(x[i - 1] - x[i]);
    }
    return sum;
}

// T(n) = O(n!)
// M(n) = O(n)
std::vector<float> przekładaniec_brut(const std::vector<float> x)
{
    vector<float> perm(x.size());
    copy(x.begin(), x.end(), perm.begin());
    sort(perm.begin(), perm.end());

    float max = 0;
    vector<float> results(x.size());
    while (next_permutation(perm.begin(), perm.end()))
    {
        float currentSum = sum(perm);
        if (currentSum > max)
        {
            max = currentSum;
            copy(perm.begin(), perm.end(), results.begin());
        }
    }
    return results;
}

vector<float> randomVector()
{
    srand((unsigned)time(NULL));
    int length = 0;
    while (length <= 3)
    {
        length = rand() % 10;
    }
    vector<float> ret;
    for (int i = 0; i < length; i++)
    {
        float nextNum = (rand() % 10000) / 100.0;
        ret.push_back(nextNum);
    }
    return ret;
}

int main()
{
    int n;
    cin >> n;
    vector<float> x;
    for (int i = 0; i < n; i++)
    {
        float input;
        cin >> input;
        x.push_back(input);
    }

    // vector<float> x = randomVector();

    vector<float> bestPerm = przekładaniec(x);
    //int sumBest = sum(bestPerm);
    for (float a : bestPerm)
    {
        cout << a << endl;
    }

    // vector<float> brutPerm = przekładaniec_brut(x);
    // int sumBrut = sum(brutPerm);
    // if (sumBest != sumBrut)
    // {
    //     cout << "bad :(" << endl;
    //     for (float a : brutPerm)
    //     {
    //         cout << a << endl;
    //     }
    //     cout << endl
    //          << sumBest << " != " << sumBrut << endl;
    // }
}