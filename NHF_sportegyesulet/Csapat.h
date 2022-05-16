#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;


class Csapat{
protected:
    std::string csapatnev;
    int alapletszam;
    int tipus;  /* Hogy meg tudjam különböztetni a sportágakat; kosár=1, foci=2, kézi=3 */
public:
    Csapat(){}
    Csapat(std::string ujnev, int ujletszam, int tipus) : csapatnev(ujnev), alapletszam(ujletszam), tipus(tipus) {} /*Konstruktor*/
    int getTipus();
    std::string getCsapatnev();
    int getAlapletszam();
    virtual int getExtra()=0;
    virtual void cs_listaz(std::ostream& os)=0; /*Virtuális listázó fv*/
    virtual ~Csapat(){} /*Virtuális destruktor*/

};

#endif // CSAPAT_H_INCLUDED
