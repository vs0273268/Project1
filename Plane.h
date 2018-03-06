#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED
#include "slinklist.h"
#include <iostream>
using namespace std;
class Plane
{

public:

 string planeId;
 int numberOfMilesTraveled;
 int first_class;
 int second_class;
 int seats[100];
 int numberofseats;
 int counter;
public:
    Plane()
    {
        planeId="";
        numberOfMilesTraveled=0;
        first_class=0;
        second_class=0;
        counter=0;
        numberofseats=0;
        for(int i=0;i<100;i++)
        {
            seats[i]=0;
        }
    }
    void set_PID(string a)
    {
        planeId=a;
    }
    void set_NMT(int NMT)
    {
        numberOfMilesTraveled=NMT;
    }
    void setFirstClass(int a)
    {
        first_class=a;
    }
    void setSecondClass(int a)
    {
        second_class=a;
    }
    void set_seats(int a)
    {
        if(a>0)
        {seats[counter]=a;
        counter++;}
        else
        counter--;
    }
    void setMiles(int a)
    {
        numberOfMilesTraveled=a;
    }
    void set_info(string id, int miles,int nos)
    {
        set_PID(id);
        setMiles(miles);
        set_nos(nos);
    }
    int getFirstClass()
    {
        return first_class;
    }
    int getSecondClass()
    {
        return second_class;
    }
    int getMiles()
    {
        return numberOfMilesTraveled;
    }
    void set_nos(int nos)
    {
        numberofseats=nos;
    }
    string getplaneId()
    {
        return planeId;
    }
    int get_nos()
    {
        return numberofseats;
    }
    void seat_reserve(string pi);
    void displayy()
    {
        cout << "plane id = "<< planeId<<endl;
        cout << "Number of miles = "<< numberOfMilesTraveled<<endl;
        cout << "Total seats are available = "<<100-counter<<endl;
    }


};
#endif // PLANE_H_INCLUDED
