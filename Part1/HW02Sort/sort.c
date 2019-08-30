// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}

// logical error fixed. 
// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{ 
  int swap = 0; 
  int temp_min = 0; 
  int record = 0; 
  for (int count_2 = 0; count_2 < size; count_2 ++) 
  {
    
    //the numbers before count_2 have been sorted. 
    temp_min = arr [count_2];
    record = count_2; 
    for ( int count_1 = count_2; count_1 < size; count_1 ++)
    //initial the miminal value to the first element after the sorted element. 
    //if count_1 is less than size, continue sorting.
    //this for body is to find the minimum in the remaining part of the arrey. 
    { 
     if (temp_min >  arr [count_1]) 
                 /*compare the value of temp_min and the element*/
      { 
       temp_min = arr [count_1];
       record = count_1;         
                 /* record the minimum's position in the array. */
      }
    }
     swap = arr [count_2];
     arr [count_2] = arr [record];
     arr [record] = swap; 
    //switch the position between the first element and the minimum
    // in part of array unsorted. 
   
  //check if the array is in the right order. 
  }
    
  // This function has two levels of for
  // The first level specifies which element in the array
  // The second level finds the smallest element among the unsorted
  // elements

  // This is the syntax to read or write an array element:
  // int x = arr[4];
  // read the value of arr[4] and store it in x
  // arr[4] = 5;
  // stores 5 in the element arr[4]
  // Please remember that indexes start from 0.

  // After finding the smallest element among the unsorted elements,
  // swap it with the element of the index from the first level
}

#endif
