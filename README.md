# Wstęp do programowania

_WDP\* MIM UW_

## _Zadania_

## Ćwiczenia

### Ćwiczenia I: [Wstęp](./pdf/WDP_.Inf.23_24Z__Wstęp.pdf) 2023.10.02

- [rectangles_intersection](./src/cw1/zad1/rectangles_intersection.cpp): [zad. 1.] prostokąty; rzutowanie na osie (C++) :white_check_mark::microscope:
- [line_segments_intersection](./src/cw1/zad2/line_segments_intersection.cpp): [zad. 2.] odcinki; sprawdzanie, z której strony jest punkt (C++) :white_check_mark::microscope:
- [parallelograms_intersection](./src/cw1/zad3/parallelograms_intersection.cpp): [zad. 3.] równoległoboki; sprawdzanie punktów wewnątrz i przecinania się przekątnych (C++)
- [point_inside_polygon](./src/cw1/zad4/point_inside_polygon.cpp): [zad. 4.] czy punkt leży wewnątrz dowolnego wielokąta

### Ćwiczenia II: [Funkcje operujące na liczbach](./pdf/WDP_.Inf.23_24Z__Funkcje_operujące_na_liczbach.pdf) 2023.10.04, 2023.10.09

- [parity_degree](./src/cw2/zad1/parity_degree.c): [zad. 1.] stopień parzystości (C) :white_check_mark:
- [reverse](./src/cw2/zad2/reverse.c): [zad. 2.] odwracanie kolejności cyfr w liczbie (C) :white_check_mark:
- [sqrt_floor](./src/cw2/zad3/sqrt_floor.c): [zad. 3.] podłoga z pierwiastka; suma kolejnych liczb nieparzystych (C) :white_check_mark:
- [zad. 4.] szukanie następnej liczby, która w zapisie binarnym nie ma dwóch jedynek koło siebie
  - [next_sparse_number](./src/cw2/zad4/next_sparse_number.c) (C)
  - [sparse](./src/cw2/zad4/sparse.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 5.] zliczanie wszystkich liczb rzadkich mniejszych od danej liczby
  - [count_sparse_numbers_brute](./src/cw2/zad5/count_sparse_numbers_brute.c) (C) :white_check_mark::microscope:
  - [count_sparse_numbers](./src/cw2/zad5/count_sparse_numbers.c) (C) :white_check_mark:
  - [consecutive_ones](./src/cw2/zad5/consecutive_ones.c) programowanie dynamiczne, GFG (C)
- [is_prime](./src/cw2/zad6/is_prime.c): [zad. 6.] sprawdzanie czy liczba jest pierwsza (C) :white_check_mark::microscope:
- [encode_in_one_integer](./src/cw2/zad7/encode_in_one_integer.c): [zad. 7.] kodowanie pary liczb naturalnych jako liczbę naturalną (C)
- [modulo](./src/cw2/zad8/modulo.c): [zad. 8.] czy pierścień reszt modulo n zawiera nietrywialne pierwiastki z 1 (C) :white_check_mark:
- [count_zeros](./src/cw2/zad10/count_zeros.c): [zad. 10.] ile jest zer na końcu n! (C)
- [count_ones](./src/cw2/zad12/count_ones.c): [zad. 12.] ile jest jedynek w zapisie binarnym liczby n (C)

### Ćwiczenia III: [Zadania na tablice](./pdf/WDP_.Inf.23_24Z__Zadania_na_tablice.pdf) 2023.10.09, 2023.10.11, 2023.10.16

- [zad. 1.] obrót tablicy
  - [rotate_table](./src/cw3/zad1/rotate_table.c) (C)
  - [rotate](./src/cw3/zad1/rotate.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 2.] tasowanie dwóch tablic
  - [shuffle](./src/cw3/zad2/shuffle.c) (C) :white_check_mark::microscope:
- [zad. 3.] ile różnych liczb występuje w dwóch niemalejących tablicach
  - [nondecreasing_tables](./src/cw3/zad3/nondecreasing_tables.c) (C)
  - [count_distinct](./src/cw3/zad3/count_distinct.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 4.] ciąg Bonifacego (podobny do Fibonacciego)
  - [bonifacy](./src/cw3/zad4/bonifacy.c) (C) :white_check_mark::microscope:
