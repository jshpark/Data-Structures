#ifndef CHECK_H
#define CHECK_H

#include "FileIO.h"
#include <iostream>

using namespace std;

class Check
{
public:
  int CheckArg(int num);  //check if correct number of command lime arguments are inputted
  int CheckDelim(char delimiter, char checkDelimeter, int lineNumber);    //checks the delimeters
  int CheckWhile(int& choice, ifstream& readFile, string& filename, FileIO& checkFile);    //checks the user input for processing another file
};

#endif
