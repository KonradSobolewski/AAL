/*** Sobolewski Konrad ***/
/*** indeks:  270820 ***/
/*** Tytul: AAL - 10- LS HOTEL ***/

#ifndef MENU_H
#define MENU_H
#include <vector>
#include "Person.h"
#include "Edge.h"



class Menu
{
public:
    Menu();
    virtual~Menu();
    void showMenu();
    void typeChoice();
    void showProjectInfo();
    void showData();
    int generateData();
    int make_relations(boolean randomly);
    int checkSolution();
    int make_branches(int friend1,int friend2);
    int quantity_of_people();
    int useAlgorithm();
    void tests();
    vector<Edge*> vectorEdge; ///       przetrzymuje krawedzie
    vector<Person*> vectorPersons; ///  przetrzymuje osoby



private:
    int numberOfPeople=0;///liczba osob
    int tv=0,bathroom=0,emptyRoom=0; ///liczniki wskazujace ilosc pokoi
    int price=0;  ///cena calkowita
    int tOfAlgorithm=0;  ///czas wykonania algorytmu
    int success=0;

};

#endif // MENU_H
