/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     November 25, 2023                         */
/*   Due Date:          November 27, 2023                         */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #5                                        */
/*   Filename:          BinarySearchTree.h                        */
/*   Purpose:           This file contains the constructors,      */
/*                      functions, and helper functions           */
/*                      declarations                              */
/******************************************************************/

#ifndef H_BinarySearchTree
#define H_BinarySearchTree

#include <iostream>

using namespace std;

//Definition of the tree node
template <class ItemType>
struct treeNode
{
  ItemType item;
  treeNode<ItemType> *left;
  treeNode<ItemType> *right;
};

template <class ItemType>
class BinarySearchTree
{
public:

  //Default constructor, set root to nullptr
  BinarySearchTree();

  //constructor that takes a  rootItem 
  BinarySearchTree(const ItemType& rootItem);
  
  //check if the tree is empty
  bool isEmpty() const;
  
  //insert an item into the tree
  void add(const ItemType& newData);

  
  /////////////////TO DO///////////////////////////
  //1. get the height of the tree
  int getHeight() const;
  
  //2. tree treversal
  void preorderTraverse() const;
  void inorderTraverse() const;
  void postorderTraverse() const;
  
  //3. returns true if target is in the tree
  bool contains(const ItemType& target) const;
  
  
  //4. copy constructor
  BinarySearchTree(const BinarySearchTree<ItemType>& tree);
  
  //5. remove target from the tree
  //if target is not in the tree, do nothing
  void remove(const ItemType& target);
  
 private:
  treeNode<ItemType> * rootPtr; //pointer to the root of the tree
  
  //define your helper methods here
  treeNode<ItemType>* placeNode(treeNode<ItemType>* subTreePtr,
				treeNode<ItemType>* newNodePtr);
  //my helper functions
  int heightHelper(treeNode<ItemType>* subPtr) const; //getHeight helper function
  void preorderHelper(treeNode<ItemType>* subPtr) const; //preorderTraverse helper function
  void inorderHelper(treeNode<ItemType>* subPtr) const; //inorderTraverse helper function
  void postorderHelper(treeNode<ItemType>* subPtr) const; //postorderTraverse helper function
  bool searchHelper(const ItemType& target, treeNode<ItemType>* subPtr) const; //contains helper function
  treeNode<ItemType>* copyTree(const treeNode<ItemType>* oldPtr) const; //copy constructor helper function
  treeNode<ItemType>* removeHelper(const ItemType& target, treeNode<ItemType>* subPtr) const; //remove helper function
  treeNode<ItemType>* removeNode(treeNode<ItemType>* subPtr) const; //remove helper function
  treeNode<ItemType>* removeLeftMostNode(treeNode<ItemType>* subPtr, ItemType& newNodeValue) const; //remove helper function
  
};


#include "BinarySearchTree.cpp"

#endif
