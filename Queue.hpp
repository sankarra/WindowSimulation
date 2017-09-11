//
//  Queue.hpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/25/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "DLList.hpp"

template <class T>
class Queue
{
public:
    Queue();
    void enQueue(T d);
    T deQueue();
    bool empty();
    T front();
    ~Queue();
    
private:
    DLList<T> *myQueue;
    int elementsInQueue;
    
};
#endif /* Queue_hpp */
