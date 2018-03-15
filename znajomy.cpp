#include <iostream>
#include <vector>
#include <fstream>
#include "znajomy.h"
#include "uzytkownik.h"

using namespace std;

Znajomy::Znajomy()
{
    numerIDZnajomego = 0;
    numerIDUzytkownika = 0;
    imie = "";
    nazwisko = "";
    numerTelefonu = "";
    mail = "";
    adres = "";
}

Znajomy::~Znajomy() {;}

int Znajomy::pobierzIdZnajomego()
{
    return numerIDZnajomego;
}

int Znajomy::pobierzIdUzytkownika()
{
    return numerIDUzytkownika;
}
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
    return numerTelefonu;
}
string Znajomy::pobierzMailZnajomego()
{
    return mail;
}
string Znajomy::pobierzAdresZnajomego()
{
    return adres;
}

void Znajomy::ustawNumerIDZnajomego(int numerIDZnajomego)
{
    this -> numerIDZnajomego = numerIDZnajomego;
}
void Znajomy::ustawNumerIDUzytkownika(int numerIDUzytkownika)
{
    this -> numerIDUzytkownika = numerIDUzytkownika;
}
void Znajomy::ustawImieZnajomego(string imie)
{
    this -> imie = imie;
}
void Znajomy::ustawNazwiskoZnajomego(string nazwisko)
{
    this -> nazwisko = nazwisko;
}
void Znajomy::ustawNumerTelefonuZnajomego(string numerTelefonu)
{
    this -> numerTelefonu = numerTelefonu;
}
void Znajomy::ustawMailZnajomego(string mail)
{
    this -> mail = mail;
}
void Znajomy::ustawAdresZnajomego(string adres)
{
    this -> adres = adres;
}
