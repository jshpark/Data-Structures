#ifndef CHECK_H
#define CHECK_H

#include "FileIO.h"

#include <iostream>

using namespace std;

class Check
{
public:
  int CheckArg(int num);  //check if correct number of command lime arguments are inputted
  int CheckWhile(int& choice, ifstream& readFile, string& filename, FileIO& checkFile);    //checks the user input for processing another file
  bool CheckFile(ifstream& readFile); //checks to see if all lines are positive integers
};

#endif
