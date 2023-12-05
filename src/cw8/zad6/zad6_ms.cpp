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
// let: elemInCycle is in cycle
int count_length(SingleNode<T> *elemInCycle)
{
    int length = 1;
    SingleNode<T> *runner = elemInCycle->next;
    while (runner != elemInCycle)
    {
        length++;
        runner = runner->next;
    }
    return length;
}

template <typename T>
int cycle_length(OneWayList<T> *list)
{
    if (list == NULL || list->head == NULL)
        return false;

    SingleNode<T> *runnerA = list->head;
    SingleNode<T> *runnerB = runnerA->next;

    while (runnerA && runnerB)
    {
        if (runnerA == runnerB)
        {
            // list has cycle
            return count_length(runnerA);
        }
        // move runnerA by 1
        runnerA = runnerA->next;

        // move runnerB by 2
        if (runnerB->next == NULL)
            break;
        runnerB = runnerB->next->next;
    }
    return 0;
}

template <typename T>
void print_elems(SingleNode<T> *cycle, int count)
{
    SingleNode<T> *current = cycle;
    for (int i = 1; i <= count; i++)
    {
        cout << i << ". " << current->value << endl;
        current = current->next;
    }
}

int main()
{
    OneWayList<int> *createList = create_new_one_way_list<int>();
    createList->head = create_single_node(0);
    createList->head->next = create_single_node(1);
    createList->head->next->next = create_single_node(2);
    createList->head->next->next->next = create_single_node(3);
    createList->head->next->next->next->next = create_single_node(4);
    // when no cycle
    //     cout << "List" << endl;
    // print_elems(createList->head, 5);

    // create cycle
    createList->head->next->next->next->next->next = createList->head->next->next;
        cout << "List" << endl;
    print_elems(createList->head, 5 + 4);

    int length = cycle_length(createList);
    cout << "Length of cycle is: " << length << endl;
}