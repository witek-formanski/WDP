/*
policz srednice i najplytszy wierzachloek srednicy
od tego elementu znajdz wierzchoke, od ktorego jest rowno d/2 wysokosci

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right;
};

bin_tree newNode(int val)
{
    bin_tree node = (bin_tree)malloc((sizeof(int) + 2 * sizeof(bin_tree)));
    node->val = val;
    return node;
}

int max(int a, int b)
{
    if (a < b)
        return b;
    return a;
}

int longest(bin_tree t, int *best, bin_tree *shallowest)
{
    if (!t)
        return 0;
    int l = longest(t->left, best, shallowest);
    int p = longest(t->right, best, shallowest);
    int longestPathBelow = l + p;
    if (*best < longestPathBelow)
    {
        *best = longestPathBelow;
        *shallowest = t;
    }
    // return longest path from this below + path to this
    return max(l, p) + 1;
}

void find_diameter(bin_tree t, int *best, bin_tree *shallow)
{
    int temp = longest(t, best, shallow);
}

int path_to_end(bin_tree t, int seeked, bin_tree *results)
{
    if (!t)
        return -1;
    int l = path_to_end(t->left, seeked, results);
    int p = path_to_end(t->right, seeked, results);
    int m = max(l, p) + 1;
    if (m == seeked)
    {
        *results = t;
    }
    return m;
}

bin_tree środek(bin_tree t)
{
    int diameter = 0;
    bin_tree shallow;
    find_diameter(t, &diameter, &shallow);
    bin_tree results;
    int temp = path_to_end(shallow, (diameter + 1) / 2, &results);
    return results;
}

int main()
{
    bin_tree t2 = newNode(1);
    t2->right = newNode(2);
    t2->right->right = newNode(3);
    t2->left = newNode(4);
    t2->left->left = newNode(5);
    t2->left->right = newNode(6);
    t2->left->right->left = newNode(7);
    t2->left->right->left->left = newNode(8);
    t2->left->right->left->left->left = newNode(9);
    t2->left->right->left->left->left->left = newNode(10);
    t2->left->right->left->left->left->left->left = newNode(100);
    t2->left->right->left->left->left->left->left->left = newNode(101);
    t2->left->right->left->left->left->right = newNode(11);
    t2->left->right->right = newNode(12);
    t2->left->right->right->right = newNode(13);
    t2->left->right->right->left = newNode(14);
    t2->left->right->right->left->right = newNode(15);
    t2->left->right->right->left->right->left = newNode(16);

    bin_tree center = środek(t2);
    printf("%d\n", center->val);
}
