#ifndef PLIK_H
#define PLIK_H

#include <iostream>
#include <fstream>

using namespace std;

/*
Klasa  zawiera funkcje czy plik jest pusty.
*/

class Plik
{
    fstream plik;

public:
    bool czyPlikJestPusty(string nazwaPliku);
};

#endif
