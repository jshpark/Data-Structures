#ifndef FACULTY_H
#define FACULTY_H

#include "Person.h"
#include "BST.h"
#include "SingleLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Faculty : public Person<Faculty>
{
private:
  string department;
  SingleLinkedList<int> *studentList;
public:
  Faculty(); //constructor,
  Faculty(int id); //constructor to create a temporary faculty object to delete node from tree,
  Faculty(int id, string Name, string Level, string Department); //overaloded constructor if student id is not given
  Faculty(int id, string Name, string Level, string Department, int studentid); //overloded constructor
  ~Faculty(); //destructor
  void AddToFacultyIDList(int id);
  void DeleteFromFacultyIDList(int id);
  void PrintList(); //just to test if the list in this class works
  int getID(); //get id
  string getName(); //get faculty name,
  string getLevel(); //get level of faculty,
  string getDepartment(); //get department of faculty
  string getStudentList(); //outputs all ints in the linked list
  int getStudentListSize(); //getting size of linked list for students
  int getStudentNumberFromList(int index); //getting id of one studnet from the studentlist
  bool getContains(int value); //seeing if a student id is in the student list
  bool operator < (Faculty &faculty); //overloaded operator for <,
  bool operator > (Faculty &faculty); //overloaded operator for >,
  bool operator == (Faculty &faculty); //overloaded operator for ==,
  bool operator != (Faculty &faculty); //overloaded operatorfor !=
  ostream& serialize(ostream &out);
};
ostream& operator << (ostream &out, Faculty &faculty); //overloaded operator for <<,
#endif
