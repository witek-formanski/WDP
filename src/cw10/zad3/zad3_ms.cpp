#define NONE -1

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

typedef struct c *Choice;
struct c
{
    pair<int, int> brick;
    int i;
    bool reversed;
};

Choice new_choice(pair<int, int> pair, int i)
{
    Choice newChoice = (Choice)malloc(sizeof(c));
    newChoice->brick = pair;
    newChoice->i = i;
    newChoice->reversed = false;
    return newChoice;
}

void give_back(int **inventory, int a, int b)
{
    if (b < a)
        swap(a, b);
    inventory[a][b]++;
}

bool try_take(int **inventory, int a, int i, pair<int, int> &results)
{
    for (int j = i + 1; j < 6; j++)
    {
        int f = min(a, j);
        int s = max(a, j);
        if (inventory[f][s] > 0)
        {
            results.first = f;
            results.second = s;
            inventory[f][s]--;
            return true;
        }
    }
    return false;
}

int domino(const vector<pair<int, int>> &bricks)
{
    if ((int)bricks.size() <= 0)
        return 0;
    int **inventory = (int **)malloc(6 * sizeof(int *));
    for (int i = 0; i < 6; i++)
    {
        inventory[i] = (int *)malloc(6 * sizeof(int *));
        for (int j = 0; j < 6; j++)
        {
            inventory[i][j] = 0;
        }
    }

    for (pair<int, int> cube : bricks)
    {
        give_back(inventory, cube.first, cube.second);
    }

    int maxLength = 1;

    for (pair<int, int> cube : bricks)
    {
        stack<Choice> currentString;
        currentString.push(new_choice(cube, NONE));

        while ((int)currentString.size() < (int)bricks.size())
        {
            if (currentString.empty())
                break;

            Choice current = currentString.top();
            current->i++;

            pair<int, int> nextChoice;

            // if we need to change choice
            if (current->i >= 6 || !try_take(inventory, current->brick.second, current->i, nextChoice))
            {
                // retrack
                if (current->reversed || current->brick.first == current->brick.second)
                {
                    // undo choice
                    give_back(inventory, current->brick.first, current->brick.second);
                    free(current);
                    currentString.pop();
                }
                else
                {
                    // try reverted
                    swap(current->brick.first, current->brick.second);
                    current->reversed = true;
                }
                continue;
            }

            // make next choice
            currentString.push(new_choice(nextChoice, NONE));
            maxLength = max(maxLength, (int)currentString.size());
        }

        while(!currentString.empty()){
            free(currentString.top());
            currentString.pop();
        }
    }

    for(int i = 0; i<6; i++){
        free(inventory[i]);
    }
    free(inventory);

    return maxLength;
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> dom(n);
    for(int i = 0; i<n; i++){
        cin>>dom[i].first>>dom[i].second;
    }

    int longest = domino(dom);
    cout<<longest<<endl;

    dom.clear();
    return 0;
}