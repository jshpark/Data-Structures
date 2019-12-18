#ifndef SIMULATION_
#define SIMULATION_

#include <iostream>
#include <fstream>
#include <string>
#include "Window.h"
#include "Student.h"
#include "FileIO.h"
#include "ListQueue.h"

using namespace std;

class Simulation
{
public:
  Simulation();
  ~Simulation();
  int GetLine(ifstream& readFile, int& linecount);
  int Convert(string line);
  int ReturnStudent(ifstream& readFile);
  int ReturnLineNumber(ifstream& readFile);
  void DecreaseStudentIncreaseWindow(int windowSize, Window *windowArray, int &timegap);
  void WindowOpenTest(ListQueue<Student> *myQueue, Window* windowArray, int windowSize, int* waitArray, int &waitarraycount);
  void IncrementStudentWait(ListQueue<Student> *myQueue, int &timegap);
  void WindowOccupiedTest(int windowSize, Window *windowArray, bool &windowbool);
  void CalculateWaitTime(int numstudents, int& longestWaitTime, int* waitArray, int &numStudentsOverTen, int &sumWaitTime, double &averageWaitTime, double& medianWaitTime);
  void PrintCalc(double &averageWaitTime, double &medianWaitTime, int &longestWaitTime, int &numStudentsOverTen, double &averageIdleTime, int longestIdleTime, int &numWindowsOverFive);
private:

};
#endif
