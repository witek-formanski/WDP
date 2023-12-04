#include<vector>
#include<stdio.h>
#include<stdlib.h>

typedef struct _node {
    int val;
    std::vector<struct _node*> dzieci;
} node;

typedef node* drzewo;

int wysokosc(drzewo t){
    if(!t) return -1; //drzewo puste
    int maksZDzieci = -1;
    for(size_t i = 0; i < t->dzieci.size(); i++){
        if(wysokosc(t->dzieci[i]) > maksZDzieci)
            maksZDzieci = wysokosc(t->dzieci[i]);
    }

    return maksZDzieci + 1;
}

drzewo dodajPotomka(int val, drzewo *t){
    drzewo potomek = (node*)malloc(sizeof(node));
    potomek->val = val;
    potomek->dzieci = {};

    if(*t){
        (*t)->dzieci.push_back(potomek);
    } else {
        *t = potomek;
    }

    return potomek;
}

int liczbaElementow(drzewo t){
    if(!t) return 0;
    int liczbaWPotomkach = 0;
    for(size_t i = 0; i < t->dzieci.size(); i++){
        liczbaWPotomkach += liczbaElementow(t->dzieci[i]);
    }
    return liczbaWPotomkach + 1;
}

void _preOrder(drzewo t, std::vector<int> &v){
    if(t){
        v.push_back(t->val);
        for(size_t i = 0; i < t->dzieci.size(); i++){
            _preOrder(t->dzieci[i], v);
        }
    }
}

std::vector<int> preOrder(drzewo t){
    std::vector<int> v;
    _preOrder(t, v);
    return v;
}

void _postOrder(drzewo t, std::vector<int> &v){
    if(t){
        for(size_t i = 0; i < t->dzieci.size(); i++){
            _postOrder(t->dzieci[i], v);
        }
        v.push_back(t->val);
    }
}

std::vector<int> postOrder(drzewo t){
    std::vector<int> v;
    _postOrder(t, v);
    return v;
}

int main(){
    drzewo t = NULL, doDodania;
    dodajPotomka(1, &t);
    doDodania = dodajPotomka(2, &t);
    dodajPotomka(3, &t);
    dodajPotomka(4, &t);

    doDodania = dodajPotomka(5, &doDodania);
    doDodania = dodajPotomka(6, &doDodania);
    dodajPotomka(7, &doDodania);
    dodajPotomka(8, &doDodania);

    doDodania = t->dzieci[2];
    doDodania = dodajPotomka(9, &doDodania);
    dodajPotomka(10, &doDodania);
    dodajPotomka(11, &doDodania);
    dodajPotomka(12, &doDodania);
    dodajPotomka(13, &doDodania);

    printf("%i\n", wysokosc(t));
    printf("%i\n", liczbaElementow(t));

    std::vector<int> wynik = postOrder(t);
    for(int val : wynik){
        printf("%i ", val);
    }
    printf("\n");
    return 0;
}