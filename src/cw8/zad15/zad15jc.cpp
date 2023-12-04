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

void usun_drzewo(bin_tree t){
    if(!t) return;
    if(t->left != t->right) {
        usun_drzewo(t->left);
        usun_drzewo(t->right);
    }
    free(t);
}

void _odchudzanie(bin_tree t, int &suma){
    if(!t){
        suma = 0;
    } else {
        int l_pod, p_pod;
        _odchudzanie(t->left, l_pod);
        _odchudzanie(t->right, p_pod);
        if(l_pod == 0) t->left = NULL;
        if(p_pod == 0) t->right = NULL;
        if(t->val + l_pod + p_pod <= 0){ //usuwam sie
            usun_drzewo(t);
            suma = 0;
        } else {
            suma = l_pod + p_pod + t->val;
        }
    }
}

bin_tree odchudzanie(bin_tree t){
    int suma;
    _odchudzanie(t, suma);
    if(suma < 0) return NULL;
    return t;
}

int main(){
    bin_tree t = newNode(10);
    t->left = newNode(9);
    t->left->left = newNode(-7);
    t->left->left->left = newNode(6);
    t->left->left->right = newNode(-2);
    t->right = newNode(-7);
    t->right->left = newNode(2);
    t->right->left->left = newNode(10);
    t->right->left->right = newNode(-4);
    t->right->right = newNode(3);
    t->right->right->right = newNode(-4);

    odchudzanie(t);

    return 0;
}