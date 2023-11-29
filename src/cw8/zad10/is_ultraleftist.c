#include <stdbool.h>

typedef struct node* bin_tree;

struct node {
    int val;
    bin_tree left, right;
};

bool is_ultraleftist(bin_tree t, int depth, int* depth_last) {
    if (!t) return true;

    if (!t->left && !t->right) {
        if (*depth_last < depth)
            return false;

        *depth_last = depth;
        return true;
    }

    return is_ultraleftist(t->left, depth + 1, depth_last) 
        && is_ultraleftist(t->right, depth + 1, depth_last);
}