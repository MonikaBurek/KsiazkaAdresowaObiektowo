#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "uzytkownicy.h"

using namespace std;

/*string konwerjsaIntNaString (int liczba)
{
    ostringstream ss;
    ss << liczba;
    string lancuch = ss.str();
    return lancuch;
}


Klasa odpowiedzialna za operacje na pliku Uzytkownicy.txt

class PlikUzytkownicy
{

    fstream plik;

public:
    void wczytajUzytkownikowZPliku( vector <Uzytkownik> &uzytkownicy)
    {
        string linia;
        string wyraz;
        int iloscPionowychKresek = 0;
        int ileZnakowWyjac = 0;
        int poczatek = 0 ;

        uzytkownicy.clear();
        plik.open("Uzytkownicy.txt",ios::in); // aby otworzyc plik do odczytu
        if (plik.good() == true)
        {
            while (pobierzline(plik,linia))
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
                            ustawIdUzytkownika(atoi(wyraz.c_str()));
                            break;
                        case 2:
                            ustawNazwaUzytkownika(wyraz);
                            break;
                        case 3:
                            ustawHasloUzytkownika(wyraz);
                            break;
                        }
                        poczatek = poczatek + ileZnakowWyjac + 1;
                    }
                }

                uzytkownicy.push_back(Uzytkownik(pobierzIdUzytkownika(), pobierzNazwaUzytkownika(), pobierzHasloUzytkownika()));
                cout << pobierzIdUzytkownika() << pobierzNazwaUzytkownika() << pobierzHasloUzytkownika() << endl;
            }
            plik.close();
        }
    }

    void zapiszDaneUzytkownikowDoPliku ( vector <Uzytkownik> &uzytkownicy)
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

};*/



int main()
{

    Uzytkownicy ksiazka1;

    ksiazka1.rejestracjaUzytkownika();
    ksiazka1.logowanieUzytkownika();

    ksiazka1.wylogowanieUzytkownika();


    return 0;
}
