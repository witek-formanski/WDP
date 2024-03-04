#include <iostream>
#include <stack>

using namespace std;

int best_area(stack<int> *towers, int arr[], int currentTower, int i)
{
    int max = 0;
    while (!towers->empty() && arr[towers->top()] > currentTower)
    {
        int width = (i-1) - towers->top() + 1;
        int area = width * arr[towers->top()];
        if (area > max)
        {
            max = area;
        }
        towers->pop();
    }
    return max;
}

int prostokat(int n, int arr[])
{
    if (n <= 0)
        return 0;
    stack<int> towers;
    towers.push(0);
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        int currArea = best_area(&towers, arr, arr[i], i);
        if (currArea > max)
            max = currArea;
        towers.push(i);
    }
    return max;
}

int prostokat_brut(int n, int arr[])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int currMin = arr[i];
        for (int j = i; j < n; j++)
        {
            if (currMin > arr[j])
                currMin = arr[j];

            int currArea = (j-i+1) * currMin;
            if(currArea > max)
            max=currArea;
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    int *arr = (int *)malloc((size_t)n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int bestArea = prostokat(n, arr);
    cout << bestArea << endl;

    free(arr);
}