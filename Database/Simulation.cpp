#include "Simulation.h"
#include "TreeNode.h"
#include "BST.h"
#include "Person.h"
#include "Faculty.h"
#include "Student.h"
#include "TextFromBST.h"
#include "BSTFromText.h"
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;

Simulation::Simulation()
{
  studentStack = new GenStack<string>(5);
  facultyStack = new GenStack<string>(5);
}

int Simulation::CheckStudent(BST<Student> *studentTree) //prompts for id and checks if student exists
{
  int id = 0;
  bool id_bool = true;
  while (id_bool) //while loop to make sure the user inserts a valid ID
  {
    cout << endl << endl;
    cout << "Insert student's ID :";
    cin >> id;
    if (cin.fail())
    {
      cout << "Please enter a valid ID." << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    else
    {
      Student student(id);
      TreeNode<Student> *temp = new TreeNode<Student>(student);
      if (!(studentTree -> contains(id))) //checks to see if the ID exists in the data base
      {
        cout << "Student does not exist. Please enter a valid ID." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
      }
      else
      {
        cin.clear();
        cin.ignore(1000, '\n');
        return id;
      }
    }
  }
}

int Simulation::CheckFaculty(BST<Faculty> *facultyTree) //prompts user for faculty id and checks if it exists
{
  int id = 0;
  bool id_bool = true;
  while (id_bool) //makes sure the user inputs a valid ID
  {
    cout << endl << endl;
    cout << "Insert faculty's ID :";
    cin >> id;
    if (cin.fail())
    {
      cout << "Please enter a valid ID." << endl;
      cin.clear();
      cin.ignore(1000, '\n');
      continue;
    }
    else
    {
      Faculty faculty(id);
      TreeNode<Faculty> *temp = new TreeNode<Faculty>(faculty);
      if (!(facultyTree -> contains(id))) //checks if the ID exists in the database
      {
        cout << "Faculty does not exist. Please enter a valid ID." << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        continue;
      }
      else
      {
        cin.clear();
        cin.ignore(1000, '\n');
        return id;
      }
    }
  }
}

void Simulation::StartProgram(BST<Student> *studentTree, BST<Faculty> *facultyTree) //method to start the program
{
  BSTFromText createBST; //creating object of another class that contains methods to create BST
  ifstream readFile; //reading from file object
  createBST.StudentToBST(readFile, studentTree); //creates student BST
  createBST.FacultyToBST(readFile, facultyTree); //creates faculty BST
}

void Simulation::EndProgram(BST<Student> *studentTree, BST<Faculty> *facultyTree) //method to end the program
{
  TextFromBST createText; //creating object of another class that contains methods to write to file
  ofstream writeFile; //writing to file serialization
  createText.StudentToText(writeFile, studentTree); //serializes student objects into studentTable
  createText.FacultyToText(writeFile, facultyTree); //serializes faculty objects into facultyTable
}

int Simulation::Choices() //determines which choice the user inputs
{
  bool choice_bool = true;
  int choice = 0;
  while (choice_bool) //while loop to make sure the user inputs a valid choice
  {
    cout << "Please enter your desired choice's corresponding number." << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "1) Print all students and their information (sorted by ascending id #)." << endl;
    cout << "2) Print all faculty and their information (sorted by ascending id #)." << endl;
    cout << "3) Find and display student information given the student's id." << endl;
    cout << "4) Find and display faculty information given the faculty's id." << endl;
    cout << "5) Given a student's id, print the name and info of their faculty advisor." << endl;
    cout << "6) Given a faculty's id, print ALL the names and info of his/her advisees." << endl;
    cout << "7) Add a new student." << endl;
    cout << "8) Delete a student given the id." << endl;
    cout << "9) Add a new faculty member." << endl;
    cout << "10) Delete a faculty member given the id." << endl;
    cout << "11) Change a student's advisor given the student's id and the new faculty's id." << endl;
    cout << "12) Remove an advisee from a faculty member given their id." << endl;
    cout << "13) Undo." << endl;
    cout << "14) Exit." << endl;
    cout << "--------------------------------------------------------";
    cout << endl << "Your Option: ";
    cin >> choice;
    if (cin.fail() || !(choice >= 1 && choice <= 14))
    {
      cout << endl << "Please enter a valid option." << endl;
      cout << "--------------------------------------------------------" << endl;
    }
    else
    {
      choice_bool = false;
    }
    cin.clear();
    cin.ignore(1000, '\n');
  }
  return choice; //returns the user's choice
}

void Simulation::Choice_1(BST<Student> *studentTree) //choice 1 is to print all student objects
{
  studentTree -> printTree();
  string line = ""; //this is to create a clean student table
  for (int i = 0; i < 107; ++i)
  {
    line += "_";
  }
  cout << endl << endl;
  cout << setw(7) << "ID" << setw(15) << "Name" << setw(15) << "Year" << setw(30) << "Major" << setw(15) << "GPA" << setw(25) << "Advisor Faculty ID" << endl;
  cout << setw(107) << line << endl << endl; //this is to create the studenttable
  Choice_1_Support(studentTree -> getRoot()); //writing onto the file using recursion method
}

void Simulation::Choice_1_Support(TreeNode<Student> *node) //inorder traverse
{
  if (node == NULL)
  {
    return;
  }
  Choice_1_Support(node -> left); //prints to console the student object in a clean format
  cout << setw(7) << node -> key.getID() << setw(15) << node -> key.getName() << setw(15) << node -> key.getLevel() << setw(30) << node -> key.getMajor() << setw(15) << node -> key.getGPA() << setw(25) << node -> key.getAdvisorID() << endl;
  Choice_1_Support(node -> right);
}

void Simulation::Choice_2(BST<Faculty> *facultyTree) //choice 2 is to print all faculty objects
{
  string line = ""; //this is to create a clean faculty table
  for (int i = 0; i < 117; ++i)
  {
    line += "_";
  }
  cout << endl << endl;
  cout << setw(7) << "ID" << setw(15) << "Name" << setw(15) << "Title" << setw(30) << "Department" << setw(50) << "Faculty Member's Advisees' IDS" << endl;
  cout << line << endl << endl; //this is to create the facultytable
  Choice_2_Support(facultyTree -> getRoot());
}

void Simulation::Choice_2_Support(TreeNode<Faculty> *node) //inorder traverse
{
  if (node == NULL)
  {
    return;
  }
  Choice_2_Support(node -> left); //prints to console the faculty objects in a clean format
  cout << setw(7) << node -> key.getID() << setw(15) << node -> key.getName() << setw(15) << node -> key.getLevel() << setw(30) << node -> key.getDepartment() << setw(35) << node -> key.getStudentList() << endl;
  Choice_2_Support(node -> right);
}

void Simulation::Choice_3(BST<Student> *studentTree) //choice 3 is to print out a student's info given their id
{
  if (studentTree -> GetSize() != 0) //if the student tree is not 0
  {
    int id = CheckStudent(studentTree);
    Student student(id);
    TreeNode<Student> *temp = new TreeNode<Student>(student);
    temp = studentTree -> returnNode(id); //grabbing the node of the corresponding ID
    string line = ""; //again to print a clean student table format
    for (int i = 0; i < 107; ++i)
    {
      line += "_";
    }
    cout << endl << endl;
    cout << setw(7) << "ID" << setw(15) << "Name" << setw(15) << "Year" << setw(30) << "Major" << setw(15) << "GPA" << setw(25) << "Advisor Faculty ID" << endl;
    cout << setw(107) << line << endl << endl; //this is to create the studenttable
    cout << setw(7) << temp -> key.getID() << setw(15) << temp -> key.getName() << setw(15) << temp -> key.getLevel() << setw(30) << temp -> key.getMajor() << setw(15) << temp -> key.getGPA() << setw(25) << temp -> key.getAdvisorID() << endl;
    }
  else //if there are no students in the database
  {
    cout << "No Students exist." << endl;
  }
}

void Simulation::Choice_4(BST<Faculty> *facultyTree) //choice 4 is to print out faculty information given their id
{
  if (facultyTree -> GetSize() != 0) //checks to see if there are faculty objects in the database
  {
    int id = CheckFaculty(facultyTree);
    Faculty faculty(id);
    TreeNode<Faculty> *temp = new TreeNode<Faculty>(faculty);
    temp = facultyTree -> returnNode(id); //grabbing the node corresponding to the ID
    string line = ""; //again this is to create the table format
    for (int i = 0; i < 117; ++i)
    {
      line += "_";
    }
    cout << endl << endl;
    cout << setw(7) << "ID" << setw(15) << "Name" << setw(15) << "Title" << setw(30) << "Department" << setw(50) << "Faculty Member's Advisees' IDS" << endl;
    cout << line << endl << endl; //this is to create the facultytable
    cout << setw(7) << temp -> key.getID() << setw(15) << temp -> key.getName() << setw(15) << temp -> key.getLevel() << setw(30) << temp -> key.getDepartment() << setw(35) << temp -> key.getStudentList() << endl;
  }
  else //no faculties are in the data base
  {
    cout << "No faculties exist." << endl;
  }
}

void Simulation::Choice_5(BST<Student> *studentTree, BST<Faculty> *facultyTree) //choice 5 is to print info of faculty member given student id
{
  if (studentTree -> GetSize() != 0) //you should know what this does by now
  {
    int id = CheckStudent(studentTree); //id of student
    Student student(id);
    TreeNode<Student> *StuTemp = new TreeNode<Student>(student);
    StuTemp = studentTree -> returnNode(id);
    int faculty_id = StuTemp -> key.getAdvisorID(); //grabs the student's advisor's id
    Faculty faculty(id);
    TreeNode<Faculty> *facTemp = new TreeNode<Faculty>(faculty);
    facTemp = facultyTree -> returnNode(faculty_id); //grabs the faculty node that corresponds to the student's advisor's id
    string line = "";
    for (int i = 0; i < 117; ++i)
    {
      line += "_";
    }
    cout << endl << endl;
    cout << setw(7) << "ID" << setw(15) << "Name" << setw(15) << "Title" << setw(30) << "Department" << setw(50) << "Faculty Member's Advisees' IDS" << endl;
    cout << line << endl << endl; //this is to create the facultytable
    cout << setw(7) << facTemp -> key.getID() << setw(15) << facTemp -> key.getName() << setw(15) << facTemp -> key.getLevel() << setw(30) << facTemp -> key.getDepartment() << setw(35) << facTemp -> key.getStudentList() << endl;
  }
  else
  {
    cout << "No students exist." << endl;
  }
}

void Simulation::Choice_6(BST<Student> *studentTree, BST<Faculty> *facultyTree) //choice 6 is to print all advisee information given faculty id
{
  if (facultyTree -> GetSize() != 0)
  {
    int id = CheckFaculty(facultyTree);
    Faculty faculty(id);
    TreeNode<Faculty> *facTemp = new TreeNode<Faculty>(faculty);
    facTemp = facultyTree -> returnNode(id);
    if (facTemp -> key.getStudentListSize() != 0)
    {
      string line = "";
      for (int i = 0; i < 107; ++i)
      {
        line += "_";
      }
      cout << endl << endl;
      cout << setw(7) << "ID" << setw(15) << "Name" << setw(15) << "Year" << setw(30) << "Major" << setw(15) << "GPA" << setw(25) << "Advisor Faculty ID" << endl;
      cout << setw(107) << line << endl << endl; //this is to create the studenttable
      for (int i = 0; i < facTemp -> key.getStudentListSize(); ++i) //for each advisee ID
      {
        int stuID = facTemp -> key.getStudentNumberFromList(i); //grab advisee id
        Student student(stuID);
        TreeNode<Student> *stuTemp = new TreeNode<Student>(student); //create a temporary student object to compare
        stuTemp = studentTree -> returnNode(stuID); //grab actual student object
        cout << setw(7) << stuTemp -> key.getID() << setw(15) << stuTemp -> key.getName() << setw(15) << stuTemp -> key.getLevel() << setw(30) << stuTemp -> key.getMajor() << setw(15) << stuTemp -> key.getGPA() << setw(25) << stuTemp -> key.getAdvisorID() << endl;
      }
    }
    else
    {
      cout << "Faculty does not have any advisees." << endl;
    }
  }
  else
  {
    cout << "No faculties exist." << endl;
  }
}

void Simulation::Choice_7(BST<Student> *studentTree, BST<Faculty> *facultyTree) //choice 7 is to add a new student
{
  int random_id = 0;
  string name = "";
  string level = "";
  string major = "";      //initiating the information needed to create a student object
  double gpa = 0.00;
  bool name_bool = true;
  while (name_bool) //the while loops from here and down are used to make sure the user puts in valid information
  {
    cout << endl << endl;
    cout << "Insert student's name: ";
    getline(cin, name);
    if (cin.fail())
    {
      cout << "Please enter a valid name." << endl;
    }
    else
    {
      name_bool = false;
    }
  }
  bool level_bool = true;
  while (level_bool)
  {
    cout << endl << endl;
    cout << "Insert student's year: ";
    getline(cin, level);
    if (cin.fail())
    {
      cout << "Please enter a valid year." << endl;
    }
    else
    {
      level_bool = false;
    }
  }
  bool major_bool = true;
  while (major_bool)
  {
    cout << endl << endl;
    cout << "Insert student's major: ";
    getline(cin, major);
    if (cin.fail())
    {
      cout << "Please enter a valid major." << endl;
    }
    else
    {
      major_bool = false;
    }
  }
  bool gpa_bool = true;
  while (gpa_bool)
  {
    cout << endl << endl;
    cout << "Insert student's GPA: ";
    cin >> gpa;
    if (cin.fail())
    {
      cout << "Please enter a valid GPA." << endl;
    }
    else
    {
      gpa_bool = false;
    }
    cin.clear();
    cin.ignore(1000, '\n');
  }
  //creating random id for student and insert an existing random faculty id
  while (true)
  {
    random_id = (1 + rand()) % (5000); //getting a random id from 1-5000
    if (studentTree -> contains(random_id)) //seeing if the id already exists
    {
      continue;
    }
    else
    {
      break;
    }
  }
  if (facultyTree -> GetSize() != 0)
  {
    int faculty_id = CheckFaculty(facultyTree);
    Faculty faculty(faculty_id);
    TreeNode<Faculty> *temp = new TreeNode<Faculty>(faculty);
    temp = facultyTree -> returnNode(faculty_id); //grabbing faculty ndoe corresponding to id
    Student newStudent(random_id, name, level, major, gpa, faculty_id); //create new student object
    //PUSHING INTO STACK
    PushingToStacks(studentTree, studentStack, facultyTree, facultyStack);
    //DONE PUSHING
    studentTree -> insert(newStudent);
    temp -> key.AddToFacultyIDList(random_id);
  }
  else
  {
    //pushing into stack
    PushingToStacks(studentTree, studentStack, facultyTree, facultyStack);
    //done pushing
    Student newStudent(random_id, name, level, major, gpa);
    studentTree -> insert(newStudent);
  }
}

void Simulation::Choice_8(BST<Student> *studentTree, BST<Faculty> *facultyTree) //choice 8 is to delete a student given their id
{
  if (studentTree -> GetSize() != 0) //if students exist
  {
    //pushing into stack
    PushingToStacks(studentTree, studentStack, facultyTree, facultyStack);
    //done pushing
    int id = CheckStudent(studentTree); //their id number
    Student student(id);
    TreeNode<Student> *StuTemp = new TreeNode<Student>(student);
    StuTemp = studentTree -> returnNode(id); //grab the node corresponding to the student id
    int faculty_id = StuTemp -> key.getAdvisorID(); //get the advisor's id for the student
    Faculty faculty(faculty_id);
    TreeNode<Faculty> *facTemp = new TreeNode<Faculty>(faculty);
    facTemp = facultyTree -> returnNode(faculty_id); //grab the node corresponding to the faculty id
    facTemp -> key.DeleteFromFacultyIDList(id); //delete the id from the faculty object
    studentTree -> deleteNode(id); //delete the student
    }
  else //if students do not exist
  {
    cout << "No Students exist." << endl;
  }
}

void Simulation::Choice_9(BST<Student> *studentTree, BST<Faculty> *facultyTree) //choice 9 is to add a new faculty member
{
  int random_id = 0;
  string name = "";
  string level = "";    //initiating information needed to create a faculty object
  string department = "";
  bool name_bool = true;
  while (name_bool) //while loops from here and below are to make sure the user inputs valid information
  {
    cout << endl << endl;
    cout << "Insert faculty's name: ";
    getline(cin, name);
    if (cin.fail())
    {
      cout << "Please enter a valid name." << endl;
    }
    else
    {
      name_bool = false;
    }
  }
  bool level_bool = true;
  while (level_bool)
  {
    cout << endl << endl;
    cout << "Insert faculty's position: ";
    getline(cin, level);
    if (cin.fail())
    {
      cout << "Please enter a valid position." << endl;
    }
    else
    {
      level_bool = false;
    }
  }
  bool department_bool = true;
  while (department_bool)
  {
    cout << endl << endl;
    cout << "Insert faculty's department: ";
    getline(cin, department);
    if (cin.fail())
    {
      cout << "Please enter a valid department." << endl;
    }
    else
    {
      department_bool = false;
    }
  }
  while (true) //this while loops is to create a faculty id
  {
    random_id = (rand() % 5001) + 5000; //getting a random id from 5001 - 10000
    if (facultyTree -> contains(random_id)) //seeing if the id already exists
    {
      continue;
    }
    else
    {
      break;
    }
  }
  PushingToStacks(studentTree, studentStack, facultyTree, facultyStack); //pushing into stack
  Faculty faculty(random_id, name, level, department); //create faculty object
  facultyTree -> insert(faculty); //insert it into the tree
}


void Simulation::Choice_10(BST<Student> *studentTree, BST<Faculty> *facultyTree) //choice 10 is to delete a faculty member given their id
{
  if (facultyTree -> GetSize() != 0)
  {
    PushingToStacks(studentTree, studentStack, facultyTree, facultyStack); //pushing into stack
    int id = CheckFaculty(facultyTree);
    Faculty faculty(id);
    TreeNode<Faculty> *facTemp = new TreeNode<Faculty>(faculty);
    facTemp = facultyTree -> returnNode(id); //grab the node corresponding to the faculty id
    if (facTemp -> key.getStudentListSize() != 0) //faculty has advisees
    {
      TreeNode<Faculty> *newFac = new TreeNode<Faculty>();
      for (int i = 0; i < facTemp -> key.getStudentListSize(); ++i) //for each student
      {
        int studentID_temp = facTemp -> key.getStudentNumberFromList(i); //get student id from the student list of the faculty object
        Student student(studentID_temp);
        TreeNode<Student> *student_temp = new TreeNode<Student>(student); //creates a temporary student object from the student id
        student_temp = studentTree -> returnNode(studentID_temp); //grabbing the node corresponding to the id number
        newFac = facultyTree -> getRandomNode(); //grabbing a random node from the faculty tree
        cout << "test" << endl;
        while (true) //checking to see if the random node is not the faculty that we just deleted the advisee from
        {
          if (newFac != facTemp)
          {
            break;
          }
          newFac = facultyTree -> getRandomNode();
        }
        student_temp -> key.setAdvisorID(newFac -> key.getID()); //changing advisee's advisor id to a random one
        newFac -> key.AddToFacultyIDList(studentID_temp); //inserting new advisee to advisor
      }
      facultyTree -> deleteNode(id); //delete faculty object from tree
    }
    else
    {
      facultyTree -> deleteNode(id); //delete faculty object from tree if it has no advisees
    }
  }
  else
  {
    cout << "No faculties exist." << endl;
  }
}


void Simulation::Choice_11(BST<Student> *studentTree, BST<Faculty> *facultyTree)
{
  if (studentTree -> GetSize() != 0) //if students exist
  {
    if (facultyTree -> GetSize() == 1) //if only one faculty member exists, then we cant change advisor ids
    {
      cout << "Only one faculty member exists. Cannot change student's advisor ID." << endl;
    }
    else
    {
      PushingToStacks(studentTree, studentStack, facultyTree, facultyStack); //pushing into stacks
      int id = CheckStudent(studentTree); //their id number
      Student student(id);
      TreeNode<Student> *StuTemp = new TreeNode<Student>(student);
      int new_faculty_id = CheckFaculty(facultyTree); //initiating new faculty id
      StuTemp = studentTree -> returnNode(id); //grab the node corresponding to the student id
      int old_faculty_id = StuTemp -> key.getAdvisorID(); //get the advisor's id for the student
      Faculty old_faculty(old_faculty_id);
      TreeNode<Faculty> *facTemp = new TreeNode<Faculty>(old_faculty);
      facTemp = facultyTree -> returnNode(old_faculty_id); //grab the node corresponding to the faculty id
      facTemp -> key.DeleteFromFacultyIDList(id); //delete the id from the faculty object
      StuTemp -> key.setAdvisorID(new_faculty_id); //setting student's advisor ID to the new faculty id
      Faculty new_faculty(new_faculty_id);
      TreeNode<Faculty> *newFacTemp = new TreeNode<Faculty>(new_faculty);
      newFacTemp = facultyTree -> returnNode(new_faculty_id); //grabbing node corresponding to the new faculty id
      newFacTemp -> key.AddToFacultyIDList(id); //inserting a student id into new faculty
    }
  }
  else //if students do not exist
  {
    cout << "No Students exist." << endl;
  }
}

void Simulation::Choice_12(BST<Student> *studentTree, BST<Faculty> *facultyTree) //removing an advisee from a faculty member given their ids
{
  int id = CheckFaculty(facultyTree); //their id number
  Faculty faculty(id);
  TreeNode<Faculty> *facTemp = new TreeNode<Faculty>(faculty);
  facTemp = facultyTree -> returnNode(id); //grabbing faculty node
  if (facTemp -> key.getStudentListSize() == 0)
  {
    cout << "Faculty does not have any advisees." << endl;
  }
  else
  {
    PushingToStacks(studentTree, studentStack, facultyTree, facultyStack); //pushing into stacks
    int stu_id = CheckStudent(studentTree); //student id number
    bool check_id = true;
    while (check_id) //checking if the inputted id is an advisee of the faculty
    {
      if (facTemp -> key.getContains(stu_id))
      {
        check_id = false;
      }
      else
      {
        cout << "Student is not an advisee of the faculty. Please enter a valid ID." << endl;
        stu_id = CheckStudent(studentTree);
      }
    }
    Student student(stu_id);
    TreeNode<Student> *stuTemp = new TreeNode<Student>(student);
    stuTemp = studentTree -> returnNode(stu_id); //grabbing student node
    facTemp -> key.DeleteFromFacultyIDList(stu_id); //deleting advisee from the faceulty
    TreeNode<Faculty> *newFac = new TreeNode<Faculty>();
    newFac = facultyTree -> getRandomNode(); //grabbing a random node from the faculty tree
    while (true) //checking to see if the random node is not the faculty that we just deleted the advisee from
    {
      if (newFac != facTemp)
      {
        break;
      }
      newFac = facultyTree -> getRandomNode();
    }
    stuTemp -> key.setAdvisorID(newFac -> key.getID()); //set the student advisor id to the new faculty member
    newFac -> key.AddToFacultyIDList(stu_id); //insert student into the new faculty member advisees
  }
}

void Simulation::Choice_13(BST<Student>* &studentTree, BST<Faculty>* &facultyTree) //undoing operation
{
  if (studentStack -> isEmpty())
  {
    cout << "No Command History." << endl;
  }
  else
  {
    string studentString = studentStack -> pop();
    string facultyString = facultyStack -> pop();
    if (studentString == "") //if the string is empty, do nothing
    {

    }
    else //if the string is not empty
    {
      BST<Student> *tempStudentTree = new BST<Student>();
      istringstream studentStringFile(studentString);
      string line;
      string data;
      while (getline(studentStringFile, line))
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
        tempStudentTree -> insert(student); //inserting student object into tree
      }
      studentTree = tempStudentTree;
    }
    if (facultyString == "") //do nothing
    {

    }
    else
    {
      BST<Faculty> *tempFacultyTree = new BST<Faculty>();
      istringstream facultyStringFile(facultyString);
      string line;
      string data;
      while (getline(facultyStringFile, line))
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
          tempFacultyTree -> insert(faculty); //insert object into tree
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
          tempFacultyTree -> insert(faculty); //insert
        }
      }
      facultyTree = tempFacultyTree;
    }
  }
}

