#ifndef KOL_H
#define KOL_H

#include <vector>

// Wszędzie w zadaniu można założyć, że wskaźniki przekazywane do funkcji są
// wskaźnikami na struktury interesant, które były kiedyś wynikiem funkcji
// "nowy_interesant".

// UWAGA: funkcja "numerek" powinna działać również dla interesantów
// niestojących w żadnej kolejce, a nawet po wywołaniu "zamkniecie_urzedu"

// Należy wypełnić
struct interesant {
    // Twój kod zaczyna się tu

    // A kończy tu
};

/**
 * @brief Inicjuje bibliotekę
 *
 * @param m liczba okienek
 */
void otwarcie_urzedu(int m);

/**
 * @brief Do urzędu przychodzi nowy interesant
 *
 * @param k numer okienka, do którego ustawia się nowy interesant
 * @return interesant* wskaźnik na strukturę nowego interesanta
 */

interesant *nowy_interesant(int k);

/**
 * @brief Zwraca numerek interesanta
 *
 * Interesanci dostają numerki będące kolejnymi liczbami całkowitymi, zaczynając
 * od 0
 *
 * UWAGA: musi działać dla interesantów niestojących w żadnej kolejce i po
 * wywołaniu "zamkniecie_urzedu"
 *
 * @param i wskaźnik na interesanta
 * @return int numerek interesanta
 */

int numerek(interesant *i);

/**
 * @brief Obsługuje jednego interesanta
 *
 * @param k numer okienka przy którym obsługiwany jest interesant
 * @return interesant* obsłużony interesant lub NULL jeśli kolejka była pusta
 */

interesant *obsluz(int k);

/**
 * @brief Interesant i ustawia się w kolejce do okienka k
 *
 * Możesz założyć, że wcześniej stał w kolejce do innego okienka
 *
 * @param i interesant zmieniający okienko
 * @param k numer okienka, do którego przechodzi interesant i
 */

void zmiana_okienka(interesant *i, int k);

/**
 * @brief Okienko k1 się zamyka, a interesanci stojący w kolejce przechodzą do
 * okienka k2, w kolejności w jakiej stali
 *
 * @param k1 Zamykane okienko
 * @param k2 Okienko do którego przechodzą interesanci
 */

void zamkniecie_okienka(int k1, int k2);

/**
 * @brief Interesanci od i1 do i2 przechodzą do okienka specjalnego, gdzie są od
 * razu obsługiwani
 *
 * Zakładamy, że i1 oraz i2 stoją w tej samej kolejce oraz że i1 stoi w kolejce
 * przed i2, chyba że i1 == i2.
 *
 * @param i1 Pierwszy ekspresowo obsłużony interesant
 * @param i2 Ostatni ekspresowo obsłużony interesant
 * @return std::vector<interesant *> Wszyscy ekspresowo obsłużeni interesanci w
 * kolejności w której stali w kolejce, zaczynając od i1 a kończąc na i2
 */

std::vector<interesant *> fast_track(interesant *i1, interesant *i2);

/**
 * @brief Naczelnik odwraca kolejność kolejki
 *
 * @param k numer okienka, którego kolejkę odwraca naczelnik
 */

void naczelnik(int k);

/**
 * @brief Zamyka urząd
 *
 * @return std::vector<interesant *> wszyscy interesanci którzy jeszcze stali w
 * kolejkach, uporządkowani wg numeru okienka i następnie porządku kolejki
 */

std::vector<interesant *> zamkniecie_urzedu();

#endif
