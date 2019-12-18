#include "ListQueue.h"
#include "FileIO.h"
#include <algorithm>
#include <cassert>
#include <cctype>
#include "Check.h"
#include "Window.h"
#include "Student.h"
#include "Simulation.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  FileIO checkFile;
  ifstream readFile;
  Check checkData;
  Simulation simulate;

  string filename;

  if (checkData.CheckArg(argc) == -1) //checks correct input of command line argument
  {
    return -1;
  }

  filename = argv[1];

  if (checkFile.ReadFileOpen(readFile, filename) == -1) //checks for correct file read input
  {
    return -1;
  }

  if (!checkData.CheckFile(readFile))
  {
    return -1;
  }

  int linecount = simulate.ReturnLineNumber(readFile);
  int linenumber = 0;

  int windowSize = simulate.GetLine(readFile, linenumber); //reads the first line
  Window* windowArray= new Window[windowSize];   //we have this many windows open ALSO getline is @ the first number
  for (int i = 0; i < windowSize; ++i)
  {
    windowArray[i].setOccupied(false);
  }
  for (int i = 0; i < windowSize; ++i)
  {
    windowArray[i].setIdleTime(0);
    windowArray[i].setOccupiedTime(0);
  }

  ListQueue<Student>* myQueue = new ListQueue<Student>(); //queue of students
  int numstudents = simulate.ReturnStudent(readFile);
  int* waitArray = new int[numstudents];
  int oldtime = 0;
  int waitarraycount = 0;
  linenumber = 0;
  bool windowbool = true;
  int countasd = 0;
  int timegap2 = 0;
  int sumWaitTime = 0;
  int longestWaitTime = 0;
  int numStudentsOverTen = 0; //initiating variables needed
  double averageWaitTime = 0;
  double medianWaitTime = 0;
  int sumIdleTime = 0;
  int longestIdleTime = 0;
  int numWindowsOverFive = 0;
  double averageIdleTime = 0;

  simulate.GetLine(readFile, linenumber); //skips the first line
  do
  {
    if (linenumber != linecount) //if reading the file reached the end of its path
    {
      //Reading the time of the clock
      int newtime = simulate.GetLine(readFile, linenumber); //reads the time
      int timegap2 = newtime - oldtime; //calculates how much time has passed
      oldtime = newtime; //old time is now new time to comapre for the next iteration


      //inserting students into line
      int number_student = simulate.GetLine(readFile, linenumber); //Starts to read number of students
      for (int i = 0; i < number_student; ++i)
      {
        int requiredTime = simulate.GetLine(readFile, linenumber); //getting required time for student
        // Student student(requiredTime, 0); // = new Student(requiredTime, 0);  //making student object with required time
        Student student(requiredTime, 0);// = new Student(requiredTime, 0);
        myQueue -> enqueue(student);
      }
    }
    else
    {
      timegap2++;
    }
    int timegap = timegap2;

    simulate.DecreaseStudentIncreaseWindow(windowSize, windowArray, timegap); //decrease student time, increase window time, open free window
    simulate.WindowOpenTest(myQueue, windowArray, windowSize, waitArray, waitarraycount); //test to see if windows are open for students
    simulate.IncrementStudentWait(myQueue, timegap); //increment student wait time in line
    simulate.WindowOccupiedTest(windowSize, windowArray, windowbool); //test if all windows are unoccupied
}while(windowbool);


  sort(waitArray, waitArray + numstudents); //sorting array
  simulate.CalculateWaitTime(numstudents, longestWaitTime, waitArray, numStudentsOverTen, sumWaitTime, averageWaitTime, medianWaitTime);
  //method to calcluate all wait time for students

  //calcluate all idle time for window
  for (int i = 0; i < windowSize; ++i)
  {
    if (longestIdleTime < windowArray[i].getIdleTIme())
    {
      longestIdleTime = windowArray[i].getIdleTIme();
    }
    if (windowArray[i].getIdleTIme() > 5)
    {
      numWindowsOverFive++;
    }
    sumIdleTime += windowArray[i].getIdleTIme();
  }
  averageIdleTime = (double)sumIdleTime / (double)windowSize;

  simulate.PrintCalc(averageWaitTime, medianWaitTime, longestWaitTime, numStudentsOverTen, averageIdleTime, longestIdleTime, numWindowsOverFive);
  //printing values
  delete[] waitArray;
  delete[] windowArray;
  return 0;
}
