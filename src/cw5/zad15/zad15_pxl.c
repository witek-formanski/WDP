#include<stdio.h>
#include<stdlib.h>

int **obliczSumPref(int **t, int size_y, int size_x){
    int **sumPref = (int**)malloc((unsigned int)(size_y + 1) * sizeof(int*));
    for(int i = 0; i < size_y + 1; i++)
        sumPref[i] = (int*)malloc((unsigned int)(size_x + 1) * sizeof(int));
    for(int i = 0; i < size_y + 1; i++)
        sumPref[i][0] = 0;
    for(int i = 0; i < size_x + 1; i++)
        sumPref[0][i] = 0;
    for(int y = 0; y < size_y; y++)
        for(int x = 0; x < size_x; x++)
            sumPref[y + 1][x + 1] = t[y][x] + sumPref[y][x + 1] + sumPref[y + 1][x] - sumPref[y][x];
    return sumPref;
}

int prostakat(int **a, int size_y, int size_x, int k){
    int minObw = 2 * (size_y + 1) + 2 * (size_x + 1);
    int x1, x2, drzewa, obwod;
    int **sumPref = obliczSumPref(a, size_y, size_x);

    for(int y1 = 0; y1 < size_y; y1++){
        for(int y2 = y1; y2 < size_y; y2++){
            x1 = x2 = 0;
            while (x2 < size_x){
                drzewa = sumPref[y2 + 1][x2 + 1] - sumPref[y1][x2 + 1] - sumPref[y2 + 1][x1] + sumPref[y1][x1];
                if(drzewa < k)
                    x2++;
                else if(drzewa >= k){
                    obwod = 2 * (x2 - x1 + 1) + 2 * (y2 - y1 + 1);
                    if(obwod < minObw)
                        minObw = obwod;
                    x1++;
                }    
            }
        }
    }

    for(int i = 0; i < size_y + 1; i++)
        free(sumPref[i]);
    free(sumPref);
    
    return minObw;
}

int main(){
    int size_x = 4, size_y = 4;
    int **t = (int**)malloc((unsigned int)size_y * sizeof(int*));
    for(int i = 0; i < size_y; i++)
        t[i] = (int*)malloc((unsigned int)size_x * sizeof(int));
    
    int tab[4][4] = {
        {1, 1, 1, 1},
        {1, 1, 11, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 15}
    };

    for(int y = 0; y < size_y; y++)
        for(int x = 0; x < size_x; x++)
            t[y][x] = tab[y][x];

    printf("%i\n", prostakat(t, size_y, size_x, 30));

    for(int i = 0; i < size_y; i++)
        free(t[i]);
    free(t);
    return 0;
}