#include <stdio.h>
#include <stdlib.h>

// zakladajac, ze tablica t[n] posiada element wystepujacy na wiecej niz polowie pozycji, wskazuje jego wartosc

int leader(int n, int t[]) {

   int candidate = t[0];
   int count = 1;
   for(int i = 1; i < n; ++i) {
      if (count == 0) {
         candidate = t[i];
         ++count;
      }
      else { // count > 0
         if (t[i] == candidate)
            ++count;
         else
            --count;
      }
   }
   return candidate;

}

int main(void) {

   int n;
   scanf("%d",&n);

   int* t = (int*)malloc((unsigned)n * sizeof(int));
   for(int i = 0; i < n; ++i)
      scanf("%d",&t[i]);

   printf("%d",leader(n,t));

   free(t);
   return 0;

}