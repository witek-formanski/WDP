// liczymy średnicę i zapamiętujemy najpłytszy wierzchołek
// postfiksowo szukamy miejsca, w którym głębokość jest równa d/2

typedef struct node* bin_tree;

struct node {
    int val;
    bin_tree left, right;
};

int get_diameter(bin_tree t) {
    return 0;
}

bin_tree get_middle(bin_tree t) {
    bin_tree *ans;
    find_middle_node(t, &ans, (get_diameter(t)+1)/2);
    return ans;
}

int find_middle_node(bin_tree t, bin_tree* ans, int n) { // n = (diam + 1) / 2
    if (!t) return 0;

    int l = find_middle_node(t->left, ans, n);
    int r = find_middle_node(t->right, ans, n);
    int m = max(l, r) + 1;
    if (m == n) *ans = t;
    return m;
}