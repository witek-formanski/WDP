#include<vector>
#include<queue>
#include<stdio.h>

void przelej(std::queue<float> &v, std::queue<float> &q){
    float zlane = 0;
    for(int i = 0; i < 2; i++){
        if(q.empty() || v.front() < q.front()){
            zlane += v.front();
            v.pop();
        } else {
            zlane += q.front();
            q.pop();
        }
    }

    q.push(zlane);
}

float zlewki(const std::vector<float> x, int k){
    std::queue<float> v, q;
    for(float val : x) v.push(val);

    for(int i = 0; i < k; ++i){
        przelej(v, q);
    }

    if(!v.empty() && !q.empty())
        return std::min(v.front(), q.front());
    else if(v.empty())
        return q.front();
    else
        return v.front();

}

int main(){
    printf("%lf\n", zlewki({1, 2, 3, 4, 5}, 3));
    return 0;
}