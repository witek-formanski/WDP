#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node *bin_tree;
struct node
{
    int val;
    bin_tree left, right;
};

typedef struct pt *walk;
struct pt
{
    bin_tree *previous;
    int size;
    int index;

    bin_tree current;
};

bin_tree new_node(int val)
{
    bin_tree node = (bin_tree)(malloc(sizeof(int) + 2 * sizeof(bin_tree)));
    node->val = val;
    return node;
}

walk make_walk(bin_tree t)
{
    if (t == NULL)
        return NULL;
    walk pt = (walk)malloc(sizeof(bin_tree) + sizeof(bin_tree *) + 2 * sizeof(int));
    pt->current = t;
    pt->index = -1;
    pt->size = 2;
    pt->previous = (bin_tree *)(malloc((size_t)pt->size * sizeof(bin_tree)));
    return pt;
}

void end_walk(walk w)
{
    if (!w)
        return;
    free(w->previous);
    free(w);
}

void go_down(walk w, bool goLeft)
{
    if (w == NULL)
        return;
    if (w->current == NULL)
        return;

    bin_tree direction = NULL;
    if (goLeft)
        direction = w->current->left;
    else
        direction = w->current->right;
    if (direction == NULL)
        return;

    if (w->index + 1 >= w->size)
    {
        w->previous = (bin_tree *)realloc(w->previous, (w->size) * 2 * sizeof(bin_tree));
    }
    w->previous[w->index + 1] = w->current;
    w->current = direction;
    w->index++;
}

void go_up(walk w)
{
    if (w == NULL)
        return;
    if (w->current == NULL)
        return;
    if (w->index < 0)
        return;
    w->current = w->previous[w->index];
    w->previous[w->index] = NULL;
    w->index--;
    if (w->index < w->size / 2)
    {
        w->previous = (bin_tree *)realloc(w->previous, (w->size) / 2 * sizeof(bin_tree));
    }
}

void go_left(walk w)
{
    go_down(w, true);
}

void go_right(walk w)
{
    go_down(w, false);
}

int lookup(const walk w)
{
    if (w == NULL || w->current == NULL)
        // throw exception but i dunno how
        return 0;
    return w->current->val;
}

int main()
{
    bin_tree t = new_node(10);
    t->left = new_node(5);
    t->left->right = new_node(15);
    t->right = new_node(14);

    walk w = make_walk(t);
    printf("Top: %d\n", lookup(w));
    go_left(w);
    printf("Left: %d\n", lookup(w));
    go_right(w);
    printf("Right: %d\n", lookup(w));
    go_up(w);
    printf("Up: %d\n", lookup(w));
    go_right(w);
    printf("Right: %d\n", lookup(w));
    go_right(w);
    printf("Cannot go right: %d\n", lookup(w));
    go_left(w);
    printf("Cannot go left: %d\n", lookup(w));
    go_up(w);
    printf("Up: %d\n", lookup(w));
    go_up(w);
    printf("Top: %d\n", lookup(w));
    go_up(w);
    printf("Cannot go up: %d\n", lookup(w));
    go_right(w);
}
