#include <iostream>
#include "uzytkownicy.h"
#include <windows.h>
#include "plik.h"


using namespace std;


Uzytkownicy::Uzytkownicy()
{
    int idZalogowanegoUzytkownika = 0;

}

Uzytkownik Uzytkownicy::podajDaneNowegoUzytkownika()
{
    string nazwaUzytkownika, hasloUzytkownika;
    int numerIDUzytkownika;
    Uzytkownik nowyUzytkownik;

    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwaUzytkownika;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        while(itr -> Uzytkownik::pobierzNazwaUzytkownika() == nazwaUzytkownika)
        {
            cout << "Taki uztkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> nazwaUzytkownika;
        }
    }

    cout << "Podaj haslo: ";
    cin >> hasloUzytkownika;

    if (uzytkownicy.empty() == true)  // je¿eli ksiazka adresowa jest pusta
    {
        numerIDUzytkownika = 1;           // to nowy adresat ma id=1
    }
    else
    {
        numerIDUzytkownika = uzytkownicy.back().pobierzIdUzytkownika() + 1; // w przeciwnym przypadku pobierz id ostatniej osoby z ksiazki adresowej i zwiêksz wartoœæ o jeden.
    }


    nowyUzytkownik.ustawNazwaUzytkownika(nazwaUzytkownika);
    nowyUzytkownik.ustawHasloUzytkownika(hasloUzytkownika);
    nowyUzytkownik.ustawIdUzytkownika(numerIDUzytkownika);

    return nowyUzytkownik;
}

void Uzytkownicy::rejestracjaUzytkownika()
{
    bool czyPlikJestPusty;
    czyPlikJestPusty = plikUzytkownikowAplikacji.czyPlikJestPusty("Uzytkownicy.txt");

    if (czyPlikJestPusty == 1)
    plikUzytkownikowAplikacji.wczytajUzytkownikowZPliku(uzytkownicy);

    Uzytkownik nowyUzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(nowyUzytkownik);
    plikUzytkownikowAplikacji.dopiszUzytkownikaDoPliku(nowyUzytkownik);

    cout << endl << "Konto zalozone." << endl;
    Sleep(1000);
}

int Uzytkownicy::logowanieUzytkownika()
{
    string nazwaUzytkownika, hasloUzytkownika;
    bool znalezionyUzytkownik = 0;
    int proby = 0;
    bool czyPlikJestPusty;

    czyPlikJestPusty = plikUzytkownikowAplikacji.czyPlikJestPusty("Uzytkownicy.txt");

    if (czyPlikJestPusty == 1)
    plikUzytkownikowAplikacji.wczytajUzytkownikowZPliku(uzytkownicy);


    cout << "Podaj nazwe uzytkownika: ";
    cin >>  nazwaUzytkownika;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if(itr -> pobierzNazwaUzytkownika() == nazwaUzytkownika)
        {
            znalezionyUzytkownik = 1;
            for(int iloscProb = 0; iloscProb < 3; iloscProb++)
            {
                proby = iloscProb + 1;
                cout << "Podaj haslo. Pozostalo prob " << 3 - iloscProb << ":";
                cin >> hasloUzytkownika;
                if (itr -> pobierzHasloUzytkownika() == hasloUzytkownika)
                {
                    cout<< "Zalogowales sie."<<endl;
                    idZalogowanegoUzytkownika = itr -> pobierzIdUzytkownika();
                    return idZalogowanegoUzytkownika;
                }
            }
            if( proby == 3)
            {
                cout << "Podales 3 razy bledne haslo.Poczekaj przez 3 sekundy przed kolejna proba." << endl;
            }
        }
    }

    if(!znalezionyUzytkownik)   //jesli zmienna Znaleziony_znajomy==0
    {
        cout << "Nie ma uzytkownika z takim loginem." << endl;
    }

    Sleep(1500);
    return 0;
}

void Uzytkownicy::zmianaHasla( int idZalogowanegoUzytkownika)
{
    string hasloUzytkownika;
    int pozycjaZnalezionejOsoby = 0;

    cout << "Podaj nowe haslo: ";
    cin >> hasloUzytkownika;

    plikUzytkownikowAplikacji.wczytajUzytkownikowZPliku(uzytkownicy);

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if(itr -> pobierzIdUzytkownika() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[pozycjaZnalezionejOsoby].pobierzHasloUzytkownika() = hasloUzytkownika;
            uzytkownicy[pozycjaZnalezionejOsoby].ustawHasloUzytkownika(hasloUzytkownika);
            cout << "Haslo zostalo zmienione." << endl;
            Sleep(1500);
        }
        pozycjaZnalezionejOsoby++;
    }


    plikUzytkownikowAplikacji.zapiszDaneUzytkownikowDoPliku(uzytkownicy);
}

int Uzytkownicy::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    return idZalogowanegoUzytkownika;
}

