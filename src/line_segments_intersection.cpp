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

int which_side_of_line(line_segment line_seg, int xp, int yp)
{
    int a, b, c;
    line(line_seg, &a, &b, &c);
    int aux = a*xp + b*yp + c; //zmienna pomocnicza (auxiliary variable)
    return (aux > 0) ? 1 : (!aux ? 0 : -1);
}



