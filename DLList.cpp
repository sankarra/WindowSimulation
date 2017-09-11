//
//  DLList.cpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/19/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#include "DLList.hpp"

//constructors and member functions for handling a doubly linked list
template <class T>
ListNode<T>::ListNode()
{
    next = prev = NULL;
    
}

template <class T>
ListNode<T>::ListNode(T d)
{
    data = d;
    next = NULL;
    prev = NULL;
}

template <class T>
void ListNode<T>::setData(T d)
{
    data = d;
}

template <class T>
T ListNode<T>::getData()
{
    return data;
}

template <class T>
void ListNode<T>::setPrev(ListNode *p)
{
    prev = p;
}

template <class T>
ListNode<T>* ListNode<T>::getPrev()
{
    return prev;
}

template <class T>
void ListNode<T>::setNext(ListNode *n)
{
    next = n;
}

template <class T>
ListNode<T>* ListNode<T>::getNext()
{
    return next;
}

template <class T>
ListNode<T>::~ListNode()
{
    
}

template <class T>
DLList<T>::DLList()
{
    head = NULL;
    tail = NULL;
    numElements = 0;
}

template <class T>
void DLList<T>::insertBack(T  d)
{
    ListNode<T> *newNode = new ListNode<T>(d);
    
    //0 elements in the linked list
    if (numElements == 0)
    {
        head = tail = newNode;
    }
    //1 or more elements in the linked list
    else
    {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    
    numElements++;
}

template <class T>
T  DLList<T>::getFront()
{
    ListNode<T>* frontElement = head;
    
    if (numElements == 0)
    {
        //throw 10;
    }
    else if (numElements == 1)
    {
        frontElement = head;
        head = tail = NULL;
    }
    else
    {
        frontElement = head;
        head = head->getNext();
        head->setPrev(NULL);
    }
    numElements--;
    return frontElement->getData();
}

template <class T>
T DLList<T>::peekFront()
{
    return head->getData();
}

template <class T>
int DLList<T>::numberOfElements()
{
    return numElements;
}

template <class T>
DLList<T>::~DLList()
{
    ListNode<T> *temp = head;
    
    while(temp != NULL)
    {
        head = head->getNext();
        delete temp;
        temp = head;
    }
    head = tail = NULL;
    numElements = 0;
    
}
