// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  // You cannot assume * sum is zero.
  // Thus, * sum needs to be set 0
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  // if fopen succeeds, read integers using fscan
  // (do not use fgetc)
  //
  // * sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  FILE* fptr = fopen(filename, "r");
  if (fptr == NULL)
    return false;
  int add;
  *sum = 0; 
  while ((fscanf(fptr, "%d", &add)) != EOF)
    {
      if (add != EOF)
	*sum = *sum + add;
    }
  if (fptr != NULL)
    {
      fclose(fptr);
      fptr = NULL;
    }
  
  
  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //
  FILE* fptr = fopen(filename, "w");
  if (fptr != NULL)
    {
      fprintf(fptr, "%d\n", sum);
      fclose(fptr);
    }
  else
    {
      return false;
    }
  return true;
}
#endif
