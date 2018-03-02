#include "iostream"
#include "slinklist.h"
#include "Plane.h"
#include "Ticket.h"
using namespace std;
template <class T> SLinklist<T>::SLinklist()
{
    head=NULL;
    tail=NULL;
}

template <class T> void SLinklist<T>::add_at_end(T x)
{
    SNode<T> *N=new SNode<T> (x);

    N->Next=NULL;
    if(head==NULL)
    {
        head=N;
        N=NULL;
    }
    else
    {
     SNode<T> *temp;
    temp=head;
    while(temp->Next!=NULL)
        {
                temp=temp->Next;
            }
            temp->Next=N;

    }
}
template <class T>  void SLinklist<T>::delete_from_start()
{

    if(head != NULL)
        {
        head=head->Next;
    }

}
template <class T>  void SLinklist<T>::delete_from_end()
{
      if(head != NULL){
            SNode<T> *end = head;
            if(end->Next != NULL){
                    SNode<T> *prev_end;
                    while(end->Next != NULL){
                            prev_end = end;
                            end = end->Next;
                    }
                    prev_end->Next = NULL;
                    delete end;
            }
            else {
                    delete head;
                    head = NULL;
            }
            }
}
template <class T>  void SLinklist<T>::delete_by_value(int id,string fn)
{
    SNode<T> *Pre=NULL;
    SNode<T> *Del=NULL;

    if (head->obj.customerId==id && head->obj.flightNum==fn)
        {
        Del=head;
        head=Del->Next;
        delete Del;
        return;
        }
    Pre=head;
    Del=head->Next;

    while(Del!=NULL)
        {
        if(Del->obj.customerId==id && Del->obj.flightNum==fn)
            {
            Pre->Next=Del->Next;
            delete Del;
            break;
            }
        Pre = Del;
        Del = Del->Next;

    }}
template <class T>  void SLinklist<T>::delete_all()
{
    if(head==NULL)
    {
        return;
    }
    SNode<T> *temp;
    temp=head;
    while(temp!=NULL)
    {
        delete_from_start();
        temp=temp->Next;
    }

        }
template <class T>  int SLinklist<T>::search(string id)
{
    SNode<T> *temp;
    temp=head;
    int flag=0;
    if(head==NULL)
    {
        cout << "No flights are available"<<endl;
        return 0;
    }
    else if (head!=NULL)
    {

    temp=head;
    while(temp!=NULL)
        {
            if(temp->obj.getplaneId()==id)
            {
                flag=1;
                cout <<endl;
                cout << "Flight is availible in the list ..."<<endl;
                return temp->obj.getMiles();
            }
            temp=temp->Next;
        }
    }
    if (flag==0)
        cout << "This flight is not in the list ..."<<endl;
        return 0;
}


template <class T> bool SLinklist<T>::seat_reserve(string pi)
{
    if(head==NULL)
    {
        cout<<"\nNo flight available\n";
        return 0;
    }
    SNode<T> *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->obj.getplaneId()==pi)
        {
            if(temp->obj.counter!=100)
            {temp->obj.set_seats(1);
            cout<<"\nSeat is reserved\n";
            return 1;}
            else
                {cout<<"Seats are full\n";
                return 0;}
        }
        temp=temp->Next;
    }
    cout<<"\nNo flight available\n";
        return 0;
}
template <class T> bool SLinklist<T>::seat_cancel(string pi)
{
    if(head==NULL)
    {
        cout<<"\nNo flight available\n";
        return 0;
    }
    SNode<T> *temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->obj.getplaneId()==pi)
        {
            if(temp->obj.counter!=0)
            {
                temp->obj.set_seats(-1);
            cout<<"\nSeat is Cancelled\n";
            temp->obj.displayy();
            return 1;
            }
            else
                {cout<<"No seats are available\n";
                return 0;}
        }
        temp=temp->Next;
    }
    cout<<"\nNo flight available\n";
        return 0;
}


template <class T>  void SLinklist<T>::display()
{

    SNode<T> *temp;
    temp=head;
    while(temp!=NULL)
        {
            temp->obj.displayy();
            cout<<"\n";
            temp=temp->Next;

            }
}
