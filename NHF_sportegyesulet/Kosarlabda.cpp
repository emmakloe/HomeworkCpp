#include "Kosarlabda.h"

int Kosarlabda::getExtra(){return pp;}

void Kosarlabda::cs_listaz(std::ostream& os){
    os << csapatnev << ", " << alapletszam << " fo, " << pp << " pompom lany" << std::endl;
}
