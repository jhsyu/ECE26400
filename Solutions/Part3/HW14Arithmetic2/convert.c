// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "list.h"
#include "convert.h"

// DO NOT MODIFY FROM HERE --->>>
const int Operations[] = {'+', '-', '*', '(', ')'};

// return -1 if the word is not an operator
// return 0 if the word contains '+'
// return 1 if the word contains '-'
// return 2 if the word contains '*'
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
    output -> head = NULL;
    output -> tail = NULL;
    //pointers point to arithlist
    ListNode * p = arithlist -> head;
    ListNode * q = p -> next;

    // start convert.
    while (q != NULL) {
      // read one word from arithlist.
      char temp [WORDLENGTH] = {0};
      strcpy(temp, p -> word);
      // read fails:
      if (temp == NULL) {
        return false;
      }
      // determine if it is a number or an operator.
      int rtv = isOperator(temp);
      int val = -2;
      // according to rtv decide what to do:
      // 1. if it is a number (rtv = -1)
      switch (rtv) {
        case -1: //it is a number,
        //push it to output and then read the next.
        addNode(output, temp);
        break;



        case 0: // it is a '+'
        if (operators -> head == NULL) {
          addNode(operators, temp);
          break;
        }
        // there is something before this '+'
        val = isOperator(operators -> tail -> word);
        if (val < 3) {
          // if there is a +/-/*, pop it to output
          // and push the '+' to operator list.
          deleteNode(operators, operators -> tail);
          switch (val) {
            case 0:
            addNode(output, "+");
            break;
            case 1:
            addNode(output, "-");
            break;
            case 2:
            addNode(output, "*");
            break;
            default:
            return false;
          }
          addNode(operators, "+");
        }
        else if (val == 3) {
          // there is a left paranthesis before this '+'
          // just add this '+' to operator list.
          addNode(operators, "+");
        }
        else if (val == 4) {
          // impossible.
          return false;
        }
        break;



        case 1: // it is a '-', similar to '+'.
        if (operators -> head == NULL) {
          addNode(operators, temp);
          break;
        }
        // there is something before this '+'
        val = isOperator(operators -> tail -> word);
        if (val < 3) {
          // if there is a +/-/*, pop it to output
          // and push the '+' to operator list.
          deleteNode(operators, operators -> tail);
          switch (val) {
            case 0:
            addNode(output, "+");
            break;

            case 1:
            addNode(output, "-");
            break;

            case 2:
            addNode(output, "*");
            break;

            default:
            return false;
          }
          addNode(operators, "-");
        }
        else if (val == 3) {
          // there is a left paranthesis before this '+'
          // just add this '+' to operator list.
          addNode(operators, "-");
        }
        else if (val == 4) {
          // impossible.
          return false;
        }
        break;



        case 2: // it is a '*'.
        // if there is nothing before:
        // read * and push it to operator stack, then read
        // the next char.
        if (operators -> head == NULL) {
          addNode(operators, "*");
          break;
        }
        val = isOperator(operators -> tail -> word);
        switch (val) {
          case -1:
          return false;

          case 0: // the case that there is a '+' before it.
          // if there is a '+' or '-' before '*
          // 2. read next number and push it to number stack.
          // 3. pu '*' to output stack,
          // 4. then push '+' or '-' to output.
          addNode(operators, "*");
          p = q;
          p = p -> next;
          addNode(output, p -> word); // read next number
          // put the * to output stack.
          addNode(output, "*");
          // put the +/- to Output stack.
          addNode(output, operators -> tail -> word);
          // pop the +/- from the operator stack.
          deleteNode(operators, operators -> tail);
          break;

          case 1: // the case that there is a '-' before it
          // the same like '+'
          addNode(operators, "*");
          p = q;
          p = p -> next;
          addNode(output, p -> word); // read next number
          // put the * to output stack.
          addNode(output, "*");
          // put the +/- to Output stack.
          addNode(output, operators -> tail -> word);
          // pop the +/- from the operator stack.
          deleteNode(operators, operators -> tail);
          break;

          case 2: // the case there is a '*' before it.
          // what to do :
          // put the previous * to Output,
          // then read next number, put it into output
          // put this * to output.
          addNode(output, "*");
          p = q;
          p = p -> next;
          addNode(output, p -> word);
          addNode(output, "*");
          break;

          case 3: // the case that there is a '(' before it.
          // WHAT TO DO:
          // push this * to operator stack.
          addNode(operators, "*");
          break;

          case 4:
          return false;
        }
        break;


        case 3: // it is a '(', put it to operator list.
        addNode(operators, "(");
        break;

        case 4: // it is a ')', do not do any thing to it,
                // pop all the operators
                // untill there is a '('.
                addNode(output, operators -> tail -> word);
                deleteNode(operators, operators -> tail);
                deleteNode(operators, operators -> tail);
                break;

        default:
        return false;
      }
      p = q;
      q = p -> next;
    }
  List * input = malloc(sizeof(List));
  input -> head = arithlist -> head,
  input -> tail = arithlist -> tail,
  arithlist -> head = output -> head;
  arithlist -> head = output -> tail;
  deleteList(input);
  deleteList(operators);
  return true;
}
#endif
