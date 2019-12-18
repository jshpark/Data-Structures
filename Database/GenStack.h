#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>

using namespace std;

template <class T>
class GenStack
{
public:
  GenStack() //default constructor
  {
    myArray = new T[10];
    size = 10;
    top = -1;
  }

  GenStack(int maxSize) //overloaded constructor
  {
    myArray = new T[maxSize];
    size = maxSize;
    top = -1;
  }

  ~GenStack()
  {
    //what do i need to do here?
    delete[] myArray;
  }

  void push(T d)
  {
    if (isFull()) //if the array is full, create a new array and resize it
    {
      for (int i = 0; i < size; ++i)
      {
        myArray[i] = myArray[i + 1];
      }
      myArray[top] = d;
    }
    myArray[++top] = d;
  }

  T pop()
  {
    //error checks
    //check if IsEmpty
    if (isEmpty())
    {

    }
    else
    {
      return myArray[top--];
    }
  }

  T peek()
  {
    if (top == -1)
    {
      cout << "Stack is Empty." << endl;
    }
    return myArray[top];
  }

  bool isFull()
  {
    return (top == size - 1);
  }
  bool isEmpty()
  {
    return (top == -1);

  }

  int getSize()
  {
    return size;
  }

private:
  int size;
  int top;

  T* myArray;
};

#endif