string Simulation::StudentStringSerialize(BST<Student> *studentTree)
{
  stringstream studentString;
  SupportStudentStringSerialize(studentString, studentTree, studentTree -> getRoot());
  return studentString.str();
}

void Simulation::SupportStudentStringSerialize(stringstream &studentString, BST<Student> *studentTree, TreeNode<Student> *node)
{
  if (node == NULL)
  {
    return;
  }
  SupportStudentStringSerialize(studentString, studentTree, node -> left);
  studentString << node -> key; //write node to studentstring
  SupportStudentStringSerialize(studentString, studentTree, node -> right);
}

string Simulation::FacultyStringSerialize(BST<Faculty> *facultyTree)
{
  stringstream facultyString;
  SupportFacultyStringSerialize(facultyString, facultyTree, facultyTree -> getRoot());
  return facultyString.str();
}

void Simulation::SupportFacultyStringSerialize(stringstream &facultyString, BST<Faculty> *facultyTree, TreeNode<Faculty> *node)
{
  if (node == NULL)
  {
    return;
  }
  SupportFacultyStringSerialize(facultyString, facultyTree, node -> left);
  facultyString << node -> key; //write node to faculty string
  SupportFacultyStringSerialize(facultyString, facultyTree, node -> right);
}

void Simulation::PushingToStacks(BST<Student> *studentTree, GenStack<string> *studentStack, BST<Faculty> *facultyTree, GenStack<string> *facultyStack)
{
  string oldStudentTree = "";
  oldStudentTree = StudentStringSerialize(studentTree);
  studentStack -> push(oldStudentTree);
  string oldFacultyTree = "";
  oldFacultyTree = FacultyStringSerialize(facultyTree);
  facultyStack -> push(oldFacultyTree);
}





void Simulation::Choice_14()
{
  //do nothing because int choice is already 14 and the loop will exit
}
