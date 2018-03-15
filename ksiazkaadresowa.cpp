#include <iostream>
#include "ksiazkaadresowa.h"
#include <windows.h>
#include "plik.h"


using namespace std;


Znajomy KsiazkaAdresowa::podajDaneNowegoZnajomego(int idZalogowanegoUzytkownika)
{
    string imie, nazwisko, adres, numerTelefonu, mail;
    int IDZnajomego, IDUzytkownika;
    Znajomy nowyZnajomy;
    PlikZnajomi plikZnajomiUzytkownika;

    cout << endl << "Zapisywanie nowego znajomego." << endl << endl;
    cout << "Podaj imie: ";
    cin >> imie;
    cout << "Podaj nazwisko: ";
    cin >> nazwisko;
    cout << "Podaj numer telefonu: ";
    cin.sync();
    getline(cin,numerTelefonu);
    cout << "Podaj mail: ";
    cin >> mail;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin,adres);

    IDZnajomego = plikZnajomiUzytkownika.znajdzKolejnyNumerIDZnajomego();
    IDUzytkownika = idZalogowanegoUzytkownika;

    nowyZnajomy.ustawNumerIDZnajomego(IDZnajomego);
    nowyZnajomy.ustawNumerIDUzytkownika(IDUzytkownika);
    nowyZnajomy.ustawImieZnajomego(imie);
    nowyZnajomy.ustawNazwiskoZnajomego(nazwisko);
    nowyZnajomy.ustawNumerTelefonuZnajomego(numerTelefonu);
    nowyZnajomy.ustawMailZnajomego(mail);
    nowyZnajomy.ustawAdresZnajomego(adres);

    return nowyZnajomy;
}

void KsiazkaAdresowa::zapiszNowegoZnajomego(int idZalogowanegoUzytkownika)
{
    bool czyPlikJestPusty;
    czyPlikJestPusty = plikZnajomiUzytkownika.czyPlikJestPusty("Ksiazkaadresowa.txt");

    if (czyPlikJestPusty == 1) //"Plik zawiera dane." << endl;
    plikZnajomiUzytkownika.wczytajZnajomychZPliku(znajomi, idZalogowanegoUzytkownika);

    Znajomy nowyZnajomy = podajDaneNowegoZnajomego(idZalogowanegoUzytkownika);

    znajomi.push_back(nowyZnajomy);
    plikZnajomiUzytkownika.dopiszZnajomegoDoPliku(nowyZnajomy);

    cout << "Dane zostaly zapisne." << endl;
    Sleep(1000);
}
