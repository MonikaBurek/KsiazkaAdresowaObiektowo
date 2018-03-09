#include <iostream>
#include "konwersja.h"

using namespace std;

string Konwersja::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string lancuch = ss.str();
    return lancuch;
}
