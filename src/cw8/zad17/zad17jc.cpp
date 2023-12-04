#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

typedef struct node *bin_tree;
struct node {
    int val;
    bin_tree left, right, jump;
};

bin_tree newNode(int val){
    bin_tree nowy = (node*)malloc(sizeof(node));
    nowy->val = val;
    nowy->left = nowy->right = nowy->jump = NULL;
    return nowy;
}

void _fastryguj(bin_tree t, bin_tree &poprzedni){
    if(t){
        _fastryguj(t->left, poprzedni);
        if(poprzedni) poprzedni->jump = t;
        poprzedni = t;
        _fastryguj(t->right, poprzedni);
    }
}

void fastryguj(bin_tree t){
    bin_tree poprzedni = NULL;
    _fastryguj(t, poprzedni);
}

void _w_lewo(bin_tree t, int depth, std::vector<bin_tree> &v){
    if(t){
        t->jump = v[depth];
        v[depth] = t;
        _w_lewo(t->left, depth + 1, v);
        _w_lewo(t->right, depth + 1, v);
    }
}

int height(bin_tree t){
    if(!t) return -1;
    return std::max(height(t->left), height(t->right)) + 1;
}

void w_lewo(bin_tree t){
    std::vector<bin_tree> v(height(t), NULL);
    _w_lewo(t, 0, v);
}

void _potomek(bin_tree t, int glebokosc, int &glPotomka, bin_tree &potomek){
    if(t){
        if(t->left == t->right){
            potomek = t;
            glPotomka = glebokosc;
        } else {
            bin_tree najdlPotomekL = NULL, najdlPotomekR = NULL;
            int glPotomkaL = 0, glPotomkaR = 0;
            _potomek(t->left, glebokosc + 1, glPotomkaL, najdlPotomekL);
            _potomek(t->right, glebokosc + 1, glPotomkaR, najdlPotomekR);
            if(glPotomkaL >= glPotomkaR){
                glPotomka = glPotomkaL;
                potomek = najdlPotomekL;
            } else {
                glPotomka = glPotomkaR;
                potomek = najdlPotomekR;
            }

            t->jump = potomek;
        }
    }
}

void potomek(bin_tree t){
    int glTemp;
    bin_tree potTemp;
    _potomek(t, 0, glTemp, potTemp);
}

int main(){
    bin_tree t = newNode(1);
    t->left = newNode(2);
    t->left->left = newNode(4);
    t->left->left->left = newNode(5);
    t->right = newNode(3);
    t->right->left = newNode(6);
    t->right->right = newNode(7);
    t->left->right = newNode(11);
    t->right->left->right = newNode(12);

    // fastryguj(t);
    // w_lewo(t);
    potomek(t);
    return 0;
}