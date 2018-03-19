#include <iostream>
#include "plikznajomi.h"
#include <windows.h>
#include <cstdlib>
#include "konwersja.h"

using namespace std;


int PlikZnajomi::znajdzKolejnyNumerIDZnajomego ()
{
    string linia;
    string wyraz;
    int iloscPionowychKresek = 0;
    int ileZnakowWyjac = 0;
    int poczatek = 0 ;
    int najwiekszyNumerID = 0;
    int aktualnyNumerID = 0;
    int kolejnyNumerID = 0;
    fstream plik;

    plik.open("KsiazkaAdresowa.txt",ios::in);
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
                    wyraz = linia.substr (poczatek, ileZnakowWyjac);
                    aktualnyNumerID = atoi(wyraz.c_str());
                    if ( iloscPionowychKresek == 1 )
                    {
                        if (aktualnyNumerID > najwiekszyNumerID)
                        {
                            najwiekszyNumerID = aktualnyNumerID;
                        }
                    }
                }
            }
        }
    }
    kolejnyNumerID = najwiekszyNumerID + 1;
    return kolejnyNumerID;
}

void PlikZnajomi::dopiszZnajomegoDoPliku(Znajomy nowyZnajomy)
{
    string liniaZDanymiZnajomego = "";
    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);
    Konwersja liczba;

    if (plik.good() == true)
    {
        liniaZDanymiZnajomego += liczba.konwerjsaIntNaString(nowyZnajomy.pobierzIdZnajomego()) + '|';
        liniaZDanymiZnajomego += liczba.konwerjsaIntNaString(nowyZnajomy.pobierzIdUzytkownika()) + '|';
        liniaZDanymiZnajomego += nowyZnajomy.pobierzImieZnajomego() + '|';
        liniaZDanymiZnajomego += nowyZnajomy.pobierzNazwiskoZnajomego() + '|';
        liniaZDanymiZnajomego += nowyZnajomy.pobierzNumerTelefonuZnajomego() + '|';
        liniaZDanymiZnajomego += nowyZnajomy.pobierzMailZnajomego() + '|';
        liniaZDanymiZnajomego += nowyZnajomy.pobierzAdresZnajomego() + '|';

        plik << liniaZDanymiZnajomego << endl;
        liniaZDanymiZnajomego = "";

        plik.close();
        cout << "Dane zostaly zapisane." << endl;
        system("pause");
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac do niego danych." << endl;
        system("pause");
    }
}

void PlikZnajomi::zapiszZnajomychUzytkownikaDoWektora (vector <Znajomy> &znajomi, string linia, int iloscZnajomych)
{
    string wyraz;
    int iloscPionowychKresek = 0;
    int ileZnakowWyjac = 0;
    int poczatek = 0 ;

    Znajomy nowyZnajomy;

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
                nowyZnajomy.ustawNumerIDZnajomego(atoi(wyraz.c_str()));
                break;
            case 2:
                nowyZnajomy.ustawNumerIDUzytkownika(atoi(wyraz.c_str()));
                break;
            case 3:
                nowyZnajomy.ustawImieZnajomego(wyraz);
                break;
            case 4:
                nowyZnajomy.ustawNazwiskoZnajomego(wyraz);
                break;
            case 5:
                nowyZnajomy.ustawNumerTelefonuZnajomego(wyraz);
                break;
            case 6:
                nowyZnajomy.ustawMailZnajomego(wyraz);
                break;
            case 7:
                nowyZnajomy.ustawAdresZnajomego(wyraz);
                break;
            }
            poczatek = poczatek + ileZnakowWyjac + 1;
        }
    }
    znajomi.push_back(nowyZnajomy);
}

