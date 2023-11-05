#include <stdio.h>

int sqrt(int x){
    int i = 1, k = 0;
    while(x>0){
        i+=2;
        x-=i;
        ++k;
    }

    return k;
}

int main(){
    int x;
    if(!scanf(("%d", &x))) printf("wrong input");

    int sqrtOfx=sqrt(x);
    printf("%d\n",sqrtOfx);
}