#ifndef GOAL_H
#define GOAL_H
#include "map.h"

class goal
{
public:
    int totalRows;
    int totalCols;
    goal();
    void newGoal();
    int* getCoordinates();

private:
    int info[2];
    int tempCol;
    int tempRow;
    map testMap;
};

#endif
