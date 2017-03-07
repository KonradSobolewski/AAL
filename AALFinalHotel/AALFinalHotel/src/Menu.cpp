/*** Sobolewski Konrad ***/
/*** indeks:  270820 ***/
/*** Tytul: AAL - 10- LS HOTEL ***/

#include "Menu.h"
#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "Edge.h"
#include "Menu.h"
#include "AboutAlgorithm.h"
#include <windows.h>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <algorithm>
#include <set>

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
void Menu::showMenu()
{

    system("CLS");
    cout << " ________________ Analiza Algorytmow _______________" << endl;
    cout << "1. Pokaz informacje o projekcie. " << endl;
    cout << "2. Generuj Osoby" << endl;
    cout << "3. Generuj Zwiazki" << endl;
    cout << "4. Uzyj algorymu" << endl;
    cout << "5. Pokaz wyniki" << endl;
    cout << "6. Testuj ( dla malych danych )" << endl;
    cout << "7. Zamknij" << endl<<endl;

    cout << "Ilosc osob: " <<vectorPersons.size() <<endl;
    cout << "Ilosc krawedzi: " <<vectorEdge.size() <<endl<<endl;

    typeChoice();

}



void Menu::typeChoice()
{
    cout << "Wybierz: " << endl;
    int n = 0,wrong=0;
    static int tested=0;
    cin.clear();
    cin.sync();
    cin >> n;
    cin.ignore();
    switch(n)
    {
    case 1:
        showProjectInfo();
        break;
    case 2:
        numberOfPeople=quantity_of_people();
        if(numberOfPeople>1)
        {
            cout << "Sukces" << endl;
            getchar();
            getchar();
        }
        else
        {
            cout<<"Nie da sie rozwiazac zadania dla tej danej"<<endl;
            getchar();
            getchar();
        }
        showMenu();
    case 3:
        if(numberOfPeople>1)
        {
            wrong=generateData();///sprawdzamy czy dane wygenerowane poprawnie,jesli nie kasujemy i wychodzimy
            if(wrong==1)
            {
                cout << "Blad danych. Sprobuj ponownie" << endl;
                vectorEdge.clear();
                for(int i; i<vectorPersons.size(); i++)
                {
                    vectorPersons[i]->vector_friends.clear();
                    vectorPersons[i]->sumFriends=0;
                }
                getchar();
            }
            else
            {
                cout << "Dane poprawne" << endl;
                getchar();
            }
        }
        else
        {
            cout << "Generuj Osoby" << endl;
            getchar();
        }
        showMenu();
    case 4:
        if(!vectorEdge.empty())
        {
            tested=useAlgorithm();///ustawiona flaga oznaczająca czy mozna juz zobaczyc testy(6)
        }
        else
        {
            cout << "Generuj Osoby i zwiazki" << endl;
            getchar();
        }
        showMenu();
    case 5:
        showData();
        break;
    case 6:
        if(tested)
            tests();
        else
            cout << "Wykonaj algorytm" << endl;
        showData();
    case 7:
        exit(0);
    default:
        showMenu();
    }

}

int Menu::quantity_of_people() ///tworzy ilooa osób
{
    ///czyszczenie po to zeby moglo wykonac sie ponownie
    vectorPersons.clear();
    vectorEdge.clear();
    tv=0;
    bathroom=0;
    emptyRoom=0;
    price=0;
    success=0;

    system("CLS");///czyszcze ekran i rozpoczynam operacje
    int skip=0;
    int number=0;
    cout<<"Podaj ilosc lokatorow"<<endl;
    while (!(cin>>number)) /// nie bierze pod uwage innych znakow poza cyframi
    {
        cin.clear();
        cin.sync();
        system("CLS"); ///czyszcze ekran i rozpoczynam operacje
        cout<<"Blad.Podaj cyfre"<<endl;
    }
    if(number<2)///nie da sie utworzyc pary
    {
        skip=1;
        number=0;
    }
    if(!skip)  ///jesli sie nie da to nie tworze osob
        for(int i=1; i<=number; i++)
        {
            try
            {
                Person* resident=new Person(i,0);
                vectorPersons.push_back(resident);
            }
            catch(bad_alloc)
            {
                --i;///powtórz iteracje
            }
        }

    return number; ///zwraca liczbe osob zeby wiedziec ile utworzyc max krawędzi
}

