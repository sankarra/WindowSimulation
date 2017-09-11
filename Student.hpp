//
//  Customer.hpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/26/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>

//definition of student
class Student {
public:
    Student();
    Student (int at, int pt);
    bool done();
    int getArrivalTime();
    int getProcessTime();
    int getWaitTime();
    void addToWaitTime(int w);
    
protected:
    int arrivalTime;
    int processTime;
};


#endif /* Student_hpp */