- [zad. 5.] znajdź lidera
  - [find_leader](./src/cw3/zad5/find_leader.c) (C)
  - [leader](./src/cw3/zad5/leader.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 6.] podziel std::vector<int> na mniejsze części
  - [split_to_vectors](./src/cw3/zad6/split_to_vectors.cpp) (C++) :white_check_mark:
- [zad. 7.] fragment tablicy zawierający wszystkie indeksy jego elementów
  - [find_fragments_containing_all_indexes](./src/cw3/zad7/find_fragments_containing_all_indexes.c) (C)
  - [divide](./src/cw3/zad7/divide.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 8.] dekompresuj tablicę ciągów skompresowanych 2^(i−1)⋅(2⋅k−1)
  - [decompress.cpp](./src/cw3/zad8/decompress.cpp) (C++) :white_check_mark::microscope:
  - [compress.cpp](./src/cw3/zad8/compress.cpp) (C++) :white_check_mark::microscope:
  - [decompress.c](./src/cw3/zad8/decompress.c) (C)
- [zad. 9.] ile jest trójek spełniających nierówność trójkąta w tablicy
  - [triangle_inequality](./src/cw3/zad9/triangle_inequality.c) (C)
- [zad. 10.] zabawka Jasia
  - [cylinder_toy](./src/cw3/zad10/cylinder_toy.c) (C)
  - [toy](./src/cw3/zad10/toy.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 11.] kodowanie w systemie minus-dwójkowym
  - [minus_2_binary](./src/cw3/zad11/minus_2_binary.c) (C)
  - [minus2](./src/cw3/zad11/minus2.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 12.] następna permutacja
  - [lexicographical_order](./src/cw3/zad12/lexicographical_order.c) (C)
  - [next_perm](./src/cw3/zad12/next_perm.c): autor: @lbozyk (C) :white_check_mark:
- [zad. 14.] sprawdź, czy jeden ciąg zawiera się w drugim
  - [subsequence](./src/cw3/zad14/subsequence.c) (C) :white_check_mark::microscope:
- [zad. 16.] ciąg różnicowy
  - [differential_sequence](./src/cw3/zad16/differential_sequence.c) (C)
  - [diff_seq](./src/cw3/zad16/diff_seq.c) (C): autor: @lbozyk (C) :white_check_mark:
  - [diff_seq_fam](./src/cw3/zad16/diff_seq_fam.c) (C) :white_check_mark::microscope:
- [zad. 17.] ciąg ciągu różnicowego
  - [diff_diff_seq_fam](./src/cw3/zad17/diff_diff_seq_fam.c) (C) :white_check_mark::microscope:


### Ćwiczenia IV: [Złożoność czasowa i pamięciowa](./pdf/WDP_.Inf.23_24Z__Złożoność_czasowa_i_pamięciowa.pdf) 2023.10.18

- [zad. 1.] $n^{3}$
- [zad. 2.] $n^{4}$
- [zad. 3.]
  - $\frac{1}{n^{4}}$
  - $\frac{1}{n^{2}}$
- [zad. 6.] znajdź minimalną liczbę ruchów potrzebnych do uzyskania danej konfiguracji wież Hanoi
  - [hanoi](./src/cw4/zad6_1/hanoi.c) (C) :white_check_mark:
  - [print_hanoi](./src/cw4/zad6_2/print_hanoi.c) (C)

### Ćwiczenia V: [Zliczanie, sumy_prefiksowe, gąsienica, bisekcja](./pdf/WDP_.Inf.23_24Z__Zliczanie,_sumy_prefiksowe,_gąsienica,_bisekcja_.pdf) 2023.10.23, 2023.10.25, 2023.11.06

