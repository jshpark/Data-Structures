#ifndef DOUBLYLIST_
#define DOUBLYLIST_

#include "ListNodeDouble.h"
#include "QueueException.h"
#include <iostream>

using namespace std;

template <class M>
class DoublyList
{
public:
  DoublyList();
  ~DoublyList();

  void insertFront(M d);
  M deleteFront();
  void insertBack(M d);
  M deleteBack();

private:
  unsigned int size;
  ListNodeDouble<M>* head;
  ListNodeDouble<M>* tail;
};

template <class M>
DoublyList<M>::DoublyList()
{
  size = 0;
  head = NULL;
  tail = NULL;
}

template <class M>
DoublyList<M>::~DoublyList()
{
  while (!(size == 0))
  {
    deleteFront();
  }
}

template <class M>
void DoublyList<M>::insertFront(M d)
{
  ListNodeDouble<M>* node = new ListNodeDouble<M>(d);
  if (size == 0)
  {
    tail = node;
  }
  else
  {
    head -> prev = node;
    node -> next = head;
  }
  head = node;
  size++;
}

template <class M>
M DoublyList<M>::deleteFront()
{
  if (size == 0)
  {
    // cout << "Queue is empty" << endl;
    // return false; //return nothing
    throw QueueException("Queue is empty.");
  }
  ListNodeDouble<M>* temp = head;
  M dataTemp = temp -> data;
  if (size == 1)
  {
    tail = NULL;
  }
  else
  {
    head -> next -> prev = NULL;
  }
  head = head -> next;
  temp -> next = NULL;
  delete temp;
  size--;
  return dataTemp;
}

template <class M>
void DoublyList<M>::insertBack(M d)
{
  ListNodeDouble<M>* node = new ListNodeDouble<M>(d);
  if (size == 0)
  {
    head = node;
  }
  else
  {
    tail -> next = node;
    node -> prev = tail;
  }
  tail = node;
  size++;
}

template <class M>
M DoublyList<M>::deleteBack()
{
  if (size==0)
  {
    cout << "Queue is empty." << endl;
    return; //return nothing if empty
  }
  ListNodeDouble<M>* temp = tail;
  M dataTemp = tail -> data;
  if (size == 1)
  {
    head = NULL;
  }
  else
  {
    tail -> prev -> next = NULL;
  }
  tail = tail -> prev;
  temp -> prev = NULL;
  delete temp;
  size--;
  return dataTemp;
}

#endif
