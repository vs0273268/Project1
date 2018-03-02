#pragma once
template <class T>
class fNode
{
public:
    T obj;
    fNode *Next;
    fNode *Back;
    fNode(T obj1);
    fNode();
};