- [zad. 1.]
  - [sum_table_brute](./src/cw5/zad1/sum_table_brute.c) (C) :white_check_mark:
  - [zad_1](./src/cw5/zad1/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 2.]
  - [absolute_minimum_of_sequence](./src/cw5/zad2/absolute_minimum_of_sequence.cpp) (C++)
  - [zad_2](./src/cw5/zad2/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
  - [zad2](./src/cw5/zad2/zad2_pxl.c): autor: @pixelkubek (C) :white_check_mark::microscope:
- [zad. 3.]
  - [minimal_sum_of_two_elements](./src/cw5/zad3/minimal_sum_of_two_elements.c) (C) :white_check_mark:
  - [minimal_sum_of_two_elements_brute](./src/cw5/zad3/minimal_sum_of_two_elements_brute.c) (C) :white_check_mark:
  - [zad_3](./src/cw5/zad3/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 4.]
  - [fit](./src/cw5/zad4/zad_ms.c) (C)
  - [zad_4](./src/cw5/zad4/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 5.2.]
  - [convex_func_min](./src/cw5/zad5_2/convex_func_min.c) (C)
  - [zad_5_2](./src/cw5/zad5_2/zad5_2_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 6.]
  - [diagonal](./src/cw5/zad6/diagonal.c) (C)
- [zad. 7.]
  - [zad_7](./src/cw5/zad7/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
  - [zad7](./src/cw5/zad7/zad7.c): autor: @pixelkubek (C) :white_check_mark:
- [zad. 8.]
  - [find_duplicate](./src/cw5/zad8/find_duplicate.c) (C)
  - [zad_8](./src/cw5/zad8/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 10.]
  - [find_number_in_monotonic_matrix](./src/cw5/zad10/find_number_in_monotonic_matrix.c) (C)
  - [zad_10](./src/cw5/zad10/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 11.]
  - [find_rotated_min](./src/cw5/zad11/find_rotated_min.c) (C)
  - [zad_11](./src/cw5/zad11/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 12.]
  - [zad_12](./src/cw5/zad12/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 14.]
  - [farthest_pair](./src/cw5/zad14/farthest_pair.c) (C)
  - [daleko](./src/cw5/zad14/daleko_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
- [zad. 15.]
  - [zad_15](./src/cw5/zad15/zad_ms.c): autor: @MrD4rkne (C) :white_check_mark::microscope:
  - [zad15](./src/cw5/zad15/zad15.c): autor: @pixelkubek (C) :white_check_mark:
- [zad. 17.]
  - [orzechy](./src/cw5/zad17/orzechy.c) (C) :white_check_mark::microscope:
- [zad. 18.]
  - [zad18](./src/cw5/zad18/zad18.c): autor: @pixelkubek (C) :white_check_mark:

### Ćwiczenia VI: [Stosy, kolejki i koszt zamortyzowany](./pdf/WDP_.Inf.23_24Z__Stosy,_kolejki_i_koszt_zamortyzowany.pdf) 2023.11.13

- [zad. 2.]
  - [lifo_stack](./src/cw6/zad2/lifo_stack.cpp) (C++)
- [zad. 3.]
  - [pond](./src/cw6/zad3/pond.cpp) (C++)
  - [sadzawka](./src/cw6/zad3/sadzawka.cpp): auto: @lbozyk (C++)
  - [zad_3](./src/cw6/zad3/zad3_sadzawka.cpp): autor: @pixelkubek (C++) :white_check_mark:
  - [zad3_ms](./src/cw6/zad3/zad3_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 4.]
  - [zad_4](./src/cw6/zad4/zad4.cpp): autor: @pixelkubek (C++) :x:
  - [zad_4](./src/cw6/zad4/zad4_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 5.]
  - [katastrofy](./src/cw6/zad5/katastrofy.cpp) (C++) :white_check_mark::microscope:
  - [wtc_ms](./src/cw6/zad5/wtc_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 6.]
  - [zad_6](./src/cw6/zad6/zad6.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 7.]
  - [scyscrapers_rectangle_field](./src/cw6/zad7/scyscrapers_rectangle_field.cpp) (C++)
  - [zad_7](./src/cw6/zad7/zad7_skyline.cpp): autor: @pixelkubek (C++) :white_check_mark:
  - [zad7_ms](./src/cw6/zad7/zad7_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 8.]
  - [zad_8](./src/cw6/zad8/zad8.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 9.]
  - [zad_9](./src/cw6/zad9/zad9_Zeckendorf.c): autor: @pixelkubek (C) :white_check_mark:
  - [zad9_ms](./src/cw6/zad9/zad9_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 10.]
  - [zad_10](./src/cw6/zad10/zad10.cpp): autor: @pixelkubek (C++) :white_check_mark:
  - [zad_10_ms](./src/cw6/zad10/zad10_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 11.]
  - [zad_11](./src/cw6/zad11/zad11.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 12.]
  - [fibonacci_word](./src/cw6/zad12/fibonacci_word.cpp) (C++)
  - [slowa](./src/cw6/zad12/slowa.cpp): autor: @MrD4rkne (C++)
  - [zad_12](./src/cw6/zad12/zad12.cpp): autor: @pixelkubek (C++) :white_check_mark:

### Ćwiczenia VII: [Zastosowanie sortowania](WDP_.Inf.23_24Z__Zastosowanie_sortowania.pdf)

- [zad. 1.]
  - [bars](./src/cw7/zad1/bars.cpp) (C++)
  - [bars_linear](./src/cw7/zad1/bars_linear.cpp) (C++)
  - [median_of_medians](./src/cw7/zad1/median_of_medians.cpp) (C++)
  - [zad1_ms](./src/cw7/zad1/zad1_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad1_jc](./src/cw7/zad1/zad1jc.cpp): autor: @pixelkubek (C++)
- [zad. 2.]
  - [contains_triangle](./src/cw7/zad2/contains_triangle.cpp) (C++)
  - [zad2_ms](./src/cw7/zad2/zad2_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad2_jc](./src/cw7/zad2/zad2jc.cpp): autor: @pixelkubek (C++)
- [zad. 3.]
  - [zad3_jc](./src/cw7/zad3/zad3jc.cpp): autor: @pixelkubek (C++)
  - [zad3_ms](./src/cw7/zad3/zad3_ms_.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 4.]
  - [max_combined_diff](./src/cw7/zad4/max_combined_diff.cpp) (C++)
  - [zad4_ms](./src/cw7/zad4/zad4_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad4_jc](./src/cw7/zad4/zad4jc.cpp): autor: @pixelkubek (C++)
- [zad. 5.]
  - [beakers](./src/cw7/zad5/beakers.cpp) (C++)
  - [zad5_ms](./src/cw7/zad5/zad5_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad5_jc](./src/cw7/zad5/zad5jc.cpp): autor: @pixelkubek (C++)
- [zad. 6.]
  - [rejs](./src/cw7/zad6/rejs.cpp) (C++)
  - [zad6_ms](./src/cw7/zad6/zad6_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad6_jc](./src/cw7/zad6/zad6jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 7.]
  - [zad_7](./src/cw7/zad7/zad7jc.cpp): pomysl: @lbozyk, autor: @pixelkubek :white_check_mark:

### Ćwiczenia VIII: [Listy i drzewa](WDP_.Inf.23_24Z__Listy_i_drzewa.pdf) 2023.11.29

- [zad. 1.]
  - [zad1_ms](./src/cw8/zad1/zad1_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad1_jc](./src/cw8/zad1/zad1jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 2.]
  - [zad2_jc](./src/cw8/zad2/zad2jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 3.]
  - [concatenate_lists](./src/cw8/zad3/concatenate_lists.c) (C)
  - [zad3_ms](./src/cw8/zad3/zad3_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:  
  - [zad3_jc](./src/cw8/zad3/zad3jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 5.]
  - [common_suffix_hourglass](./src/cw8/zad5/common_suffix_hourglass.c) (C)
  - [common_suffix_len](./src/cw8/zad5/common_suffix_len.c) (C)
  - [zad5_ms](./src/cw8/zad5/zad5_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad5_jc](./src/cw8/zad5/zad5jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 6.]
  - [find_cycle_reverse_copy](./src/cw8/zad6/find_cycle_reverse_copy.cpp) (C++)
  - [find_cycle_reverse_sum](./src/cw8/zad6/find_cycle_reverse_sum.cpp) (C++)
  - [find_cycle_runners](./src/cw8/zad6/find_cycle_reverse.cpp) (C++)
  - [zad6_jc](./src/cw8/zad6/zad6jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 7.]
  - [general_tree](./src/cw8/zad7/general_tree.c) (C)
  - [zad7_ms](./src/cw8/zad7/zad7_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad7_jc](./src/cw8/zad7/zad7jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 8.]
  - [jump_traversal](./src/cw8/zad8/jump_traversal.c) (C)
  - [zad8_ms](./src/cw8/zad8/zad8_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
  - [zad8_jc](./src/cw8/zad8/zad8jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 10.]
  - [is_ultraleftist](./src/cw8/zad10/is_ultraleftist.c) (C)
  - [zad10_ms](./src/cw8/zad10/zad10_ms.c): autor: @MrD4rkne (C) :white_check_mark:
- [zad. 11.]
  - [zad11_jc](./src/cw8/zad11/zad11jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
  - [zad11_ms](./src/cw8/zad11/zad11_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 12.]
  - [cut_tree_into_two](./src/cw8/zad12/cut_tree_into_two.c) (C)
  - [zad12_ms](./src/cw8/zad12/zad12_ms.c): autor: @MrD4rkne (C) :white_check_mark:
- [zad. 13.]
  - [zad13_jc](./src/cw8/zad13/zad13jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
  - [zad13_ms](./src/cw8/zad13/zad13_ms.cpp): autor: @MrD4rkne (C) :white_check_mark:
- [zad. 14.]
  - [zad14_jc](./src/cw8/zad14/zad14jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 15.]
  - [zad15_jc](./src/cw8/zad15/zad15jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
- [zad. 16.]
  - [](./src/cw8/zad16/middle.c) (C)
  - [zad16_jc](./src/cw8/zad16/zad16jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
  - [zad16_ms](./src/cw8/zad16/zad16j_mscpp): autor: @MrD4rkne (C) :white_check_mark:
- [zad. 17.]
  - [zad17_jc](./src/cw8/zad17/zad17jc.cpp): autor: @pixelkubek (C++) :white_check_mark:

## Laboratoria

### Laboratorium I: [Podzielny fragment ciągu](./pdf/WDP_.Inf.23_24Z__Laboratorium_1__rozgrzewka.pdf) 2023.10.04

- [divisible_sequence](./src/lab1/divisible_sequence.c): najdłuższy dzielny fragment ciągu (C) :white_check_mark::microscope:
- [divisible_sequence](./src/lab1/divisible_sequence.cpp): najdłuższy dzielny fragment ciągu (C++) :white_check_mark::microscope:

### Laboratorium II: [Gra w skakanie (NWD)](./pdf/WDP_.Inf.23_24Z__Zadanie_rozgrzewkowe_2.pdf) 2023.10.11

- [game.c](./src/lab2/game.c): strategia wygrywająca (C) :white_check_mark::microscope:
- [game.h](./src/lab2/game.h): prototyp funkcji :white_check_mark::microscope:
- [evaluate_game.c](./src/lab2/evaluate_game.c): program grający w grę (C) :white_check_mark::microscope:

## Zadania zaliczeniowe z laboratoriów

_wkrótce_

## Kolokwia

### [Kolokwium I 2022/2023](./pdf/2022_I_Kolokwium.pdf)

- [zad. 1.]
  - [schodki](./src/kol1_22/zad1/schodki.c): autor: @stopnoanime (C) :white_check_mark::microscope:
  - [count_stepped_sequences](./src/kol1_22/zad1/count_stepped_sequences.c) (C) :white_check_mark::microscope:
- [zad. 2.]
  - [cieniowanie](./src/kol1_22/zad2/cieniowanie.c): autor: @stopnoanime (C) :white_check_mark:
  - [shading_matrix](./src/kol1_22/zad2/shading_matrix.c) (C) :white_check_mark:

### [Kolokwium II 2022/2023](./pdf/2022_II_Kolokwium.pdf)

- [zad. 1.]
  - [zad1_jc](./src/kol2_22/zad1jc.cpp): autor: @pixelkubek (C++) :white_check_mark:
  - [zad1_ms](./src/kol2_22/zad1_ms.cpp): autor: @MrD4rkne (C++) :white_check_mark:
- [zad. 2.]
  - [zad2_jc](./src/kol2_22/zad2jc.cpp): autor: @pixelkubek (C++)
  - [zad2_ms](./src/kol2_22/zad2_ms.cpp): autor: @MrD4rkne (C) :white_check_mark:

### [Kolokwium III 2022/2023](./pdf/2022_III_Kolokwium.pdf)

- [zad. 1.]
- [zad. 2.]

### Inne

- [fibonacci_matrix](./src/other/fibonacci_matrix.c)
- [fibonacci](./src/other/fibonacci.c)
- [cola 42](./src/other/cola.cpp)

## Legenda

:white_check_mark: skończony program (da się go uruchomić i wydaje się, że działa poprawnie)\
:x: program z wykrytym bugiem\
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

Szczególnie jeśli chcesz ręcznie skonfigurować testy, możesz potrzebować skorzystać ze skryptów. Wszystkie znajdują się w folderze **scripts**.

Skrypt **builder.py** kompiluje kod napisany w C (z restrykcyjnymi opcjami **configs/options**) lub w C++.

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
