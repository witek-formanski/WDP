#define GO_LEFT -1
#define GO_RIGHT 0
#define SUMMARY 1

#include <iostream>
#include <stack>

using namespace std;

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right;
};

typedef struct q *interesant;
struct q
{
    bin_tree parent;
    int *height;
    int status;
};

bin_tree new_node(int val)
{
    bin_tree node = (bin_tree)malloc((sizeof(int) + 2 * sizeof(bin_tree)));
    node->val = val;
    return node;
}

interesant create_interesant(bin_tree parent)
{
    interesant inter = (interesant)malloc(2 * (sizeof(int) + sizeof(bin_tree)));
    inter->parent = parent;
    inter->height = (int *)malloc((size_t)2 * sizeof(int));
    inter->status = GO_LEFT;
    return inter;
}

// we can't go with recursion, so i made pseudo recursion
bool avl(bin_tree t)
{
    int height = 0;
    stack<interesant> pseudo;
    pseudo.push(create_interesant(t));

    while (1)
    {
        interesant current = pseudo.top();
        switch (current->status)
        {
        case GO_LEFT:
            // measure left subtree
            if (current->parent->left == NULL)
            {
                current->height[0] = 0;
                current->status = GO_RIGHT;
            }
            else
            {
                current->status = GO_RIGHT;
                pseudo.push(create_interesant(current->parent->left));
            }
            break;
        case GO_RIGHT:
            // measure right subtree
            if (current->parent->right == NULL)
            {
                current->height[1] = 0;
                current->status = SUMMARY;
            }
            else
            {
                current->status = SUMMARY;
                pseudo.push(create_interesant(current->parent->right));
            }
            break;
        case SUMMARY:
            // summary subtress heigh at pass own height to parent
            // if this subtree is AVL
            if (abs(current->height[0] - current->height[1]) > 1)
                return false;
            pseudo.pop();
            if (pseudo.empty())
            {
                return true;
            }
            int height = max(current->height[0], current->height[1]) + 1;
            if (pseudo.top()->parent->left == current->parent)
            {
                // current tree is a left subtree of a parent
                pseudo.top()->height[0] = height;
            }
            else
            {
                // current tree is a right subtree of a parent
                pseudo.top()->height[1] = height;
            }
            break;
        }
    }
    return false;
}

int main()
{
    bin_tree t = new_node(10);
    t->left = new_node(5);
    t->left->right = new_node(15);
    // t->left->right->right = new_node(15);
    t->right = new_node(14);
    cout << avl(t) << endl;
}