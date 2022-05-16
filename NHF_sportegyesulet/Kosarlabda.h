#ifndef KOSARLABDA_H_INCLUDED
#define KOSARLABDA_H_INCLUDED

#include "Csapat.h"
#include <iostream>
#include <string>
using namespace std;

class Kosarlabda : public Csapat{
    int pp;
public:
    Kosarlabda(std::string csapatnev, int alapletszam, int tipus, int pp) : Csapat(csapatnev, alapletszam, tipus), pp(pp){} /*Konstruktor*/
    int getExtra(); /* Visszaadja a pompom l�nyok sz�m�t */
    void cs_listaz(std::ostream& os); /*List�z�s*/
};

#endif // KOSARLABDA_H_INCLUDED
