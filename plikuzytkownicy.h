#include <iostream>
#include <fstream>
#include <vector>
#include "uzytkownik.h"

using namespace std;

/*
Klasa odpowiedzialna za operacje na pliku Uzytkownicy.txt
*/

class PlikUzytkownicy
{
    fstream plik;

public:
    void wczytajUzytkownikowZPliku( vector <Uzytkownik> &uzytkownicy);
    void zapiszDaneUzytkownikowDoPliku ( vector <Uzytkownik> &uzytkownicy);
    void dopiszUzytkownikaDoPliku(Uzytkownik nowyUzytkownik);

};
