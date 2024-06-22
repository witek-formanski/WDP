#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define EPSILON 1.192093e-07

// define basic structers, their constructors and a few auxiliary functions

typedef struct point {
    double x, y;
} point;

point new_point(double x, double y) {
    return (point){.x = x, .y = y};
}

typedef struct {
    double A, B, C;  // used for reflection
    point P1, P2;    // used for determining the direction of a fold
} line;

line new_line(double A, double B, double C, point P1, point P2) {
    return (line){.A = A, .B = B, .C = C, .P1 = P1, .P2 = P2};
}

line get_line(point P1, point P2) {  // assumption: P1 != P2
    return new_line(P2.y - P1.y, P1.x - P2.x, P2.x * P1.y - P1.x * P2.y, P1, P2);
}

typedef struct {
    point P1, P2;
} rectangle;

rectangle new_rectangle(point P1, point P2) {
    return (rectangle){.P1 = P1, .P2 = P2};
}

typedef struct {
    double x, y, r;
} circle;

circle new_circle(double x, double y, double r) {
    return (circle){.x = x, .y = y, .r = r};
}

typedef union shape {  // OOP surrogate in C
    rectangle _rectangle;
    circle _circle;
} shape;

typedef struct {
    bool is_rectangle;
    shape _shape;
} shape_struct;

typedef union data {  // used in list
    line _line;
    point _point;
} data;

data new_data_point(point _point) {
    return (data){._point = _point};
}

data new_data_line(line _line) {
    return (data){._line = _line};
}

typedef struct node node;

struct node {
    data _data;
    node *prev;
    node *next;
};

typedef struct list {
    node *head;
    node *tail;
} list;

void init(list *_list) {
    _list->head = NULL;
    _list->tail = NULL;
}

void push_back(list *_list, data _data) {
    node *new_node = malloc(sizeof(node));
    new_node->_data = _data;
    new_node->next = NULL;

    if (_list->head == NULL) {
        new_node->prev = NULL;
        _list->head = new_node;
    } else {
        new_node->prev = _list->tail;
        _list->tail->next = new_node;
    }

    _list->tail = new_node;
}

void remove_node(node *_node, list *_list) {
    if (_node == _list->head && _node == _list->tail)
        init(_list);
    else if (_node == _list->head) {
        _list->head = _list->head->next;
        _list->head->prev = NULL;
    } else if (_node == _list->tail) {
        _list->tail = _list->tail->prev;
        _list->tail->next = NULL;
    } else {
        _node->next->prev = _node->prev;
        _node->prev->next = _node->next;
    }

    free(_node);
}

typedef struct {
    shape_struct shape;
    list folds;
} sheet;

sheet new_rectangle_sheet(point P1, point P2) {
    return (sheet){.shape = (shape_struct){.is_rectangle = true, ._shape._rectangle = new_rectangle(P1, P2)}};
}

sheet new_circle_sheet(double x, double y, double r) {
    return (sheet){.shape = (shape_struct){.is_rectangle = false, ._shape._circle = new_circle(x, y, r)}};
}

// core funtions

point reflect(line _line, point _point) {
    return new_point(
        _point.x - (2 * _line.A * (_line.A * _point.x + _line.B * _point.y + _line.C)) / (pow(_line.A, 2) + pow(_line.B, 2)),
        _point.y - (2 * _line.B * (_line.A * _point.x + _line.B * _point.y + _line.C)) / (pow(_line.A, 2) + pow(_line.B, 2)));
}

double get_position(line _line, point _point) {  // == 0 - on the line, > 0 - on the left
    double position = (_line.P2.x - _line.P1.x) * (_point.y - _line.P1.y) - (_line.P2.y - _line.P1.y) * (_point.x - _line.P1.x);
    return (position < EPSILON && position > -EPSILON) ? 0 : position;
}

bool is_puncture_in_rectangle(rectangle _rectangle, point _point) {
    return (_point.x >= _rectangle.P1.x) && (_point.y >= _rectangle.P1.y) && (_point.x <= _rectangle.P2.x) && (_point.y <= _rectangle.P2.y);
}

bool is_puncture_in_circle(circle _circle, point _point) {
    return sqrt(pow(_point.x - _circle.x, 2) + pow(_point.y - _circle.y, 2)) <= _circle.r;
}

bool is_puncture_in_shape(shape_struct _shape_struct, point _point) {
    return (_shape_struct.is_rectangle)
        ? is_puncture_in_rectangle(_shape_struct._shape._rectangle, _point)
        : is_puncture_in_circle(_shape_struct._shape._circle, _point);
}

int count_punctures(sheet *_sheet, point pin) {
    int count = 0;
    double position;
    list punctures;
    init(&punctures);

    push_back(&punctures, new_data_point(pin));

    node *fold = _sheet->folds.tail;
    node *puncture, *prev_puncture;
    while (fold != NULL) {
        puncture = punctures.tail;
        while (puncture != NULL) {
            position = get_position(fold->_data._line, puncture->_data._point);
            prev_puncture = puncture->prev;
            if (position > 0)
                push_back(&punctures, new_data_point(reflect(fold->_data._line, puncture->_data._point)));
            else if (position < 0)
                remove_node(puncture, &punctures);

            puncture = prev_puncture;
        }
        fold = fold->prev;
    }

    puncture = punctures.head;
    while (puncture != NULL) {
        if (is_puncture_in_shape(_sheet->shape, puncture->_data._point)) count++;
        puncture = puncture->next;
    }

    return count;
}

// handle input and output stream

sheet *get_sheets(int n) {
    sheet *sheets = (sheet *)malloc((size_t)n * sizeof(sheet));
    sheet folded_sheet;
    int k;
    char ch;
    double a, b, c, d;

    for (int i = 0; i < n; i++) {
        init(&sheets[i].folds);
        if (!scanf(" %c", &ch)) printf("invalid input\n");
        switch (ch) {
            case 'P':  // rectangle
                if (!scanf("%lf %lf %lf %lf", &a, &b, &c, &d)) printf("invalid input\n");
                sheets[i] = new_rectangle_sheet(new_point(a, b), new_point(c, d));
                break;
            case 'K':  // circle
                if (!scanf("%lf %lf %lf", &a, &b, &c)) printf("invalid input\n");
                sheets[i] = new_circle_sheet(a, b, c);
                break;
            case 'Z':  // fold
                if (!scanf("%d %lf %lf %lf %lf", &k, &a, &b, &c, &d)) printf("invalid input\n");
                folded_sheet = sheets[k - 1];
                push_back(&folded_sheet.folds, new_data_line(get_line(new_point(a, b), new_point(c, d))));
                sheets[i] = folded_sheet;
                break;
            default:
                printf("invalid input\n");
                break;
        }
    }

    return sheets;
}

int *get_answers(int q, sheet *sheets) {
    int *answers = (int *)malloc((size_t)q * sizeof(int));
    int k;
    double a, b;

    for (int i = 0; i < q; i++) {
        if (!scanf(" %d", &k)) printf("invalid input\n");
        if (!scanf("%lf %lf", &a, &b)) printf("invalid input\n");
        answers[i] = count_punctures(&sheets[k - 1], new_point(a, b));
    }

    return answers;
}

int main() {
    int n, q;
    if (!scanf("%d %d", &n, &q)) printf("invalid input\n");

    int *answers = get_answers(q, get_sheets(n));
    for (int i = 0; i < q; i++)
        printf("%d\n", answers[i]);

    free(answers);
}