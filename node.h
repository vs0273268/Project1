#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#pragma once
template <class T>
class Node
{
public:
    T obj;
    Node *left;
    Node *right;
    Node(T obj1);
};

#endif // NODE_H_INCLUDED
