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
    cout << (list->head) << endl;
    SingleNode<T> *currentElem = list->head;
    while (currentElem != NULL)
    {
        cout << currentElem << " | " << currentElem->value << " " << (currentElem->next) << endl;
        currentElem = currentElem->next;
    }
}

template <typename T>
void push_back(OneWayList<T> *originalList, SingleNode<T>* node)
{
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
void push_back(OneWayList<T> *originalList, T value)
{
    push_back(originalList, create_single_node(value));
}

template <typename T>
OneWayList<T> *find_union(OneWayList<T> *listA, OneWayList<T> *listB)
{
    if (listA == NULL || listB == NULL)
        return NULL;
    int posA = 0, posB = 0;
    SingleNode<T> *jumperA = listA->head;
    SingleNode<T> *jumperB = listB->head;
    while (jumperA != jumperB)
    {
        if (jumperA != NULL)
        {
            jumperA = jumperA->next;
            posA++;
        }
        if (jumperB != NULL)
        {
            jumperB = jumperB->next;
            posB++;
        }
    }

    if (posA != posB)
    {
        // both pointers are pointing to NULL
        jumperA = listA->head;
        jumperB = listB->head;
        while(posA>posB){
            jumperA = jumperA->next;
            posA--;
        }
        while(posB>posA){
            jumperB = jumperB->next;
            posB--;
        }
        while(jumperA != jumperB){
            jumperA = jumperA->next;
            jumperB = jumperB->next;
        }
    }

    OneWayList<T> *commonList = create_new_one_way_list<T>();
    commonList->head = jumperA;
    return commonList;
}

int main(){
    OneWayList<int>* listA = create_new_one_way_list<int>();
    push_back(listA, 1);
    push_back(listA, 3);
    push_back(listA, 5);

    OneWayList<int>* listB = create_new_one_way_list<int>();
    push_back(listB, 2);
    push_back(listB, 4);

    OneWayList<int>* common = create_new_one_way_list<int>();
    push_back(common,6);
    push_back(common,7);
    push_back(common,8);
    push_back(common,9);
    
    // connect
    push_back(listA, common->head);
    push_back(listB, common->head);

    OneWayList<int>* foundCommon = find_union(listA, listB);
    print_list(foundCommon);
}