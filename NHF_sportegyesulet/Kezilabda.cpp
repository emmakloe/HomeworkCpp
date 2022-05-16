#include "Kezilabda.h"

int Kezilabda::getExtra(){return penz;}

void Kezilabda::cs_listaz(std::ostream& os){
    os << csapatnev << ", " << alapletszam << " fo, " << penz << " Ft tamogatas" << std::endl;
}
