#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

string konwerjsaIntNaString (int liczba)
{
    ostringstream ss;
    ss << liczba;
    string lancuch = ss.str();
    return lancuch;
}

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
Klasa odpowiedzialna za operacje na pliku Uzytkownicy.txt
*/
class PlikUzytkownicy :public virtual Uzytkownik
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
                            setIdUzytkownika(atoi(wyraz.c_str()));
                            break;
                        case 2:
                            setNazwaUzytkownika(wyraz);
                            break;
                        case 3:
                            setHasloUzytkownika(wyraz);
                            break;
                        }
                        poczatek = poczatek + ileZnakowWyjac + 1;
                    }
                }

                uzytkownicy.push_back(Uzytkownik(getIdUzytkownika(), getNazwaUzytkownika(), getHasloUzytkownika()));
                cout << getIdUzytkownika() << getNazwaUzytkownika() << getHasloUzytkownika() << endl;
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
                liniaZDanymiUzytkownika += konwerjsaIntNaString(itr -> getIdUzytkownika()) + '|';
                liniaZDanymiUzytkownika += itr -> getNazwaUzytkownika() + '|';
                liniaZDanymiUzytkownika += itr -> getHasloUzytkownika() + '|';

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

};

/*
Klasa odpowiedzialna m.in. za logowanie, rejestrację, zmianę hasła, wylogowanie.
*/
class Uzytkownicy: public Uzytkownik, public PlikUzytkownicy
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
  //      setHasloUzytkownika(hasloUzytkownika);
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
    //PlikUzytkownicy obiekt;
    //obiekt.wczytajUzytkownikowZPliku();
   // obiekt.zapiszDaneUzytkownikowDoPliku();


    return 0;
}
