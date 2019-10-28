// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST

void Construct (ListNode * ptr)
{
  ListNode * p = malloc(sizeof(ListNode));
  if (p == NULL) {
    return;
  }
  p -> prev = NULL;
  p -> next = NULL;
  return;
}

ListNode * Insert(ListNode * head)
{
  ListNode * p;
  Construct(p);
  if (p == NULL) {
    return head;
  }
  p -> next = head;
  head = p;
  return head;
}

bool readC (List * arithlist, FILE * fptr)
{
  //known : the list's head and tail
  //        the file ponter

}

// read line by line from the input file
// each line shorter than WORDLENGTH (including '\n' and '\0')
// arithlist should have memory to store head and tail
// If arithlist is NULL, return false
// If fopen fails, return false
// If a line is too long,
//    free memory of the list
//    fclose
//    return false
// If everything is fine
//    fclose
//    arithlist points to the head and tail of the list
//    return true

bool readList(char * filename, List * arithlist)
{
  FILE * fptr = fopen(filename);
  //fopen fails.
  if (fptr == NULL) {
    return false;
  }
  if (arithlist == NULL) {
    return false;
  }

  ListNode * p;
  while (fscanf("%s", ); {

  }
  //read list from the file.


  return true;
}
#endif

#ifdef TEST_DELETELIST
// If arithlist is NULL, do nothing
// release the memory of every node in the list
// release the memory of the list
void deleteList(List * arithlist)
{
  if (arithlist == NULL) {
    return;
  }
  ListNode * p = arithlist -> head;
  ListNode * q = p -> next;
  while (q != NULL) {
    free(p);
    // the two lines following cannot change order.
    p = q;
    q = p -> next;
  }
  free(arithlist);
}
#endif

#ifdef TEST_ADDNODE
// Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, do nothing
// word is the word to be added
//
// Output:
// a ListNode is added to the end (become tail)
//
// allocate memory for a new ListNode
// copy word to the word attribute of the new ListNode
// insert the ListNode to the list
void addNode(List * arithlist, char * word)
{
}
#endif

#ifdef TEST_DELETENODE
//  Input:
// arithlist stores the addresses of head and tail
// If arithlist is NULL, return false
// If the list is empty (head and tail are NULL), return false
// ln is the node to be deleted
// If ln is not in the list, return false
//
// Output:
// arithlist stores the addresses of head and tail
//   after ln is deleted
// return true.
//
// Be careful about delete the first or the last node
bool deleteNode(List * arithlist, ListNode * ln)
{
  return true;
}
#endif
