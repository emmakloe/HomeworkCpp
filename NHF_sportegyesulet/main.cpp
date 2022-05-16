#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "gtest_lite.h"
#include "Sportegyesulet.h"
#include "Csapat.h"
#include "Labdarugas.h"
#include "Kosarlabda.h"
#include "Kezilabda.h"
#include <fstream>
#include "menu.h"
#include <sstream>
#include <algorithm>

using namespace std;

#define TESZTEK 1 /* Ha a TESZTEK értéke 1, akkor tesztelés van érvényben, ha 0, akkor a menü main-je aktív. */

#if TESZTEK == 1 /* TESZTEK aktív */
int main()
{
    TEST(ctor, dtor){
    Labdarugas la("FCB", 21, 2, 2);
    Kosarlabda ko("Lakers", 17, 1, 10);
    Kezilabda ke("Szkka", 16, 3, 200000);
    if(ko.getCsapatnev()=="Lakers" && ko.getAlapletszam()==17 && ko.getTipus()==1 && ko.getExtra()==10) SUCCEED();
    else FAIL();
    END}

    TEST(sportegyesulet, ujfelvetele){
        Kezilabda *ke1 = new Kezilabda("Szkka", 16, 3, 200000);
        Kezilabda *ke2 = new Kezilabda("GyETO", 18, 3, 600000);
        Kezilabda *ke3 = new Kezilabda("MTK", 17, 3, 400000);
        Sportegyesulet egyesulet;
        egyesulet.uj(ke1);
        egyesulet.uj(ke2);
        egyesulet.uj(ke3);
        if(egyesulet[1]->getCsapatnev()=="GyETO" && egyesulet[1]->getAlapletszam()==18 && egyesulet[1]->getTipus()==3 && egyesulet[1]->getExtra()==600000)  SUCCEED();
        else FAIL();
    END}

    TEST(sportegyesulet, beolvasas){
        Sportegyesulet egyesulet;
        egyesulet.adatbazis_beolvas();
        if(egyesulet[1]->getCsapatnev()=="FCB" && egyesulet[1]->getAlapletszam()==21 && egyesulet[1]->getTipus()==2 && egyesulet[1]->getExtra()==2) SUCCEED();
        else FAIL();
    END}

    TEST(sportegyesulet, fajlbair){
        Sportegyesulet egyesulet;
        Kosarlabda *ko1= new Kosarlabda("Lakers", 17, 1, 10);
        Labdarugas *l1= new Labdarugas("FCB", 21, 2, 2);
        Kezilabda *ke1= new Kezilabda("Szkka", 16, 3, 200000);
        egyesulet.uj(ko1);
        egyesulet.uj(l1);
        egyesulet.uj(ke1);
        egyesulet.adatbazis_feltolt();
        Sportegyesulet egy;
        egyesulet.adatbazis_beolvas();
        if(egyesulet[1]->getCsapatnev()=="FCB" && egyesulet[1]->getAlapletszam()==21 && egyesulet[1]->getTipus()==2 && egyesulet[1]->getExtra()==2) SUCCEED();
        else FAIL();
    END}

    TEST(sportegyesulet, csapatokszama){
        Sportegyesulet egyesulet;
        Kosarlabda *ko1= new Kosarlabda("Lakers", 17, 1, 10);
        Labdarugas *l1= new Labdarugas("FCB", 21, 2, 2);
        Kezilabda *ke1= new Kezilabda("Szkka", 16, 3, 200000);
        egyesulet.uj(ko1);
        egyesulet.uj(l1);
        egyesulet.uj(ke1);
        if(egyesulet.getCsapatokszama() == 3) SUCCEED();
        else FAIL();
    END}

    TEST(sportegyesulet, keres){
        Sportegyesulet egyesulet;
        std::string s1("Szkka");
        Kosarlabda *ko1= new Kosarlabda("Lakers", 17, 1, 10);
        Labdarugas *l1= new Labdarugas("FCB", 21, 2, 2);
        Kezilabda *ke1= new Kezilabda("Szkka", 16, 3, 200000);
        egyesulet.uj(ko1);
        egyesulet.uj(l1);
        egyesulet.uj(ke1);
        EXPECT_EQ(2, egyesulet.keres(s1,3));
    END}

    TEST(sportegyesulet, torol){
        Kosarlabda *ko1= new Kosarlabda("Lakers", 17, 1, 10);
        Kosarlabda *ko2= new Kosarlabda("CBulls", 16, 1, 11);
        Kosarlabda *ko3= new Kosarlabda("Warriors", 18, 1, 12);
        Sportegyesulet egyesulet;
        egyesulet.uj(ko1);
        egyesulet.uj(ko2);
        egyesulet.uj(ko3);
        egyesulet.torol("CBulls",1);
        if(egyesulet[1]->getCsapatnev()=="Warriors" && egyesulet[1]->getAlapletszam()==18 && egyesulet[1]->getTipus()==1 && egyesulet[1]->getExtra()==12) SUCCEED();
        else FAIL();
    END}

    TEST(sportegyesulet, torol_urestomb){
        Sportegyesulet egyesulet;
        EXPECT_ANY_THROW(egyesulet.torol("CBulls",1));
    END}

    TEST(sportegyesulet, kiir1){
        Sportegyesulet egyesulet;
        Labdarugas *l1= new Labdarugas("ManCity", 22, 2, 2);
        Labdarugas *l2= new Labdarugas("FCB", 21, 2, 2);
        egyesulet.uj(l1);
        egyesulet.uj(l2);
		std::stringstream ss;
		egyesulet.listaz(l1->getTipus(),ss);
        std::string s = ss.str();
        int cnt = std::count(s.begin(), s.end(), '\n');
        EXPECT_EQ(2, cnt);
    END}

    TEST(sportegyesulet, kiir2){
        Sportegyesulet egyesulet;
        Kosarlabda *ko1= new Kosarlabda("CBulls", 16, 1, 11);
        Kosarlabda *ko2= new Kosarlabda("Warriors", 18, 1, 12);
        egyesulet.uj(ko2);
        egyesulet.uj(ko1);
		std::stringstream ss;
		egyesulet.listaz(ko1->getTipus(),ss);
        std::string s = ss.str();
        int cnt = std::count(s.begin(), s.end(), '\n');
        EXPECT_EQ(2, cnt);
    END}

    TEST(sportegyesulet, kiir3){
        Sportegyesulet egyesulet;
        Kezilabda *ke1 = new Kezilabda("GyETO", 18, 3, 600000);
        Kezilabda *ke2 = new Kezilabda("MTK", 17, 3, 400000);
        egyesulet.uj(ke2);
        egyesulet.uj(ke1);
		std::stringstream ss;
		egyesulet.listaz(ke1->getTipus(),ss);
        std::string s = ss.str();
        int cnt = std::count(s.begin(), s.end(), '\n');
        EXPECT_EQ(2, cnt);
    END}

        TEST(menu, fomenu){
		std::stringstream ss;
		fomenu(ss);
        std::string s = ss.str();
        int cnt = std::count(s.begin(), s.end(), '\n');
        EXPECT_EQ(4, cnt);
    END}

        TEST(menu, almenu){
		std::stringstream ss;
		almenu(ss);
        std::string s = ss.str();
        int cnt = std::count(s.begin(), s.end(), '\n');
        EXPECT_EQ(4, cnt);
    END}

    TEST(csapat, gettype){
        Kosarlabda *ko1= new Kosarlabda("Lakers", 17, 1, 10);
        Sportegyesulet egyesulet;
        egyesulet.uj(ko1);
        if(egyesulet[0]->getTipus()==1) SUCCEED();
        else FAIL();
    END}

    TEST(csapat, getnev){
        Kosarlabda *ko1 = new Kosarlabda("Lakers", 17, 1, 10);
        Sportegyesulet egyesulet;
        egyesulet.uj(ko1);
        if(egyesulet[0]->getCsapatnev()=="Lakers") SUCCEED();
        else FAIL();
    END}

    TEST(csapat, getletszam){
        Kosarlabda *ko1= new Kosarlabda("Lakers", 17, 1, 10);
        Sportegyesulet egyesulet;
        egyesulet.uj(ko1);
        if(egyesulet[0]->getAlapletszam()==17) SUCCEED();
        else FAIL();
    END}

    TEST(csapat, getextra){
        Kosarlabda *ko1= new Kosarlabda("Lakers", 17, 1, 10);
        Sportegyesulet egyesulet;
        egyesulet.uj(ko1);
        if(egyesulet[0]->getExtra()==10) SUCCEED();
        else FAIL();
    END}

    return 0;
}
#endif // TESZTEK


