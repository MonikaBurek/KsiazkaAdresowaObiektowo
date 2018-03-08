#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

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
/*
Klasa  zawiera funkcję czy plik jest pusty.
*/
class Plik
{
    fstream plik;

public:
    bool czyPlikJestPusty(string nazwaPliku);
};

/*
Klasa odpowiedzialna za operacje na pliku Uzytkownicy.txt
*/

class PlikUzytkownicy :public Plik
{
    fstream plik;

public:
    void wczytajUzytkownikowZPliku( vector <Uzytkownik> &uzytkownicy);
    void zapiszDaneUzytkownikowDoPliku ( vector <Uzytkownik> &uzytkownicy);
    void dopiszUzytkownikaDoPliku(Uzytkownik nowyUzytkownik);

};

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
    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void zmianaHasla(int idZalogowanegoUzytkownika);
    int wylogowanieUzytkownika();
};

