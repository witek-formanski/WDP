struct line_segment {
    int x1;
    int x2;
    int y1;
    int y2;

    line_segment(int a1, int a2, int b1, int b2) {
        x1 = a1;
        x2 = a2;
        y1 = b1;
        y2 = b2;
    }
};

int max(int a, int b) { return (a > b) ? a : b; };
