#include <stdio.h>
#include <stdlib.h>

// O(n)
// M(n)

int schodki(int n, int t[]) {
  int *pom = (int*)malloc((size_t)(n+1)*sizeof(int));
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
  if(!scanf(("%d", n))) printf("wrong input");

  *t = (int*)malloc((size_t)*n * sizeof(int));
  for (int i = 0; i < *n; i++)
    if(!scanf(("%d", *t + i))) printf("wrong input");
}

int main() {
  // int n, *t;

  int n = 10;
  int t[10] = {3, 0, 1, 6, 2, 3, 4, 4, 5, 6};

  // readIntArray(&n, &t);

  printf("%d", schodki(n,t)); // should be 3, currently: 1
}