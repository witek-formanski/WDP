#include <stdio.h>
#include <stdlib.h>

// typ ciag (dlugosc oraz wskaznik na tablice zawierajaca elementy)
typedef struct {
   int dl;
   double* el;
} ciag;

// konstruuje ciag roznicowy danego i zwraca adres poczatku
ciag* diffSeq(ciag *s) {
   int n = s->dl;
   ciag* diff = malloc(sizeof(ciag));
   diff->dl = n - 1;
   double* diffEl = malloc((unsigned)(n - 1) * sizeof(double));
   for(int i = n - 2; i >= 0; --i)
      diffEl[i] = (s->el)[i + 1] - (s->el)[i];
   diff->el = diffEl;
   return diff;
}


// typ ciagCiagow: wskaznik na ciag oraz na kolejny ciagCiagow
typedef struct ciagCiag {
   ciag* c;
   struct ciagCiag* nast;
} ciagCiagow;

ciagCiagow* diffSeqs(ciag *s) {
   ciagCiagow* diffs = malloc(sizeof(ciagCiagow));
   diffs->c = s;
   diffs->nast = (s->dl == 1) ? NULL : diffSeqs(diffSeq(s));
   return diffs;
}

int main(void) {

   int n = 5;

   ciag *s = malloc(sizeof(ciag));
   s->dl = 5;
   double *d = malloc(5 * sizeof(double));
   //for(int i = 0; i < n; ++i)
     // d[i] = i + 0.0;
   d[0] = 1.0;
   d[1] = 4.0;
   d[2] = 10.0;
   d[3] = 20.0;
   d[4] = 35.0;

   s->el = d;

   ciag *t = diffSeq(s);
   for(int i = 0; i < n - 1; ++i)
      printf("%f ", (t->el)[i]);
   printf("\n");

   ciagCiagow *ss = diffSeqs(s);
   while (ss) {
      for(int i = 0; i < (ss->c)->dl; i++)
         printf("%f ", (ss->c)->el[i]);
      printf("\n");
      ss = ss->nast;
   }

   free(d);
   free(t);
   free(s);
   free(ss); // to powinno byc madrzejsze (jakas procedura iteracyjnie zwalniaca ss od konca)

   return 0;
}