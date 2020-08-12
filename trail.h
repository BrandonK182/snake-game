#ifndef TRAIL_H
#define TRAIL_H
#include "map.h"

class trail
{
private:
    static map testMap;
    int length;
    int capacity;

public:
    const static int totalRows = testMap.totalRows;
    const static int totalCols = testMap.totalCols;
    trail();
    int** getTrail();
    int getCapacity();
    void activate(int row, int col);
    void deactivate(int row, int col);
    void move();
    void add();
    void restart();

private:
    int numTurns[totalRows][totalCols];
};

#endif
