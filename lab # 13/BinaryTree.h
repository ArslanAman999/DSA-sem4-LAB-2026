#pragma once
#include <iostream>

template <class T>
class BinaryTree
{
protected:
  Node<T> * root;
  void deleteTree();
  void copyTree(const BinaryTree *);
public:
  BinaryTree(){root = nullptr;}
  BinaryTree(const BinaryTree & bt) {copyTree(bt);}
  const BinaryTree & operator = (const BinaryTree & );
  virtual ~BinaryTree(){deleteTree();}
  virtual void insert(const T & value) = 0; 
  virtual void remove(const T & value) = 0;
  virtual bool search(const T & value) const = 0;   
  virtual bool isEmpty() const= 0; 
  void inorderDisplay() const= 0;
  void preorderDisplay() const= 0;
  void postorderDisplay() const= 0;
  int treeHeight() const;  //Returns the height of the binary tree.
  int treeNodeCount() const;   //Returns the number of nodes in the binary tree.
  int treeLeavesCount() const;  //Returns the number of leaves in the binary tree
};

