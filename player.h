#ifndef PLAYER_H
#define PLAYER_H
#include "map.h"
#include "goal.h"
#include "trail.h"

class player
{
public:
    int totalRows;
    int totalCols;
    player();
    void movePlayerUp();
    void movePlayerDown();
    void movePlayerLeft();
    void movePlayerRight();
    int getPlayerRow();
    bool overGoal();
    void changeGoal();
    int getCapacity();
    bool lose();
    void reset();

    friend std::ostream& operator<<(std::ostream&, const player&);

private:
    map savedMap;
    goal savedGoal;
    trail savedTrail;
    string** area;
    int playerRow;
    int playerCol;
    int* apple;
    int** snake;

    void refresh();
};

#endif // PLAYER_H
