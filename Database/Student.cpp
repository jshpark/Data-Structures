#include "Student.h"
#include "Person.h"
#include "BST.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Student::Student()
{
  ID = 0;
  name = "Bob";
  level = "freshman";
  major = "undeclared";
  GPA = 4.0;
  advisorID = 0;
}

Student::Student(int id)
{
  ID = id;
  name = "Bob";
  level = "freshman";
  major = "undeclared";
  GPA = 4.0;
  advisorID = 0;
}

Student::Student(int id, string Name, string Level, string Major, double gpa)
{
  ID = id;
  name = Name;
  level = Level;
  major = Major;
  GPA = gpa;
  advisorID = 0;
}

Student::Student(int id, string Name, string Level, string Major, double gpa, int AdvisorID)
{
  ID = id;
  name = Name;
  level = Level;
  major = Major;
  GPA = gpa;
  advisorID = AdvisorID;
}

Student::~Student()
{

}

int Student::getID()
{
  return ID;
}

string Student::getName()
{
  return name;
}

string Student::getLevel()
{
  return level;
}

string Student::getMajor()
{
  return major;
}

double Student::getGPA()
{
  return GPA;
}

int Student::getAdvisorID()
{
  return advisorID;
}

void Student::setAdvisorID(int facID)
{
  advisorID = facID;
}

bool Student::operator < (Student &student) //overloaded operator for '<'
{
  return (this -> ID < student.ID);
}

bool Student::operator > (Student &student) //overloaded operator for '>'
{
  return (this -> ID > student.ID);
}

bool Student::operator == (Student &student) //overloaded operator for '=='
{
  return (this -> ID == student.ID);
}

bool Student::operator != (Student &student) //overloaded operaor for '!='
{
  return (!(this -> ID == student.ID));
}

ostream& Student::serialize(ostream &out)
{
  out << ID;
  out << ',';
  out << name;
  out << ',';
  out << level;
  out << ',';
  out << major;
  out << ',';
  out << GPA;
  out << ',';
  out << advisorID;
  out << ',';
  out << "\r\n";
}

ostream& operator << (ostream &o, Student &student) //overlaoded operator for <<
{
  return student.serialize(o);
}
