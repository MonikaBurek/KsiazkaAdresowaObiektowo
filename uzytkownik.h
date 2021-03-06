#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

#include <iostream>

using namespace std;

/*
Klasa na podstawie ktorej jest tworzony Uzytkownik.(gettery i settery).
*/

class Uzytkownik
{
    int idUzytkownika;
    string nazwa;
    string haslo;

public:
    // Konstruktor domyslny
    Uzytkownik();
    virtual ~Uzytkownik();

    //Zwraca (get) numer ID nazwe i haslo Uzytkownika
    int pobierzIdUzytkownika();
    string pobierzNazwaUzytkownika();
    string pobierzHasloUzytkownika();

    //Ustawia (set) numer ID uzytkownika, nazwê
    void ustawIdUzytkownika(int idUzytkownika);
    void ustawNazwaUzytkownika(string nazwa);
    void ustawHasloUzytkownika(string haslo);
};

#endif // UZYTKOWNIK_H
