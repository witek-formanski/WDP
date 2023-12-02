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
struct DoubleNode
{
    T value;
    DoubleNode<T> *previous;
    DoubleNode<T> *next;
};

template <typename T>
struct TwoWayList
{
    DoubleNode<T> *head;
    DoubleNode<T> *tail;
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
TwoWayList<T> *create_new_two_way_list()
{
    TwoWayList<T> *newList = (TwoWayList<T> *)malloc(sizeof(TwoWayList<T>));
    newList->tail = NULL;
    newList->head = NULL;
    return newList;
}

template <typename T>
DoubleNode<T> *create_double_node(T value)
{
    DoubleNode<T> *newNode = (DoubleNode<T> *)malloc(sizeof(DoubleNode<T>));
    newNode->value = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

// create new one way list with duplicated values:
// 3 2 -> 3 3 2 2
// free(old list)
template <typename T>
OneWayList<T> *duplicate_values(OneWayList<T> *originalList)
{
    if (originalList->head == NULL)
        return create_new_one_way_list<T>();
    OneWayList<T> *newList = create_new_one_way_list<T>();
    SingleNode<T> **lastNodeFromDuplicated = &(newList->head);
    SingleNode<T> **lastNodeFromOrigin = &(originalList->head);
    while (*lastNodeFromOrigin != NULL)
    {
        *lastNodeFromDuplicated = create_single_node((*lastNodeFromOrigin)->value);
        (*lastNodeFromDuplicated)->next = create_single_node((*lastNodeFromOrigin)->value);
        
        lastNodeFromDuplicated = &((*lastNodeFromDuplicated)->next->next);

        lastNodeFromOrigin = &((*lastNodeFromOrigin)->next);
    }
    free(originalList);
    return newList;
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

template <typename T>
void push_back(TwoWayList<T> *originalList, T value)
{
    DoubleNode<T> *node = create_double_node(value);
    if (originalList->head == NULL)
    {
        originalList->head = node;
        originalList->tail = node;
    }
    else
    {
        originalList->tail->next = node;
        node->previous = originalList->tail;
        originalList->tail = node;
    }
}

// create new two way list with duplicated values:
// 3 2 -> 3 3 2 2
// free(old list)
template <typename T>
TwoWayList<T> *duplicate_values(TwoWayList<T> *originalList)
{
    if (originalList->head == NULL)
        return create_new_two_way_list<T>();
    TwoWayList<T> *newList = create_new_two_way_list<T>();

    DoubleNode<T> **lastNodeFromOrigin = &(originalList->head);
    while (*lastNodeFromOrigin != NULL)
    {
        push_back(newList, (*lastNodeFromOrigin)->value);
        push_back(newList, (*lastNodeFromOrigin)->value);
        lastNodeFromOrigin = &((*lastNodeFromOrigin)->next);
    }
    free(originalList);
    return newList;
}

template <typename T>
void print_list(OneWayList<T> *list)
{
    cout << "head adress" << endl;
    cout << (list->head) << endl;
    SingleNode<T> *currentElem = list->head;
    while (currentElem != NULL)
    {
        cout << currentElem << " | " << currentElem->value << " " << (currentElem->next) << endl;
        currentElem = currentElem->next;
    }
}

template <typename T>
void print_list(TwoWayList<T> *list)
{
    cout << "head adress, tail adress" << endl;
    cout << (list->head) << ", " << (list->tail) << endl;
    DoubleNode<T> *currentElem = list->head;
    while (currentElem != NULL)
    {
        cout << currentElem << " | " << currentElem->previous << " " << currentElem->value << " " << currentElem->next << endl;
        currentElem = currentElem->next;
    }
}

void one_way_list_test()
{
    OneWayList<double> *list = create_new_one_way_list<double>();
    push_back(list, 3.0);
    push_back(list, 2.0);

    cout << "Normal:" << endl;
    print_list(list);
    cout << "Double:" << endl;
    print_list(duplicate_values(list));
}

void two_way_list_test()
{
    TwoWayList<double> *list = create_new_two_way_list<double>();
    push_back(list, 3.0);
    push_back(list, 2.0);

    cout << "Normal:" << endl;
    print_list(list);
    cout << "Double:" << endl;
    print_list(duplicate_values(list));
}

int main()
{
    cout << "one way" << endl
         << endl;
    one_way_list_test();
    cout << endl
         << "or another" << endl
         << endl;
    two_way_list_test();
    cout << endl
         << "I'm gonna find ya" << endl;
}