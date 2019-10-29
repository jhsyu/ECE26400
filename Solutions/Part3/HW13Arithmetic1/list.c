// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef TEST_READLIST

ListNode * Construct (ListNode * ptr)
{
  ListNode * p = malloc(sizeof(ListNode));
  if (p == NULL) {
    return ptr;
  }
  p -> prev = NULL;
  p -> next = NULL;
  ptr = p;
  return ptr;
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
  FILE * fptr = fopen(filename, "r");
  //fopen fails.
  if (fptr == NULL) {
    return false;
  }
  if (arithlist == NULL) {
    return false;
  }
  //read list from the file.
  char word [WORDLENGTH];
  while (! feof(fptr)) {
    if (fscanf(fptr, "%s", word) == 1) {
      addNode(arithlist, word);
    }
  }
  fclose(fptr);


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
  //free the last one. now p->next should be NULL.
  free(p);
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
  if (arithlist == NULL) {
    return;
  }
  //when airthlist is empty, add one node whose prev and next are NULL.
  //head and tail point to the same node added.
  //words is empty.
  if (arithlist -> head == NULL) {
    arithlist -> head = Construct(arithlist -> head);
    arithlist -> tail = arithlist -> head;
    ListNode * p = arithlist -> head;
    strcpy(p -> word, word);
  }
  // if arithlist is not empty, add one node to the tail.
  // make tail pointed to the new node.
  else {
    ListNode * p = arithlist -> tail;
    ListNode * q = Construct((arithlist -> tail) -> next);
    p -> next = q;
    q -> prev = p;
    q -> next = NULL;
    arithlist -> tail = q;
    strcpy(q -> word, word);
  }
  return;
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
  if (arithlist == NULL) {
    return false;
  }
  if ((arithlist -> head == NULL) || (arithlist -> tail == NULL)) {
    return false;
  }
  ListNode * p = arithlist -> head;
  ListNode * q = p -> next;
  ListNode * r = arithlist -> tail;
  if (p == ln) {
    q -> prev = NULL;
    arithlist -> head = q;
    free(p);
  }
  else if (r == ln) {
    (r -> prev) -> next = NULL;
    arithlist -> tail = r -> prev;
    free(r);
  }
  // find the node to be deleted.
  else {
    while (q != ln) {
      p = q;
      q = p -> next;
    }
    if (q == NULL) {
      return false;   // listnode is not in arithlist.
    }
    // at this case q must be eaqual to ListNode * ln.
    // p is equal to q -> prev.
    p -> next = q -> next;
    (q -> next) -> prev = p;
    free(q);
  }
  return true;
}
#endif
