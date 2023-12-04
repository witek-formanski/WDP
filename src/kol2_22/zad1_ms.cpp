#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// let: minimal element exists
int get_min(queue<int> *sums, const std::vector<int> r, int *i)
{
    if (sums->empty() || sums->front() > r[*i]){
        int ret = r[*i];
        (*i)++;
        return ret;
    }
    int ret = sums->front();
    sums->pop();
    return ret;
}

int robakołak(const std::vector<int> r)
{
    queue<int> sums;

    // current index in r
    int i = 0;
    while (!sums.size() > 1 || i < r.size())
    {
        int a = get_min(&sums, r, &i);
        int b = get_min(&sums, r, &i);
        if (a == b)
            sums.push(a - 1);
        else
            sums.push(a + b-1);
    }
    return sums.front();
}

int main()
{
    int n;
    cin >> n;
    vector<int> wilkolaki(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wilkolaki[i];
    }

    int w = robakołak(wilkolaki);
    cout << w << endl;
}