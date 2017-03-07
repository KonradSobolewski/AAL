/*** Sobolewski Konrad ***/
/*** indeks:  270820 ***/
/*** Tytul: AAL - 10- LS HOTEL ***/

#include "Edge.h"
#include "Person.h"

Edge::Edge(Person* x, Person* y)
{
   A=x;
   B=y;
}

Edge::~Edge()
{
    //dtor
}
