/*
analogicznie do nawiasów
odpowiedź to zbiór maksymalnych głębokości sufiksowych
*/

#include <vector>

std::vector<int> get_union(std::vector<int> possible_stations_left, std::vector<int> possible_stations_right) {}

std::vector<int> get_possible_initial_stations(int distance[], int fuel[], int size, bool direction) {}

std::vector<int> get_possible_initial_stations(int distance[], int fuel[], int size) {
    return get_union(
        get_possible_initial_stations(distance, fuel, size, true),
        get_possible_initial_stations(distance, fuel, size, false)
    );
}