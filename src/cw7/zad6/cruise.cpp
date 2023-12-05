/*
z sortowaniem:
T(n) = O(n logn)
pomijając sortowanie:
T(n) = O(n)

M(n) = O(n)
*/

#include <assert.h>

#include <algorithm>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

int* get_sorted_array(const std::vector<int> vect) {
    int* arr = (int*)malloc((size_t)vect.size() * sizeof(int));
    for (int i = 0; i < vect.size(); i++)
        arr[i] = vect[i];

    std::sort(arr, arr + vect.size());
    return arr;
}

// at timeline[i][2]: count of colleagues available at day timeline[i][0]
void set_colleagues_count_in_timeline(int** timeline, int size) {
    assert(timeline[0][1] == 1);  // first arrival before any departures
    timeline[0][2] = timeline[0][1];
    for (int i = 1; i < size; i++)
        timeline[i][2] = timeline[i - 1][2] + timeline[i][1];
}

/*
at timeline[i][0]: day of arrival or departure
at timeline[i][1]: 1 for arrival or -1 for departure
at timeline[i][2]: empty for set_colleagues_count_in_timeline()
*/
int** get_timeline(int start[], int end[], int size) {
    int** timeline = (int**)malloc((size_t)(2*size) * sizeof(int*));
    for (int i = 0; i < 2 * size; i++)
        timeline[i] = (int*)malloc((size_t)3 * sizeof(int));

    int start_i = 0;
    int end_i = 0;
    int i = 0;
    while (start_i < size && end_i < size) {
        if (start[start_i] <= end[end_i]) {
            timeline[i][0] = start[start_i];
            timeline[i][1] = 1;
            start_i++;
            i++;
        } else {
            timeline[i][0] = end[end_i];
            timeline[i][1] = -1;
            end_i++;
            i++;
        }
    }

    while (start_i < size) {
        timeline[i][0] = start[end_i];
        timeline[i][1] = 1;
        start_i++;
        i++;
    }

    while (end_i < size) {
        timeline[i][0] = end[end_i];
        timeline[i][1] = -1;
        end_i++;
        i++;
    }

    assert(i == 2 * size);

    set_colleagues_count_in_timeline(timeline, 2 * size);
    return timeline;
}

std::vector<std::pair<int, int>> get_vect_of_counts(int** timeline, int size) {
    std::vector<std::pair<int, int>> counts;

    std::stack<int> days_of_increasing_count;
    days_of_increasing_count.push(timeline[0][0]);
    for (int i = 1; i < size; i++) {
        if (timeline[i][2] > timeline[i - 1][2])
            days_of_increasing_count.push(timeline[i][0]);
        else {
            counts.push_back(
                std::make_pair(
                    timeline[i - 1][2],
                    timeline[i][0] - days_of_increasing_count.top()));
            days_of_increasing_count.pop();
        }
    }

    return counts;
}

int get_max_colleagues_count(std::vector<std::pair<int, int>> counts, int period) {
    int max_count = 0;
    for (std::pair<int, int> time_span : counts)
        if (time_span.second >= period)
            max_count = std::max(time_span.first, max_count);

    return max_count;
}

int cruise(int k, const std::vector<int> start, const std::vector<int> end) {
    assert(start.size() == end.size());

    return get_max_colleagues_count(
        get_vect_of_counts(
            get_timeline(
                get_sorted_array(start),
                get_sorted_array(end),
                start.size()),
            2 * start.size()),
        k);
}

#include <iostream>

int main() {
    std::cout << cruise(20, {12, 48, 28, 55, 0, 25}, {36, 100, 70, 80, 65, 30});
}

/*
inny pomysł:
O(n logn)
binsearch po możliwych wynikach
dla każdego potencjalnego wyniku sprawdzenie gąsiennicą,
czy przynajmniej n kolegów jest dostępnych w danym przedziale

jeszcze inny pomysł:
O(k), gdzie k to maksymalny dzień
potencjalnie ogromna tablica pomocnicza - oś czasu
*/