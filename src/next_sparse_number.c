// zad. 4
// may be useful xd: https://en.wikipedia.org/wiki/Fast_inverse_square_root

int next_sparse_number(int n)
{
    int backup = n+1;
    int k = backup;
    int position = 0;
    int i = 1;

    while(k) // szukamy pierwszego wystąpienia 11 od lewej
    {
        if (k&3 == 3)
        {
            position = i;
        }

        k >>= 1;
        ++i;
    }

    k = backup;

    k >>= position + 1;
    k += 1;
    i = 0;

    while (k) // 
    {
        if (k % 4 == 0)
        {
            // stop
        }
    }
    
    k >> 1;

    
}

/*
algorytm
1. mamy liczbę n
2. dodajemy do niej 1 (szukamy większej rzadkiej liczby)
3. szukamy pierwszego "11" od lewej i zapisujemy tę pozycję jako position
4. szukamy "00" na lewo od "11", ale najbardziej po prawej
5. wstawiamy 1 zamiast drugiego 0 (00 -> 01) i zerujemy wszystkie bity do końca
*/