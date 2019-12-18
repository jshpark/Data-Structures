#ifndef MIRRORBOARD_H
#define MIRRORBOARD_H

#include "Board.h"
#include <iostream>

using namespace std;

class MirrorBoard : public Board
{
  //inheiting from Board (constructors/destructors)
public:
    MirrorBoard();
    int CellDetermine() override;
};

#endif
