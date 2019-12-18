#ifndef BST_H
#define BST_H

#include <iostream>
#include <random>
#include <ctime>
#include "TreeNode.h"
#include "SingleLinkedList.h"

using namespace std;

template <class type>
class BST
{
private:
  TreeNode<type>* root;
public:
  BST() //default constructor
  {
    root = NULL;
  }

  ~BST() //destructor
  {
    BSTDestructor(root);
  }

  void BSTDestructor(TreeNode<type> d) //inorder deletion
  {
    BSTDestructor(d -> left);
    delete d;
    BSTDestructor(d -> right);
  }

  bool isEmpty() //checks if the BST is empty
  {
    return (root == NULL); //if the root is NULL, then the tree is obviously empty
  }

  void insert(type value) //insert to the BST
  {
    TreeNode<type>* node = new TreeNode<type>(value);
    // cout << "test2" << endl;
    if (isEmpty()) //empty tree
    {
      root = node;
    }
    else //if not empty tree
    {
      TreeNode<type>* current = root;
      TreeNode<type>* parent; //empty treenode
      while (true)
      {
        parent = current;
        if (value < current -> key) //if the adding vaue is less than the current node, ten go left
        {
          current = current -> left;
          if (current == NULL)
          {
            parent -> left = node;
            break;
          }
        }
        else if (value > current -> key) //going to the right if the value is bigger than the current node
        {
          current = current -> right;
          if (current == NULL)
          {
            parent -> right = node;
            break;
          }
        }
        else //THIS CHECKS FOR DUPLICATES
        {
          cout << "Data already exists. Please try again." << endl;
          break;
        }
      }
    }
  }

  bool contains(type value) //checks if the data is inside the tree
  {
    if (isEmpty()) //tree is empty, so does not contain value
    {
      return false;
    }
    else
    {
      TreeNode<type> *current = root;
      while (true) //while loop to iterate through the tree
      {
        if (current == NULL) //if current node is null node, then the tree does not contain the value, so return false
        {
          return false;
        }
        if (current -> key == value) //if the current node key is the same as value, then return true
        {
          return true;
        }
        else if (value < current -> key) //if value is less than curent node, traverse to left
        {
          current = current -> left;
        }
        else //if value is greater than current node, traverse to right
        {
          current = current -> right;
        }
      }
    }
  }

  bool deleteNode(type value) //deleting a node from the tree
  {
    if (!contains(value))
    {
      cout << "Data does not exist. Cannot delete non-existent data. Try again." << endl;
      return false;
    }
    else
    {
      TreeNode<type> *current = root;
      TreeNode<type> *parent = root;
      bool isLeft = true; //this is to keep track if we go left or right of the tree
      while (value != current -> key) //need to find the node we need to delete
      {
        parent = current; //making parent stay one node back
        if (value < current -> key) //this means the value is less than the current node, so we need to travel left
        {
          current = current -> left;
          isLeft = true;
        }
        else //this means we need to travel right
        {
          current = current -> right;
          isLeft = false;
        }
      }
      //we found the node we are trying to delete

      //now we check if it is a leaf, because if it is, we can just delete it easily
      if ((current -> left == NULL) && (current -> right == NULL)) //this means the node is a leaf
      {
        if (current == root) //and if the node is the root, then the root is null, and now the tree is empty
        {
          root = NULL;
        }
        else if (isLeft) //if we are on the left side of the tree
        {
          parent -> left = NULL; //this makes the current node NULL by calling the left node of the parent node (which is the current node)
        }
        else //if we are on the right side of the tree
        {
          parent -> right = NULL;
        }
      }

      else if ((current -> right == NULL) && (current -> left != NULL)) // has no right child and has a left child
      {
        if (current == root) //if the current node is the root, then just make its only child (which is the left) the root
        {
          root = current -> left;
        }
        else if (isLeft) //if the current node is on the left side
        {
          parent -> left = current -> left; //then make the left child of the current node the child of the parent node
        }
        else //if the current node is on the right side
        {
          parent -> right = current -> left;
        }
      }
      else if ((current -> left == NULL) && (current -> right != NULL)) //has no left child and has a right child
      {
        if (current == root) //if the current node is the root
        {
          root = current -> right; //then make the right child the root
        }
        else if (isLeft) //if the current node is on the left side
        {
          parent -> left = current -> right;
        }
        else //if the current node is on the right side
        {
          parent -> right = current -> right;
        }
      }
      else //if the current node has two children
      {
        TreeNode<type>* successor = getSuccessor(current); //getting the successor

        if (current == root) //if current node is root
        {
          root = successor; //make root the successor
        }
        else if (isLeft) //if the current node is on the left side
        {
          parent -> left = successor; //make the left child of the parent node the successor
        }
        else //if the current node is on the right side
        {
          parent -> right = successor; //make the right child of the parent node the successor
        }
        successor -> left = current -> left; //the left child of the SUCCESSOR is going to be the current nodes left child
      }
      current -> right = NULL;
      current -> left = NULL;
      delete current;
      return true;
    }
  }

