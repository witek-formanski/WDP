// SADZAWKA

// Idea: Przechowujemy kolejne warstwy sadzawki na stosie: +n to warstwa n milimetrów wody, -n to warstwa n milimetrów lodu (tak jak w wyniku) i im bliżej spodu stosu, tym bliżej dna sadzawki.

// Kluczowa obserwacja jest taka, że każdego dnia sadzawka zmienia się w taki sposób, że ze stosu zdejmujemy pewną liczbę (być może zero, jeśli jest 0 stopni) elementów, a następnie dodajemy *co najwyżej dwa* --- np. po mroźnym (ujemnym) dniu na wierzchu będzie warstwa lodu (pewna liczba ujemna --- trzeba ją wyznaczyć), pod nią warstwa wody (jej wielkość też mogła zostać zmodyfikowana w porównaniu z poprzednim dniem), a niżej stos będzie niezmieniony --- lód ,,pochłonie'' ileś warstw wody + dokładnie jedną (ostatnią) tylko ,,zmodyfikuje''.

// W szczególności z obserwacji wynika, że każdego dnia zrobimy <= 2 x PUSH, czyli łączna liczba PUSHów będzie liniowa od liczby dni. W szczególności również liczba POPów zamortyzuje się do liniowej i złożoność całego algorytmu będzie liniowa.

// Implementacja: kapitalikami zapisuję funkcje obsługujące stos, których dokładną implementację uzgodnimy następnym razem.

///////////////////////

// w tablicy t[n] mamy temperatury w (n) kolejnych dni

#include <cmath>
#include <iostream>
#include <stack>

int sadzawka(int n, int t[]) {
    int topLayer = 0;  // nowa warstwa ,,wierzchnia'' po danym dniu
    int botLayer = 0;  // nowa warstwa ,,tuz pod wierzchnia''

    int modifier = 0;  // ile mm sadzawki ma zmienic swoj stan danego dnia
    int curr = 0;

    std::stack<int> s;  // s jest typu ,,stos intów''

    for (int i = 0; i < n; ++i) {
        topLayer = 0;
        modifier = std::abs(t[i]);
        if (t[i] < 0) {  // mrozny dzien
            while (!s.empty() && modifier >= 0) {
                curr = s.top();
                s.pop();
                if (curr < 0)
                    topLayer += curr;
                else {
                    topLayer -= curr;
                    modifier -= curr;
                }
            }
            // wychodzimy z petli gdy modifier < 0: czyli zmienilismy stan zbyt wielu mm (trzeba dolozyc z powrotem te nadwyzke jako dolna warstwe)

            if (!s.empty()) {  // dolna warstwe wody dodajemy tylko gdy jest nad jakims lodem
                s.push(botLayer);
                botLayer = -modifier;
                topLayer += modifier;
            }
            if (modifier >= 0)  // stos jest pusty i musimy zamarznąć jeszscze trochę wody pod stosem
                topLayer -= modifier;
            s.push(topLayer);
        } else if (t[i] > 0) {  // sloneczny dzien
            // w gruncie rzeczy prawie copy-paste, pewnie da sie to scalić (znaki muszą się zgadzać)
            while (!s.empty() && modifier >= 0) {
                curr = s.top();
                s.pop();
                if (curr < 0)  // uwaga, swap przypadkow
                    topLayer += curr;
                else {
                    topLayer -= curr;
                    modifier -= curr;
                }
            }
            botLayer = modifier;  // uwaga, tym razem botLayer to lód
            topLayer += modifier;
            if (botLayer < 0) {  // uwaga, obie warstwy dodajemy tylko gdy zostal jakikolwiek lod w sadzawce
                s.push(botLayer);
                s.push(topLayer);
            }
        }
    }

    // przepisujemy ze stosu na tablice, liczac ile jest warstw
    int layers = 0;
    int i = 0;

    while (!s.empty()) {
        t[layers] = s.top();
        s.pop();
        ++layers;
    }

    //    CLEAR(s); // zwalniamy pamięć

    return layers;
}

int main() {
    int t[9] = {2, -12, 8, -4, 2, 4, -4, 1, 3};
    int n = 9;

    std::cout << sadzawka(n, t);
}