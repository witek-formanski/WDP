#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int przedzial(const std::vector<int> x, int r)
{
    vector<int> sorted(x.size());
    copy(x.begin(), x.end(), sorted.begin());
    sort(sorted.begin(), sorted.end());
    int i = 0, j = 0;

    int bestC = sorted[0];
    int longest = 0;
    while (j < x.size()-1 || i<j)
    {   
        // move head max right
        while (j+1<x.size() && sorted[j + 1] <= sorted[i] + 2 * r)
        {
            j++;
        }
        if (j - i + 1 > longest)
        {
            longest = j - i + 1;
            bestC = (sorted[i] + r); // will be even, because we add 2*r
        }
        i++;
    }
    return bestC;
}

int main()
{
    int r;
    cin >> r;
    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int bestC = przedzial(x, r);
    cout << bestC << endl;
}