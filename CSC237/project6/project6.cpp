/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     December 9, 2023                          */
/*   Due Date:          December 12, 2023                         */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #6                                        */
/*   Filename:          project6.cpp                              */
/*   Purpose:           This file reads a file of words and calls */
/*                      a function to put them into a hash table  */
/*                      it also checks spelling and provides      */
/*                      posssible corrections for mispelled words */
/******************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include "QuadraticProbing.h"
using namespace std;

int main()
{
  HashTable<string> table; //create an int hash table
  
  ifstream fp; //file variable
  string word, oneLess, oneMore, newWord; //variables to store the mutated strings
  int max = 100; //max size of the array
  string array[max] = {}; //array to store possible corrections
  bool duplicate = false; //check for duplicates
  int index = 0; //current index of the array
  
  
  cout << "Initializing the hash table ... " << endl;
  fp.open("words.dat"); // open the file
  
  if(!fp)
    {
      cout << "Error" << endl;
      return 0;
    }
  
  //insert the files words into the table
  while (fp >> word) 
    table.insert(word);
  
  fp.close(); //close the file
  
  table.OutputLoadFactor(); //calls funstion to output the load factor
  
  table.OutputCollisionTotal(); // calls a function to output the number of collisions
  
  while(word != "done") //spell check loop
    {
      cout << "Enter a word for spell checking (enter done to exit): ";
      cin >> word;
      for (int i = 0; i < max; ++i) //reset the array of words back i=to blank after each loop
	{
	  array[i] = "";
	}
      index = 0; //reset the index
      if(word == "done")
	break;
      if(table.contains(word) == true)
	cout << "Correct!" << endl;
      else
	{
	  cout << "Wrong! Possible corrections: ";
	  for(int i = 0; i < word.length(); i++)
	    {
	      duplicate = false; //no duplicates
	      oneMore = word;
	      oneMore.erase(i, 1); //delete the ith letter from the string
	      for(int j = 0; j < index; j++) //loop to check if the word is in the array
		{
		  if(array[j] == oneMore) //if the word is in the array, break
		    {
		      duplicate = true;
		      break;
		    }
		}
	      if(duplicate != true && table.contains(oneMore) == true) //if its a new word, add to the array
		{
		  array[index] = oneMore;
		  index++;
		}
	      duplicate = false; //reset back to false
	      for(char ch = 'a'; ch <= 'z'; ch++) 
		{
		  newWord = word;
		  oneLess = word;
		  newWord[i] = ch; //change the ith character to the value of ch
		  oneLess.insert(i, 1, ch); //insert an extra character at position i
		  for(int j = 0; j < index; j++)
		    {
		      if(array[j] == newWord)  //loop to check if the word is in the array
			{
			  duplicate = true; //if the word is in the array, break
			  break;
			}
		    }
		  if(duplicate != true && table.contains(newWord) == true) //if its a new word, add to the array
		    {
		      array[index] = newWord;
		      index++;
		    }
		  duplicate = false; //reset back to false
		  for(int j = 0; j < index; j++) //loop to check if the word is in the array
		    {
		      if(array[j] == oneLess) //if the word is in the array, break
			{
			  duplicate = true;
			  break;
			}
		    }
		  if(duplicate != true && table.contains(oneLess) == true) //if its a new word, add to the array
		    {
		      array[index] = oneLess;
		      index++;
		    }
		}
	    }
	  for(int j = 0; j < index; j++) //output the entire array
	    {
	      cout << array[j] << " ";
	    }
	  cout << endl;
	}
    }
  cout << "Bye." << endl;
  return 0;
}