void PlikZnajomi::wczytajZnajomychZPliku(vector <Znajomy> &znajomi, int idZalogowanegoUzytkownika)
{
    string linia;
    string wyraz;
    int iloscPionowychKresek = 0;
    int ileZnakowWyjac = 0;
    int poczatek = 0 ;
    int idUzytkownikaZPliku = 0;
    int iloscZnajomych = 0;
    fstream plik;

    znajomi.clear();
    plik.open("KsiazkaAdresowa.txt",ios::in); // aby otworzyc plik do odczytu
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
                    wyraz = linia.substr (poczatek, ileZnakowWyjac);
                    idUzytkownikaZPliku = atoi(wyraz.c_str());
                    if ( iloscPionowychKresek == 2 && idZalogowanegoUzytkownika == idUzytkownikaZPliku)
                    {
                        iloscZnajomych++;
                        zapiszZnajomychUzytkownikaDoWektora(znajomi, linia, iloscZnajomych);
                        break;
                    }
                    poczatek = poczatek + ileZnakowWyjac + 1;
                }
            }
        }
        plik.close();
    }
}

void PlikZnajomi::usunLinieZPliku (int idZalogowanegoUzytkownika)
{
    vector <string> linieDoUsuniecia;
    string linia;
    string wyraz;
    int iloscPionowychKresek = 0;
    int ileZnakowWyjac = 0;
    int poczatek = 0 ;
    int idUzytkownikaZPliku;
    bool znalezionaLinia;

    fstream plik;
    ofstream nowyPlik;

    linieDoUsuniecia.clear();
    plik.open("KsiazkaAdresowa.txt", ios::in); // aby otworzyc plik do odczytu
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
                    idUzytkownikaZPliku = atoi(wyraz.c_str());
                    if ( iloscPionowychKresek == 2 && idZalogowanegoUzytkownika == idUzytkownikaZPliku)
                    {
                        linieDoUsuniecia.push_back(linia);
                        break;
                    }
                    poczatek = poczatek + ileZnakowWyjac + 1;
                }
            }
        }
        plik.close();
    }

    nowyPlik.open("PlikBezLinii.txt");
    plik.open("KsiazkaAdresowa.txt", ios::in);

    while (getline(plik,linia))
    {
        znalezionaLinia = 0;
        for( int i = 0; i < linieDoUsuniecia.size(); i++ )
        {
            if ( linia == linieDoUsuniecia[i])
            {
                znalezionaLinia = 1;
            }
        }
        if (znalezionaLinia == 0)
            nowyPlik << linia << endl;

    }

    nowyPlik.close();
    plik.close();
    remove("KsiazkaAdresowa.txt"); // remove usuwa plik, aby usunac plik musi byc on zamkniety dotyczy to wszystkich funkcji ktorych sie uzywa
    rename("PlikBezLinii.txt","KsiazkaAdresowa.txt");
}

void PlikZnajomi::zapiszDaneZnajomychDoPliku(vector <Znajomy> &znajomi, int idZalogowanegoUzytkownika)
{
    fstream plik;
    string liniaZDanymiZnajomego = "";
    Konwersja liczba;

    usunLinieZPliku(idZalogowanegoUzytkownika);

    plik.open("KsiazkaAdresowa.txt", ios::out | ios::app);
    if (plik.good() == true)
    {
        for (vector <Znajomy>::iterator itr = znajomi.begin(); itr != znajomi.end(); itr++)
        {
            liniaZDanymiZnajomego += liczba.konwerjsaIntNaString(itr -> pobierzIdZnajomego()) + '|';
            liniaZDanymiZnajomego += liczba.konwerjsaIntNaString(itr -> pobierzIdUzytkownika()) + '|';
            liniaZDanymiZnajomego += itr -> pobierzImieZnajomego() + '|';
            liniaZDanymiZnajomego += itr -> pobierzNazwiskoZnajomego() + '|';
            liniaZDanymiZnajomego += itr -> pobierzNumerTelefonuZnajomego() + '|';
            liniaZDanymiZnajomego += itr -> pobierzMailZnajomego() + '|';
            liniaZDanymiZnajomego += itr -> pobierzAdresZnajomego() + '|';

            plik << liniaZDanymiZnajomego << endl;
            liniaZDanymiZnajomego = "";
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
