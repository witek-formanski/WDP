#include <stdlib.h>
#include <limits.h>

typedef struct node *bin_tree;
struct node {
    int val;
    bin_tree left, right;
};

void del_subtree(bin_tree *t) {
    if (!*t) return;
    del_subtree(&((*t)->left));
    del_subtree(&((*t)->right));
    free(*t);
    *t = NULL;
}

void bstify_subtree(bin_tree t, int maxx, int minn) {
    if (!t) return;
    if (t->right) {
        if (t->right->val <= t->val || t->right->val >= maxx)
            del_subtree(&t->right);
        else
            bstify_subtree(t->right, maxx, t->val);
    }
    if (t->left) {
        if (t->left->val <= minn || t->left->val >= t->val)
            del_subtree(&t->left);
        else
            bstify_subtree(t->left, t->val, minn);
    }
}

void bstify(bin_tree t) {
    bstify_subtree(t, INT_MAX, INT_MIN);
}