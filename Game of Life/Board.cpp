#include "Board.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

Board::Board()
{
  //EMPTY CONSTRCUTOR. JUST NEED TO CREATE AN OBJECT AND NOTHING MORE WITH THIS CONSTRUCTOR.
}

void Board::SetRandom(int x, int y, double d)
{
  srand(time(NULL));
  double random_double;
  rowLocation = 0;
  columnLocation = 0;
  column = y;
  row = x;
  boardArray = new char* [row];
  copyArray = new char* [row];
  for (int i = 0; i < row; ++i)         //this section creates two arrays of sizes
  {
    boardArray[i] = new char[column];
    copyArray[i] = new char[column];
  }
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      do
      {
        random_double = ((double) rand() / (double) RAND_MAX);      //this section randomly assigns each cell an 'X' based on the density
        //cout << random_double << endl;
      } while(random_double == 0);
      if (random_double <= d)
      {
        copyArray[i][j] = 'X';
        boardArray[i][j] = 'X';
      }
      else
      {
        copyArray[i][j] = '-';
        boardArray[i][j] = '-';
      }
    }
  }
}

void Board::FileBoardCreate(int x, int y)
{
  rowLocation = 0;
  columnLocation = 0;
  row = x;
  column = y;
  boardArray = new char* [row];
  copyArray = new char* [row];
  for (int i = 0; i < row; ++i)
  {
    boardArray[i] = new char[column];
    copyArray[i] = new char[column];
  }
}

void Board::FileBoardInit(int row_location, int column_location, char data)
{
  copyArray[row_location][column_location] = data;
  boardArray[row_location][column_location] = data;
}

void Board::setRowLocation(int x)
{
  rowLocation = x;
}

int Board::getRowLocation()
{
  return rowLocation;
}

void Board::setColumnLocation(int y)
{
  columnLocation = y;
}

int Board::getColumnLocation()
{
  return columnLocation;
}

int Board::getRow()
{
  return row;
}

int Board::getColumn()
{
  return column;
}

Board::~Board() //destructor
{
  for (int i = 0; i < row; ++i)
  {
    delete [] boardArray[i];
    delete [] copyArray[i];
  }
  delete boardArray;
  delete copyArray;
  cout << "Game is done." << endl;
}

int Board::getXValue()
{
  int count = 0;
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      if (boardArray[i][j] == 'X')
      {
        count++;
      }
    }
  }
  return count;
}

void Board::getArray() //prints array
{
  cout << endl << endl;
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      cout << boardArray[i][j];
    }
    cout << endl;
  }
}

void Board::getArray2()
{
  cout << endl << endl;
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      cout << copyArray[i][j];
    }
    cout << endl;
  }
}

void Board::ArrayCopy()
{
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      copyArray[i][j] = boardArray[i][j];
    }
  }
}

void Board::PrintToFile(ofstream& new_file, int gen)
{
  new_file << endl << endl << "Generation: " << gen << endl;
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      new_file << boardArray[i][j];
    }
    new_file << endl;
  }
}

int Board::Lonely_Cell()
{
  if (neighbors <= 1)
  {
    if (boardArray[rowLocation][columnLocation] == '-')
    {
      return -1;
    }
    else
    {
      boardArray[rowLocation][columnLocation] = '-';
      return 0;
    }
  }
  else
  {
    return -1;
  }
}

int Board::Stable_Cell()
{
  if (neighbors == 2)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

int Board::Perfect_Cell()
{
  if (neighbors == 3)
  {
    if (boardArray[rowLocation][columnLocation] == 'X')
    {
      return -1;
    }
    else
    {
      boardArray[rowLocation][columnLocation] = 'X';
      return 0;
    }
  }
  else
  {
    return -1;
  }
}

int Board::Crowding_Cell()
{
  if (neighbors >= 4)
  {
    if (boardArray[rowLocation][columnLocation] == '-')
    {
      return -1;
    }
    else
    {
      boardArray[rowLocation][columnLocation] = '-';
      return 0;
    }
  }
  else
  {
    return -1;
  }
}

bool Board::getBool()
{
  bool array_board_bool;
  for (int i = 0; i < row; ++i)
  {
    for (int j = 0; j < column; ++j)
    {
      if (copyArray[i][j] == boardArray[i][j])
      {
        array_board_bool = true;
      }
      else
      {
        return false;
      }
    }
  }
  return array_board_bool;
}
