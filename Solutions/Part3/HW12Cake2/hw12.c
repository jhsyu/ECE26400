// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "hw12.h"

// DO NOT MODIFY this function --->>>
void printListNode(ListNode * head)
{
  ListNode * p = head;
  printf("printListNode: ");
  while (p != NULL)
    {
      printf("%7d ", p -> value);
      p = p -> next;
    }
  printf("\n");
}
// <<<--- until here

// You MUST modify the following functions

#ifdef TEST_CREATELIST
// create a linked list storing values 0, 1, 2, ... valn - 1
// The first node (head) stores 0, the next node stores 1,
// ..., the last node stores valn - 1
// return the head of the linked listn
ListNode * createHelp(int Valn, int index)
{
  // terminating condtion: create the node for vlan.
  if (index == Valn) {
    return NULL;
  }
  ListNode * lptr = malloc(sizeof(ListNode));
  lptr->value = index;
  lptr->next = createHelp(Valn, index + 1);
  return lptr;
}
ListNode * createList(int valn)
{
  ListNode * head = createHelp(valn, 0);
  return head;
}
#endif

#ifdef TEST_ELIMINATE
// eliminate the nodes in the linked list
// starting from the head, move one node at a time and count to valk.
// eliminate that node, keep counting
//
// when reaching the end of the list, continue from the beginning of
// the list
//
// print the values of the nodes to be deleted
void eliminate(ListNode * head, int valk)
{
  // count the n.
  int n = 0;
  ListNode * p = head;
  while (p != NULL) {
    n ++;
    p = p->next;
  }
  //initialize the list pointer.
  p = head;
  // count starts from 1, not 0.
  int count = 1;
  //initialize the value of remain.
  int remain = n;
  while (remain != 1) {
    if (count == valk) {
      #ifdef DEBUG
      // this #ifdef ... #endif should be inside the condition *BEFORE* a
      // node' value is printed and it is deleted
      ListNode * todelete = p;
      printListNode (todelete);
      #endif
      ListNode * del = p;
      if (p->next ==NULL) {
        p = head;
      }
      else {
        p = p->next;
      }
      printf("%d\n", del->value);
      head = deleteNode(head, del);
      remain --;
      count = 1;
    }
    else {
      if (p->next ==NULL) {
        p = head;
        count ++;
      }
      else {
        count ++;
        p = p->next;
      }
    }
  }
  printf("%d\n", p->value);
}
#endif

#ifdef TEST_DELETENODE
// head points to the first node in the linked list
// todelete points  to the node to be deleted
//
// delete the node and return the head of the linked list
// release the memory of the deleted node
//
// should check several conditions:
// 1. If head is NULL, the list is empty and this function returns
//    NULL
// 2. If todelete is NULL, nothing can be deleted, return head
// 3. If todelete is not in the list, keep the list unchanged and
//    return head
// It is possible that todelete is the first node in the list (i.e.,
// the head). If this occurs, return the second node of the list.
ListNode * deleteNode(ListNode * head, ListNode * todelete)
{
  // list is empty.
  if (head == NULL) {
    return NULL;
  }
  // nothing to delete.
  if (todelete == NULL) {
    return NULL;
  }
  // initialize the pointers
  ListNode * next = head->next;
  ListNode * curr = head;
  if (head == todelete) {
    free(head);
    return next;
  }
  while (next != NULL) {
    if (next->value == todelete->value) {
      curr->next = todelete->next;
      free(todelete);
    }
    curr = next;
    next = next->next;
  }
  return head;
}
#endif
