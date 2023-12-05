#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<algorithm>

typedef struct _para{
    int a;
    int b;
} para;

bool greater(para a, para b){
    return a.a < b.a;
}

int rejs(int k, const std::vector<int> start, const std::vector<int> end){
    std::vector<para> v;
    int maks = 0;

    for(size_t i = 0; i < start.size(); i++){
        para temp;
        temp.a = start[i];
        temp.b = end[i];
        v.push_back(temp);
    }

    std::sort(v.begin(), v.end(), greater);

    std::priority_queue<int> pq;

    for(size_t i = 0; i < v.size(); i++){
        while(!pq.empty() && abs(pq.top()) <= v[i].a){
            pq.pop();
        }
        pq.push(-v[i].b);

        while(pq.size() > (size_t)k){
            pq.pop();
        }

        if(pq.size() == (size_t)k)
            maks = std::max((-pq.top() - v[i].a + 1), maks);
    }

    return maks;
}

int main(){
    printf("%i\n", rejs(2, {12, 48, 28, 50, 0, 25}, {36, 100, 70, 80, 69, 30}));
    return 0;
}