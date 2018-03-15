#ifndef PLIKZNAJOMI_H
#define PLIKZNAJOMI_H

#include <iostream>
#include <vector>
#include "znajomy.h"
#include "plik.h"

using namespace std;

/*
Klasa odpowiedzialna za operacje na pliku Znajomi.txt
*/

class PlikZnajomi :public Plik
{
    fstream plik;

public:
    int znajdzKolejnyNumerIDZnajomego ();
    void dopiszZnajomegoDoPliku(Znajomy nowyZnajomy);

    void zapiszZnajomychUzytkownikaDoWektora (vector <Znajomy> &znajomi, string linia, int iloscZnajomych);
    void wczytajZnajomychZPliku(vector <Znajomy> &znajomi, int idZalogowanegoUzytkownika);

    void usunLinieZPliku (int idZalogowanegoUzytkownika);
    void zapiszDaneZnajomychDoPliku(vector <Znajomy> &znajomi, int idZalogowanegoUzytkownika);

};

#endif // PLIKZNAJOMI_H
