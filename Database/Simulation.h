#ifndef SIMULATION_H
#define SIMULATION_H

#include "BST.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "TextFromBST.h"
#include "BSTFromText.h"
#include "GenStack.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Simulation
{
private:
  GenStack<string> *studentStack; //stack of 5 student strings. each string is a big string of nodes
  GenStack<string> *facultyStack; //stack of 5 faculty strings. each string is a big string of nodes
public:
  Simulation(); //constructor pretty much for the stack
  int CheckStudent(BST<Student> *studentTree); //method to check if student exists given the id
  int CheckFaculty(BST<Faculty> *facultyTree); //method to check if faculty exists given the id
  void StartProgram(BST<Student> *studentTree, BST<Faculty> *facultyTree);
  void EndProgram(BST<Student> *studentTree, BST<Faculty> *facultyTree);
  int Choices();
  void Choice_1(BST<Student> *studentTree); //print all student information
  void Choice_1_Support(TreeNode<Student> *node); //support method to print all student information in order recursion
  void Choice_2(BST<Faculty> *facultyTree); //print all faculty information
  void Choice_2_Support(TreeNode<Faculty> *node); //support method to print all faculty information in order recursion
  void Choice_3(BST<Student> *studentTree); //print student information given their id
  void Choice_4(BST<Faculty> *facultyTree); //print faculty information givern their id
  void Choice_5(BST<Student> *studentTree, BST<Faculty> *facultyTree); //print faculty information given student id
  void Choice_6(BST<Student> *studentTree, BST<Faculty> *facultyTree); //print all student info | faculty id
  void Choice_7(BST<Student> *studentTree, BST<Faculty> *facultyTree); //insert a student
  void Choice_8(BST<Student> *studentTree, BST<Faculty> *facultyTree); //delete a student
  void Choice_9(BST<Student> *studentTree, BST<Faculty> *facultyTree); //insert a faculty
  void Choice_10(BST<Student> *studentTree, BST<Faculty> *facultyTree); //delete a faculty
  void Choice_11(BST<Student> *studentTree, BST<Faculty> *facultyTree); //change student advisor id
  void Choice_12(BST<Student> *studentTree, BST<Faculty> *facultyTree); //remove advisee from faculty member
  void Choice_13(BST<Student>* &studentTree, BST<Faculty>* &facultyTree); //undo any operaton
  void Choice_14(); //exit the program
  string StudentStringSerialize(BST<Student> *studentTree); //operation to serialize the student tree into a huge string
  void SupportStudentStringSerialize(stringstream &studentString, BST<Student> *studentTree, TreeNode<Student> *node); //recursion function to inorder traverse add to the string
  string FacultyStringSerialize(BST<Faculty> *facultyTree); //operation to serialize the faculty tree into a huge string
  void SupportFacultyStringSerialize(stringstream &facultyString, BST<Faculty> *facultyTree, TreeNode<Faculty> *node); //recursion function to inorder traverse add to the string
  void PushingToStacks(BST<Student> *studentTree, GenStack<string> *studentStack, BST<Faculty> *facultyTree, GenStack<string> *facultyStack); //method to push things into stacks
};
#endif
