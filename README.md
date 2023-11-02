# Wstęp do programowania

WDP\* MIM UW

## Zadania

### Ćwiczenia: [Wstęp](./pdf/WDP_.Inf.23_24Z__Wstęp.pdf) 2023.10.02

- [rectangles_intersection](./src/rectangles_intersection.cpp): prostokąty; rzutowanie na osie (C++) :white_check_mark::microscope:
- [line_segments_intersection](./src/line_segments_intersection.cpp): odcinki; sprawdzanie, z której strony jest punkt (C++) :white_check_mark::microscope:
- [parallelograms_intersection](./src/parallelograms_intersection.cpp): równoległoboki; sprawdzanie punktów wewnątrz i przecinania się przekątnych (C++)
- [point_inside_polygon](./src/point_inside_polygon.cpp): czy punkt leży wewnątrz dowolnego wielokąta

### Ćwiczenia: [Funkcje operujące na liczbach](./pdf/WDP_.Inf.23_24Z__Funkcje_operujące_na_liczbach.pdf) 2023.10.04, 2023.10.09

- [parity_degree](./src/parity_degree.c): [zad. 1.] stopień parzystości (C) :white_check_mark:
- [reverse](./src/reverse.c): [zad. 2.] odwracanie kolejności cyfr w liczbie (C) :white_check_mark:
- [sqrt_floor](./src/sqrt_floor.c): [zad. 3.] podłoga z pierwiastka; suma kolejnych liczb nieparzystych (C) :white_check_mark:
- [zad. 4.] szukanie następnej liczby, która w zapisie binarnym nie ma dwóch jedynek koło siebie
  - [next_sparse_number](./src/next_sparse_number.c) (C)
  - [sparse](./src/sparse.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 5.] zliczanie wszystkich liczb rzadkich mniejszych od danej liczby
  - [count_sparse_numbers_brute](./src/count_sparse_numbers_brute.c) (C):white_check_mark::microscope:
  - [count_sparse_numbers](./src/count_sparse_numbers.c) (C):white_check_mark:
  - [consecutive_ones](./src/consecutive_ones.c) programowanie dynamiczne, GFG (C)
- [is_prime](./src/is_prime.c): [zad. 6.] sprawdzanie czy liczba jest pierwsza (C) :white_check_mark::microscope:
- [encode_in_one_integer](./src/encode_in_one_integer.c): [zad. 7.] kodowanie pary liczb naturalnych jako liczbę naturalną (C)
- [modulo](./src/modulo.c): [zad. 8.] czy pierścień reszt modulo n zawiera nietrywialne pierwiastki z 1 (C) :white_check_mark:
- [count_zeros](./src/count_zeros.c): [zad. 10.] ile jest zer na końcu n! (C)
- [count_ones](./src/count_ones.c): [zad. 12.] ile jest jedynek w zapisie binarnym liczby n (C)

### Laboratorium: [Podzielny fragment ciągu](./pdf/WDP_.Inf.23_24Z__Laboratorium_1__rozgrzewka.pdf) 2023.10.04

- [divisible_sequence](./src/divisible_sequence.c): najdłuższy dzielny fragment ciągu (C) :white_check_mark::microscope:
- [divisible_sequence](./src/divisible_sequence.cpp): najdłuższy dzielny fragment ciągu (C++) :white_check_mark::microscope:

### Ćwiczenia: [Zadania na tablice](./pdf/WDP_.Inf.23_24Z__Zadania_na_tablice.pdf) 2023.10.09, 2023.10.11, 2023.10.16

- [zad. 1.] obrót tablicy
  - [rotate_table](./src/rotate_table.c) (C)
  - [rotate](./src/rotate.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 2.] tasowanie dwóch tablic
  - [shuffle](./src/shuffle.c) (C) :white_check_mark::microscope:
- [zad. 3.] ile różnych liczb występuje w dwóch niemalejących tablicach
  - [nondecreasing_tables](./src/nondecreasing_tables.c) (C)
  - [count_distinct](./src/count_distinct.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 4.] ciąg Bonifacego (podobny do Fibonacciego)
  - [bonifacy](./src/bonifacy.c) (C) :white_check_mark::microscope:
