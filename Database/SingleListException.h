#ifndef SINGLELISTEXCEPTION_H
#define SINGLELISTEXCEPTION_H

#include <iostream>
#include <string>

using namespace std;

class SingleListExcepion
{
public:
  SingleListExcepion();
  SingleListExcepion(string d);
  ~SingleListExcepion();
  string getError();
private:
  string error;
};
#endif
