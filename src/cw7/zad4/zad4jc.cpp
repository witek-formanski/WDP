#include<stdio.h>
#include<vector>
#include<algorithm>

std::vector<float> przekładaniec(const std::vector<float> x){
    std::vector<float> v(x);
    std::sort(v.begin(), v.end());
    std::vector<float> wynik;

    size_t odwiedzone = 1;
    size_t i = 0, j = v.size() - 1;
    wynik.push_back(v[(v.size() - 1) / 2]);
    
    while (odwiedzone < v.size() - 1)
    {
        wynik.push_back(v[j--]);
        wynik.push_back(v[i++]);

        odwiedzone += 2;
    }

    if(odwiedzone < v.size())
        wynik.push_back(v[(v.size() - 1) / 2 + 1]);

    return wynik;
}

int main(){
    std::vector<float> wynik = przekładaniec({1, 2, 3, 4, 6});
    for(auto val : wynik)
        printf("%lf ", val);

    printf("\n");
    return 0;
}