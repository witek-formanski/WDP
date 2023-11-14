#include<stdlib.h>
#include<stdio.h>

using namespace std;

void printArr(int t[], int n){
    for(int i = 0; i < n; i++)
        printf("%i ", t[i]);
    printf("\n");
}

void inc(int arr[], int n){
    if(arr[0]){
        arr[0] = 0;
        arr[1] = 1;
    } else
        arr[0] = 1;

    for(int i = 2; i < n; i++){
        if(arr[i - 1] && arr[i - 2]){
            arr[i - 1] = 0;
            arr[i - 2] = 0;
            arr[i] = 1;
        }
    }
}

int calculateZeckendorf(int t[], int n){
    int wynik = 0;
    int a = 1, b = 2, temp;
    wynik += t[0] * a + t[1] * b;
    for(int i = 2; i < n; i++){
        temp = a + b;
        a = b;
        b = temp;
        wynik += t[i] * b;
    }
    return wynik;
}

int main(){
    int n = 10; //maksymalna dlugosc
    int *liczba = (int*)calloc((size_t)n, sizeof(int));
    for(int i = 0; i < 30; i++){
        printf("%i\t", calculateZeckendorf(liczba, n));
        printArr(liczba, n); //wyswietla sie w kolejnosci od najmniej znaczacego bitu
        inc(liczba, n);
    }
    return 0;
}