int Menu::checkSolution() ///sprawdza czy wprowadzane dane odnosnie relacji sa prawidlowe
{
    int wrong=0;
    cout<<"Sprawdzanie rozwiazania..."<<endl;
    for(int i=0; i<vectorPersons.size(); i++)///sprawdzam czy problem jest rozwiazywalny tzn czy w zasiêgu kazdej osoby sa potencjalne pokoje z tv i wc
    {
        if(vectorPersons[i]->vector_friends.size()<1)
        {
            wrong=1;
            cout<<"Blad danych, nie wszystkie osoby maja dostep do obu udogodnien"<<endl;
            return wrong;
        }
    }
    return wrong;
}

int Menu::generateData()
{
    ///czyszczenie po to zeby moglo wykonac sie ponownie
    tv=0;
    bathroom=0;
    emptyRoom=0;
    price=0;
    vectorEdge.clear();
    for(int i=0; i<vectorPersons.size(); i++)
    {
        vectorPersons[i]->vector_friends.clear();
        vectorPersons[i]->sumFriends=0;
        vectorPersons[i]->done=0;
        vectorPersons[i]->room=0;
    }
    int mode,wrong=0;
    success=0;
    ///koniec czyszczenia

    while(1)
    {
        cout<<"Dopasowac recznie(1) czy losowo(2) ?"<<endl;
        cin.clear();
        cin.sync();
        cin>>mode;
        if(mode==1) ///nie losowo
        {
            wrong=make_relations(false);
            break;
        }
        else if(mode==2) ///losowo
        {
            wrong=make_relations(true);
            break;
        }
        else
        {
            system("CLS");
            cout<<"Brak takiej opcji"<<endl;
        }
    }
    return wrong;
}

int Menu::make_relations(boolean randomly)
{
    typedef std::pair<int,int> pairs;
    typedef std::set<pairs> container;
    pairs p;
    pairs p_tmp;
    container zb;
    int skip=0,wrong=0;
    int friend1,friend2;
    int relations;
    boolean is_it;
    srand (time(NULL));

    if(randomly)
    {
        cout<<"Podaj ilosc zwiazkow"<<endl;
        while (1)
        {
            cin.clear();
            cin.sync();
            cin>>relations;
            if((relations>=numberOfPeople-1) && (relations<=numberOfPeople*(numberOfPeople-1)/2))
                break;
            else if(relations<numberOfPeople-1)
                cout<<"Blad , za malo"<<endl;
            else if(relations>numberOfPeople*(numberOfPeople-1)/2)
                cout<<"Blad , za duzo"<<endl;
        }
        for(int i=0; i<relations; i++)///tworze pary losowe
        {
            friend1=rand() % numberOfPeople + 1;
            friend2=rand() % numberOfPeople + 1;
            if (friend1 == friend2)
            {
                ///pomija sytuacje np (1,1)
                --i;
                continue;
            }
            p= make_pair(friend1, friend2);
            if(zb.find(p)==zb.end())//nie znalazl takiej pary w zbiorze, wiec trzeba sprawdzic
                //czy moze odwrotna para tam jest
            {
                p = std::make_pair(p.second, p.first);
                if(!zb.insert(p).second)
                {
                    --i;
                    continue;
                }
            }
            else --i;
        }
        for (auto &i:zb) ///dla wytworzonych par tworze zwiazki
        {
            vectorPersons[i.first-1]->vector_friends.push_back(vectorPersons[i.second-1]);
            vectorPersons[i.second-1]->vector_friends.push_back(vectorPersons[i.first-1]);
            vectorPersons[i.first-1]->sum();
            vectorPersons[i.second-1]->sum();
            try
            {
                Edge* V = new Edge(vectorPersons[i.first-1],vectorPersons[i.second-1]);
                vectorEdge.push_back(V);
            }
            catch(bad_alloc)
            {
                //skip=1; ///jesli nie udalo sie utworzyc to powtorze iteracje
            }
        }
        cout<<"Sukces"<<endl<<endl;
        if(zb.size()<relations)
            cout<<"Czesc par pominieto ze wzgledu na powtarzalnosc"<<endl;
        getchar();
        getchar();
    }
    else
    {
        cout<<"Kto jest z kim znajomym?"<<endl;
        for(int i=0; i<numberOfPeople*(numberOfPeople-1)/2; i++)
        {
            cout<<"Podaj pare, obecna ilosc par: "<<i<<" max("<<numberOfPeople*(numberOfPeople-1)/2<<") min("<<(numberOfPeople-1)<<"), 0 konczy wpisywanie par"<<endl;
            while (!(cin>>friend1))                              /// nie bierze pod uwage innych znakow poza cyframi
            {
                cin.clear();
                cin.sync();
                cout<<"Blad.Podaj cyfre"<<endl;
            }
            if(friend1==0)
            {
                system("CLS");
                cout<<"Koniec wpisywania"<<endl;
                break;
            }
            else if(friend1>numberOfPeople)
            {
                cout<<"Za duza, twoj wybor to: "<<numberOfPeople<<endl;
                friend1=numberOfPeople;
            }
            else if (friend1<1)
            {
                cout<<"Za malo, twoj wybor to: "<<1<<endl;
                friend1=1;
            }
            while (!(cin>>friend2))
            {
                cin.clear();
                cin.sync();
                cout<<"Blad.Podaj cyfre"<<endl;
            }
            if(friend2==0)
            {
                system("CLS");
                cout<<"Koniec wpisywania"<<endl;
                break;
            }
            else if(friend2>numberOfPeople)
            {
                cout<<"Za duza, twoj wybor to: "<<numberOfPeople<<endl;
                friend2=numberOfPeople;
            }
            else if (friend2<1)
            {
                cout<<"Za malo, twoj wybor to: "<<1<<endl;
                friend2=1;
            }
            skip=make_branches(friend1,friend2);
            if(skip==1)///jesli sie powtorzylo lub friend1==friend2
                --i;
        }
    }
    cout<<"Zapisanie ilosci znajomych... "<<endl;
    for(int i=0; i<vectorEdge.size(); i++)///zapisuje ilu znajomych ma kazda krawedz
    {
        vectorEdge[i]->sumFriends=vectorEdge[i]->A->sumFriends+vectorEdge[i]->B->sumFriends-2;
    }
    wrong=checkSolution(); ///sprawdzam poprawnosc, czy kazdy ma znajomego
    getchar();

    return wrong;

}

