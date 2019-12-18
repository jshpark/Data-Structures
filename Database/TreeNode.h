#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;

template <class type>
class TreeNode
{
public:
  TreeNode() //default constructor
  {
    left =  NULL;
    right = NULL;
  }
  TreeNode(type k) //overloaded constructor
  {
    key = k;
    left = NULL;
    right = NULL;
  }
  ~TreeNode() //destructor
  {
    left = NULL;
    right = NULL;
    delete left;
    delete right;
  }


  type key; //data inside the node
  TreeNode<type>* left; //left node
  TreeNode<type>* right; //right node
};

#endif
