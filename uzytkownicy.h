#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H

#include <iostream>
#include "plikuzytkownicy.h"


using namespace std;

/*
Klasa odpowiedzialna m.in. za logowanie, rejestracjê, zmianê has³a, wylogowanie.
*/

class Uzytkownicy
{
    vector <Uzytkownik> uzytkownicy;
    PlikUzytkownicy plikUzytkownikowAplikacji;
    int idZalogowanegoUzytkownika;

public:
    Uzytkownicy();
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void zmianaHasla();
    int wylogowanieUzytkownika();
};

#endif
