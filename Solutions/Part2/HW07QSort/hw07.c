// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  // count the number of integers in the file
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL) {
    return -1;
  }
  int count = 0;
  int temp = 0;
  while ((fscanf(fptr, "%d", &temp)) ==  1) {
    count ++;
  }
  fclose(fptr);
  return count;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // read integers from the file.
  //
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  //
  // if everything is fine, fclose and return true
  if ((countInt(filename)) != size) {
    return false;
  }
  FILE *fptr = fopen(filename, "r");
  if (fptr == NULL)
  {
    return false;
  }

  //read the integers from the file.
  for (int i = 0; i < size; i++)
  {
    fscanf(fptr, "%d", &intArr[i]);
  }
  fclose(fptr);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  int arg1 = *(const int *) p1;
  int arg2 = *(const int *) p2;
  if (arg1 < arg2) {
    return -1;
  }
  if (arg1 > arg2) {
    return 1;
  }
  return 0;
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  // write integers to the file.
  // one integer per line
  //
  // fclose and return true
  FILE * fptr = fopen(filename, "w");
  if (fptr == NULL) {
    return false;
  }
  for (int i = 0; i < size; i++) {
    fprintf(fptr, "%d\n", intArr[i]);
  }
  return true;
}
#endif
