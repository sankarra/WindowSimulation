//
//  RWindow.cpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/29/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#include "RWindow.hpp"

//Constructors and member functions for a window in a registrars office
RWindow::RWindow()
{
    free = true;
    lastArrivalTime = 0;
}

bool RWindow::isFree()
{
    if (free)
        return true;
    if (s.done())
        free = true;
    return free;
    
}

void RWindow::addStudent(Student &st)
{
    s = st;
    free = false;
    lastArrivalTime = st.getArrivalTime();
}

int RWindow::getLastArrivalTime()
{
    return lastArrivalTime;
}

Student RWindow::getStudent()
{
    return s;
}
