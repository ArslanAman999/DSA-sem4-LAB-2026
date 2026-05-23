#pragma once
#include"Node.h"
template <class T>
class BinaryTree
{
protected:
  Node<T> * root;
  void deleteTree();
  void copyTree(const BinaryTree <T> *);
public:
  BinaryTree(){
      this->root = nullptr;
  }
  BinaryTree(const BinaryTree& bt)
  {
      root = nullptr;
      copyTree(root, bt.root);
  }

  const BinaryTree<T>& operator=(const BinaryTree<T>& bt)
  {
      if (this != &bt)
      {
          deleteTree(root);

          root = nullptr;

          copyTree(root, bt.root);
      }

      return *this;
  }

  virtual void insert(const T & value) = 0; 
  virtual void remove(const T & value) = 0;
  virtual bool search(const T & value) const = 0;   
  virtual bool isEmpty() const= 0; 
  virtual void inorderDisplay() const= 0;
  virtual void preorderDisplay() const= 0;
  virtual void postorderDisplay() const= 0;
  int treeHeight() const
  {
      return treeHeight(this->root);
  }

  int treeNodeCount() const
  {
      return treeNodeCount(this->root);
  }

  int treeLeavesCount() const
  {
      return treeLeavesCount(this->root);
  }

private:
    //helper
    void copyTree(Node<T>*& thisNode, Node<T>* otherNode)
    {
        if (otherNode == nullptr)
        {
            thisNode = nullptr;

            return;
        }

        thisNode = new Node<T>(otherNode->data);

        copyTree(thisNode->left, otherNode->left);

        copyTree(thisNode->right, otherNode->right);
    }

    void deleteTree(Node<T>*& node)
    {
        if (node == nullptr)
        {
            return;
        }

        deleteTree(node->left);

        deleteTree(node->right);

        delete node;

        node = nullptr;
    }

    int treeHeight(Node<T>* node) const
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = treeHeight(node->left);
        int rightHeight = treeHeight(node->right);

        if (leftHeight > rightHeight)
        {
            return leftHeight + 1;
        }

        return rightHeight + 1;
    }

    int treeNodeCount(Node<T>* node) const
    {
        if (node == nullptr)
        {
            return 0;
        }

        return 1 + treeNodeCount(node->left) + treeNodeCount(node->right);
    }

    int treeLeavesCount(Node<T>* node) const
    {
        if (node == nullptr)
        {
            return 0;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            return 1;
        }

        return treeLeavesCount(node->left) + treeLeavesCount(node->right);
    }

};

