// pomysł: wystarczy szukać zachłannie od lewej
// dwie kolejki:
// na jednej spamiętujemy, którego słowa szukamy
// na drugiej pamiętamy, które słowo dokleimy

// 'c' - znak stop

#include <queue>

int fib_word(char s[]) {
    std::queue<char> q;  // compare
    std::queue<char> k;  // build
    int count = 1;
    q.push('a');
    q.push('c');
    q.push('b');
    q.push('c');

    for (int i = 0; s[i]; ++i) {
        if (s[i] == q.front()) {
            k.push(s[i]);
            q.pop();
            if (q.front() == 'c') {
                ++count;
                k.push('c');
                while (k.front() != 'c') {
                    q.push(k.front());
                    k.push(k.front());
                    k.pop();
                    q.push('c');
                    k.pop();  // remove 'c'
                }
            }
        }
    }

    if (count == 1)
        for (int i = 0; s[i]; ++i) {
            if (s[i] == 'b')
                return 1;

            return 0;
        }
    
    return count;
}

#include <iostream>

int main() {
    char my_string[20] = "abccxabbbaaxccbbba";
    std::cout << fib_word(my_string) << "\n";
}