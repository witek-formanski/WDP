#include<stdio.h>
#include<vector>
#include<algorithm>

bool trojkat(const std::vector<int> v){
    std::vector<int> kopia(v);
    std::sort(kopia.begin(), kopia.end());

    for(size_t i = 2; i < kopia.size(); i++){
        if(kopia[i] <= kopia[i - 1] + kopia[i - 2])
            return true;
    }

    return false;
}

int main(){
    printf("%i\n", trojkat({1, 5, 2, 4, 2, 4, 2}));
}