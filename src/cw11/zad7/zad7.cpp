#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

// brut \/

typedef struct c *Stick;
struct c
{
    int glue;
    int l;
    int r;
    int dl;
};

Stick new_stick(int glue, int l, int r, int dl)
{
    Stick st = (Stick)malloc(sizeof(c));
    st->glue = glue;
    st->l = l;
    st->r = r;
    st->dl = dl;
    return st;
}

Stick new_stick(Stick a, Stick b)
{
    int dl = a->dl + b->dl;
    Stick bigger = new_stick(a->glue + b->glue + max(a->dl, b->dl), min(a->l, b->l), max(a->r, b->r), dl);
    return bigger;
}

bool compare(pair<pair<Stick *, Stick *>, int> a, pair<pair<Stick *, Stick *>, int> b)
{
    return a.second < b.second;
}

int brut(const vector<int> &x)
{
    int n = (int)x.size();
    vector<int> c(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        c[i] = i;
    }

    int min = INT32_MAX;
    do
    {
        vector<Stick> sticks(n);
        for (int i = 0; i < n; i++)
        {
            sticks[i] = new_stick(0, i, i, x[i]);
        }

        vector<pair<pair<Stick *, Stick *>, int>> order(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            order[i] = make_pair(make_pair(&sticks[i], &sticks[i + 1]), c[i]);
        }
        sort(order.begin(), order.end(), compare);

        for (int i = 0; i < n - 1; i++)
        {
            Stick *a = order[i].first.first;
            Stick *b = order[i].first.second;
            Stick bigger = new_stick(*a, *b);
            free(*a);
            free(*b);
            sticks[bigger->l] = bigger;
            sticks[bigger->r] = bigger;
        }
        if (sticks[0]->glue < min)
        {
            min = sticks[0]->glue;
        }
        free(sticks[0]);
        sticks.clear();
    } while (next_permutation(c.begin(), c.end()));
    return min;
}

// brut /\

int calc_sum(int *sums, int starting, int ending)
{
    int outside = 0;
    if (starting != 0)
        outside = sums[starting - 1];
    int length = sums[ending] - outside;
    return length;
}

int calc_glue(int l, int r, int **dp, int *sums)
{
    int currMin = INT32_MAX;
    for (int i = l + 1; i <= r; i++)
    {
        int current = dp[l][i - 1] + dp[i][r] + max(calc_sum(sums, l, i - 1), calc_sum(sums, i, r));
        if (current < currMin)
        {
            currMin = current;
        }
    }
    return currMin;
}

int *calc_prefix_sum(const vector<int> &x)
{
    int n = (int)x.size();
    int *sums = (int *)malloc((size_t)n * sizeof(int));
    if (n == 0)
        return sums;
    sums[0] = x[0];
    for (int i = 1; i < n; i++)
    {
        sums[i] = sums[i - 1] + x[i];
    }
    return sums;
}

int **make_2d(int x, int y)
{
    int **ret = (int **)malloc((size_t)y * (sizeof(int *)));
    for (int i = 0; i < y; i++)
    {
        ret[i] = (int *)malloc((size_t)x * sizeof(int));
        for (int j = 0; j < x; j++)
        {
            ret[i][j] = 0;
        }
    }
    return ret;
}

// T(n) = O(n^3)
// M(n) = O(n^2)
int klej(const vector<int> &x)
{
    int n = (int)x.size();
    int *sums = calc_prefix_sum(x);
    int **dp = make_2d(n, n);

    // c = r - l
    for (int c = 1; c < n; c++)
    {
        for (int l = 0; l + c < n; l++)
        {

            int r = l + c;
            dp[l][r] = calc_glue(l, r, dp, sums);
        }
    }

    int ans = dp[0][n - 1];
    return ans;
}

std::vector<int> generate_random(int NumberCount, int minimum, int maximum)
{
    std::random_device rd;
    std::mt19937 gen(rd()); // these can be global and/or static, depending on how you use random elsewhere

    std::vector<int> values(NumberCount);
    std::uniform_int_distribution<> dis(minimum, maximum);
    std::generate(values.begin(), values.end(), [&]()
                  { return dis(gen); });
    return values;
}

int main()
{
    int n;
    cin >> n;

    while (true)
    {
        vector<int> stick = generate_random(n,0, 100);

        int glue = klej(stick);
        int brutAns = brut(stick);
        cout << glue << " " << brutAns << (brutAns == glue ? " correct" : " wrong") << endl;
        stick.clear();
    }
    return 0;
}