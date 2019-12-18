#ifndef TEXTFROMBST_H
#define TEXTFROMBST_H

#include "BST.h"
#include "Person.h"
#include "Faculty.h"
#include "Student.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class TextFromBST
{
public:
  void StudentToText(ofstream &writeFile, BST<Student> *studentTree); //write student objects into file
  void WriteStudentToText(ofstream &writeFile, TreeNode<Student> *node); //write student object into file w/ recursion
  void FacultyToText(ofstream &writeFile, BST<Faculty> *facultyTree); //write faculty objects into file
  void WriteFacultyToText(ofstream &writeFile, TreeNode<Faculty> *node); //write faculty object into file w/ recursion
};
#endif
