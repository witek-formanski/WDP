#include <bitset>
#include <iostream>
#include <string>

/*
0
01
0110
01101001

01101001
0110
01
0
*/

using namespace std;

bool sprawdzRozdzial(string s, string &wynik) {
  for (int i = 0; i < s.size(); i += 2) {
    if (i < s.size() - 1) {
      if (s[i] == '0' && s[i + 1] == '1') {
        wynik += "0";
      } else if (s[i] == '1' && s[i + 1] == '0') {
        wynik += "1";
      } else {
        // nie da sie
        return false;
      }
    } else { // ostatni element
      wynik += s[i];
    }
  }

  return true;
}

bool czyWCiagu(string s) {
  string wynik;

  if (s.size() <= 3)
    return !(s == "111" || s == "000");

  if (sprawdzRozdzial(s, wynik))
    return czyWCiagu(wynik);

  // Probujemy offset +1
  wynik = (s[0] == '1') ? "0" : "1";
  s.erase(0, 1);

  if (sprawdzRozdzial(s, wynik))
    return czyWCiagu(wynik);

  return false;
}

int main() {
  int ile = 0;
  const int potega = 14;
  const int warPotega = 1 << potega;

  for (int i = 0; i < warPotega; i++) {
    string s = bitset<(size_t)potega>(i).to_string();
    if (czyWCiagu(s))
      ile++;
  }

  cout << ile << " " << (float)ile / (float)warPotega;
}