#include <stdio.h>
#include <stdlib.h>

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right, jump;
};

bin_tree newNode(int val)
{
    bin_tree node = (bin_tree)malloc((sizeof(int) + 3 * sizeof(bin_tree)));
    node->val = val;
    return node;
}

bin_tree fastrige(bin_tree t, bin_tree next)
{
    if (t->left == NULL)
    {
        if (t->right == NULL)
            t->jump = next;
        else
            t->jump = fastrige(t->right, next);
        return t;
    }
    if (t->right == NULL)
    {
        t->jump = next;
        return fastrige(t->left, t);
    }
    bin_tree ret = fastrige(t->left, t);
    t->jump = fastrige(t->right, next);
    return ret;
}

void bind_left(bin_tree t, int depth, bin_tree *lefts)
{
    if (t == NULL)
        return;
    t->jump = lefts[depth];
    lefts[depth] = t;
    bind_left(t->left, depth + 1, lefts);
    bind_left(t->right, depth + 1, lefts);
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void set_depth(bin_tree t, int currentDepth, int *maxDepth, bin_tree *deepest)
{
    if (t == NULL)
        return;
        
    int currentRecordDepth = currentDepth;
    set_depth(t->left, currentDepth + 1, &currentRecordDepth, &(t->jump));
    set_depth(t->right, currentDepth + 1, &currentRecordDepth, &(t->jump));
    if (t->jump != NULL)
        *deepest = t->jump;
    else
    {
        t->jump = NULL;
        if (currentDepth > *maxDepth)
        {
            *deepest = t;
            *maxDepth = currentDepth;
        }
    }
}

void potomek(bin_tree t)
{
    int depth = 0;
    bin_tree d;
    set_depth(t, 0, &depth, &d);
}

int get_depth(bin_tree t)
{
    if (t == NULL)
        return 0;
    return max(get_depth(t->left), get_depth(t->right)) + 1;
}

void w_lewo(bin_tree t)
{
    int depth = get_depth(t);
    bin_tree *lefts = (bin_tree *)malloc((size_t)(depth) * ((sizeof(int) + 3 * sizeof(bin_tree))));
    for (int i = 0; i < depth; i++)
    {
        lefts[i] = NULL;
    }
    bind_left(t, 0, lefts);
}

bin_tree fastryguj(bin_tree t)
{
    if (t == NULL)
        return NULL;
    return fastrige(t, NULL);
}

void fastryguj_test()
{
    bin_tree t2 = newNode(0);
    t2->left = newNode(1);
    t2->left->left = newNode(3);
    t2->left->right = newNode(4);
    t2->right = newNode(2);
    t2->right->left = newNode(5);
    t2->right->right = newNode(6);
    bin_tree curr = fastryguj(t2);
    // print in infix order
    while (curr)
    {
        printf("%d\n", curr->val);
        curr = curr->jump;
    }
}

void lewo_test()
{
    bin_tree t2 = newNode(0);
    t2->left = newNode(1);
    t2->left->left = newNode(3);
    t2->left->right = newNode(4);
    t2->right = newNode(2);
    t2->right->left = newNode(5);
    t2->right->right = newNode(6);

    w_lewo(t2);
    bin_tree lvl = t2;
    do
    {
        bin_tree curr = lvl;
        do
        {
            printf("%d ", curr->val);
            curr = curr->jump;
        } while (curr);
        lvl = lvl->right;
        printf("\n");
    } while (lvl);
}

void print_potomek(bin_tree t)
{
    if (t == NULL)
        return;

    print_potomek(t->left);

    printf("%d: ", t->val);
    if (t->jump == NULL)
        printf("NULL");
    else
        printf("%d", t->jump->val);
    printf("\n");

    print_potomek(t->right);
}

void potomek_test()
{
    bin_tree t2 = newNode(0);
    t2->left = newNode(1);
    t2->left->left = newNode(3);
    t2->left->right = newNode(4);
    t2->right = newNode(2);
    t2->right->left = newNode(5);
    t2->right->right = newNode(6);
    t2->right->right->right = newNode(7);

    potomek(t2);
    print_potomek(t2);
}

int main()
{
    // fastryguj_test();
    // lewo_test();
    potomek_test();
}