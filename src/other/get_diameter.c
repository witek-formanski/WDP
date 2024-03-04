typedef struct node* bin_tree;

struct node {
    int val;
    bin_tree left, right;
};

int get_height(bin_tree t, int* maxx) {
    if(!t) 
        return;

    int left = 0, right = 0;

    left = get_height(t->left, &maxx);
    right = get_height(t->left, &maxx);

    *maxx = max(*maxx, left + right);

    return max(left, right) + 1;
}

int get_diameter(bin_tree t) {
    int maxx = 0;
    int temp = get_height(t, &maxx);
    return temp;
}