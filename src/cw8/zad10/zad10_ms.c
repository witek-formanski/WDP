#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right;
};

bin_tree create_node(int val)
{
    bin_tree node = (bin_tree)(malloc(sizeof(int) + 2*sizeof(bin_tree)));
    node->val=val;
    return node;
}

bool spacer(bin_tree t, int depth, int *max_depth)
{
    if (t == NULL)
        return true;
    if (t->left == t->right)
    {
        // leaf
        if (*max_depth < depth)
            return false;
        *max_depth = depth;
    }
    return spacer(t->left, depth + 1, max_depth) && spacer(t->right, depth + 1, max_depth);
}

bool ultraleft(bin_tree t)
{
    int maxDepth = 1;
    bin_tree left = t->left;
    while(left != NULL){
        maxDepth++;
        left = left->left;
    }
    return spacer(t, 1, &maxDepth);
}

int main()
{
    bin_tree tree = create_node(1);
    tree->left =  create_node(2);
    tree->left->left =  create_node(3);
    tree->left->right =  create_node(4);
    tree->left->right->right =  create_node(5);
    tree->left->right->right->right =  create_node(3);
    //tree->left->right->right->right->right =  create_node(3);
    //tree->left->right->right->right->right->right =  create_node(3);
    tree->left->left->left =  create_node(6);
    tree->left->left->left->left =  create_node(7);

    printf("%d\n", ultraleft(tree));
}