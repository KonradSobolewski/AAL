/*** Sobolewski Konrad ***/
/*** indeks:  270820 ***/
/*** Tytul: AAL - 10- LS HOTEL ***/

#include "Person.h"

Person::Person(int indeks, int typ)
{
    ID=indeks;
    room=typ;
}

Person::~Person()
{

}

void Person::set_rooms(int typ) /// przydziela pokój
{
   room=typ;
}
void Person::sum() ///przydziela liczbe znajomych
{
    sumFriends=vector_friends.size();
}

