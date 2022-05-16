#ifndef CSAPAT_H_INCLUDED
#define CSAPAT_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;


class Csapat{
protected:
    std::string csapatnev;
    int alapletszam;
    int tipus;  /* Hogy meg tudjam k�l�nb�ztetni a sport�gakat; kos�r=1, foci=2, k�zi=3 */
public:
    Csapat(){}
    Csapat(std::string ujnev, int ujletszam, int tipus) : csapatnev(ujnev), alapletszam(ujletszam), tipus(tipus) {} /*Konstruktor*/
    int getTipus();
    std::string getCsapatnev();
    int getAlapletszam();
    virtual int getExtra()=0;
    virtual void cs_listaz(std::ostream& os)=0; /*Virtu�lis list�z� fv*/
    virtual ~Csapat(){} /*Virtu�lis destruktor*/

};

#endif // CSAPAT_H_INCLUDED