#if TESZTEK == 0 /* Menü aktív */
int main()
{
    Sportegyesulet egyesulet;
    egyesulet.adatbazis_beolvas();
	int menupont = 0;
	int almenupont = 0;
	int hibas = 0;
	std::string nev;
	int letszam, extra, tipus;
	bool aktiv = true;


    do {
      if(menupont<5 && almenupont<5 && hibas<5){
        system("CLS");
        fomenu(std::cout);
        std::cin >> menupont;}
    switch(menupont){
    case 0:
        system("CLS");
        fomenu(std::cout);
        std::cin >> menupont;
    case 1:
        system("CLS");
        std::cout << "********** Kosarlabda **********" << std::endl;
        almenu(std::cout);
        std::cin >> almenupont;
        switch(almenupont){
        case 0:
            menupont=0;
            break;
        case 1:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            egyesulet.listaz(1,std::cout);
            std::cin >> almenupont;
            if(almenupont == 0) menupont=0;
            else {system("CLS");
                  std::cout << "Error!" << std::endl;}
            break;
        case 2:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            std::cout << "Csapat neve: ";
            std::cin >> nev;
            std::cout << "Letszam: ";
            std::cin >> letszam;
            std::cout << "Egyeb: ";
            std::cin >> extra;
            tipus=1;
            egyesulet.uj(new Kosarlabda(nev,letszam,tipus,extra));
            std::cout << "Sikeres letrehozas!" << std::endl;
            std::cin >> almenupont;
            break;
        case 3:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            egyesulet.listaz(1,std::cout);
            std::cout << std::endl;
            std::cout << "Csapat neve: ";
            std::cin >> nev;
            try{
            egyesulet.torol(nev,1);
            } catch(int x){ std::cout << "Nincs ilyen nevu csapat!" << std::endl;}
            std::cin >> almenupont;
            break;
        default:
            system("CLS");
            std::cout << "Nincs ilyen menupont!" << std::endl;
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cin >> hibas;
            if(hibas==0) menupont = 0;
            else menupont=4;
            break;
        }
        break;
    case 2:
        system("CLS");
        std::cout << "********** Labdarugas **********" << std::endl;
        almenu(std::cout);
        std::cin >> almenupont;
        switch(almenupont){
        case 0:
            menupont=0;
            break;
        case 1:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            egyesulet.listaz(2,std::cout);
            std::cin >> almenupont;
            if(almenupont == 0) menupont=0;
            else {system("CLS");
                  std::cout << "Error!" << std::endl;}
            break;
        case 2:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            std::cout << "Csapat neve: ";
            std::cin >> nev;
            std::cout << "Letszam: ";
            std::cin >> letszam;
            std::cout << "Egyeb: ";
            std::cin >> extra;
            tipus=2;
            egyesulet.uj(new Labdarugas(nev,letszam,tipus,extra));
            std::cout << "Sikeres letrehozas!" << std::endl;
            std::cin >> almenupont;
            break;
        case 3:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            egyesulet.listaz(2,std::cout);
            std::cout << std::endl;
            std::cout << "Csapat neve: ";
            std::cin >> nev;
            try{
            egyesulet.torol(nev,2);
            } catch(int x){ std::cout << "Nincs ilyen nevu csapat!" << std::endl;}
            std::cin >> almenupont;
            break;
        default:
            system("CLS");
            std::cout << "Nincs ilyen menupont!" << std::endl;
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cin >> hibas;
            if(hibas==0) menupont = 0;
            else menupont=4;
            break;
        }
        break;
    case 3:
        system("CLS");
        std::cout << "********** Kezilabda **********" << std::endl;
        almenu(std::cout);
        std::cin >> almenupont;
        switch(almenupont){
        case 0:
            menupont=0;
            break;
        case 1:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            egyesulet.listaz(3,std::cout);
            std::cin >> almenupont;
            if(almenupont == 0) menupont=0;
            else {system("CLS");
                  std::cout << "Error!" << std::endl;}
            break;
        case 2:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            std::cout << "Csapat neve: ";
            std::cin >> nev;
            std::cout << "Letszam: ";
            std::cin >> letszam;
            std::cout << "Egyeb: ";
            std::cin >> extra;
            tipus=3;
            egyesulet.uj(new Kezilabda(nev,letszam,tipus,extra));
            std::cout << "Sikeres letrehozas!" << std::endl;
            std::cin >> almenupont;
            break;
        case 3:
            system("CLS");
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cout << std::endl;
            egyesulet.listaz(3,std::cout);
            std::cout << std::endl;
            std::cout << "Csapat neve: ";
            std::cin >> nev;
            try{
            egyesulet.torol(nev,3);
            } catch(int x){ std::cout << "Nincs ilyen nevu csapat!" << std::endl;}
            std::cin >> almenupont;
            break;
        default:
            system("CLS");
            std::cout << "Nincs ilyen menupont!" << std::endl;
            std::cout << "(0): Vissza a menube" << std::endl;
            std::cin >> hibas;
            if(hibas==0) menupont = 0;
            else menupont=4;
            break;
                }
        break;
    default:
        system("CLS");
        std::cout << "Nincs ilyen menupont!" << std::endl;
        std::cout << "(0): Vissza a menube" << std::endl;
        std::cin >> almenupont;
        if(almenupont==0) menupont = 0;
        else menupont=4;
        break;
    }
    egyesulet.adatbazis_feltolt();
    } while(aktiv);


    return 0;
}
#endif // TESZTEK
