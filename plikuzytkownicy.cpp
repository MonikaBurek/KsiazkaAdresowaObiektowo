#include <iostream>
#include "plikuzytkownicy.h"
#include <windows.h>
#include <cstdlib>
#include "konwersja.h"

using namespace std;


void PlikUzytkownicy::wczytajUzytkownikowZPliku( vector <Uzytkownik> &uzytkownicy)
{
    string linia;
    string wyraz;
    int iloscPionowychKresek = 0;
    int ileZnakowWyjac = 0;
    int poczatek = 0 ;
    Uzytkownik uzytkownik;

    uzytkownicy.clear();
    plik.open("Uzytkownicy.txt",ios::in); // aby otworzyc plik do odczytu
    if (plik.good() == true)
    {
        while (getline(plik,linia))
        {
            ileZnakowWyjac = 0;
            poczatek = 0;
            iloscPionowychKresek = 0;

            for (int i = 0; i < linia.size(); i++)
            {
                ileZnakowWyjac = i - poczatek;
                if (linia[i] == '|')
                {
                    iloscPionowychKresek++;
                    wyraz = linia.substr (poczatek,ileZnakowWyjac);
                    switch (iloscPionowychKresek)
                    {
                    case 1:
                        uzytkownik.ustawIdUzytkownika(atoi(wyraz.c_str()));
                        break;
                    case 2:
                        uzytkownik.ustawNazwaUzytkownika(wyraz);
                        break;
                    case 3:
                        uzytkownik.ustawHasloUzytkownika(wyraz);
                        break;
                    }
                    poczatek = poczatek + ileZnakowWyjac + 1;
                }
            }

            uzytkownicy.push_back(uzytkownik);
        }
        plik.close();
    }
}

void PlikUzytkownicy::zapiszDaneUzytkownikowDoPliku( vector <Uzytkownik> &uzytkownicy)
{
    string liniaZDanymiUzytkownika = "";
    plik.open("Uzytkownicy.txt", ios::out);
    Konwersja liczba;

    if (plik.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {

            liniaZDanymiUzytkownika += liczba.konwerjsaIntNaString(itr -> pobierzIdUzytkownika()) + '|';
            liniaZDanymiUzytkownika += itr -> pobierzNazwaUzytkownika() + '|';
            liniaZDanymiUzytkownika += itr -> pobierzHasloUzytkownika() + '|';

            plik << liniaZDanymiUzytkownika << endl;
            liniaZDanymiUzytkownika = "";
        }
        plik.close();
        cout << "Dane zostaly zapisne." << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
}

void PlikUzytkownicy::dopiszUzytkownikaDoPliku(Uzytkownik nowyUzytkownik)
{
    string liniaZDanymiUzytkownika = "";
    plik.open("Uzytkownicy.txt", ios::out | ios::app);
    Konwersja liczba;

    if (plik.good() == true)
    {
        liniaZDanymiUzytkownika += liczba.konwerjsaIntNaString(nowyUzytkownik.pobierzIdUzytkownika()) + '|';
        liniaZDanymiUzytkownika += nowyUzytkownik.pobierzNazwaUzytkownika() + '|';
        liniaZDanymiUzytkownika += nowyUzytkownik.pobierzHasloUzytkownika() + '|';

        plik << liniaZDanymiUzytkownika << endl;
        liniaZDanymiUzytkownika = "";

        plik.close();
        cout << "Dane zostaly zapisne." << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
}
