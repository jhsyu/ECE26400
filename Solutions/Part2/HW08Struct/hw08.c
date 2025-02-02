// ***
// *** You must modify this file
// ***
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", )
  // If fopen fails, return -1
  // For the mode of fopen, you may use "r" without b
  FILE * fptr = fopen(filename, "r");
  if (fptr == NULL) {
    return -1;
  } //fopen fails.
  int count = 0;
  Vector * buffer = malloc(sizeof(Vector));
  if (buffer == NULL) {
    return -1;
  }
  while (fread(buffer, sizeof(Vector), 1, fptr)) {
    count ++;
  }
  free(buffer);
  fclose(fptr);
  return count;
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // read Vectors from the file.
  //
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  //
  // if everything is fine, fclose and return true
  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL) {
    return false;
  } //fopen fails.

  int numElem = countVector(filename);
  if (numElem != size) {
    fclose(fptr);
    return false;
  } //check the number of elements.

  int read = 0;
  read = fread(vecArr, sizeof(vecArr[0]), size, fptr);
  fclose(fptr);
  return true;
}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *p1, const void *p2)
{
  Vector arg1 = *(const Vector *) p1;
  Vector arg2 = *(const Vector *) p2;

  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1
  // If the first vector's x is greater than the second vector's x
  // return 1
  // If the two vectors' x is the same, compare the y attribute
  if (arg1.x != arg2.x) {
    return arg1.x > arg2.x ? 1:-1;
  }
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  else if ((arg1.x == arg2.x)&&(arg1.y != arg2.y)) {
    return arg1.y > arg2.y ? 1:-1;
  }
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
  else if ((arg1.x == arg2.x)&&(arg1.y == arg2.y)&&(arg1.z != arg2.z)) {
    return arg1.z > arg2.z ? 1:-1;
  }
  else return 0;
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  // write the array to file using fwrite
  // need to check how many have been written
  // if not all are written, fclose and return false
  FILE * fptr = fopen(filename, "w");
  if (fptr ==NULL) {
    return false;
  }
  int numElem = fwrite(vecArr, sizeof(Vector), size, fptr);
  if (numElem != size) {
    fclose(fptr);
    return false;
  } //the number of vectors written is not match with size.

  fclose(fptr);
  return true;
  // fclose and return true
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
