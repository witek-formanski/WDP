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
SingleNode<T>* make_cyclic_reversed_list(OneWayList<T>* originalList)
{
    if (originalList == NULL)
        return NULL;
    if (originalList->head == NULL)
        return originalList->head;

    SingleNode<T>* begginning = originalList->head;
    SingleNode<T>* previous = originalList->head;
    SingleNode<T>* current = originalList->head->next;

    while(current != NULL){
        SingleNode<T>* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    begginning->next = previous;
    return begginning;
}

template <typename T>
void print_elems(SingleNode<T>* cycle, int count){
    SingleNode<T>* current = cycle;
    for(int i = 1; i<=count; i++){
        cout<<i<<". "<<current->value<<endl;
        current = current->next;
    }
}

int main(){
    OneWayList<int>* createList = create_new_one_way_list<int>();
    createList->head = create_single_node(0);
    createList->head->next = create_single_node(1);
    createList->head->next->next = create_single_node(2);
    createList->head->next->next->next = create_single_node(3);
    createList->head->next->next->next->next = create_single_node(4);

    cout<<"Original"<<endl;
    print_elems(createList->head, 5);

    SingleNode<int>* cyclic = make_cyclic_reversed_list<int>(createList);
    // print cycle 2 tmes
    cout<<endl<<"Cyclic"<<endl;
    print_elems(cyclic, 2*5);
    return 0;
}