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

void del_subtree(bin_tree t){
    if(t == NULL) return;
    del_subtree(t->left);
    del_subtree(t->right);
    free(t);
}

void bestify_subtree(bin_tree t, int maxx, int minn, bin_tree *pToME){
    if(!t) return;
    if(t->val >= maxx || t->val <= minn){
        del_subtree(t);
        *pToME = NULL;
        return;
    }

    bestify_subtree(t->left, t->val, minn, &(t->left));
    bestify_subtree(t->right, maxx, t->val, &(t->right));
}


int main(){
    bin_tree t = newNode(10);
    t->left = newNode(5);
    t->left->right = newNode(15);
    t->right = newNode(14);

    bestify_subtree(t, __INT16_MAX__, -__INT_MAX__, &t);
    return 0;
}