// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
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

static void preOrderNode(TreeNode * tn, FILE * fptr)
{
  if (tn == NULL)
    {
      return;
    }
  fprintf(fptr, "%d\n", tn -> value);
  preOrderNode(tn -> left, fptr);
  preOrderNode(tn -> right, fptr);
}

void preOrder(Tree * tr, char * filename)
{
  if (tr == NULL)
    {
      return;
    }
  FILE * fptr = fopen(filename, "w");
  preOrderNode(tr -> root, fptr);
  fclose (fptr);
}
// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***

#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
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
  int * p = &inArray[strt];
  for (size_t i = strt; i <= end; i++) {
    if (*p == v) {
      return i;
    }
    p ++;
  }
  return -1;
}

TreeNode * buildHelp(int * inArray, int * postArray, int instrt, int inend, int * post)
{
  // terminating condition.
  if (instrt > inend) {
    return NULL;
  }
  int v = postArray[*post];
  TreeNode * trnode = construct(v);
  (*post) --;
  if (instrt == inend) {
    return trnode;
    // this node has no offspring.
  }
  // now this node has offsprings.
  int inind = search(v, inArray, instrt, inend);
  #ifdef DEBUG
  printf("IN: \n");
  for (size_t i = instrt; i <= inend; i++) {
    printf("%6d",inArray[i]);
  }
  printf("\nV = %d\n",postArray[*post]);
  #endif
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
