/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     November 25, 2023                         */
/*   Due Date:          November 27, 2023                         */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #5                                        */
/*   Filename:          BinarySearchTree.cpp                      */
/*   Purpose:           This file contains all of the function    */
/*                      definitions and is used to do different   */
/*                      things with a binary search tree          */
/******************************************************************/

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree()
{
  rootPtr = nullptr;
}

template <class ItemType>
BinarySearchTree<ItemType>::
BinarySearchTree(const ItemType& rootItem)
{
  //create a tree with a single tree node
  rootPtr = new treeNode<ItemType>;
  rootPtr -> item = rootItem;
  rootPtr -> left = nullptr;
  rootPtr -> right = nullptr;
}


template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
  return rootPtr == nullptr;
}  

template<class ItemType>
void BinarySearchTree<ItemType>::
add(const ItemType& newData)
{
  //create a new tree node containing newData
  treeNode<ItemType>* newNodePtr = new treeNode<ItemType>; 
  newNodePtr -> item = newData;
  newNodePtr -> left = nullptr;
  newNodePtr -> right = nullptr;
  
  //place the tree node in the tree
  rootPtr = placeNode(rootPtr, newNodePtr);
}

template<class ItemType>
treeNode<ItemType>* BinarySearchTree<ItemType>::
placeNode(treeNode<ItemType>* subTreePtr,
	  treeNode<ItemType>* newNodePtr)
{
  if (subTreePtr == nullptr)
    return newNodePtr;
  else
    {
      if (subTreePtr -> item > newNodePtr -> item)
	{
	  treeNode<ItemType>* tempPtr = placeNode(subTreePtr -> left, newNodePtr);
	  subTreePtr -> left = tempPtr;
	}
      else
	{
	  treeNode<ItemType>* tempPtr = placeNode(subTreePtr -> right, newNodePtr);
          subTreePtr -> right = tempPtr;
	}
      return subTreePtr;
    }
}

//////////////////TO DO///////////////////////////////
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
  return heightHelper(rootPtr); //returns the height
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const
{
  preorderHelper(rootPtr);
  cout << endl;
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const
{
  inorderHelper(rootPtr); 
  cout << endl;
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const
{
  postorderHelper(rootPtr);
  cout << endl;
}


template<class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& target) const
{
  if(rootPtr == nullptr)
    return false;
  else if(rootPtr -> item == target)
    return true;
  else if(target < rootPtr -> item) //if target < root -> item, search left side of the tree
    return searchHelper(target, rootPtr -> left);
  else //else search right side of tree
    return searchHelper(target, rootPtr -> right); 
}


template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree)
{
  rootPtr = copyTree(tree.rootPtr);
}

template<class ItemType>
void BinarySearchTree<ItemType>::remove(const ItemType& target)
{
  rootPtr = removeHelper(target, rootPtr);
}

//////////////////////////// Helper Functions ////////////////////////////////////
template<class ItemType>
int BinarySearchTree<ItemType>::heightHelper(treeNode<ItemType>* subPtr) const
{
  if(subPtr == nullptr)
    return 0;
  else
    return 1 + max(heightHelper(subPtr -> left), heightHelper(subPtr -> right)); //return the side that has the largest height
}

template<class ItemType>
void BinarySearchTree<ItemType>::preorderHelper(treeNode<ItemType>* subPtr) const
{
  if(subPtr != nullptr)
    {
      cout << subPtr -> item << " ";
      preorderHelper(subPtr -> left);
      preorderHelper(subPtr -> right);
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::inorderHelper(treeNode<ItemType>* subPtr) const
{
  if(subPtr != nullptr)
    {
      inorderHelper(subPtr -> left);
      cout << subPtr -> item << " ";
      inorderHelper(subPtr -> right);
    }
}

template<class ItemType>
void BinarySearchTree<ItemType>::postorderHelper(treeNode<ItemType>* subPtr) const
{
  if(subPtr != nullptr)
    {
      postorderHelper(subPtr -> left);
      postorderHelper(subPtr -> right);
      cout << subPtr -> item << " ";
    }
}

template<class ItemType>
bool BinarySearchTree<ItemType>::searchHelper(const ItemType& target, treeNode<ItemType>* subPtr) const
{
  if(subPtr == nullptr)
    return false;
  else if(subPtr -> item == target)
    return true;
  else if(target < subPtr -> item) //if target < subPtr -> item, search left side of the tree
    return searchHelper(target, subPtr -> left); 
  else //else search right side of tree
    return searchHelper(target, subPtr -> right); 
  return true;
}

template<class ItemType>
treeNode<ItemType>* BinarySearchTree<ItemType>::copyTree(const treeNode<ItemType>* oldPtr) const
{
  treeNode<ItemType>* newPtr = nullptr;
  if (oldPtr != nullptr)
    {
      newPtr = new treeNode<ItemType>;
      newPtr -> item = oldPtr -> item; //copy the item
      newPtr -> left = copyTree(oldPtr -> left); //call the function for the left node
      newPtr -> right = copyTree(oldPtr -> right); //call the function for the right node
    }
  return newPtr;
}

template<class ItemType>
treeNode<ItemType>* BinarySearchTree<ItemType>::removeHelper(const ItemType& target, treeNode<ItemType>* subPtr) const
{
  treeNode<ItemType>* tempPtr = nullptr;
  if(subPtr -> item == target) //if target is found
    subPtr = removeNode(subPtr); //call to remove the target
  else if(subPtr -> item > target) //if current item > target, search left side
    {
      tempPtr = removeHelper(target, subPtr -> left); 
      subPtr -> left = tempPtr; 
    }
  else //search the right side of the tree
    {
      tempPtr = removeHelper(target, subPtr -> right);
      subPtr -> right = tempPtr;
    }
  return subPtr;
}

template<class ItemType>
treeNode<ItemType>* BinarySearchTree<ItemType>::removeNode(treeNode<ItemType>* subPtr) const
{
  ItemType newNodeValue;
  treeNode<ItemType>* tempPtr = nullptr;
  if(subPtr -> left == nullptr && subPtr -> right == nullptr) //if node is a leaf
    {
      delete subPtr;
      subPtr = nullptr;
      return subPtr;
    }
  else if(subPtr -> left == nullptr || subPtr -> right == nullptr) //if node has 1 child
    {
      if(subPtr -> left == nullptr)
	tempPtr = subPtr -> right;
      else
	tempPtr = subPtr -> left;
      delete subPtr;
      subPtr = nullptr;
      return tempPtr;
    }
  else //if node has 2 children, search leftmost node of right subtree
    { 
      tempPtr = removeLeftMostNode(subPtr -> right, newNodeValue); 
      subPtr -> right = tempPtr;
      subPtr -> item = newNodeValue;
      return subPtr;
    }
}

template<class ItemType>
treeNode<ItemType>* BinarySearchTree<ItemType>::removeLeftMostNode(treeNode<ItemType>* subPtr, ItemType& newNodeValue) const
{
  ItemType newValue;
  treeNode<ItemType>* tempPtr = nullptr;
  if(subPtr -> left == nullptr) //if left child is null, current node is the leftmost
    {
      newNodeValue = subPtr -> item;
      return removeNode(subPtr);
    }
  else //continue searching for leftmost node
    {
      tempPtr = removeLeftMostNode(subPtr -> left, newNodeValue);
      subPtr -> left = tempPtr;
      return subPtr;
    }
}
