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
    lista nast = NULL;
    if(l){
        nast = l->next;
        free(l);
    }
    return nast;
}

void printList(lista l){
    while(l){
        printf("%i ", l->val);
        l = l->next;
    }
    printf("\n");
}

void scal(lista l1, lista l2){
    lista nast1, nast2;
    while(l1 && l2){
        nast1 = l1->next;
        nast2 = l2->next;
        l1->next = l2;
        if(nast1) l2->next = nast1;

        l1 = nast1;
        l2 = nast2;
    }
}

int main(){
    lista l1 = NULL, l2 = NULL;
    l1 = push(7, l1);
    l1 = push(5, l1);
    l1 = push(3, l1);
    l1 = push(1, l1);

    l2 = push(6, l2);
    l2 = push(4, l2);
    l2 = push(2, l2);

    scal(l1, l2);

    printList(l1);

    return 0;
}