#ifndef DOUGHNUTBOARD_H
#define DOUGHNUTBOARD_H

#include "Board.h"
#include <iostream>

using namespace std;

class DoughnutBoard : public Board
{
  //inheriting from Board (constructors/destructors)
  public:
    DoughnutBoard(); //empty constructor. only needed to make an object of this type.
    int CellDetermine() override;
};

#endif
