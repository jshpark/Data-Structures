#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <fstream>

using namespace std;

class Simulation
{
public:
  int GetLineNumber(ifstream& readFile);
  double GetLine(ifstream& readFile);
  void QuickSort(double* myArray, int left, int right);
  int Partition(double* myArray, int left, int right);
  void Swap(double* myArray, int index_1, int index_2);
  void InsertionSort(double* myArray, int& size);
  void BubbleSort(double* myArray, int& size);
  void SelectionSort(double* myArray, int& size);
};
#endif