- [zad. 5.] znajdź lidera
  - [find_leader](./src/find_leader.c) (C)
  - [leader](./src/leader.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 6.] podziel std::vector<int> na mniejsze części
  - [split_to_vectors](./src/split_to_vectors.cpp) (C++) :white_check_mark:
- [zad. 7.] fragment tablicy zawierający wszystkie indeksy jego elementów
  - [find_fragments_containing_all_indexes](./src/find_fragments_containing_all_indexes.c) (C)
  - [divide](./src/divide.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 8.] dekompresuj tablicę ciągów skompresowanych 2^(i−1)⋅(2⋅k−1)
  - [decompress.cpp](./src/decompress.cpp) (C++) :white_check_mark::microscope:
  - [compress.cpp](./src/compress.cpp) (C++) :white_check_mark::microscope:
  - [decompress.c](./src/decompress.c) (C)
- [zad. 9.] ile jest trójek spełniających nierówność trójkąta w tablicy
  - [triangle_inequality](./src/triangle_inequality.c) (C)
- [zad. 10.] zabawka Jasia
  - [cylinder_toy](./src/cylinder_toy.c) (C)
  - [toy](./src/toy.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 11.] kodowanie w systemie minus-dwójkowym
  - [minus_2_binary](./src/minus_2_binary.c) (C)
  - [minus2](./src/minus2.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 12.] następna permutacja
  - [lexicographical_order](./src/lexicographical_order.c) (C)
  - [next_perm](./src/next_perm.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 14.] sprawdź, czy jeden ciąg zawiera się w drugim
  - [subsequence](./src/subsequence.c) (C) :white_check_mark::microscope:
- [zad. 16.] ciąg róznicowy
  - [differential_sequence](./src/differential_sequence.c) (C)
  - [diff_seq](./src/diff_seq.c) (C): autor: @lbozyk (C) :white_check_mark:

### Laboratorium: [Gra w skakanie (NWD)](./pdf/WDP_.Inf.23_24Z__Zadanie_rozgrzewkowe_2.pdf) 2023.10.11

- [game.c](./src/game.c): strategia wygrywająca (C) :white_check_mark::microscope:
- [game.h](./src/game.h): prototyp funkcji :white_check_mark::microscope:
- [evaluate_game.c](./src/evaluate_game.c): program grający w grę (C) :white_check_mark::microscope:

### Ćwiczenia: [Złożoność czasowa i pamięciowa](./pdf/WDP_.Inf.23_24Z__Złożoność_czasowa_i_pamięciowa.pdf) 2023.10.18

- [zad. 1.] $n^{3}$
- [zad. 2.] $n^{4}$
- [zad. 3.]
  - $\frac{1}{n^{4}}$
  - $\frac{1}{n^{2}}$
- [zad. 6.] znajdź minimalną liczbę ruchów potrzebnych do uzyskania danej konfiguracji wież Hanoi
  - [hanoi](./src/hanoi.c) (C) :white_check_mark:
  - [print_hanoi](./src/print_hanoi.c) (C)

### Ćwiczenia: [Zliczanie, sumy_prefiksowe, gąsienica, bisekcja](./pdf/WDP_.Inf.23_24Z__Zliczanie,_sumy_prefiksowe,_gąsienica,_bisekcja_.pdf) 2023.10.23, 2023.10.25

- [zad. 2.]
  - [absolute_minimum_of_sequence](./src/absolute_minimum_of_sequence.cpp) (C++)
- [zad. 5.2.]
  - [convex_func_min](./src/convex_func_min.c) (C)
- [zad. 11.]
  - [find_rotated_min](./src/find_rotated_min.c) (C)

### Kolokwium: [I Kolokwium 2022/2023](./pdf/2022_I_Kolokwium.pdf)

- [zad. 1.]
  - [schodki](./src/2022_I_Kolokwium_schodki.c) (C) :white_check_mark:
- [zad. 2.]
  - [cieniowanie](./src/2022_I_Kolokwium_cieniowanie.c) (C) :white_check_mark:

### Inne

- [fibonacci_matrix](./src/fibonacci_matrix.c)
- [fibonacci](./src/fibonacci.c)

