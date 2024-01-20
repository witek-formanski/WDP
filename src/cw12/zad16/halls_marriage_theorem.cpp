/*
warunek konieczny i wystarczający:
Hall's Marriage Theorem
osobno rozpatrujemy najpierw dla kolumn, później dla wierszy
sortujemy rosnąco po początkach przedziałów

rozpatrujemy od początku
jeżeli na danym polu nie ma konfliktów, ustawiamy wieżę
i przechodzimy do kolejnej
w razie konfliktu (remis początków):
 - wrzucamy wszystkie remisujące początkami wieże na kolejkę
   priorytetową (priorytetyzującą wcześniejszy koniec)
 - zdejmujemy z kolejki wieżę z najwcześniejszym końcem
   i ustawiamy ją
 - dorzucamy na kolejkę wszystkie elementy z kolejnego pola
 - powtarzamy procedurę
*/