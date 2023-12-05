#include<stack>
#include<stdio.h>

using namespace std;

int nawiasy(char arr[]){
    int wynik = 0;
    stack<int> s;
    s.push(-1);

    for(int i = 0; arr[i]; i++){
        if(arr[i] == '(')
            s.push(i);

        if(arr[i] == ')' && s.top() != -1 && arr[s.top()] == '('){
            s.pop();
            wynik = max(wynik, i - s.top());
        } else if(arr[i] == ')' and s.top() == -1){
            s.pop();
            s.push(i);
        }
    }
    return wynik;
}

int main(){
    char string[] = "()())()()()";
    printf("%i\n", nawiasy(string));
    return 0;
}