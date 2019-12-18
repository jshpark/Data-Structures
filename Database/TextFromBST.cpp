#include "TextFromBST.h"
#include "BST.h"
#include "Person.h"
#include "Faculty.h"
#include "Student.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void TextFromBST::StudentToText(ofstream &writeFile, BST<Student> *studentTree)
{
  writeFile.open("studentTable.txt"); //opening file
  WriteStudentToText(writeFile, studentTree -> getRoot()); //inorder serialization of student objects
  writeFile.close();
}

void TextFromBST::WriteStudentToText(ofstream &writeFile, TreeNode<Student> *node) //in order recursion
{
  if (node == NULL)
  {
    return;
  }
  WriteStudentToText(writeFile, node -> left);
  writeFile << node -> key; //write node to file
  WriteStudentToText(writeFile, node -> right);
}

void TextFromBST::FacultyToText(ofstream &writeFile, BST<Faculty> *facultyTree)
{
  writeFile.open("facultyTable.txt"); //opening file
  WriteFacultyToText(writeFile, facultyTree -> getRoot()); //inorder serialization of faculty objects
  writeFile.close();
}

void TextFromBST::WriteFacultyToText(ofstream &writeFile, TreeNode<Faculty> *node)
{
  if (node == NULL)
  {
    return;
  }
  WriteFacultyToText(writeFile, node -> left);
  writeFile << node -> key; //write node to file
  WriteFacultyToText(writeFile, node -> right);
}