## Legenda

:white_check_mark: skończony program (da się go uruchomić)\
:microscope: program przechodzący testy

## Instrukcja korzystania

### Zostań kontrybutorem!

Jeśli rozwiązałeś zadanie innym sposobem, zaimplementowałeś nierozwiązane wcześniej zadanie lub po prostu chcesz się podzielić swoim kodem - nie krępuj się, wrzuć kod na repo. Razem stwórzmy bazę różnych rozwiązań i źródło do nauki dla każdego! Moje rozwiązania często nie są najoptymalniejsze, więc jeśli masz lepszy pomysł na zadanie, twój wkład będzie tym bardziej cenny.

### Gdzie wrzucić kod (i testy)?

Jeżeli już zdecydujesz się podzeilić swoim kodem, umieść go w folderze **src**. Idealnie, gdybyś do kodu dołączył testy - ostatecznie pliki _.IN_ i _.OUT_ powinny się znaleźć w folderze **tests**, w podfolderze odpowiednim dla rozszerzenia, np. **c** lub **cpp**.

### Jak napisać testy?

Jeśli twój program to _power_of_two.c_, to testy powinny nazywać się _power_of_two0.in_, _power_of_two0.out_, _power_of_two1.in_, _power_of_two1.out_... i powinieneś je umieścić w folderze **c**. Oczywiście pliki _.IN_ zawierają input, a pliki _.OUT_ oczekiwany output. Po każdym pushu na branch main testy automatycznie się uruchomią i ich wyniki będziesz mógł zobaczyć w szczegółach odpowiedniej githubowej akcji. Dla kodów w C wszystkie testy odpalają się po skompilowaniu pliku z restykcyjnymi opcjami **configs/options**.

### Generowanie testów z CSV

Jeżeli jesteś leniwy i nie chce ci się dla każdego programu tworzyć ręcznie serii plików, możesz wpisać pary input-output do CSVki. Dla programu _power_of_two.c_ będzie to przykładowo:

```
3,8
11,2048
12,4096
```

Następnie możesz skorzystać ze skryptu **test_generator.py** w folderze **scripts**, aby wygenerować pliki do testowania:

```console
foo@WDP:~$ py scipts/test_generator.py other/power_of_two.csv power_of_two.c

```

### Ręczne konfigurowanie testów

Jeżeli masz bardziej skomplikowany program, który przykładowo wymaga wskazania headera podczas kompilacji, możesz samodzielnie skonfigurować cały proces w **.github/workflows/ci_pipeline.yml**. Najlepiej, jeśli testy wrzucisz wtedy do folderu **tests/manual**.

### Jak korzystać ze skryptów?

Szczególnie jeśli chcesz ręcznie skonfigurować testy, możesz potrzebować skorzystać ze skryptów. Wszystkie znajdują się w folderze **scripts**.\ Skrypt **builder.py** kompiluje kod napisany w C (z restrykcyjnymi opcjami **configs/options**) lub w C++.

```console
foo@WDP:~$ py scipts/builder.py src/power_of_two.c

```

```console
foo@WDP:~$ py scipts/builder.py src/power_of_two.cpp

```

Skrypt **tester.py** uruchamia podaną liczbę testów dla danego pliku. _Uwaga!_ Należy podać numer ostatniego testu (czyli o jeden mniej niż jest testów, bo numerację zaczynamy od zera). Jeżeli chcesz przetestować program _power_of_two_ i mamy testy (pliki .IN i .OUT w folderach odpowiednich dla rozszerzenia) o numerach 0, 1, 2, to napisz:

```console
foo@WDP:~$ py scipts/tester.py src/power_of_two.c 2

```

```console
foo@WDP:~$ py scipts/tester.py src/power_of_two.cpp 2

```

Jeżeli nasz kod wymaga niestandardowej kompilacji i testy do niego znajdują się w folderze **tests/manual**, wtedy napisz:

```console
foo@WDP:~$ py scipts/tester.py src/power_of_two.c 2 manual

```

Skrypt **test_detector.py** służy do automatycznego wykrywania testów i najlepiej zrozumieć jego działanie, zaglądając do **.github/workflows/ci_pipeline.yml**.
