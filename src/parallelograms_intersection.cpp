#include <iostream>

#include "common_library.h"

/*
równoległobok:
podajemy trzy punkty: pierwszy punkt, dwa kolejne przeciwległe względem siebie
(czwarty punkt jest przeciwległy względem pierwzego)
(x1, y1, x2, y2, x3, y3) należy do Z^6
*/
struct parallelogram {
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int x4;
    int y4;

    parallelogram(int a1, int b1, int a2, int b2, int a3, int b3) {
        x1 = a1;
        y1 = b1;
        x2 = a2;
        y2 = b2;
        x3 = a3;
        y3 = b3;
        x4 = x2 + x3 - x1;
        y4 = y2 + y3 - y1;
    }
};

// a*x + b*x + c = 0
struct line {
    int a;
    int b;
    int c;

    line(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    line(int x1, int y1, int x2, int y2)  // from two points
    {
        a = y1 - y2;
        b = x2 - x1;
        c = x1 * y2 - x2 * y1;
    }
};

/*
algorytm:
sprawdzić każdy punkt jednego równoległoboku leży wewnątrz drugiego
równoległoboku i vice versa (8 sprawdzeń) sprawdzić, czy przekątne się
przecinają (4 sprawdzenia)
*/

bool is_between_or_equal(int number, int extreme_1, int extreme_2) {
    return (number - extreme_1) * (number - extreme_2) <= 0;
}

line parallel_line_from_point(line parallel_line, int x_point, int y_point) {
    int c = -parallel_line.a * x_point - parallel_line.b * y_point;
    return line(parallel_line.a, parallel_line.b, c);
}

bool is_point_inside_parallelogram(parallelogram parallelogram, int x_point,
                                   int y_point) {
    int c_x_point, c_y_point;
    auto line_12 = line(parallelogram.x1, parallelogram.y1, parallelogram.x2,
                        parallelogram.y2);
    auto line_34 = line(parallelogram.x3, parallelogram.y3, parallelogram.x4,
                        parallelogram.y4);
    c_x_point = parallel_line_from_point(line_12, x_point, y_point).c;
    auto line_13 = line(parallelogram.x1, parallelogram.y1, parallelogram.x3,
                        parallelogram.y3);
    auto line_24 = line(parallelogram.x2, parallelogram.y2, parallelogram.x4,
                        parallelogram.y4);
    c_y_point = parallel_line_from_point(line_13, x_point, y_point).c;
    return is_between_or_equal(c_x_point, line_12.c, line_34.c) &&
           is_between_or_equal(c_y_point, line_13.c, line_24.c);
}

bool do_diagonals_intersect(line_segment diagonal_1, line_segment diagonal_2) {}

bool do_parallelograms_intersect(parallelogram parallelogram_a,
                                 parallelogram parallelogram_b) {}

int main() {
    int xa1, ya1, xa2, ya2, xa3, ya3, xb1, yb1, xb2, yb2, xb3, yb3;
    std::cin >> xa1 >> ya1 >> xa2 >> ya2 >> xa3 >> ya3 >> xb1 >> yb1 >> xb2 >>
        yb2 >> xb3 >> yb3;
    auto parallelogram_a = parallelogram(xa1, ya1, xa2, ya2, xa3, ya3);
    auto parallelogram_b = parallelogram(xb1, yb1, xb2, yb2, xb3, yb3);
    std::cout << do_parallelograms_intersect(parallelogram_a, parallelogram_b);
    return 0;
}