  TreeNode<type>* getSuccessor(TreeNode<type>* d) //getting the successor of the current node
  {
    TreeNode<type>* successor_parent = d;
    TreeNode<type>* successor = d;
    TreeNode<type>* current = d -> right;

    while (current != NULL)
    {
      successor_parent = successor;
      successor = current;
      current = current -> left;
    }

    if (successor != d -> right)
    {
      successor_parent -> left = successor -> right;
      successor -> right = d -> right;
    }
    return successor;
  }

  void PrintNode(type value) //print a node form the tree
  {
    TreeNode<type>* current = root;
    while (true)
    {
      if (current == NULL)
      {
        cout << "Data does not exist." << endl;
      }
      if (value == current -> key)
      {
        cout << current -> key << endl;;
        break;
      }
      else if (value < current -> key)
      {
        current = current -> left;
      }
      else
      {
        current = current -> right;
      }
    }
  }

  TreeNode<type>* returnNode(type value) //return a node from the tree
  {
    if (isEmpty())
    {
      return NULL;
    }
    else
    {
      TreeNode<type>* current = root;
      while (true)
      {
        if (current == NULL)
        {
          return NULL;
        }
        if (value == current -> key)
        {
          return current;
        }
        else if (value < current -> key)
        {
          current = current -> left;
        }
        else
        {
          current = current -> right;
        }
      }
    }
  }

  void printTree() //print the entire tree in order starting from the root
  {
    recPrint(root);
  }

  void recPrint(TreeNode<type>* node) //recursive method to print the tree in order
  {
    if (node == NULL)
    {
      return;
    }

    recPrint(node -> left); //this is to traverse the tree to the left
    cout << node -> key << endl; //if the traverse is all the way to the left, then print the key
    recPrint(node -> right); //after printing the left most node, move to the right
  }

  TreeNode<type>* getRoot()
  {
    return root;
  }

// type getRandomNode() //returning a random node
TreeNode<type>* getRandomNode()
  {
    SingleLinkedList<TreeNode<type>*> *nodeList = new SingleLinkedList<TreeNode<type>*>();
    RandomNode(nodeList, root);
    int x = GetSize();
    int randNum = rand() % x;
    return nodeList -> ReturnPosition(randNum);
  }

  void RandomNode(SingleLinkedList<TreeNode<type>*> *nodeList, TreeNode<type> *node) //inorder recursive method to get random node
  {
    if (node == NULL)
    {
      return;
    }
    RandomNode(nodeList, node -> left);
    nodeList -> InsertFront(node);
    RandomNode(nodeList, node -> right);
  }

int GetSize()
{
  int size = 0;
  GetSizeRecursion(size, root);
  return size;
}

void GetSizeRecursion(int &size, TreeNode<type>* node)
{
  if (node == NULL)
  {
    return;
  }
  GetSizeRecursion(size, node -> left);
  ;
  cout << "wtf" << endl;
  GetSizeRecursion(size, node -> right);
}


};
#endif
