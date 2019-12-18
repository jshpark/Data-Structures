#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>

using namespace std;

class Board
{
public:
  Board(); //going to be empty constructor
  void SetRandom(int x, int y, double d);
  void FileBoardCreate(int row, int column); //method to create an array for file given
  void FileBoardInit(int row_location, int column_location, char data); //method to initialize array
  ~Board(); //destructor
  void setRowLocation(int x); //to change row location in main function
  int getRowLocation();   //to get row location in main function
  void setColumnLocation(int y);  //to change column location in main function
  int getColumnLocation();  //to get column location in main funciton
  int getRow(); //to get numbers of row in main function
  int getColumn(); //to get numbres of columns in main functon
  int getXValue(); //to get total number of X in the array
  void getArray();  //prints out boardArray
  void getArray2(); //prints out copyArray
  void ArrayCopy();  //copies boardarray onto copy array
  void PrintToFile(ofstream& new_file, int gen);



  virtual int CellDetermine() = 0; //determine the number of neighbors in a cell
  int Lonely_Cell(); //cell empties if neighbors are 1 or less
  int Stable_Cell(); //cell remains if neighbors are 2
  int Perfect_Cell(); //cell grows/remains if neighbors are 3         //these methods will return 0 if performed, or -1 if not performed.
  int Crowding_Cell(); //cell dies if neighbors are 4+                //if all methods are not performed, then all will return -1.

  bool getBool(); //tests to see if two arrays are the same

protected:
  char** boardArray;
  char** copyArray;
  int row;
  int column;             //board information stuff
  double density;
  int neighbors;

  int rowLocation;
  int columnLocation;     //cell specifying location
};

#endif
