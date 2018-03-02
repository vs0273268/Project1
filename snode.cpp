#include "snode.h"
#include "iostream"
using namespace std;

template <class T> SNode<T>::SNode(T ptr)
{
    obj=ptr;
    Next=NULL;
}


