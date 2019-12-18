#include "MirrorBoard.h"
#include <iostream>

using namespace std;

MirrorBoard::MirrorBoard() : Board()
{
  //empty just need to create an object of this derived class
}

int MirrorBoard::CellDetermine()
{
  neighbors = 0;
  if ((rowLocation == 0)) //checks top row
  {
    if (columnLocation == 0) //checks top left corner
    {
      if (copyArray[0][0] == 'X')
      {
        neighbors =+ 3;
      }
      if (copyArray[0][1] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[1][0] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[1][1] == 'X')
      {
        neighbors++;
      }
    }
    return neighbors;
    if (columnLocation == (column - 1)) // checks top right corner
    {
      if (copyArray[0][columnLocation] == 'X')
      {
        neighbors += 3;
      }
      if (copyArray[0][columnLocation - 1] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[1][columnLocation] == 'X')              //HIGHEST PRIORITY CHECK TOP ROW!!!!!!!!!!!!!!!!!!!!!!!************8
      {
        neighbors += 2;
      }
      if (copyArray[1][columnLocation - 1] == 'X')
      {
        neighbors++;
      }
      return neighbors;
    }
    if ((columnLocation > 0) && !(columnLocation == (column - 1))) //checks entire top row except top left and top right corner
    {
      for (int i = (columnLocation - 1); i < (columnLocation + 2); ++i)
      {
        if (copyArray[1][i] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[0][columnLocation] == 'X')
      {
        neighbors++;
      }
      if (copyArray[0][columnLocation - 1] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[0][columnLocation + 1] == 'X')
      {
        neighbors += 2;
      }
      return neighbors;
    }
  }
  if (rowLocation == (row - 1)) //checking bottom row
  {
    if (columnLocation == 0) //checking bottom left corner
    {
      if (copyArray[rowLocation][0] == 'X')
      {
        neighbors += 3;
      }
      if (copyArray[rowLocation - 1][0] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[rowLocation][1] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[rowLocation - 1][1] == 'X')
      {
        neighbors++;
      }
      return neighbors;
    }
    if (columnLocation == (column - 1)) //checking bottom right corner
    {
      if (copyArray[rowLocation][columnLocation] == 'X')
      {
        neighbors += 3;
      }
      if (copyArray[rowLocation][columnLocation - 1] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[rowLocation - 1][columnLocation] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[rowLocation - 1][columnLocation - 1] == 'X')
      {
        neighbors++;
      }
      return neighbors;
    }
    if ((columnLocation > 0) && !(columnLocation == (column - 1))) //checks entire bottom row except bottom left and bottom right corner
    {
      for (int i = (columnLocation - 1); i < (columnLocation + 2); ++i)
      {
        if (copyArray[rowLocation - 1][i] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[rowLocation][columnLocation - 1] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[rowLocation][columnLocation] == 'X')
      {
        neighbors++;
      }
      if (copyArray[rowLocation][columnLocation + 1] == 'X')
      {
        neighbors += 2;
      }
      return neighbors;
    }
  }
  if (columnLocation == 0) //checking left side
  {
    if ((rowLocation > 0) && !(rowLocation == (row - 1))) //checks entire left side except top left and bottom left corner
    {
      for (int i = (rowLocation - 1); i < (rowLocation + 2); ++i)
      {
        if (copyArray[i][1] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[rowLocation - 1][0] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[rowLocation][0] == 'X')
      {
        neighbors++;
      }
      if (copyArray[rowLocation + 1][0] == 'X')
      {
        neighbors += 2;
      }
    }
    return neighbors;
  }
  if (columnLocation == (column - 1)) //checks entire right side except top right and bottom right corner
  {
    if ((rowLocation > 0) && !(rowLocation == (row - 1)))
    {
      for (int i = (rowLocation - 1); i < (rowLocation + 2); ++i)
      {
        if (copyArray[i][columnLocation] == 'X')
        {
          neighbors++;
        }
      }
      if (copyArray[rowLocation - 1][columnLocation] == 'X')
      {
        neighbors += 2;
      }
      if (copyArray[rowLocation][columnLocation] == 'X')
      {
        neighbors++;
      }
      if (copyArray[rowLocation + 1][columnLocation] == 'X')
      {
        neighbors += 2;
      }
    }
    return neighbors;
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
  }
}
