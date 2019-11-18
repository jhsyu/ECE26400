// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

typedef struct node
{
  int value;
  struct node * next;
  struct node * prev;
} ListNode;

typedef struct
{
  ListNode * head;
  ListNode * tail;
} List;

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
ListNode * nodeconstruct(int v)
{
  ListNode * node = malloc(sizeof(ListNode));
  node -> next = NULL;
  node -> prev = NULL;
  node -> value = v;
  return node;
}

void record(int value, List * path)
{
  ListNode * p = nodeconstruct(value);
  path -> tail = p;
}

void deletelist(List * list)
{
  if (list -> head == NULL) {
    return;
  }
  if (list -> head == list -> tail) {
    free(list -> head);
    return;
  }
  ListNode * p = list -> head;
  ListNode * q = p -> next;
  while (q != NULL) {
    free(p);
    p = q;
    q = p -> next;
  }
}
TreeNode * treesearch(TreeNode * tr, int v, List * path)
{
  if (tr == NULL) {
    return NULL;
  }
  record(v, path);
  if (tr -> value == v) {
    // node found!
    return tr;
  }
  if (tr -> value > v) {
    return treesearch(tr -> left, v, path);
  }
  return treesearch(tr -> right, v, path);
}


void printPath(Tree * tr, int val)
{
  List path = {
    .head = NULL,
    .tail = NULL,
  };
  treesearch(tr -> root, val, &path);
  ListNode * p = path.head;
  while (p != NULL) {
    printf("%d\n", p -> value);
    if (p -> next != NULL) {
      p = p -> next;
    }
  }
  deletelist(&path);
}
#endif
