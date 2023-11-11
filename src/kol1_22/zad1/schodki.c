#include <stdio.h>
#include <stdlib.h>

// O(n)
// M(n)

int schodki(int n, int t[]) {
  int *pom = (int*)calloc((size_t)(n+1), sizeof(int));
  int ile = 0; 

  for(int i=0; i<n; i++) {
    if(t[i] == 0 || pom[t[i]-1] == 0) {
      pom[t[i]]++;
      ile++;
    } else {
      pom[t[i]-1]--;
      pom[t[i]]++;
    }
  }

  return ile;
}

void readIntArray(int *n, int *t[]) {
  if (!scanf("%d", n)) printf("invalid n provided\n");
  
  *t = (int*)malloc((size_t)*n * sizeof(int));

  for (int i = 0; i < *n; i++)
    if (!scanf("%d", *t + i)) printf("invalid n provided\n");
}

int main() {
  int n, *t;

  readIntArray(&n, &t);

  printf("%d", schodki(n,t));
}