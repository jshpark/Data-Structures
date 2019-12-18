#ifndef BSTFROMTEXT_H
#define BSTFROMTEXT_H

#include "BST.h"
#include "Person.h"
#include "Faculty.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class BSTFromText
{
public:
  void StudentToBST(ifstream& readFile, BST<Student> *studentTree); //this is to create a BST from the file for STUDENTS
  void FacultyToBST(ifstream& readFile, BST<Faculty> *facultyTree); //this is to create a BST from the file for FACULTY
};
#endif
