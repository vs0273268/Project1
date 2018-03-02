#pragma once
#include "fNode.cpp"
#include "Flight_class.h"
template <class T>

class fLinklist
{
    public:
    fNode<T> *head;
    fNode<T> *tail;
    //void set_head(fNode *);
    //void set_tail(fNode *);
    //fNode* get_head();
    //fNode* get_tail();
    fLinklist();
    //Linklist(fNode *,fNode *);
    void add_at_end(T );
    fNode<Flight>* search(string ,string );
    bool Destination_search(string);
    void delete_all();
    void delete_from_start();
    void delete_from_end();
    void delete_by_value(string);
    void update(string);
    void display();
};
