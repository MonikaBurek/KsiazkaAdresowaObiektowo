#include <iostream>
#include "uzytkownik.h"

using namespace std;

Uzytkownik::Uzytkownik()
    {
        idUzytkownika = 0;
        nazwa = "";
        haslo = "";
    }

Uzytkownik::~Uzytkownik() {;}

int Uzytkownik::pobierzIdUzytkownika()
    {
        return idUzytkownika;
    }

string Uzytkownik::pobierzNazwaUzytkownika()
    {
        return nazwa;
    }

string Uzytkownik::pobierzHasloUzytkownika()
    {
        return haslo;
    }

void Uzytkownik::ustawIdUzytkownika(int idUzytkownika)
    {
        this -> idUzytkownika = idUzytkownika;
    }

void Uzytkownik::ustawNazwaUzytkownika(string nazwa)
    {
        this -> nazwa = nazwa;
    }

void Uzytkownik::ustawHasloUzytkownika(string haslo)
    {
        this -> haslo = haslo;
    }
