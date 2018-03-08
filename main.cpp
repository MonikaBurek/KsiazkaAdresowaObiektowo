#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include "uzytkownicy.h"

using namespace std;

int main()
{

    Uzytkownicy ksiazka1;
    int idZalogowanegoUzytkownika = 0;

    char wybranaPozycjaMenu;

    while(1)
    {
        if(idZalogowanegoUzytkownika == 0)
        {
            system("cls");
            cout << "1.Rejestracja" << endl;
            cout << "2.Logowanie" << endl;
            cout << "9.Zamknij program" << endl;
            cin >> wybranaPozycjaMenu;

            switch(wybranaPozycjaMenu)
            {
            case '1':
                ksiazka1.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika = ksiazka1.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            }
        }
else
        {
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
           /* case '1':

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

                    break;
                case '2':

                    break;
                case '9':
                    system("pause");
                }
                break;
            case '3':

                break;
            case '4':
            ;
                break;
            case '5':
               */
                break;
            case '6':
                ksiazka1.zmianaHasla(idZalogowanegoUzytkownika);
                break;
            case '9':
                idZalogowanegoUzytkownika = ksiazka1.wylogowanieUzytkownika();
                break;
            }
        }
    }





    return 0;
}
