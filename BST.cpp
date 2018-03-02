#include "BST.h"
#include <iostream>
#include "Customer_class.h"
#include <stdio.h>
using namespace std;
CBST::CBST()
{
    root=NULL;

}
void CBST::insert(Customer val)
{
    Node<Customer> *create=new Node<Customer> (val);

    if(root==NULL)
    {
        root=create;

    }
    else
    {
        Node<Customer> *temp=root;
        Node<Customer> * back=temp;
        while(temp!=NULL)
        {       back=temp;

            if(val.get_customerid()>= temp->obj.get_customerid() )
            {
                temp=temp->right;
            }
            else
                temp=temp->left;
        }
        if(val.get_customerid() > back->obj.get_customerid())
        {
            back->right=create;

        }
        else
        {
            back->left=create;

        }
    }

}

void CBST::display_in(Node<Customer>* temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
        display_in(temp->left);
        temp->obj.display();
        display_in(temp->right);
}
void CBST::outt(Node<Customer>* temp)
{
    if(temp==NULL)
    {
        return;
    }
    else
        outt(temp->left);
        temp->obj.out();
        outt(temp->right);
}
Node<Customer>* CBST::search(Node<Customer>* temp,int val)
{
    if(val ==temp->obj.customerId)
    {
        cout<<"Found\n";
        return temp;
    }

    else if(val<temp->obj.customerId)
     {
         if(temp->left==NULL)
            cout<<"Not-Found\n";
         else
            return search(temp->left,val);
     }
     else if(val>temp->obj.customerId)
        {
            if(temp->right==NULL)
            cout<<"Not-Found\n";
            else
           return search(temp->right,val);
        }
        return NULL;

}
Node<Customer>* CBST::update(Node<Customer> *temp , int id)
{
     if(id ==temp->obj.customerId)
    {
        cout << endl;
        cout<<"Found\n";
        cout << endl;
        string  phone;
 string dob;
        fflush(stdin);
        cout << "Enter new phone number : ";
        getline(cin,phone);
        cout << "Enter new date of birth : ";
        getline(cin, dob);
        temp->obj.set_phone(phone);
        temp->obj.set_DOB(dob);

        cout << endl<< "updated ..."<<endl;
    }

    else if(id<temp->obj.customerId)
     {
         if(temp->left==NULL)
            cout<<"Not-Found\n";
         else
            return update(temp->left,id);
     }
     else if(id>temp->obj.customerId)
        {
            if(temp->right==NULL)
            cout<<"Not-Found\n";
            else
           return update(temp->right,id);
        }
        return NULL;

}
Node<Customer> *CBST:: erase(Node<Customer>* temp,int data)
{

      if (temp == NULL)
        {
        return NULL;
      }
      else if (data < temp->obj.customerId)
      {
        root->left = erase(temp->left, data);
      }
      else if (data > temp->obj.customerId)
      {
        temp->right = erase(temp->right, data);
      }
      else {
        if (temp->left == NULL && temp->right == NULL)
            {
          delete temp;
          temp = NULL;
        }
        else if (temp->left == NULL)
        {
          Node<Customer> * temps = temp;
          temp = temp->right;
          delete temps;
        }
        else if (temp->right == NULL)
        {
          Node<Customer>* temps = temp;
          temp = temp->left;
          delete temps;
        }
        else
        {
          Node<Customer>* temps = min(temp->right);
          temp->obj.customerId = temps->obj.customerId;
          temp->right = erase(temp->right, temps->obj.customerId);
        }
      }
      return temp;
    }
Node<Customer>  * CBST::min(Node<Customer> * temp)
{
    Node<Customer> *pre=temp;
    if(temp->left==NULL && temp->right==NULL)
    {
        cout<<temp->obj.customerId;
        return temp;
    }
    else
    {
        while(temp!=NULL)
        {
                pre=temp;
                temp=temp->left;
        }
        cout<<pre->obj.customerId;
        return pre;
    }
}
