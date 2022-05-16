#include "Labdarugas.h"

int Labdarugas::getExtra(){return edzokszama;}

void Labdarugas::cs_listaz(std::ostream& os){
    os << csapatnev << ", " << alapletszam << " fo, " << edzokszama << " edzo" << std::endl;
}
