#include <iostream>
#include <stack>

using namespace std;

void clear(stack<char> *heap)
{
    while (!heap->empty())
    {
        heap->pop();
    }
}

int nawiasy(char arr[])
{
    stack<char> heap;
    int i = 0;
    int curr = 0;
    int max = 0;
     while (arr[i] != '0')
    {
        switch (arr[i])
        {
        case '(':
            heap.push('(');
            break;
        case ')':
            if (heap.empty())
            {
                curr = 0;
                clear(&heap);
            }
            else{
                heap.pop();
                curr+=2;
            }

            if (curr > max)
                    max = curr;
            break;
        }
        i++;
    }
    return max;
}

int main()
{
    string s = " ";
    cin >> s[0];
    char c = ' ';
    while (c != '0' && cin >> c)
    {
        s += c;
    }
    char *temp = (char *)malloc((size_t)s.size() * sizeof(char));
    for (int i = 0; i < s.size(); i++)
        temp[i] = s[i];
    cout << nawiasy(temp) << endl;
}