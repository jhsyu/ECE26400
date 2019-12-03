#include <stdio.h>
##include "maze.h"
int main(int argc, char ** argv){
  // for the file, argv1 is the input file,
  // and argv2 is the output file
  if (argc != 3) {
    fprintf(stderr, "need 2 files! \n" );
    return -1;
  }
  Maze * mzptr = malloc(sizeof(Maze));
  mzptr = maze_construct(argv[1]);
  find_distance(mzptr);
  Maze_print(mzptr, argv[2]);
  maze_destruct(mzptr);
}
