#ifndef TICKET_H_INCLUDED
#define TICKET_H_INCLUDED
#include "slinklist.h"
#include <iostream>
class Ticket
{
public:

 int customerId; //related to customerId in Customer class
 string name; // related to customer name in Customer class
 string flightNum; // related to flight number in Flight class
 int ticketNumber; // uniquely identifies a ticket
 string ticketType; // related to ticket type in Flight class
 int costOfFlight; //related to ticket price in Flight class
 bool discount; // related to offers class

 string reasonForDiscount; //related to offers class
 string dateTime; //related to date and time of the flight
 int seatNumber; //reserved on airplane on flight

public:
    void set_customerID(int n)
    {
        customerId=n;
    }
    void set_name(string n)
    {
        name=n;
    }
    void set_flightnum(string n)
    {
        flightNum=n;
    }
    void set_ticketN(int n)
    {
        ticketNumber=n;
    }
    void set_ticketT(string n)
    {
        ticketType=n;
    }
    void set_cost(int n)
    {
        costOfFlight=n;
    }
    void set_discount(bool n)
    {
        discount=n;
    }
    void set_RFD(string n)
    {
        reasonForDiscount=n;
    }
    void set_DT(string n)
    {
        dateTime=n;
    }
    void set_seatN(int n)
    {
        seatNumber=n;
    }
    void set_info(int cid,string n,string FN,int TN,string DT)
    {
        set_customerID(cid); set_name(n); set_flightnum(FN); set_ticketN(TN); //set_ticketT(TT);set_cost(COF); set_discount(d);et_RFD(RFD);
        set_DT(DT);//set_seatN(SN);
    }
    void displayy()
    {
cout<< customerId<<"--"<<name<<"--"<<flightNum<<"--"<<ticketNumber//<"--"<<ticketType<<"--"<<costOfFlight<<"--"<<discount<<"--"
    //<<reasonForDiscount
    <<"--"<<dateTime;//<<"--"<<seatNumber;
    }
//Public member functions to set, get, and print
};
#endif // TICKET_H_INCLUDED
