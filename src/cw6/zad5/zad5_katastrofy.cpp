#include<stdio.h>
#include<stack>

using namespace std;

int pole(int t[], int n){
    int maks = 0;
    int poprzedni;
    stack<int> s;
    s.push(-1);

    for(int i = 0; i < n; i++){

        while(s.top() > -1 && t[s.top()] > t[i]){
            poprzedni = s.top();
            while (t[s.top()] == t[poprzedni]) {
                s.pop();
            }
            maks = max(maks, (i - s.top() - 1) * t[poprzedni]);
        }

        s.push(i);        
    }

    return maks;
}

int main(){
    int t[] = {3, 5, 1, 3, 3, 5, 4, 5, 2, 3};
    int n = 10;
    printf("%i\n", pole(t, n));
    return 0;
}