#include "GenStack.h"
#include "FileIO.h"
#include "Check.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
  FileIO checkFile;
  ifstream readFile;        //creating objects of classes
  Check checkData;
  GenStack<char> myStack(100);    //creating stack of 100.

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

  int choice; //used later to see if user wants to process a new file
  do
  {
    string line;
    int lineNumber = 1; //lines start at 1 not 0
    while (getline(readFile, line))
    {
      cout << lineNumber << endl;
      for (int i = 0; i < line.size(); ++i) //reads each character in the string
      {
        cout << i << endl;
        if (line[i] == '\"') //skips data inside a string
        {
          do
          {
            ++i;
          }while (!(line[i] == '\"'));
          continue; //continues the for loop
        }
        else if (line[i] == '\'')   //skips data inside ' '
        {
          do
          {
            ++i;
          }while (!(line[i] == '\''));
          continue; //continues the for loop
        }


        if ((line[i] == '/') && (line[i] == '/'))
        {
          break; //breaks the current loop for the entire line
        }





        if ((line[i] == '{') || (line[i] == '(') || (line[i] == '['))   //if character is open delimiter, push in stack
        {
          myStack.push(line[i]);
        }
        else if ((line[i] == '}') || (line[i] == ')') || (line[i] == ']'))    //if character is closed delimiter, pop out stack
        {
          char delimiter = myStack.pop();
          if (checkData.CheckDelim(delimiter, line[i], lineNumber) == -1)   //checking if delimters match
          {
            readFile.close();   //closes file so object can be used to reopen another file
            return -1;
          }
        }
      }
      lineNumber++; //increases line number by 1
    }

    if (!(myStack.isEmpty()))   //checks to see if stack only has one delimter left. Usually the last curly bracket
    {
      cout << "Reached end of file: missing }" << endl;
      readFile.close();
      return -1;
    }

    cout << "No syntax errors." << endl;    //file has no errors.

    //this part of the code and down is to see if the user wants to process another file
    if (checkData.CheckWhile(choice, readFile, filename, checkFile) == -1) //checks to see if user wants another file
    {
      return -1;
    }
  }while(choice == 1); //loop again if user says yes to processing another file

  return 0;
}
