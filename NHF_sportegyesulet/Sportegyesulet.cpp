#include "Sportegyesulet.h"
#include "Csapat.h"

Sportegyesulet::Sportegyesulet(){
        csapatokszama = 0;
        csapatok = new Csapat*[csapatokszama];
    }

Sportegyesulet::Sportegyesulet(const Sportegyesulet& egy){
    this->csapatokszama=egy.csapatokszama;
    this->csapatok=new Csapat*[egy.csapatokszama];
    for(int i=0; i < egy.csapatokszama; i++){
        this->csapatok[i]=egy.csapatok[i];
    }
}

Sportegyesulet& Sportegyesulet::operator=(const Sportegyesulet& egy){
    this->csapatok=egy.csapatok;
    this->csapatokszama=egy.csapatokszama;
    return *this;
}

Csapat* Sportegyesulet::operator[](int idx){ /* Indexelõ operátor, segíti, hogy ne forduljon elõ túlindexelés */
    if(idx >= csapatokszama || idx < 0) throw std::out_of_range("Nincs ilyen indexu elem!");
    return csapatok[idx];
}

int Sportegyesulet::getCsapatokszama(){
    return csapatokszama;
}

int Sportegyesulet::keres(std::string nev, int type){ /* Segédfüggvény a törölhöz, visszaadja a megfelelõ indexet */
    int i=0;
    while(i < csapatokszama){
        if(type==csapatok[i]->getTipus() && nev == csapatok[i]->getCsapatnev())return i;
        else i++;
    }
    if(type!=csapatok[i-1]->getTipus() && i==csapatokszama) throw 420;
    return i;
}

void Sportegyesulet::uj(Csapat* ujcsapat){
    Csapat** uj = new Csapat*[csapatokszama + 1];
    for(int i = 0; i < csapatokszama; i++){
        uj[i] = csapatok[i];
    }
    uj[csapatokszama] = ujcsapat;
    delete[] csapatok;
    csapatokszama+=1;
    csapatok = uj;
}

void Sportegyesulet::torol(std::string nev, int type){
    if(csapatokszama == 0) throw("Egy csapat sincs a nyilvantartasban!");
    int idx;
    idx = keres(nev,type);
    if(idx < 0 || idx > csapatokszama) throw std::out_of_range("Nincs ilyen indexu csapat!");
    Csapat** uj = new Csapat*[csapatokszama - 1];
    for(int i = 0; i < idx; i++){
        uj[i] = csapatok[i];
    }
    for(int i = idx; i < csapatokszama-1; i++){
        uj[i] = csapatok[i+1];
    }
    delete csapatok[idx];
    delete[] csapatok;
    csapatokszama-=1;
    csapatok = uj;
}

void Sportegyesulet::listaz(int type, std::ostream& os){
    for(int i=0; i < csapatokszama; i++) {
        if(type==csapatok[i]->getTipus()){
           csapatok[i]->cs_listaz(os);
        }
    }
}

void Sportegyesulet::adatbazis_beolvas(){
    std::ifstream adatbazis("adatbazis.txt");
    std::string nev;
    int tipus, letszam, extra;

    if(adatbazis.is_open()){
        while(adatbazis >> tipus >> nev >> letszam >> extra){
            /* Beolvassa az egész sort és a tipustól függöen létrehozza a csapatot */
            switch(tipus){
            case(1):
                uj(new Kosarlabda(nev,letszam,tipus,extra));
                break;
            case(2):
                uj(new Labdarugas(nev,letszam,tipus,extra));
                break;
            case(3):
                uj(new Kezilabda(nev,letszam,tipus,extra));
                break;
            default:
                return;
            }
        }
        adatbazis.close();
    }
    else std::cout << "Nem sikerult megnyitni a fajlt!";
}

void Sportegyesulet::adatbazis_feltolt(){ /* A txt fájlt újratölti */
    std::ofstream adatbazis;
    adatbazis.open("adatbazis.txt", std::ofstream::out | std::ofstream::trunc);
    if(adatbazis.is_open()){
        for(int i=0; i < csapatokszama ; i++){
            adatbazis << csapatok[i]->getTipus() << " " << csapatok[i]->getCsapatnev() << " " << csapatok[i]->getAlapletszam() << " " << csapatok[i]->getExtra() << "\n";
        }
        adatbazis.close();
    }
    else std::cout << "Nem sikerult megnyitni fajlt!";
}

Sportegyesulet::~Sportegyesulet(){
    for (int i = 0; i < csapatokszama; i++)
        delete csapatok[i];
    delete[] csapatok;
}
