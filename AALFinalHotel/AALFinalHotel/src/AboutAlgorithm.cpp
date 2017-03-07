/*** Sobolewski Konrad ***/
/*** indeks:  270820 ***/
/*** Tytul: AAL - 10- LS HOTEL ***/

#include "AboutAlgorithm.h"
#include <vector>
#include <algorithm>
#include "Person.h"
#include "Edge.h"

AboutAlgorithm::AboutAlgorithm()
{
    //ctor
}

AboutAlgorithm::~AboutAlgorithm()
{
    //dtor
}

bool sort_branches(Edge* A, Edge* B)
{
    return (A->sumFriends>B->sumFriends);
}

vector<Edge*> AboutAlgorithm::QuickSort(vector<Edge*> vectorEdge)
{
    sort(vectorEdge.begin(),vectorEdge.end(),sort_branches);

    return vectorEdge;
}

/// przydziela pokoj ,opisane w sprawozdaniu
void AboutAlgorithm::Algorithm(Person* A, Person* B)
{
    int typ=0;
    if(A->room==0)
    {
        if(B->room==0 )
        {
            if(A->done==0)
            {
                typ=Search_vector(A->vector_friends,B->ID);
                if(typ==2 || typ==0)
                {
                    A->set_rooms(1);
                    A->done=1;
                }
                else if(typ==1)
                {
                    A->set_rooms(2);
                    A->done=1;
                }
            }
        }
        else if (B->room==1 || B->room==2 )
        {
            typ=Search_vector(A->vector_friends,B->ID);
            if((typ==2 && B->room==1) || (typ==1 && B->room==2))
            {
                A->done=1;
                return;

            }
            else if ((typ==1 && B->room==1) || (typ==0 && B->room==1))
            {
                A->set_rooms(2);
                A->done=1;
            }
            else if ((typ==2 && B->room==2) || (typ==0 && B->room==2))
            {
                A->set_rooms(1);
                A->done=1;
            }
        }
    }
}

///funkcja sprawdza jakich mamy znajomych w zasiegu
int AboutAlgorithm::Search_vector(vector<Person*> vector_friends,int ID)
{
    int typ=0;
    for(int i=0; i<vector_friends.size(); i++)
    {
        if(vector_friends[i]->ID==ID )
            continue;
        else if(vector_friends[i]->room==2)
        {
            typ=2;
            break;
        }
        else if(vector_friends[i]->room==1)
        {
            typ=1;
            break;
        }
        else
            typ=0;
    }
    return typ;
}
