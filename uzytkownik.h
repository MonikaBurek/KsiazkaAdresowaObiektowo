#include <iostream>

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
