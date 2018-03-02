#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
/*
Klasa na podstawie, ktorej jest tworzony obiekt uzytkownik (z prywatnymipolamioraz publicznymi getterami i setterami).
*/
class Uzytkownik
{
    int idUzytkownika;
    string nazwa;
    string haslo;

public:
// Konstruktor domyslny
    Uzytkownik()
    {
        idUzytkownika = 0;
        nazwa = "";
        haslo = "";
    }

// Konstruktor inicjiujacy atrybuty
    Uzytkownik(int numberIDUser, string name, string password)
    {
        idUzytkownika = numberIDUser;
        nazwa = name;
        haslo = password;
    }

//Ustawia numer ID uzytkownika
    void setIdUzytkownika(int numberIDUser)
    {
        idUzytkownika = numberIDUser;
    }

//Zwraca numer ID uzytkownika
    int getIdUzytkownika()
    {
        return idUzytkownika;
    }

    void setNazwaUzytkownika(string name)
    {
        nazwa = name;
    }

    string getNazwaUzytkownika()
    {
        return nazwa;
    }

    void setHasloUzytkownika(string password)
    {
        haslo = password;
    }

    string getHasloUzytkownika()
    {
        return haslo;
    }
};
/*
Klasa odpowiedzialna m.in. za logowanie, rejestrację, zmianę hasła, wylogowanie.
*/

class Uzytkownicy :public Uzytkownik
{
    vector <Uzytkownik> uzytkownicy;
    int idZalogowanegoUzytkownika = 0;

public:
    void rejestracjaUzytkownika()
    {
        string nazwaUzytkownika, hasloUzytkownika;
        int numerIDUzytkownika;

        cout << "Podaj nazwe uzytkownika: ";
        cin >> nazwaUzytkownika;

        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            while(itr -> getNazwaUzytkownika() == nazwaUzytkownika)
            {
                cout << "Taki uztkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
                cin >> nazwaUzytkownika;
            }
        }

        cout << "Podaj haslo: ";
        cin >> hasloUzytkownika;

        if (uzytkownicy.empty() == true)  // je¿eli ksia¿ka adresowa jest pusta
        {
            numerIDUzytkownika = 1;           // to nowy adresat ma id=1
        }
        else
        {
            numerIDUzytkownika = uzytkownicy.back().getIdUzytkownika() + 1; // w przeciwnym przypadku pobierz id ostatniej osoby z ksi¹¿ki adresowej i zwiêksz wartoœæ o jeden.
        }

        setNazwaUzytkownika(nazwaUzytkownika);
        setHasloUzytkownika(hasloUzytkownika);
        setIdUzytkownika(numerIDUzytkownika);

        uzytkownicy.push_back(Uzytkownik(getIdUzytkownika(), getNazwaUzytkownika(), getHasloUzytkownika()));

        cout<< "Konto zalozone." <<endl;
        Sleep(1000);
    }

    int logowanieUzytkownika()
    {
        string nazwaUzytkownika, hasloUzytkownika;
        bool znalezionyUzytkownik = 0;
        int proby = 0;
        cout << "Podaj nazwe uzytkownika: ";
        cin >>  nazwaUzytkownika;

        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            if(itr -> getNazwaUzytkownika() == nazwaUzytkownika)
            {
                znalezionyUzytkownik = 1;
                for(int iloscProb = 0; iloscProb < 3; iloscProb++)
                {
                    proby = iloscProb + 1;
                    cout << "Podaj haslo. Pozostalo prob " << 3 - iloscProb << ":";
                    cin >> hasloUzytkownika;
                    if (itr -> getHasloUzytkownika() == hasloUzytkownika)
                    {
                        cout<< "Zalogowales sie."<<endl;
                        idZalogowanegoUzytkownika = itr -> getIdUzytkownika();
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

    void zmianaHasla()
    {
        string hasloUzytkownika;
        int pozycjaZnalezionejOsoby = 0;
        cout << "Podaj nowe haslo: ";
        cin >> hasloUzytkownika;

        for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
        {
            if(itr -> getIdUzytkownika() == idZalogowanegoUzytkownika)
            {
                uzytkownicy[pozycjaZnalezionejOsoby].getHasloUzytkownika() = hasloUzytkownika;
                cout << "Haslo zostalo zmienione"<< endl;
                Sleep(1500);
            }
            pozycjaZnalezionejOsoby++;
        }
        setHasloUzytkownika(hasloUzytkownika);
    }

    int wylogowanieUzytkownika()
    {
        idZalogowanegoUzytkownika = 0;
        return idZalogowanegoUzytkownika;
    }
};

int main()
{


    Uzytkownicy ksiazka;
    ksiazka.rejestracjaUzytkownika();
    ksiazka.logowanieUzytkownika();
    ksiazka.zmianaHasla();
    ksiazka.wylogowanieUzytkownika();





    return 0;
}
