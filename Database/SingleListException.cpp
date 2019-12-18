#include <iostream>
#include "SingleListException.h"

using namespace std;

SingleListExcepion::SingleListExcepion()
{

}

SingleListExcepion::SingleListExcepion(string d)
{
  error = d;
}

SingleListExcepion::~SingleListExcepion()
{

}

string SingleListExcepion::getError()
{
  return error;
}
