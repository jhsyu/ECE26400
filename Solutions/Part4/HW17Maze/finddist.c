#include "maze.h"
#include <stdio.h>
// return 1 if can Move
// 0 if cannot Move
int canMove(Maze * mzptr, int row, int col, int dir)
{
  /* (row, col) is the current location */
  switch (dir)
    {
    case NORTH:
      row --;
      break;
    case SOUTH:
      row ++;
      break;
    case WEST:
      col --;
      break;
    case EAST:
      col ++;
      break;
    }
    // invalid index: go out of the maze.
    if (row < 0) {
      return -1;
    }
    if (row > mzptr -> numRow) {
      return -1;
    }
    if (col > maptr -> numCol) {
      return -1;
    }
    if (col < 0) {
      return -1;
    }
  // valid index, in the range of the maze.
  return (mzptr->cells)[row][col];
}
void move(Maze * mzptr, int row, int col, int distance)
{
  if (distance == -1) {
    fprintf(stderr, "Wrong. Enter a Brick. \n");
    return;
  }
  distance = mzptr -> [row][col];
  //can move towards east?
  int dest = canMove(mzptr, row, col + 1, EAST);
  if (dest > distance + 1) {
    move(mzptr, row, col + 1, distance + 1);
  }
  dest = canMove(mzptr, row, col + 1, WEST);
  if (dest > distance + 1) {
    move(mzptr, row, col - 1, distance + 1);
  }
  dest = canMove(mzptr, row, col + 1, SOUTH);
  if (dest > distance + 1) {
    move(mzptr, row + 1, col, distance + 1);
  }
  dest = canMove(mzptr, row, col + 1, NORTH);
  if (dest > distance + 1) {
    move(mzptr, row - 1, col, distance + 1);
  }
}
void find_distance(Maze * mzptr)
{
  if (maze == NULL) {
    return;
  }
  move(mzptr, mzptr -> startRow, mzptr -> startCol, 0);
}
