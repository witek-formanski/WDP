#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool is_smallest_in_x(const std::vector<float> x, int *currentPosinX, queue<float> *sums)
{
    if (sums->empty())
        return true;
    if (*currentPosinX >= x.size())
        return false;
    return sums->front() > x[*currentPosinX];
}

float get_smallest(const std::vector<float> x, int *currentPosinX, queue<float> *sums)
{
    if (is_smallest_in_x(x, currentPosinX, sums))
    {
        (*currentPosinX)++;
        return x[*currentPosinX - 1];
    }

    float smallest = sums->front();
    sums->pop();
    return smallest;
}

float zlewki(const std::vector<float> x, int k)
{
    queue<float> sums;
    int sumCount = 0;
    int currentPos = 0;

    while (sumCount++ < k)
    {
        float smallest = get_smallest(x, &currentPos, &sums);
        float secondSmallest = get_smallest(x, &currentPos, &sums);
        sums.push(smallest + secondSmallest);
    }

    return get_smallest(x, &currentPos, &sums);
}

int main()
{
    int k; cin >> k;
    int n; cin >> n;
    vector<float> x;
    for (int i = 0; i < n; i++)
    {
        float input;
        cin >> input;
        x.push_back(input);
    }

    cout << zlewki(x, k) << endl;
}