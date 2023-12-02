#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// median (middle element in array, should there be two, return smaller)
int median(const vector<int> s){
    vector<int> sorted(s.size());
    copy(s.begin(), s.end(),sorted.begin());
    sort(sorted.begin(), sorted.end());

    // median is middle element in sorted array or average of two middle ones
    // for purpose of this task, we just need the first number from the middle ones
    return sorted[(s.size() - 1) / 2];
}

// to find how many hits we need to do, we just need to find median
//  O(nlogn)
int slupki(const vector<int> s)
{
    int pivot = median(s);
    int hitsCount = 0;
    for(int pole : s){
        hitsCount+=abs(pivot-pole);
    }
    return hitsCount;
}

int main()
{
    int n;
    cin>>n;
    vector<int> poles;
    for(int i = 0; i<n; i++){
        int pole;
        cin>>pole;
        poles.push_back(pole);
    }

    int hammerHits = slupki(poles);
    cout<<hammerHits<<endl;
}