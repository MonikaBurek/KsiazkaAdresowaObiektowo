#ifndef PLIK_H
#define PLIK_H

#include <iostream>
#include <fstream>

using namespace std;
/*
Klasa  zawiera funkcj� czy plik jest pusty.
*/
class Plik
{
    fstream plik;

public:
    bool czyPlikJestPusty(string nazwaPliku);
};


#endif
