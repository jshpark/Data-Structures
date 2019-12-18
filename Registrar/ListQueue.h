#ifndef LISTQUEUE_
#define LISTQUEUE_

#include "DoublyList.h"
#include "QueueException.h"
#include <iostream>

using namespace std;

template <class Type>
class ListQueue
{
public:
  ListQueue();
  ~ListQueue();

  void enqueue(Type d);
  Type dequeue();
  Type peek();
  bool isEmpty();
  int getSize();

private:
  DoublyList<Type>* myQueue;
  unsigned int size;
};

template <class Type>
ListQueue<Type>::ListQueue()
{
  myQueue = new DoublyList<Type>();
  size = 0;
}

template <class Type>
ListQueue<Type>::~ListQueue()
{
  while (!isEmpty())
  {
    dequeue();
  }
  delete myQueue;
}

template <class Type>
void ListQueue<Type>::enqueue(Type d)
{
  myQueue -> insertBack(d);
  size++;
}

template <class Type>
Type ListQueue<Type>::dequeue()
{
  if (size == 0)
  {
    //empty
    // cout << "HI" << endl;
    // return false; //throw an exception
    throw QueueException("Queue is empty.");
  }
  size--;
  return myQueue -> deleteFront();
}

template <class Type>
Type ListQueue<Type>::peek()
{
  Type dataTemp = myQueue -> deleteFront();
  myQueue -> insertFront(dataTemp);
  return dataTemp;
}

template <class Type>
bool ListQueue<Type>::isEmpty()
{
  return (size == 0);
}

template <class Type>
int ListQueue<Type>::getSize()
{
  return size;
}
#endif
