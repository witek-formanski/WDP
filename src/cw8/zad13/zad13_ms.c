#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right;
};

bin_tree create_node(int v)
{
    bin_tree newTree = (bin_tree)malloc((sizeof(int) + 2 * sizeof(bin_tree)));
    newTree->val = v;
    return newTree;
}

bool are_symetrical_subtrees(bin_tree a, bin_tree b)
{
    if (a == b)
        return true;
    if (!a || !b)
        return false;
    if (a->val != b->val)
        return false;
    return are_symetrical_subtrees(a->left, b->right) && are_symetrical_subtrees(a->right, b->left);
}

bool symetryczne(bin_tree t)
{
    if (t == NULL)
        return true;
    return are_symetrical_subtrees(t->left, t->right);
}

int main()
{
    bin_tree t = create_node(1);
    t->left = create_node(2);
    t->right = create_node(2);
    t->left->left = create_node(3);
    t->left->right = create_node(4);
    t->right->right = create_node(3);
    t->right->left = create_node(4);
    t->right->left->left = create_node(2);
    printf("%i\n", symetryczne(t));
    return 0;
}