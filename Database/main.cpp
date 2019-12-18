#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "SingleLinkedList.h"
#include "Person.h"
#include "BSTFromText.h"
#include "TextFromBST.h"
#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <ctime>

using namespace std;

int main(int argc, char *argv[])
{
  srand(time(NULL));
  Simulation simulation; //this object will carry out all methods
  //creating BST from the text files
  //THIS SHOULD BE IN THE BEGINNING OF THE PROGRAM
  BST<Student> *studentTree = new BST<Student>();
  BST<Faculty> *facultyTree = new BST<Faculty>();
  simulation.StartProgram(studentTree, facultyTree);


/*
  // JUST PUTTING FACULTY OBJECTS INTO FILE
  Faculty faculty(5984, "Allali", "Professor", "Mathematics", 4621);
  Faculty faculty2(8426, "Rene", "Professor", "Computer Science", 1352);
  facultyTree -> insert(faculty);
  facultyTree -> insert(faculty2);



  // JUST PUTTING STUDENT OBJECTS INTO FILE
  Student student(4621, "John", "Sophomore", "Software Engineering", 4.00, 5894);
  Student student2(1352, "Angelica", "Freshman", "Health Science", 4.00, 8426);
  studentTree -> insert(student);
  studentTree -> insert(student2);
*/



  //MENU SHOULD GO HERE
  int choice = 0;
  while (choice != 14)
  {
    choice = simulation.Choices(); //asks for what choice the user wants
    switch (choice)
    {
      case 1:
        simulation.Choice_1(studentTree); //choice is 1...printing all student information
        break;
      case 2:
        simulation.Choice_2(facultyTree); //choice is 2...printing all faculty information
        break;
      case 3:
        simulation.Choice_3(studentTree); //choice is 3...printing one student information | their id
        break;
      case 4:
        simulation.Choice_4(facultyTree); //choice is 4 ...printing one faculty information | their id
        break;
      case 5:
        simulation.Choice_5(studentTree, facultyTree); //choice is 5...printing faculty information | student id
        break;
      case 6:
        simulation.Choice_6(studentTree, facultyTree); //choice is 6...printing all student information | faculty id
        break;
      case 7:
        simulation.Choice_7(studentTree, facultyTree); //choice is 7...inserting a student object
        break;
      case 8:
        simulation.Choice_8(studentTree, facultyTree); //choice is 8...deleting a student object
        break;
      case 9:
        simulation.Choice_9(studentTree, facultyTree); //choice is 9...inserting a faculty object
        break;
      case 10:
        simulation.Choice_10(studentTree, facultyTree); //choice is 10... deleting a faculty object NEED TO FIX THIS ASAP RETURNING RANDOM NODE
        break;
      case 11:
        simulation.Choice_11(studentTree, facultyTree); //choice is 11...change students advisor given student id and new faculty id
        break;
      case 12:
        simulation.Choice_12(studentTree, facultyTree); //choice is 12...remove advisee from a faculty member
        break;
      case 13:
        simulation.Choice_13(studentTree, facultyTree); //choice is 13...rollback
        break;
      case 14:
        simulation.Choice_14(); //choice is 14
        break;
    }
    cout << endl << endl << endl << "Press the Enter key to continute..."; //this is to make the UI cleaner. Forces the user to enter
    cin.get();
  }
  //writing objects back into text files
  //THIS SHOULD BE AT THE END OF THE PROGRAM AFTER THE USER SAYS TO EXIT
  simulation.EndProgram(studentTree, facultyTree);
  return 0;
}
