#include <iostream>
#include <queue>

using namespace std;

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right;
};

bin_tree newNode(int val)
{
    bin_tree newTree = (bin_tree)malloc((sizeof(int) + 2 * sizeof(bin_tree)));
    newTree->val = val;
    return newTree;
}

bin_tree bestify(bin_tree t, queue<bin_tree> *toAdd)
{
    if (!t)
        return t;
    // if empty put
    if (!t->left)
    {
        if (!toAdd->empty() && toAdd->front()->val < t->val)
        {
            t->left = toAdd->front();
            toAdd->pop();
        }
    }
    if (!t->right)
    {
        if (!toAdd->empty() && toAdd->front()->val > t->val)
        {
            t->right = toAdd->front();
            toAdd->pop();
        }
    }

    if (t->left)
    {
        if (t->left->val > t->val)
        {
            if (t->right != NULL)
            {
                toAdd->push(t->right);
            }
            t->right = t->left;
            t->left = NULL;
        }
        else
        {
            t->left = bestify(t->left, toAdd);
        }
    }

    if (t->right)
    {
        if (t->right->val < t->val)
        {
            toAdd->push(t->right);
            t->right = NULL;
        }
        else
        {
            t->right = bestify(t->right, toAdd);
        }
    }
    return t;
}

bin_tree bestify(bin_tree t)
{
    queue<bin_tree> q;
    bin_tree r = NULL;
    do
    {
        r = bestify(t, &q);
    } while (!q.empty());
    return r;
}

int main()
{
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