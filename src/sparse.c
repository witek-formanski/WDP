// autor: Łukasz Bożyk 	[l.bozyk@uw.edu.pl]

#include <stdio.h>

// Dla n >= 0 sprawdza, czy n jest rzadka i jeśli nie,
// zwraca pod adresem &poz indeks prawej jedynki w pierwszym (od lewej) segmencie "11" w zapisie binarnym n
// (zakladamy, ze ostatnia cyfra n ma indeks 0)
int isSparse(int n, int* poz) {
   int s = 1;
   int p = 0;
   int i = 0;
   while (n) {
      if ((n & 3) == 3) {
         s = 0;
         p = i;
      }
      n >>= 1;
      i += 1;
   }
   *poz = p;
   return s;
}

// wyznacza najmniejsza rzadka liczbe wieksza od m
int nextSparse(int n) {
   int m = n + 1;
   int poz = 0;
   if (!isSparse(m, &poz)) {
      int zz = -1;               // indeks prawego zera w pierwszym od prawej segmencie "00"
      int i = 0;
      m >>= poz;
      while (zz < 0 && m) {
         if ((m % 4) == 0)
            zz = i;
         else
            m >>= 1;
         i += 1;
      }
      m += 1;
      m <<= i + poz;
   }
   return m;
}

int main(void) {
   int n;
   scanf("%d", &n);
   printf("%d",nextSparse(n));
   return 0;
}
