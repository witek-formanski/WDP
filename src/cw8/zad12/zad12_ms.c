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
    bin_tree node = (bin_tree)(malloc(sizeof(int) + 2 * sizeof(bin_tree)));
    node->val = val;
    return node;
}

int cut(bin_tree t, int *min, int total, bin_tree* results_parent, bin_tree* results)
{
    int childrenLeft = 0;
    if(t->left != NULL)
        childrenLeft=cut(t->left, min, total, results_parent,results);

    int childrenRight = 0;
    if(t->right !=NULL)
        childrenRight=cut(t->right, min, total, results_parent,results);

    // is left subtree current best
    if (abs(total - (2*childrenLeft)) < *min)
    {
        *min = abs(total - (2*childrenLeft));
        *results= t->left;
        *results_parent=t;
    }
    // is right subtree current best
    if (abs(total - (2*childrenRight)) < *min)
    {
        *min = abs(total - (2*childrenRight));
        *results = t->right;
        *results_parent=t;
    }
    return childrenLeft + childrenRight +1;
}

int total_nodes(bin_tree t)
{
    if (t == NULL)
        return 0;
    int count = 1;
    count += total_nodes(t->left);
    count += total_nodes(t->right);
    return count;
}


bin_tree rozcięcie(bin_tree t)
{
    int totalNodes = total_nodes(t);
    if (totalNodes < 2)
        return NULL;
    int min = totalNodes;
    bin_tree results, parent;
    int total= cut(t, &min, totalNodes, &parent,&results);
    
    // cut the connection
    if(parent->left == results){
        parent->left = NULL;
    }
    if(parent->right == results){
        parent->right = NULL;
    }
    return results;
}

int main()
{

    bin_tree tree = create_node(1);
    tree->left = create_node(2);
    tree->left->left = create_node(3);
    tree->left->right = create_node(4);
    tree->left->right->right = create_node(5);
    tree->left->right->right->right = create_node(6);
    tree->left->right->right->right->right = create_node(7);
    tree->left->right->right->right->right->right = create_node(8);
    tree->left->left->left = create_node(9);
    tree->left->left->left->left = create_node(10);

    bin_tree s = rozcięcie(tree);
}