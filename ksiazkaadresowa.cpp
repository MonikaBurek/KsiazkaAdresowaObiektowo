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

    cout << "Dane znajomego zostaly zapisne." << endl;
    Sleep(1000);
}

void KsiazkaAdresowa::szukajImie(int idZalogowanegoUzytkownika)
{
    plikZnajomiUzytkownika.wczytajZnajomychZPliku(znajomi,idZalogowanegoUzytkownika);

    string poszukiwaneImie;
    bool znalezionyZnajomy = 0;
    cout << endl << "Podaj imie znajomego, ktorego wyszukac: ";
    cin >> poszukiwaneImie;

    for (vector <Znajomy>::iterator itr = znajomi.begin(); itr != znajomi.end(); itr++)
    {
        if (itr -> pobierzImieZnajomego() == poszukiwaneImie)
        {
            znalezionyZnajomy = 1;
            cout << endl;
            cout << "Numer ID Znajomego: " << itr -> pobierzIdZnajomego() << endl;
            cout << itr -> pobierzImieZnajomego() << " " << itr -> pobierzNazwiskoZnajomego() << endl;
            cout << "Numer telefonu: " << itr -> pobierzNumerTelefonuZnajomego() << endl;
            cout << "Mail: " << itr -> pobierzMailZnajomego() << endl;
            cout << "Adres: " << itr -> pobierzAdresZnajomego() << endl;
            cout << endl;
        }
    }

    if(!znalezionyZnajomy)   //jesli zmienna Znaleziony_znajomy==0
    {
        cout << endl << "Nie znaleziono osoby o tym imieniu." << endl << endl;
    }
    system("pause");
}

void KsiazkaAdresowa::szukajNazwisko(int idZalogowanegoUzytkownika)
{
    plikZnajomiUzytkownika.wczytajZnajomychZPliku(znajomi,idZalogowanegoUzytkownika);

    string poszukiwaneNazwisko;
    bool znalezionyZnajomy = 0;
    cout << endl << "Podaj nazwisko znajomego, ktorego wyszukac: ";
    cin >> poszukiwaneNazwisko;

    for (vector <Znajomy>::iterator itr = znajomi.begin(); itr != znajomi.end(); itr++)
    {
        if (itr -> pobierzNazwiskoZnajomego() == poszukiwaneNazwisko)
        {
            znalezionyZnajomy = 1;
            cout << endl;
            cout << "Numer ID Znajomego: " << itr -> pobierzIdZnajomego() << endl;
            cout << itr -> pobierzImieZnajomego() << " " << itr -> pobierzNazwiskoZnajomego() << endl;
            cout << "Numer telefonu: " << itr -> pobierzNumerTelefonuZnajomego() << endl;
            cout << "Mail: " << itr -> pobierzMailZnajomego() << endl;
            cout << "Adres: " << itr -> pobierzAdresZnajomego() << endl;
            cout << endl;
        }
    }

    if(!znalezionyZnajomy)   //jesli zmienna Znaleziony_znajomy==0
    {
        cout << endl << "Nie znaleziono osoby o tym imieniu." << endl << endl;
    }
    system("pause");
}

void KsiazkaAdresowa::wyswietlWszystkichZnajomych(int idZalogowanegoUzytkownika)
{
    plikZnajomiUzytkownika.wczytajZnajomychZPliku(znajomi,idZalogowanegoUzytkownika);

    for (vector <Znajomy>::iterator itr = znajomi.begin(); itr != znajomi.end(); itr++)
    {
        cout << endl;
        cout << "Numer ID Znajomego: " << itr -> pobierzIdZnajomego() << endl;
        cout << itr -> pobierzImieZnajomego() << " " << itr -> pobierzNazwiskoZnajomego() << endl;
        cout << "Numer telefonu: " << itr -> pobierzNumerTelefonuZnajomego() << endl;
        cout << "Mail: " << itr -> pobierzMailZnajomego() << endl;
        cout << "Adres: " << itr -> pobierzAdresZnajomego() << endl;
        cout << endl;
    }
    system("pause");
}

