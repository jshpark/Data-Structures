#include "Faculty.h"
#include "Person.h"
#include "BST.h"
#include "SingleLinkedList.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

Faculty::Faculty()
{
  ID = 0;
  name = "Bob";
  level = "academic advisor";
  department = "registrar";
}

Faculty::Faculty(int id)
{
  ID = id;
  name = "Bob";
  level = "academic advisor";
  department = "registrar";
}

Faculty::Faculty(int id, string Name, string Level, string Department)
{
  ID = id;
  name = Name;
  level = Level;
  department = Department;
  studentList = new SingleLinkedList<int>();
}

Faculty::Faculty(int id, string Name, string Level, string Department, int studentid)
{
  ID = id;
  name = Name;
  level = Level;
  department = Department;
  studentList = new SingleLinkedList<int>();
  studentList -> InsertFront(studentid);
}

Faculty::~Faculty()
{

}

void Faculty::PrintList() //ONLY USED TO TEST IF SINGLE LINKED LIST WORKS IN THIS CLASS
{
  studentList -> PrintList();
}

void Faculty::AddToFacultyIDList(int id)
{
  studentList -> InsertFront(id);
}

void Faculty::DeleteFromFacultyIDList(int id)
{
  studentList -> DeleteValue(id);
}
int Faculty::getID()
{
  return ID;
}

string Faculty::getName()
{
  return name;
}

string Faculty::getLevel()
{
  return level;
}

string Faculty::getDepartment()
{
  return department;
}

string Faculty::getStudentList()
{
  string whitespace = "";
  string para = "";
  if (studentList != 0)
  {
    for (int i = 0; i < 67; ++i)
    {
      whitespace += " ";
    }
    string whitespace2 = "";
    for (int i = 0; i < 30; ++i)
    {
      whitespace2 += " ";
    }
    for (int i = 0; i < studentList -> getSize(); ++i)
    {
      para += whitespace2;
      para += to_string(studentList -> ReturnPosition(i));
      para += "\n";
      para += whitespace;
    }
  }
  return para;
}

int Faculty::getStudentListSize()
{
  return studentList -> getSize();
}

int Faculty::getStudentNumberFromList(int index)
{
  return studentList -> ReturnPosition(index);
}

bool Faculty::getContains(int value)
{
  return studentList -> contains(value);
}

bool Faculty::operator < (Faculty &faculty)
{
  return (this -> ID < faculty.ID);
}

bool Faculty::operator > (Faculty &faculty)
{
  return (this -> ID > faculty.ID);
}

bool Faculty::operator == (Faculty &faculty)
{
  return (this -> ID == faculty.ID);
}

bool Faculty::operator != (Faculty &faculty)
{
  return (!(this -> ID == faculty.ID));
}

ostream& Faculty::serialize(ostream &out) //serialization
{
  out << ID;
  out << ',';
  out << name;
  out << ',';
  out << level;
  out << ',';
  out << department;
  out << ',';

  for (int i = 0; i < studentList -> getSize(); ++i)
  {
    out << to_string(studentList -> ReturnPosition(i));
    out << ',';
  }
  out << "\r\n";
  return out;
}

ostream &operator << (ostream &o, Faculty &faculty) //comma serialization << operator
{
  return faculty.serialize(o);
}
