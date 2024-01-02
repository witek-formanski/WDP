#define NEVER -1
#define UNKNOWN -2

#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <set>
#include "fu.cpp"

using namespace std;

typedef struct nd *node;
struct nd
{
    int id;
    set<int> tail;
    node left;
    node right;
};

node create_node(int id)
{
    node newNode = (node)malloc((sizeof(nd)));
    newNode->id = id;
    newNode->left = NULL;
    newNode->right = NULL;

    set<int> newSet;
    newNode->tail=newSet;
    return newNode;
}

// a grabs b
void grab(node a, node b, bool left)
{
    if (left)
        a->left = b;
    else
        a->right = b;
    b->tail.insert(a->id);
}

bool let_go(node a, node b)
{
    bool left = a->left == b;
    b->tail.erase(a->id);
    node *toBeRemoved = left ? &(a->left) : &(a->right);
    *toBeRemoved = NULL;
    return left;
}

void mark_time(node head, vector<int> &timeline, int timestamp)
{
    if (head == NULL)
        return;
    timeline[head->id] = timestamp;
    mark_time(head->left, timeline, timestamp);
    mark_time(head->right, timeline, timestamp);
}

void bfs(node monkey, vector<int> &timeline, const vector<node> nodes, int timestamp)
{
    set<int> visited;
    queue<node> toBeVisited;
    toBeVisited.push(monkey);

    while (!toBeVisited.empty())
    {
        node currentMonkey = toBeVisited.front();
        toBeVisited.pop();
        timeline[currentMonkey->id] = timestamp;

        // push monkeys holding onto tail
        for (int id : currentMonkey->tail)
        {
            if (visited.find(id) == visited.end())
            {
                toBeVisited.push(nodes[id]);
                visited.insert(nodes[id]->id);
            }
        }

        // left hand
        if (currentMonkey->left != NULL && visited.find(currentMonkey->left->id) == visited.end())
        {
            toBeVisited.push(currentMonkey->left);
            visited.insert(currentMonkey->left->id);
        }
        // right hand
        if (currentMonkey->right != NULL && visited.find(currentMonkey->right->id) == visited.end())
        {
            toBeVisited.push(currentMonkey->right);
            visited.insert(currentMonkey->right->id);
        }
    }
}

/// @brief Zad 2 / Ćw 9
/// @param monkeys i-monkeys holds .first and .second (-1 if does not in each hand)
/// @param pawLettingGo
/// @return
vector<int> malpki(const vector<pair<int, int>> monkeys, const vector<pair<int, int>> pawLettingGo)
{
    int n = (int)monkeys.size();
    vector<node> nodes(n);

    for(int i = 0; i<n; i++){
        nodes[i] = create_node(i);
    }

    // build tree
    for (int i = 0; i < n; i++)
    {
        node currentMonkey = nodes[i];
        int leftId = monkeys[i].first, rightId = monkeys[i].second;

        if (leftId != -1)
        {
            grab(currentMonkey, nodes[leftId], true);
        }
        if (rightId != -1)
        {
            grab(currentMonkey, nodes[rightId], false);
        }
    }

    // let go
    vector<array<int,3>> reverseHistory;
    for (int s = 0; s < (int)pawLettingGo.size(); s++)
    {
        pair<int, int> letGo = pawLettingGo[s];
        node currentMonkey = nodes[letGo.first];
        node tailOwner = nodes[letGo.second];
        bool left = let_go(currentMonkey, tailOwner);
        reverseHistory.push_back({currentMonkey->id, tailOwner->id, (int)left});
    }

    vector<int> timeline(n, UNKNOWN);
    bfs(nodes[0], timeline, nodes, NEVER);

    // reverse steps
    for (int s = (int)reverseHistory.size() -1; s>=0; s--)
    {
        array<int,3> letGo = reverseHistory[s];
        int monkey = letGo[0];
        int grabed = letGo[1];
        bool left = (bool)letGo[2];
        if (timeline[grabed] == UNKNOWN && timeline[monkey] != UNKNOWN)
        {
            // now handing
            bfs(nodes[grabed], timeline, nodes, s);
        }
        grab(nodes[monkey], nodes[grabed], left);
    }

    reverseHistory.clear();

    return timeline;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> monkeys(n);
    for (int i = 0; i < n; i++)
    {
        pair<int, int> newMonkey;
        cin >> newMonkey.first >> newMonkey.second;
        monkeys[i] = newMonkey;
    }

    int s;
    cin>>s;
    vector<pair<int, int>> lettingGo(s);
    for (int i = 0; i < s; i++)
    {
        pair<int, int> newMonkey;
        cin >> newMonkey.first >> newMonkey.second;
        lettingGo[i] = newMonkey;
    }

    vector<int> timeline = malpki(monkeys, lettingGo);
    for(int s : timeline){
        cout<<s<<endl;
    }

    monkeys.clear();
    timeline.clear();
}
