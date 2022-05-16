#ifndef SPORTEGYESULET_H_INCLUDED
#define SPORTEGYESULET_H_INCLUDED

#include <iostream>
#include <fstream>
#include "Csapat.h"
#include "Kosarlabda.h"
#include "Labdarugas.h"
#include "Kezilabda.h"
using namespace std;

class Sportegyesulet {
    Csapat** csapatok; /*Csapatok eltárolása*/
    int csapatokszama;
    Sportegyesulet(const Sportegyesulet& egy); /* Copy ctor */
    Sportegyesulet& operator=(const Sportegyesulet& egy);
public:
    Sportegyesulet(); /*Konstruktor*/
    Csapat* operator[](int idx); /*Indexelõ operátor*/
    int getCsapatokszama();
    int keres(std::string nev, int type); /*Keresem hogy melyik indexű csapatot szeretnék törölni*/
    void listaz(int type, std::ostream& os); /*Csapatok listázása*/
    void uj(Csapat* uj); /* Új csapat hozzáadása */
    void torol(std::string nev, int type); /*Csapat törlése*/
    void adatbazis_beolvas(); /*Fájlból beolvas*/
    void adatbazis_feltolt(); /*Fájlba ír*/
    ~Sportegyesulet(); /*Destruktor*/

};

#endif // SPORTEGYESULET_H_INCLUDED
