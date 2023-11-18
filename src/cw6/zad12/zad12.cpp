#include<queue>
#include<stdio.h>

using namespace std;

int slowa(char s[]){
    queue<char> nastSlowo;
    queue<char> q;
    int wynik = 1;
    q.push('a');
    q.push('|');
    q.push('b');

    for(int i = 0; s[i]; i++){
        if(s[i] == q.front()){
            nastSlowo.push(q.front());
            q.pop();

            if(q.front() == '|'){
                wynik++;
                q.pop();
                q.push('|');
                
                //przepisanie nastSlowo
                nastSlowo.push('|');
                while(nastSlowo.front() != '|'){
                    q.push(nastSlowo.front());
                    nastSlowo.push(nastSlowo.front());
                    nastSlowo.pop();
                }
                nastSlowo.pop();
            }
        }
    }

    bool byloB = false;
    if(wynik == 1)
        for(int i = 0; s[i]; i++)
            if(s[i] == 'b')
                byloB = true;

    if(wynik > 1) return wynik;
    else if(byloB) return 1;
    else return 0;

}

int main(){
    char s[] = "abzzabaabacab";
    printf("%i\n", slowa(s));
    return 0;
}