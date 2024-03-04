#include<stack>
#include<stdio.h>

using namespace std;

int roznica(int t[], int n){
    int wynik = 0;
    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && t[s.top()] <= t[i]){
            s.pop();
        }
        if(!s.empty()){
            wynik = max(wynik, i - s.top() - 1);
        } else {
            wynik = i - 1;
        }

        s.push(i);
    }

    return wynik;
}

int main(){
    int n = 7, t[] = {6, 4, 3, 4, 5, 2, 3};
    printf("%i\n", roznica(t, n));
    return 0;
}