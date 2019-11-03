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

void print_list(List * arithlist)
{
  if (arithlist == NULL)
    {
      return;
    }
  ListNode * ln = arithlist -> head;
  ListNode * p;
  while (ln != NULL)
    {
      p = ln -> next;
      printf("%s", ln -> word); // no need to add '\n'
      ln = p;
    }
    printf("\n");
}

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
    // output stack
    List * output = malloc (sizeof(List));
    output -> head = NULL;
    output -> tail = NULL;
    //pointers point to arithlist
    ListNode * p = arithlist -> head;

    // start convert.
    while (p != NULL) {
      #ifdef DEBUG
      printf("    OUTPUT IN: \n");
      print_list(output);
      printf("    OPERATORS IN: \n");
      print_list(operators);
      #endif
      // read one word from arithlist.
      char temp [WORDLENGTH] = {'0'};
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
        // check if there is a * in operators.
        if (operators -> tail != NULL) {
          val = isOperator(operators -> tail -> word);
          if (val == 2) {
            addNode(output, "*\n");
            deleteNode(operators, operators -> tail);
            if (operators -> tail != NULL) {
              val = isOperator(operators -> tail -> word);
              if (val != 3) {
                addNode(output, operators -> tail -> word);
                deleteNode(operators, operators -> tail);
              }
            }
        }
        }
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
          addNode(output, operators -> tail -> word);
          deleteNode(operators, operators -> tail);
          // if there is something before *,
          // put it to output after put * into output.
          if (val == 2) {
            addNode(output, operators -> tail -> word);
            deleteNode(operators, operators -> tail);
          }
          addNode(operators, "+\n");
          }
          // if the operator before is a '('
        else if (val == 3) {
          // there is a left paranthesis before this '+'
          // just add this '+' to operator list.
          addNode(operators, "+\n");
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
          addNode(output, operators -> tail -> word);
          deleteNode(operators, operators -> tail);
          addNode(operators, "-\n");
        }
        else if (val == 3) {
          // there is a left paranthesis before this '+'
          // just add this '+' to operator list.
          addNode(operators, "-\n");
        }
        else if (val == 4) {
          // impossible.
          return false;
        }
        break;



        case 2: // it is a '*'.
        // read * and push it to operator stack, then read
        // the next char.
        addNode(operators, "*\n");
        break;


        case 3: // it is a '(', put it to operator list.
        addNode(operators, "(\n");
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

      #ifdef DEBUG
      printf(" OUTPUT OUT: \n");
      print_list(output);
      printf("OPERATORS OUT: \n");
      print_list(operators);
      #endif

      if (p != NULL) {
        p = p -> next;
      }
    }
    // put all the operators in operators stack into output.
    while (operators -> tail != NULL) {
      addNode(output, operators -> tail -> word);
      deleteNode(operators, operators -> tail);
    }
    // the input is arithlist.
    // the output is output.
    // temp storage is operators.
    // use "input" to keep track on the arithlist.
    List * input = malloc(sizeof(List));
    input -> head = arithlist -> head;
    input -> tail = arithlist -> tail;
    // REPLACE the content of arithlist
    // with the content of output.
    // and delete output.
    arithlist -> head = output -> head;
    arithlist -> tail = output -> tail;
    output -> head = NULL;
    output -> tail = NULL;
    // delete all local lists in heap memory.
    deleteList(input);
    deleteList(operators);
    deleteList(output);
  return true;
}
#endif
