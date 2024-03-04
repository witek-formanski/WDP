#define NOTHING_HERE -1

#include <iostream>
#include <stack>

using namespace std;

/*
5    #
4  # #
3  ####
2 ######
1 #######
i 1234567
k 1214111
*/

/// @brief
/// @param arr array with towers [1..n]
/// @param size elements count n
/// @param results  array [1..n] with k's, when arr[i] = max(arr[i-results[i]+1], ... arr[i])
/// @return
int *katastrofa(int *arr, int size)
{
    stack<int> indexes;
    // if all towers are lower than current, when
    indexes.push(NOTHING_HERE);

    int *results = (int *)malloc((size_t)(size + 1) * sizeof(int));
    for (int i = 1; i <= size; i++)
    {
        // remove all lower / same towers, because there are irrelevants
        while (indexes.top() != NOTHING_HERE && arr[indexes.top()] <= arr[i])
            indexes.pop();
        // because indexes.top() is the index of first higher than arr[i] tower
        // if arr[i] is the highest yet then
        if (indexes.top() == NOTHING_HERE)
            results[i] = i;
        else
            results[i] = i - indexes.top();
        // add current tower
        indexes.push(i);
    }
    return results;
}

int main()
{
    int n;
    cin>>n;
    int* arr = (int*)malloc((size_t)(n+1)*sizeof(int));
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }
    int* results = katastrofa(arr,n);
    for(int i = 1; i<=n; i++){
        cout<<results[i]<<endl;
    }

    free(arr);
    free(results);
}