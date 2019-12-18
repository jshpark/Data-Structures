#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
  waittime = 0;
  requiredtime = 0;
}

Student::Student(int d)
{
  requiredtime = d;
}

Student::Student(int d, int x)
{
  requiredtime = d;
  waittime = x;
}

Student::~Student()
{
  //empty
}

void Student::SetWaitTime(int d)
{
  waittime = d;
}

int Student::GetWaitTime()
{
  return waittime;
}

void Student::SetRequiredTime(int d)
{
  requiredtime = d;
}

int Student::GetRequiredTime()
{
  return requiredtime;
}
