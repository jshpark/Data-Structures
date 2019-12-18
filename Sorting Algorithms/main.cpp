#include "Check.h"
#include "FileIO.h"
#include "Simulation.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

int main(int argc, char** argv)
{
  Check check; //object to check arguments
  FileIO checkReadFile; //object to read file
  ifstream readFile; //object to read file
  Simulation simulate; //object to simulate program
  if (check.CheckArg(argc) == -1) //checking to see if the number of inputs is correct
  {
    return 0;
  }
  if (checkReadFile.ReadFileOpen(readFile, argv[1]) == -1) //checking if file is valid
  {
    return 0;
  }
  if (!check.CheckFile(readFile))
  {
    return 0;
  }


  readFile.open(argv[1]); //opening file again because it was closed
  int lineNumber = simulate.GetLineNumber(readFile); //getting total number of lines
  int lineCount = 1; //line count starts at 1
  readFile.open(argv[1]); //opening file again because it was closed.
  int arrayLength = (int)simulate.GetLine(readFile); //getting first line data

  double* myQuickArray = new double[arrayLength]; //making quick sory array
  double* myInsertionArray = new double[arrayLength]; //making insertion sort array
  double* myBubbleArray = new double[arrayLength]; //making bubble sort array
  double* mySelectionArray = new double[arrayLength]; //making selection sort array

  string line; //line of each file
  while (lineCount < lineNumber) //reading line
  {
    //inputting data into arrays
    double data = simulate.GetLine(readFile);
    myQuickArray[lineCount - 1] = data;
    myInsertionArray[lineCount - 1] = data;
    myBubbleArray[lineCount - 1] = data;
    mySelectionArray[lineCount - 1] = data;
    lineCount++;
  }

  //calculating bubble sort time
  high_resolution_clock::time_point bubble_Time_1 = high_resolution_clock::now();
  simulate.BubbleSort(myBubbleArray, arrayLength);
  high_resolution_clock::time_point bubble_Time_2 = high_resolution_clock::now();
  duration<double> bubbleElapsedTime = duration_cast<duration<double>>(bubble_Time_2 - bubble_Time_1);

  high_resolution_clock::time_point selection_Time_1 = high_resolution_clock::now();
  simulate.SelectionSort(mySelectionArray, arrayLength);
  high_resolution_clock::time_point selection_Time_2 = high_resolution_clock::now();
  duration<double> selectionElapsedTime = duration_cast<duration<double>>(selection_Time_2 - selection_Time_1);


  high_resolution_clock::time_point insertion_Time_1 = high_resolution_clock::now();
  simulate.InsertionSort(myInsertionArray, arrayLength);
  high_resolution_clock::time_point insertion_Time_2 = high_resolution_clock::now();
  duration<double> insertionElapsedTime = duration_cast<duration<double>>(insertion_Time_2 - insertion_Time_1);

  high_resolution_clock::time_point quick_Time_1 = high_resolution_clock::now();
  simulate.QuickSort(myQuickArray, 0, arrayLength - 1);
  high_resolution_clock::time_point quick_Time_2 = high_resolution_clock::now();
  duration<double> quickElapsedTime = duration_cast<duration<double>>(quick_Time_2 - quick_Time_1);


  cout << "Time it took to sort using Bubble Sort: " << bubbleElapsedTime.count() << endl;
  cout << "Time it took to sort using Selection Sort: " << selectionElapsedTime.count() << endl;
  cout << "Time it took to sort using Insertion Sort: " << insertionElapsedTime.count() << endl;
  cout << "Time it took to sort using Quick Sort: " << quickElapsedTime.count() << endl;




  delete[] myQuickArray;
  delete[] myInsertionArray;
  delete[] myBubbleArray;
  delete[] mySelectionArray;
  return 0;
};
