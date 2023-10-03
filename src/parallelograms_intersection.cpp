/*
równoległobok:
podajemy trzy punkty: pierwszy punkt, dwa kolejne przeciwległe względem siebie
(czwarty punt jest przeciwległy względem pierwzego)
(x1, y1, x2, y2, x3, y3) należy do Z^6
*/
struct parallelogram
{
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;

    parallelogram(int a1, int b1, int a2, int b2, int a3, int b3)
    {
        x1 = a1;
        y1 = b1;
        x2 = a2;
        y2 = b2;
        x3 = a3;
        y3 = b3;
    }
};


/*
algorytm:
sprawdzić każdy punkt jednego równoległoboku leży wewnątrz drugiego równoległoboku i vice versa (8 sprawdzeń)
sprawdzić, czy przekątne się przecinają (4 sprawdzenia)
*/

// void c_coefficient_of_line(line_segment line_seg, int *c)
// {
//     *c = line_seg.x2 * line_seg.y1 - line_seg.x1 * line_seg.y2;
// }