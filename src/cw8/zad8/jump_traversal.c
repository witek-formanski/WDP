typedef struct bin_tree bin_tree;

struct bin_tree {
    int data;
    bin_tree* left;
    bin_tree* right;
};

void visit(bin_tree *t) {}

void jump_traversal(bin_tree *t, int depth_mod2) {
    if (!t) return;

    if (depth_mod2) visit(t);
    jump_traversal(t->left, 1 - depth_mod2);
    jump_traversal(t->right, 1 - depth_mod2);
    if (!depth_mod2) visit(t);
}

int main() {
    bin_tree t;
    jump_traversal(&t, 0);
}