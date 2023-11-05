#include <stdio.h>
#include <stdlib.h>

// Original task [PL]
// Napisz procedurę int* shuffle(int n, int a[], int m, int b[]), która dla danych dwóch tablic postaci
// {x1,x2,…,xn} oraz {y1,y2,…,ym} stworzy tablicę postaci {x1;y1;x2;y2;…}. Jeżeli jedna z danych tablic
// jest dłuższa, to jej końcowe elementy trafiają na koniec tablicy wynikowej. 

// What does it do
// Shuffle array a & b into single array: (a0,b0,a1,b1,a2,b2...)
// if one of arrays is shorter, skip "missing" elements from shorter array, for instance: n = 5, m = 2, shuffle: (a0,b0,a1,b1,a2,a3,a4)
int* shuffle(int n, int a[], int m, int b[]){
    int combinedSize = n + m;
    int* mergedArray = (int*)malloc((size_t)combinedSize * sizeof(int));

    int ia = 0, ib = 0, im = 0;
    while(im < combinedSize){
        if(ia < n){
            mergedArray[im++]=a[ia++];
        }
        if(ib < m){
            mergedArray[im++]=b[ib++];
        }
    }

    return mergedArray;
}

int* scan_array(int* arrayLength){
    if(!scanf(("%d", arrayLength))) printf("wrong input");
    int* array = (int*)malloc((size_t)*arrayLength * sizeof(int));
    for(int i = 0; i< *arrayLength; i++){
        if(!scanf(("%d", &array[i]))) printf("wrong input");
    }
    return array;
}

int main(){
    int n,m;
    int* a = scan_array(&n);
    int* b = scan_array(&m);
    int* shuffledArrays = shuffle(n,a,m,b);
    
    for(int i = 0; i< n+m; i++){
        printf("%d\n", shuffledArrays[i]);
    }
}