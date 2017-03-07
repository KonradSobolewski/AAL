/*** Sobolewski Konrad ***/
/*** indeks:  270820 ***/
/*** Tytul: AAL - 10- LS HOTEL ***/

#ifndef Edge_H
#define Edge_H
#include "Person.h"

class Person;

class Edge
{
public:
    Edge(Person* x, Person* y);
    virtual ~Edge();
    Person* A;
    Person* B;
    int sumFriends;

};

#endif
