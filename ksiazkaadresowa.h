#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "plikznajomi.h"


using namespace std;

/*
Klasa odpowiedzialna m.in. za dodawanie nowego znajomego, edycje usuwanie, wyszukiwanie.
*/
class KsiazkaAdresowa
{
    vector <Znajomy> znajomi;
    PlikZnajomi plikZnajomiUzytkownika;

public:
  Znajomy podajDaneNowegoZnajomego(int idZalogowanegoUzytkownika);
  void zapiszNowegoZnajomego(int idZalogowanegoUzytkownika);
  void wyswietlWszystkichZnajomych();
  void szukajImie();
  void szukajNazwisko();
  void edytujKontakt ();
  void usunKontakt ();

};

#endif
