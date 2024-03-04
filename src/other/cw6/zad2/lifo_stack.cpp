#include <stack>

class lifo {
    std::stack<int> up;
    std::stack<int> down;

   private:
    void move(std::stack<int> down, std::stack<int> up) {
        while (!down.empty()) {
            up.push(down.top());
            down.pop();
        }
    }

   public:
    int front() {
        if (up.empty())
            move(down, up);

        return up.top();
    }

    void push(int k) {
        down.push(k);
    }

    void pop() {
        if (!up.empty())
            move(down, up);

        up.pop();
    }
};

/*
kolejka dwustronna od 1 do k
n zapytań
O(n*k) jeśli nie optymalizujemy
O(nlogk) jeśli trzymamy równej wysokości stosy 
(wyrównujemy gdy jeden jest pusty)
*/