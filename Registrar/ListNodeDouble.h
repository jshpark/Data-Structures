#ifndef LISTNODEDOUBLE_
#define LISTNODEDOUBLE_

#include <iostream>

using namespace std;

template <class T>
class ListNodeDouble
{
public:
  ListNodeDouble();
  ListNodeDouble(T d);
  ~ListNodeDouble();

  ListNodeDouble* next;
  ListNodeDouble* prev;
  T data;
};

template <class T>
ListNodeDouble<T>::ListNodeDouble()
{
  data = NULL;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNodeDouble<T>::ListNodeDouble(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNodeDouble<T>::~ListNodeDouble()
{
  next = NULL;
  prev = NULL;
  delete next;
  delete prev;
}
#endif
