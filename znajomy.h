#ifndef ZNAJOMY_H
#define ZNAJOMY_H

#include <iostream>
#include <vector>
#include <fstream>
#include "uzytkownicy.h"

using namespace std;

/*
Klasa na podstawie ktorej jest tworzony Znajomy.(gettery i settery).
*/

class Znajomy
{
    string imie, nazwisko, numerTelefonu, mail, adres;
    int numerIDZnajomego, numerIDUzytkownika;

public:
    // Konstruktor domyslny
    Znajomy();
    virtual ~Znajomy();

    //Zwraca (get) numer ID nazwe i haslo Uzytkownika
    int pobierzIdZnajomego();
    int pobierzIdUzytkownika();
    string pobierzImieZnajomego();
    string pobierzNazwiskoZnajomego();
    string pobierzNumerTelefonuZnajomego();
    string pobierzMailZnajomego();
    string pobierzAdresZnajomego();

    //Ustawia (set) numer ID uzytkownika, nazwê
    void ustawNumerIDZnajomego(int numerIDZnajomego);
    void ustawNumerIDUzytkownika(int numerIDUzytkownika);
    void ustawImieZnajomego(string imie);
    void ustawNazwiskoZnajomego(string nazwisko);
    void ustawNumerTelefonuZnajomego(string numerTelefonu);
    void ustawMailZnajomego(string mail);
    void ustawAdresZnajomego(string adres);
};

#endif // ZNAJOMY_H
