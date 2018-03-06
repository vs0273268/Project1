#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include "node.cpp"
#include "Customer_class.h"
class CBST
{
public:
    CBST();
    Node <Customer> *root;
    void insert(Customer val);
    Node<Customer> *search(Node<Customer>* ,int );
    Node<Customer>* update(Node<Customer> *temp , int id);
    Node<Customer>* erase(Node<Customer>* t,int data);
    Node<Customer>* min(Node<Customer> * temp);
    void outt(Node<Customer>* temp);
    void display_in(Node<Customer> *val);
};

#endif // BST_H_INCLUDED
