#include<stdio.h>
#include<stack>

using namespace std;

int znak(int n){
    return n >= 0 ? 1 : -1;
}

int warstwy(int t[], int n){
    stack<int> s;
    int w1, doZmiany;
    for(int i = 0; i < n; i++){
        if(s.empty() && t[i] < 0){
            s.push(t[i]);
        } else if(!s.empty()){
            w1 = 0;
            doZmiany = t[i];

            while (znak(doZmiany) == znak(t[i]) && !s.empty()) {
                if(znak(s.top()) == znak(t[i]))
                    w1 += s.top();
                else{
                    w1 += -s.top();
                    doZmiany += s.top();
                }
                s.pop();
            }
            w1 += doZmiany;

            if(!(s.empty() && w1 >= 0 && doZmiany >= 0)){
                if(doZmiany) s.push(doZmiany);
                if(w1) s.push(w1);
            }            
        }
    }

    int ct = 0;
    while(!s.empty())
    {
        t[ct++] = s.top();
        s.pop();
    }

    return ct;

}

void printArr(int t[], int n){
    for(int i = 0; i < n; i++)
        printf("%i ", t[i]);
    printf("\n");
}

int main(){
    int temperatury[] = {2, -12, 8, -4, 2, 4, -4, 1, -3};
    int n = 9;
    int n_wynik = warstwy(temperatury, n);
    printArr(temperatury, n_wynik);
    return 0;
}