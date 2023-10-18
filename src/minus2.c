#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool neg2_of_int(long long int n, int wynik[], int size) {
   if (!size) { 
      return false;
   }
   if (n == 0) {
      wynik[0] = -1;
      return true;
   }
   if (n > 0) {
      wynik[0] = (int)(n % 2);
      return neg2_of_int(- n / 2, wynik + 1, size - 1);
   }
   else {
      wynik[0] = (int)(-n % 2);
      return neg2_of_int((1 - n) / 2, wynik + 1, size - 1);
   }
}

/*** ponizej okropnie slaba proba zrobienia +1 z uwzglednieniem roznych przypadkow brzegowych ***/



/* przepisuje tablice cyfra[] do tablicy wynik[size]
   zwraca falsz, jesli sie nie miesci */
bool rewrite(int cyfra[], int wynik[], int size) {
   if (size <= 0)
      return false;
   int i = 0;
   while (i < size && cyfra[i] != -1) {
      wynik[i] = cyfra[i];
      ++i;
   }
   if (i < size)
      wynik[i] = -1;
   return (i != size);
}

/* wpisuje zapis (-2)-owy liczby n + 1 na tablice wynik
   zwraca falsz jesli wynik nie zmiescil sie w tablicy */
bool inc(int cyfra[], int wynik[], int size) {

   // nie ma gdzie wpisywac --- zwroc falsz
   if (size <= 0)
      return false;

   // obsluga przypadku gdy cyfra[] przechowuje zero
   if (cyfra[0] == -1) {
      wynik[0] = 1;
      if (size > 1) {
         wynik[1] = -1;
         return true;
      }
      else
         return false;
   }

   // koniec 0 -> dodaj 1
   if (cyfra[0] == 0) {
      wynik[0] = 1;
      // przepisz reszte liczby z cyfra[] do wynik[] (jesli sie miesci)
      return rewrite(cyfra + 1, wynik + 1, size - 1);
   }

   // koniec 11 -> zmien na 00
   if (cyfra[0] == 1 && cyfra[1] == 1) {
      wynik[0] = 0;
      bool b = false;
      if (size > 1)
         wynik[1] = 0;
      b = rewrite(cyfra + 2, wynik - 2, size - 2);
      // obsluga przypadku -1 + 1 =0
      if (wynik[2] == -1) {
         wynik[0] = -1;
         b = size > 0;
      }
      return b;
   }

   // w przec. przyp. (koniec 01) -> zmien na 10 i dodaj 1 do prefiksu kodlugosci 2
   if (cyfra[0] == 1 && cyfra[1] != 1) {
      // tu sie poddalem
      return false;
   }
   return false;
}

/*** do testow ***/

int main(void) {

   long long int n = -10;
   int size = 10;
   int* wynik = malloc((unsigned)n * sizeof(int));

   printf("%d\n", neg2_of_int(n, wynik, size));
   for(int i = 0; (i < size) && (wynik[i] != -1); ++i)
      printf("%d", wynik[i]);
   printf("\n");

   free(wynik);
   return 0;

}