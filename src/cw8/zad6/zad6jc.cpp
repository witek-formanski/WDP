#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int val;
    struct _node *next;
} node;

typedef node* lista;

lista push(int val, lista l){
    lista nowy = (node*)malloc(sizeof(node));
    nowy->val = val;
    nowy->next = l;

    return nowy;
}

void printList(lista l){
    while(l){
        printf("%i ", l->val);
        l = l->next;
    }
    printf("\n");
}

int odwrocIPolicz(lista l){
    lista poprzedni = NULL, nast;
    int ct = 0;
    while(l){
        nast = l->next;
        l->next = poprzedni;
        poprzedni = l;
        l = nast;
        ct++;
    }
    return ct;
}

int dlugoscCylku(lista l){
    int kroki = odwrocIPolicz(l), ct = 0;
    for(int i = 0; i < kroki / 2 + 1; i++){
        l = l->next; //jestem na cyklu
    }

    lista start = l;

    do
    {
        ct++;
        l = l->next;
    } while (l != start);
    

    odwrocIPolicz(l);
    return ct;
}

int main(){
    lista l = NULL, mem, pocz;
    pocz = l = push(7, l);
    l = push(6, l);
    l = push(5, l);
    l = push(4, l);
    mem = l = push(3, l);
    l = push(2, l);
    l = push(1, l);

    pocz->next = mem;

    printf("%i\n", dlugoscCylku(l));

    // printList(l);

    return 0;
}