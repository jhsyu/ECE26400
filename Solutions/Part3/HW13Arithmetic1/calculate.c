// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "calculate.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// return 2 if the word contains '*'
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
    char *loc = strchr(word, Operations[ind]);
    if (loc != NULL && !isdigit(loc[1]))
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the calculate function
// ***
#ifdef TEST_CALCULATE
// if arithlist is NULL, return true
// if arithlist -> head is NULL, return true
// if the input list is invalid, return false
bool calculate(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
    int numE = 1;
    int result = 0;
    ListNode * p = arithlist -> head;
    ListNode * q = p -> next;
    ListNode * o = NULL;
    while (q != NULL) {
      numE ++;
      p = q;
      q = p -> next;
    }
    int remain = numE;
    // initialize p and q
    while (remain > 1) {
      p = arithlist -> head;
      q = p -> next;
      // operator cannot appear in the first place.
      if (isOperator(p -> word) != -1) {
        return false;
      }
      // find a operator.
      while ((q != NULL) && (isOperator(q -> word) == -1)) {
        // must check if q is null.
        // these two lines cannot change the order.
        p = q;
        q = p -> next;
      }
      if (q == NULL) {
        // no operator found.
        return false;
      }
      //there is an operator found: q is an operator.
      // hence, p is the second number, p -> prev is the first number.
      // need conversion from '1' to 1.
      // find the two number before it.
      o = p -> prev;
      // o points to the first number.
      if ((p != arithlist -> head) && (o == NULL)) {
        // cannot find two numbers before the operator.
        return false;
      }
      if ((o != NULL) && (p != NULL)) {
        int a = (int) strtol(o -> word, NULL, 10);
        int b = (int) strtol((p -> word), NULL, 10);
        int rtv = isOperator(q -> word);
        switch (rtv) {
          case 0:
          result = a + b;
          break;
          case 1:
          result = a - b;
          break;
          case 2:
          result = a * b;
          break;
          default:
          result = - 114514;
          return false;
        }
        sprintf(q -> word, "%d", result);
        // after calculation, push the result to the linked list
        // and delete the numbers and opertors.
        deleteNode(arithlist, o);
        deleteNode(arithlist, p);
        remain -= 2;
      }

    }


  // go through the list until there is only one node in the list
  // find the next operator
  // If no operator can be found, return false
  // If an operator is found, find the two previous nodes as operands
  // If cannot find previous two operands, return false
  // If two operands can be found, perform the arithmetic operation
  // Be careful, subtraction is no commutative: 4 2 - means 4 - 2,
  //    not 2 - 4
  // After the operation,
  //     put the result back to the list
  //     remove the two nodes used to store the two operands
  // After going through the entire list and performing the operations,
  //     the list should have exactly one node left. If this is not
  //     true, return false
  // If the input is valud, return true



  // if more than one node left, return false

  // if the remaining node is an operator, return false

  // if everything is OK, return true
  return true;
}
#endif
