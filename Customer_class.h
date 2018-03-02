#ifndef CUSTOMER_CLASS_H_INCLUDED
#define CUSTOMER_CLASS_H_INCLUDED
#include<iostream>
#include"slinklist.h"
#include "Ticket.h"
#include <fstream>
using namespace std;

class Customer
{
public:
 int  customerId; //uniquely identifies a customer
 string name;
 string  phone;
 string dob; //date of birth
int numOfFlights; //incremented at each flight to be used for offers
 int  milesTraveled; //
 SLinklist<Ticket> asobj;


public:
    Customer()
    {
        customerId=numOfFlights=milesTraveled=0;
    }
    void set_customerid(int a)
    {
            customerId=a;
    }
    void set_name(string a)
    {
        name=a;
    }
    void set_phone(string  a)
    {
        phone=a;
    }
    void set_DOB(string a)
    {
        dob=a;
    }
    void set_NOF(int a)
    {
        numOfFlights+=a;
    }
    void set_MilesT(int a)
    {
        milesTraveled+=a;
    }
    int get_customerid()
    {
        return customerId;
    }

    string get_name()
    {
        return name;
    }
    string get_phone()
    {
        return phone;
    }
    string set_DOB()
    {
        return dob;
    }
    int  get_NOF()
    {
        return numOfFlights;
    }
    int  get_MilesT()
    {
        return milesTraveled;
    }
    void insertinfo(string name1 , int cust1 , string phone1 , string dob1 ,int nof1  , int miles1)
    {
        set_DOB(dob1);
        set_MilesT(miles1);
        set_name(name1);
        set_NOF(nof1);
        set_customerid(cust1);
        set_phone(phone1);
    }
    void display()
    {

        cout <<"Name: " <<name <<endl<<"Customer-id: "<<customerId<<endl
        <<"Phone :"<<phone<<endl<<"DOB: "<<dob<<endl<<"Number of flights: "<<numOfFlights<<endl
        <<"Miles-Travelled: "<<milesTraveled<<endl<<endl;

    }
    void out()
    {
            fstream customers;
            customers.open("Customer.txt",ios::out| ios::app);
            customers<<name<<" "<<customerId<<" "<<phone<<" "<<dob<<" "<<numOfFlights<<" "<<milesTraveled<<endl;
            customers.close();

    }

    //Public member functions to set, get, updateNumOfFlights, and updateMilesTraveled...
};
#endif // CUSTOMER_CLASS_H_INCLUDED
