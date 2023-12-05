#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right;
};

bin_tree new_node(int val)
{
    bin_tree node = (bin_tree)(malloc(sizeof(int) + 2 * sizeof(bin_tree)));
    node->val = val;
    return node;
}

void delete_tree(bin_tree *t)
{
    if (t == NULL)
        return;
    if (*t == NULL)
        return;
    delete_tree(&((*t)->left));
    delete_tree(&((*t)->right));
    free(*t);
    *t = NULL;
}

int make_bigger_sum(bin_tree t)
{
    if (t == NULL)
        return 0;

    int sumLeft = make_bigger_sum(t->left);
    if (sumLeft < 0)
    {
        delete_tree(&(t->left));
        sumLeft = 0;
    }

    int sumRight = make_bigger_sum(t->right);
    if (sumRight < 0)
    {
        delete_tree(&(t->right));
        sumRight = 0;
    }

    return t->val + sumLeft + sumRight;
}
bin_tree odchudzanie(bin_tree t)
{
    int temp = make_bigger_sum(t);
    if (temp < 0)
    {
        delete_tree(&t);
    }

    return t;
}

int main(){
    //bin_tree t = new_node(-22);
    bin_tree t = new_node(-21);
    t->left = new_node(5);
    t->left->right = new_node(2);
    t->left->right->right = new_node(-2);
    t->left->right->right->left = new_node(-10);
    t->right = new_node(14);
    
    t = odchudzanie(t);

    delete_tree(&t);
}