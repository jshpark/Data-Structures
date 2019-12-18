#ifndef CLASSICBOARD_H
#define CLASSICBOARD_H

#include "Board.h"
#include <iostream>

using namespace std;

class ClassicBoard : public Board
{
  //inheriting base constructors/destructors
  public:
    ClassicBoard(); //EMPTY CONSTRUCTOR
    int CellDetermine() override;
};

#endif
