#include <stdio.h>
#include <stdlib.h>

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right;
};

bin_tree new_node(int val)
{
    bin_tree node = (bin_tree)malloc((sizeof(int) + 2 * sizeof(bin_tree)));
    node->val = val;
    return node;
}

void delete_tree(bin_tree *t)
{
    if (!*t)
        return;
    delete_tree(&((*t)->left));
    delete_tree(&((*t)->right));
    free(*t);
    *t = NULL;
}

void make_bst(bin_tree* t, int max, int min)
{
    if(*t==NULL)
    return;
    if ((*t)->val <= min || (*t)->val >= max)
    {
        delete_tree(t);
        return;
    }
    make_bst(&((*t)->left), (*t)->val, min);
    make_bst(&((*t)->right), max, (*t)->val);
}

void bstify(bin_tree t)
{
    if(t==NULL)
    return;
    make_bst(&(t->left), t->val, -__INT32_MAX__);
    make_bst(&(t->right), __INT32_MAX__, t->val);
}

int main()
{
    bin_tree t = new_node(10);
    t->left = new_node(5);
    t->left->right = new_node(15);
    t->right = new_node(14);

    bstify(t);
    return 0;
}