#include <stdio.h>
#include <stdlib.h>

int leader(int n, int t[]){
    int candidate = t[0];
    int count = 1;
    for(int i = 1; i< n; i++){
        if(t[i] == candidate){
            ++count;
        }else{
            --count;
            if(!candidate){
                candidate = t[i+1];
            }
        }
    }
    return candidate;
}

int main(){
    int n;
    if(!scanf(("%d", &n))) printf("wrong input");
    int* t = (int*)malloc((size_t)n * sizeof(int));

    for(int i = 0; i < n; i++){
        if(!scanf(("%d", &t[i]))) printf("wrong input");
    }

    int lead = leader(n, t);
    printf("%d\n", lead);
}