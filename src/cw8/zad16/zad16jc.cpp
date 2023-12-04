#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

typedef struct node *bin_tree;
struct node {
    int val;
    bin_tree left, right;
};

bin_tree newNode(int val){
    bin_tree nowy = (node*)malloc(sizeof(node));
    nowy->val = val;
    nowy->left = nowy->right = NULL;
    return nowy;
}

int spacer(bin_tree t, int *najdl){
    if(!t) return -1;
    int dlLewy, dlPrawy;
    dlLewy = spacer(t->left, najdl);
    dlPrawy = spacer(t->right, najdl);
    *najdl = std::max(*najdl, dlLewy + dlPrawy + 2);
    return std::max(dlLewy, dlPrawy) + 1;
}

int diam(bin_tree t){
    int wynik = 0;
    spacer(t, &wynik);
    return wynik;
}

int znajdzSr(bin_tree t, const int srednica, bin_tree *wynik){
    if(!t) return -1;
    int dlLewy, dlPrawy;
    dlLewy = znajdzSr(t->left, srednica, wynik);
    dlPrawy = znajdzSr(t->right, srednica, wynik);
    if(std::max(dlLewy, dlPrawy) + 1 == (srednica + 1) / 2) *wynik = t;
    return std::max(dlLewy, dlPrawy) + 1;
}

bin_tree srodek(bin_tree t){
    bin_tree wynik = NULL;
    znajdzSr(t, diam(t), &wynik);
    return wynik;
}

int main(){
    bin_tree t = newNode(1);
    t->left = newNode(2);
    t->left->left = newNode(4);
    t->left->left->left = newNode(5);
    t->left->left->left->left = newNode(60);
    t->right = newNode(3);
    t->right->left = newNode(6);
    t->right->right = newNode(7);
    t->left->right = newNode(11);
    t->right->left->right = newNode(12);

    bin_tree t2 = newNode(1);
    t2->right = newNode(2);
    t2->right->right = newNode(3);
    t2->left = newNode(4);
    t2->left->left = newNode(5);
    t2->left->right = newNode(6);
    t2->left->right->left = newNode(7);
    t2->left->right->left->left = newNode(8);
    t2->left->right->left->left->left = newNode(9);
    t2->left->right->left->left->left->left = newNode(10);
    // t2->left->right->left->left->left->left->left = newNode(100);
    // t2->left->right->left->left->left->left->left->left = newNode(101);
    t2->left->right->left->left->left->right = newNode(11);
    t2->left->right->right = newNode(12);
    t2->left->right->right->right = newNode(13);
    t2->left->right->right->left = newNode(14);
    t2->left->right->right->left->right = newNode(15);
    t2->left->right->right->left->right->left = newNode(16);




    // printf("%i\n", diam(t));
    bin_tree wynik = srodek(t2);
    printf("%i\n", wynik->val);
    return 0;
}