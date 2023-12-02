#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// T(n) = O(nlogn)
// M(n) = O(n)
bool trojkat(const std::vector<int> v)
{
    if (v.size() < 3)
        return false;
    vector<int> sorted(v.size());
    copy(v.begin(), v.end(), sorted.begin());
    sort(sorted.begin(), sorted.end());

    for (int i = 2; i < v.size(); i++)
    {
        if (v[i - 2] + v[i - 1] > v[i])
            return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        v.push_back(input);
    }

    cout << trojkat(v) << endl;
}