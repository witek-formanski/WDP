#include<stdio.h>
#include<stdlib.h>
#include<deque>
#include<vector>

//popuje i zwraca najmniejszy element, q_main.size() + q._size.size() >= 1
int minn(std::deque<int> &q_main, std::deque<int> &q_side){
    int wynik = 0;
    if(q_main.empty()){
        wynik = q_side.front();
        q_side.pop_front();
    } else if(q_side.empty()){
        wynik = q_main.front();
        q_main.pop_front();
    } else if(q_main.front() < q_side.front()){
        wynik = q_main.front();
        q_main.pop_front();
    } else {
        wynik = q_side.front();
        q_side.pop_front();
    }
    return wynik;
}

//jedna walka, q_main.size() + q._size.size() >= 2
void walka(std::deque<int> &q_main, std::deque<int> &q_side){
    int pierwszy = minn(q_main, q_side);
    int drugi = minn(q_main, q_side);
    if(pierwszy != drugi){
        q_side.push_back(pierwszy + drugi - 1);
    } else {
        q_main.push_front(pierwszy - 1);
    }
}

int robakolak(const std::vector<int> r){
    std::deque<int> q_main, q_side;

    for(size_t i = 0; i < r.size(); i++)
        q_main.push_back(r[i]);

    while(q_main.size() + q_side.size() >= 2)
        walka(q_main, q_side);

    return minn(q_main, q_side);
}

int main(){
    printf("%i\n", robakolak({1, 2, 3, 4, 7, 10, 23}));
    //1 2 3 4 7 10 23
    //2 3 4 7 10 23
    //4 4 7 10 23
    //3 7 10 23
    //9 10 23
    //18 23
    //40
    return 0;
}