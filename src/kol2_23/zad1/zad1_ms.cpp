#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_lower(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

bool is_on_left_edge(pair<int, int> p)
{
    return p.second == 0;
}

bool is_on_right_edge(pair<int, int> p, int size)
{
    return p.second + 1 == size;
}

bool is_single_island(pair<int, int> p, const vector<bool> isInAir){
    if(is_on_left_edge(p) && is_on_right_edge(p, isInAir.size())){
        return true;
    }
    if(is_on_left_edge(p)){
        return !isInAir[p.second+1];
    }
    if(is_on_right_edge(p,isInAir.size())){
        return !isInAir[p.second-1];
    }
    return !isInAir[p.second-1] && !isInAir[p.second+1];
}

// let: is not single
bool does_divide_islands(pair<int, int> p, const vector<bool> isInAir){
    if(is_on_left_edge(p) || is_on_right_edge(p, isInAir.size())) return false;
    return isInAir[p.second-1] && isInAir[p.second+1];
}

int wyspa(const vector<int> v)
{
    // vector to be sorted of pairs: <v[i],i>
    vector<pair<int, int>> pairs;
    for (int i = 0; i < v.size(); i++)
    {
        pair<int, int> curr(v[i], i);
        pairs.push_back(curr);
    }
    // sort by height
    sort(pairs.begin(), pairs.end(), is_lower);
    // is peak above the lvl of water
    vector<bool> isInAir(v.size(), true);
    int currentCount = 1, maxCount = 1;
    for (int i = 0; i < pairs.size(); i+=0)
    {
        int newCount = currentCount;
        // iterate while height is the same
        do
        {
            pair<int, int> p = pairs[i];
            isInAir[p.second] = false;
            if(is_single_island(p, isInAir)){
                newCount--;
                i++;
                continue;
            }
            if(does_divide_islands(p, isInAir)){
                newCount++;
                i++;
                continue;
            }
            i++;
        }while(i< pairs.size() && pairs[i-1]==pairs[i]);
        if (newCount > maxCount)
        {
            maxCount = newCount;
        }
        currentCount = newCount;
    }
    pairs.clear();
    isInAir.clear();
    return maxCount;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int islandMax = wyspa(v);
    cout<<islandMax<<endl;

    v.clear();
    return 0;
}