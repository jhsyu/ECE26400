// ***
// *** You MUST modify this file
// ***


//This is the calrifcation for the testcases.
//In the testcase1, n = 6, k = 3, the last element printed
//is the element who gets the cake.
//the output1 should be 2 5 3 1 4 0


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h>


//because the number they count will never less than 1,
//define 0 as the people leave in this trun,
//define -1 as the people leave in the last turn.
int const X = 0; 
int const Y = -1; 

//this function return a number showing how many people are still alive.
int check_remain(int* arr, int size);    
{
  int remain = size;
  int dead = 0;   //count the dead people.
  for (int ind = 0; ind < size, ind ++)
    {
      if (arr[ind] == X || arr[ind] == Y)
	dead ++;
    }
  remain = remain - dead; 
  return remain;
}


#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements


  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked




  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
