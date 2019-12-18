#include "Check.h"
#include <fstream>
#include <iostream>

using namespace std;

int Check::CheckArg(int num)
{
  if (num > 2) //checks if there are more than just a file name.
  {
    cout << "Too many arguments." << " Enter only a file name." << endl;
    return -1;
  }
  if (num == 1) //checks if the program ran with no arguments other than itself.
  {
    cout << "Please enter a file name." << endl;
    return -1;
  }
}

int Check::CheckDelim(char delimiter, char checkDelimeter, int lineNumber)
{
  if ((delimiter == '{') && ((checkDelimeter == ')') || (checkDelimeter == ']')))   //if popped delimiter is {
  {
    cout << "Syntax error on line " << lineNumber << ".";
    cout << " Expected: " << '}' << " but found " << checkDelimeter << endl;
    return -1;
  }
  else if ((delimiter == '(') && ((checkDelimeter == '}') || (checkDelimeter == ']')))  //if popped delimiter is (
  {
    cout << "Syntax error on line " << lineNumber << ".";
    cout << " Expected: " << ')' << " but found " << checkDelimeter << endl;
    return -1;
  }
  else if ((delimiter == '[') && ((checkDelimeter == '}') || (checkDelimeter == ')')))  //if popped delimiter is [
  {
    cout << "Syntax error on line " << lineNumber << ".";
    cout << " Expected: " << ')' << " but found " << checkDelimeter << endl;
    return -1;
  }
}

int Check::CheckWhile(int& choice, ifstream& readFile, string& filename, FileIO& checkFile)   //checks what user inputted for processing another file
{
  bool choice_while = true;
  while (choice_while)    //while loop is to see if the user puts in real / correct options
  {
    cout << endl;
    cout << "Would you like to process a new file?" << endl << "Enter 1 for yes" << endl << "Enter 2 for no" << endl;
    cin >> choice;
    if (cin.fail() || (!(choice == 1 || choice == 2)))    //cheking if user put a valid choice
    {
      cout << "Please enter a valid option." << endl << endl;
    }
    else
    {
      choice_while = false;
    }
    cin.clear();
    cin.ignore(1000, '\n');
  }

  if (choice == 2)
  {
    readFile.close();
    return -1;      //ends the program if user says no
  }

  readFile.close();
  bool file_while = true;
  while (file_while) //this while loop is to see if the user puts in an actual file name
  {
    cout << endl;
    cout << "What is the file's name?" << endl;
    cin >> filename;
    if (checkFile.ReadFileOpen(readFile, filename) == -1) //checking if file exists/is open.
    {
      continue;
    }
    else
    {
      file_while = false;
    }
    cin.clear();
    cin.ignore(1000, '\n');
  }

  return 0;
}
