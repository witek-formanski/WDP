#define STOP_SYNTAX 'c'

#include <iostream>
#include <queue>

using namespace std;

int slowa(string s)
{
    queue<char> q, k;
    // fill q with default data
    q.push('a');
    q.push(STOP_SYNTAX);
    q.push('b');
    q.push(STOP_SYNTAX);
    int count = 1;
    bool wasB = false;

    for (int i = 0; s[i]; i++)
    {
        if (s[i] == 'b' && !wasB)
            wasB = true;

        // do we encounter next fib letter
        if (s[i] == q.front())
        {
            k.push(s[i]);
            q.pop();

            // if it was not last letter of word
            if (q.front() == STOP_SYNTAX)
            {
                ++count;
                k.push(STOP_SYNTAX);
                // copy finished word to make queue for next one
                while (k.front() != STOP_SYNTAX)
                {
                    q.push(k.front());
                    k.push(k.front());
                    k.pop();
                }
            }
        }
    }

    // free q,k but i cannot do it
    if (wasB)
        return count;
    return 0;
}

int main()
{
    string slowo = "abccxabbbaaxccbbba" + 0;
    cout << slowa(slowo) << endl;
}