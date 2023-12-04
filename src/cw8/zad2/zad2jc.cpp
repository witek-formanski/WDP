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

int top(lista l){
    if(l) return l->val;
    return 0;
}

lista pop(lista l){
    lista nowy = NULL;
    if(l){
        nowy = l->next;
        free(l);
    }
    return nowy;
}

void printList(lista l){
    int i = 0;
    while(l && i++ < 8){
        printf("%i ", l->val);
        l = l->next;
    }
    printf("\n\n");
}

void zcykluj(lista l){
    if(l){
        lista prev = NULL, nast, first = l;
        while(l){
            nast = l->next;
            l->next = prev;
            prev = l;
            l = nast;
        }
        first->next = prev;
    }
}

int main(){
    lista l = NULL;
    l = push(1, l);
    l = push(2, l);
    l = push(3, l);
    l = push(4, l);

    zcykluj(l);
    printList(l);
    return 0;
}