#define MAZE_H
#define STARTSYMBOL   's'
#define BRICKSYMBOL   'b'
#define PATHSYMBOL    ' '
#define NORTH
typedef struct {
  int numRol, numCol;
  int startRow, int startCol;
  int curRow, curCol;
  int ** cells;
} Maze;
// directions, ORIGIN marks the starting point
enum {ORIGIN, EAST, SOUTH, WEST, NORTH};
// move forward, backward, or found exit alread
enum {FORWARD, BACKWARD, DONE};
Maze * maze_construct(char * filename);
void maze_destruct(Maze * mzptr);
void maze_print(Maze * mzptr);
bool can_move(Maze * mzptr, int dir, int row, int col);
void get_out(Maze * mzptr, int row, int col, int dir, int * mode);
