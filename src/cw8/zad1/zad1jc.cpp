#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int val;
    struct _node *prev, *next;
} node;

typedef struct _lista {
    node *head, *tail;
} lista;

lista nowaLista(){
    lista wynik = {NULL, NULL};

    return wynik;
}

bool czyPusta(lista l){
    return (!l.head && !l.tail);
}

void push_back(int val, lista &l){
    node *nowy = (node*)malloc(sizeof(node));
    nowy->prev = l.tail;
    nowy->next = NULL;
    nowy->val = val;

    if(!czyPusta(l)){
        l.tail->next = nowy;
    } else {
        l.head = nowy;
    }

    l.tail = nowy;
}

int front(lista l){
    return l.head->val;
}

void pop_front(lista &l){
    if(!czyPusta(l)){
        node *nast = l.head->next;
        free(l.head);
        l.head = nast;
        if(l.head) l.head->prev = NULL;
        else l.tail = NULL;
    }
}

void printList(lista l){
    node *it = l.head;
    bool koniec = false;
    while(!koniec && !czyPusta(l)){ //uwzględnia null, null
        if(it == l.tail) koniec = true;
        printf("%i ", it->val);
        it = it->next;
    }
    printf("\n");
}

void dubluj(lista &l){
    if(czyPusta(l)) return;
    node *nowy = NULL;
    node *it = l.head;
    while(it){
        nowy = (node*)malloc(sizeof(node));
        nowy->val = it->val;
        nowy->prev = it;
        nowy->next = it->next;
        if(it->next){
            it->next->prev = nowy;
        }
        it->next = nowy;
        it = nowy->next;
    }
    l.tail = nowy;
}

int main(){
    lista l = nowaLista();
    push_back(1, l);
    push_back(2, l);
    push_back(3, l);
    push_back(4, l);

    dubluj(l);

    printList(l);

    return 0;
}