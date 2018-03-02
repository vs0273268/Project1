#include "QNode.h"
#include <iostream>
template <class T> QNode<T>::QNode()
{
    left=right=next=head=NULL;

}
template <class T> QNode<T>::QNode(T val)
{
    data=val;
    left=right=NULL;
}
