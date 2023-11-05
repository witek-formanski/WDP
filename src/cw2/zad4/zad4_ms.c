#include <stdio.h>

int rzadkie(int n){
    n+=1;
    int m = n;
    int i = 1, j = 1;
    while(m){
        if(m & 3 == 1){
            j=i;
        }
        i++;
        m>>=1;
    }

    m = n;
    m >>= j;
    i=0;

    while(m % 4){
        i++;
        m/=2;
    }

    m+=1;
    m<<=i+j;
    
    return m;
}

int main(){
    int x;
    if(!scanf(("%d", &x))) printf("wrong input");

    int rareNum = rzadkie(x);
    printf("%d", rareNum);
}