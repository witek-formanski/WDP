// zad. 5 tablice

// assumption: there is a leader

int find_leader(int n, int t[]) {
    int candidate = t[0];
    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (t[i] == candidate) {
            ++count;
        } else {
            --count;
            if (!count) {
                candidate = t[i];
            }
        }
    }

    return candidate;
}