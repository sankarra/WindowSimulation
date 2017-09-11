//
//  DLList.hpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/19/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef DLList_hpp
#define DLList_hpp

#include <stdio.h>

//template class so any data type can be used. Multi-functional
//defines a doubly linked list node and a doubly linked list
template <class T>
class ListNode {
    
private:
    T data;
    ListNode *next;
    ListNode *prev;
    
public:
    ListNode();
    ListNode(T d);
    void setData(T d);
    T getData();
    void setPrev(ListNode *p);
    ListNode *getPrev();
    void setNext(ListNode *n);
    ListNode *getNext();
    ~ListNode();
    
    
};

template <class T>
class DLList
{
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    int numElements;
public:
    DLList();
    void insertBack(T d);
    T getFront();
    T peekFront();
    ~DLList();
    int numberOfElements();
    
};
#endif /* DLList_hpp */
