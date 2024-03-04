#include<stack>
#include<stdio.h>

using namespace std;

typedef enum pora {Wiosna, Lato, Jesień, Zima} pora;

int pory(int size, pora arr[]){
    int wynik = -1, najdalszaPora = -1;
    stack<int> s;
    for(int i = 0; i < size; i++){
        if(arr[i] == najdalszaPora + 1)
            najdalszaPora++;
        
        if(najdalszaPora == 3){ //zima i wszystko przed w odpowiedniej kolejnosci
            while(arr[s.top()] != Jesień){
                s.pop();
            }
            while(arr[s.top()] != Lato){
                s.pop();
            }
            while(arr[s.top()] != Wiosna){
                s.pop();
            }

            wynik = max(wynik, i - s.top() + 1);
            s.pop();
            najdalszaPora = -1;
        } else {
            s.push(i);
        }
    }
    return wynik;
}

int main(){
    pora arr[10] = {Wiosna, Wiosna, Jesień, Zima, Lato, Wiosna, Jesień, Zima, Zima, Zima};
    printf("%i\n", pory(10, arr));
    return 0;
}