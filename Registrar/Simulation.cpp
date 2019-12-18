#include <iostream>
#include "Window.h"
#include "Student.h"
#include "FileIO.h"
#include "ListQueue.h"
#include "Simulation.h"

using namespace std;

Simulation::Simulation()
{
  //empty
}

Simulation::~Simulation()
{

}

int Simulation::GetLine(ifstream& readFile, int& linecount)
{
  string line;
  while(getline(readFile, line)) //reads only line w data
  {
    if (!(line[0] == '\n' || line[0] == '\r'))
    {
      break;
    }
  }
  linecount++;
  return stoi(line);
}

int Simulation::Convert(string line)
{
  return stoi(line);
}

int Simulation::ReturnStudent(ifstream& readFile)
{
  int linecount = 0;
  string line;
  while(getline(readFile, line))
  {
    if (!(line[0] == '\n' || line[0] == '\r'))
    {
      linecount++;
    }
  }
  readFile.clear();
  readFile.seekg(0, ios::beg); //reset the reading position to the beginning
  int totalstudents = 0;
  while(getline(readFile, line)) //reads only line w data
  {
    if (!(line[0] == '\n' || line[0] == '\r'))
    {
      break;
    }
  }
  for (int i = 0; i < linecount; ++i)
  {
    while(getline(readFile, line)) //reads only line w data
    {
      if (!(line[0] == '\n' || line[0] == '\r'))
      {
        break;
      }
    }
    i++;
    while(getline(readFile, line)) //reads only line w data
    {
      if (!(line[0] == '\n' || line[0] == '\r'))
      {
        break;
      }
    }
    i++;
    int temp = stoi(line);
    totalstudents += temp;
    for (int j = 0; j < temp; ++j)
    {
      while(getline(readFile, line)) //reads only line w data
      {
        if (!(line[0] == '\n' || line[0] == '\r'))
        {
          break;
        }
      }
      i++;
    }
  }
  readFile.clear();
  readFile.seekg(0, ios::beg); //reset the reading position to the beginning
  return totalstudents;
}

int Simulation::ReturnLineNumber(ifstream& readFile)
{
  int linecount = 0;
  string line;
  while(getline(readFile, line))
  {
    if (!(line[0] == '\n' || line[0] == '\r'))
    {
      linecount++;
    }
  }
  readFile.clear();
  readFile.seekg(0, ios::beg); //reset the reading position to the beginning
  return linecount++;
}

void Simulation::DecreaseStudentIncreaseWindow(int windowSize, Window *windowArray, int &timegap)
{
  for (int i = 0; i < windowSize; ++i) //for loop to decrease each student's required time in the window
  {
    if (windowArray[i].getOccupied()) //if window is occupied
    {
      windowArray[i].setOccupiedTime(windowArray[i].getOccupiedTime() - timegap); //gets occupied time and decreases it by timegap
      if (windowArray[i].getOccupiedTime() <= 0)
      {
        windowArray[i].setOccupied(false);
      }
    }
    if (!windowArray[i].getOccupied()) //if window is not occupied
    {
      windowArray[i].setIdleTime(windowArray[i].getIdleTIme() + timegap); //increases idle window time by timegap
    }
  }
}

void Simulation::WindowOpenTest(ListQueue<Student> *myQueue, Window *windowArray, int windowSize, int* waitArray, int &waitarraycount)
{
  int tempsize = myQueue -> getSize();
  for (int i = 0; i < tempsize; ++i) //for loop for each student //testing to see if any windows are open so new students can go in
  {
    for (int j = 0; j < windowSize; ++j) //for loop for each window to see if it is occupied
    {
      if (!windowArray[j].getOccupied()) //if window is not occupied
      {
        // int studentwaittime = myQueue -> peek() -> GetWaitTime(); //gets student's wait time
        int studentwaittime = myQueue -> peek().GetWaitTime(); //gets student's wait time
        waitArray[waitarraycount++] = studentwaittime; //inserting waittime
        windowArray[j].setOccupiedTime(myQueue -> dequeue().GetRequiredTime()); //uses student's required time to set window's occupied time
        windowArray[j].setOccupied(true); //if window is not occupied, then now it is

        break; //because now window is occupied, break the window for loop and move onto the next student
      }
    }
  }
}

void Simulation::IncrementStudentWait(ListQueue<Student> *myQueue, int &timegap)
{
  int tempsize2 = myQueue -> getSize();
  Student student;
  for (int i = 0; i < tempsize2; ++i)
  {
    student = myQueue -> dequeue(); //dequeuing student to change their wait time
    student.SetWaitTime(student.GetWaitTime() + timegap); //changing wait time of student by incrementing
    myQueue -> enqueue(student); //putting student back in the back of the line
  } //repeat until the line is back to the original organization
}

void Simulation::WindowOccupiedTest(int windowSize, Window *windowArray, bool &windowbool)
{
  for (int i = 0; i < windowSize; ++i) //going through all windows to see if they are occupied
  {
    if (windowArray[i].getOccupied()) //if one window is occupied
    {
      windowbool = true; //that means all the windows are NOT unoccupied
      break; //break the loop
    }
    else
    {
      windowbool = false; //that means all windows are occupied
    }
  }
}

void Simulation::CalculateWaitTime(int numstudents, int& longestWaitTime, int* waitArray, int &numStudentsOverTen, int &sumWaitTime, double &averageWaitTime, double& medianWaitTime)
{
  for (int i = 0; i < numstudents; ++i)
  {
    if (longestWaitTime < waitArray[i])
    {
      longestWaitTime = waitArray[i]; //finding longest student wait time
    }
    if (waitArray[i] > 10)
    {
      numStudentsOverTen++; //number of students that wait over ten minutes
    }
    sumWaitTime += waitArray[i]; //finding the sum of wait times
  }
  averageWaitTime = (double)sumWaitTime / (double)numstudents; //average of student wait time
  if (numstudents % 2 == 0) //if array size is even, then we must take and average of the two middle numbers
  {
    int sizearray = numstudents;
    medianWaitTime = waitArray[sizearray / 2] + waitArray[(sizearray / 2) - 1]; //taking the average between two middle numbers
  }
  else
  {
    int sizearray = numstudents;
    medianWaitTime = waitArray[(sizearray - 1)/ 2]; //getting the middle number
  }
}

void Simulation::PrintCalc(double &averageWaitTime, double &medianWaitTime, int &longestWaitTime, int &numStudentsOverTen, double &averageIdleTime, int longestIdleTime, int &numWindowsOverFive)
{
  cout << "Mean Student Wait Time: " << averageWaitTime << endl;
  cout << "Median Student Wait Time: " << medianWaitTime << endl;
  cout << "Longest Student Wait Time: " << longestWaitTime << endl;
  cout << "Number of Students Waiting Over 10 Minutes: " << numStudentsOverTen << endl;
  cout << "Mean Window Idle Time: " << averageIdleTime << endl;
  cout << "Longest Window Idle Time: " << longestIdleTime << endl;
  cout << "Number of Windows Idle for Over 5 Minutes: " << numWindowsOverFive << endl;
}
