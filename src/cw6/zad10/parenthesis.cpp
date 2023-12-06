// zad. 10 nawiasy

/*
(   )   )   (   )   (   (   (   (   (   )   (   )   (   )   )   )   (   )   (   )   (   )   (   (   (   )
1   1   0   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1
1   1   1   1   1   0   0   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   1   0   0   1   1
*/

#include <vector>
#include <stack>

// typedef 

int parenthesis(char arr[]) {
    int size = sizeof(arr) / sizeof(char);
    std::vector<bool> is_correct(size, true);
    // std::stack<enum
    int open_parenthesis = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == '(') open_parenthesis++;
        else if (arr[i] == ')') {
            if (open_parenthesis == 0) {
                is_correct[i] = false;
            } else {
                open_parenthesis--;
            }
        }
    }

}






