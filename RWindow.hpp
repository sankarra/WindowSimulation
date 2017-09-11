//
//  RegistrarWindow.hpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/26/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef RWindow_hpp
#define RWindow_hpp

#include <stdio.h>
#include "Student.hpp"

//registrar window definition
class RWindow {
    
public:
    RWindow();
    bool isFree();
    void addStudent (Student &s);
    int getLastArrivalTime();
    Student getStudent();
    
private:
    Student s;
    bool free;
    int lastArrivalTime;
    
};

#endif /* RegistrarWindow_hpp */
