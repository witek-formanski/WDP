#include <stdio.h>
#include <stdlib.h>



void swap(int a[], int i, int j) { // zamienia wartosci a[i] oraz a[j] w tablicy int a[]
   int temp = a[i];
   a[i] = a[j];
   a[j] = temp;
}

void mirror(int a[], int l, int r) { // odbija segment tablicy int a[] od a[l] do a[r] wlacznie
   while (l < r) {
      swap(a, l, r);
      ++l;
      --r;
   }
}

void rotate(int n, int t[], int k) { // przesuwa cyklicznie elementy int t[n] w prawo o k pozycji
   
   k %= n;
   k += n * (k < 0);    // redukcja k do liczby z zakresu 0..n-1
   
   mirror(t, 0, n - k - 1);
   mirror(t, n - k, n - 1);
   mirror(t, 0, n - 1);
}




/**** tu zaczynaja sie rzeczy do testowania ****/


void printArray(int n, int a[]) { // wypisuje tablice a[n]
   for(int i = 0; i < n; ++i)
      printf("%d ", a[i]);
   printf("\n");
}

int* getArray(int* n) { // pobiera najpierw dlugosc tablicy n, a potem tworzy pod adresem a tablice z kolejnymi n wartosciami
   scanf("%d", n);
   int *a = (int*)malloc((unsigned)*n * sizeof(int));
   for(int i = 0; i < *n; ++i)
      scanf("%d", &a[i]);
   return a;
}

int main(void) {

   int n;
   int* a = getArray(&n);
   int k;
   scanf("%d", &k);
   printf("\n");

   printArray(n, a);
   rotate(n, a, k);
   printArray(n, a);

   free(a);
   return 0;
}