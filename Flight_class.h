#ifndef FLIGHT_CLASS_H_INCLUDED
#define FLIGHT_CLASS_H_INCLUDED
#include "Ticket.h"
#include <iostream>
class Flight
{
    private:
 string flightNumber; //uniquely identifies a flight
 string  planeId; //relates to planId in Plane class
 string  day;
 string  month;
 string year;
 string departureTime;
 string airport_destination;
 string Ticket_type; //relates to airportName in Airport class
 int ticket; //firstClass:780$, secondClass:400$

    public:
        void set_flightNum(string a)
        {
            flightNumber=a;
        }
        void set_Planeid(string a)
        {
            planeId=a;
        }
        void set_day(string a)
        {
            day=a;
        }
        void set_month(string a)
        {
            month=a;
        }
        void set_year(string a)
        {
            year=a;
        }
        void set_departureT(string a)
        {
            departureTime=a;
        }
        void set_airportD(string a)
        {
            airport_destination=a;
        }
        void set_ticket(int t)
        {
            ticket=t;
        }

        string get_flightNum()
        {
            return flightNumber;
        }
        string get_Planeid()
        {
            return planeId;
        }
        string get_day()
        {
            return day;
        }
        string get_month()
        {
            return month;
        }
        string get_year()
        {
            return year;
        }
        string get_destination()
        {
            return airport_destination;
        }
        string get_departure()
        {
            return departureTime;
        }
        int get_ticket()
        {
            return ticket;
        }

        void set_info(string fn,string pi,string d,string m,string y,string dest,string dep,int t)
        {
            set_flightNum(fn);
            set_Planeid(pi);
            set_day(d);
            set_month(m);
            set_year(y);
            set_airportD(dest);
            set_departureT(dep);
            set_ticket(t);
        }
        void displayy()
    {
        cout << "Flight number = "<< flightNumber<<endl;
        cout << "Plane Id = "<<planeId<<endl;
        cout << "Departure date = "<<day<<"-"<<month<<"-"<<year<<endl;
        cout << "Airport Destination = "<<airport_destination<<endl;
        cout << "Departure Time = "<<departureTime<<endl;
        cout <<endl;
    }

 //Public member functions to set and get
};
#endif // FLIGHT_CLASS_H_INCLUDED
