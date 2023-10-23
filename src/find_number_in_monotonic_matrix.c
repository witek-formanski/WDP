// zad. 10 zliczanie

// start from lower-left corner
// greater -> move up
// lower -> move right
// equal -> move up and right
int x_size;
int y_size;

int count_occurences(int** t, int v)
{
    int a = 0;
    int b = 0;
    int count = 0;

    while (a < x_size && b < y_size)
    {
        if (t[a][b] == v)
        {
            ++count;
            ++a;
            ++b;
        }
        else if (t[a][b] > v)
            ++b;
        else //if (t[a][b] < v)
            ++a;
    }

    return count;
    
}