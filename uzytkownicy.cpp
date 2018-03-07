#include <iostream>
#include "uzytkownicy.h"
#include <windows.h>
#include <cstdlib>
#include "funkcjedodatkowe.h"


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

//-------------------------------------------------------------------------------------------------------------------------//

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
            //cout << uzytkownik.pobierzIdUzytkownika() << " " << endl;
            //cout << uzytkownik.pobierzNazwaUzytkownika() << " " << uzytkownik.pobierzHasloUzytkownika() << endl;
        }
        plik.close();
    }
}

void PlikUzytkownicy::zapiszDaneUzytkownikowDoPliku( vector <Uzytkownik> &uzytkownicy)
{
    string liniaZDanymiUzytkownika = "";
    plik.open("Uzytkownicy.txt", ios::out);

    if (plik.good() == true)
    {
        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {

            liniaZDanymiUzytkownika += konwerjsaIntNaString(itr -> pobierzIdUzytkownika()) + '|';
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

    if (plik.good() == true)
    {
            liniaZDanymiUzytkownika += konwerjsaIntNaString(nowyUzytkownik.pobierzIdUzytkownika()) + '|';
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

//------------------------------------------------------------------------------------------------------//

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

void Uzytkownicy::zmianaHasla(int idZalogowanegoUzytkownika)
{
    string hasloUzytkownika;
    int pozycjaZnalezionejOsoby = 0;
    cout << "Podaj nowe haslo: ";
    cin >> hasloUzytkownika;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if(itr -> pobierzIdUzytkownika() == idZalogowanegoUzytkownika)
        {
            uzytkownicy[pozycjaZnalezionejOsoby].pobierzHasloUzytkownika() = hasloUzytkownika;
            cout << "Haslo zostalo zmienione"<< endl;
            Sleep(1500);
        }
        pozycjaZnalezionejOsoby++;
    }
    uzytkownicy[pozycjaZnalezionejOsoby-1].ustawHasloUzytkownika(hasloUzytkownika);
    plikUzytkownikowAplikacji.zapiszDaneUzytkownikowDoPliku(uzytkownicy);
}

int Uzytkownicy::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    return idZalogowanegoUzytkownika;
}
