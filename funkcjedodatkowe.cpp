#include <iostream>
#include "funkcjedodatkowe.h"

using namespace std;

string konwerjsaIntNaString (int liczba)
{
    ostringstream ss;
    ss << liczba;
    string lancuch = ss.str();
    return lancuch;
}
