#ifndef LABDARUGAS_H_INCLUDED
#define LABDARUGAS_H_INCLUDED

#include "Csapat.h"
#include <iostream>
#include <string>
using namespace std;

class Labdarugas : public Csapat{
    int edzokszama;
public:
    Labdarugas(std::string csapatnev, int alapletszam, int tipus, int edzokszama) : Csapat(csapatnev, alapletszam, tipus), edzokszama(edzokszama){} /*Konstruktor*/
    int getExtra(); /* Visszaadja az edzők számát */
    void cs_listaz(std::ostream& os); /*Listázás*/
};

#endif // LABDARUGAS_H_INCLUDED
