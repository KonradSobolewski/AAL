/*** Sobolewski Konrad ***/
/*** indeks:  270820 ***/
/*** Tytul: AAL - 10- LS HOTEL ***/

#ifndef ABOUTALGORITHM_H
#define ABOUTALGORITHM_H
#include <vector>
#include "Person.h"
#include "Edge.h"

class AboutAlgorithm
{
public:
    AboutAlgorithm();
    virtual~AboutAlgorithm();
    int Search_vector(vector<Person*> vector_friends,int ID);
    void Algorithm(Person* A, Person* B);
    vector<Edge*> QuickSort(vector<Edge*> vectorEdge);
};

#endif // ABOUTALGORITHM_H
