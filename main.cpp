#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "uzytkownicy.h"
#include "ksiazkaadresowa.h"

using namespace std;

int main()
{
    Uzytkownicy listaUzytkownikow;

    char wybranaPozycjaMenu;

    while(1)
    {
        if(listaUzytkownikow.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            system("cls");
            cout << "1.Rejestracja" << endl;
            cout << "2.Logowanie" << endl;
            cout << "9.Zamknij program" << endl;
            cin >> wybranaPozycjaMenu;

            switch(wybranaPozycjaMenu)
            {
            case '1':
                listaUzytkownikow.rejestracjaUzytkownika();

                break;
            case '2':
                listaUzytkownikow.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            }
        }
        else if(listaUzytkownikow.pobierzIdZalogowanegoUzytkownika() > 0)
        {
            KsiazkaAdresowa listaZnajomych(listaUzytkownikow.pobierzIdZalogowanegoUzytkownika());
            system("cls");
            cout<< "Ksiazka adresowa."<<endl<<endl;
            cout << "1.Zapisz nowego znajomego." << endl;
            cout << "2.Wyszukaj znajomego." << endl;
            cout << "3.Wyswietl liste znajomych." << endl;
            cout << "4.Edytuj kontakt." << endl;
            cout << "5.Usun kontakt." << endl;
            cout << "6.Zmien haslo." << endl;
            cout << "9.Wyloguj sie." << endl<<endl;
            cin>> wybranaPozycjaMenu;

            switch(wybranaPozycjaMenu)
            {
            case '1':
                listaZnajomych.zapiszNowegoZnajomego();
                break;
            case '2':

                system("cls");
                cout<< "Wyszukiwanie znajomego." <<endl<< endl;
                cout<<"1.Wyszukiwanie wg imienia." <<endl;
                cout<<"2.Wyszukiwanie wg nazwiska." <<endl;
                cout<<"9.Zakoncz wyszukiwanie."<< endl;
                cin>> wybranaPozycjaMenu;

                switch(wybranaPozycjaMenu)
                {
                case '1':
                    listaZnajomych.szukajImie();
                    break;
                case '2':
                    listaZnajomych.szukajNazwisko();
                    break;
                case '9':
                    system("pause");
                }
                break;
            case '3':
                listaZnajomych.wyswietlWszystkichZnajomych();
                break;
            case '4':
                listaZnajomych.edytujKontakt();
                break;
            case '5':
                listaZnajomych.usunKontakt();
                break;
            case '6':
                listaUzytkownikow.zmianaHasla();
                break;
            case '9':
                listaUzytkownikow.wylogowanieUzytkownika();
                break;
            }
        }
    }

    return 0;
}

