/******************************************************************/
/*   Author:            Skyler Romanuski                          */
/*   Major:             Computer Science                          */
/*   Creation Date:     November 9, 2023                          */
/*   Due Date:          November 13, 2023                         */
/*   Course:            CSC_237_010                               */
/*   Professor Name:    Dr. Yong Zhang                            */
/*   Assignment:        #4                                        */
/*   Filename:          main.cpp                                  */
/*   Purpose:           This file calls the different sorting     */
/*                      method functions to count how many        */
/*                      comparisons are made with each            */
/******************************************************************/

/**
 * @file sort_benchmark.cpp
 * @brief compare basic sorting algorithms
 */
#include <iostream>
#include <stdlib.h>
#include <iomanip>

#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"

using namespace std;

int* makeRandomArray(int n, int seed);
void printArray(int* a, int size);


int main() {
  // use 9000 as the random seed
  const int seed = 9000;
  
  // Example of running the sort algorithms with the random array.
  // TODO Remove or comment out this code before submission.
  
  //int n = 100;
  int* a;
  int bubble[4] = {0}; //array to store bubblesort values
  int selection[4] = {0}; //array to store selectionsort values
  int insertion[4] = {0}; //array to store insertionsort values
  int merge[4] = {0}; //array to store mergesort values
  int quick[4] = {0}; //array to store quicksort values
  int SIZE[] = {10, 100, 1000, 10000}; //array to store the different testing sizes
  //int A, B, C, D, E;
  
  /*
    std::cout << "Bubble sort" << std::endl;
    a = makeRandomArray(100, seed);
    //printArray(a, n);
    A = bubblesort(a, n);
    //printArray(a, n);
    delete[] a;
    
    std::cout << "Selection sort" << std::endl;
    a = makeRandomArray(100, seed);
    //printArray(a, n);
    B = selectionsort(a, n);
    //printArray(a, n);
    delete[] a;
    
    std::cout << "Insertion sort" << std::endl;
    a = makeRandomArray(100, seed);
    //printArray(a, n);
    C = insertionsort(a, n);
    //printArray(a, n);
    delete[] a;

    std::cout << "Merge sort" << std::endl;
    a = makeRandomArray(100, seed);
    //printArray(a, n);
    D = mergesort(a, 0, n-1);
    //printArray(a, n);
    delete[] a;

    std::cout << "Quick sort" << std::endl;
    a = makeRandomArray(100, seed);
    //printArray(a, n);
    E = quicksort(a, 0, n-1);
    //printArray(a, n);
    delete[] a;
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    cout << D << endl;
    cout << E << endl;
    */
    //Store Values in Arrays
  
    //for loop to add all the values to the designated arrays
  for(int i = 0; i < 4; i++)
    {
      a = makeRandomArray(SIZE[i], seed);
      bubble[i] = bubblesort(a, SIZE[i]);
      delete[] a;
      
      a = makeRandomArray(SIZE[i], seed);
      selection[i] = selectionsort(a, SIZE[i]);
      delete[] a;
      
      a = makeRandomArray(SIZE[i], seed);
      insertion[i] = insertionsort(a, SIZE[i]);
      delete[] a;
      
      a = makeRandomArray(SIZE[i], seed);
      merge[i] = mergesort(a, 0, SIZE[i]-1);
      merge[i] = merge[i] - merge[i - 1] - merge[i - 2] - merge[i - 3] ; //remove previous entries since it adds past values to current ones
      delete[] a;
      
      a = makeRandomArray(SIZE[i], seed);
      quick[i] = quicksort(a, 0, SIZE[i]-1);
      //remove previous entries since it adds past values to current ones
      if(i == 1)
	quick[i] = quick[i] - quick[i - 1];
      else if(i == 2)
	quick[i] = quick[i] - quick[i - 1] - quick[i - 2];
      else if(i == 3)
	quick[i] = quick[i] - quick[i - 1] - quick[i - 2] - quick[i - 3];
      else
	quick[i] = quick[i];
      delete[] a;
    }
  
  //Make the final output table
  
  cout << setw(16) << "|" << setw(10) << SIZE[0] << setw(2) << "|" << setw(10) << SIZE[1] << setw(2) 
       << "|" << setw(10) << SIZE[2] << setw(2) << "|" << setw(10) << SIZE[3] << setw(2) << "|" << endl;
  cout << setfill('-') << setw(16) << "+" << setw(12) << "+" << setw(12) << "+" << setw(12) << "+" << setw(12) << "+" << setfill(' ') << endl;
  cout << "Selection Sort" << setw(2) << "|" << setw(10) << selection[0] << setw(2) << "|" << setw(10) << selection[1] << setw(2) 
       << "|" << setw(10) << selection[2] << setw(2) << "|" << setw(10) << selection[3] << setw(2) << "|" << endl;
  cout << "Bubble Sort" << setw(5) << "|" << setw(10) << bubble[0] << setw(2) << "|" << setw(10) << bubble[1] << setw(2) 
       << "|" << setw(10) << bubble[2] << setw(2) << "|" << setw(10) << bubble[3] << setw(2) << "|" << endl;
  cout << "Insertion Sort" << setw(2) << "|" << setw(10) << insertion[0] << setw(2) << "|" << setw(10) << insertion[1] << setw(2) 
       << "|" << setw(10) << insertion[2] << setw(2) << "|" << setw(10) << insertion[3] << setw(2) << "|" << endl;
  cout << "Merge Sort" << setw(6) << "|" << setw(10) << merge[0] << setw(2) << "|" << setw(10) << merge[1] << setw(2) 
       << "|" << setw(10) << merge[2] << setw(2) << "|" << setw(10) << merge[3] << setw(2) << "|" << endl;
  cout << "Quick Sort" << setw(6) << "|" << setw(10) << quick[0] << setw(2) << "|" << setw(10) << quick[1] << setw(2) 
       << "|" << setw(10) << quick[2] << setw(2) << "|" << setw(10) << quick[3] << setw(2) << "|" << endl;
  
  
  return 0;
}


/**
 * Generate an array of random integers
 * @param n the size of the array
 * @param seed the seed for the random number generator
 * @return a pointer to a new array
 * @note the client is responsible for deleting the array with delete[]
 */
int* makeRandomArray(int n, int seed) {
  srand(seed);
  int * a = new int[n];
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 1000;
  }
  return a;
}



void printArray(int* a, int size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::string sep = (i == size-1) ? " " : ", ";
        std::cout << a[i] << sep;
    }
    std::cout << "]" << std::endl;
}
