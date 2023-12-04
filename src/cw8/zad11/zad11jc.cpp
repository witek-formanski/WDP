#include<stdio.h>
#include<stdlib.h>

typedef struct node *bin_tree;
struct node {
    int val;
    bin_tree left, right;
};

bin_tree newNode(int val){
    bin_tree t = (node*)malloc(sizeof(node));
    t->val = val;
    t->left = t->right = NULL;
    return t;
}

void insert(bin_tree el, bin_tree *t){ //szuka miejsca w slabszym BST
    if(!*t) *t = el;
    else{
        bin_tree *k = t;
        while(*k){
            if(el->val <= (*k)->val){
                k = &((*k)->left);
            } else {
                k = &((*k)->right);
            }
        }
        *k = el;
    }
}

void _bestify(bin_tree t){
    if(!t) return;
    //tylko lwey za duzy
    if(t->left && t->left->val > t->val && !t->right){
        t->right = t->left;
        t->left = NULL;
    } else if(t->right && t->right->val < t->val && !t->left){
        t->left = t->right;
        t->right = NULL;
    } else if(t->left && t->right){
        if(t->left->val > t->val && t->right->val < t->val){
            bin_tree temp = t->right;
            t->right = t->left;
            t->left = temp;
        } else if(t->left->val >= t->val && t->right->val >= t->val){
            insert(t->left, &(t->right));
            t->left = NULL;
        } else if(t->left->val <= t->val && t->right->val <= t->val){
            insert(t->right, &(t->left));
            t->left = NULL;
        }
    }
}

void bestify(bin_tree t){
    if(t){
        bestify(t->left);
        bestify(t->right);
        _bestify(t);
    }
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

    // bin_tree t = newNode(2);
    // t->left = newNode(4);
    // t->left->right = newNode(5);
    // t->right = newNode(11);

    bestify(t);
    return 0;
}