#include <iostream>
#include "plik.h"

using namespace std;

bool Plik::czyPlikJestPusty(string nazwaPliku)
{
    int dlugosc;

    plik.open(nazwaPliku.c_str());
    plik.seekg(0, ios::end); // Przejœcie na koniec pliku

    dlugosc = plik.tellg();  // Sprawdzamy pozycjê, która odpowiada d³ugoœci pliku!

    if (dlugosc == 0)
        return 0;//"Plik jest pusty." << endl;
    else
        return 1; //"Plik zawiera dane." << endl;
}
