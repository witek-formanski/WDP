#include<stdio.h>
#include<vector>
#include<algorithm>
#include<deque>
#include<stdlib.h>

int przedzial(const std::vector<int> x, int r){
    std::vector<int> srt_x(x);
    std::sort(srt_x.begin(), srt_x.end());
    std::deque<int> q;
    int c, wynik = 0;
    for(size_t i = 0; i < srt_x.size(); i++){
        c = srt_x[i] - r;
        q.push_back(srt_x[i]);

        while(!q.empty() && q.front() < c - r){
            q.pop_front();
        }

        wynik = std::max((int)q.size(), wynik);
    }

    return wynik;
}

int main(){
    printf("%i\n", przedzial({2, -2, 5, -1, 11, 8, 4, 5, 8, 7}, 2));
    return 0;
}