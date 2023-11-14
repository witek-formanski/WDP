#include <stdio.h>
#include <stdlib.h>

//Uses https://en.wikipedia.org/wiki/Flexible_array_member at end of struct
typedef struct {
  int dl;
  double el[];
} ciag;

ciag *roznicowy(ciag *c) {
  ciag *r = malloc(sizeof(ciag) + (size_t)(c->dl - 1) * sizeof(double));
  r->dl = c->dl - 1;

  for (int i = 0; i < r->dl; i++)
    r->el[i] = c->el[i + 1] - c->el[i];

  return r;
}

ciag *readCiag() {
  int dl;
  if(!scanf("%d", &dl)) printf("wrong input");

  ciag *c = malloc(sizeof(ciag) + (size_t)dl * sizeof(double));
  c->dl = dl;

  for (int i = 0; i < dl; i++)
    if(!scanf("%lf", &(c->el[i]))) printf("wrong input");

  return c;
}

void printCiag(ciag *c) {
  for (int i = 0; i < c->dl; i++)
    printf("%lf ", c->el[i]);
}

int main() {
  ciag *c = readCiag();

  printCiag(roznicowy(c));
}