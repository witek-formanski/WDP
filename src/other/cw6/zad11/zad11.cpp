#include<queue>
#include<deque>
#include<stdio.h>

using namespace std;

int dlugosc(int a[], int n){
    if(n == 0)
        return 0;

    queue<int> q;
    deque<int> minima; //zakladam, ze deque zostaly zaimplementowane w zad2
    int dl = 1, wynik = 0;
    q.push(0);
    minima.push_back(0);

    for(int i = 1; i < n; i++){
        while(!minima.empty() && a[minima.back()] >= a[i]){
            minima.pop_back();
        }
        minima.push_back(i);

        while(dl >= a[minima.front()]){
            if(minima.front() == q.front()){ //usuwam minimum
                minima.pop_front();
            }
            q.pop();
            dl--;
        }

        if(dl < a[minima.front()]){
            dl++;
            wynik = max(wynik, dl);
            q.push(i);
        }
    }

    return wynik;
}

int main(){
    int n = 11, t[] = {1, 8, 6, 5, 6, 1, 7, 8, 6, 3, 4};
    printf("%i\n", dlugosc(t, n));
    return 0;
}