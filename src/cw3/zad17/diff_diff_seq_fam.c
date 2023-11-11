#include <stdio.h>
#include <stdlib.h>

//Uses https://en.wikipedia.org/wiki/Flexible_array_member at end of struct
typedef struct ciag {
  int dl;
  struct ciag *next;
  double el[];
} ciag;

ciag *roznicowyRec(ciag *c) {
  c->next = malloc(sizeof(ciag) + (size_t)(c->dl - 1) * sizeof(double));
  c->next->dl = c->dl - 1;
  c->next->next = NULL;

  for (int i = 0; i < c->next->dl; i++)
    c->next->el[i] = c->el[i + 1] - c->el[i];

  if(c->next->dl != 0) roznicowyRec(c->next);

  return c;
}

ciag *readCiag() {
  int dl;
  if(!scanf("%d", &dl)) printf("wrong input");

  ciag *c = malloc(sizeof(ciag) + (size_t)dl * sizeof(double));
  c->dl = dl;
  c->next = NULL;

  for (int i = 0; i < dl; i++)
    if(!scanf("%lf", &(c->el[i]))) printf("wrong input");

  return c;
}

void printCiag(ciag *c) {
  for (int i = 0; i < c->dl; i++)
    printf("%lf ", c->el[i]);

  printf("\n");

  if(c->next != NULL) printCiag(c->next);
}

int main() {
  ciag *c = readCiag();

  printCiag(roznicowyRec(c));
}