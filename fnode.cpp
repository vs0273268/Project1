#include "fnode.h"
#include "iostream"
using namespace std;

template <class T> fNode<T>::fNode(T obj1)
{
    obj=obj1;
    Next=NULL;
    Back=NULL;
}

template <class T> fNode<T>::fNode()
{
    Next=NULL;
    Back=NULL;
}

