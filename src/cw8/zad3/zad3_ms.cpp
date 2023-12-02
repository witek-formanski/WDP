#include <iostream>

using namespace std;

template <typename T>
struct SingleNode
{
    T value;
    SingleNode<T> *next;
};

template <typename T>
struct OneWayList
{
    SingleNode<T> *head;
};

template <typename T>
OneWayList<T> *create_new_one_way_list()
{
    OneWayList<T> *newList = (OneWayList<T> *)malloc(sizeof(OneWayList<T>));
    newList->head = NULL;
    return newList;
}

template <typename T>
SingleNode<T> *create_single_node(T value)
{
    SingleNode<T> *newNode = (SingleNode<T> *)malloc(sizeof(SingleNode<T>));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

template <typename T>
void print_list(OneWayList<T> *list)
{
    cout << "head adress" << endl;
    cout  << (list->head) << endl;
    SingleNode<T> *currentElem = list->head;
    while (currentElem != NULL)
    {
        cout << currentElem << " | " << currentElem->value << " " << (currentElem->next) << endl;
        currentElem = currentElem->next;
    }
}

template <typename T>
OneWayList<T> *shuffle(OneWayList<T> *listA, OneWayList<T> *listB)
{
    SingleNode<T> *nodeA = NULL, *nodeB = NULL;
    if (listA != NULL)
    {
        nodeA = listA->head;
    }
    if (listB != NULL)
    {
        nodeB = listB->head;
    }
    bool shouldPutNodeA = true;
    OneWayList<T>* shuffledList = create_new_one_way_list<T>();
    SingleNode<T> **placeForNewNode = &(shuffledList->head);
    while (nodeA != NULL && nodeB != NULL)
    {
        if (shouldPutNodeA)
        {
            *placeForNewNode = nodeA;
            nodeA = nodeA->next;
        }
        else
        {
            *placeForNewNode = nodeB;
            nodeB = nodeB->next;
        }
        placeForNewNode = &((*placeForNewNode)->next);
        shouldPutNodeA = !shouldPutNodeA;
    }

    if (nodeA == NULL)
        nodeA = nodeB;
    while (nodeA != NULL)
    {
        *placeForNewNode = nodeA;
        nodeA = nodeA->next;
        placeForNewNode = &((*placeForNewNode)->next);
    }
    return shuffledList;
}

template <typename T>
void push_back(OneWayList<T> *originalList, T value)
{
    SingleNode<T> *node = create_single_node(value);

    // find last elem's adress
    SingleNode<T> **lastNode = &(originalList->head);
    while (*lastNode != NULL)
    {
        lastNode = &((*lastNode)->next);
    }
    // put adress of node in the .next of current last elem
    (*lastNode) = node;
}

int main()
{
    OneWayList<int> *listA = create_new_one_way_list<int>();
    push_back(listA, 1);
    push_back(listA, 3);
    push_back(listA, 5);
    push_back(listA, 6);

    OneWayList<int> *listB = create_new_one_way_list<int>();
    push_back(listB, 2);
    push_back(listB, 4);

    OneWayList<int>* shuffledList = shuffle(listA,listB);
    print_list(shuffledList);
}