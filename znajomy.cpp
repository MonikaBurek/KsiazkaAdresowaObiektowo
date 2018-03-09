#include <iostream>
#include <vector>
#include <fstream>
#include "znajomy.h"

using namespace std;

Znajomy::Znajomy()
{
    numerIDZnajomego = 0;
    idUzytkownika = 0;
    imie = "";
    nazwisko = "";
    adres = "";
    numerTelefonu = "";
    mail = "";
}

Znajomy::~Znajomy() {;}

int Znajomy::pobierzIdZnajomego()
{
    return numerIDZnajomego;
}
/*int Znajomy::pobierzIdUzytkownika()
{
    return idUzytkownika
}*/
string Znajomy::pobierzImieZnajomego()
{
    return imie;
}
string Znajomy::pobierzNazwiskoZnajomego()
{
    return nazwisko;
}
string Znajomy::pobierzNumerTelefonuZnajomego()
{
    return adres;
}
string Znajomy::pobierzAdresZnajomego()
{
    return numerTelefonu;
}
string Znajomy::pobierzMailZnajomego()
{
    return mail;
}

void Znajomy::ustawNumerIDZnajomego(int numerIDZnajomego)
{
    this -> numerIDZnajomego = numerIDZnajomego;
}

void Znajomy::ustawIdUzytkownika(int idUzytkownika)
{
    this -> idUzytkownika = idUzytkownika;
}
void Znajomy::ustawImieZnajomego(string imie)
{
    this -> imie = imie;
}
void Znajomy::ustawNazwiskoZnajomego(string nazwisko)
{
    this -> nazwisko = nazwisko;
}
void Znajomy::ustawAdresZnajomego(string adres)
{
    this -> adres = adres;
}
void Znajomy::ustawNumerTelefonuZnajomego(string numerTelefonu)
{
    this -> numerTelefonu = numerTelefonu;
}
void Znajomy::ustawMailZnajomego(string mail)
{
    this -> mail = mail;
}

