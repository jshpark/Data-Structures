#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "BST.h"
#include <iostream>
#include <string>

using namespace std;

class Student : public Person<Student>
{
public:
  Student(); //constructor, DONE
  Student(int id); //constructor to make student with object w iD, DONE
  Student(int id, string Name, string Level, string Major, double gpa); //constructor
  Student(int id, string Name, string Level, string Major, double gpa, int AdvisorID); //constructor, DONE
  ~Student(); //destructor, UNSURE
  int getID(); //accessor for ID, DONE
  string getName(); //accessor for name, DONE
  string getLevel(); //accessor for level, DONE
  string getMajor(); //accessor for major, DONE
  double getGPA(); //accessor for GPA, DONE
  int getAdvisorID(); //accessor for advisorID, DONE
  void setAdvisorID(int facID); //mutator for advisorID, DONE
  bool operator < (Student &student); //overloaded operator for <, DONE
  bool operator > (Student &student); //overloaded operator for >, DONE
  bool operator == (Student &student); //overlaoded operator for ==, DONE
  bool operator != (Student &student); //overloaded operator for !=, DONE
  ostream& serialize(ostream &out);
private:
  string major;
  double GPA;
  int advisorID;
};
ostream& operator << (ostream &o, Student &student); //overloaded operator for <<,

#endif
