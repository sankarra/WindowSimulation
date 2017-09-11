//
//  Queue.cpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/25/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//



#include "Queue.hpp"
#include "DLList.cpp"

//constructors and member functions for handling a queue
template <class T>
Queue<T>::Queue()
{
    myQueue = new DLList<T>();
    elementsInQueue = 0;
}

template <class T>
void Queue<T>::enQueue(T d)
{
    myQueue->insertBack(d);
    elementsInQueue++;
}

template <class T>
T Queue<T>::deQueue()
{
    elementsInQueue--;
    return myQueue->getFront();
}

template <class T>
T Queue<T>::front()
{
    return myQueue->peekFront();
}

template <class T>
bool Queue<T>::empty()
{
    if (elementsInQueue == 0)
        return true;
    else
        return false;
}

template <class T>
Queue<T>::~Queue()
{
    delete myQueue;
}
