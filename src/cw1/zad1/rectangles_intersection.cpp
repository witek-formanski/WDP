#include <iostream>

struct rectangle {
    int x1;
    int x2;
    int y1;
    int y2;

    rectangle(int a1, int a2, int b1, int b2) {
        x1 = a1;
        x2 = a2;
        y1 = b1;
        y2 = b2;
    }
};

// podproblem: przecięcie odcinków na osiach OX i OY

int max(int a, int b) { return (a > b) ? a : b; };

int min(int a, int b) { return (a < b) ? a : b; };

// założenie: wszystkie prostokąty są w pierwszej ćwiartce układu współrzędnych
// odcinki: A: (a1,0)->(a2,0) i B: (b1,0)->(b2,0) to rzuty prostokątów na osie

bool do_line_segments_intersect(int a1, int a2, int b1, int b2,
                                int* common_part_min, int* common_part_max) {
    *common_part_min = max(a1, b1);
    *common_part_max = min(a2, b2);

    return (*common_part_min <= *common_part_max);
}

bool do_rectangles_intersect(rectangle rectangle_a, rectangle rectangle_b,
                             int* common_min_x, int* common_max_x,
                             int* common_min_y, int* common_max_y) {
    bool does_x_intersect = do_line_segments_intersect(
        rectangle_a.x1, rectangle_a.x2, rectangle_b.x1, rectangle_b.x2,
        common_min_x, common_max_x);
    bool does_y_intersect = do_line_segments_intersect(
        rectangle_a.y1, rectangle_a.y2, rectangle_b.y1, rectangle_b.y2,
        common_min_y, common_max_y);

    return (does_x_intersect && does_y_intersect);
}

// ToDo: test if it works and run on some examples

int main() {
    int xa1, xa2, ya1, ya2, xb1, xb2, yb1, yb2;
    std::cin >> xa1 >> xa2 >> ya1 >> ya2 >> xb1 >> xb2 >> yb1 >> yb2;
    auto rectangle_a = rectangle(xa1, xa2, ya1, ya2);
    auto rectangle_b = rectangle(xb1, xb2, yb1, yb2);
    int common_part_min_x, common_part_max_x, common_part_min_y,
        common_part_max_y;

    if (do_rectangles_intersect(rectangle_a, rectangle_b, &common_part_min_x,
                                &common_part_max_x, &common_part_min_y,
                                &common_part_max_y)) {
        std::cout << "true\n";
        std::cout << common_part_min_x << " " << common_part_max_x << " "
                  << common_part_min_y << " " << common_part_max_y;
        return 0;
    }
    std::cout << "false";
    return 0;
}