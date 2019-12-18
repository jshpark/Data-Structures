#ifndef STUDENT_
#define STUDENT_

#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int d);
  Student(int d, int x);
  ~Student();
  void SetWaitTime(int d);
  int GetWaitTime();
  void SetRequiredTime(int d);
  int GetRequiredTime();
private:
  unsigned int waittime;
  unsigned int requiredtime;
};
#endif
