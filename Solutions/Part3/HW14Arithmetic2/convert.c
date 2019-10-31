// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// retrun 2 if the word contains '*'
// return 3 if the word contains '('
// return 4 if the word contains ')'
int isOperator(char * word)
{
  int ind;
  int numop = sizeof(Operations) / sizeof(int);
  for (ind = 0; ind < numop; ind ++)
    {
      if (strchr(word, Operations[ind]) != NULL)
	{
	  return ind;
	}
    }
  return -1;
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the convert function
// ***

#ifdef TEST_CONVERT
bool convert(List * arithlist)
{
  if (arithlist == NULL)
    {
      return true;
    }
  if ((arithlist -> head) == NULL)
    {
      return true;
    }
    // the output stack is arithlist.
    // arithlist also stores the arithlist need to convert.
    // create another list to store operators.
    List * operators = malloc(sizeof(List));
    operators -> head = NULL;
    operators -> tail = NULL;
    //number list
    List * output = malloc (sizeof(List));
    numbers -> head = NULL;
    numbers -> tail = NULL;
    //pointers point to arithlist
    ListNode * p = arithlist -> head;
    ListNode * q = p -> next;
    // pointers point to operator list.
    ListNode * m = operators -> head;
    ListNode * n = NULL;
    // pointers point to number list.
    ListNode * a = output -> head;
    ListNode * b = NULL;

    // start convert.
    while (q != NULL) {
      // read one word from arithlist.
      char * temp;
      strcpy(temp, p -> word);
      // read fails:
      if (temp == NULL) {
        return false;
      }
      // determine if it is a number or an operator.
      int rtv = isOperator(temp);
      // according to rtv decide what to do:
      // 1. if it is a number (rtv = -1)
      switch (rtv) {
        case -1: //it is a number, push it to output and then read the next.
        addNode(output, temp);
        case 0: // it is a '+', push it to operator list.
        addNode(operators, temp);
        case 1:

        case 2:

        case 3:

        case 4:

        default:

      }
      p = q;
      q = p -> next;
    }
  ListNode * ori = arithlist -> head;
  arithlist -> head = output -> head;
  arithlist -> head = output -> tail;
  deleteList(ori);
  deleteList(operators);
  return true;
}
#endif
