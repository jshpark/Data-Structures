#include "DoughnutBoard.h"
#include <iostream>

using namespace std;

DoughnutBoard::DoughnutBoard() : Board()
{
  //empty constructor, needed to create object
}

int DoughnutBoard::CellDetermine()
{
  neighbors = 0;
  if ((rowLocation == 0)) // checks top row
  {
    if (columnLocation == 0) //checks top left corner
    {
      for (int i = 0; i < 2; ++i)
      {
        if (copyArray[i][1] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[1][0] == 'X')
      {
        neighbors++;
      }
      for (int i = 0; i < 2; ++i)
      {
        if (copyArray[row - 1][i] == 'X')
        {
          neighbors++;
        }
      }
      for (int i = 0; i < 2; ++i)
      {
        if (copyArray[i][column - 1] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[row - 1][column - 1] == 'X')
      {
        neighbors++;
      }
      return neighbors;
    }
    if (columnLocation == (column - 1)) // checks top rght corner
    {
      for (int i = 0; i < 2; ++i)
      {
        if (copyArray[i][columnLocation - 1] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[1][columnLocation] == 'X')
      {
        neighbors++;
      }
      for (int i = 0; i < 2; ++i)
      {
        if (copyArray[i][0] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[row - 1][0] == 'X')
      {
        neighbors++;
      }
      for (int i = columnLocation; i > (columnLocation - 2); --i)
      {
        if (copyArray[row - 1][i] == 'X')
        {
          neighbors++;
        }
      }
      return neighbors;
    }
    if ((columnLocation > 0) && !(columnLocation == (column - 1))) //checks entire top row except for top left and top right corner
    {
      for (int i = 0; i < 2; ++i)
      {
        if (copyArray[i][columnLocation - 1] == 'X')
        {
          neighbors++;
        }
      }
      for (int i = 0; i < 2; ++i)
      {
        if (copyArray[i][columnLocation + 1] == 'X')
        {
          neighbors++;
        }
      }
      for (int i = (columnLocation - 1); i < (columnLocation + 2); ++i)
      {
        if (copyArray[row - 1][i] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[1][columnLocation] == 'X')
      {
        neighbors++;
      }
      return neighbors;
    }
  }
  if (rowLocation == (row -1)) //checking bottom row
  {
    if (columnLocation == 0) // checking bottom left corner
    {
      for (int i = rowLocation; i > (rowLocation - 2); --i)
      {
        if (copyArray[i][1] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[rowLocation - 1][0] == 'X')
      {
        neighbors++;
      }
      for (int i = rowLocation; i > (rowLocation - 2); --i)
      {
        if (copyArray[i][column - 1] == 'X')
        {
          neighbors++;
        }
      }
      for (int i = 0; i > 2; ++i)
      {
        if (copyArray[0][i] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[0][column - 1] == 'X')
      {
        neighbors++;
      }
      return neighbors;
    }
    if (columnLocation == (column - 1)) //checking bottom right corner
    {
      for (int i = rowLocation; i > (rowLocation - 2); --i)
      {
        if (copyArray[i][columnLocation - 1] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[rowLocation - 1][columnLocation] == 'X')
      {
        neighbors++;
      }
      for (int i = rowLocation; i > (rowLocation - 2); --i)
      {
        if (copyArray[i][0] == 'X')
        {
          neighbors++;
        }
      }
      for (int i = columnLocation; i > (columnLocation - 2); --i)
      {
        if (copyArray[0][i] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[0][0] == 'X')
      {
        neighbors++;
      }
      return neighbors++;
    }
    if ((columnLocation > 0) && !(columnLocation == (column - 1))) //checks entire bottom row except bottom left and bottom right corner
    {
      for (int i = rowLocation; i > (rowLocation - 2); --i)
      {
        if (copyArray[i][columnLocation - 1] == 'X')
        {
          neighbors++;
        }
      }
      for (int i = rowLocation; i > (rowLocation -2); --i)
      {
        if (copyArray[i][columnLocation + 1] == 'X')
        {
          neighbors++;
        }
      }
      for (int i = (columnLocation - 1); i < (columnLocation + 2); ++i)
      {
        if (copyArray[0][i] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[rowLocation - 1][columnLocation] == 'X')
      {
        neighbors++;
      }
      return neighbors;
    }
  }
  if (columnLocation == 0)
  {
    if ((rowLocation > 0) && !(rowLocation == (row - 1))) //checking entire left side except top left and bottom left corner
    {
      for (int i = (rowLocation - 1); i < (rowLocation + 2); ++i)
      {
        if (copyArray[i][1] == 'X')
        {
          neighbors++;
        }
        if (copyArray[i][column - 1] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[rowLocation - 1][0] == 'X')
      {
        neighbors++;
      }
      if (copyArray[rowLocation + 1][0] == 'X')
      {
        neighbors++;
      }
    }
    return neighbors;
  }
  if (columnLocation == (column - 1)) // checking entire right side except top right and bottom right corner
  {
    if ((rowLocation > 0) && !(rowLocation == (row - 1)))
    {
      for (int i = (rowLocation - 1); i < (rowLocation + 2); ++i)
      {
        if (copyArray[i][columnLocation - 1] == 'X')
        {
          neighbors++;
        }
        if (copyArray[i][0] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[rowLocation - 1][columnLocation] == 'X')
      {
        neighbors++;
      }
      if (copyArray[rowLocation + 1][columnLocation] == 'X')
      {
        neighbors++;
      }
    }
    return neighbors;
  }
  if ((columnLocation == (column - 1)) &&(rowLocation == (row - 1))) //error if bottom right cell is calculated.
  {
    cout << "Error. Last cell already calculated." << endl;
  }

  if (!(columnLocation == 0) && !(rowLocation == 0) && !(columnLocation == (column - 1)) && !(rowLocation == (row - 1))) //checks the inside of the board
  {
    for (int i = (rowLocation - 1); i < (rowLocation + 2); ++i)
    {
      if (copyArray[i][columnLocation - 1] == 'X')
      {
        neighbors++;
      }
      if (copyArray[i][columnLocation + 1] == 'X')
      {
        neighbors++;
      }
    }
    if (copyArray[rowLocation - 1][columnLocation] == 'X')
    {
      neighbors++;
    }
    if (copyArray[rowLocation + 1][columnLocation] == 'X')
    {
      neighbors++;
    }
    return neighbors;
  }
}
