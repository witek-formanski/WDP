/*
policz węzły drzewa które mają tyle samo kroków do korzenia 
co do najgłębszego liścia
*/

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

typedef struct bin_tree bin_tree;

struct bin_tree {
    int data;
    bin_tree* left;
    bin_tree* right;
};

int count_symmetrical(bin_tree *t, int depth, int* max_depth) {
    if (!t) {
        *max_depth = -1;
        return 0;
    }
    
    int max_depth_left, max_depth_right, count = 0;
    count += count_symmetrical(t->left, depth+1, &max_depth_left);
    count += count_symmetrical(t->right, depth+1, &max_depth_right);
    
    *max_depth = 1 + max(max_depth_left, max_depth_right);
    if (*max_depth == depth) ++count;
    return count;
}