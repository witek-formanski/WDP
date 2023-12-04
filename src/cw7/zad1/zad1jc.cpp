#include<stdio.h>
#include<vector>
#include<algorithm>

int słupki(const std::vector<int> s){
    std::vector<int> kopia;
    for(size_t i = 0; i < s.size(); i++){
        kopia.push_back(s[i]);
    }
    std::sort(kopia.begin(), kopia.end());

    int mediana = kopia[kopia.size() / 2];

    int wynik = 0;

    for(size_t i = 0; i < kopia.size(); i++){
        wynik += abs(kopia[i] - mediana);
    }

    return wynik;
}


int main(){
    printf("%i\n", słupki({6, 4, 3, 4, 5, 2, 3}));
    return 0;
}