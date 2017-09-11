//
//  Student.cpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/29/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#include "Student.hpp"

//constructor and member functions for each student arriving to the registrars office for some service
//student arrives at the registrars office at some time and have their request processed for a period of time
Student::Student()
{
    arrivalTime = processTime = 0;
}
Student::Student(int at, int pt)
{
    arrivalTime = at;
    processTime = pt;
}

bool Student::done()
{
    return --processTime == 0;
}

int Student::getArrivalTime()
{
    return arrivalTime;
}

int Student::getProcessTime()
{
    return processTime;
}