int Menu::make_branches(int friend1,int friend2)
{
    int skip=0;
    if(friend1==friend2)  ///nie mo¿e wyst¹piæ takie same
    {
        cout<<"Blad relacji"<<endl;
        getchar();
        skip=1; ///powtorz iteracje
    }
    else
    {
        for(int j=0; j<vectorEdge.size(); j++) ///gdy para zosta³a powtórzona.....
        {
            if((vectorEdge[j]->A->ID==friend1 && vectorEdge[j]->B->ID==friend2) || (vectorEdge[j]->A->ID==friend2 && vectorEdge[j]->B->ID==friend1))
            {
                cout<<"Relacja juz istnieje,wpisz nowa"<<endl;
                getchar();
                skip=1; /// powtorze iteracje
            }
        }
    }
    if(skip==0) ///jesli wszystko dobrze przypisuje znajomych do osob i tworze krawedz
    {
        /**------------------Stoworzenie przyjaciól----------------------**/
        vectorPersons[friend1-1]->vector_friends.push_back(vectorPersons[friend2-1]);
        vectorPersons[friend2-1]->vector_friends.push_back(vectorPersons[friend1-1]);
        vectorPersons[friend1-1]->sum();
        vectorPersons[friend2-1]->sum();
        try
        {
            Edge* V = new Edge(vectorPersons[friend1-1],vectorPersons[friend2-1]);
            vectorEdge.push_back(V);
        }
        catch(bad_alloc)
        {
            skip=1; ///jesli nie udalo sie utworzyc to powtorze iteracje
        }
    }
    return skip;
}



void Menu::showProjectInfo()
{
    system("CLS");
    cout << " Sobolewski Konrad " << endl<<endl;
    cout <<"AAL - 10 - LS - Hotel"<<endl;
    cout <<"Zadanie polega na utworzeniu grafu oraz znalezienie najtanszego zakwaterowania dla danego zbioru osob."<<endl;
    cout <<"Aby program wykonal sie poprawnie nalezy utworzyc osoby(2) ,wygenerowac recznie(3.1) lub losowo(3.2) "<<endl;
    cout <<"laczace ich relacje. Wykonanie algorymu(4) pozwala na zobaczenie danych o zadaniu(5/6)."<<endl;

    getchar();

    showMenu();
}


void Menu::showData()///pokazuje podstawowe informacje o zakwaterowaniu ludzi
{
    bathroom=0;
    price=0;
    emptyRoom=0;
    tv=0;

    cout<<"Ilosc osob w Hotelu : "<<numberOfPeople<<endl;
    if(!vectorPersons.empty())
        for(int i=0; i<vectorPersons.size(); i++)///wypisuje
            if(vectorPersons[i]->room==2)
            {
                bathroom++;
                price=price+50;
            }
            else if(vectorPersons[i]->room==1)
            {
                tv++;
                price=price+50;
            }
            else
            {
                emptyRoom++;
                price=price+30;
            }
    cout<<"Ilosc osob z telewizorem: "<<tv<<endl;
    cout<<"Ilosc osob z lazienka : "<<bathroom<<endl;
    cout<<"Ilosc osob z pustym pokojem : "<<emptyRoom<<endl;
    if(success)
    {
        cout<<"Mozna zakwaterowac te osoby za: "<<price<<" zl."<<endl;
        cout<<"Czas twania wykonywania: "<<tOfAlgorithm<<" mikroseconds"<<endl;
    }

    getchar();
    showMenu();
}


