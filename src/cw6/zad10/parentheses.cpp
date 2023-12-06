/*
T(n) = O(n)
M(n) = O(n)

    (   )   )   (   )   (   (   (   (   (   )   (   )   (   )   )   )   (   )   (   )   (   )   (   (   (   )
->  1   1   0   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
<-  1   1   1   1   1   0   0   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   0   0   1   1
 =  1   1   0   1   1   0   0   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   0   0   1   1
*/

#include <vector>
#include <algorithm>
#include <cstring>

void find_incorrect(char arr[], int i, int* count, std::vector<bool>* is_correct, char start, char end) {
    if (arr[i] == start) (*count)++;
    else if (arr[i] == end) {
        if (*count == 0) (*is_correct)[i] = false;
        else (*count)--;
    }
}

int get_longest_parentheses_expression(const std::vector<bool> is_correct) {
    int count = 0, max_count = 0;
    for (bool el : is_correct) {
        if (el) {
            count++;
            max_count = std::max(count, max_count);
        }
        else count = 0;
    }

    return max_count;
}

int parentheses(char arr[]) {
    int size = strlen(arr);
    std::vector<bool> is_correct(size, true);

    int open_parentheses_count = 0;
    for (int i = 0; i < size; i++) 
        find_incorrect(arr, i, &open_parentheses_count, &is_correct, '(', ')');
    
    open_parentheses_count = 0;
    for (int i = size - 1; i >= 0; i--) 
        find_incorrect(arr, i, &open_parentheses_count, &is_correct, ')', '(');

    return get_longest_parentheses_expression(is_correct);
}

#include <iostream>

int main() {
    char input[] = "(())";
    std::cout << parentheses(input);
}