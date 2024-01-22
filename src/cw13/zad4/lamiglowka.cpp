/*
wrzucamy wszystkie liczby na kolejkę priorytetowa (najmnnijesze na początku)
jeżeli dwa pierwsze są równe, to je "sklejamy" i wrzucamy dwukrotność na kolejkę
jeżeli dwa pierwsze różne, to wyrzucamy pierwszy
*/

#include <queue>
#include <vector>

int lamiglowka(std::vector<int> v) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> q(v.begin(), v.end());
    
}