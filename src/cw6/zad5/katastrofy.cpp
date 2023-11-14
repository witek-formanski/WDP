#include <iostream>
#include <stack>

/*

5               #
4 #       #     #
3 #   #   #     # #
2 # # #   #   # # # # #
1 # # # # # # # # # # #
x 0 1 2 3 4 5 6 7 8 9 10

Iterujemy się po tablicy, w każdym kroku usuwamy ze stosu elementy niższe od
i-tego, zapisujemy w wyniku odległość i-tego do tego który pozostał na górze
stosu, a potem wrzucamy i-ty element na stos.
*/

int *katastrofy(int n, int t[]) {
  std::stack<int> indeksy;
  int *wynik = (int *)malloc((size_t)n * sizeof(int));

  indeksy.push(-1);

  for (int i = 0; i < n; i++) {
    while (indeksy.top() != -1 && t[indeksy.top()] <= t[i])
      indeksy.pop();

    wynik[i] = i - indeksy.top();

    indeksy.push(i);
  }

  return wynik;
}

void readIntArray(int *n, int *t[]) {
  if (!scanf("%d", n))
    printf("invalid n provided\n");

  *t = (int *)malloc((size_t)*n * sizeof(int));

  for (int i = 0; i < *n; i++)
    if (!scanf("%d", *t + i))
      printf("invalid value\n");
}

void printIntArray(int n, int t[]) {
  for (int i = 0; i < n; i++)
    printf("%d ", t[i]);
}

int main() {
  int n, *t;

  readIntArray(&n, &t);
  printIntArray(n, katastrofy(n, t));
}