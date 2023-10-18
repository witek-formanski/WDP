# WDP
## Ćwiczenia: [Wstęp](./pdf/WDP_.Inf.23_24Z__Wstęp.pdf) 2023.10.02
* [rectangles_intersection](./src/rectangles_intersection.cpp): prostokąty; rzutowanie na osie (C++) :white_check_mark::microscope:
* [line_segments_intersection](./src/line_segments_intersection.cpp): odcinki; sprawdzanie, z której strony jest punkt (C++) :white_check_mark::microscope:
* [parallelograms_intersection](./src/parallelograms_intersection.cpp): równoległoboki; sprawdzanie punktów wewnątrz i przecinania się przekątnych (C++)
* [point_inside_polygon](./src/point_inside_polygon.cpp): czy punkt leży wewnątrz dowolnego wielokąta
## Ćwiczenia: [Funkcje operujące na liczbach](./pdf/WDP_.Inf.23_24Z__Funkcje_operujące_na_liczbach.pdf) 2023.10.04, 2023.10.09
* [parity_degree](./src/parity_degree.c): [zad. 1] stopień parzystości (C) :white_check_mark:
* [reverse](./src/reverse.c): [zad. 2] odwracanie kolejności cyfr w liczbie (C) :white_check_mark:
* [sqrt_floor](./src/sqrt_floor.c): [zad. 3] podłoga z pierwiastka; suma kolejnych liczb nieparzystych (C) :white_check_mark:
* [zad. 4.] szukanie następnej liczby, która w zapisie binarnym nie ma dwóch jedynek koło siebie
    * [next_sparse_number](./src/next_sparse_number.c) (C)
    * [sparse](./src/sparse.c): autor: @lbozyk (C) :white_check_mark:
* [encode_in_one_integer](./src/encode_in_one_integer.c): [zad. 7] kodowanie pary liczb naturalnych jako liczbę naturalną (C)
* [modulo](./src/modulo.c): [zad. 8] czy pierścień reszt modulo n zawiera nietrywialne pierwiastki z 1 (C) :white_check_mark:
* [count_zeros](./src/count_zeros.c): [zad. 10] ile jest zer na końcu n! (C)
* [count_ones](./src/count_ones.c): [zad. 12] ile jest jedynek w zapisie binarnym liczby n (C)
## Laboratorium: [Podzielny fragment ciągu](./pdf/WDP_.Inf.23_24Z__Laboratorium_1__rozgrzewka.pdf) 2023.10.04
* [divisible_sequence](./src/divisible_sequence.c): najdłuższy dzielny fragment ciągu (C) :white_check_mark::microscope:
* [divisible_sequence](./src/divisible_sequence.cpp): najdłuższy dzielny fragment ciągu (C++) :white_check_mark::microscope:
## Ćwiczenia: [Zadania na tablice](./pdf/WDP_.Inf.23_24Z__Zadania_na_tablice.pdf) 2023.10.09, 2023.10.11, 2023.10.16
* [zad. 1.] obrót tablicy
    * [rotate_table](./src/rotate_table.c) (C)
    * [rotate](./src/rotate.c): autor: @lbozyk (C) :white_check_mark:
* [zad. 2.] tasowanie dwóch tablic
* [zad. 3.] ile różnych liczb występuje w dwóch niemalejących tablicach
    * [nondecreasing_tables](.src/nondecreasing_tables.c) (C)
    * [count_distinct](.src/count_distinct.c): autor: @lbozyk (C) :white_check_mark:
* [zad. 5.] znajdź lidera
    * [find_leader](./src/find_leader.c) (C)
    * [leader](./src/leader.c): autor: @lbozyk (C) :white_check_mark:
* [zad. 7.] fragment tablicy zawierający wszystkie indeksy jego elementów
    * [find_fragments_containing_all_indexes](./src/find_fragments_containing_all_indexes.c) (C)
    * [divide](./src/divide.c): autor: @lbozyk (C) :white_check_mark:
* [zad. 10.] zabawka Jasia
    * [cylinder_toy](./src/cylinder_toy.c) (C)
    * [toy](./src/toy.c): autor: @lbozyk (C) :white_check_mark:
* [zad. 11.] kodowanie w systemie minus-dwójkowym
    * [minus_2_binary](./src/minus_2_binary.c) (C)
    * [minus2](./src/minus2.c): autor: @lbozyk (C) :white_check_mark:
* [zad. 12.] następna permutacja
    * [lexicographical_order](./src/lexicographical_order.c) (C)
    * [next_perm](./src/next_perm.c): autor: @lbozyk (C) :white_check_mark:
* [zad. 16.] ciąg róznicowy
    * [differential_sequence](./src/differential_sequence.c) (C)
    * [diff_seq](./src/diff_seq.c) (C): autor: @lbozyk (C) :white_check_mark:
## Laboratorium: [Gra w skakanie (NWD)](./pdf/WDP_.Inf.23_24Z__Zadanie_rozgrzewkowe_2.pdf) 2023.10.11
* [game.c](./src/game.c): strategia wygrywająca (C) :white_check_mark::microscope:
* [game.h](./src/game.h): prototyp funkcji :white_check_mark::microscope:
* [evaluate_game.c](./src/evaluate_game.c): program grający w grę (C) :white_check_mark::microscope:
## Ćwiczenia: [Zadania na tablice](./pdf/WDP_.Inf.23_24Z__Złożoność_czasowa_i_pamięciowa.pdf) 2023.10.18
* [zad. 1.] n^3
* [zad. 2.] n^4
* [zad. 3.]
    * 1/n^4
    * 1/n^2
* [zad. 6.] znajdź minimalną liczbę ruchów potrzebnych do uzyskania danej konfiguracji wież Hanoi
    * [hanoi](./src/hanoi.c) (C)
