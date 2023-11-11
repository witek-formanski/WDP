#include <stdio.h>
#include <stdlib.h>

#define x_size 6
#define y_size 4

int orzechy(int a[x_size][y_size], int k) {
  int sumPref[x_size + 1][y_size + 1];

  //Obliczanie sumy prefiksowej
  for (int y = 0; y < y_size + 1; y++) {
    for (int x = 0; x < x_size + 1; x++) {
      if (x == 0 || y == 0) {
        sumPref[x][y] = 0;
      } else {
        sumPref[x][y] = a[x - 1][y - 1] + sumPref[x - 1][y] +
                        sumPref[x][y - 1] - sumPref[x - 1][y - 1];
      }
    }
  }

  int maks = 0;

  //Sprawdzanie wszystkich prostokątów zaczynających się w x i y
  for (int x = 0; x < x_size; x++) {
    for (int y = 0; y < y_size; y++) {
      for (int w = 1; w <= k && x + w <= x_size; w++) {
        if (k % w != 0)
          continue;

        int h = k / w;

        if (y + h > y_size)
          continue;

        int suma = sumPref[x + w][y + h] - sumPref[x][y + h] -
                   sumPref[x + w][y] + sumPref[x][y];

        if (suma > maks)
          maks = suma;
      }
    }
  }

  return maks;
}

int main() {
  int k;
  int t[x_size][y_size];

  for (int y = 0; y < y_size; y++)
    for (int x = 0; x < x_size; x++)
      if(!scanf("%d", &t[x][y])) printf("wrong input");

  if(!scanf("%d", &k)) printf("wrong input");

  printf("%d", orzechy(t, k));
}