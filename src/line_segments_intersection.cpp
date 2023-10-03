#include<iostream>

// założenie: odcinki są domknięte (rozważamy końce)
// nie rozważamy zdegenerowanych odcinków (nie mogą być punktem)
//dziedzina algorytmiczna: Z, {0,1}

//odcinek (x1, x2, y1, y2) należy do Z^4
struct line_segment
{
    int x1;
    int x2;
    int y1;
    int y2;

    line_segment(int a1, int a2, int b1, int b2)
    {
        x1 = a1;
        x2 = a2;
        y1 = b1;
        y2 = b2;
    }
};

// obserwacja: dwa odcinki się przecinają, gdy końce jednego są po różnych stronach drugiego i vice versa

// przecięcie należy do {} lub Z^2 lub Z^4

// wyznaczamy równanie ogólne prostej na której leży pierwszy odcinek
// Ax + By + C = 0 - możemy założyć, że A, B, C należy do Z
// f(x, y) = Ax + By + C
// wystarczy sprawdzić znaki f(x1, y1), f(x2, y2)

void line(line_segment line_seg, int *a, int *b, int *c)
{
    *a = line_seg.y2 - line_seg.y1;
    *b = line_seg.x1 - line_seg.x2;
    *c = line_seg.x2 * line_seg.y1 - line_seg.x1 * line_seg.y2;
}

int which_side_of_line(line_segment line_seg, int x_point, int y_point) // 1 - above, 0 - on line, -1 - below
{
    int a, b, c;
    line(line_seg, &a, &b, &c);
    int aux = a*x_point + b*y_point + c; //zmienna pomocnicza (auxiliary variable)
    return (aux > 0) ? 1 : (!aux ? 0 : -1);
}

bool do_line_segments_intersect(line_segment line_segment_1, line_segment line_segment_2)
{
    int a1, b1, a2, b2;
    a1 = which_side_of_line(line_segment_2, line_segment_1.x1, line_segment_1.y1);
    b1 = which_side_of_line(line_segment_2, line_segment_1.x2, line_segment_1.y2);
    a2 = which_side_of_line(line_segment_1, line_segment_2.x1, line_segment_2.y1);
    b2 = which_side_of_line(line_segment_1, line_segment_2.x2, line_segment_2.y2);

    /*
    0 * ?  = 0              -> intersection
    1 * -1 = -1             -> intersection
    1 * 1 = -1 * -1 = 1     -> no intersection
    */
   return ((a1*b1 != 1) && (a2*b2 != 1));
}

int main()
{
    int xA1, yA1, xB1, yB1, xA2, yA2, xB2, yB2;
    std::cin >> xA1 >> yA1 >> xB1 >> yB1 >> xA2 >> yA2 >> xB2 >> yB2;
    auto line_segment_1 = line_segment(xA1, yA1, xB1, yB1);
    auto line_segment_2 = line_segment(xA2, yA2, xB2, yB2);

    std::cout << do_line_segments_intersect(line_segment_1, line_segment_2);

    return 0;
}



