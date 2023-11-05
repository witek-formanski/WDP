#include <stdio.h>

int reverse_number(int x){
    int reversedNumber = 0;
    while(x){
        reversedNumber *= 10;
        reversedNumber += x%10;
        x /= 10;
    }
    return reversedNumber;
}

int main(){
    int x;
    if(!scanf(("%d", &x))) printf("wrong input");
        
    int reversedNum=reverse_number(x);
    printf("%d\n", reversedNum);
}