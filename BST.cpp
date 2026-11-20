#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>

#include "tnode.hpp"

template <typename T>
class BinarySearchTree {
 public:
  BinarySearchTree() = default;
  ~BinarySearchTree();

  BinarySearchTree(const BinarySearchTree& other);
  BinarySearchTree& operator=(const BinarySearchTree& other);

  void Insert(const T& value);

const T* Find(const T& target) const;
  const T* FindMin() const;
  const T* FindMax() const;
  int Height() const;
  std::vector<T> InorderTraversal() const;
  std::vector<T> PreorderTraversal() const;
  std::vector<T> PostorderTraversal() const;

 private:
  TNode<T>* root_ = nullptr;

  void Clear(TNode<T>* node);
  TNode<T>* CopyTree(TNode<T>* node, TNode<T>* parent) const;

int Height(TNode<T>* node) const;
  void Inorder(TNode<T>* node, std::vector<T>& result) const;
  void Preorder(TNode<T>* node, std::vector<T>& result) const;
  void Postorder(TNode<T>* node, std::vector<T>& result) const;
};

//deconstructor
template <typename T>
void BinarySearchTree<T>::Clear(TNode<T>* node) {
  if(node == nullptr) {
    return;
  }
  Clear(node->left);
  Clear(node->right);
  delete node;
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
  Clear(root_);
}

//copy constructor
template <typename T>
TNode<T>* BinarySearchTree<T>::CopyTree(TNode<T>* node, TNode<T>* parent) const {
  if(node == nullptr) {
    return nullptr;
  }
  TNode<T>* copy = new TNode<T>(node->value);
  copy->parent = parent;
  copy->left = CopyTree(node->left,copy);
  copy->right = CopyTree(node->right,copy);
  return copy;
  
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& other) {
  root_ = CopyTree(other.root_, nullptr);
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& other) {
  if(this == &other) {
    return *this;
  }
  Clear(root_);
  root_ = CopyTree(other.root_, nullptr);
  return *this;
}

//insert
template <typename T>
void BinarySearchTree<T>::Insert(const T& value) {
  TNode<T>* new_node = new TNode<T>(value);
  if (root_ == nullptr) {
    root_ = new_node;
    return;
  }
  TNode<T>* current = root_;
  TNode<T>* par = nullptr;
  while (current != nullptr) {
    par = current;
    if (value < current->value)
      current = current->left;
    else
      current = current->right;
  }
  new_node->parent = par;
  if (value < par->value)
    par->left = new_node;
  else
    par->right = new_node;
}

template <typename T>
const T* FindBST<T>::Find(const T& target) const {
  TNode<T>* current = root_;
  while (current != nullptr) {
    if(current->value == target) {
      return &current->value;
    } else if (current->value > target) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  return nullptr;
}

template <typename T>
const T* FindBST<T>::FindMin() const {
  if(root_ == nullptr) {
    return nullptr;
  }
  TNode<T>* current = root_;
  while (current->left != nullptr) {
    current = current->left;
  }
  return &current->value;
}

template <typename T>
const T* FindBST<T>::FindMax() const {
  if(root_ == nullptr) {
    return nullptr;
  }
  TNode<T>* current = root_;
  while(current->right != nullptr) {
    current = current->right;
  }
  return &current->value;
}

template <typename T>
int FindBST<T>::Height() const {
  return Height(root_);
}

template <typename T>
int FindBST<T>::Height(TNode<T>* node) const {
  if(node == nullptr) {
    return -1;
  }
  int left = Height(node->left);
  int right = Height(node->right);
  int diff = (left > right) ? left : right;
  return diff + 1;
}

template <typename T>
std::vector<T> FindBST<T>::InorderTraversal() const {
  std::vector<T> result;
  Inorder(root_, result);
  return result;
}

template <typename T>
void FindBST<T>::Inorder(TNode<T>* node, std::vector<T>& result) const {
  if(node == nullptr) {
    return;
  }
  Inorder(node->left, result);
  result.push_back(node->value);
  Inorder(node->right, result);
}

template <typename T>
std::vector<T> FindBST<T>::PreorderTraversal() const {
  std::vector<T> result;
  Preorder(root_, result);
  return result;
}

template <typename T>
void FindBST<T>::Preorder(TNode<T>* node, std::vector<T>& result) const {
  if(node == nullptr) {
    return;
  }
  result.push_back(node->value);
  Preorder(node->left, result);
  Preorder(node->right, result);
}

template <typename T>
std::vector<T> FindBST<T>::PostorderTraversal() const {
  std::vector<T> result;
  Postorder(root_, result);
  return result;
}

template <typename T>
void FindBST<T>::Postorder(TNode<T>* node, std::vector<T>& result) const {
  if(node == nullptr) {
    return;
  }
  Postorder(node->left, result);
  Postorder(node->right, result);
  result.push_back(node->value);
}



#endif
