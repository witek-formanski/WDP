#include<stdio.h>

int p(int n, int t[]){
    int mini = 0, suma = 0, wynik = 0;

    for(int i = 0; i < n; i++){
        suma += t[i];
        if(suma < mini) mini = suma;
        if(suma - mini > wynik) wynik = suma - mini;
    }
    return wynik;
}

int main(){
    int t[] = {1, 6, 8, -16, 20, -2, 7, -8};
    int n = 8;
    printf("%i\n", p(n, t));
    return 0;
}