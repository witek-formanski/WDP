#include <stdio.h>
#include <stdlib.h>

// O(2^(2k))
// M(k) - nie jestem pewny

int pow2(int k) { return 1 << k; }

void wypelnij_cwiartke(int **m, int k, int x, int y, int przes, int sufiks) {
  if (k == 0) {
    m[x][y] = sufiks;
  } else {
    k--;

    wypelnij_cwiartke(m, k, x, y, przes + 2, sufiks);
    wypelnij_cwiartke(m, k, x + pow2(k), y + pow2(k), przes + 2, (1 << przes) + sufiks);
    wypelnij_cwiartke(m, k, x + pow2(k), y, przes + 2, (2 << przes) + sufiks);
    wypelnij_cwiartke(m, k, x, y + pow2(k), przes + 2, (3 << przes) + sufiks);
  }
}

int **cieniowanie(int k) {
  int **m = (int **)malloc(sizeof(int *) * (size_t)pow2(k));
  for (int i = 0; i < pow2(k); i++)
    m[i] = (int *)malloc(sizeof(int) * (size_t)pow2(k));

  wypelnij_cwiartke(m, k, 0, 0, 0, 0);

  return m;
}

int main() {
  int k;
  scanf("%d", &k);

  int **m = cieniowanie(k);

  for (int y = 0; y < (1 << k); y++) {
    for (int x = 0; x < (1 << k); x++) {
      printf("%d\t", m[x][y]);
    }
    printf("\n");
  }

  return 0;
}