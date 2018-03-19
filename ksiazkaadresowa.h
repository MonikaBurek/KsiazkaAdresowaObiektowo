#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "plikznajomi.h"


using namespace std;

/*
Klasa odpowiedzialna m.in. za dodawanie nowego znajomego, edycje usuwanie, wyszukiwanie.
*/

class KsiazkaAdresowa
{
    vector <Znajomy> znajomi;
    PlikZnajomi plikZnajomiUzytkownika;
    int IDZalogowanegoUzytkownika;

public:
    KsiazkaAdresowa(int IDZalogowanegoUzytkownika);
    Znajomy podajDaneNowegoZnajomego();
    void zapiszNowegoZnajomego();
    void szukajImie();
    void szukajNazwisko();
    void wyswietlWszystkichZnajomych();
    void edytujKontakt();
    void usunKontakt();
};

#endif
