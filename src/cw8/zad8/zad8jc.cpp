#include<stdio.h>
#include<stdlib.h>
#include<vector>

typedef struct _node {
    int val;
    std::vector<struct _node*> dzieci;
} node;

typedef node* drzewo;

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

void _obejdz(drzewo t, std::vector<int> &v, bool odwiedzPrzed){
    if(t){
        if(odwiedzPrzed) v.push_back(t->val);
        for(drzewo dziecko : t->dzieci){
            _obejdz(dziecko, v, !odwiedzPrzed);
        }
        if(!odwiedzPrzed) v.push_back(t->val);
    }
}

std::vector<int> obejdz(drzewo t){
    std::vector<int> v;
    _obejdz(t, v, false);
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


    std::vector<int> v = obejdz(t);
    for(int val : v){
        printf("%i ", val);
    }
    printf("\n");
    return 0;
}