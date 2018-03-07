#include <iostream>
#include <vector>
//#include "uzytkownik.h"
#include "plikuzytkownicy.h"


using namespace std;

/*
Klasa odpowiedzialna m.in. za logowanie, rejestracj�, zmian� has�a, wylogowanie.
*/
class Uzytkownicy
{
    vector <Uzytkownik> uzytkownicy;
    PlikUzytkownicy plikUzytkownikowAplikacji;
    int idZalogowanegoUzytkownika;

public:
    Uzytkownicy();
    Uzytkownik podajDaneNowegoUzytkownika();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void zmianaHasla(int idZalogowanegoUzytkownika);
    int wylogowanieUzytkownika();
};
