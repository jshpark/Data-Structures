#include "BSTFromText.h"
#include "BST.h"
#include "Person.h"
#include "Faculty.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void BSTFromText::StudentToBST(ifstream &readFile, BST<Student> *studentTree) //creating BST from studentTable file
{
  readFile.open("studentTable.txt"); //opening text file
  if (readFile.peek() == ifstream::traits_type::eof())   //checks if file is empty
  {
    //do nothing
  }
  else //if its not empty
  {
    string line;
    string data;
    while (getline(readFile, line)) //reading each "object"
    {
      if (line.empty())
      {
        break;
      }
      string studentarr[6]; //array of 6 because each student object has 6 members
      int index = 0;
      for (int i = 0; i < line.length(); ++i)
      {
        if (line[0] == '\n' || line[0] == '\r')
        {
          break;
        }
        if (line[i] == ',') //if the char is a comma, then insert the data before the comma into the array
        {
          studentarr[index++] = data;
          data = ""; //resets the data string to empty
        }
        else
        {
          data += line[i]; //inserts more data into the data string
        }
      }
      Student student(stoi(studentarr[0]), studentarr[1], studentarr[2], studentarr[3], stod(studentarr[4]), stoi(studentarr[5])); //creating the student object with the array
      studentTree -> insert(student); //inserting student object into tree
    }
  }
  readFile.close();
}

void BSTFromText::FacultyToBST(ifstream &readFile, BST<Faculty> *facultyTree) //creating BST from facultyTable file
{
  readFile.open("facultyTable.txt"); //opening facultTable text document
  if (readFile.peek() == ifstream::traits_type::eof())   //checks if file is empty
  {
    //do nothing
  }
  else //if it's not empty
  {
    string line;
    string data;
    while (getline(readFile, line)) //reading each line from the text document
    {
      if (line.empty())
      {
        break;
      }
      int comma = 0;
      for (int i = 0; i < line.length(); ++i) //going through line to see how many commas there are
      {
        if (line[i] == ',') //if the character of the line is a comma, then increment once
        {
          comma++; //this is to see how big the array of data should be
        }
      }
      string facultyarr[comma]; //creating the array
      int index = 0;
      for (int i = 0; i < line.length(); ++i)
      {
        if (line[0] == '\n' || line[0] == '\r') //if the character is a new line character, then move on to the next line
        {
          break;
        }
        if (line[i] == ',') //if the char is a comma, then insert the data before the comma into the array
        {
          facultyarr[index++] = data;
          data = ""; //resets the data string to empty
        }
        else
        {
          data += line[i]; //inserts more chars into the data string
        }
      }
      if (comma == 4) //if there are no advisee ID for the faculty
      {
        Faculty faculty(stoi(facultyarr[0]), facultyarr[1], facultyarr[2], facultyarr[3]); //create faculty object without student id
        facultyTree -> insert(faculty); //insert object into tree
      }
      else
      {
        Faculty faculty(stoi(facultyarr[0]), facultyarr[1], facultyarr[2], facultyarr[3], stoi(facultyarr[4])); //create faculty object with student id
        if (comma > 5)
        {
          for (int i = 5; i < comma; ++i) // if there contains more than one student id for the faculty
          {
            faculty.AddToFacultyIDList(stoi(facultyarr[i])); //add more
          }
        }
        facultyTree -> insert(faculty); //insert
      }
    }
  }
  readFile.close();
}
