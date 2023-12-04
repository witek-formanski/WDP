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

int dlugosc(lista l){
    int wynik = 0;
    while(l){
        ++wynik;
        l = l->next;
    }
    return wynik;
}

lista wspolnaCzesc(lista l1, lista l2){
    int dL1 = dlugosc(l1), dL2 = dlugosc(l2);
    if(dL1 > dL2){
        for(int i = 0; i < dL1 - dL2; i++) l1 = l1->next;
    } else {
        for(int i = 0; i < dL2 - dL1; i++) l2 = l2->next;
    }

    while(l1 != l2){
        l1 = l1->next;
        l2 = l2->next;
    }

    return l1;
}

int main(){
    lista l3 = NULL;
    l3 = push(4, l3);
    l3 = push(3, l3);
    l3 = push(2, l3);
    l3 = push(1, l3);

    lista l1, l2;
    l1 = l2 = l3;

    l1 = push(11, l1);
    l1 = push(12, l1);
    l1 = push(13, l1);
    l1 = push(14, l1);

    l2 = push(20, l2);
    l2 = push(21, l2);


    printList(l1);
    printList(l2);

    printList(wspolnaCzesc(l1, l2));
    return 0;
}
