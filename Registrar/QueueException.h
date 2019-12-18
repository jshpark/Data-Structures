#ifndef QUEUEEXCEPTION_
#define QUEUEEXCEPTION_

#include <iostream>
#include <string>

using namespace std;

class QueueException
{
public:
  QueueException();
  QueueException(string d);
  ~QueueException();
  string getError();
private:
  string error;
};
#endif
