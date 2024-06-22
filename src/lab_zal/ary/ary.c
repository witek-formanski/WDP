#include "ary.h"
#include <math.h>
#include <stdlib.h>
#include <string.h> // memcpy()
#include <float.h>

bool is_plus_infinity(double x) {
    return (isinf(x) && x > 0);
}

bool is_minus_infinity(double x) {
    return (isinf(x) && x < 0);
}

bool are_equal(double x, double y) {
    if ((is_plus_infinity(x) && is_plus_infinity(y)) || (is_minus_infinity(x) && is_minus_infinity(y)))
        return true;
    
    return (fabs(x - y) < DBL_EPSILON);
}

wartosc new_interval(int n) {
    wartosc w;
    w.n = n;
    w.t = (double *)malloc((size_t)w.n * sizeof(double));

    return w;
}

wartosc wartosc_od_do(double x, double y) { // x <= y
    if (isnan(x) || isnan(y)) 
        return new_interval(0);

    wartosc w = new_interval(2);
    w.t[0] = x;
    w.t[1] = y;

    return w;
}

wartosc construct(double x, double y) {
    return (x <= y) ? wartosc_od_do(x, y) : wartosc_od_do(y, x);
}

wartosc wartosc_dokladnosc(double x, double p) { // p > 0
    return construct(x * (1.0 - (p / 100.0)), x * (1.0 + (p / 100.0)));
}

wartosc concatenate(int n, double arr[]) { // create one interval from n points
    double minimum = HUGE_VAL;
    double maximum = -HUGE_VAL;

    for (int i = 0; i < n; i++) {
        minimum = fmin(arr[i], minimum);
        maximum = fmax(arr[i], maximum);
    }

    return wartosc_od_do(minimum, maximum);
}

wartosc wartosc_dokladna(double x) {
    return wartosc_od_do(x, x);
}

bool in_wartosc(wartosc w, double x) {
    for (int i = 0; i < w.n; i += 2)
        if (x >= w.t[i] - DBL_EPSILON && x <= w.t[i + 1] + DBL_EPSILON)
            return true;

    return false;
}

double min_wartosc(wartosc w) {
    return (w.n == 0) ? NAN : w.t[0];
}

double max_wartosc(wartosc w) {
    return (w.n == 0) ? NAN : w.t[w.n - 1];
}

double sr_wartosc(wartosc w) {
    return (w.n == 0 || (is_minus_infinity(w.t[0]) && is_plus_infinity(w.t[w.n - 1])))
        ? NAN
        : (w.t[0] + w.t[w.n - 1]) / 2.0;
}

void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);
    if (temp) {
        memcpy(temp, a, size);
        memcpy(a, b, size);
        memcpy(b, temp, size);
        free(temp);
    }
}

void bubble_sort(double *points, int *labels, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (points[j] > points[j + 1]) {
                swap(&points[j], &points[j + 1], sizeof(double));
                swap(&labels[j], &labels[j + 1], sizeof(int));
            }
}

void resize(wartosc *w, int k) {
    w->n = k;
    w->t = realloc(w->t, (size_t)(w->n) * sizeof(double));
}

wartosc merge(wartosc a, wartosc b) { // merge two intervals into one
    if (a.n == 0) return b;
    if (b.n == 0) return a;

    wartosc w = new_interval(a.n + b.n);
    double *points = (double *)malloc((size_t)w.n * sizeof(double)); // all beginnings and ends from intervals a and b
    int *labels = (int *)malloc((size_t)w.n * sizeof(int)); // 1 for corresponding (having the same index in points[]) beginning and 0 for end

    for (int i = 0; i < a.n; i++) {
        points[i] = a.t[i];
        labels[i] = (i % 2 == 0);
    }

    for (int i = 0; i < b.n; i++) {
        points[i + a.n] = b.t[i];
        labels[i + a.n] = (i % 2 == 0);
    }

    bubble_sort(points, labels, w.n); // sort points[] in nondecreasing order and modify lables[] accordingly

    double prev = points[0]; // previously set beginning of the interval
    bool is_prev_set = false;
    int j = 1; // counter of intervals currently being merged
    int k = 0; // index of final sum of intervals

    for (int i = 1; i < w.n; i++) {// iterate over the "axis" and skip intervals contained in others
        if (!is_prev_set && labels[i - 1] == 1) {
            prev = points[i - 1];
            is_prev_set = true;
        }

        (labels[i] == 1) ? j++ : j--; // counter incremented for beginning and decremented for end of an interval

        if (j == 0) { 
            if (k > 0 && are_equal(w.t[k - 1], prev))
                w.t[k - 1] = points[i];
            else {
                w.t[k] = prev;
                w.t[k + 1] = points[i];
                k += 2;
            }

            is_prev_set = false;
        }
    }

    resize(&w, k);
    free(points);
    free(labels);
    return w;
}

wartosc plus(wartosc a, wartosc b) {
    wartosc w = new_interval(0);
    double x, y;

    for (int i = 0; i < a.n; i += 2)
        for (int j = 0; j < b.n; j += 2) {
            x = a.t[i] + b.t[j];
            y = a.t[i + 1] + b.t[j + 1];

            w = merge(w, construct(x, y));
        }

    return w;
}

wartosc minus(wartosc a, wartosc b) {
    wartosc w = new_interval(0);
    double x, y;

    for (int i = 0; i < a.n; i += 2)
        for (int j = 0; j < b.n; j += 2) {
            x = a.t[i] - b.t[j + 1];
            y = a.t[i + 1] - b.t[j];

            w = merge(w, construct(x, y));
        }

    return w;
}

wartosc razy(wartosc a, wartosc b) {
    if ((a.n == 2 && are_equal(a.t[0], 0) && are_equal(a.t[1], 0)) || (b.n == 2 && are_equal(b.t[0], 0) && are_equal(b.t[1], 0)))
        return wartosc_dokladna(0);

    wartosc w = new_interval(0);
    for (int i = 0; i < a.n; i += 2)
        for (int j = 0; j < b.n; j += 2) {
            double arr[4] = {
                a.t[i] * b.t[j],
                a.t[i] * b.t[j + 1],
                a.t[i + 1] * b.t[j],
                a.t[i + 1] * b.t[j + 1]
            };

            w = merge(w, concatenate(4, arr));
        }

    return w;
}

wartosc podzielic(wartosc a, wartosc b) {
    wartosc w = new_interval(0);

    for (int i = 0; i < a.n; i += 2)
        for (int j = 0; j < b.n; j += 2) {
            if (are_equal(b.t[j], 0) && are_equal(b.t[j + 1], 0))
                continue;

            else if (b.t[j] < 0 && b.t[j + 1] > 0) { // if an interval contains both-sided neighbourhood of 0, split it into two
                wartosc dividend = wartosc_od_do(a.t[i], a.t[i + 1]);
                w = merge(w, podzielic(dividend, wartosc_od_do(b.t[j], -0.0)));
                w = merge(w, podzielic(dividend, wartosc_od_do(0.0, b.t[j + 1])));
            }

            else {
                double divisor_left = are_equal(b.t[j], 0) ? 0.0 : b.t[j]; // get rid of -0.0 in non-negative interval
                double divisor_right = are_equal(b.t[j + 1], 0) ? -0.0 : b.t[j + 1]; // replace 0.0 with -0.0 in negative interval
                double arr[4] = {
                    a.t[i] / divisor_left,
                    a.t[i] / divisor_right,
                    a.t[i + 1] / divisor_left,
                    a.t[i + 1] / divisor_right
                };
                w = merge(w, concatenate(4, arr));
            }
        }

    return w;
}