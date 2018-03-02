#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include <iostream>
#include "QNode.h"

using namespace std;
template <class T>

class Queue
{
private:
    QNode<T> *head;
    int counter;
public:
    Queue()
    {
        head=NULL;
        counter=0;
    }

    QNode<T>* getHead()
    {
        return head;
    }

    void enqueue(QNode<T> temp)
    {
        QNode<T> *N= new QNode<T>;
        N->next=NULL;
        if (head==NULL)
        {
            head=N;
        }
        else
        {
            QNode<T> *temp;
            temp=head;
            while(temp->next!=NULL)
            {
                temp=temp->next;

            }

            temp->next=N;
            counter++;
        }

    }
    QNode<T>* dequeue()
    {
       QNode<T> *p=new QNode<T>;
       if(head->next==NULL)
       {
           QNode<T> *temp;
        temp=head;
        head=NULL;
        delete temp;
        return p;
       }
       else
       {

        QNode<T> *temp;
        temp=head;
        head=head->next;
        p->data=temp->data;
        p->left=temp->left;
        p->right=temp->right;
        counter--;
        delete temp;
        return p;
       }

    }
  bool is_Emty()
  {
      if (head==NULL)
      {
          return false;
      }
      return true;
  }

};
#endif // QUEUE_H_INCLUDED
