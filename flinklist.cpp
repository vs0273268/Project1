#include "iostream"
#include "fLinklist.h"
#include "Flight_class.h"
#include"fnode.h"
#include <stdio.h>
using namespace std;
template <class T> fLinklist<T>::fLinklist()
{
    head=NULL;
    tail=NULL;
}



template <class T> void fLinklist<T>::add_at_end(T obj1)
{
    fNode<T> *N=new fNode<T>(obj1);
    N->Next=NULL;
    N->Back=NULL;
    if(head==NULL)
    {
        head = tail=N;
        head->Next=tail->Next=NULL;
        head->Back=tail->Back=NULL;
    }
    else
    {
        tail->Next=N;
        N->Back=tail;
        tail=N;
    }
}

template <class T> void fLinklist<T>::delete_from_start()
{
    fNode<T> *temp;
    temp=head;

    if(head->Next==NULL)
    {
        temp=NULL;
        tail=NULL;
        delete temp;
    }
    else
    {
        head=temp->Next;

        delete temp;

        head->Back=tail;
        tail->Next=head;
    }


}
template <class T> void fLinklist<T>::delete_from_end()
{
    fNode<T> *temp;
    temp=tail;

    if(head->Next==NULL)
    {
        temp=NULL;
        head=NULL;
        delete temp;
    }
    else
    {
        fNode<T>* prevTemp;
        prevTemp=tail->Back;

        tail=prevTemp;

        delete temp;

        tail->Next=head;
        head->Back=tail;
    }
}

template <class T> void fLinklist<T>::delete_all()
{

    fNode<T> *temp;
    temp=tail;

    if(head->Next==NULL)
    {
        return;
    }
    while(head!=NULL)
    {
        delete_from_start();
    }


}
template <class T> void fLinklist<T>::display()
{

    fNode<T> *temp;
    temp=head;
    if (head==NULL)
    {
        cout << "No flights are available ...."<<endl;
    }
    else
    {

    while(temp!=tail)
        {
            temp->obj.displayy();
            cout<<"\n";
            temp=temp->Next;

            }
        tail->obj.displayy();
    }
}
template <class T> void fLinklist<T>::delete_by_value(string value )
{
    if(head->obj.get_flightNum()==value)
        delete_from_start();

    else if(tail->obj.get_flightNum()==value)
        delete_from_end();

    else
    {
        fNode<T>* temp;
        fNode<T>* prevTemp;
        fNode<T>* nextTemp;

        nextTemp=NULL;
        prevTemp=NULL;

        temp=head;

        while(temp->obj.get_flightNum()!=value)
        {
            prevTemp=temp;
            temp=temp->Next;
        }
        nextTemp=temp->Next;

        prevTemp->Next=nextTemp;
        nextTemp->Back=prevTemp;

        temp=NULL;

        delete temp;
    }

}
template <class T> fNode<Flight>* fLinklist<T>::search(string id,string planeidd)
{
    int flag=0;
    fNode<T> *temp;
    temp=head;
    if (head==NULL)
    {
        cout << "No flights are available ..."<<endl;
        return NULL;

    }
    else if (head!=NULL)
    {

temp=head;
    while(temp!=NULL)
        {
            if(temp->obj.get_flightNum()==id && temp->obj.get_Planeid()==planeidd)
            {
                flag=1;
                cout <<endl;
                cout << "Flight is availible in the list ..."<<endl;
                return temp;
            }
            temp=temp->Next;
        }
    }
if (flag==0)
        cout << "This flight is not in the list ..."<<endl;

    return NULL;
}

template <class T> bool fLinklist<T>::Destination_search(string dest)
{
    int flag=0;
    fNode<T> *temp;
    temp=head;
    if (head==NULL)
    {
        cout << "No flights are available ..."<<endl;
        return 0;

    }
    else if (head!=NULL)
    {

temp=head;
    while(temp!=NULL)
        {
            if(temp->obj.get_destination()==dest)
            {
                flag=1;
                cout <<endl;
                temp->obj.displayy();

            }
            temp=temp->Next;
        }
    }
if (flag==0)
        cout << "This flight is not in the list ..."<<endl;

    return 0;
}
template <class T> void fLinklist<T>::update(string value )
{
    int flag=0;
    if (head==NULL)
    {
        cout << "No flights are available...."<<endl;
    }
    else
    {
       fNode<T> *temp;
    temp=head;
    while(temp!=NULL)
    {
        if (temp->obj.get_flightNum()==value)
        {
            flag=1;
            cout <<endl;
            cout << "flight is found ..."<<endl;
            cout << endl;
            string day,month,year,departuretime;
            fflush(stdin);
            cout << "Enter new day : ";
            getline(cin,day);
            cout << "Enter new month : ";
            getline(cin,month);
            cout << "Enter new year : ";
            getline(cin , year);
            cout << "Enter new departure time : ";
            getline(cin, departuretime);
            temp->obj.set_departureT(departuretime);
            temp->obj.set_day(day);
            temp->obj.set_month(month);
            temp->obj.set_year(year);

        }
        temp=temp->Next;
    }
    }
    if (flag==0)
    {
        cout << "Flight is not found......"<<endl;
    }
}
