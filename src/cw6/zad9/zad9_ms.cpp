#include <iostream>
#include <stack>

// let: results fit in arr
void inc(int n, bool arr[])
{
    if (n <= 0)
        return;

    int j;
    if (arr[0])
    {
        arr[0] = false;
        arr[1] = true;

        // double 1 can be at arr[1] arr[2]
        j = 2;
    }
    else{
        arr[0] = true;
        // double 1 can be at arr[0] arr[1]
        j = 1;
        
    }

    while (j < n && arr[j - 1] && arr[j])
    {
        // if there are two 1 side by side, then represent them as 1 on arr[j+1]
        arr[j + 1] = true;
        arr[j - 1] = false;
        arr[j] = false;

        j+=2;
    }
}

int fib(int n)
{
    if (n == 0)
        return 1;
    if (n == 2)
        return 2;
    return fib(n - 2) + fib(n - 1);
}

// int to_dec_from_zeckendorf(int n, bool arr[])
// {
//     int decValue = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i])
//             decValue += fib(i);
//     }
//     return decValue;
// }

int scan_bool(bool *results)
{
    int input;
    int response = scanf("%d", &input);
    if (response)
    {
        *results = (bool)input;
    }
    return response;
}

int main()
{
    int n;
    if (!scanf("%d", &n))
    {
        printf("wrong n");
        return -1;
    }

    bool *arr = (bool *)malloc((size_t)n * sizeof(bool));
    for (int i = 0; i < n; i++)
    {
        if (!scan_bool(&arr[i]))
        {
            printf("wrong bool");
            i--;
        }
    }

    inc(n, arr);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", (int)arr[i]);
    }

    free(arr);
}