#include"queue.h"
#include <iostream>
using namespace std;
template <class T> queue<T>::queue(T s)
{   size=s;
    arr=new T[size];

    front=-1;
    rear=-1;
    capacity=0;
    temp=0;
    temp1=0;
}
template <class T> queue<T>::enqueue(T x)
{
    if(front==-1 && rear==-1)
    {
        front++;
        arr[front]=x;
        rear++;
        capacity++;
    }
    else if(rear==size-1 && capacity<size)
    {
        rear=0;
        arr[rear]=x;
         capacity++;


    }
    else if(capacity==size)
    {
        cout<<"capacity full\n";
        return 1;
    }
    else
    {
         rear++;
        arr[rear]=x;

        capacity++;

    }
}
template <class T> QNode<Customer>* queue<T>::dequeue()
{
    if(capacity==size)
    {
         pop();


    }
        if(front==-1)
        {
            cout<<"Empty\n";
            return 1;

        }

            else if(front==size-1)
            {
                arr[temp]=0;
                front=-1;
                capacity--;
                temp++;
            }
            else
            {
                arr[temp]=0;
                front++;
                capacity--;
                temp++;
            }


        return arr[0];

}
template <class T> void queue<T>::show()
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<"    ";
    }
}
template <class T> void queue<T>::push(QNode<T> * x)
{

    arr1[temp1]=x;
    temp1++;
}
template <class T> int queue<T>::pop()
{

       for(int i=size;i>size;i--)
       {
        rear--;
        capacity--;
        size--;
       }
       size--;
}
