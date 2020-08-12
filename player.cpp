#include "player.h"
#include "map.h"
#include "goal.h"
#include "trail.h"

#include <iostream>
#include <cstdlib>
#include <time.h>

player::player()
{
    srand (time(NULL));
    apple = savedGoal.getCoordinates();
    totalRows = savedMap.totalRows;
    totalCols = savedMap.totalCols;
    int tempCol = totalCols -2;
    int tempRow = totalRows -2;
    playerCol = rand()% tempCol;
    playerRow = rand()% tempRow;
    playerCol = playerCol + 1;
    playerRow = playerRow + 1;
    area = savedMap.getMap();

    savedTrail.activate(playerRow, playerCol);

    refresh();

    area[apple[0]][apple[1]] = "O";
}

void player::refresh()
{
  for(int i = 0; i<totalRows; i++)
  {
    for(int j = 0; j <totalCols; j++)
    {
      snake = savedTrail.getTrail();
    }
  }

  for(int i = 1; i<totalRows-1; i++)
  {
    for(int j = 1; j <totalCols-1; j++)
    {
      if(snake[i][j] > 0)
        area[i][j] = "\u25A0";
      
      if(snake[i][j] == 0)
      {
        if(i!= apple[0] || j!=apple[1])
        {
          area[i][j] = " ";
        }
      }
    }
  }
}

void player::movePlayerUp()
{
    if(playerCol != 0)
    {
        if(area[playerRow-1][playerCol]!="\u25A0")
        {
          playerRow = playerRow -1;
          savedTrail.move();
          savedTrail.activate(playerRow, playerCol);
          refresh();
        }
    }
}

void player::movePlayerDown()
{
    if(area[playerRow+1][playerCol]!="\u25A0")
    {
      playerRow = playerRow +1;
      savedTrail.move();
      savedTrail.activate(playerRow, playerCol);
      refresh();
    }
}

void player::movePlayerRight()
{
    if(area[playerRow][playerCol+1]!="\u25A0")
    {
      playerCol = playerCol +1;
      savedTrail.move();
      savedTrail.activate(playerRow, playerCol);
      refresh();
    }
}

void player::movePlayerLeft()
{
    if(area[playerRow][playerCol-1]!="\u25A0")
    {
      playerCol = playerCol -1;
      savedTrail.move();
      savedTrail.activate(playerRow, playerCol);
      refresh();
    }
}

bool player::overGoal()
{
  if(playerRow==apple[0] && playerCol==apple[1])
  {
    return true;
  }
  return false;
}

void player::changeGoal()
{
  savedGoal.newGoal();
  apple = savedGoal.getCoordinates();
  while(area[apple[0]][apple[1]] == "\u25A0")
  {
    savedGoal.newGoal();
    apple = savedGoal.getCoordinates();
  }
  area[apple[0]][apple[1]] = "O";
  savedTrail.add();
}

int player::getPlayerRow()
{
  return playerRow;
}

int player::getCapacity()
{
  return savedTrail.getCapacity();
}

bool player::lose()
{
  if(area[playerRow-1][playerCol]=="\u25A0")
  {
    if(area[playerRow+1][playerCol]=="\u25A0")
    {
      if(area[playerRow][playerCol+1]=="\u25A0")
      {
        if(area[playerRow][playerCol-1]=="\u25A0")
        {
          return true;
        }
      }
    }
  }
  return false;
}

void player::reset()
{
  savedTrail.restart();

  int tempCol = totalCols -2;
  int tempRow = totalRows -2;
  playerCol = rand()% tempCol;
  playerRow = rand()% tempRow;
  playerCol = playerCol + 1;
  playerRow = playerRow + 1;
  changeGoal();
  refresh();
}

std::ostream& operator<<(std::ostream& out, const player& pop)
{
  for(int i = 0; i< pop.totalRows; i++)
  {
    for(int j = 0; j<pop.totalCols; j++)
    {
      out<<pop.area[i][j]<<" ";
    }
    out<<endl;
  }
  return out;
}
