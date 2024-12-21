/*
    Author: Jan Kwiecinski
    O(n) time complexity
    O(h) memory complexity, due to the recurrence stack
    (where h is the height of the tree)
*/
#include <iostream>
typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right, next;
    
    //constructor defined for testing, cannot be used in the task
    node(int _val, bin_tree _left, bin_tree _right) : val(_val), left(_left), right(_right) {}
};

void recurrent_solve(bin_tree t, bin_tree& curr_ptr, bin_tree& prev_ptr)
{
    if (t->right) recurrent_solve(t->right, curr_ptr, prev_ptr);
    
    if (curr_ptr != NULL && t->val != curr_ptr->val) prev_ptr = curr_ptr;
    curr_ptr = t;
    t->next = prev_ptr;

    if (t->left) recurrent_solve(t->left, curr_ptr, prev_ptr);
}

void fastryguj(bin_tree t)
{
    if (t == NULL) return;
    bin_tree curr_ptr = NULL; bin_tree prev_ptr = NULL;
    recurrent_solve(t, curr_ptr, prev_ptr);
}


#include <vector>
#include <assert.h>
void unit_test()
{
    std::vector <bin_tree> T(10, NULL);
    T[9] = new node(10, NULL, NULL);
    T[8] = new node(8, NULL, NULL);
    T[7] = new node(3, NULL, NULL);
    T[6] = new node(1, NULL, NULL);
    T[5] = new node(5, T[7], T[8]);
    T[4] = new node(3, NULL, NULL);
    T[3] = new node(1, NULL, T[6]);
    T[2] = new node(8, T[5], T[9]);
    T[1] = new node(2, T[3], T[4]);
    T[0] = new node(3, T[1], T[2]);

    fastryguj(T[0]);

    assert(T[9]->next == NULL);
    assert(T[8]->next == T[9]);
    assert(T[7]->next == T[5]);
    assert(T[6]->next == T[1]);
    assert(T[5]->next == T[8]);
    assert(T[4]->next == T[5]);
    assert(T[3]->next == T[1]);
    assert(T[2]->next == T[9]);
    assert(T[1]->next == T[4]);
    assert(T[0]->next == T[5]);

}

int main() {unit_test();}