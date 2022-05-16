#include "menu.h"

void fomenu(std::ostream& os){
        os << "********** Fomenu **********" << std::endl;
        os << "(1): Kosarlabda" << std::endl;
        os << "(2): Labdarugas" << std::endl;
        os << "(3): Kezilabda" << std::endl;
}

void almenu(std::ostream& os){
        os << "(0): Vissza a menube" << std::endl;
        os << "(1): Csapatok listazasa" << std::endl;
        os << "(2): Csapat hozzaadasa" << std::endl;
        os << "(3): Csapat torlese" << std::endl;
}

