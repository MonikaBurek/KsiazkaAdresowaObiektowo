#ifndef PLIKUZYTKOWNICY_H
#define PLIKUZYTKOWNICY_H

#include <iostream>
#include <vector>
#include "uzytkownik.h"
#include "plik.h"

using namespace std;

/*
Klasa odpowiedzialna za operacje na pliku Uzytkownicy.txt
*/

class PlikUzytkownicy :public Plik
{
    fstream plik;

public:
    void wczytajUzytkownikowZPliku(vector <Uzytkownik> &uzytkownicy);
    void zapiszDaneUzytkownikowDoPliku (vector <Uzytkownik> &uzytkownicy);
    void dopiszUzytkownikaDoPliku(Uzytkownik nowyUzytkownik);
};

#endif // PLIKUZYTKOWNICY_H
