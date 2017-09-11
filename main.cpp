//
//  main.cpp
//  ROSimulation
//
//  Created by Anup Sankarraman on 3/26/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include "Queue.cpp"
#include "Student.hpp"
#include "RWindow.hpp"

using namespace std;


int main(int argc, const char * argv[])
{
    
    if (argc < 2)
    {
        cerr << "Usage: " << argv[0] << " <name of input file> " << endl;
        return 1;
    }
    
    string inputf;
    string inputc;
    string line;
    int numberOfWindows;
    int numberOfStudents = 0;
    int numArriving;
    int arrivalTime, processTime;
    Queue<Student *> cq = Queue<Student *>();
    RWindow *window;
    
    inputf = argv[1];
    //Open the input file containing simulation information
    ifstream ifile (inputf);
    if (ifile.is_open())
    {
        getline(ifile, line);
        numberOfWindows = stoi(line);
        
        window = new RWindow [numberOfWindows];
        //gather all the information of students arriving at registrar office and put them in a queue.
        while (getline(ifile, line))
        {
            arrivalTime = stoi(line);
            getline(ifile, line);
            numArriving = stoi(line);
            numberOfStudents += numArriving;
            for (int i = 0; i < numArriving; i++)
            {
                getline(ifile, line);
                processTime = stoi(line);
                Student *c = new Student(arrivalTime, processTime);
                cq.enQueue(c);
            }
        }
    }
    else
    {
        cerr << "Unable to open file: " << argv[1] << endl;
        return 1;
    }
    ifile.close();
    
    int clockTick = 0;
    //the following variables keep track of student (wait time) information
    double totalWaitTime = 0;
    int maxWaitTime = 0;
    int waitTimeMorethan10 = 0;
    
    //the following variables keep track of window (idle time) information
    double totalIdleTime = 0;
    int maxIdleTime = 0;
    int windowsIdleOver5 = 0;
    
    //the following is used to keep all the wait time of students so we can find median
    int *studentWaitTimeSortArray = new int [numberOfStudents];
    int studentWaitTimeIndex = 0;
    
    //simulation starts here
    //we process students one by one until all students are processed
    //if a window is free and there is a student, the student is assigned to the window
    //as we assign  students to windows we keep track of student wait time and window idle time stats
    while (!cq.empty())
    {
        for (int i = 0; i < numberOfWindows; i++)
        {
            if ((window[i].isFree() && !cq.empty()) && (cq.front()->getArrivalTime() <= clockTick))
            {
                
                int studentWaitTime = clockTick - cq.front()->getArrivalTime();
                if (studentWaitTime < 0)
                    studentWaitTime = 0;
                studentWaitTimeSortArray[studentWaitTimeIndex] = studentWaitTime;
                studentWaitTimeIndex++;
                totalWaitTime += studentWaitTime;
                if (maxWaitTime < studentWaitTime)
                    maxWaitTime = studentWaitTime;
                if (studentWaitTime > 10)
                    waitTimeMorethan10++;
                
                int windowIdleTime = cq.front()->getArrivalTime() - window[i].getLastArrivalTime();
                totalIdleTime += windowIdleTime;
                if (maxIdleTime < windowIdleTime)
                    maxIdleTime = windowIdleTime;
                if (windowsIdleOver5 > windowIdleTime)
                    windowsIdleOver5++;
                Student *frontStudent = cq.front();
                window[i].addStudent(*frontStudent);
                cq.deQueue();
            }
        }
        clockTick++;
    }
    
    double studentMedianWaitTime = 0;
    sort (studentWaitTimeSortArray, studentWaitTimeSortArray + numberOfStudents);
    if ((numberOfStudents %2) == 1)
        studentMedianWaitTime = studentWaitTimeSortArray[numberOfStudents/2];
    else
        studentMedianWaitTime = (studentWaitTimeSortArray[numberOfStudents/2] + studentWaitTimeSortArray[numberOfStudents/2 + 1]) /2;
    
    
    cout << "Registrar Office Student-Teller Service Window Simulation Statistics: " << endl << endl;
    cout << "Mean Student wait time: " << totalWaitTime / numberOfStudents << endl;
    cout << "Median Student wait time: " << studentMedianWaitTime << endl;
    cout << "Longest Student wait time: " << maxWaitTime << endl;
    cout << "Number of Students waiting more than 10 minutes: " << waitTimeMorethan10 << endl;
    cout << endl;
    
    cout << "Mean Window Idle Time: " << totalIdleTime / numberOfWindows << endl;
    cout << "Longest Window Idle Time: " << maxIdleTime << endl;
    cout << "Number of times a window is idle more than 5 minutes: " << windowsIdleOver5 << endl;
    cout << endl;
    
    return 0;
}
