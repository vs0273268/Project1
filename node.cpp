#include "Node.h"
#include <iostream>
template <class T> Node<T>::Node(T obj1)
{
    obj=obj1;
    left=right=NULL;
}
