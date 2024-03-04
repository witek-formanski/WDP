#include<stdio.h>

int suf(int x, int d){
    if(x % d == 0)
        return x / d;
    return x / d + 1;
}

int potrzebne(int m[], int size, int d){ //ile slupow jest potrzebne, by odl byla d
    int min = m[0], x = 0, c = m[0], ct = 0;
    for(int i = 0; i < size; i++) if(m[i] < c) c = m[i];

    for(int i = 0; i < size; i++){
        if(m[i] < min)
            min = m[i];
        if(suf(x + 1, d) * c <= min){
            x++;
        }else{
            x = 1;
            min = m[i];
            ct++;
        }
    }
    return ct;
}

int most(int m[], int size, int k){
    int p = 1, q = size, mid;
    while(p < q){
        mid = (p + q) / 2;
        if(potrzebne(m, size, mid) > k)
            p = mid + 1;
        else
            q = mid;
    }
    return p;
}

int main(){
    int t[] = {3, 5, 8, 4, 2, 3, 5, 7};
    int n = 8;
    printf("%i\n", most(t, n, 1));
    return 0;
}