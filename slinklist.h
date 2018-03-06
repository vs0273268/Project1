#pragma once
#include "snode.cpp"
#include "Plane.h"
#include "Airport.h"
template <class T>
class SLinklist
{
    private:
    SNode<T> *head;
    SNode<T> *tail;
    public:
    SLinklist();
    bool seat_reserve(string);
    bool seat_cancel(string pi);
    void delete_by_value(int id,string fn);
    int search(string);
    void add_at_end(T);
    void delete_all();
    void delete_from_start();
    void delete_from_end();
    void display();
};