void KsiazkaAdresowa::edytujKontakt(int idZalogowanegoUzytkownika)
{
    string numerTelefonu, mail, adres;
    char wybranaPozycjaMenu;

    int poszukiwanyNumerID;
    bool znalezionyZnajomy = 0;
    int pozycjaZnalezionejOsoby = 0;

    plikZnajomiUzytkownika.wczytajZnajomychZPliku(znajomi, idZalogowanegoUzytkownika);

    cout << "Wyszukanie znajomego. Podaj numer ID znajomego: ";
    cin >> poszukiwanyNumerID;

    for (vector <Znajomy>::iterator itr = znajomi.begin(); itr != znajomi.end(); itr++)
    {
        if (itr -> pobierzIdZnajomego() == poszukiwanyNumerID)
        {
            znalezionyZnajomy = 1;
            system("cls");
            cout << "Edycja kontaktu." << endl;
            cout << endl;
            cout << "Numer ID Znajomego: " << itr -> pobierzIdZnajomego() << endl;
            cout << itr -> pobierzImieZnajomego() << " " << itr -> pobierzNazwiskoZnajomego() << endl;
            cout << "Numer telefonu: " << itr -> pobierzNumerTelefonuZnajomego() << endl;
            cout << "Mail: " << itr -> pobierzMailZnajomego() << endl;
            cout << "Adres: " << itr -> pobierzAdresZnajomego() << endl;
            cout << endl;

            cout << "1.Edytuj numer telefonu." << endl;
            cout << "2.Edytuj adres mailowy." << endl;
            cout << "3.Edytuj adres kontaktowy." << endl;
            cout << "4.Edytuj wszystkie informacje." << endl;
            cout << "9.Zakoncz edycje." << endl<<endl;
            cin>> wybranaPozycjaMenu;

            switch(wybranaPozycjaMenu)
            {
            case '1':
                cout << "Podaj nowy numer telefonu: ";
                cin.sync();
                getline(cin,numerTelefonu);
                znajomi[pozycjaZnalezionejOsoby].pobierzNumerTelefonuZnajomego() = numerTelefonu;
                znajomi[pozycjaZnalezionejOsoby].ustawNumerTelefonuZnajomego(numerTelefonu);
                break;
            case '2':
                cout << "Podaj nowy adres mailowy: ";
                cin >>  mail;
                znajomi[pozycjaZnalezionejOsoby].pobierzMailZnajomego() = mail;
                znajomi[pozycjaZnalezionejOsoby].ustawMailZnajomego(mail);
                break;
            case '3':
                cout << "Podaj nowy adres kontaktowy: ";
                cin.sync();
                getline(cin,adres);
                znajomi[pozycjaZnalezionejOsoby].pobierzAdresZnajomego() = adres;
                znajomi[pozycjaZnalezionejOsoby].ustawAdresZnajomego(adres);
                break;
            case '4':
                cout << "Podaj nowy numer telefonu: ";
                cin.sync();
                getline(cin,numerTelefonu);
                cout << "Podaj nowy adres mailowy: ";
                cin >>  mail;
                cout << "Podaj nowy adres kontaktowy: ";
                cin.sync();
                getline(cin,adres);

                znajomi[pozycjaZnalezionejOsoby].pobierzNumerTelefonuZnajomego() = numerTelefonu;
                znajomi[pozycjaZnalezionejOsoby].pobierzMailZnajomego() = mail;
                znajomi[pozycjaZnalezionejOsoby].pobierzAdresZnajomego() = adres;

                znajomi[pozycjaZnalezionejOsoby].ustawNumerTelefonuZnajomego(numerTelefonu);
                znajomi[pozycjaZnalezionejOsoby].ustawMailZnajomego(mail);
                znajomi[pozycjaZnalezionejOsoby].ustawAdresZnajomego(adres);

                break;
            case '9':
                system("pause");
                break;
            }
            cout << "Edycja kontaktu przebiegla pomyslnie." << endl << endl;

        }
        pozycjaZnalezionejOsoby++;
    }

    if(!znalezionyZnajomy)   //jesli zmienna Znaleziony_znajomy==0
    {
        cout << endl << "Nie znaleziono osoby o podanym: imieniu i nazwisku." << endl << endl;
        system("pause");
    }

    plikZnajomiUzytkownika.zapiszDaneZnajomychDoPliku(znajomi,idZalogowanegoUzytkownika);
}

void KsiazkaAdresowa::usunKontakt(int idZalogowanegoUzytkownika)
{
    int poszukiwanyNumerID;

    plikZnajomiUzytkownika.wczytajZnajomychZPliku(znajomi,idZalogowanegoUzytkownika);

    cout << "Wyszukanie znajomego. Podaj numer ID znajomego: ";
    cin >> poszukiwanyNumerID;

    for (vector <Znajomy>::iterator itr = znajomi.begin(); itr != znajomi.end(); itr++)
    {
        if (itr -> pobierzIdZnajomego() == poszukiwanyNumerID)
        {
            itr = znajomi.erase(itr);
            cout << "Kontakt zostal usuniety." << endl << endl;
            system("pause");
            break;
        }
    }

    plikZnajomiUzytkownika.zapiszDaneZnajomychDoPliku(znajomi,idZalogowanegoUzytkownika);
}

