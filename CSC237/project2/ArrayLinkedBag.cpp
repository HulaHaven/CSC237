/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     September 30, 2023                        */
/*   Due Date:          October 2, 2023                           */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #2                                        */
/*   Filename:          ArrayLinkedBag.cpp                        */
/*   Purpose:           This file is the implementation file      */
/*                      to test the adding, removing, etc. of     */
/*                      elements in an Array Linked Bag           */
/******************************************************************/
/** Implementation file for the class ArrayLinkedBag.
  @file ArrayLinkedBag.cpp */

#include "ArrayLinkedBag.h"
#include <cstddef>

template<class ItemType>
ArrayLinkedBag<ItemType>::ArrayLinkedBag()
{
  head = 0;
  free = 0;
  itemCount = 0;
  maxItems = DEFAULT_CAPACITY;
}

template<class ItemType>
int ArrayLinkedBag<ItemType>::getCurrentSize() const
{
  return itemCount;
}

template<class ItemType>
bool ArrayLinkedBag<ItemType>::isEmpty() const
{
  if(itemCount == 0)
    return true;
  else
    return false;
}

template<class ItemType>
bool ArrayLinkedBag<ItemType>::add(const ItemType& newEntry)
{
  if(itemCount == DEFAULT_CAPACITY)
    return false;
  else
    {
      for(int i = 0; i < maxItems; i++)
	{
	  if(cells[i].item == "")
	    {
	      cells[i].item = newEntry;
	      cells[i].next = head;
	      head = i;
	      itemCount++;
	      return true;
	    }
	}
    }
  return false;
}

template<class ItemType>
bool ArrayLinkedBag<ItemType>::remove(const ItemType& anEntry)
{
  //keeps track of the index and sets the position to an empty string
  int index = -1;
  for(int i = 0; i < maxItems; i++)
    {
      if(cells[i].item == anEntry)
	index = i;
    }
  if(index != -1)
    {
      cells[index].item = "";
      itemCount--;
      return true;
    }
  return false;
}

template<class ItemType>
void ArrayLinkedBag<ItemType>::clear()
{
  for(int i = maxItems - 1; i >= 0; i--)
    {
      cells[i].item = "";
    }
  itemCount = 0;
}

template<class ItemType>
int ArrayLinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
  int count = 0;
  for(int i = 0; i < maxItems; i++)
    {
      if(cells[i].item == anEntry)
	{
	  count++;
	}
    }
  return count;
}

template<class ItemType>
bool ArrayLinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
  for(int i = 0; i < maxItems; i++)
    {
      if(cells[i].item == anEntry)
	{
	  return true;
	}
    }
  return false;
}

template<class ItemType>
std::vector<ItemType> ArrayLinkedBag<ItemType>::toVector() const
{
  std::vector<ItemType> bagContents;
  for(int i = maxItems - 1; i >= 0; i--)
    {
      bagContents.push_back(cells[i].item);
    }
  return bagContents;

}

