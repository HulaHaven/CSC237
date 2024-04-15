/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     September 14, 2023                        */
/*   Due Date:          September 20, 2023                        */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #1                                        */
/*   Filename:          linkedList.cpp                            */
/*   Purpose:           This file is the implementation file      */
/*                      to manipulate elements in a linked list   */
/******************************************************************/

template <class Type>
linkedListType<Type>::linkedListType() //default constructor
{
    first = nullptr;
    count = 0;
}


template <class Type>
linkedListType<Type>::~linkedListType() //destructor
{
  nodeType<Type> *temp;   //pointer to deallocate the memory
  //occupied by the node
  while (first != nullptr)   //while there are nodes in
    {                          //the list
      temp = first;        //set temp to the current node
      first = first->link; //advance first to the next node
      delete temp;   //deallocate the memory occupied by temp
    }
  count = 0;
}//end destructor


template <class Type>
bool linkedListType<Type>::isEmptyList() const
{
    return (first == nullptr);
}


template <class Type>
void linkedListType<Type>::print() const
{
    nodeType<Type> *current; //pointer to traverse the list

    current = first;    //set current so that it points to 
                        //the first node
    while (current != nullptr) //while more data to print
    {
      cout << current->info;
      current = current->link;
      if (current != nullptr)
	cout << " -> ";
    }
    cout << endl;
}//end print


template <class Type>
int linkedListType<Type>::length() const
{
    return count;
}  //end length


template <class Type>
void linkedListType<Type>::insertFront(const Type& newItem)
{
    nodeType<Type> *newNode; //pointer to create the new node

    newNode = new nodeType<Type>; //create the new node

    newNode->info = newItem;    //store the new item in the node
    newNode->link = first;      //insert newNode before first
    first = newNode;            //make first point to the
                                //actual first node
    count++;                    //increment count

}//end insertFront


/////////////////////TO DO///////////////////////

template <class Type>
bool linkedListType<Type>::contains(const Type& searchItem) const
{
  nodeType<Type> *temp = first;
  while(temp != nullptr)
    {
      if(temp -> info == searchItem)
	return true;
      temp = temp -> link;
    }
  return false;
}


template <class Type>
Type linkedListType<Type>::getElement(int position) const
{
  nodeType<Type> *temp = first;
  int counter = 1;
  while(temp != nullptr)
    {
      //check if the wanted position matches the current position in the loop
      if(counter == position)
	return temp -> info;
      counter++;
      temp = temp -> link;
    }
   return first -> info;
}

template <class Type>
int linkedListType<Type>::getPosition(Type element) const
{
  nodeType<Type> *temp = first;
  int counter = 1;
  while(temp != nullptr)
    {
      //check if the info at the position equals the element we want
      if(temp -> info == element)
	return counter;
      counter++;
      temp = temp -> link;
    }
  return -1;
}

template <class Type>
void linkedListType<Type>::replace(int position, Type element)
{
  nodeType<Type> *temp = first;
  int counter = 1;
  while(temp != nullptr)
    {
      //if positions match, replace with element
      if(counter == position)
	{
	  temp -> info = element;
	  break;
	}
      counter++;
      temp = temp -> link;
    }
}

template <class Type>
void linkedListType<Type>::remove(int position)
{
    nodeType<Type> *current = first -> link; //pointer to traverse the list
    nodeType<Type> *trailCurrent = first; //pointer just before current
    int counter = 2;

    while(current != nullptr)
      {
	//check if we are replacing the first node
	if(position == 1)
	  {
	    first = first -> link;
	    delete trailCurrent;
	    break;
	  }
	//delete the note when positon equals counter
	else if(position == counter)
	  {
	    trailCurrent -> link = current -> link;
	    delete current;
	    break;
	  }
	//iterate to next loop
	else
	  {
	    trailCurrent = trailCurrent -> link;
	    current = current -> link;
	    counter++;
	  }
      }
}










    
