#ifndef PERSON_H
#define PERSON_H

#include "BST.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template <class type>
class Person
{
public:
  virtual int getID() = 0;
  virtual string getName() = 0;
  virtual string getLevel() = 0;
  virtual ostream& serialize(ostream &out) = 0;
protected:
  unsigned int ID;
  string name;
  string level;
};

#endif
