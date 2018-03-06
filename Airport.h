#ifndef AIRPORT_H_INCLUDED
#define AIRPORT_H_INCLUDED
#include "slinklist.h"
#include <iostream>
using namespace std;
class Airport
{
private:
 string airportName; //relates to airport destination in Flight class
 string country; //general info
 string usualWeatherCondition; //general info
 string timeFromBeirut; // general info
 string milesFromBeirut; //used to accumulate miles
    public:
        void set_airportname(string n)
        {
            airportName=n;
        }
        void set_Country(string n)
        {
            country=n;
        }
        void set_UWC(string n)
        {
            usualWeatherCondition=n;
        }
        void set_timeFB(string n)
        {
            timeFromBeirut=n;
        }
        void set_MilesFB(string n)
        {
            milesFromBeirut=n;
        }

        string get_airportname()
        {
            return airportName;
        }
        string get_Country()
        {
            return country;
        }
        string get_UWC()
        {
            return usualWeatherCondition;
        }
        string get_timeFB()
        {
            return timeFromBeirut;
        }
        string get_MilesFB()
        {
            return milesFromBeirut;
        }
        void set_info(string a,string c,string u,string tfb,string mfb)
        {
            set_airportname(a);
            set_Country(c);
            set_UWC(u);
            set_timeFB(tfb);
            set_MilesFB(mfb);
        }
        void displayy()
        {
            cout<<airportName<<"--"<<country<<"--"<<usualWeatherCondition<<"--"<<timeFromBeirut<<"--"<<milesFromBeirut;
        }

};
#endif // AIRPORT_H_INCLUDED
