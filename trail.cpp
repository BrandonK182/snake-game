#include "trail.h"

trail::trail()
{
  for(int i = 0; i<totalRows; i++)
  {
    for(int j = 0; j<totalCols; j++)
    {
      numTurns[i][j] = 0;
    }
  }
  length = 1;
  int temp1 = totalCols -2;
  int temp2 = totalRows -2;
  capacity = temp1*temp2;

}

int** trail::getTrail()
{
    int** temp;
    temp = new int*[totalRows];

    for (int i = 0; i < totalCols; i++)
    {
          temp[i] = new int[totalCols];
    }
    for(int i = 0; i< totalRows; i++)
    {
      for(int j = 0; j<totalCols; j++)
      {
        temp[i][j] = numTurns[i][j];
      }
    }
 return temp;
}

int trail::getCapacity()
{
  return capacity;
}

void trail::activate(int row, int col)
{
  numTurns[row][col] = length;
}

void trail::deactivate(int row, int col)
{
  numTurns[row][col] = 0;
}

void trail::move()
{
  for(int i = 0; i<totalRows; i++)
  {
    for(int j = 0; j<totalCols; j++)
    {
      if(numTurns[i][j]>0)
      {
        numTurns[i][j] = numTurns[i][j] - 1; 
      }
    }
  }
}

void trail::restart()
{
  for(int i = 0; i<totalRows; i++)
  {
    for(int j = 0; j<totalCols; j++)
    {
      numTurns[i][j] = 0;
    }
  }
  length = 1;
}

void trail::add()
{
  if(length != capacity)
  {
    length++;
    for(int i = 0; i<totalRows; i++)
    {
      for(int j = 0; j<totalCols; j++)
      {
        if(numTurns[i][j]>0)
        {
          numTurns[i][j] = numTurns[i][j] + 1; 
        }
      }
    }
  }
}
