#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>

int sign(int n){
    return n >= 0 ? 1 : -1;
}

bool czyDaRade(const int k, const std::vector<int> osCzasu, const int ilosc_dni){
    //funkcja sprawdzajaca, czy k znajomych da rade byc na ilosc_dni dniowej wycieczce
    //gasienica po osi czasu
    int ludzieWGasienicy = 1, dzienStartuGasienicy = osCzasu[0];
    size_t head = 0;
    while(head < osCzasu.size()){
        if(ludzieWGasienicy < k){ //przesuwa potencjalny pocz gasienicy na miejsce gdzie jest k osob
            head++;
            ludzieWGasienicy += sign(osCzasu[head]);
            dzienStartuGasienicy = abs(osCzasu[head]);
        }
        while(head < osCzasu.size() && ludzieWGasienicy >= k && abs(osCzasu[head]) <= dzienStartuGasienicy + ilosc_dni - 1){
            head++;
            ludzieWGasienicy += sign(osCzasu[head]);
        }
        if(ludzieWGasienicy - sign(osCzasu[head]) >= k && abs(osCzasu[head]) >= dzienStartuGasienicy + ilosc_dni - 1)
            return true;
    }
    return false;
}

int rejs(int k, const std::vector<int> start, const std::vector<int> end){
    std::vector<int> posStarty(start), posKonce(end);
    std::sort(posStarty.begin(), posStarty.end());
    std::sort(posKonce.begin(), posKonce.end());

    std::vector<int> osCzasu;
    size_t p = 0, q = 0;
    while(p < posStarty.size() && q < posKonce.size()){
        if(posStarty[p] <= posKonce[q]) osCzasu.push_back(posStarty[p++]);
        else osCzasu.push_back(-posKonce[q++]);
    }
    while(p < posStarty.size()) osCzasu.push_back(posStarty[p++]);
    while(q < posKonce.size()) osCzasu.push_back(-posKonce[q++]);

    int lewy = 0, prawy = (int)start.size(), srodek;

    while (lewy < prawy)
    {
        srodek = (lewy + prawy + 1) / 2;
        if(czyDaRade(srodek, osCzasu, k)){
            lewy = srodek;
        }
        else {
            prawy = srodek - 1;
        }
    }
    
    return lewy;
}

int main(){
    printf("%i\n", rejs(20, {12, 48, 28, 55, 0, 25}, {36, 100, 70, 80, 65, 30}));
    return 0;
}