typedef struct node* bin_tree;

struct node {
    int val;
    bin_tree left, right;
};

// policz rozmiar drzewa: int size

// przejdź przez drzewo postorderem