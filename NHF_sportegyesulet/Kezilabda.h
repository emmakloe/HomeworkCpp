#ifndef KEZILABDA_H_INCLUDED
#define KEZILABDA_H_INCLUDED

#include "Csapat.h"
#include <iostream>
#include <string>
using namespace std;


class Kezilabda : public Csapat{
    int penz;
public:
    Kezilabda(std::string csapatnev, int alapletszam, int tipus, int penz) : Csapat(csapatnev, alapletszam, tipus), penz(penz){} /*Konstruktor*/
    int getExtra(); /* Visszaadja a támogatás összegét */
    void cs_listaz(std::ostream& os); /*Listázás*/
};

#endif // KEZILABDA_H_INCLUDED