int Menu::useAlgorithm()
{
    tOfAlgorithm=0;
    int tab[30];
    for(int j=0; j<30; j++) ///30 iteracji algorytmu ma na celu sprawdzenie średniego czasu wykonania sie algorytmu
    {

        ///czyszczenie
        emptyRoom=0;
        tv=0;
        bathroom=0;
        price=0;
        success=1;
        for(int i=0; i<vectorPersons.size(); i++)
        {
            if(vectorPersons[i]->ID!=0)
            {
                vectorPersons[i]->set_rooms(0);
                vectorPersons[i]->done=0;
            }
        }
        ///koniec czyszczenia
        AboutAlgorithm * start= new AboutAlgorithm();

        auto t1 = std::chrono::high_resolution_clock::now(); ///rozpoczynam liczenie czasu

      //  vectorEdge=start->QuickSort(vectorEdge); ///sortuje

        for(int i=0; i<vectorEdge.size(); i++)///glowna czesc algorytmu
        {
            if(vectorEdge[i]->A->sumFriends>=vectorEdge[i]->B->sumFriends)
            {
                if(vectorEdge[i]->A->done==0)
                {
                    start->Algorithm(vectorEdge[i]->A ,vectorEdge[i]->B );
                }
                if(vectorEdge[i]->B->done==0)
                {
                    start->Algorithm(vectorEdge[i]->B ,vectorEdge[i]->A );
                }
            }
            else
            {
                if(vectorEdge[i]->B->done==0)
                {
                    start->Algorithm(vectorEdge[i]->B ,vectorEdge[i]->A );
                }
                if(vectorEdge[i]->A->done==0)
                {
                    start->Algorithm(vectorEdge[i]->A ,vectorEdge[i]->B );
                }
            }
        }
        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::micro> timeOfAlgorithm = t2 - t1;
        tab[j]=timeOfAlgorithm.count();
        cout<<"Czas : "<<tab[j]<<" mikrosekund"<<endl;
        tOfAlgorithm+=tab[j];
        delete(start);
    }

    //system("CLS");
    cout << "Done" << endl;
    cout<<"Czas twania wykonywania: "<<tOfAlgorithm/30<<" mikrosekund"<<endl<<endl;
    tOfAlgorithm=tOfAlgorithm/30;
    getchar();

    return 1;
}
///funkcje testujace poprawnosc oraz wypisujaca szczegolowe dane o budowie grafu
void Menu::tests()
{
    system("CLS");
    int pickTest;
    cout<<"Wybierz test: "<<endl;
    while(1)
    {
        cout << endl<<"1. Test poprawnosci sortowania. " << endl;
        cout << "2. Test znajomych" << endl;
        cout << "3. Test przydzielenia pokoi poszczegolnym osobom" << endl;
        cin.clear();
        cin.sync();
        cin>>pickTest;
        if(pickTest==1)
        {
            ///test dla sortowania
            for(int i=0; i<vectorEdge.size(); i++)
            {
                cout<<"     "<<i+1<<". "<<vectorEdge[i]->sumFriends<<"  Osoby :"<<vectorEdge[i]->A->ID<<", "<<vectorEdge[i]->B->ID<<endl;
            }
        }
        else if(pickTest==2)
        {
            for(int i=0; i<vectorPersons.size(); i++)
            {
                cout <<"    ID: "<<vectorPersons[i]->ID<<" -znajomi - ";
                for(int j=0; j<vectorPersons[i]->vector_friends.size(); j++)
                    cout <<vectorPersons[i]->vector_friends[j]->ID <<", ";
                cout<<" - suma - "<<vectorPersons[i]->sumFriends<<endl;
            }
        }
        else if(pickTest==3)
        {
            for(int i=0; i<vectorPersons.size(); i++)
            {
                if(vectorPersons[i]->room==1)
                    cout<<"     "<<vectorPersons[i]->ID <<": Lazienka"<<endl;
                else if(vectorPersons[i]->room==2)
                    cout<<"     "<<vectorPersons[i]->ID <<": Telewizor"<<endl;
                else if(vectorPersons[i]->room==0)
                    cout<<"     "<<vectorPersons[i]->ID <<": Brak"<<endl;
            }
        }
        else
            break;
    }
}

