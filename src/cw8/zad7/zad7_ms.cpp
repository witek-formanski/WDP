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
int find_depth_recursively(tree<T> *tree, node<T> *node)
{
    if (tree == NULL || node == NULL)
        return -1;
    if (tree->head == node)
        return 0;
    return find_depth_recursively(tree->head, node, 1);
}

template <typename T>
int find_depth_recursively(node<T> *head, node<T> *seekdNode, unsigned int currentDepth)
{
    if (head == NULL || seekdNode == NULL)
        return -1;
    node<T>* child = head->lowerNode;
    while (child != NULL)
    {
        if (child == seekdNode)
            return currentDepth;

        unsigned int results = find_depth_recursively(child, seekdNode, currentDepth + 1);
        if (results != -1)
            return results;
        child = child->nextNode;
    }
    return -1;
}

template <typename T>
unsigned int find_children_count_recursively(tree<T> *tree)
{
    if (tree == NULL || tree->head == NULL)
        return 0;
    return 1 + find_children_count_recursively(tree->head);
}

template <typename T>
unsigned int find_children_count_recursively(node<T> *parent)
{
    if (parent == NULL)
        return 0;
    node<T>* child = parent->lowerNode;
    unsigned int childrenCount = 0;
    while (child != NULL)
    {
        childrenCount += 1 + find_children_count_recursively(child);
        child = child->nextNode;
    }
    return childrenCount;
}

template <typename T>
void prefix_order(tree<T> *parent)
{
    if (parent == NULL)
        return;
    prefix_order(parent->head);
}

template <typename T>
void prefix_order(node<T> *parent)
{
    if (parent == NULL)
        return;
    // DO SOMETHING
    cout << parent->value << endl;
    node<T> *child = parent->lowerNode;
    while (child != NULL)
    {
        prefix_order(child);
        child = child->nextNode;
    }
}

template <typename T>
void suffix_order(tree<T> *parent)
{
   if (parent == NULL)
        return;
    suffix_order(parent->head);
}

template <typename T>
void suffix_order(node<T> *parent)
{
        if (parent == NULL)
        return;
    node<T> *child = parent->lowerNode;
    while (child != NULL)
    {
        prefix_order(child);
        child = child->nextNode;
    }

    // DO SOMETHING
    cout << parent->value << endl;
}

int main()
{
    tree<int> *test = create_tree<int>();
    push_node(test, 1);
    push_node(test->head, 2);
    push_node(test->head, 3);
    push_node(test->head->lowerNode, 4);
    push_node(test->head->lowerNode->nextNode, 5);

    cout << "PREORDER" << endl;
    prefix_order(test);
    cout << endl
         << "POSTORDER" << endl;
    suffix_order(test);
    cout << "Nodes count: " << find_children_count_recursively(test) << endl;
    cout << "Depth of node with '5' as value: " << find_depth_recursively(test, test->head->lowerNode->nextNode->lowerNode) << endl;
}