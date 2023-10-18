#include <stdio.h>
#include <stdlib.h>

// rurka[0] to srednica otworu tuz przy dnie rurki
// krazki[0] to srednica krazka wrzuconego najpierw
int wrzucaj(int n_rurka, int rurka[], int n_krazki, int krazki[]) {
   if (!n_rurka || !n_krazki)
      return 0;
   int szerokosc = rurka[n_rurka - 1];
   // swiecimy do rurki od gory i zmieniamy szerokosc na oswietlona
   for(int i = n_rurka - 1; i >= 0; --i) {
      if (rurka[i] > szerokosc)
         rurka[i] = szerokosc;
      else
         szerokosc = rurka[i];
   }
   int k = 0;  // ile krazkow juz sie zmiescilo
   for(int i = 0; (i < n_rurka && k < n_krazki); ++i) {
      if (krazki[k] <= rurka[i])
         ++k;
   }
   return k;
}

/** do testow **/

int main(void) {
   int r[10] = {1, 4, 3, 2, 5, 6, 7, 5, 7, 6};
   int k[8] = {1, 2, 2, 2, 5, 2, 6, 1};
   printf("%d\n", wrzucaj(10, r, 8, k));
   return 0;
}