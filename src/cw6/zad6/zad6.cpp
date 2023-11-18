#include<stack>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

int *widoczne(int t[], int n){
    int *wynik = (int*)calloc((size_t)n, sizeof(int));
    int powtorki = 0;
    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && s.top() <= t[i]){
            if(s.top() == t[i])
                powtorki++;
            s.pop();
            wynik[i]++;
        }
        if(!s.empty())
            wynik[i]++;
        s.push(t[i]);
        for(int j = 0; j < powtorki; j++) s.push(t[i]);
        powtorki = 0;
    }

    while(!s.empty()) s.pop();
    for(int i = n - 1; i >= 0; i--){
        while(!s.empty() && s.top() <= t[i]){
            if(s.top() == t[i])
                powtorki++;
            s.pop();
            wynik[i]++;
        }
        if(!s.empty())
            wynik[i]++;
        s.push(t[i]);
        for(int j = 0; j < powtorki; j++) s.push(t[i]);
        powtorki = 0;
    }
    return wynik;
}

int main(){
    // int n = 7, t[] = {1, 8, 6, 7, 4, 8, 9};
    int n = 5, t[] = {1, 8, 5, 6, 4};
    int *wynik = widoczne(t, n);
    for(int i = 0; i < n; i++)
        printf("%i ", wynik[i]);
    printf("\n");
    return 0;
}