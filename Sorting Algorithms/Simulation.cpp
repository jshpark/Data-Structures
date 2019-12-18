#include "Simulation.h"
#include <iostream>
#include <fstream>

using namespace std;

int Simulation::GetLineNumber(ifstream& readFile)
{
  string line;
  int lineNumber = 0;
  while(getline(readFile, line))
  {
    if (!(line[0] == '\n' || line[0] == '\r'))
    {
      lineNumber++;
    }
  }
  readFile.close();
  return lineNumber;
}

double Simulation::GetLine(ifstream& readFile)
{
  int check = 0;
  string line;
  while(getline(readFile, line)) //reads only line w data
  {
    if (!(line[0] == '\n' || line[0] == '\r'))
    {
      return stod(line);
      break;
    }
  }
}

void Simulation::QuickSort(double* myArray, int left, int right)
{
  int tempIndex = Partition(myArray, left, right); //Partition and get the pivot placement
  if (left < tempIndex - 1) //if the left is less than the pivot's placement - 1
  {
    QuickSort(myArray, left, tempIndex - 1); //quicksort again but on the left side of the pivot
  }
  if (tempIndex < right) //if the right is greater than the pivot's placement
  {
    QuickSort(myArray, tempIndex, right); //quicksort again but on the right side of the pivot
  }
}

int Simulation::Partition(double* myArray, int left, int right)
{
  double pivot = myArray[(left + right) / 2 ]; //pivot is in the middle regardless if its even or odd length, it just rounds
  int i = left;
  int j = right;
  while (i <= j) //while loop to make sure left is less than right
  {
    while (myArray[i] < pivot) //if left is less than pivot
    {
      ++i; //just continue, do nothing (increment left)
    }
    while (myArray[j] > pivot) //if right is greater than pivot
    {
      --j; //just continue, do nothing (decrement right)
    }
    if (i <= j)
    {
      Swap(myArray, i, j); //swap the two now because there is an interruption
      ++i; //increment left
      --j; //decrement right
    }
  }
  return i; //return the new left value 
}

void Simulation::Swap(double* myArray, int index_1, int index_2)
{
  double temp = myArray[index_1];
  myArray[index_1] = myArray[index_2];
  myArray[index_2] = temp;
}

void Simulation::InsertionSort(double* myArray, int& size)
{
  for (int i = 1; i < size; ++i) //for loop starts at 1 because we dont need to sort the first item of the array
  {
    double temp = myArray[i]; //make a temp value for the value at that index
    int j = i; //create a temp int for the index
    while (j > 0 && myArray[j -1] >= temp) //if the temp int is greater than 0, and the value before that temp int is bigger than temp
    {
      myArray[j] = myArray[j - 1]; //make the current array index equal to the previous array index
      j--; //decrement j
    }
    myArray[j] = temp; //once sorted, make the current index the temp value
  }
}

void Simulation::BubbleSort(double* myArray, int& size)
{
  for (int i = 0; i < size; ++i) //starting from the first index
  {
    for (int j = 0; j < size - i - 1; ++j) //size - i - 1 because when 1 increases, the left side is already sorted, so we have to take into account of that
    {
      if (myArray[j] > myArray[j + 1]) //if the index ahead is smaller than the index behind
      {
        double temp = myArray[j + 1];
        myArray[j + 1] = myArray[j];  //swap
        myArray[j] = temp;
      }
    }
  }
}

void Simulation::SelectionSort(double* myArray, int& size)
{
  for (int i = 0; i < size - 1; ++i)
  {
    int minIndex = i;
    for (int j = i + 1; j < size; ++j)
    {
      if (myArray[j] < myArray[minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      double temp = myArray[i];
      myArray[i] = myArray[minIndex];
      myArray[minIndex = temp];
    }
  }
}
