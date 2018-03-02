template <class T>
#pragma once
class QNode
{
public:
    T data;
    QNode *left;
    QNode *right;
    QNode *next;
    QNode *head;
    QNode();
    QNode(T);
};

 // NODE_H_INCLUDED
