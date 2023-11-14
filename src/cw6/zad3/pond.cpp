#include <iostream>
#include <stack>
#include <cmath>

void freeze(std::stack<int> s, int degrees) {
    // int top = s.top();
    // s.pop();
    // if (top < 0) {
    //     int new_top = top + degrees;
    //     int second_top = s.top();
    // }
    int top;
    int next;
    while (!s.empty() && degrees != 0) {
        top = s.top();
        s.pop();
    }
}

void defrost(std::stack<int> s, int degrees) {
    int top;
    int next;
    int new_top;
    int new_next;
    while (!s.empty() && degrees != 0) {
        top = s.top();
        s.pop();
        if (std::abs(top + degrees) < std::abs(top)) {
            new_next = top + degrees;
            new_top = degrees;
            s.push(new_next);
            s.push(new_top);
        }
    }
}

int pond(int n, int t[]) {
    std::stack<int> s;
    s.push(INT_MAX);

    for (int i = 0; i < n; i++) {
        if (t[i] < 0) {
            freeze(s, t[i]);
        }
    }
}