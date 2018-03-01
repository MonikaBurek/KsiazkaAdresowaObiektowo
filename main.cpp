#include <iostream>

using namespace std;
/*
Klasa na podstawie, ktorej jest tworzony obiekt uzytkownik (z prywatnymipolamioraz publicznymi getterami i setterami).
*/
class Uzytkownik
{
    int idUzytkownika;
    string nazwa;
    string haslo;

 public:

// Konstruktor domyslny
    Uzytkownik()
    {
        idUzytkownika = null;
        nazwa = null;
        haslo = null;
    }

// Konstruktor inicjiujacy atrybuty
    Uzytkownik(int numberID, string name, string password)
    {
        idUzytkownika = numberID;
        nazwa = name;
        haslo = password;
    }

 //Ustawia numer ID uzytkownika
 void setIdUzytkownika(int numberID)
 {
    idUzytkownika = numberID;
 }

 //Zwraca numer ID uzytkownika
 int getIdUzytkownika()
 {
     return idUzytkownika;
 }

 void setNazwaUzytkownika(string name)
 {
    nazwa = name;
 }

string getNazwaUzytkownika()
 {
     return nazwa;
 }

 void setHasloUzytkownika(string password)
 {
    haslo = password;
 }

string getHasloUzytkownika()
 {
     return haslo;
 }


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
