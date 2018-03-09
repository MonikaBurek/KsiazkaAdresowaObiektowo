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
    string imie, nazwisko, adres, numerTelefonu, mail;
    int numerIDZnajomego, idUzytkownika;

public:
     // Konstruktor domyslny
    Znajomy();
    virtual ~Znajomy();

    //Zwraca (get) numer ID nazwe i haslo Uzytkownika
    int pobierzIdZnajomego();
    //int pobierzIdUzytkownika()
    string pobierzImieZnajomego();
    string pobierzNazwiskoZnajomego();
    string pobierzNumerTelefonuZnajomego();
    string pobierzAdresZnajomego();
    string pobierzMailZnajomego();

    //Ustawia (set) numer ID uzytkownika, nazwê
    void ustawNumerIDZnajomego(int numerIDZnajomego);
    void ustawIdUzytkownika(int idUzytkownika);
    void ustawImieZnajomego(string imie);
    void ustawNazwiskoZnajomego(string nazwisko);
    void ustawAdresZnajomego(string adres);
    void ustawNumerTelefonuZnajomego(string numerTelefonu);
    void ustawMailZnajomego(string mail);
};
