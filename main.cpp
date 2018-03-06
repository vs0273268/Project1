#include <iostream>
#include "Customer_class.h"
#include "BST.h"
#include "Flight_class.h"
#include "flinklist.cpp"
#include <fstream>
#include "Plane.h"
#include "slinklist.cpp"
#include "Airport.h"
#include "Ticket.h"
#include <stdio.h>
#include<stdlib.h>
#include "queue.h"
#include "QNode.cpp"
#include <ctime>
using namespace std;

int main()
{

    Customer obj;
    CBST obj1,obj2;
    fNode<Flight> *fnobj;
    Node<Customer> *cobj;
    Queue<Customer> qobj;


    Flight fobj;
    fLinklist<Flight> lobj;
    Airport aobj;
    SLinklist<Airport> asobj;
    Ticket tobj;
    SLinklist<Ticket> tsobj;


    Plane pobj;
    SLinklist<Plane> sobj;


    Airport object;
    int choice;
    char again;
    do
    {
        system("CLS");
      cout<<"-------------Menu-------------"<<endl;
        cout << "1-   Flight reservation  \n"<<endl;
        cout << "2-   Customer \n"<<endl;
        cout << "3-   Flights  \n"<<endl;
        cout << "4-   Setup system data\n"<<endl;
        cout << "5-   Save data to text files\n"<<endl;
        cout << "6-   Exit "<<endl<<endl;
        cin >> choice;
        if (choice==1)
        {

            system("CLS");
            cout <<"1-  Search for destination\n"<<endl;
            cout <<"2-  Reserve flight\n"<<endl;
            /*if reserved: generate ticket, update customer info, and update flight info. 
            if flight is full, add (if agreed) to waiting list*/
            cout <<"3-  Cancel Reservation\n"<<endl;
            cout <<"4-  Change Reservation\n"<<endl;
            cout <<"5- to go back to main menu"<<endl;
            cin >> choice;
            if (choice==1)
            {

                system("CLS");
                string destination;
                cout<<"\nEnter destination: \n";
                cin>>destination;
                lobj.Destination_search(destination);
;            }
            else if (choice==2)
            {
                system("CLS");
                if(lobj.head!=NULL)
                {
                    lobj.display();
                 string flightNumber; //uniquely identifies a flight
                string  planeId; //relates to planId in Plane class
                string  name;
                int  ticketnum;
                string seatnumber;
                string departureTime;
                string airport_destination; //relates to airportName in Airport class
                fflush(stdin);
                cout << endl;
                cout << "Enter flight number = ";
                getline(cin,flightNumber);

                cout << "Enter Plane Id = ";
                getline(cin,planeId);
                fnobj=lobj.search(flightNumber,planeId);

                 if(fnobj!=NULL)
                 {
                        int id,nom;
                     cout<<"Enter you Customer-Id\n";
                     cin>>id;
                     cobj=obj1.search(obj1.root,id);
                     if(cobj!=NULL)
                     {
                         cobj->obj.set_NOF(1);

                     if(sobj.seat_reserve(flightNumber)!=0)
                     {
                         nom=sobj.search(flightNumber);
                     cobj->obj.set_MilesT(nom);

                         cout<<"Customer data is updated\n";
                         cobj->obj.display();
                         obj2.insert(cobj->obj);
                         name=cobj->obj.get_name();
                         cout<<name;
                         srand(time(NULL));
                         departureTime=fnobj->obj.get_departure();
                         ticketnum=rand();
                         tobj.set_info(id,name,flightNumber,ticketnum,departureTime);
                         tobj.displayy();
                         fstream ticket;
                         ticket.open("Ticket.txt",ios::out | ios::app);
                         ticket<<id<<" "<<name<<" "<<flightNumber<<" "<<ticketnum<<" "<<departureTime<<endl;
                         ticket.close();
                         tsobj.add_at_end(tobj);
                 }
                 else
                 {
                     char choice;
                     cout<<"\nNo more seats left\n";
                    cout<<"\nDo you want to be added in waiting list(Y||N)?\n";
                    cin>>choice;
                    if(choice=='y' || choice=='Y' )
                    {
                            qobj.enqueue(cobj->obj);
                    }


}



                 }}

                }
                else
                    cout << "No flights are available..."<<endl;


            }
            else if (choice==3)
            {

                system("CLS");
                fflush(stdin);
                string flight_number;
                string id;
                int i=0;
                cout << "Enter Flight number you want to cancel : ";
                getline(cin , flight_number);
                cout << "Enter your user id : ";
                cin>>id;
                i=atoi(id.c_str());
                cobj=obj1.search(obj1.root,i);
                     if(cobj!=NULL)
                     {
                         int nom;
                         cobj->obj.set_NOF(-1);
                         sobj.seat_cancel(flight_number);
                         nom=sobj.search(flight_number);
                         cobj->obj.set_MilesT(-nom);
                         tsobj.delete_by_value(i,flight_number);
                         tsobj.display();


                         }


            }
            else if(choice==4)
            {
                system("CLS");
            }

        }
        else if (choice==2)
        {
            system("CLS");
            cout << "1- Add customer\n"<<endl;
            cout << "2- Update customer info \n"<<endl;
            cout << "3- Delete customer      \n"<<endl;
            cout << "4- to go to main menu "<<endl;
            cin >> choice;
            if (choice==1)
            {
                 int  customerId; string name  ,phone, dob;
                 int numOfFlights,milesTraveled;
                 cout<<"Enter customer id: ";
                 cin>>customerId;
                 cout<<"Enter customer name: ";
                 cin>>name;
                 cout<<"Enter customer Phone-Number: ";
                 cin>>phone;
                 cout<<"Enter customer DOB: ";
                 cin>>dob;
                 cout<<"Enter number of flights: ";
                 cin>>numOfFlights;
                 cout<<"Enter number of miles travelled: ";
                 cin>>milesTraveled;
                 fstream customers;
                 obj.insertinfo(name,customerId,phone, dob, numOfFlights, milesTraveled);
                 obj1.insert(obj);
                 customers.open("Customer.txt",ios::out| ios::app );
                 customers<<name<<" "<<customerId<<" "<<phone<<" "<<dob<<" "<<numOfFlights<<" "<<" "<<milesTraveled<<endl;

                 customers.close();

                system("CLS");
                cout<<"\nCustomer added successfully\n";
            }
            else if (choice==2)
            {
                system("CLS");
                int id;
                cout<<"Enter customer id: ";
                cin>>id;
                obj1.update(obj1.root,id);


            }
            else if (choice==3)
         {

                system("CLS");
                int id;
                cout<<"Enter customer id of the customer you want to delete : ";
                cin>>id;
                if (obj1.search(obj1.root,id)!=NULL)
                {
                    obj1.erase(obj1.root,id);
                    cout <<endl<<"customer is deleted successfully ....."<<endl;
                }
            else if(choice==4){
                cout << "customer not found..."<<endl;

        }
         }

        }

        else if (choice==3)
        {
            system("CLS");
            cout <<"1- Add flight\n"<<endl;
            cout <<"2- Update flight\n"<<endl;
            cout <<"3- Delete flight\n"<<endl;
            cout <<"4- to go back to main menu"<<endl;
            cin >> choice;
            if (choice==1)
            {
                system("CLS");
                string flightNumber,  planeId,day,month, year, departureTime, airport_destination;int ticket; //firstClass:780$, secondClass:400$
                cout<<"Enter flight number: ";
                 cin>>flightNumber;
                 cout<<"Enter plane id: ";
                 cin>>planeId;
                 cout<<"Enter day: ";
                 cin>>day;
                 cout<<"Enter month: ";
                 cin>>month;
                 cout<<"Enter year: ";
                 cin>>year;
                 cout<<"Enter departure time: ";
                 cin>>departureTime;
                 cout<<"Enter airport destination: ";
                 cin>>airport_destination;
                 cout<<"Enter ticket: ";
                 cin>>ticket;
                fstream flight;
                flight.open("Flight.txt", ios::out| ios::app);

                flight<<flightNumber<<" "<<planeId<<" "<<day<<" "<<month<<" "<<year<<" "<<airport_destination<<" "<<departureTime<<" "<<ticket<<endl;
                flight.close();
                fobj.set_info(flightNumber,planeId,day,month,year,airport_destination,departureTime,ticket);
                lobj.add_at_end(fobj);
            }
            else if (choice==2)
            {
                system("CLS");
                string flightNumber;
                cout<<"Enter flight number: ";
                 cin>>flightNumber;
                 lobj.update(flightNumber);
            }
            else if (choice==3)
            {
                string fid;
                system("CLS");
                cout<<"Enter Flight id\n";
                cin>>fid;
                lobj.delete_by_value(fid);


            }

        }
        else if (choice==4)
        {
            fstream customers;
            customers.open("Customer.txt",ios::in);
            while(!customers.eof())
            {
                 string id;
            int i,nof,mt;
                string name, phone,dob,numOfFlights,milesTraveled;
                customers>>name;customers>>id;customers>>phone;customers>>dob;customers>>numOfFlights;customers>>milesTraveled;
                i=atoi(id.c_str());
                nof=atoi(numOfFlights.c_str());
                mt=atoi(milesTraveled.c_str());
                obj.insertinfo(name,i, phone,dob,nof ,mt);
                obj1.insert(obj);

            }
             customers.close();
            obj1.display_in(obj1.root);

            system("CLS");
            fstream flight;
            flight.open("Flight.txt",ios::in);
            while(!flight.eof())
            {
                int i;
                string flightNumber,  planeId,day,month, year, departureTime, airport_destination,ticket; //firstClass:780$, secondClass:400$
                flight>>flightNumber;flight>>planeId;flight>>day;flight>>month;flight>>year;flight>>airport_destination;flight>>departureTime;
                flight>>ticket;
                i=atoi(ticket.c_str());
                fobj.set_info(flightNumber,planeId,day,month,year,airport_destination,departureTime,i);
                lobj.add_at_end(fobj);

            }
            flight.close();

            fstream planes;
            planes.open("Planes.txt",ios::in);
            while(!planes.eof())
            {
             string planeId,numberOfMilesTraveled,numberofseats;
             planes>>planeId;planes>>numberOfMilesTraveled;planes>>numberofseats;
             int nom=atoi(numberOfMilesTraveled.c_str());
             int nos=atoi(numberofseats.c_str());
             pobj.set_info(planeId,nom,nos);
             sobj.add_at_end(pobj);

            }
            planes.close();

        cout << "Files are loaded......"<<endl;
        cout <<endl;
        }
        else if (choice==5)
        {
            fstream customers;
            customers.open("Customer.txt",ios::out|ios::ate);
            customers.close();
            system("CLS");
            obj1.outt(obj1.root);


        }
        else
        {
            break;
        }
        cout << endl;
        cout << "Enter y to run again and n to end"<<endl;
        cin >>again;
    }
    while (again=='y'|| again == 'Y');

    return 0;
}

