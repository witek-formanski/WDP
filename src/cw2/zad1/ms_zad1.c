#include <stdio.h>

int parzystosc(int x){
    if(x==0){
        return -1;
    }
    int i = 0;
    while(x % 2 == 0){
        ++i;
        x >>=1;
    }
    return i;
}

int main(){
    int x;
    scanf("%d", &x);

    int stopien_parzystosci = parzystosc(x);
    printf("%d\n", stopien_parzystosci);
}