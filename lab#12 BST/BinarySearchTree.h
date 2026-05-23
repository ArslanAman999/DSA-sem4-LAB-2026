#pragma once
#include"BinaryTree.h"
template <class T>
class BinarySearchTree: public BinaryTree<T>
{
public:
  BinarySearchTree():BinaryTree<T>() {}
  BinarySearchTree(const BinarySearchTree & bt): BinaryTree<T>(bt){}
  const BinarySearchTree & operator = (const BinarySearchTree & );
  ~BinarySearchTree(){}

  void insert(const T & value)
  {
	  insert(this->root, value);
  }
  void remove(const T & value) 
  {
      remove(this->root, value);
  }
  bool search(const T & value) const
  {
      return search(this->root, value);
  }
  bool isEmpty() const
  {
      return this->root == nullptr;
  }

  Node<T>* findNode(const T& value)
  {
      Node<T>* current = this->root;

      while (current != nullptr)
      {
          if (current->data == value)
          {
              return current;
          }

          if (value < current->data)
          {
              current = current->left;
          }
          else
          {
              current = current->right;
          }
      }

      return nullptr;
  }
  /*void display() const;*/
 void inorderDisplay() const
  {
      inorderDisplay(this->root);
  }
  void preorderDisplay() const
  {
      preorderDisplay(this->root);
  }
  void postorderDisplay() const
  {
      postorderDisplay(this->root);
  }
  Node<T>* getRoot() const
  {
      return this->root;
  }

  void setRoot(Node<T>* node)
  {
      this->root = node;
  }
private:
	// helpers
    void insert(Node<T>*& node, const T& value)
    {
        if (node == nullptr)
        {
            node = new Node<T>(value);
            return;
        }

        if (value < node->data)
        {
            insert(node->left, value);
        }
        else if (value > node->data)
        {
            insert(node->right, value);
        }
    }
    bool search(Node<T>* node, const T& value) const
    {
        if (node == nullptr)
        {
            return false;
        }

        if (node->data == value)
        {
            return true;
        }

        if (value < node->data)
        {
            return search(node->left, value);
        }

        return search(node->right, value);
    }
    void inorderDisplay(Node<T>* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        inorderDisplay(node->left);

        cout << node->data << " ";

        inorderDisplay(node->right);
    }
    void preorderDisplay(Node<T>* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        cout << node->data << " ";

        preorderDisplay(node->left);

        preorderDisplay(node->right);
    }
    void postorderDisplay(Node<T>* node) const
    {
        if (node == nullptr)
        {
            return;
        }

        postorderDisplay(node->left);

        postorderDisplay(node->right);

        cout << node->data << " ";
    }
    void remove(Node<T>*& node, const T& value)
    {
        if (node == nullptr)
        {
            return;
        }

        if (value < node->data)
        {
            remove(node->left, value);
        }
        else if (value > node->data)
        {
            remove(node->right, value);
        }
        else
        {
            // Case 1: No children
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                node = nullptr;
            }

            // Case 2: One child
            else if (node->left == nullptr)
            {
                Node<T>* temp = node;

                node = node->right;

                delete temp;
            }
            else if (node->right == nullptr)
            {
                Node<T>* temp = node;

                node = node->left;

                delete temp;
            }

            // Case 3: Two children
            else
            {
                Node<T>* successor = node->right;

                while (successor->left != nullptr)
                {
                    successor = successor->left;
                }

                node->data = successor->data;

                remove(node->right, successor->data);
            }
        }
    }
};
