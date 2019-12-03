#include "maze.h"
#include <stdio.h>

static void checkMalloc(void * ptr, char * message)
{
  if (ptr == NULL) // malloc fail
    {
      printf("malloc for %s fail\n", message);
    }
}

static int findLineLength(FILE * fh)
{
  int ch;
  int length = 0;
  if (feof(fh)) { return -1; }
  do
    {
      ch = fgetc(fh); // read one character
      length ++;
    } while ((ch != '\n') && (ch != EOF));
  return length;
}

static void Maze_findSize(FILE * fh, int * numRow, int * numCol)
{
  int row = 0;
  int col = 0;
  int maxCol = 0;
  // find the maximum number of columns. This allows the
  // program to handle a maze that is not rectangular.
  do
    {
      col = findLineLength(fh);
      if (col != -1)
	{
	  if (maxCol < col) { maxCol = col; }
	  row ++;
	}
    } while (col != -1);
  * numRow = row;
  * numCol = maxCol;
}

Maze * maze_construct(char * fileName)
{
  int numRow = 0;
  int numCol = 0;
  int row, col;
  int ch;
  FILE * fptr = fopen(fileName, "r");
  if (fptr == 0)
    {
      fprintf(stderr, "open %s fail\n", fileName);
      return NULL;
    }
  Maze_findSize(fptr, & numRow, & numCol);
  Maze * mzptr = malloc(sizeof(Maze));
  checkMalloc(mzptr, "mzptr");
  mzptr -> numRow = numRow;
  mzptr -> numCol = numCol;
  // create a two-dimensional array to store the cells
  mzptr -> cells = malloc(numRow * sizeof(int *));
  checkMalloc(mzptr -> cells, "mzptr -> cells");
  for (row = 0; row < numRow; row ++)
    {
      mzptr -> cells[row] = malloc(numCol * sizeof(int));
      checkMalloc(mzptr -> cells[row],
			 "mzptr -> cells[row]");
      // initialize the cells to invalid
      for (col = 0; col < numCol; col ++)
	{
	  (mzptr -> cells)[row][col] = numCol * numRol + 1;
	}
    }
  // move fptr to the beginning
  fseek(fptr, 0, SEEK_SET);

  // read the file again and fill the two-dimensional array
  row = 0;
  while ((! feof(fptr)) && (ch != EOF) && (row < numRow))
    {
      // fill one row
      col = 0;
      do
	{
	  ch = fgetc(fptr);
	  if (ch != EOF)
	    {
	      // notice that '\n' is also stored
        switch (ch) {
          case BRICKSYMBOL:
          (mzptr -> cells)[row][col] = -1;
          case STARTSYMBOL:
          (mzptr -> cells)[row][col] = 0;
          mzptr -> startRow = row;
          mzptr -> startCol = col;
          mzptr -> curRow = row;
          mzptr -> curCol = col;
        }
	      col ++;
	    }
	} while ((ch != EOF) && (ch != '\n'));
      // checking '\n" to handle non-rectangular mazes
      row ++;
    }
  fclose(fptr);
  return mzptr;
}

void Maze_destruct(Maze * mzptr)
{
  int row;
  for (row = 0; row < (mzptr -> numRow); row ++)
    { free ((mzptr -> cells)[row]); }
  free (mzptr -> cells);
  free(mzptr);
}

void Maze_print(Maze * mzptr, char * filename)
{
  FILE * fptr = fopen(filename);
  if (fptr == NULL) {
    fprintf(stderr, "Open output file error!\n");
    return;
  }
  int row;
  int col;
  for (row = 0; row < (mzptr -> numRow); row ++){
    for (col = 0; col < (mzptr -> numCol); col ++){
      fprintf(fptr, "%ld", mzptr -> cells[row][col]);
    }
    fprintf(fptr, "\n");
  }

}
