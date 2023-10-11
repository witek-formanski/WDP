// zad. 7 tablice

/*
divide table into fragments conatining all indexes
{0, 2, 1, 5, 4, 3, 6, 10, 8, 9, 7, 12, 11} -> {0, 2, 5, 6, 10, 12}
*/

int* find_fragments_containing_all_indexes(int n, int t[])
{
    int* result = (int*)malloc((unsigned)n * sizeof(int));
    int maxNum = -1;
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        if (t[i] > maxNum)
        {
            maxNum = t[i];
        }
        if (maxNum == i)
        {
            result[count++] = i;
        }
    }

    return result;
}

// implementacja Bożyka: skaczemy po indeksach
// żeby sprawdzić, czy odwiedziliśmy już dany element tablicy, możemy odjąć od niego n

// rozkład permutacji na cykle