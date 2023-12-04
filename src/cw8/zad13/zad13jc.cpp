#include<stdio.h>
#include<stdlib.h>

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

bool _symetryczne(bin_tree t1, bin_tree t2){
    if(t1 == t2) return true; //dwa nulle
    else if(!t1 || !t2) return false; //jeden juz sie skonczyl
    else if(t1->val != t2->val) return false;
    return _symetryczne(t1->left, t2->right) && _symetryczne(t1->right, t2->left);
}

bool symetryczne(bin_tree t){
    if(!t) return true;
    return _symetryczne(t->left, t->right);
}

int main(){
    bin_tree t = newNode(1);
    t->left = newNode(2);
    t->right = newNode(2);
    t->left->left = newNode(3);
    t->left->right = newNode(4);
    t->right->right = newNode(3);
    t->right->left = newNode(4);
    // t->right->left->left = newNode(2);
    printf("%i\n", symetryczne(t));
    return 0;
}