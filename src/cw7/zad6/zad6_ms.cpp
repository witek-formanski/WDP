#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct interv
{
    int a, b, v;
};

typedef struct interv *interval;

interval new_interval(int a, int b, int v)
{
    interval inv = (interval)malloc(3 * sizeof(int));
    inv->a = a;
    inv->b = b;
    inv->v = v;
    return inv;
}

void bin_search(const vector<interval> intervals, int value, int change)
{
    int i = 0, j = intervals.size() - 1;
    while (i < j)
    {
        int pivot = (i + j) / 2;
        if (intervals[pivot]->a < value)
        {
            i = pivot + 1;
        }
        else
            j = pivot;
    }
    intervals[i]->v += change;
}

void push_pair(int i, int v, stack<pair<int, int>> *s)
{
    pair<int, int> newTop(i, v);
    s->push(newTop);
}

// O(nlogn)
int rejs(int k, const std::vector<int> start, const std::vector<int> end)
{
    vector<int> sorted(start.size() * 2);
    copy(start.begin(), start.end(), sorted.begin());
    copy(end.begin(), end.end(), sorted.begin() + start.size());
    // (nlogn)
    sort(sorted.begin(), sorted.end());
    // create vector with all intervals (relevant)
    vector<interval> intervals;
    for (int i = 1; i < sorted.size(); i++)
    {
        intervals.push_back(new_interval(sorted[i - 1], sorted[i], 0));
    }
    sorted.clear();

    // O(nlogn)
    // fill intervals with values stating change in number of crewmates
    for (int i = 0; i < start.size(); i++)
    {
        bin_search(intervals, start[i], 1);
        bin_search(intervals, end[i], -1);
    }

    // now find the results
    // O(n)
    int max = 0;
    stack<pair<int, int>> maxes;
    push_pair(0, intervals[0]->v, &maxes);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i]->v < 0)
        {
            for (int j = 0; j < abs(intervals[i]->v); j++)
            {
                int currentLength = intervals[i - 1]->b - intervals[maxes.top().first]->a + 1;
                if (currentLength >= k)
                {
                    if (max < maxes.top().second)
                        max = maxes.top().second;
                }
                maxes.pop();
            }
            continue;
        }
        push_pair(i, maxes.top().second + intervals[i]->v, &maxes);
    }
    return max;
}

int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    vector<int> start(n);
    for (int i = 0; i < n; i++)
    {
        cin >> start[i];
    }
    vector<int> end(n);
    for (int i = 0; i < n; i++)
    {
        cin >> end[i];
    }

    int w = rejs(k, start, end);
    cout << w << endl;
}