#include<stdio.h>
#include<stdlib.h>
#include<stack>

typedef struct node *bin_tree;
struct node {
    int val;
    bin_tree left, right;
};

typedef struct _walk {
    bin_tree current;
    std::stack<bin_tree> parents;
} walk;

walk make_walk(bin_tree t){
    return {t, {}};
}

void go_left(walk &w){
    if(w.current && w.current->left){
        w.parents.push(w.current);
        w.current = w.current->left;
    }
}

void go_right(walk &w){
    if(w.current && w.current->right){
        w.parents.push(w.current);
        w.current = w.current->right;
    }
}

void go_up(walk &w){
    if(!w.parents.empty()){
        w.current = w.parents.top();
        w.parents.pop();
    }
}

int lookup(walk &w){
    return w.current->val;
}

bin_tree newNode(int val){
    bin_tree nowy = (node*)malloc(sizeof(node));
    nowy->val = val;
    nowy->left = nowy->right = NULL;
    return nowy;
}

int main(){
    bin_tree t = newNode(1);
    t->left = newNode(2);
    t->left->left = newNode(4);
    t->left->left->left = newNode(5);
    t->right = newNode(3);
    t->right->left = newNode(6);
    t->right->right = newNode(7);

    t->left->right = newNode(11);
    t->right->left->right = newNode(12);

    walk w = make_walk(t);
    go_left(w);
    go_left(w);
    go_left(w);
    go_right(w);
    printf("%i\n", lookup(w));
    go_up(w);
    printf("%i\n", lookup(w));
    go_up(w);
    printf("%i\n", lookup(w));

    return 0;
}