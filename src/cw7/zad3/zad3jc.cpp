#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<stdlib.h>

int zaokrDod(int a, int b){
    if(2 * (a % b) >= b)
        return a / b + 1;
    return a / b;
}

int zaokrDzielenie(int a, int b){
    return a * b > 0 ? zaokrDod(a, b) : -zaokrDod(abs(a), abs(b));
}

int przedzial(const std::vector<int> x, int r){
    std::vector<int> kopia(x);
    std::sort(kopia.begin(), kopia.end());
    std::queue<int> q;

    int suma = 0, elementy = 0, maxElementy = 0, wynik = 0;
    int c;
    bool wszystkieNaleza;

    for(size_t i = 0; i < kopia.size(); i++){
        q.push(kopia[i]);
        suma += kopia[i];
        ++elementy;

        do
        {
            wszystkieNaleza = true;
            c = zaokrDzielenie(suma, elementy); //c jest srednia z elementow
            if(abs(q.front() - c) > r){
                suma -= q.front();
                --elementy;
                q.pop();
                wszystkieNaleza = false;
            }
        } while (!wszystkieNaleza);
        //dla konktertnego i bede usuwal mniejsze elementy az kopia[i] sie zalicza
        
        if(elementy > maxElementy){
            maxElementy = elementy;
            wynik = c;
        }
    }

    return wynik;
}

int main(){
    printf("%i\n", przedzial({2, -2, 5, -1, 11, 8, 4, 5, 8, 7}, 2));
    return 0;
}