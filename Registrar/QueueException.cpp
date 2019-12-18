#include <iostream>
#include "QueueException.h"

using namespace std;

QueueException::QueueException()
{

}

QueueException::QueueException(string d)
{
  error = d;
}

QueueException::~QueueException()
{

}

string QueueException::getError()
{
  return error;
}
