#include "FileIO.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int FileIO::ReadFileOpen(ifstream& new_file, string file_name) //opening a read file
{
  new_file.open(file_name);
  if (!new_file.is_open())    //check if file is open
  {
    cout << "Please enter a valid file name." << endl;
    return -1;
  }
  if (new_file.peek() == ifstream::traits_type::eof())   //checks if file is empty
  {
    return -5;
  }
  else
  {
    return 1;
  }
  return 0;
}

void FileIO::WriteFileOpen(ofstream& new_file, string file_name) //opening a write file
{
  writebool = true;
  while (writebool)
  {
    new_file.open(file_name);
    if (!new_file.is_open()) // checks if the file is open
    {
      cout << "Please enter a valid file name." << endl;
      cin >> file_name;
    }
    else
    {
      writebool = false;
    }
  }
}
