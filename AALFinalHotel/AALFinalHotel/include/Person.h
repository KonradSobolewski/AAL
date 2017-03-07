/*** Sobolewski Konrad ***/
/*** indeks:  270820 ***/
/*** Tytul: AAL - 10- LS HOTEL ***/

#ifndef Person_H
#define Person_H
#include <windows.h>
#include<vector>

using namespace std;
class Person
{
public:
    Person(int ID,int typ);
    virtual~Person();
    int sumFriends;
    int done=0; ///flaga informuje czy pokoj zosta³ ustawiony,po to zeby sprawdzaæ osobe tylko raz
    int ID;
    int room;
    vector<Person*> vector_friends;
    void set_rooms(int typ);
    void sum();

};
#endif
