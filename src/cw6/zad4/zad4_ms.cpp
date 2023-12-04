#include <iostream>
#include <queue>

using namespace std;

typedef enum pora
{
    Wiosna,
    Lato,
    Jesień,
    Zima
} pora;

pora next_season(pora season)
{
    int v = season + 1;
    return (pora)(v % 4);
}

int pory(int size, pora arr[])
{
    if (size <= 0)
        return -1;
    int shortestLength = -1;

    // take each season as first
    for (int s = 0; s < 4; s++)
    {
        int currentLength = -1;

        // queue which value is awaited
        queue<pora> q;
        q.push((pora)s);
        for (int i = 0; i < 3; i++)
        {
            q.push(next_season(q.back()));
        }
        for (int i = 0; i < size; i++)
        {
            if (q.front() == arr[i])
            {
                if (currentLength == -1)
                {
                    // first hit
                    currentLength = 0;
                }
                // move queue
                q.push(q.front());
                q.pop();

                // if sequence is completed
                if (q.front() == (pora)s)
                {
                    if(shortestLength == -1)
                        shortestLength = currentLength;
                    if(shortestLength < currentLength){
                        shortestLength = currentLength;
                    }
                    currentLength = -1;
                }
            }
            if (currentLength >= 0)
                currentLength++;
        }
    }

    return shortestLength;
}

int main()
{
    int n;
    cin >> n;
    pora *arr = (pora *)malloc((size_t)n * sizeof(pora));
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (input >= 0 && input <= 3)
        {
            arr[i] = (pora)input;
        }
        else
            i --;
        ;
    }

    int w = pory(n, arr);
    cout << w << endl;

    free(arr);
}