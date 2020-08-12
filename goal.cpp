#include "goal.h"
#include "map.h"
#include <cstdlib>
#include <time.h>

goal::goal()
{
  srand (time(NULL));
  totalRows = testMap.totalRows;
  totalCols = testMap.totalCols;
  tempCol = totalCols -2;
  tempRow = totalRows -2;
  info[0] = rand()% tempRow;
  info[1] = rand()% tempCol;
  info[0] = info[0] + 1;
  info[1] = info[1] + 1;
}

void goal::newGoal()
{
  info[0] = rand()% tempRow;
  info[1] = rand()% tempCol;
  info[0] = info[0] + 1;
  info[1] = info[1] + 1;
}

int* goal::getCoordinates()
{
  int* pointer = info;
  return pointer;
}