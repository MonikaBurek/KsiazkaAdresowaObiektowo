#include <iostream>
#include <vector>
#include "uzytkownik.h"

using namespace std;

/*
Klasa odpowiedzialna m.in. za logowanie, rejestracj�, zmian� has�a, wylogowanie.
*/
class Uzytkownicy
{
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika;

public:
    Uzytkownicy();
    Uzytkownik podajDaneNowegoUzytkownika();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void zmianaHasla();
    int wylogowanieUzytkownika();
};
