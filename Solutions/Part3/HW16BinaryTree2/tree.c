// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"



// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE

TreeNode * construct (int v)
{
  TreeNode * r = malloc(sizeof(TreeNode));
  r -> left = NULL;
  r -> right = NULL;
  r -> value = v;
  return r;
}
int search (int v, int * inArray, int strt, int end)
{
  // search the number v in the in-order array.
  int * p = &inArray[strt];
  for (size_t i = strt; i <= end; i++) {
    if (*p == v) {
      return i;
    }
    p ++;
  }
  return -1;
}

TreeNode * buildHelp(int * inArray, int * postArray,
                      int instrt, int inend, int * post)
{
  // terminating condition.
  if (instrt > inend) {
    return NULL;
  }
  // construct the root node.
  int v = postArray[*post];
  TreeNode * trnode = construct(v);
  (*post) --;
  // if this node has no offspring.
  if (instrt == inend) {
    return trnode;
  }
  // now this node must has offsprings.
  int inind = search(v, inArray, instrt, inend);
  if (inind == -1) {
    return NULL;
    printf("SEARCH ERROR!\n");
    // error.
  }

  trnode -> right = buildHelp(inArray, postArray, inind + 1, inend, post);
  trnode -> left = buildHelp(inArray, postArray, instrt, inind - 1, post);
  return trnode;
}

Tree * buildTree(int * inArray, int * postArray, int size)
{
  Tree * tr = malloc(sizeof(Tree));
  int post = size - 1;
  tr -> root = buildHelp(inArray, postArray, 0, size - 1, &post);
  return tr;
}
#endif

#ifdef TEST_PRINTPATH

typedef struct listnode {
  struct listnode * next;
  struct listnode * prev;
  int data;
} ListNode;
typedef struct {
  ListNode * head;
  ListNode * tail;
} List;

ListNode * nodeconstruct(int v)
{
  ListNode * p = malloc(sizeof(ListNode));
  p -> next = NULL;
  p -> prev = NULL;
  p -> data = v;
  return p;
}

void addNode(List * list, int v)
{
  if (list == NULL) {
    return;
  }
  //when airthlist is empty, add one node whose prev and next are NULL.
  //head and tail point to the same node added.
  //words is empty.
  if (list -> head == NULL) {
    list -> head = nodeconstruct(v);
    list -> tail = list -> head;
  }
  // if list is not empty, add one node to the tail.
  // make tail pointed to the new node.
  else {
    ListNode * p = list -> tail;
    ListNode * q = nodeconstruct(v);
    p -> next = q;
    q -> prev = p;
    q -> next = NULL;
    list -> tail = q;
  }
  return;
}

bool deletenode(List * list, ListNode * todelete)
{
  if (list == NULL) {
    return false;
  }
  if ((list -> head == NULL) || (list -> tail == NULL)) {
    return false;
  }
  ListNode * p = list -> head;
  ListNode * q = p -> next;
  ListNode * r = list -> tail;
  // the case that the node is head:
  if (p == todelete) {
    if (q == NULL) { // only one node in list.
      list -> head = NULL;
      list -> tail = NULL;
    }
    else { // not only one.
      q -> prev = NULL;
      list -> head = q;
    }
    free(p);
    }
    else if (r == todelete) {
      (r -> prev) -> next = NULL;
      list -> tail = r -> prev;
      free(r);
    }
    // find the node to be deleted.
    else {
      while (q != todelete) {
        p = q;
        q = p -> next;
      }
      if (q == NULL) {
        return false;   // listnode is not in list.
      }
      // at this case q must be eaqual to ListNode * todelete.
      // p is equal to q -> prev.
      p -> next = q -> next;
      (q -> next) -> prev = p;
      free(q);
    }
    return true;
  }

void deleteList(List * list)
{
  if (list == NULL) {
    return;
  }
  if (list -> head == NULL) {
    free(list);
    return;
  }
  ListNode * p = list -> head;
  ListNode * q = p -> next;
  while (q != NULL) {
    free(p);
    // the two lines following cannot change order.
    p = q;
    q = p -> next;
  }
  //free the last one. now p->next should be NULL.
  free(p);
  free(list);
}



bool treesearch(TreeNode * tr, int v, List * path)
{
  if (tr == NULL) {
    return false;
  }
  if (tr -> value) {
    return true;
  }
  if (treesearch(tr -> left, v, path)) {
    addNode(path, v);
    return true;
  }
  if (treesearch(tr -> right, v, path)) {
    addNode(path, v);
    return true;
  }
  return false;
}
void printPath(Tree * tr, int val)
{

}
#endif
