#include <iostream>

using namespace std;

template <typename T>
struct node
{
    T value;
    node<T> *nextNode;
    node<T> *lowerNode;
};

template <typename T>
struct tree
{
    node<T> *head;
};

template <typename T>
tree<T> *create_tree()
{
    tree<T> *emptyTree = (tree<T> *)malloc(sizeof(node<T> *));
    emptyTree->head = NULL;
    return emptyTree;
}

template <typename T>
node<T> *create_node(T value)
{
    node<T> *emptyTree = (node<T> *)malloc(sizeof(T) + 2 * sizeof(node<T> *));
    emptyTree->value = value;
    emptyTree->nextNode = NULL;
    emptyTree->lowerNode = NULL;
    return emptyTree;
}

template <typename T>
void push_node(node<T> *parent, node<T> *child)
{
    if (parent == NULL || child == NULL)
        return;
    if (parent->lowerNode == NULL)
    {
        parent->lowerNode = child;
        return;
    }
    node<T> *predecessor = parent->lowerNode;
    while (predecessor->nextNode != NULL)
    {
        predecessor = predecessor->nextNode;
    }
    predecessor->nextNode = child;
}

template <typename T>
void push_node(node<T> *parent, T value)
{
    if (parent == NULL)
        return;
    node<T> *child = create_node<T>(value);
    push_node(parent, child);
}

template <typename T>
void push_node(tree<T> *parent, node<T> *value)
{
    if (parent == NULL)
        return;
    parent->head = value;
}

template <typename T>
void push_node(tree<T> *parent, T value)
{
    if (parent == NULL)
        return;
    node<T> *child = create_node<T>(value);
    push_node(parent, child);
}

template <typename T>
void stroll(tree<T> *parent)
{
    if (parent == NULL)
        return;
    stroll(parent->head, 1);
}

// should not exceed jump longer that 3?
template <typename T>
void stroll(node<T> *parent, int depth)
{
    if (depth % 2 == 0)
    {
        // PROCESS NODE
        cout << parent->value << endl;
    }
    node<T> *child = parent->lowerNode;
    bool wasPrinted = depth % 2 == 0;
    while (child != NULL)
    {
        stroll(child, depth + 1);
        if (!wasPrinted)
        {
            // PROCESS NODE
            cout << parent->value << endl;
            wasPrinted = true;
        }
        child = child->nextNode;
    }
    if (!wasPrinted)
    {
        // PROCESS NODE
        cout << parent->value << endl;
        wasPrinted = true;
    }
}

int main()
{
    tree<int> *test = create_tree<int>();
    push_node(test, 1);
    push_node(test->head, 2);
    push_node(test->head, 3);
    push_node(test->head, 4);
    push_node(test->head->lowerNode, 5);
    push_node(test->head->lowerNode, 6);
    push_node(test->head->lowerNode->nextNode, 7);
    push_node(test->head->lowerNode->nextNode, 8);
    push_node(test->head->lowerNode->nextNode->nextNode, 9);
    push_node(test->head->lowerNode->nextNode->nextNode, 10);
    stroll(test);
}