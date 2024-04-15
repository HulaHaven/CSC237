/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     September 14, 2023                        */
/*   Due Date:          September 20, 2023                        */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #1                                        */
/*   Filename:          stringTest.cpp                            */
/*   Purpose:           This file is the testing file for string  */
/*                      values on the template class              */
/******************************************************************/

#include <iostream>
#include "linkedList.h"
#include <string>

using namespace std;

int main()
{
  //create a string list                                                                  
  linkedListType<string> stringList;

  //create an empty list                                                                       
  linkedListType<string> stringList2;
  string str[8] = {"h", "g", "f", "e", "d", "c", "b", "a"};

  //insert some strings in stringList                                                      
  for (int i = 0; i < 8; i++)
    stringList.insertFront(str[i]);

  cout << "stringList: ";
  stringList.print();

  cout << endl;

  //testing contains()                                                                         
  cout << "Testing contains():\n";
  cout << "stringList contains a? " << boolalpha << stringList.contains("a")<< endl;
  cout << "stringList contains c? " << boolalpha << stringList.contains("c") << endl;
  cout << "stringList contains i? " << boolalpha << stringList.contains("i") << endl;
  cout << endl;

  //testing getElement()                                                                        
  cout << "Testing getElement():\n";
  cout << "get element at position 1: " << stringList.getElement(1) << endl;
  cout << "get element at position 5: " << stringList.getElement(5) << endl;
  cout << "get element position 8: " << stringList.getElement(8) << endl;

  //testing getPosition()
  cout << endl;
  cout << "Testing getPosition():\n";
  cout << "get position for h: " << stringList.getPosition("h") << endl;
  cout << "get position for c: " << stringList.getPosition("c") << endl;
  cout << "get position for a: " << stringList.getPosition("a") << endl;
  cout << "get position for t: " << stringList.getPosition("t") << endl;
  cout << "get position from empty list: " << stringList2.getPosition("t") << endl;

  cout << endl;

  //test replace()                                                                  
  cout << "Testing replace():\n";
  stringList.replace(1, "k");
  cout << "after replacing position 1 with k\n";
  stringList.print();

  stringList.replace(4, "n");
  cout << "after replacing position 4 with n\n";
  stringList.print();

  stringList.replace(8, "r");
  cout << "after replacing position 8 with r\n";
  stringList.print();

  //testing remove()                                                              
  cout << endl;
  cout << "Testing remove():\n";
  cout << "after removing element at position 1:\n";
  stringList.remove(1);
  stringList.print();

  cout << "after removing element at position 3:\n";
  stringList.remove(3);
  stringList.print();

  cout << "after removing element at position 6:\n";
  stringList.remove(6);
  stringList.print();

}
