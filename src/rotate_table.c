// zad. 1 tablice

// b[(i +k) mod n] = a[i]

// NWW(n,k) / k

// a * b = NWD(a,b) * NWW(a,b)

void rotate(int n, int t[], int k)
{
    k %= n;
    k += (k < 0) * n; // if (k < 0) k += n;

    int temp, next, aux;

    for (int i = 0; i < nwd(n, k); ++i)
    {
        temp = t[i];
        for (int j = 0; j < n / nwd(n, k); ++j)
        {
            next = (i + (j + 1) * k) % n;
            aux = t[next];
            t[next] = temp;
            temp = aux;
        }
    }
}

////////////////////////////////////////////////////////////////

void swap(int t[], int i, int j)
{
    int temp = t[i];
    t[i] = t[j];
    t[j] = temp;
}

void mirror(int t[], int left, int right)
{
    while (left < right)
    {
        swap(t, left, right);
        ++left;
        --right;
    }
}

void rotate_lbozyk(int n, int t[], int k)
{
    k %= n;
    if (k < 0)
        k += n;
    mirror(t, 0, n - k - 1);
    mirror(t, n - k, n - 1);
    mirror(t, 0, n - 1);
}