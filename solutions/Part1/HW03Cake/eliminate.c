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
int check_remain(int* arr, int size)
{
  int remain = size;
  int dead = 0;   //count the dead people.
  for (int ind = 0; ind < size; ind ++)
    {
      if (arr[ind] == X || arr[ind] == Y)
	dead ++;
    }
  remain = remain - dead;
  return remain;
}


#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)    /* n people, n is the size of the array. */
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
  for (int i = 0; i < n; i ++)
    {
      arr[i] = i + 1;
    }


  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked
  int remain = n;
  int count = 1;

  while (remain > 1) {
    for (int i = 0; i < n; i++) {
      //case 1: if one has been marked as X or Y, he has been died, do nothing.
      if ((arr[i] == X) || (arr[i] == Y)) {

      }
      //case 2: if one's count equal to k, he dies, print his number, marked as X.
      else if (count == k) {
        arr[i] = X;
        printf("%d\n", arr[i]);
        count = 1;       /* initialize the count value. */
      }
      //case 3: if one is alive and his count is not equal to k, go to next one.
      else {
        count ++;
      }
    }
    //mark the people died in this turn as Y.
    for (int j = 0; j < n; j++) {
      if (arr[j] == X) {
        arr[j] = Y;
      }
    }
    //check the remainning people.
    remain = check_remain(arr, n);
  }
  // print the last one
  if (remain == 1) {
    //test the number of winner.
    count = 0;
    //find and print the winner.
    for (int ind = 0; ind < n; ind ++) {
      if ((arr [ind] != X) && (arr[ind] != Y)) {
        printf("%d\n", ind);
        count ++;
      }
      //check the number of winner.
      if (count > 1) {
        printf("Error! The are more than 1 winners. \n");
      }
    }
  }

  // release the memory of the array
  free (arr);
}
#endif
