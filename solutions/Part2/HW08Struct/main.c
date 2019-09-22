// ***
// *** You must modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "hw08.h"

#ifdef TEST_MAIN
int main(int argc, char * * argv)
{
  // argv[1]: name of input file (binary)
  // argv[2]: name of output file (binary)
  // check whether there are three arguments.
  // If not, return EXIT_FAILURE. DO NOT print anything
  if (argc != 4) {
    return EXIT_FAILURE;
  }

  // use argv[1] as the input to countVector, save the result
  int numElem = countVector(argv[1]);
  // if the number of vector is 0 or negative, return EXIT_FAILURE
  if (numElem < 1) {
    return EXIT_FAILURE;
  }
  // otherwise, allocate memory for an array of vectors
  Vector * vecArr = malloc(numElem * sizeof(Vector));
  if (vecArr == NULL) {
    return false;
  }
  // read the vectors from the file whose name is argv[1]. save the
  // results in the allocated array
  bool rtv = readVector(argv[1], vecArr, numElem);
  // if reading fails, release memory and return EXIT_FAILURE
  if (rtv == false) {
    return EXIT_FAILURE;
  }

#ifdef DEBUG
  printVector(vecArr, numElem);
#endif

  // call qsort to sort the vectors, use argv[3] to determine which
  // attribute to sort
  if ((strcmp(argv[3], "x"))) {
    qsort(vecArr, numElem, sizeof(Vector), compareVector);
  }
  else if ((strcmp(argv[3], "y"))) {
    qsort((vecArr + sizeof(int)), numElem, sizeof(Vector), compareVector);
  }
  else if ((strcmp(argv[3], "z"))) {
    qsort((vecArr + 2 * sizeof(int)), numElem, sizeof(Vector), compareVector);
  }
  else {
    printf("The attribute can be ONLY x, y, or z!\n");
    return EXIT_FAILURE;
  }
#ifdef DEBUG
  printf("\n");
  printVector(vecArr, numElem);
#endif

  // write the sorted array to the file whose name is argv[2]
  // if writing fails, release memory and return EXIT_FAILURE
  if (writeVector(argv[2], vecArr, numElem)) {
    free(vecArr);
    return EXIT_FAILURE;
  }
  free(vecArr);
  return EXIT_SUCCESS;

  // releave memory, return EXIT_SUCCESS
}
#endif
